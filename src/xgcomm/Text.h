#pragma once
#include <string>

namespace xg {
std::wstring gbkToUnicode(const std::string& str);

std::string unicodeToGbk(const std::wstring& str);

std::wstring utf8ToUnicode(const std::string& str);

std::string unicodeToUtf8(const std::wstring& str);

std::string gbkToUtf8(const std::string& str);

std::string utf8ToGbk(const std::string& str);

std::string local8bitToUtf8(const std::string& str);

std::string utf8ToLocal8bit(const std::string& str);
} // namespace xg