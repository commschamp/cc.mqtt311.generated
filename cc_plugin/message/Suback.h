// Generated by commsdsl2comms v3.6.2

#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Suback.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class Suback : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Suback<mqtt311::cc_plugin::Message>,
        Suback
    >
{
public:
    Suback();
    Suback(const Suback&) = delete;
    Suback(Suback&&) = delete;
    virtual ~Suback();
    Suback& operator=(const Suback&);
    Suback& operator=(Suback&&);

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311



