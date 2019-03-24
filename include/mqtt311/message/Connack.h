/// @file
/// @brief Contains definition of <b>"CONNACK"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Connack.
/// @tparam TOpt Extra options
/// @see @ref Connack
/// @headerfile "mqtt311/message/Connack.h"
template <typename TOpt = mqtt311::DefaultOptions>
struct ConnackFields
{
    /// @brief Definition of <b>"Flags"</b> field.
    class Flags : public
        comms::field::BitmaskValue<
            mqtt311::field::FieldBase<>,
            comms::option::FixedLength<1U>,
            comms::option::BitmaskReservedBits<0xFEU, 0x0U>
        >
    {
        using Base = 
            comms::field::BitmaskValue<
                mqtt311::field::FieldBase<>,
                comms::option::FixedLength<1U>,
                comms::option::BitmaskReservedBits<0xFEU, 0x0U>
            >;
    public:
        /// @brief Provides names and generates access functions for internal bits.
        /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
        ///     related to @b comms::field::BitmaskValue class from COMMS library
        ///     for details.
        ///
        ///      The generated enum values and functions are:
        ///      @li @b BitIdx_sp, @b getBitValue_sp() and @b setBitValue_sp().
        COMMS_BITMASK_BITS_SEQ(
            sp
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return "Flags";
        }
        
    };
    
    /// @brief Values enumerator for @ref mqtt311::message::ConnackFields::ReturnCode field.
    enum class ReturnCodeVal : std::uint8_t
    {
        Accepted = 0, ///< value @b Accepted
        BadProtocolVersion = 1, ///< value <b>Bad Protocol Version</b>.
        IdentifierRejected = 2, ///< value <b>Identifier Rejected</b>.
        ServerUnavalable = 3, ///< value <b>Server Unavailable</b>.
        BadAuth = 4, ///< value <b>Bad Auth Details</b>.
        NotAuthorized = 5, ///< value <b>Not Authorized</b>.
        
    };
    
    /// @brief Definition of <b>"Return Code"</b> field.
    /// @see @ref mqtt311::message::ConnackFields::ReturnCodeVal
    struct ReturnCode : public
        comms::field::EnumValue<
            mqtt311::field::FieldBase<>,
            ReturnCodeVal,
            comms::option::ValidNumValueRange<0, 5>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "Return Code";
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Flags,
        ReturnCode
    >;
};

/// @brief Definition of <b>"CONNACK"</b> message class.
/// @details
///     See @ref ConnackFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Connack.h"
template <typename TMsgBase, typename TOpt = mqtt311::DefaultOptions>
class Connack : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Connack,
        comms::option::StaticNumIdImpl<mqtt311::MsgId_Connack>,
        comms::option::FieldsImpl<typename ConnackFields<TOpt>::All>,
        comms::option::MsgType<Connack<TMsgBase, TOpt> >,
        comms::option::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Connack,
            comms::option::StaticNumIdImpl<mqtt311::MsgId_Connack>,
            comms::option::FieldsImpl<typename ConnackFields<TOpt>::All>,
            comms::option::MsgType<Connack<TMsgBase, TOpt> >,
            comms::option::HasName
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_flags() for @ref ConnackFields::Flags field.
    ///     @li @b field_returnCode() for @ref ConnackFields::ReturnCode field.
    COMMS_MSG_FIELDS_ACCESS(
        flags,
        returnCode
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 2U, "Unexpected max serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return "CONNACK";
    }
    
    /// @brief Updated validity check
    bool doValid() const
    {
        return Base::doValid() && Base::flagsZeroed();
    }
    
    
};

} // namespace message

} // namespace mqtt311


