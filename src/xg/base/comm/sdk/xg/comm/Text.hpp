#pragma once
#include <string>
#include <string_view>

namespace xg
{

/**
 * @brief Converts a UTF-8 string to a wide string.
 *
 * On Windows the result is UTF-16; on Linux the result is UTF-32.
 * This is the primary conversion for interacting with platform wide-string APIs.
 *
 * @param str UTF-8 encoded input.
 * @return Wide string, or empty on failure.
 */
std::wstring utf8ToWide(std::string_view str);

/**
 * @brief Converts a wide string to UTF-8.
 *
 * @param wstr Wide string (UTF-16 on Windows, UTF-32 on Linux).
 * @return UTF-8 encoded string, or empty on failure.
 */
std::string wideToUtf8(std::wstring_view wstr);

/**
 * @brief Converts a locale-encoded string to UTF-8.
 *
 * @deprecated Depends on system locale encoding and may produce different
 *             results on different machines. Prefer storing text as UTF-8
 *             and using utf8ToWide() / wideToUtf8() instead.
 *
 * @param str String in the current system locale encoding.
 * @return UTF-8 encoded string, or empty on failure.
 */
std::string local8bitToUtf8(std::string_view str);

/**
 * @brief Converts a UTF-8 string to locale encoding.
 *
 * @deprecated Depends on system locale encoding and may produce different
 *             results on different machines. Prefer storing text as UTF-8
 *             and using utf8ToWide() / wideToUtf8() instead.
 *
 * @param str UTF-8 encoded input.
 * @return Locale-encoded string, or empty on failure.
 */
std::string utf8ToLocal8bit(std::string_view str);

/**
 * @brief Converts a locale-encoded string to a wide string.
 *
 * @deprecated Depends on system locale encoding. Prefer utf8ToWide()
 *             with UTF-8 input instead.
 *
 * @param str String in the current system locale encoding.
 * @return Wide string, or empty on failure.
 */
std::wstring local8bitToWide(std::string_view str);

/**
 * @brief Converts a wide string to locale encoding.
 *
 * @deprecated Depends on system locale encoding. Prefer wideToUtf8()
 *             and store the result as UTF-8 instead.
 *
 * @param wstr Wide string (UTF-16 on Windows, UTF-32 on Linux).
 * @return Locale-encoded string, or empty on failure.
 */
std::string wideToLocal8bit(std::wstring_view wstr);

} // namespace xg