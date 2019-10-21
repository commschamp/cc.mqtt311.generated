/// @file
/// @brief Contains definition of protocol default options.

#pragma once

#include "comms/options.h"

namespace mqtt311
{

namespace options
{

/// @brief Default (empty) options of the protocol.
struct DefaultOptions
{
    /// @brief Extra options for fields.
    struct field
    {
        /// @brief Extra options for @ref
        ///     mqtt311::field::BinData field.
        using BinData = comms::option::app::EmptyOption;
        
        /// @brief Extra options for @ref
        ///     mqtt311::field::ProtocolName field.
        using ProtocolName = comms::option::app::EmptyOption;
        
        /// @brief Extra options for @ref
        ///     mqtt311::field::String field.
        using String = comms::option::app::EmptyOption;
        
    }; // struct field
    
    /// @brief Extra options for messages.
    struct message
    {
        /// @brief Extra options for
        ///     @ref mqtt311::message::Connack message.
        using Connack = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Connect message.
        using Connect = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Disconnect message.
        using Disconnect = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Pingreq message.
        using Pingreq = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Pingresp message.
        using Pingresp = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref mqtt311::message::Publish message.
        struct PublishFields
        {
            /// @brief Extra options for @ref
            ///     mqtt311::message::PublishFields::Payload
            ///     field.
            using Payload = comms::option::app::EmptyOption;
            
        }; // struct PublishFields
        
        
        /// @brief Extra options for fields of
        ///     @ref mqtt311::message::Suback message.
        struct SubackFields
        {
            /// @brief Extra options for @ref
            ///     mqtt311::message::SubackFields::List
            ///     field.
            using List = comms::option::app::EmptyOption;
            
        }; // struct SubackFields
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Suback message.
        using Suback = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref mqtt311::message::Subscribe message.
        struct SubscribeFields
        {
            /// @brief Extra options for @ref
            ///     mqtt311::message::SubscribeFields::List
            ///     field.
            using List = comms::option::app::EmptyOption;
            
        }; // struct SubscribeFields
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Subscribe message.
        using Subscribe = comms::option::app::EmptyOption;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Unsuback message.
        using Unsuback = comms::option::app::EmptyOption;
        
        /// @brief Extra options for fields of
        ///     @ref mqtt311::message::Unsubscribe message.
        struct UnsubscribeFields
        {
            /// @brief Extra options for @ref
            ///     mqtt311::message::UnsubscribeFields::List
            ///     field.
            using List = comms::option::app::EmptyOption;
            
        }; // struct UnsubscribeFields
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Unsubscribe message.
        using Unsubscribe = comms::option::app::EmptyOption;
        
    }; // struct message
    
    /// @brief Extra options for frames.
    struct frame
    {
        /// @brief Extra options for Layers of
        ///     @ref mqtt311::frame::Frame frame.
        struct FrameLayers
        {
            /// @brief Extra options for @ref
            ///     mqtt311::frame::FrameLayers::Data layer.
            using Data = comms::option::app::EmptyOption;
            
            /// @brief Extra options for @ref
            ///     mqtt311::frame::FrameLayers::IdAndFlags
            ///     layer.
            using IdAndFlags = comms::option::app::EmptyOption;
            
        }; // struct FrameLayers
        
    }; // struct frame
    
    
};

} // namespace options

} // namespace mqtt311

