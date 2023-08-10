// Generated by commsdsl2comms v6.2.1

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Pubrel message and its fields.

#pragma once

#include "cc_mqtt311/field/PacketIdCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Pubrel message.
/// @see cc_mqtt311::message::PubrelFields
struct PubrelFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PubrelFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Pubrel message.
struct PubrelCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Pubrel message.
    static const char* name()
    {
        return "PUBREL";
    }
};

} // namespace message

} // namespace cc_mqtt311
