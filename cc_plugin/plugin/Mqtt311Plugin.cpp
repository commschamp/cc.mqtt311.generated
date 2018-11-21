#include "Mqtt311Plugin.h"

#include "Mqtt311Protocol.h"

namespace cc = comms_champion;

namespace mqtt311
{

namespace cc_plugin
{

namespace plugin
{

Mqtt311Plugin::Mqtt311Plugin()
{
    pluginProperties()
        .setProtocolCreateFunc(
            []() -> cc::ProtocolPtr
            {
                return cc::ProtocolPtr(new Mqtt311Protocol());
            });
}

Mqtt311Plugin::~Mqtt311Plugin() = default;

} // namespace plugin

} // namespace cc_plugin

} // namespace mqtt311


