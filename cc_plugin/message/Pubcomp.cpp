#include "Pubcomp.h"

#include "comms_champion/property/field.h"
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Pubcomp.h"
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
    using Field = mqtt311::message::PubcompFields<>::PacketId;
    return cc_plugin::field::createProps_packetId(Field::name());
    
}

QVariantList createProps()
{
    QVariantList props;
    props.append(createProps_packetId());
    return props;
}

} // namespace

class PubcompImpl : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Pubcomp<mqtt311::cc_plugin::Message>,
        PubcompImpl
    >
{
public:
    PubcompImpl() = default;
    PubcompImpl(const PubcompImpl&) = delete;
    PubcompImpl(PubcompImpl&&) = delete;
    virtual ~PubcompImpl() = default;
    PubcompImpl& operator=(const PubcompImpl&) = default;
    PubcompImpl& operator=(PubcompImpl&&) = default;

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override
    {
        static const QVariantList Props = createProps();
        return Props;
    }
};

Pubcomp::Pubcomp() : m_pImpl(new PubcompImpl) {}
Pubcomp::~Pubcomp() = default;

Pubcomp& Pubcomp::operator=(const Pubcomp& other)
{
    *m_pImpl = *other.m_pImpl;
    return *this;
}

Pubcomp& Pubcomp::operator=(Pubcomp&& other)
{
    *m_pImpl = std::move(*other.m_pImpl);
    return *this;
}

const char* Pubcomp::nameImpl() const
{
    return static_cast<const cc::Message*>(m_pImpl.get())->name();
}

const QVariantList& Pubcomp::fieldsPropertiesImpl() const
{
    return m_pImpl->fieldsProperties();
}

void Pubcomp::dispatchImpl(cc::MessageHandler& handler)
{
    static_cast<cc::Message*>(m_pImpl.get())->dispatch(handler);
}

void Pubcomp::resetImpl()
{
    m_pImpl->reset();
}

bool Pubcomp::assignImpl(const cc::Message& other)
{
    auto* castedOther = dynamic_cast<const Pubcomp*>(&other);
    if (castedOther == nullptr) {
        return false;
    }
    return m_pImpl->assign(*castedOther->m_pImpl);
}

Pubcomp::MsgIdParamType Pubcomp::getIdImpl() const
{
    return m_pImpl->getId();
}

comms::ErrorStatus Pubcomp::readImpl(ReadIterator& iter, std::size_t len)
{
    return m_pImpl->read(iter, len);
}

comms::ErrorStatus Pubcomp::writeImpl(WriteIterator& iter, std::size_t len) const
{
    return m_pImpl->write(iter, len);
}

bool Pubcomp::validImpl() const
{
    return m_pImpl->valid();
}

std::size_t Pubcomp::lengthImpl() const
{
    return m_pImpl->length();
}

bool Pubcomp::refreshImpl()
{
    return m_pImpl->refresh();
}

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


