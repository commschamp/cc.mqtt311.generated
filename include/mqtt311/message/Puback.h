/// @file
/// @brief Contains definition of <b>"PUBACK"</b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Puback.
/// @tparam TOpt Extra options
/// @see @ref Puback
/// @headerfile "mqtt311/message/Puback.h"
template <typename TOpt = mqtt311::DefaultOptions>
struct PubackFields
{
    /// @brief Definition of <b>"Packet ID"</b> field.
    using PacketId =
        mqtt311::field::PacketId<
           TOpt
       >;
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        PacketId
    >;
};

/// @brief Definition of <b>"PUBACK"</b> message class.
/// @details
///     See @ref PubackFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Puback.h"
template <typename TMsgBase, typename TOpt = mqtt311::DefaultOptions>
class Puback : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<mqtt311::MsgId_Puback>,
        comms::option::FieldsImpl<typename PubackFields<TOpt>::All>,
        comms::option::MsgType<Puback<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::StaticNumIdImpl<mqtt311::MsgId_Puback>,
            comms::option::FieldsImpl<typename PubackFields<TOpt>::All>,
            comms::option::MsgType<Puback<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_packetId() for @ref PubackFields::PacketId field.
    COMMS_MSG_FIELDS_ACCESS(
        packetId
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 2U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return "PUBACK";
    }
    
    
};

} // namespace message

} // namespace mqtt311


