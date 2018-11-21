#include "Subscribe.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Subscribe.h"
#include "cc_plugin/field/PacketId.h"
#include "cc_plugin/field/Qos.h"
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
    using Field = mqtt311::message::SubscribeFields<>::PacketId;
    return cc_plugin::field::createProps_packetId(Field::name());
    
}

struct ListMembers
{
    struct ElementMembers
    {
        static QVariantMap createProps_topic()
        {
            using Field = mqtt311::message::SubscribeFields<>::ListMembers::ElementMembers::Topic;
            return cc_plugin::field::createProps_topic(Field::name());
            
        }
        
        static QVariantMap createProps_qos()
        {
            using Field = mqtt311::message::SubscribeFields<>::ListMembers::ElementMembers::Qos;
            return cc_plugin::field::createProps_qos(Field::name());
            
        }
        
    };
    
    static QVariantMap createProps_element()
    {
        using Field = mqtt311::message::SubscribeFields<>::ListMembers::Element;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .add(ElementMembers::createProps_topic())
                .add(ElementMembers::createProps_qos())
                .asMap();
        
    }
    
};

static QVariantMap createProps_list()
{
    using Field = mqtt311::message::SubscribeFields<>::List;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(ListMembers::createProps_element())
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

class SubscribeImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Subscribe<mqtt311::cc_plugin::Message>,
        SubscribeImpl
    >
{
public:
    SubscribeImpl() = default;
    SubscribeImpl(const SubscribeImpl&) = delete;
    SubscribeImpl(SubscribeImpl&&) = delete;
    virtual ~SubscribeImpl() = default;
    SubscribeImpl& operator=(const SubscribeImpl&) = default;
    SubscribeImpl& operator=(SubscribeImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Subscribe::Subscribe() : m_pImpl(new SubscribeImpl) {}
Subscribe::~Subscribe() = default;

Subscribe& Subscribe::operator=(const Subscribe& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Subscribe& Subscribe::operator=(Subscribe&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Subscribe::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Subscribe::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Subscribe::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Subscribe::resetImpl()
{
    m_pImpl->reset();
}

bool Subscribe::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Subscribe*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Subscribe::MsgIdParamType Subscribe::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Subscribe::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Subscribe::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Subscribe::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Subscribe::lengthImpl() const
{
    return m_pImpl->length();
}

bool Subscribe::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


