#include "ConsoleNotifyHandler.h"

#include <cstdint>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <mutex>
#include <string>
#include <chrono>

// before Windows.h, NOMINMAX
#include <backward.hpp>


#ifdef _WIN32
#    include <Windows.h>
#endif // _WIN32


namespace glv {
namespace {

static std::mutex g_syncout_mutex;

struct SyncConsoleOut {
    std::unique_lock<std::mutex> _lock;
    SyncConsoleOut()
      : _lock(std::unique_lock<std::mutex>(g_syncout_mutex)) {}
    template <typename T> SyncConsoleOut& operator<<(const T& _t) {
        std::cout << _t;
        return *this;
    }
    SyncConsoleOut& operator<<(std::ostream& (*fp)(std::ostream&)) {
        std::cout << fp;
        return *this;
    }
};

std::string getDateTimeTick() {
    auto tick        = std::chrono::system_clock::now();
    auto posix       = std::chrono::system_clock::to_time_t(tick);
    auto millseconds = std::chrono::duration_cast<std::chrono::milliseconds>(tick.time_since_epoch()).count() -
                       std::chrono::duration_cast<std::chrono::seconds>(tick.time_since_epoch()).count() * 1000;

    char        buf[20] = { 0 }, buf2[5] = { 0 };
    std::tm     tp = *std::localtime(&posix);
    std::string dateTime{ buf, std::strftime(buf, sizeof(buf), "%F %T", &tp) };
    snprintf(buf2, sizeof(buf2), ".%03d", (int)millseconds);
    return dateTime + std::string(buf2);
}

} // namespace

ConsoleNotifyHandler::ConsoleNotifyHandler()
  : _handle(nullptr) {
#ifdef _WIN32
    // https://learn.microsoft.com/en-us/windows/console/console-screen-buffers
    _handle = GetStdHandle(STD_OUTPUT_HANDLE);
#else
    // https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
#endif
}

void ConsoleNotifyHandler::notifyLevel0(osg::NotifySeverity severity, const std::string& message) {
    std::string header = message.length() < 5 ? "" : "[FATAL   " + getDateTimeTick() + "] ";
#ifdef _WIN32
    SetConsoleTextAttribute(_handle, FOREGROUND_RED);
    SyncConsoleOut() << header << message;
    SetConsoleTextAttribute(_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#elif defined(VERSE_WEBGL1) || defined(VERSE_WEBGL2)
    SyncConsoleOut() << header << message;
#else
    SyncConsoleOut() << "\033[91m" << header << message << "\033[0m";
#endif
}

void ConsoleNotifyHandler::notifyLevel1(osg::NotifySeverity severity, const std::string& message) {
    std::string header = message.length() < 5 ? "" : "[WARNING " + getDateTimeTick() + "] ";
#ifdef _WIN32
    SetConsoleTextAttribute(_handle, FOREGROUND_RED | FOREGROUND_GREEN);
    SyncConsoleOut() << header << message;
    SetConsoleTextAttribute(_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#elif defined(VERSE_WEBGL1) || defined(VERSE_WEBGL2)
    SyncConsoleOut() << header << message;
#else
    SyncConsoleOut() << "\033[33m" << header << message << "\033[0m";
#endif
}

void ConsoleNotifyHandler::notifyLevel2(osg::NotifySeverity severity, const std::string& message) {
    std::string header = message.length() < 5 ? "" : "[NOTICE  " + getDateTimeTick() + "] ";
#ifdef _WIN32
    SyncConsoleOut() << header << message;
#elif defined(VERSE_WEBGL1) || defined(VERSE_WEBGL2)
    SyncConsoleOut() << header << message;
#else
    SyncConsoleOut() << "\033[37m" << header << message << "\033[0m";
#endif
}

void ConsoleNotifyHandler::notify(osg::NotifySeverity severity, const char* message) {
    std::string msg(message);
    if (severity <= osg::NotifySeverity::WARN) {
        backward::Printer    printer;
        backward::StackTrace st;
        st.load_here(10);
        st.skip_n_firsts(2);
        std::stringstream ss;
        ss << std::string(15, '#') << "\n";
        printer.print(st, ss);
        msg += ss.str() + std::string(15, '#') + "\n";
    }

    switch (severity) {
    case osg::NotifySeverity::ALWAYS: notifyLevel0(severity, msg); break;
    case osg::NotifySeverity::FATAL: notifyLevel0(severity, msg); break;
    case osg::NotifySeverity::WARN: notifyLevel1(severity, msg); break;
    case osg::NotifySeverity::NOTICE: notifyLevel2(severity, msg); break;
    case osg::NotifySeverity::INFO: notifyLevel2(severity, msg); break;
    case osg::NotifySeverity::DEBUG_INFO: notifyLevel3(severity, msg); break;
    case osg::NotifySeverity::DEBUG_FP: notifyLevel3(severity, msg); break;
    default: notifyLevel3(severity, msg); break;
    }
}

} // namespace glv