// Generated by commsdsl2comms v5.1.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Unsubscribe message and its fields.

#pragma once

#include "cc_mqtt311/field/PacketIdCommon.h"
#include "cc_mqtt311/field/TopicCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Unsubscribe message.
/// @see cc_mqtt311::message::UnsubscribeFields
struct UnsubscribeFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::UnsubscribeFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;

    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref cc_mqtt311::message::UnsubscribeFields::List field.
    struct ListMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref cc_mqtt311::message::UnsubscribeFields::ListMembers::Topic field.
        using TopicCommon = cc_mqtt311::field::TopicCommon;
    };

    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::UnsubscribeFields::List field.
    struct ListCommon
    {
        /// @brief Name of the @ref cc_mqtt311::message::UnsubscribeFields::List field.
        static const char* name()
        {
            return "List";
        }
    };
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Unsubscribe message.
struct UnsubscribeCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Unsubscribe message.
    static const char* name()
    {
        return "UNSUBSCRIBE";
    }
};

} // namespace message

} // namespace cc_mqtt311
