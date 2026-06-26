#include <xg/comm/Text.hpp>

#include <codecvt>
#include <cstring>
#include <locale>

#ifdef _WIN32
#    include <Windows.h>
#endif // _WIN32


namespace xg {
namespace {

#ifdef _WIN32
class codecvt_gbk : public std::codecvt_byname<wchar_t, char, std::mbstate_t> {
  public:
    codecvt_gbk()
      : codecvt_byname("zh_CN")
    {
    }
};

std::wstring_convert<codecvt_gbk> s_GbkConvert;
#endif

std::wstring_convert<std::codecvt_utf8<wchar_t>> s_Utf8Convert;

} // namespace

#ifdef _WIN32
std::wstring gbkToUnicode(const std::string& str) {
    return s_GbkConvert.from_bytes(str);
}
std::string unicodeToGbk(const std::wstring& str) {
    return s_GbkConvert.to_bytes(str);
}
#else
std::wstring gbkToUnicode(const std::string& str) {
    return utf8ToUnicode(str);
}
std::string unicodeToGbk(const std::wstring& str) {
    return unicodeToUtf8(str);
}
#endif

std::wstring utf8ToUnicode(const std::string& str) {
    return s_Utf8Convert.from_bytes(str);
}
std::string unicodeToUtf8(const std::wstring& str) {
    return s_Utf8Convert.to_bytes(str);
}

#ifdef _WIN32
std::string gbkToUtf8(const std::string& str) {
    return s_Utf8Convert.to_bytes(s_GbkConvert.from_bytes(str));
}
std::string utf8ToGbk(const std::string& str) {
    std::u8string s((const char8_t*)str.data());
    return s_GbkConvert.to_bytes(s_Utf8Convert.from_bytes(str));
}
#else
std::string gbkToUtf8(const std::string& str) {
    return str;
}
std::string utf8ToGbk(const std::string& str) {
    return str;
}
#endif

std::string local8bitToUtf8(const std::string& str) {
    if (str.empty()) {
        return str;
    }
#ifdef _WIN32
    int          tmpLen = MultiByteToWideChar(CP_ACP, 0, str.data(), -1, NULL, 0);
    std::wstring tempStr(tmpLen + 1, WCHAR(0));
    MultiByteToWideChar(CP_ACP, 0, str.data(), -1, tempStr.data(), tmpLen + 1);
    return unicodeToUtf8(tempStr);
#else
    return str;
#endif
}
std::string utf8ToLocal8bit(const std::string& str) {
    if (str.empty()) {
        return str;
    }
#ifdef _WIN32
    /* auto         wstr   = utf8ToUnicode(str);
     int          tmpLen = WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, NULL, 0);
     std::wstring tempStr(tmpLen + 1, WCHAR(0));
     MultiByteToWideChar(CP_ACP, 0, str.data(), -1, tempStr.data(), tmpLen + 1);
     return unicodeToUtf8(tempStr);*/
    return str;
#else
    return str;
#endif
}
} // namespace xg