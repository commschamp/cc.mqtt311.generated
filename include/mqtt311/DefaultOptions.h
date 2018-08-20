/// @file
/// @brief Contains definition of protocol default options.

#pragma once

#include "comms/options.h"

namespace mqtt311
{

/// @brief Default (empty) options of the protocol.
struct DefaultOptions
{
    /// @brief Extra options for fields.
    struct field
    {
        /// @brief Extra options for @ref mqtt311::field::BinData field.
        using BinData = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::field::Length field.
        using Length = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::field::PacketId field.
        using PacketId = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::field::ProtocolName field.
        using ProtocolName = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::field::Qos field.
        using Qos = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::field::String field.
        using String = comms::option::EmptyOption;
        
    }; // struct field
    
    /// @brief Extra options for messages.
    struct message
    {
        /// @brief Extra options for fields of @ref mqtt311::message::Connack message.
        struct ConnackFields
        {
            /// @brief Extra options for @ref mqtt311::message::ConnackFields::Flags field.
            using Flags = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref mqtt311::message::ConnackFields::ReturnCode field.
            using ReturnCode = comms::option::EmptyOption;
            
        }; // struct ConnackFields
        
        /// @brief Extra options for @ref mqtt311::message::Connack message.
        using Connack = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Connect message.
        struct ConnectFields
        {
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::ProtocolName field.
            using ProtocolName = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::ProtocolLevel field.
            using ProtocolLevel = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::ConnectFields::Flags bitfield.
            struct FlagsMembers
            {
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::FlagsMembers::Low field.
                using Low = comms::option::EmptyOption;
                
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::FlagsMembers::WillQos field.
                using WillQos = comms::option::EmptyOption;
                
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::FlagsMembers::High field.
                using High = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::Flags field.
            using Flags = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::KeepAlive field.
            using KeepAlive = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::ClientId field.
            using ClientId = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::ConnectFields::WillTopic optional.
            struct WillTopicMembers
            {
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::WillTopicMembers::WillTopic field.
                using WillTopic = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::WillTopic field.
            using WillTopic = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::ConnectFields::WillMessage optional.
            struct WillMessageMembers
            {
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::WillMessageMembers::WillMessage field.
                using WillMessage = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::WillMessage field.
            using WillMessage = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::ConnectFields::UserName optional.
            struct UserNameMembers
            {
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::UserNameMembers::UserName field.
                using UserName = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::UserName field.
            using UserName = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::ConnectFields::Password optional.
            struct PasswordMembers
            {
                /// @brief Extra options for @ref mqtt311::message::ConnectFields::PasswordMembers::Password field.
                using Password = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::ConnectFields::Password field.
            using Password = comms::option::EmptyOption;
            
        }; // struct ConnectFields
        
        /// @brief Extra options for @ref mqtt311::message::Connect message.
        using Connect = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::message::Disconnect message.
        using Disconnect = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::message::Pingreq message.
        using Pingreq = comms::option::EmptyOption;
        
        /// @brief Extra options for @ref mqtt311::message::Pingresp message.
        using Pingresp = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Puback message.
        struct PubackFields
        {
            /// @brief Extra options for @ref mqtt311::message::PubackFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
        }; // struct PubackFields
        
        /// @brief Extra options for @ref mqtt311::message::Puback message.
        using Puback = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Pubcomp message.
        struct PubcompFields
        {
            /// @brief Extra options for @ref mqtt311::message::PubcompFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
        }; // struct PubcompFields
        
        /// @brief Extra options for @ref mqtt311::message::Pubcomp message.
        using Pubcomp = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Publish message.
        struct PublishFields
        {
            /// @brief Extra options for @ref mqtt311::message::PublishFields::Topic field.
            using Topic = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref mqtt311::message::PublishFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
            /// @brief Extra options for @ref mqtt311::message::PublishFields::Payload field.
            using Payload = comms::option::EmptyOption;
            
        }; // struct PublishFields
        
        /// @brief Extra options for @ref mqtt311::message::Publish message.
        using Publish = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Pubrec message.
        struct PubrecFields
        {
            /// @brief Extra options for @ref mqtt311::message::PubrecFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
        }; // struct PubrecFields
        
        /// @brief Extra options for @ref mqtt311::message::Pubrec message.
        using Pubrec = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Pubrel message.
        struct PubrelFields
        {
            /// @brief Extra options for @ref mqtt311::message::PubrelFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
        }; // struct PubrelFields
        
        /// @brief Extra options for @ref mqtt311::message::Pubrel message.
        using Pubrel = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Suback message.
        struct SubackFields
        {
            /// @brief Extra options for @ref mqtt311::message::SubackFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::SubackFields::List string.
            struct ListMembers
            {
                /// @brief Extra options for @ref mqtt311::message::SubackFields::ListMembers::ReturnCode field.
                using ReturnCode = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::SubackFields::List field.
            using List = comms::option::EmptyOption;
            
        }; // struct SubackFields
        
        /// @brief Extra options for @ref mqtt311::message::Suback message.
        using Suback = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Subscribe message.
        struct SubscribeFields
        {
            /// @brief Extra options for @ref mqtt311::message::SubscribeFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::SubscribeFields::List string.
            struct ListMembers
            {
                /// @brief Extra options for all the member fields of @ref mqtt311::message::SubscribeFields::ListMembers::Element bitfield.
                struct ElementMembers
                {
                    /// @brief Extra options for @ref mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Topic field.
                    using Topic = comms::option::EmptyOption;
                    
                    /// @brief Extra options for @ref mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Qos field.
                    using Qos = comms::option::EmptyOption;
                    
                };
                
                /// @brief Extra options for @ref mqtt311::message::SubscribeFields::ListMembers::Element field.
                using Element = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::SubscribeFields::List field.
            using List = comms::option::EmptyOption;
            
        }; // struct SubscribeFields
        
        /// @brief Extra options for @ref mqtt311::message::Subscribe message.
        using Subscribe = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Unsuback message.
        struct UnsubackFields
        {
            /// @brief Extra options for @ref mqtt311::message::UnsubackFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
        }; // struct UnsubackFields
        
        /// @brief Extra options for @ref mqtt311::message::Unsuback message.
        using Unsuback = comms::option::EmptyOption;
        
        /// @brief Extra options for fields of @ref mqtt311::message::Unsubscribe message.
        struct UnsubscribeFields
        {
            /// @brief Extra options for @ref mqtt311::message::UnsubscribeFields::PacketId field.
            using PacketId = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::message::UnsubscribeFields::List string.
            struct ListMembers
            {
                /// @brief Extra options for @ref mqtt311::message::UnsubscribeFields::ListMembers::Topic field.
                using Topic = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::message::UnsubscribeFields::List field.
            using List = comms::option::EmptyOption;
            
        }; // struct UnsubscribeFields
        
        /// @brief Extra options for @ref mqtt311::message::Unsubscribe message.
        using Unsubscribe = comms::option::EmptyOption;
        
    }; // struct message
    
    /// @brief Extra options for frames.
    struct frame
    {
        /// @brief Extra options for Layers of @ref mqtt311::frame::Frame frame.
        struct FrameLayers
        {
            /// @brief Extra options for @ref mqtt311::frame::FrameLayers::Data layer.
            using Data = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::frame::FrameLayers::SizeMembers::Size layer field.
            struct SizeMembers
            {
                /// @brief Extra options for @ref mqtt311::frame::FrameLayers::SizeMembers::Size field.
                using Size = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::frame::FrameLayers::Size layer.
            using Size = comms::option::EmptyOption;
            
            /// @brief Extra options for all the member fields of @ref mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlags layer field.
            struct IdAndFlagsMembers
            {
                /// @brief Extra options for all the member fields of @ref mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlagsField bitfield.
                struct IdAndFlagsFieldMembers
                {
                    /// @brief Extra options for @ref mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlagsFieldMembers::Flags field.
                    using Flags = comms::option::EmptyOption;
                    
                    /// @brief Extra options for @ref mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlagsFieldMembers::Id field.
                    using Id = comms::option::EmptyOption;
                    
                };
                
                /// @brief Extra options for @ref mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlagsField field.
                using IdAndFlagsField = comms::option::EmptyOption;
                
            };
            
            /// @brief Extra options for @ref mqtt311::frame::FrameLayers::IdAndFlags layer.
            using IdAndFlags = comms::option::EmptyOption;
            
        }; // struct FrameLayers
        
    }; // struct frame
    
    
};

} // namespace mqtt311


