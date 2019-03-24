#include "Disconnect.h"

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

Disconnect::Disconnect() = default;
Disconnect::~Disconnect() = default;
Disconnect& Disconnect::operator=(const Disconnect&) = default;
Disconnect& Disconnect::operator=(Disconnect&&) = default;

const QVariantList& Disconnect::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


