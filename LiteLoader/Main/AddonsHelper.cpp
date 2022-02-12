#include "AddonsHelper.h"
#include <Main/Config.h>
#include <EventAPI.h>
#include <RegCommandAPI.h>
#include <LLAPI.h>
#include <MC/CommandOrigin.hpp>
#include <MC/CommandOutput.hpp>
#include <MC/CommandPosition.hpp>
#include <MC/CommandRegistry.hpp>
#include <MC/PropertiesSettings.hpp>
#include <GlobalServiceAPI.h>
#include <Utils/WinHelper.h>
#include <Utils/FileHelper.h>
#include <third-party/Nlohmann/json.hpp>
#include <LoggerAPI.h>
#include <filesystem>
#include <set>
#include <vector>
using namespace std;
using namespace RegisterCommandHelper;

#define ZIP_PROGRAM_PATH "./plugins/LiteLoader/7z/7za.exe"
#define ADDON_INSTALL_TEMP_DIR "./plugins/LiteLoader/Temp/"
#define ADDON_INSTALL_MAX_WAIT 30000
#define VALID_ADDON_FILE_EXTENSION std::set<string>({".mcpack", ".mcaddon", ".zip"})

Logger addonLogger("AddonHelper");
std::vector<Addon> addons;


void AutoInstallAddons()
{
    std::error_code ec;
    if (!filesystem::exists(LL::globalConfig.addonsInstallPath))
    {
        filesystem::create_directories(LL::globalConfig.addonsInstallPath ,ec);
        addonLogger.warn("Directory created. You can move compressed Addon files to {} to get installed at next launch.",
            LL::globalConfig.addonsInstallPath);
        return;
    }
    std::vector<string> toInstallList;

    filesystem::directory_iterator ent(LL::globalConfig.addonsInstallPath);
    for (auto& file : ent)
    {
        if (!file.is_regular_file())
            continue;

        if (VALID_ADDON_FILE_EXTENSION.find(file.path().extension().u8string()) != VALID_ADDON_FILE_EXTENSION.end())
        {
            toInstallList.push_back(file.path().lexically_normal().u8string());
        }
    }

    if (toInstallList.empty())
        return;

    addonLogger.warn("{} new addon(s) found to install. Working...", toInstallList.size());

    int cnt = 0;
    for (auto& path : toInstallList)
        if (!AddonsManager::install(path))
        {
            //filesystem::remove_all(ADDON_INSTALL_TEMP_DIR, ec);
            break;
        }
        else
        {
            ++cnt;
            addonLogger.warn("Addon {} has beed installed.", path);
        }

    if (cnt == 0)
    {
        addonLogger.error("No addon was installed.");
        return;
    }
    else
    {
        addonLogger.warn("{} addon(s) was installed.", cnt);
        return;
    }
}

//Helper
std::string GetCurrentLevelPath()
{
    try
    {
        return "./worlds/" + Global<PropertiesSettings>->getLevelName();
    }
    catch (...)
    {
        ifstream fin("server.properties");
        string buf;
        while (getline(fin, buf))
        {
            if (buf.find("level-name=") != string::npos)
            {
                if (buf.back() == '\n')  buf.pop_back();
                if (buf.back() == '\r')  buf.pop_back();
                return "./worlds/" + buf.substr(11);
            }
        }
    }
}

void BuildAddonList()
{
    string levelPath = GetCurrentLevelPath();

    //behavior_packs
    string path = levelPath + "/world_behavior_packs.json";

    //??? TODO
}

//Helper
bool InstallAddonToLevel(std::string addonDir, std::string addonName)
{
    Addon::Type addonType;
    string subPath = "";
    string uuid;
    nlohmann::json version;

    // parse addon data
    try
    {
        auto manifest = nlohmann::json::parse(*ReadAllFile(addonDir + "/manifest.json"), nullptr, false, true);
        string type = manifest["modules"][0]["type"];
        if (type == "resources")
        {
            addonType = Addon::Type::ResourcePack;
            subPath = "/resource_packs";
        }
        else if (type == "data")
        {
            addonType = Addon::Type::BehaviorPack;
            subPath = "/behavior_packs";
        }
        else
            throw "Unknown type of addon pack!";

        uuid = manifest["header"]["uuid"];
        version = manifest["header"]["version"];
    }
    catch (const std::exception &e)
    {
        addonLogger.error("Fail to parse the manifest data of addon {}!", addonName);
        addonLogger.error("Error: {}", e.what());
        addonLogger.error("* Install progress aborted!");
        return false;
    }

    // copy files
    string levelPath = GetCurrentLevelPath();
    string toPath = levelPath + subPath + "/" + addonName;

    std::error_code ec;
    filesystem::create_directories(toPath,ec);
    filesystem::copy(addonDir, toPath, filesystem::copy_options::recursive, ec);

    // add addon to list file
    string addonListFile = levelPath;
    if (addonType == Addon::Type::ResourcePack)
        addonListFile += "/world_resource_packs.json";
    else if (addonType == Addon::Type::BehaviorPack)
        addonListFile += "/world_behavior_packs.json";

    if (!filesystem::exists(addonListFile))
    {
        ofstream fout(addonListFile);
        fout << "[]" << flush;
    }

    try
    {
        auto newAddonData = nlohmann::json::object();
        newAddonData["pack_id"] = uuid;
        newAddonData["version"] = version;

        auto addonList = nlohmann::json::parse(*ReadAllFile(addonListFile));
        addonList.push_back(newAddonData);
        bool res = WriteAllFile(addonListFile, addonList.dump(4));
        if (!res)
            throw "Fail to write data back to addon list file!";

        return true;
    }
    catch (const std::exception& e)
    {
        addonLogger.error("Fail to insert the addon {} into {}!", addonName, addonListFile);
        addonLogger.error("Error: {}", e.what());
        addonLogger.error("* Install progress aborted!");
        return false;
    }
}

void FindManifest(vector<string> &result, const string& path)
{
    filesystem::directory_iterator ent(path);
    for (auto& file : ent)
    {
        if (file.is_directory())
        {
            FindManifest(result, file.path().string());
        }
        else {
            auto path = file.path();
            if (path.filename() == "manifest.json")
            {
                result.push_back(filesystem::canonical(path).parent_path().u8string());
                break;
            }
        }
    }
    return;
}

bool AddonsManager::install(std::string packPath)
{
    try
    {
        if (!filesystem::exists(packPath))
        {
            addonLogger.error("Addon file no found!");
            return false;
        }
        if (VALID_ADDON_FILE_EXTENSION.find(filesystem::path(packPath).extension().u8string()) == VALID_ADDON_FILE_EXTENSION.end())
        {
            addonLogger.error("Unsupported type of file found!");
            return false;
        }

        string name = filesystem::path(packPath).filename().u8string();
        addonLogger.warn("Installing addon <{}>...", name);

        std::error_code ec;
        if (EndsWith(packPath, ".mcpack"))
        {
            string newPath = packPath;
            ReplaceStr(newPath, ".mcpack", ".zip");
            filesystem::rename(packPath, newPath, ec);
            packPath = newPath;
        }
        if (EndsWith(packPath, ".mcaddon"))
        {
            string newPath = packPath;
            ReplaceStr(newPath, ".mcaddon", ".zip");
            filesystem::rename(packPath, newPath, ec);
            packPath = newPath;
        }

        filesystem::remove_all(ADDON_INSTALL_TEMP_DIR, ec);
        filesystem::create_directories(ADDON_INSTALL_TEMP_DIR, ec);

        auto res = NewProcessSync(fmt::format("{} x {} -o{} -aoa", ZIP_PROGRAM_PATH, packPath, ADDON_INSTALL_TEMP_DIR), ADDON_INSTALL_MAX_WAIT);
        if (res.first != 0)
        {
            addonLogger.error("Fail to uncompress addon {}!", name);
            addonLogger.error("Exit Code: {}", res.first);
            addonLogger.error("Program Output:\n{}", res.second);
            addonLogger.error("* Install progress aborted!");
            filesystem::remove_all(ADDON_INSTALL_TEMP_DIR, ec);
            return false;
        }

        vector<string> paths;
        FindManifest(paths, ADDON_INSTALL_TEMP_DIR);

        for (auto& dir : paths)
        {
            string addonName = filesystem::path(dir).filename().u8string();
            if (addonName.empty() || addonName == "Temp")
                addonName = filesystem::path(packPath).stem().u8string();
            if (!InstallAddonToLevel(dir, addonName))
                return false;
        }

        filesystem::remove_all(ADDON_INSTALL_TEMP_DIR, ec);
        filesystem::remove_all(packPath, ec);
        return true;
    }
    catch (const seh_exception& e)
    {
        addonLogger.error("Uncaught SEH Exception Detected!");
        addonLogger.error("In AddonsInstaller");
        //addonLogger.error("Error: Code[{}] {}", e.code(), e.what());
        cout << "Error: Code[" << e.code() << "] " << e.what() << endl;     //TODO Issue #223
    }
    catch (const std::exception& e)
    {
        addonLogger.error("Uncaught C++ Exception Detected!");
        addonLogger.error("In AddonsInstaller");
        //addonLogger.error("Error: {}", e.what());
        cout << "Error: " << e.what() << endl;     //TODO Issue #223
    }
    catch (...)
    {
        addonLogger.error("Uncaught Exception Detected!");
        addonLogger.error("In AddonsInstaller");
    }
    return false;
}

bool AddonsManager::uninstall(std::string nameOrUuid)
{

}

std::vector<Addon*> AddonsManager::getAllAddons()
{
    std::vector<Addon*> res;
    for (auto& addon : addons)
        res.push_back(&addon);
    return res;
}

Addon* AddonsManager::getAddon(std::string nameOrUuid)
{
    for (auto& addon : addons)
        if (addon.name == nameOrUuid || addon.uuid == nameOrUuid)
            return &addon;
    return nullptr;
}

class AddonsCommand : public Command {
    enum class Operation
    {
        List, Install, Uninstall
    };

    Operation operation;
    std::string target;

public:
    void execute(CommandOrigin const& ori, CommandOutput& output) const override
    {
        switch (operation)
        {
        case Operation::List:
            break;
        case Operation::Install:
            if (AddonsManager::install(target))
                output.success();
            break;
        case Operation::Uninstall:
            break;
        default:
            break;
        }
    }

    static void setup(CommandRegistry* registry) {
        registry->registerCommand("addons", "LiteLoaderBDS - Addons Helper",
            CommandPermissionLevel::GameMasters, { (CommandFlagValue)0 }, { (CommandFlagValue)0x80 });

        // addons list
        registry->addEnum<Operation>("Operation_Addons_List", {
            {"list", Operation::List}
        });
        registry->registerOverload<AddonsCommand>(
            "addons",
            makeMandatory<CommandParameterDataType::ENUM>(&AddonsCommand::operation, "Operation", "Operation_Addons_List").addOptions((CommandParameterOption)1)
        );

        // addons install
        registry->addEnum<Operation>("Operation_Addons_Install", {
            {"install", Operation::Install}
        });
        registry->registerOverload<AddonsCommand>(
            "addons",
            makeMandatory<CommandParameterDataType::ENUM>(&AddonsCommand::operation, "Operation", "Operation_Addons_Install").addOptions((CommandParameterOption)1),
            makeMandatory<CommandParameterDataType::NORMAL>(&AddonsCommand::target, "Target")
        );

        // addons uninstall
        vector<string> addonsList;
        registry->addSoftEnum("AddonName", addonsList);

        registry->addEnum<Operation>("Operation_Addons_Uninstall", {
            {"uninstall", Operation::Uninstall}
        });
        registry->registerOverload<AddonsCommand>(
            "addons",
            makeMandatory<CommandParameterDataType::ENUM>(&AddonsCommand::operation, "Operation", "Operation_Addons_Uninstall").addOptions((CommandParameterOption)1),
            makeMandatory<CommandParameterDataType::SOFT_ENUM>(&AddonsCommand::target, "AddonName", "AddonName")
        );
    }
};

void InitAddonsHelper()
{
    AutoInstallAddons();
    /*BuildAddonList();

    Event::RegCmdEvent::subscribe([](Event::RegCmdEvent ev) { // Register commands
        AddonsCommand::setup(ev.mCommandRegistry);
        return true;
    });*/
    //TODO
}