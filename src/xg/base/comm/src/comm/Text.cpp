#include <xg/comm/Text.hpp>

#include <codecvt>
#include <cstring>
#include <locale>

#ifdef _WIN32
#    include <Windows.h>
#endif // _WIN32


namespace xg {
namespace {
class codecvt_gbk : public std::codecvt_byname<wchar_t, char, std::mbstate_t> {
  public:
    codecvt_gbk()
#ifdef _WIN32
      : codecvt_byname("zh_CN")
#else
      : codecvt_byname("zh_CN.GBK")
#endif
    {
    }
};

std::wstring_convert<codecvt_gbk>                s_GbkConvert;
std::wstring_convert<std::codecvt_utf8<wchar_t>> s_Utf8Convert;

} // namespace

std::wstring gbkToUnicode(const std::string& str) {
    return s_GbkConvert.from_bytes(str);
}
std::string unicodeToGbk(const std::wstring& str) {
    return s_GbkConvert.to_bytes(str);
}
std::wstring utf8ToUnicode(const std::string& str) {
    return s_Utf8Convert.from_bytes(str);
}
std::string unicodeToUtf8(const std::wstring& str) {
    return s_Utf8Convert.to_bytes(str);
}
std::string gbkToUtf8(const std::string& str) {
    return s_Utf8Convert.to_bytes(s_GbkConvert.from_bytes(str));
}
std::string utf8ToGbk(const std::string& str) {
    std::u8string s((const char8_t*)str.data());
    return s_GbkConvert.to_bytes(s_Utf8Convert.from_bytes(str));
}
std::string local8bitToUtf8(const std::string& str) {
    if (str.empty()) {
        return str;
    }
#ifdef _WIN32
    int          tmpLen = MultiByteToWideChar(CP_ACP, 0, str.data(), -1, NULL, 0);
    std::wstring tempStr(tmpLen + 1, WCHAR(0));
    MultiByteToWideChar(CP_ACP, 0, str.data(), -1, tempStr.data(), tmpLen + 1);
    return unicodeToUtf8(tempStr);

#endif // _WIN32
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

#endif // _WIN32
}
} // namespace xg