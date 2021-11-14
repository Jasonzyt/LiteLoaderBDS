#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <LoggerAPI.h>
#include <Utils/WinHelper.h>
#include <Utils/StringHelper.h>
#include <seh_exception/seh_exception.hpp>
#include <ServerAPI.h>
#include <HookAPI.h>
#include <LLAPI.h>
#include <Version.h>
#include <Config.h>
#include "Loader.h"
using namespace std;


void FixPluginsLibDir() {  // add plugins folder to path
    WCHAR *buffer = new WCHAR[8192];
    auto sz = GetEnvironmentVariableW(TEXT("PATH"), buffer, 8192);
    std::wstring PATH{buffer, sz};
    sz = GetCurrentDirectoryW(8192, buffer);
    std::wstring CWD{buffer, sz};
    SetEnvironmentVariableW(TEXT("PATH"), (CWD + L"\\plugins;" + PATH).c_str());
    delete[] buffer;
}

void FixUpCWD() {
    string buf;
    buf.assign(8192, '\0');
    GetModuleFileNameA(nullptr, buf.data(), 8192);
    buf = buf.substr(0, buf.find_last_of('\\'));
    SetCurrentDirectoryA(buf.c_str());
}

void startWBThread();
void checkUpdate();
void registerCommands();

void LLMain()
{
    //Set global SEH-Exception handler
    _set_se_translator(seh_exception::TranslateSEHtoCE);

    //Prohibit pop-up windows to facilitate automatic restart
    SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX | SEM_NOALIGNMENTFAULTEXCEPT);

    //Disable Output-Sync
    std::ios::sync_with_stdio(false);

    //Fix problems
    FixUpCWD();
    FixPluginsLibDir();

    //Load Config
    LoadLLConfig();

    //Rename Window
    HWND hwnd = GetConsoleWindow();
    std::wstring s = L"Bedrock Delicated Server " + str2wstr(LL::getBdsVersion().substr(1)) + L" with LiteLoaderBDS " + str2wstr(LL::getLoaderVersionString());
    SetWindowText(hwnd, s.c_str());

    //Init LL Logger
    Logger::setTitle("LiteLoader");

    //Load plugins
    LoadMain();

    //XIDREG::initAll();  // Initialize the xuid database
   // registerCommands(); // Register built-in commands
   // Event::addEventListener([](ServerStartedEV) {  // Server started event
   //     startWBThread();
    //    LOG("LiteLoader is distributed under the GPLv3 License");
    //    checkUpdate();
    //});

   // PostInitEV post_init_ev;  // Register PostInit event
   // for (size_t count = 0; count < Post_init_call_backs.size(); count++) {
   //     Post_init_call_backs[count](post_init_ev);
   // }
}

// Call LLMain
THook(int, "main", int a, void* b) {
    LLMain();
    return original(a, b);
}

