#include "Environment.h"

#ifdef _WIN32
#    include <Windows.h>
#elif defined(__linux__) || defined(__unix__) || defined(__APPLE__)
#    include <unistd.h>
#endif
namespace xg
{

std::string getApplicationDir()
{
#ifdef _WIN32
    HMODULE hModule = GetModuleHandle(NULL);
    char    path[MAX_PATH];
    GetModuleFileNameA(hModule, path, MAX_PATH);
    std::string fullPath(path);
    size_t      pos = fullPath.find_last_of("\\");
    return fullPath.substr(0, pos);
#else
    // todo: MAX_PATH
    char    path[256];
    ssize_t len = ::readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len == -1) {
        return {};
    }
    path[len] = '\0';
    std::string fullPath(path);
    size_t      pos = fullPath.find_last_of("/");
    return fullPath.substr(0, pos);
#endif
}

} // namespace xg