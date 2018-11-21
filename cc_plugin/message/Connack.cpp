#include "Connack.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Connack.h"
namespace cc = comms_champion;

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

namespace
{

static QVariantMap createProps_flags()
{
    using Field = mqtt311::message::ConnackFields<>::Flags;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add(0U, "Session Present")
            .asMap();
    
}

static QVariantMap createProps_returnCode()
{
    using Field = mqtt311::message::ConnackFields<>::ReturnCode;
    return
        cc::property::field::ForField<Field>()
            .name(Field::name())
            .add("Accepted", 0)
            .add("Bad Protocol Version", 1)
            .add("Identifier Rejected", 2)
            .add("Server Unavailable", 3)
            .add("Bad Auth Details", 4)
            .add("Not Authorized", 5)
            .asMap();
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_flags());
    props.append(createProps_returnCode());
    return props;
}

} // namespace

class ConnackImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Connack<mqtt311::cc_plugin::Message>,
        ConnackImpl
    >
{
public:
    ConnackImpl() = default;
    ConnackImpl(const ConnackImpl&) = delete;
    ConnackImpl(ConnackImpl&&) = delete;
    virtual ~ConnackImpl() = default;
    ConnackImpl& operator=(const ConnackImpl&) = default;
    ConnackImpl& operator=(ConnackImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Connack::Connack() : m_pImpl(new ConnackImpl) {}
Connack::~Connack() = default;

Connack& Connack::operator=(const Connack& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Connack& Connack::operator=(Connack&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Connack::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Connack::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Connack::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Connack::resetImpl()
{
    m_pImpl->reset();
}

bool Connack::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Connack*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Connack::MsgIdParamType Connack::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Connack::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Connack::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Connack::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Connack::lengthImpl() const
{
    return m_pImpl->length();
}

bool Connack::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


