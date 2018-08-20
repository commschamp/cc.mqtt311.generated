/// @file
/// @brief Contains definition of <b>"SUBACK"<\b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Suback.
/// @tparam TOpt Extra options
/// @see @ref Suback
/// @headerfile "mqtt311/message/Suback.h"
template <typename TOpt = mqtt311::DefaultOptions>
struct SubackFields
{
    /// @brief Definition of <b>"Packet ID"<\b> field.
    using PacketId =
        mqtt311::field::PacketId<
           TOpt,
           typename TOpt::message::SubackFields::PacketId
       >;
    
    /// @brief Scope for all the member fields of @ref List list.
    struct ListMembers
    {
        /// @brief Values enumerator for @ref ReturnCode field.
        enum class ReturnCodeVal : std::uint8_t
        {
            Qos0 = 0, ///< value <b>Max QoS 0</b>.
            Qos1 = 1, ///< value <b>Max QoS 1</b>.
            Qos2 = 2, ///< value <b>Max QoS 2</b>.
            Failure = 128, ///< value @b Failure
            
        };
        
        /// @brief Definition of <b>"Return Code"<\b> field.
        struct ReturnCode : public
            comms::field::EnumValue<
                mqtt311::field::FieldBase<>,
                ReturnCodeVal,
                typename TOpt::message::SubackFields::ListMembers::ReturnCode,
                comms::option::ValidNumValueRange<0, 2>,
                comms::option::ValidNumValue<128>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return "Return Code";
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"List"<\b> field.
    struct List : public
        comms::field::ArrayList<
            mqtt311::field::FieldBase<>,
            typename ListMembers::ReturnCode,
            typename TOpt::message::SubackFields::List
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

/// @brief Definition of <b>"SUBACK"<\b> message class.
/// @details
///     See @ref SubackFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Suback.h"
template <typename TMsgBase, typename TOpt = mqtt311::DefaultOptions>
class Suback : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Suback,
        comms::option::StaticNumIdImpl<mqtt311::MsgId_Suback>,
        comms::option::FieldsImpl<typename SubackFields<TOpt>::All>,
        comms::option::MsgType<Suback<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Suback,
            comms::option::StaticNumIdImpl<mqtt311::MsgId_Suback>,
            comms::option::FieldsImpl<typename SubackFields<TOpt>::All>,
            comms::option::MsgType<Suback<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_packetId() for @ref SubackFields::PacketId field.
    ///     @li @b field_list() for @ref SubackFields::List field.
    COMMS_MSG_FIELDS_ACCESS(
        packetId,
        list
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return "SUBACK";
    }
    
    /// @brief Updated validity check
    bool doValid() const
    {
        if ((!Base::doValid()) || (!Base::flagsZeroed())) {
            return false;
        }
        
        return !field_list().value().empty();
    }
    
    
};

} // namespace message

} // namespace mqtt311


