/// @file
/// @brief Contains definition of <b>"Message"</b> interface class.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/Message.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"

namespace mqtt311
{

/// @brief Extra transport fields of @ref Message interface class.
/// @see @ref Message
/// @headerfile "mqtt311/Message.h"
struct MessageFields
{
    /// @brief Scope for all the member fields of @ref Flags bitfield.
    struct FlagsMembers
    {
        /// @brief Definition of <b>""</b> field.
        class Retain : public
            comms::field::BitmaskValue<
                mqtt311::field::FieldBase<>,
                comms::option::FixedBitLength<1U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    mqtt311::field::FieldBase<>,
                    comms::option::FixedBitLength<1U>
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
            
            /// @brief Name of the field.
            static const char* name()
            {
                return "";
            }
            
        };
        
        /// @brief Values enumerator for @ref Qos field.
        enum class QosVal : std::uint8_t
        {
            AtMostOnceDelivery = 0, ///< value @b AtMostOnceDelivery
            AtLeastOnceDelivery = 1, ///< value @b AtLeastOnceDelivery
            ExactlyOnceDelivery = 2, ///< value @b ExactlyOnceDelivery
            
        };
        
        /// @brief Definition of <b>"Qos"</b> field.
        struct Qos : public
            comms::field::EnumValue<
                mqtt311::field::FieldBase<>,
                QosVal,
                comms::option::FixedBitLength<2U>,
                comms::option::ValidNumValueRange<0, 2>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return "Qos";
            }
            
        };
        
        /// @brief Definition of <b>""</b> field.
        class Dup : public
            comms::field::BitmaskValue<
                mqtt311::field::FieldBase<>,
                comms::option::FixedBitLength<5U>,
                comms::option::BitmaskReservedBits<0x1EU, 0x0U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    mqtt311::field::FieldBase<>,
                    comms::option::FixedBitLength<5U>,
                    comms::option::BitmaskReservedBits<0x1EU, 0x0U>
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
            
            /// @brief Name of the field.
            static const char* name()
            {
                return "";
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
            mqtt311::field::FieldBase<>,
            typename FlagsMembers::All
        >
    {
        using Base = 
            comms::field::Bitfield<
                mqtt311::field::FieldBase<>,
                typename FlagsMembers::All
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_ACCESS macro
        ///     related to @b comms::field::Bitfield class from COMMS library
        ///     for details.
        ///
        ///      The generated access functions are:
        ///     @li @b field_retain() - for FlagsMembers::Retain member field.
        ///     @li @b field_qos() - for FlagsMembers::Qos member field.
        ///     @li @b field_dup() - for FlagsMembers::Dup member field.
        COMMS_FIELD_MEMBERS_ACCESS(
            retain,
            qos,
            dup
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return "Flags";
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Flags
    >;
};

/// @brief Definition of <b>"Message"</b> common interface class.
/// @tparam TOpt Interface definition options
/// @headerfile "mqtt311/Message.h"
template <typename... TOpt>
class Message : public
    comms::Message<
        TOpt...,
        comms::option::BigEndian,
        comms::option::MsgIdType<mqtt311::MsgId>,
        comms::option::ExtraTransportFields<MessageFields::All>
    >
{
    using Base =
        comms::Message<
            TOpt...,
            comms::option::BigEndian,
            comms::option::MsgIdType<mqtt311::MsgId>,
            comms::option::ExtraTransportFields<MessageFields::All>
        >;
public:
    /// @brief Allow access to extra transport fields.
    /// @details See definition of @b COMMS_MSG_TRANSPORT_FIELDS_ACCESS macro
    ///     related to @b comms::Message class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b transportField_flags() for @ref MessageFields::Flags field.
    COMMS_MSG_TRANSPORT_FIELDS_ACCESS(
        flags
    );
};

} // namespace mqtt311


