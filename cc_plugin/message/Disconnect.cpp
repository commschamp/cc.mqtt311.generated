#include "Disconnect.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Disconnect.h"
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

class DisconnectImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Disconnect<mqtt311::cc_plugin::Message>,
        DisconnectImpl
    >
{
public:
    DisconnectImpl() = default;
    DisconnectImpl(const DisconnectImpl&) = delete;
    DisconnectImpl(DisconnectImpl&&) = delete;
    virtual ~DisconnectImpl() = default;
    DisconnectImpl& operator=(const DisconnectImpl&) = default;
    DisconnectImpl& operator=(DisconnectImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Disconnect::Disconnect() : m_pImpl(new DisconnectImpl) {}
Disconnect::~Disconnect() = default;

Disconnect& Disconnect::operator=(const Disconnect& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Disconnect& Disconnect::operator=(Disconnect&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Disconnect::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Disconnect::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Disconnect::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Disconnect::resetImpl()
{
    m_pImpl->reset();
}

bool Disconnect::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Disconnect*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Disconnect::MsgIdParamType Disconnect::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Disconnect::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Disconnect::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Disconnect::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Disconnect::lengthImpl() const
{
    return m_pImpl->length();
}

bool Disconnect::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


