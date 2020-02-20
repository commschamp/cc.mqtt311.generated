// Generated by commsdsl2comms v3.3.2

#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Puback.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class Puback : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Puback<mqtt311::cc_plugin::Message>,
        Puback
    >
{
public:
    Puback();
    Puback(const Puback&) = delete;
    Puback(Puback&&) = delete;
    virtual ~Puback();
    Puback& operator=(const Puback&);
    Puback& operator=(Puback&&);

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311



