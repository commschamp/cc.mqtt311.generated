// Generated by commsdsl2comms v6.3.3

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Publish message and its fields.

#pragma once

#include "cc_mqtt311/field/TopicCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Publish message.
/// @see cc_mqtt311::message::PublishFields
struct PublishFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PublishFields::Topic field.
    using TopicCommon = cc_mqtt311::field::TopicCommon;

    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PublishFields::PacketId field.
    struct PacketIdCommon
    {
        /// @brief Name of the @ref cc_mqtt311::message::PublishFields::PacketId field.
        static const char* name()
        {
            return "Packet ID";
        }
    };

    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::PublishFields::Payload field.
    struct PayloadCommon
    {
        /// @brief Name of the @ref cc_mqtt311::message::PublishFields::Payload field.
        static const char* name()
        {
            return "Payload";
        }
    };
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Publish message.
struct PublishCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Publish message.
    static const char* name()
    {
        return "PUBLISH";
    }
};

} // namespace message

} // namespace cc_mqtt311
