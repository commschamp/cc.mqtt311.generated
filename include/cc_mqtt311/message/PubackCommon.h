// Generated by commsdsl2comms v6.2.4

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Puback message and its fields.

#pragma once

#include "cc_mqtt311/field/PacketIdCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Puback message.
/// @see cc_mqtt311::message::PubackFields
struct PubackFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PubackFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Puback message.
struct PubackCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Puback message.
    static const char* name()
    {
        return "PUBACK";
    }
};

} // namespace message

} // namespace cc_mqtt311
