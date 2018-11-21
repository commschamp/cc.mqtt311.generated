#include "Connect.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Connect.h"
#include "cc_plugin/field/BinData.h"
#include "cc_plugin/field/ProtocolName.h"
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

static QVariantMap createProps_protocolName()
{
    using Field = mqtt311::message::ConnectFields<>::ProtocolName;
    return cc_plugin::field::createProps_protocolName(Field::name());
    
}

static QVariantMap createProps_protocolLevel()
{
    using Field = mqtt311::message::ConnectFields<>::ProtocolLevel;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

struct FlagsMembers
{
    static QVariantMap createProps_low()
    {
        using Field = mqtt311::message::ConnectFields<>::FlagsMembers::Low;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(1U, "Clean Session")
                .add(2U, "Will Flag")
                .asMap();
        
    }
    
    static QVariantMap createProps_willQos()
    {
        using Field = mqtt311::message::ConnectFields<>::FlagsMembers::WillQos;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add("AtMostOnceDelivery", 0)
                .add("AtLeastOnceDelivery", 1)
                .add("ExactlyOnceDelivery", 2)
                .asMap();
        
    }
    
    static QVariantMap createProps_high()
    {
        using Field = mqtt311::message::ConnectFields<>::FlagsMembers::High;
        return
            cc::property::field::ForField<Field>()
                .name(Field::name())
                .serialisedHidden()
                .add(0U, "Will Retain")
                .add(1U, "Password Flag")
                .add(2U, "User Name Flag")
                .asMap();
        
    }
    
};

static QVariantMap createProps_flags()
{
    using Field = mqtt311::message::ConnectFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(FlagsMembers::createProps_low())
            .add(FlagsMembers::createProps_willQos())
            .add(FlagsMembers::createProps_high())
            .asMap();
    
}

static QVariantMap createProps_keepAlive()
{
    using Field = mqtt311::message::ConnectFields<>::KeepAlive;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .asMap();
    
}

static QVariantMap createProps_clientId()
{
    using Field = mqtt311::message::ConnectFields<>::ClientId;
    return cc_plugin::field::createProps_string(Field::name());
    
}

struct WillTopicMembers
{
    static QVariantMap createProps_willTopic()
    {
        using Field = mqtt311::message::ConnectFields<>::WillTopicMembers::WillTopic;
        return cc_plugin::field::createProps_string(Field::name());
        
    }
    
};

static QVariantMap createProps_willTopic()
{
    using Field = mqtt311::message::ConnectFields<>::WillTopic;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(WillTopicMembers::createProps_willTopic())
            .asMap();
    
}

struct WillMessageMembers
{
    static QVariantMap createProps_willMessage()
    {
        using Field = mqtt311::message::ConnectFields<>::WillMessageMembers::WillMessage;
        return cc_plugin::field::createProps_binData(Field::name());
        
    }
    
};

static QVariantMap createProps_willMessage()
{
    using Field = mqtt311::message::ConnectFields<>::WillMessage;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(WillMessageMembers::createProps_willMessage())
            .asMap();
    
}

struct UserNameMembers
{
    static QVariantMap createProps_userName()
    {
        using Field = mqtt311::message::ConnectFields<>::UserNameMembers::UserName;
        return cc_plugin::field::createProps_string(Field::name());
        
    }
    
};

static QVariantMap createProps_userName()
{
    using Field = mqtt311::message::ConnectFields<>::UserName;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(UserNameMembers::createProps_userName())
            .asMap();
    
}

struct PasswordMembers
{
    static QVariantMap createProps_password()
    {
        using Field = mqtt311::message::ConnectFields<>::PasswordMembers::Password;
        return cc_plugin::field::createProps_binData(Field::name());
        
    }
    
};

static QVariantMap createProps_password()
{
    using Field = mqtt311::message::ConnectFields<>::Password;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .uncheckable()
            .field(PasswordMembers::createProps_password())
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_protocolName());
    props.append(createProps_protocolLevel());
    props.append(createProps_flags());
    props.append(createProps_keepAlive());
    props.append(createProps_clientId());
    props.append(createProps_willTopic());
    props.append(createProps_willMessage());
    props.append(createProps_userName());
    props.append(createProps_password());
    return props;
}

} // namespace

class ConnectImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Connect<mqtt311::cc_plugin::Message>,
        ConnectImpl
    >
{
public:
    ConnectImpl() = default;
    ConnectImpl(const ConnectImpl&) = delete;
    ConnectImpl(ConnectImpl&&) = delete;
    virtual ~ConnectImpl() = default;
    ConnectImpl& operator=(const ConnectImpl&) = default;
    ConnectImpl& operator=(ConnectImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Connect::Connect() : m_pImpl(new ConnectImpl) {}
Connect::~Connect() = default;

Connect& Connect::operator=(const Connect& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Connect& Connect::operator=(Connect&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Connect::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Connect::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Connect::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Connect::resetImpl()
{
    m_pImpl->reset();
}

bool Connect::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Connect*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Connect::MsgIdParamType Connect::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Connect::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Connect::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Connect::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Connect::lengthImpl() const
{
    return m_pImpl->length();
}

bool Connect::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


