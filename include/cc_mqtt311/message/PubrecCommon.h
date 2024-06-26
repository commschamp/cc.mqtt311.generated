// Generated by commsdsl2comms v6.3.3

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Pubrec message and its fields.

#pragma once

#include "cc_mqtt311/field/PacketIdCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Pubrec message.
/// @see cc_mqtt311::message::PubrecFields
struct PubrecFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PubrecFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Pubrec message.
struct PubrecCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Pubrec message.
    static const char* name()
    {
        return "PUBREC";
    }
};

} // namespace message

} // namespace cc_mqtt311
