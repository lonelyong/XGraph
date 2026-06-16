#pragma once
#include <string>
namespace xg {
class Logger {
  public:
    virtual void log(const char* msg) = 0;
    virtual void log(const std::string& msg) = 0;
};

} // namespace xg