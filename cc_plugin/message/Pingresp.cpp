#include "Pingresp.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Pingresp.h"
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

class PingrespImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Pingresp<mqtt311::cc_plugin::Message>,
        PingrespImpl
    >
{
public:
    PingrespImpl() = default;
    PingrespImpl(const PingrespImpl&) = delete;
    PingrespImpl(PingrespImpl&&) = delete;
    virtual ~PingrespImpl() = default;
    PingrespImpl& operator=(const PingrespImpl&) = default;
    PingrespImpl& operator=(PingrespImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Pingresp::Pingresp() : m_pImpl(new PingrespImpl) {}
Pingresp::~Pingresp() = default;

Pingresp& Pingresp::operator=(const Pingresp& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Pingresp& Pingresp::operator=(Pingresp&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Pingresp::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Pingresp::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Pingresp::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Pingresp::resetImpl()
{
    m_pImpl->reset();
}

bool Pingresp::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Pingresp*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Pingresp::MsgIdParamType Pingresp::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Pingresp::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Pingresp::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Pingresp::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Pingresp::lengthImpl() const
{
    return m_pImpl->length();
}

bool Pingresp::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


