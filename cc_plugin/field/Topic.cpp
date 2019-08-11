#include "Topic.h"

#include "cc_plugin/field/String.h"
#include "comms_champion/property/field.h"
#include "mqtt311/field/Topic.h"


namespace cc = comms_champion;

namespace mqtt311
{

namespace cc_plugin
{

namespace field
{

QVariantMap createProps_topic(const char* name, bool serHidden)
{
    auto props = cc_plugin::field::createProps_string(name, serHidden);
    return props;
    
}

} // namespace field

} // namespace cc_plugin

} // namespace mqtt311


