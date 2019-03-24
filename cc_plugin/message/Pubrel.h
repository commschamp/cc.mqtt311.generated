#pragma once

#include <memory>
#include <QtCore/QVariantList>
#include "comms_champion/ProtocolMessageBase.h"
#include "mqtt311/message/Pubrel.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace message
{

class Pubrel : public
    comms_champion::ProtocolMessageBase<
        mqtt311::message::Pubrel<mqtt311::cc_plugin::Message>,
        Pubrel
    >
{
public:
    Pubrel();
    Pubrel(const Pubrel&) = delete;
    Pubrel(Pubrel&&) = delete;
    virtual ~Pubrel();
    Pubrel& operator=(const Pubrel&);
    Pubrel& operator=(Pubrel&&);

protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace message

} // namespace cc_plugin

} // namespace mqtt311



