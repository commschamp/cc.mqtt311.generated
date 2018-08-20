#include "Pubrel.h"

#include "comms_champion/property/field.h"
#include "cc_plugin/field/PacketId.h"

namespace cc = comms_champion;

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_packetId()
{
    using Field = mqtt311::message::PubrelFields<>::PacketId;
    return cc_plugin::field::createProps_packetId(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_packetId());
    return props;
}

} // namespace

const QVariantList& Pubrel::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


