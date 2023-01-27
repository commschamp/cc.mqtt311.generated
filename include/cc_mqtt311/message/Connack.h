// Generated by commsdsl2comms v5.2.0

/// @file
/// @brief Contains definition of <b>"CONNACK"</b> message and its fields.

#pragma once

#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/message/ConnackCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Connack.
/// @tparam TOpt Extra options
/// @see @ref Connack
/// @headerfile cc_mqtt311/message/Connack.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct ConnackFields
{
    /// @brief Definition of <b>"Flags"</b> field.
    class Flags : public
        comms::field::BitmaskValue<
            cc_mqtt311::field::FieldBase<>,
            comms::option::def::FixedLength<1U>,
            comms::option::def::BitmaskReservedBits<0xFEU, 0x0U>
        >
    {
        using Base =
            comms::field::BitmaskValue<
                cc_mqtt311::field::FieldBase<>,
                comms::option::def::FixedLength<1U>,
                comms::option::def::BitmaskReservedBits<0xFEU, 0x0U>
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

        /// @brief Retrieve name of the bit.
        /// @see @ref cc_mqtt311::message::ConnackFieldsCommon::FlagsCommon::bitName().
        static const char* bitName(BitIdx idx)
        {
            return
                cc_mqtt311::message::ConnackFieldsCommon::FlagsCommon::bitName(
                    static_cast<std::size_t>(idx));
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnackFieldsCommon::FlagsCommon::name();
        }
    };

    /// @brief Definition of <b>"Return Code"</b> field.
    /// @see @ref cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::ValueType
    class ReturnCode : public
        comms::field::EnumValue<
            cc_mqtt311::field::FieldBase<>,
            cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::ValueType,
            comms::option::def::ValidNumValueRange<0, 5>
        >
    {
        using Base =
            comms::field::EnumValue<
                cc_mqtt311::field::FieldBase<>,
                cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::ValueType,
                comms::option::def::ValidNumValueRange<0, 5>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;

        /// @brief Single value name info entry.
        using ValueNameInfo = cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::ValueNameInfo;

        /// @brief Type returned from @ref valueNamesMap() member function.
        /// @see @ref cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::ValueNamesMapInfo.
        using ValueNamesMapInfo = cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::ValueNamesMapInfo;

        /// @brief Retrieve name of the enum value.
        /// @see @ref cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::valueName().
        static const char* valueName(ValueType val)
        {
            return cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::valueName(val);
        }

        /// @brief Retrieve name of the enum value.
        /// @see @ref cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::valueName().
        static const char* valueNameOf(ValueType val)
        {
            return cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::valueName(val);
        }

        /// @brief Retrieve name of the @b current value
        const char* valueName() const
        {
            return valueName(Base::getValue());
        }

        /// @brief Retrieve map of enum value names.
        /// @see @ref cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::valueNamesMap().
        static ValueNamesMapInfo valueNamesMap()
        {
            return cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::valueNamesMap();
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnackFieldsCommon::ReturnCodeCommon::name();
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
/// @headerfile cc_mqtt311/message/Connack.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Connack : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Connack,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Connack>,
        comms::option::def::FieldsImpl<typename ConnackFields<TOpt>::All>,
        comms::option::def::MsgType<Connack<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Connack,
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Connack>,
            comms::option::def::FieldsImpl<typename ConnackFields<TOpt>::All>,
            comms::option::def::MsgType<Connack<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_flags index, @b Field_flags type and @b field_flags() access fuction
    ///         for @ref ConnackFields::Flags field.
    ///     @li @b FieldIdx_returnCode index, @b Field_returnCode type and @b field_returnCode() access fuction
    ///         for @ref ConnackFields::ReturnCode field.
    COMMS_MSG_FIELDS_NAMES(
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
        return cc_mqtt311::message::ConnackCommon::name();
    }

    /// @brief Updated validity check
    bool doValid() const
    {
        return Base::doValid() && Base::flagsZeroed();
    }
};

} // namespace message

} // namespace cc_mqtt311