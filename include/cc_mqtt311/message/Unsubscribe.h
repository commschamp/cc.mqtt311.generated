// Generated by commsdsl2comms v6.0.0

/// @file
/// @brief Contains definition of <b>"UNSUBSCRIBE"</b> message and its fields.

#pragma once

#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/PacketId.h"
#include "cc_mqtt311/field/Topic.h"
#include "cc_mqtt311/message/UnsubscribeCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Unsubscribe.
/// @tparam TOpt Extra options
/// @see @ref Unsubscribe
/// @headerfile cc_mqtt311/message/Unsubscribe.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct UnsubscribeFields
{
    /// @brief Definition of <b>"Packet ID"</b> field.
    using PacketId =
        cc_mqtt311::field::PacketId<
            TOpt
        >;

    /// @brief Scope for all the member fields of
    ///     @ref List field.
    struct ListMembers
    {
        /// @brief Definition of <b>"Topic"</b> field.
        using Topic =
            cc_mqtt311::field::Topic<
                TOpt
            >;
    };

    /// @brief Definition of <b>"List"</b> field.
    class List : public
        comms::field::ArrayList<
            cc_mqtt311::field::FieldBase<>,
            typename ListMembers::Topic,
            typename TOpt::message::UnsubscribeFields::List
        >
    {
        using Base =
            comms::field::ArrayList<
                cc_mqtt311::field::FieldBase<>,
                typename ListMembers::Topic,
                typename TOpt::message::UnsubscribeFields::List
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::UnsubscribeFieldsCommon::ListCommon::name();
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
/// @headerfile cc_mqtt311/message/Unsubscribe.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Unsubscribe : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Unsubscribe,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Unsubscribe>,
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
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Unsubscribe>,
            comms::option::def::FieldsImpl<typename UnsubscribeFields<TOpt>::All>,
            comms::option::def::MsgType<Unsubscribe<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    Unsubscribe()
    {
        Base::transportField_flags().field_qos().value() = static_cast<typename Base::TransportField_flags::Field_qos::ValueType>(1);
    }

    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_packetId index, @b Field_packetId type and @b field_packetId() access fuction
    ///         for @ref UnsubscribeFields::PacketId field.
    ///     @li @b FieldIdx_list index, @b Field_list type and @b field_list() access fuction
    ///         for @ref UnsubscribeFields::List field.
    COMMS_MSG_FIELDS_NAMES(
        packetId,
        list
    );

    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");

    /// @brief Name of the message.
    static const char* doName()
    {
        return cc_mqtt311::message::UnsubscribeCommon::name();
    }

    // Generated validity check functionality
    bool doValidOrig() const
    {
        if (!Base::doValid()) {
            return false;
        }

        return
            ((Base::transportField_flags().field_retain().getValue() == static_cast<typename Base::TransportField_flags::Field_retain::ValueType>(0)) &&
             (Base::transportField_flags().field_qos().getValue() == static_cast<typename Base::TransportField_flags::Field_qos::ValueType>(1)) &&
             (Base::transportField_flags().field_dup().getValue() == static_cast<typename Base::TransportField_flags::Field_dup::ValueType>(0)));
    }

    /// @brief Custom validity check
    bool doValid() const
    {
        if (!doValidOrig()) {
            return false;
        }

        return !field_list().value().empty();
    }
};

} // namespace message

} // namespace cc_mqtt311
