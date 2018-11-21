#include "Pingreq.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Pingreq.h"
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

class PingreqImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Pingreq<mqtt311::cc_plugin::Message>,
        PingreqImpl
    >
{
public:
    PingreqImpl() = default;
    PingreqImpl(const PingreqImpl&) = delete;
    PingreqImpl(PingreqImpl&&) = delete;
    virtual ~PingreqImpl() = default;
    PingreqImpl& operator=(const PingreqImpl&) = default;
    PingreqImpl& operator=(PingreqImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Pingreq::Pingreq() : m_pImpl(new PingreqImpl) {}
Pingreq::~Pingreq() = default;

Pingreq& Pingreq::operator=(const Pingreq& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Pingreq& Pingreq::operator=(Pingreq&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Pingreq::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Pingreq::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Pingreq::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Pingreq::resetImpl()
{
    m_pImpl->reset();
}

bool Pingreq::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Pingreq*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Pingreq::MsgIdParamType Pingreq::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Pingreq::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Pingreq::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Pingreq::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Pingreq::lengthImpl() const
{
    return m_pImpl->length();
}

bool Pingreq::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


