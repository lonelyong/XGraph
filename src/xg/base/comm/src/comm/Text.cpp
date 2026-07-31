#include <xg/comm/Text.hpp>

#include <cstring>
#include <string_view>

#ifdef _WIN32
#    include <Windows.h>
#else
#    include <cerrno>
#    include <iconv.h>
#endif // _WIN32


namespace xg
{
namespace
{

#ifndef _WIN32

/**
 * @brief Generic iconv-based byte-to-byte conversion with dynamic output buffer.
 *
 * Starts with a reasonable initial output capacity and doubles the buffer
 * on E2BIG, avoiding a fixed worst-case assumption.
 *
 * @param from_code Source encoding name (e.g. "UTF-8", "WCHAR_T", "" for locale).
 * @param to_code   Target encoding name.
 * @param in_buf    Input byte buffer.
 * @param in_len    Input byte length.
 * @return Converted byte string, or empty on failure.
 */
[[nodiscard]] std::string iconvConvert(const char* from_code, const char* to_code, const char* in_buf, size_t in_len)
{
    if (in_len == 0) { return {}; }

    iconv_t cd = iconv_open(to_code, from_code);
    if (cd == (iconv_t)-1) { return {}; }

    // RAII cleanup for the conversion descriptor.
    struct IconvGuard {
        iconv_t handle;

        ~IconvGuard()
        { iconv_close(handle); }
    } guard{ cd };

    std::string result;

    // Initial capacity: 4× is the known worst case (UTF-8 → UTF-32).
    // The loop below handles any overflow via dynamic expansion.
    size_t out_capacity = in_len * 4;
    result.resize(out_capacity);

    char*  in_ptr   = const_cast<char*>(in_buf);
    size_t in_bytes = in_len;

    while (in_bytes > 0) {
        size_t consumed  = result.size() - out_capacity;
        char*  out_ptr   = result.data() + consumed;
        size_t out_bytes = out_capacity;

        size_t ret = iconv(cd, &in_ptr, &in_bytes, &out_ptr, &out_bytes);

        if (ret == static_cast<size_t>(-1)) {
            if (errno == E2BIG) {
                // Output buffer exhausted; double and retry.
                out_capacity *= 2;
                result.resize(consumed + out_capacity);
                continue;
            }
            // Unrecoverable conversion error (EILSEQ, EINVAL).
            return {};
        }

        // Success — trim to actual bytes written.
        result.resize(consumed + (out_capacity - out_bytes));
        break;
    }

    return result;
}

#endif // !_WIN32

} // namespace

std::wstring utf8ToWide(std::string_view str)
{
    if (str.empty()) { return {}; }

#if defined(_WIN32)
    // UTF-8 → UTF-16 with strict validation (fail on invalid sequences).
    const int wlen = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, str.data(), static_cast<int>(str.size()), nullptr, 0);
    if (wlen <= 0) { return {}; }

    std::wstring result(wlen, L'\0');
    MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, str.data(), static_cast<int>(str.size()), result.data(), wlen);
    return result;
#else
    // UTF-8 → WCHAR_T (UTF-32 on Linux).
    auto bytes = iconvConvert("UTF-8", "WCHAR_T", str.data(), str.size());
    if (bytes.empty()) { return {}; }

    // Avoid reinterpret_cast — use memcpy to stay within strict-aliasing rules.
    std::wstring result(bytes.size() / sizeof(wchar_t), L'\0');
    std::memcpy(result.data(), bytes.data(), bytes.size());
    return result;
#endif
}

std::string wideToUtf8(std::wstring_view wstr)
{
    if (wstr.empty()) { return {}; }

#if defined(_WIN32)
    // UTF-16 → UTF-8 with strict validation.
    const int size = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, wstr.data(), static_cast<int>(wstr.size()), nullptr, 0, nullptr, nullptr);
    if (size <= 0) { return {}; }

    std::string result(size, '\0');
    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, wstr.data(), static_cast<int>(wstr.size()), result.data(), size, nullptr, nullptr);
    return result;
#else
    // WCHAR_T (UTF-32 on Linux) → UTF-8.
    return iconvConvert("WCHAR_T", "UTF-8", reinterpret_cast<const char*>(wstr.data()), wstr.size() * sizeof(wchar_t));
#endif
}

std::string local8bitToUtf8(std::string_view str)
{
    if (str.empty()) { return {}; }

#if defined(_WIN32)
    // CP_ACP → UTF-16 → UTF-8.
    const int wlen = MultiByteToWideChar(CP_ACP, 0, str.data(), static_cast<int>(str.size()), nullptr, 0);
    if (wlen <= 0) { return {}; }

    std::wstring wide(wlen, L'\0');
    MultiByteToWideChar(CP_ACP, 0, str.data(), static_cast<int>(str.size()), wide.data(), wlen);

    const int size = WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, wide.data(), static_cast<int>(wide.size()), nullptr, 0, nullptr, nullptr);
    if (size <= 0) { return {}; }

    std::string result(size, '\0');
    WideCharToMultiByte(CP_UTF8, WC_ERR_INVALID_CHARS, wide.data(), static_cast<int>(wide.size()), result.data(), size, nullptr, nullptr);
    return result;
#else
    // Locale encoding → UTF-8 ("" picks up the current locale).
    return iconvConvert("", "UTF-8", str.data(), str.size());
#endif
}

std::string utf8ToLocal8bit(std::string_view str)
{
    if (str.empty()) { return {}; }

#if defined(_WIN32)
    // UTF-8 → UTF-16 → CP_ACP.
    const int wlen = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, str.data(), static_cast<int>(str.size()), nullptr, 0);
    if (wlen <= 0) { return {}; }

    std::wstring wide(wlen, L'\0');
    MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, str.data(), static_cast<int>(str.size()), wide.data(), wlen);

    const int size = WideCharToMultiByte(CP_ACP, 0, wide.data(), static_cast<int>(wide.size()), nullptr, 0, nullptr, nullptr);
    if (size <= 0) { return {}; }

    std::string result(size, '\0');
    WideCharToMultiByte(CP_ACP, 0, wide.data(), static_cast<int>(wide.size()), result.data(), size, nullptr, nullptr);
    return result;
#else
    // UTF-8 → locale encoding.
    return iconvConvert("UTF-8", "", str.data(), str.size());
#endif
}

std::wstring local8bitToWide(std::string_view str)
{
    if (str.empty()) { return {}; }

#if defined(_WIN32)
    // CP_ACP → UTF-16.
    const int wlen = MultiByteToWideChar(CP_ACP, 0, str.data(), static_cast<int>(str.size()), nullptr, 0);
    if (wlen <= 0) { return {}; }

    std::wstring result(wlen, L'\0');
    MultiByteToWideChar(CP_ACP, 0, str.data(), static_cast<int>(str.size()), result.data(), wlen);
    return result;
#else
    // Locale encoding → WCHAR_T (UTF-32 on Linux).
    auto bytes = iconvConvert("", "WCHAR_T", str.data(), str.size());
    if (bytes.empty()) { return {}; }

    std::wstring result(bytes.size() / sizeof(wchar_t), L'\0');
    std::memcpy(result.data(), bytes.data(), bytes.size());
    return result;
#endif
}

std::string wideToLocal8bit(std::wstring_view wstr)
{
    if (wstr.empty()) { return {}; }

#if defined(_WIN32)
    // UTF-16 → CP_ACP.
    const int size = WideCharToMultiByte(CP_ACP, 0, wstr.data(), static_cast<int>(wstr.size()), nullptr, 0, nullptr, nullptr);
    if (size <= 0) { return {}; }

    std::string result(size, '\0');
    WideCharToMultiByte(CP_ACP, 0, wstr.data(), static_cast<int>(wstr.size()), result.data(), size, nullptr, nullptr);
    return result;
#else
    // WCHAR_T (UTF-32 on Linux) → locale encoding.
    return iconvConvert("WCHAR_T", "", reinterpret_cast<const char*>(wstr.data()), wstr.size() * sizeof(wchar_t));
#endif
}

} // namespace xg