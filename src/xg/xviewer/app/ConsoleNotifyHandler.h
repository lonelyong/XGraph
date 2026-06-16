#pragma once

#include <osg/Notify>

namespace xviewer {

class ConsoleNotifyHandler : public osg::NotifyHandler {

  public:
    ConsoleNotifyHandler();

  public:
    virtual void notify(osg::NotifySeverity severity, const char* message) override;
    virtual void notifyLevel0(osg::NotifySeverity severity, const std::string& message);
    virtual void notifyLevel1(osg::NotifySeverity severity, const std::string& message);
    virtual void notifyLevel2(osg::NotifySeverity severity, const std::string& message);
    virtual void notifyLevel3(osg::NotifySeverity severity, const std::string& message) {}

    void*       _handle;
};
} // namespace xviewer