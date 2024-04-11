// Generated by commsdsl2comms v6.3.2

/// @file
/// @brief Contains definition of <b>"PUBREL"</b> message and its fields.

#pragma once

#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/PacketId.h"
#include "cc_mqtt311/message/PubrelCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Pubrel.
/// @tparam TOpt Extra options
/// @see @ref Pubrel
/// @headerfile cc_mqtt311/message/Pubrel.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct PubrelFields
{
    /// @brief Definition of <b>"Packet ID"</b> field.
    using PacketId =
        cc_mqtt311::field::PacketId<
            TOpt
        >;

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        PacketId
    >;
};

/// @brief Definition of <b>"PUBREL"</b> message class.
/// @details
///     See @ref PubrelFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile cc_mqtt311/message/Pubrel.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Pubrel : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Pubrel>,
        comms::option::def::FieldsImpl<typename PubrelFields<TOpt>::All>,
        comms::option::def::MsgType<Pubrel<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Pubrel>,
            comms::option::def::FieldsImpl<typename PubrelFields<TOpt>::All>,
            comms::option::def::MsgType<Pubrel<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    Pubrel()
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
    ///         for @ref PubrelFields::PacketId field.
    COMMS_MSG_FIELDS_NAMES(
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
        return cc_mqtt311::message::PubrelCommon::name();
    }

    // Generated validity check functionality
    bool doValid() const
    {
        if (!Base::doValid()) {
            return false;
        }

        return
            ((Base::transportField_flags().field_retain().getValue() == static_cast<typename Base::TransportField_flags::Field_retain::ValueType>(0)) &&
             (Base::transportField_flags().field_qos().getValue() == static_cast<typename Base::TransportField_flags::Field_qos::ValueType>(1)) &&
             (Base::transportField_flags().field_dup().getValue() == static_cast<typename Base::TransportField_flags::Field_dup::ValueType>(0)));
    }
};

} // namespace message

} // namespace cc_mqtt311
