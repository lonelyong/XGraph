#include <xg/comm/Text.hpp>

#include <codecvt>
#include <cstring>
#include <locale>

#ifdef _WIN32
#    include <Windows.h>
#endif // _WIN32


namespace xg
{
namespace
{

// #ifdef _WIN32
// class codecvt_gbk : public std::codecvt_byname<wchar_t, char, std::mbstate_t> {
//   public:
//     codecvt_gbk()
//       : codecvt_byname("zh_CN")
//     {}
// };
//
// std::wstring_convert<codecvt_gbk> s_GbkConvert;
// #endif

std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> s_utf8_wchar_cvt;

} // namespace

std::wstring utf8ToWide(const std::string& str)
{ return s_utf8_wchar_cvt.from_bytes(str); }

std::string wideToUtf8(const std::wstring& str)
{ return s_utf8_wchar_cvt.to_bytes(str); }

std::string local8bitToUtf8(const std::string& str)
{
    if (str.empty()) { return str; }
#ifdef _WIN32
    // cbMultiByte == -1时，MultiByteToWideChar返回的长度包含'\0'，比实际字符数多1
    const int    tmp_len = MultiByteToWideChar(CP_ACP, 0, str.data(), -1, nullptr, 0);
    std::wstring tmp_str(tmp_len - 1, wchar_t{});
    MultiByteToWideChar(CP_ACP, 0, str.data(), -1, tmp_str.data(), tmp_len);
    return wideToUtf8(tmp_str);
#else
    return str;
#endif
}

std::string utf8ToLocal8bit(const std::string& str)
{
    if (str.empty()) { return str; }
#ifdef _WIN32
    auto wstr           = utf8ToWide(str);
    // cbMultiByte == -1时，WideCharToMultiByte返回的长度包含'\0'，比实际字符数多1
    int         tmp_len = WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, nullptr, 0, nullptr, nullptr);
    std::string tmp_str(tmp_len - 1, char{});
    WideCharToMultiByte(CP_ACP, 0, wstr.data(), -1, tmp_str.data(), tmp_len, nullptr, nullptr);
    return tmp_str;
#else
    return str;
#endif
}

} // namespace xg