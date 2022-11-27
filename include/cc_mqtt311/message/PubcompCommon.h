// Generated by commsdsl2comms v5.1.3

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Pubcomp message and its fields.

#pragma once

#include "cc_mqtt311/field/PacketIdCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Pubcomp message.
/// @see cc_mqtt311::message::PubcompFields
struct PubcompFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PubcompFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Pubcomp message.
struct PubcompCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Pubcomp message.
    static const char* name()
    {
        return "PUBCOMP";
    }
};

} // namespace message

} // namespace cc_mqtt311
