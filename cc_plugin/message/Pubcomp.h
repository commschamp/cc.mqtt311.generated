#pragma once

#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Pubcomp.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class Pubcomp : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Pubcomp<mqtt311::cc_plugin::Message>,
        Pubcomp
    >
{
protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311


