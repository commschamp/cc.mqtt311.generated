#pragma once

#include "comms_champion/MessageBase.h"
#include "mqtt311/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

class Message : public
    comms_champion::MessageBase<
        mqtt311::Message
    >
{
protected:
    virtual const QVariantList& extraTransportFieldsPropertiesImpl() const override;
};

} // namespace cc_plugin

} // namespace mqtt311



