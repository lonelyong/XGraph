#pragma once

#include <xg/glr/app/Application.hpp>

namespace xg
{
namespace glr
{

class SampleApplication : public xg::glr::Application {
  public:
    SampleApplication(const xg::glr::AppParameters& params);

  public:
    virtual bool initQt();

    virtual bool isQtInitialized() const;
};

} // namespace glr
} // namespace xg