#include "Unsubscribe.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Unsubscribe.h"
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

static QVariantMap createProps_packetId()
{
    using Field = mqtt311::message::UnsubscribeFields<>::PacketId;
    return cc_plugin::field::createProps_packetId(Field::name());
    
}

struct ListMembers
{
    static QVariantMap createProps_topic()
    {
        using Field = mqtt311::message::UnsubscribeFields<>::ListMembers::Topic;
        return cc_plugin::field::createProps_topic(Field::name());
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = mqtt311::message::UnsubscribeFields<>::List;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ListMembers::createProps_topic())
            .serialisedHidden()
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_packetId());
    props.append(createProps_list());
    return props;
}

} // namespace

class UnsubscribeImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Unsubscribe<mqtt311::cc_plugin::Message>,
        UnsubscribeImpl
    >
{
public:
    UnsubscribeImpl() = default;
    UnsubscribeImpl(const UnsubscribeImpl&) = delete;
    UnsubscribeImpl(UnsubscribeImpl&&) = delete;
    virtual ~UnsubscribeImpl() = default;
    UnsubscribeImpl& operator=(const UnsubscribeImpl&) = default;
    UnsubscribeImpl& operator=(UnsubscribeImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Unsubscribe::Unsubscribe() : m_pImpl(new UnsubscribeImpl) {}
Unsubscribe::~Unsubscribe() = default;

Unsubscribe& Unsubscribe::operator=(const Unsubscribe& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Unsubscribe& Unsubscribe::operator=(Unsubscribe&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Unsubscribe::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Unsubscribe::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Unsubscribe::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Unsubscribe::resetImpl()
{
    m_pImpl->reset();
}

bool Unsubscribe::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Unsubscribe*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Unsubscribe::MsgIdParamType Unsubscribe::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Unsubscribe::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Unsubscribe::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Unsubscribe::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Unsubscribe::lengthImpl() const
{
    return m_pImpl->length();
}

bool Unsubscribe::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


