/// @file
/// @brief Contains definition of <b>"UNSUBSCRIBE"</b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/options.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"
#include "mqtt311/field/Topic.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Unsubscribe.
/// @tparam TOpt Extra options
/// @see @ref Unsubscribe
/// @headerfile "mqtt311/message/Unsubscribe.h"
template <typename TOpt = mqtt311::options::DefaultOptions>
struct UnsubscribeFields
{
    /// @brief Definition of <b>"Packet ID"</b> field.
    using PacketId =
        mqtt311::field::PacketId<
            TOpt
        >;
    
    /// @brief Scope for all the member fields of ///     @ref List list.
    struct ListMembers
    {
        /// @brief Definition of <b>"Topic"</b> field.
        using Topic =
            mqtt311::field::Topic<
                TOpt
            >;
        
    };
    
    /// @brief Definition of <b>"List"</b> field.
    struct List : public
        comms::field::ArrayList<
            mqtt311::field::FieldBase<>,
            typename ListMembers::Topic,
            typename TOpt::message::UnsubscribeFields::List
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

/// @brief Definition of <b>"UNSUBSCRIBE"</b> message class.
/// @details
///     See @ref UnsubscribeFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Unsubscribe.h"
template <typename TMsgBase, typename TOpt = mqtt311::options::DefaultOptions>
class Unsubscribe : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Unsubscribe,
        comms::option::def::StaticNumIdImpl<mqtt311::MsgId_Unsubscribe>,
        comms::option::def::FieldsImpl<typename UnsubscribeFields<TOpt>::All>,
        comms::option::def::MsgType<Unsubscribe<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Unsubscribe,
            comms::option::def::StaticNumIdImpl<mqtt311::MsgId_Unsubscribe>,
            comms::option::def::FieldsImpl<typename UnsubscribeFields<TOpt>::All>,
            comms::option::def::MsgType<Unsubscribe<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_packetId type and @b field_packetId() fuction
    ///         for @ref UnsubscribeFields::PacketId field.
    ///     @li @b Field_list type and @b field_list() fuction
    ///         for @ref UnsubscribeFields::List field.
    COMMS_MSG_FIELDS_NAMES(
        packetId,
        list
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");
    
    
    /// @brief Default constructor
    Unsubscribe()
    {
        auto& qosField = Base::transportField_flags().field_qos();
        using QosFieldType = typename std::decay<decltype(qosField)>::type;
        using QosValueType = typename QosFieldType::ValueType;
        
        qosField.value() = QosValueType::AtLeastOnceDelivery;
    }
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return "UNSUBSCRIBE";
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


