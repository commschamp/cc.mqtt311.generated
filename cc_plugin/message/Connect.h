#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Connect.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class Connect : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Connect<mqtt311::cc_plugin::Message>,
        Connect
    >
{
public:
    Connect();
    Connect(const Connect&) = delete;
    Connect(Connect&&) = delete;
    virtual ~Connect();
    Connect& operator=(const Connect&);
    Connect& operator=(Connect&&);

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311



