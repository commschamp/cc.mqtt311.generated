// Generated by commsdsl2comms v6.3.3

/// @file
/// @brief Contains definition of <b>"Message"</b> interface class.

#pragma once

#include <tuple>
#include "cc_mqtt311/MessageCommon.h"
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/Qos.h"
#include "comms/Message.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/options.h"

namespace cc_mqtt311
{

/// @brief Extra transport fields of @ref Message interface class.
/// @see @ref Message
/// @headerfile cc_mqtt311/Message.h
struct MessageFields
{
    /// @brief Scope for all the member fields of
    ///     @ref Flags field.
    struct FlagsMembers
    {
        /// @brief Definition of <b>""</b> field.
        class Retain : public
            comms::field::BitmaskValue<
                cc_mqtt311::field::FieldBase<>,
                comms::option::def::FixedBitLength<1U>
            >
        {
            using Base =
                comms::field::BitmaskValue<
                    cc_mqtt311::field::FieldBase<>,
                    comms::option::def::FixedBitLength<1U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_bit, @b getBitValue_bit() and @b setBitValue_bit().
            COMMS_BITMASK_BITS_SEQ(
                bit
            );

            /// @brief Retrieve name of the bit.
            /// @see @ref cc_mqtt311::MessageFieldsCommon::FlagsMembersCommon::RetainCommon::bitName().
            static const char* bitName(BitIdx idx)
            {
                return
                    cc_mqtt311::MessageFieldsCommon::FlagsMembersCommon::RetainCommon::bitName(
                        static_cast<std::size_t>(idx));
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::MessageFieldsCommon::FlagsMembersCommon::RetainCommon::name();
            }
        };

        /// @brief Definition of <b>"Qos"</b> field.
        using Qos =
            cc_mqtt311::field::Qos<
                cc_mqtt311::options::DefaultOptions,
                comms::option::def::FixedBitLength<2U>
            >;

        /// @brief Definition of <b>""</b> field.
        class Dup : public
            comms::field::BitmaskValue<
                cc_mqtt311::field::FieldBase<>,
                comms::option::def::FixedBitLength<5U>,
                comms::option::def::BitmaskReservedBits<0x1EU, 0x0U>
            >
        {
            using Base =
                comms::field::BitmaskValue<
                    cc_mqtt311::field::FieldBase<>,
                    comms::option::def::FixedBitLength<5U>,
                    comms::option::def::BitmaskReservedBits<0x1EU, 0x0U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_bit, @b getBitValue_bit() and @b setBitValue_bit().
            COMMS_BITMASK_BITS_SEQ(
                bit
            );

            /// @brief Retrieve name of the bit.
            /// @see @ref cc_mqtt311::MessageFieldsCommon::FlagsMembersCommon::DupCommon::bitName().
            static const char* bitName(BitIdx idx)
            {
                return
                    cc_mqtt311::MessageFieldsCommon::FlagsMembersCommon::DupCommon::bitName(
                        static_cast<std::size_t>(idx));
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::MessageFieldsCommon::FlagsMembersCommon::DupCommon::name();
            }
        };

        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               Retain,
               Qos,
               Dup
            >;
    };

    /// @brief Definition of <b>"Flags"</b> field.
    class Flags : public
        comms::field::Bitfield<
            cc_mqtt311::field::FieldBase<>,
            typename FlagsMembers::All,
            comms::option::def::HasVersionDependentMembers<false>
        >
    {
        using Base =
            comms::field::Bitfield<
                cc_mqtt311::field::FieldBase<>,
                typename FlagsMembers::All,
                comms::option::def::HasVersionDependentMembers<false>
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
        ///     related to @b comms::field::Bitfield class from COMMS library
        ///     for details.
        ///
        ///     The generated values, types and access functions are:
        ///     @li @b FieldIdx_retain index, @b Field_retain type and @b field_retain() access function -
        ///         for cc_mqtt311::MessageFields::FlagsMembers::Retain member field.
        ///     @li @b FieldIdx_qos index, @b Field_qos type and @b field_qos() access function -
        ///         for cc_mqtt311::MessageFields::FlagsMembers::Qos member field.
        ///     @li @b FieldIdx_dup index, @b Field_dup type and @b field_dup() access function -
        ///         for cc_mqtt311::MessageFields::FlagsMembers::Dup member field.
        COMMS_FIELD_MEMBERS_NAMES(
            retain,
            qos,
            dup
        );

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::MessageFieldsCommon::FlagsCommon::name();
        }
    };

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Flags
    >;
};

/// @brief Definition of <b>"Message"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile cc_mqtt311/Message.h
template <typename... TOpt>
class Message : public
    comms::Message<
        TOpt...,
        comms::option::def::BigEndian,
        comms::option::def::MsgIdType<cc_mqtt311::MsgId>,
        comms::option::def::ExtraTransportFields<MessageFields::All>
    >
{
    using Base =
        comms::Message<
            TOpt...,
            comms::option::def::BigEndian,
            comms::option::def::MsgIdType<cc_mqtt311::MsgId>,
            comms::option::def::ExtraTransportFields<MessageFields::All>
        >;
public:
    /// @brief Allow access to extra transport fields.
    /// @details See definition of @b COMMS_MSG_TRANSPORT_FIELDS_NAMES macro
    ///     related to @b comms::Message class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b TransportFieldIdx_flags index, @b TransportField_flags type
    ///         and @b transportField_flags() access fuction for @ref MessageFields::Flags field.
    COMMS_MSG_TRANSPORT_FIELDS_NAMES(
        flags
    );
};

} // namespace cc_mqtt311
