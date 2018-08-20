/// @file
/// @brief Contains definition of <b>"SUBSCRIBE"<\b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Bundle.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"
#include "mqtt311/field/Qos.h"
#include "mqtt311/field/String.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Subscribe.
/// @tparam TOpt Extra options
/// @see @ref Subscribe
/// @headerfile "mqtt311/message/Subscribe.h"
template <typename TOpt = mqtt311::DefaultOptions>
struct SubscribeFields
{
    /// @brief Definition of <b>"Packet ID"<\b> field.
    using PacketId =
        mqtt311::field::PacketId<
           TOpt,
           typename TOpt::message::SubscribeFields::PacketId
       >;
    
    /// @brief Scope for all the member fields of @ref List list.
    struct ListMembers
    {
        /// @brief Scope for all the member fields of @ref Element bitfield.
        struct ElementMembers
        {
            /// @brief Definition of <b>"Topic"<\b> field.
            struct Topic : public
                mqtt311::field::String<
                   TOpt,
                   typename TOpt::message::SubscribeFields::ListMembers::ElementMembers::Topic
               >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return "Topic";
                }
                
            };
            
            /// @brief Definition of <b>"qos"<\b> field.
            struct Qos : public
                mqtt311::field::Qos<
                   TOpt,
                   typename TOpt::message::SubscribeFields::ListMembers::ElementMembers::Qos
               >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return "qos";
                }
                
            };
            
            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   Topic,
                   Qos
                >;
        };
        
        /// @brief Definition of <b>""<\b> field.
        class Element : public
            comms::field::Bundle<
                mqtt311::field::FieldBase<>,
                typename ElementMembers::All,
                typename TOpt::message::SubscribeFields::ListMembers::Element
            >
        {
            using Base = 
                comms::field::Bundle<
                    mqtt311::field::FieldBase<>,
                    typename ElementMembers::All,
                    typename TOpt::message::SubscribeFields::ListMembers::Element
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_FIELD_MEMBERS_ACCESS macro
            ///     related to @b comms::field::Bundle class from COMMS library
            ///     for details.
            ///
            ///      The generated access functions are:
            ///     @li @b field_topic() - for @ref ElementMembers::topic member field.
            ///     @li @b field_qos() - for @ref ElementMembers::qos member field.
            COMMS_FIELD_MEMBERS_ACCESS(
                topic,
                qos
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return "";
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"List"<\b> field.
    struct List : public
        comms::field::ArrayList<
            mqtt311::field::FieldBase<>,
            typename ListMembers::Element,
            typename TOpt::message::SubscribeFields::List
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "List";
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        PacketId,
        List
    >;
};

/// @brief Definition of <b>"SUBSCRIBE"<\b> message class.
/// @details
///     See @ref SubscribeFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Subscribe.h"
template <typename TMsgBase, typename TOpt = mqtt311::DefaultOptions>
class Subscribe : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Subscribe,
        comms::option::StaticNumIdImpl<mqtt311::MsgId_Subscribe>,
        comms::option::FieldsImpl<typename SubscribeFields<TOpt>::All>,
        comms::option::MsgType<Subscribe<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Subscribe,
            comms::option::StaticNumIdImpl<mqtt311::MsgId_Subscribe>,
            comms::option::FieldsImpl<typename SubscribeFields<TOpt>::All>,
            comms::option::MsgType<Subscribe<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_packetId() for @ref SubscribeFields::PacketId field.
    ///     @li @b field_list() for @ref SubscribeFields::List field.
    COMMS_MSG_FIELDS_ACCESS(
        packetId,
        list
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");
    
    
    /// @brief Default constructor
    Subscribe()
    {
        auto& qosField = Base::transportField_flags().field_qos();
        using QosFieldType = typename std::decay<decltype(qosField)>::type;
        using QosValueType = typename QosFieldType::ValueType;
        
        qosField.value() = QosValueType::AtLeastOnceDelivery;
    }
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return "SUBSCRIBE";
    }
    
    /// @brief Custom validity check
    bool doValid() const
    {
        if (!Base::doValid()) {
            return false;
        }
        
        auto& qosField = Base::transportField_flags().field_qos();
        using QosFieldType = typename std::decay<decltype(qosField)>::type;
        using QosValueType = typename QosFieldType::ValueType;
        
        if ((Base::transportField_flags().field_retain().value() != 0U) ||
            (qosField.value() != QosValueType::AtLeastOnceDelivery) ||
            (Base::transportField_flags().field_dup().value() != 0U)) {
            return false;
        }
        
        return !field_list().value().empty();
    }
    
    
};

} // namespace message

} // namespace mqtt311


