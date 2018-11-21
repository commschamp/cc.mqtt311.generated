#include "Publish.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Publish.h"
#include "cc_plugin/field/PacketId.h"
#include "cc_plugin/field/Topic.h"

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
    return cc_plugin::field::createProps_topic(Field::name());
    
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

class PublishImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Publish<mqtt311::cc_plugin::Message>,
        PublishImpl
    >
{
public:
    PublishImpl() = default;
    PublishImpl(const PublishImpl&) = delete;
    PublishImpl(PublishImpl&&) = delete;
    virtual ~PublishImpl() = default;
    PublishImpl& operator=(const PublishImpl&) = default;
    PublishImpl& operator=(PublishImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Publish::Publish() : m_pImpl(new PublishImpl) {}
Publish::~Publish() = default;

Publish& Publish::operator=(const Publish& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Publish& Publish::operator=(Publish&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Publish::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Publish::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Publish::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Publish::resetImpl()
{
    m_pImpl->reset();
}

bool Publish::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Publish*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Publish::MsgIdParamType Publish::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Publish::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Publish::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Publish::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Publish::lengthImpl() const
{
    return m_pImpl->length();
}

bool Publish::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


