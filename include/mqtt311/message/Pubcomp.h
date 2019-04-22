/// @file
/// @brief Contains definition of <b>"PUBCOMP"</b> message and its fields.

#pragma once

#include <tuple>
#include "comms/MessageBase.h"
#include "comms/options.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Pubcomp.
/// @tparam TOpt Extra options
/// @see @ref Pubcomp
/// @headerfile "mqtt311/message/Pubcomp.h"
template <typename TOpt = mqtt311::options::DefaultOptions>
struct PubcompFields
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

/// @brief Definition of <b>"PUBCOMP"</b> message class.
/// @details
///     See @ref PubcompFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Pubcomp.h"
template <typename TMsgBase, typename TOpt = mqtt311::options::DefaultOptions>
class Pubcomp : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<mqtt311::MsgId_Pubcomp>,
        comms::option::FieldsImpl<typename PubcompFields<TOpt>::All>,
        comms::option::MsgType<Pubcomp<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::StaticNumIdImpl<mqtt311::MsgId_Pubcomp>,
            comms::option::FieldsImpl<typename PubcompFields<TOpt>::All>,
            comms::option::MsgType<Pubcomp<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_packetId() for @ref PubcompFields::PacketId field.
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
        return "PUBCOMP";
    }
    
    /// @brief Updated validity check
    bool doValid() const
    {
        return Base::doValid() && Base::flagsZeroed();
    }
    
    
};

} // namespace message

} // namespace mqtt311


