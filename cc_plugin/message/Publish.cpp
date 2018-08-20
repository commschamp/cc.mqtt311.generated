#include "Publish.h"

#include "comms_champion/property/field.h"
#include "cc_plugin/field/PacketId.h"
#include "cc_plugin/field/String.h"

namespace cc = comms_champion;

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_topic()
{
    using Field = mqtt311::message::PublishFields<>::Topic;
    return cc_plugin::field::createProps_string(Field::name());
    
}

static QVariantMap createProps_packetId()
{
    using Field = mqtt311::message::PublishFields<>::PacketId;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(cc_plugin::field::createProps_packetId("Packet ID"))
            .asMap();
    
}

static QVariantMap createProps_payload()
{
    using Field = mqtt311::message::PublishFields<>::Payload;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_topic());
    props.append(createProps_packetId());
    props.append(createProps_payload());
    return props;
}

} // namespace

const QVariantList& Publish::fieldsPropertiesImpl() const
{
    static const QVariantList Props = createProps();
    return Props;
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


