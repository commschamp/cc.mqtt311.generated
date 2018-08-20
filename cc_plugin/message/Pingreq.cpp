#include "Pingreq.h"

#include "comms_champion/property/field.h"
namespace cc = comms_champion;

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

namespace
{

QVariantList createProps()
{
    QVariantList props;
    return props;
}

} // namespace

const QVariantList& Pingreq::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


