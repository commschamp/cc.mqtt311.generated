#pragma once

#include <QtCore/QObject>
#include <QtCore/QtPlugin>
#include "comms_champion/Plugin.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace plugin
{

class Mqtt311Plugin : public comms_champion::Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "mqtt311" FILE "Mqtt311Plugin.json")
    Q_INTERFACES(comms_champion::Plugin)

public:
    Mqtt311Plugin();
    virtual ~Mqtt311Plugin();
};

} // namespace plugin

} // namespace cc_plugin

} // namespace mqtt311


