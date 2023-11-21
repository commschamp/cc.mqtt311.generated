// Generated by commsdsl2comms v6.2.4

/// @file
/// @brief Contains definition of protocol default options.

#pragma once

#include "comms/options.h"

namespace cc_mqtt311
{

namespace options
{

/// @brief Empty class to serve as the base for options.
struct EmptyOptions {};

/// @brief Default (empty) options of the protocol.
template <typename TBase = EmptyOptions>
struct DefaultOptionsT : public TBase
{
    /// @brief Extra options for fields.
    struct field
    {
        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::BinData field.
        using BinData = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::ProtocolName field.
        using ProtocolName = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::String field.
        using String = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::Topic field.
        using Topic = comms::option::EmptyOption;
    }; // struct field

    /// @brief Extra options for messages.
    struct message
    {
        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Connack message.
        using Connack = comms::option::EmptyOption;

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Connect message.
        struct ConnectFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::ConnectFields::ProtocolName
            ///     field.
            using ProtocolName = comms::option::EmptyOption;

            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::ConnectFields::ClientId
            ///     field.
            using ClientId = comms::option::EmptyOption;

            struct WillTopicMembers
            {
                /// @brief Extra options for @ref
                ///     cc_mqtt311::message::ConnectFields::WillTopicMembers::WillTopic
                ///     field.
                using WillTopic = comms::option::EmptyOption;
            }; // struct WillTopicMembers

            struct WillMessageMembers
            {
                /// @brief Extra options for @ref
                ///     cc_mqtt311::message::ConnectFields::WillMessageMembers::WillMessage
                ///     field.
                using WillMessage = comms::option::EmptyOption;
            }; // struct WillMessageMembers

            struct UserNameMembers
            {
                /// @brief Extra options for @ref
                ///     cc_mqtt311::message::ConnectFields::UserNameMembers::UserName
                ///     field.
                using UserName = comms::option::EmptyOption;
            }; // struct UserNameMembers

            struct PasswordMembers
            {
                /// @brief Extra options for @ref
                ///     cc_mqtt311::message::ConnectFields::PasswordMembers::Password
                ///     field.
                using Password = comms::option::EmptyOption;
            }; // struct PasswordMembers
        };

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Connect message.
        using Connect = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Disconnect message.
        using Disconnect = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Pingreq message.
        using Pingreq = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Pingresp message.
        using Pingresp = comms::option::EmptyOption;

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Publish message.
        struct PublishFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::PublishFields::Topic
            ///     field.
            using Topic = comms::option::EmptyOption;

            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::PublishFields::Payload
            ///     field.
            using Payload = comms::option::EmptyOption;
        };

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Suback message.
        struct SubackFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::SubackFields::List
            ///     field.
            using List = comms::option::EmptyOption;
        };

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Suback message.
        using Suback = comms::option::EmptyOption;

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Subscribe message.
        struct SubscribeFields
        {
            struct ListMembers
            {
                struct ElementMembers
                {
                    /// @brief Extra options for @ref
                    ///     cc_mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Topic
                    ///     field.
                    using Topic = comms::option::EmptyOption;
                }; // struct ElementMembers
            }; // struct ListMembers

            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::SubscribeFields::List
            ///     field.
            using List = comms::option::EmptyOption;
        };

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Subscribe message.
        using Subscribe = comms::option::EmptyOption;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Unsuback message.
        using Unsuback = comms::option::EmptyOption;

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Unsubscribe message.
        struct UnsubscribeFields
        {
            struct ListMembers
            {
                /// @brief Extra options for @ref
                ///     cc_mqtt311::message::UnsubscribeFields::ListMembers::Topic
                ///     field.
                using Topic = comms::option::EmptyOption;
            }; // struct ListMembers

            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::UnsubscribeFields::List
            ///     field.
            using List = comms::option::EmptyOption;
        };

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Unsubscribe
        ///     message.
        using Unsubscribe = comms::option::EmptyOption;
    }; // struct message

    /// @brief Extra options for frames.
    struct frame
    {
        /// @brief Extra options for layers of
        ///     @ref cc_mqtt311::frame::Frame frame.
        struct FrameLayers
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::frame::FrameLayers::Data
            ///     layer.
            using Data = comms::option::EmptyOption;

            /// @brief Extra options for @ref
            ///     cc_mqtt311::frame::FrameLayers::IdAndFlags
            ///     layer.
            using IdAndFlags = comms::option::EmptyOption;
        }; // struct FrameLayers
    }; // struct frame
};

/// @brief Default (empty) options of the protocol.
using DefaultOptions = DefaultOptionsT<>;

} // namespace options

} // namespace cc_mqtt311
