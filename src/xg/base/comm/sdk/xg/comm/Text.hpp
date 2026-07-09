#pragma once
#include <string>

namespace xg
{

std::wstring utf8ToWide(const std::string& str);

std::string wideToUtf8(const std::wstring& str);

std::string local8bitToUtf8(const std::string& str);

std::string utf8ToLocal8bit(const std::string& str);

} // namespace xg