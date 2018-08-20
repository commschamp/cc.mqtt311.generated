#pragma once

#include <tuple>
#include <QtCore/QVariantList>
#include "comms_champion/TransportMessageBase.h"
#include "mqtt311/frame/Frame.h"
#include "cc_plugin/Message.h"

namespace mqtt311
{

namespace cc_plugin
{

namespace frame
{

struct FrameTransportMessageFields
{
    using All =
        std::tuple<
            mqtt311::frame::FrameLayers<>::IdAndFlagsMembers::IdAndFlagsField,
            mqtt311::frame::FrameLayers<>::SizeMembers::Size,
            mqtt311::frame::FrameLayers<>::Data::Field
        >;
};

class FrameTransportMessage : public
    comms_champion::TransportMessageBase<
        mqtt311::cc_plugin::Message,
        FrameTransportMessageFields::All
    >
{
protected:
    virtual const QVariantList& fieldsPropertiesImpl() const override;
};

} // namespace frame

} // namespace cc_plugin

} // namespace mqtt311


