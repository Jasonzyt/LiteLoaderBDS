//
// Created by RimuruChan on 2021/12/11.
//

#pragma once

#include <LoggerAPI.h>
#include "Main/Config.h"
#include <MC/Player.hpp>

#define LOGGER_CURRENT_TITLE "ll_plugin_logger_title"
#define LOGGER_CURRENT_FILE "ll_plugin_logger_file"
#define LOGGER_CURRENT_LOCK "ll_plugin_logger_lock"

void Logger::initLockImpl(HMODULE hPlugin)
{
    //if (!PluginOwnData::hasImpl(hPlugin, LOGGER_CURRENT_LOCK))
    //    PluginOwnData::setImpl<CsLock>(hPlugin, LOGGER_CURRENT_LOCK);             //May cause DeadLock?
}

void Logger::lockImpl(HMODULE hPlugin)
{
    //initLockImpl(hPlugin);
    //PluginOwnData::getImpl<CsLock>(hPlugin, LOGGER_CURRENT_LOCK).lock();          //May cause DeadLock?
}

void Logger::unlockImpl(HMODULE hPlugin)
{
    //PluginOwnData::getImpl<CsLock>(hPlugin, LOGGER_CURRENT_LOCK).unlock();        //May cause DeadLock?
}

bool Logger::setDefaultFileImpl(HMODULE hPlugin, const std::string& logFile, bool appendMode = true)
{
    if (logFile.empty())
    {
        PluginOwnData::removeImpl<std::ofstream>(hPlugin, LOGGER_CURRENT_FILE);
        return true;
    }
    else
    {
        std::error_code ec;
        std::filesystem::create_directories(std::filesystem::path(logFile).remove_filename(), ec);

        auto& res = PluginOwnData::setImpl<std::ofstream>(hPlugin, LOGGER_CURRENT_FILE, logFile,
                                                          appendMode ? std::ios::app : std::ios::out);
        return res.is_open();
    }
}

bool Logger::setDefaultFileImpl(HMODULE hPlugin, nullptr_t)
{
    PluginOwnData::removeImpl<std::ofstream>(hPlugin, LOGGER_CURRENT_FILE);
    return true;
}


bool Logger::setFile(const std::string& logFile, bool appendMode)
{
    if (ofs.is_open())
        ofs.close();

    if (logFile.empty())
    {
        return true;
    }
    else
    {
        std::error_code ec;
        std::filesystem::create_directories(std::filesystem::path(logFile).remove_filename(), ec);
        ofs.open(logFile, appendMode ? std::ios::app : std::ios::out);
        return ofs.is_open();
    }
}

bool Logger::setFile(nullptr_t)
{
    if (ofs.is_open())
        ofs.close();
    return true;
}

Logger::OutputStream::OutputStream() = default;

Logger::OutputStream::OutputStream(Logger* logger, int level, std::string&& consoleFormat, std::string&& fileFormat,
                                   std::string&& playerFormat,
                                   fmt::text_style&& style, std::string&& levelPrefix)
{
    this->logger = logger;
    this->level = level;
    this->consoleFormat = consoleFormat;
    this->fileFormat = fileFormat;
    this->playerFormat = playerFormat;
    this->style = style;
    this->levelPrefix = levelPrefix;
}

bool checkLogLevel(int level, int outLevel)
{
    if (level >= outLevel)
        return true;
    if (level == -1 && LL::globalConfig.logLevel >= outLevel)
        return true;
    return false;
}
#define H do_hash
fmt::text_style getModeColor(string a1)
{
    if (!LL::globalConfig.colorLog) return fmt::text_style();
    switch (H(a1.c_str()))
    {
        case H("INFO"): return fmt::fg(fmt::color::light_sea_green);
        case H("WARN"): return fmt::fg(fmt::color::yellow2);
        case H("DEBUG"): return fmt::fg(fmt::color::white);
        case H("ERROR"): return fmt::fg(fmt::terminal_color::bright_red);
        case H("FATAL"): return fmt::fg(fmt::color::red);
    }
}

template <typename S, typename Char = fmt::v8::char_t<S>>
std::string applyTextStyle(const fmt::v8::text_style& ts, const S& format_str)
{
    fmt::v8::basic_memory_buffer<Char> buf;
    auto fmt = fmt::v8::to_string_view(format_str);
    bool has_style = false;
    if (ts.has_emphasis())
    {
        has_style = true;
        auto emphasis = fmt::v8::detail::make_emphasis<Char>(ts.get_emphasis());
        buf.append(emphasis.begin(), emphasis.end());
    }
    if (ts.has_foreground())
    {
        has_style = true;
        auto foreground = fmt::v8::detail::make_foreground_color<Char>(ts.get_foreground());
        buf.append(foreground.begin(), foreground.end());
    }
    if (ts.has_background())
    {
        has_style = true;
        auto background = fmt::v8::detail::make_background_color<Char>(ts.get_background());
        buf.append(background.begin(), background.end());
    }
    buf.append(fmt.begin(), fmt.end());
    if (has_style) fmt::v8::detail::reset_color<Char>(buf);
    return fmt::to_string(buf);
}

void Logger::endlImpl(HMODULE hPlugin, OutputStream& o)
{
    std::string title = o.logger->title;
    if (!title.empty())
        title = "[" + title + "]";
    if (checkLogLevel(o.logger->consoleLevel, o.level))
    {
        fmt::print(
            o.consoleFormat, 
            applyTextStyle(LL::globalConfig.colorLog ? fg(fmt::color::light_blue) : fmt::text_style(), 
                fmt::format("{:%H:%M:%S}", fmt::localtime(_time64(nullptr)))),
            applyTextStyle(getModeColor(o.levelPrefix), o.levelPrefix), 
            applyTextStyle(LL::globalConfig.colorLog ? o.style : fmt::text_style(), title),
            applyTextStyle(LL::globalConfig.colorLog ? o.style : fmt::text_style(), o.os.str()));

    }

    if (checkLogLevel(o.logger->fileLevel, o.level))
    {
        if (o.logger->ofs.is_open() || PluginOwnData::hasImpl(hPlugin, LOGGER_CURRENT_FILE))
        {
            auto fileContent = fmt::format(o.fileFormat, fmt::localtime(_time64(nullptr)), o.levelPrefix, title,
                                           o.os.str());
            if (o.logger->ofs.is_open())
                o.logger->ofs << fileContent << std::flush;
            else
                PluginOwnData::getImpl<std::ofstream>(hPlugin, LOGGER_CURRENT_FILE)
                    << fileContent << std::flush;
        }
    }
    if (checkLogLevel(o.logger->playerLevel, o.level) && o.logger->player && Player::isValid(o.logger->player))
        o.logger->player->sendTextPacket(
            fmt::format(o.playerFormat, fmt::localtime(_time64(nullptr)), o.levelPrefix, title,
                        o.os.str()));

    o.locked = false;
    o.os.str("");
    o.os.clear();
    unlockImpl(hPlugin);
}

Logger::Logger(const std::string& title)
{
    this->title = title;
    debug = OutputStream{this,
                         5,
                         "{} {} {} {}\n",
                         "[{:%Y-%m-%d %H:%M:%S} {}]{} {}\n",
                         "§o[{}{}]{} {}\n",
                         fmt::fg(fmt::terminal_color::white) | fmt::emphasis::italic,
                         "DEBUG"};
    info = OutputStream{this,
                        4,
                        "{} {} {} {}\n",
                        "[{:%Y-%m-%d %H:%M:%S} {}]{} {}\n",
                        "[{}{}]{} {}\n",
                        fmt::fg(fmt::terminal_color::white),
                        "INFO"};
    warn = OutputStream{this,
                        3,
                        "{} {} {} {}\n",
                        "[{:%Y-%m-%d %H:%M:%S} {}]{} {}\n",
                        "§l§e[{}{}]{} {}\n",
                        fmt::fg(fmt::terminal_color::yellow) | fmt::emphasis::bold,
                        "WARN"};
    error = OutputStream{this,
                         2,
                         "{} {} {} {}\n",
                         "[{:%Y-%m-%d %H:%M:%S} {}]{} {}\n",
                         "§l§c[{}{}]{} {}\n",
                         fmt::fg(fmt::color::red2) | fmt::emphasis::bold,
                         "ERROR"};
    fatal = OutputStream{this,
                         1,
                         "{} {} {} {}\n",
                         "[{:%Y-%m-%d %H:%M:%S} {}]{} {}\n",
                         "§l§4[{}{}]{} {}\n",
                         fmt::fg(fmt::color::red) | fmt::emphasis::bold,
                         "FATAL"};
}