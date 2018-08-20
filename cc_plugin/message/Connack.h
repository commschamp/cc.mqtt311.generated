#pragma once

#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Connack.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class Connack : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Connack<mqtt311::cc_plugin::Message>,
        Connack
    >
{
protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


