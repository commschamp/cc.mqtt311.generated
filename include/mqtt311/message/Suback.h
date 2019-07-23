/// @file
/// @brief Contains definition of <b>"SUBACK"</b> message and its fields.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <tuple>
#include <utility>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Suback.
/// @tparam TOpt Extra options
/// @see @ref Suback
/// @headerfile "mqtt311/message/Suback.h"
template <typename TOpt = mqtt311::options::DefaultOptions>
struct SubackFields
{
    /// @brief Definition of <b>"Packet ID"</b> field.
    using PacketId =
        mqtt311::field::PacketId<
            TOpt
        >;
    
    /// @brief Scope for all the member fields of @ref List list.
    struct ListMembers
    {
        /// @brief Values enumerator for @ref mqtt311::message::SubackFields::ListMembers::ReturnCode field.
        enum class ReturnCodeVal : std::uint8_t
        {
            Qos0 = 0, ///< value <b>Max QoS 0</b>.
            Qos1 = 1, ///< value <b>Max QoS 1</b>.
            Qos2 = 2, ///< value <b>Max QoS 2</b>.
            Failure = 128, ///< value @b Failure
            
        };
        
        /// @brief Definition of <b>"Return Code"</b> field.
        /// @see @ref mqtt311::message::SubackFields::ListMembers::ReturnCodeVal
        struct ReturnCode : public
            comms::field::EnumValue<
                mqtt311::field::FieldBase<>,
                ReturnCodeVal,
                comms::option::def::ValidNumValueRange<0, 2>,
                comms::option::def::ValidNumValue<128>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return "Return Code";
            }
            
            /// @brief Retrieve name of the enum value
            static const char* valueName(ReturnCodeVal val)
            {
                using NameInfo = std::pair<ReturnCodeVal, const char*>;
                static const NameInfo Map[] = {
                    std::make_pair(ReturnCodeVal::Qos0, "Max QoS 0"),
                    std::make_pair(ReturnCodeVal::Qos1, "Max QoS 1"),
                    std::make_pair(ReturnCodeVal::Qos2, "Max QoS 2"),
                    std::make_pair(ReturnCodeVal::Failure, "Failure")
                };
                
                auto iter = std::lower_bound(
                    std::begin(Map), std::end(Map), val,
                    [](const NameInfo& info, ReturnCodeVal v) -> bool
                    {
                        return info.first < v;
                    });
                
                if ((iter == std::end(Map)) || (iter->first != val)) {
                    return nullptr;
                }
                
                return iter->second;
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"List"</b> field.
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

/// @brief Definition of <b>"SUBACK"</b> message class.
/// @details
///     See @ref SubackFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Suback.h"
template <typename TMsgBase, typename TOpt = mqtt311::options::DefaultOptions>
class Suback : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Suback,
        comms::option::def::StaticNumIdImpl<mqtt311::MsgId_Suback>,
        comms::option::def::FieldsImpl<typename SubackFields<TOpt>::All>,
        comms::option::def::MsgType<Suback<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Suback,
            comms::option::def::StaticNumIdImpl<mqtt311::MsgId_Suback>,
            comms::option::def::FieldsImpl<typename SubackFields<TOpt>::All>,
            comms::option::def::MsgType<Suback<TMsgBase, TOpt> >,
            comms::option::def::HasName
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


