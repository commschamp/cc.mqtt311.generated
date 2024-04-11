// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Subscribe message and its fields.

#pragma once

#include "cc_mqtt311/field/PacketIdCommon.h"
#include "cc_mqtt311/field/QosCommon.h"
#include "cc_mqtt311/field/TopicCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Subscribe message.
/// @see cc_mqtt311::message::SubscribeFields
struct SubscribeFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::SubscribeFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;

    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref cc_mqtt311::message::SubscribeFields::List field.
    struct ListMembersCommon
    {
        /// @brief Scope for all the common definitions of the member fields of
        ///     @ref cc_mqtt311::message::SubscribeFields::ListMembers::Element field.
        struct ElementMembersCommon
        {
            /// @brief Common types and functions for
            ///     @ref cc_mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Topic field.
            using TopicCommon = cc_mqtt311::field::TopicCommon;

            /// @brief Common types and functions for
            ///     @ref cc_mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Qos field.
            using QosCommon = cc_mqtt311::field::QosCommon;
        };

        /// @brief Common types and functions for
        ///     @ref cc_mqtt311::message::SubscribeFields::ListMembers::Element field.
        struct ElementCommon
        {
            /// @brief Name of the @ref cc_mqtt311::message::SubscribeFields::ListMembers::Element field.
            static const char* name()
            {
                return "";
            }
        };
    };

    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::SubscribeFields::List field.
    struct ListCommon
    {
        /// @brief Name of the @ref cc_mqtt311::message::SubscribeFields::List field.
        static const char* name()
        {
            return "List";
        }
    };
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Subscribe message.
struct SubscribeCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Subscribe message.
    static const char* name()
    {
        return "SUBSCRIBE";
    }
};

} // namespace message

} // namespace cc_mqtt311
