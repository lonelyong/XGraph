#include <xg/comm/Environment.h>

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
    // 先去掉可执行文件名，得到所在目录
    size_t pos = fullPath.find_last_of("\\/");
    if (pos != std::string::npos) {
        fullPath = fullPath.substr(0, pos);
    }
    // 再去掉目录名，得到父级目录
    pos = fullPath.find_last_of("\\/");
    if (pos != std::string::npos) {
        fullPath = fullPath.substr(0, pos);
    }
    return fullPath;
#else
    // todo: MAX_PATH
    char    path[256];
    ssize_t len = ::readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len == -1) {
        return {};
    }
    path[len] = '\0';
    std::string fullPath(path);
    // 先去掉可执行文件名，得到所在目录
    size_t pos = fullPath.find_last_of("/");
    if (pos != std::string::npos) {
        fullPath = fullPath.substr(0, pos);
    }
    // 再去掉目录名，得到父级目录
    pos = fullPath.find_last_of("/");
    if (pos != std::string::npos) {
        fullPath = fullPath.substr(0, pos);
    }
    return fullPath;
#endif
}

} // namespace xg