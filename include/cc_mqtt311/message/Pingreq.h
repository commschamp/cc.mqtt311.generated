// Generated by commsdsl2comms v6.2.0

/// @file
/// @brief Contains definition of <b>"PINGREQ"</b> message and its fields.

#pragma once

#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/message/PingreqCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Pingreq.
/// @tparam TOpt Extra options
/// @see @ref Pingreq
/// @headerfile cc_mqtt311/message/Pingreq.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct PingreqFields
{
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
    >;
};

/// @brief Definition of <b>"PINGREQ"</b> message class.
/// @details
///     See @ref PingreqFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile cc_mqtt311/message/Pingreq.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Pingreq : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Pingreq,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Pingreq>,
        comms::option::def::FieldsImpl<typename PingreqFields<TOpt>::All>,
        comms::option::def::MsgType<Pingreq<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Pingreq,
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Pingreq>,
            comms::option::def::FieldsImpl<typename PingreqFields<TOpt>::All>,
            comms::option::def::MsgType<Pingreq<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static const std::size_t MsgMaxLen = Base::doMaxLength();
    static_assert(MsgMinLen == 0U, "Unexpected min serialisation length");
    static_assert(MsgMaxLen == 0U, "Unexpected max serialisation length");

    /// @brief Name of the message.
    static const char* doName()
    {
        return cc_mqtt311::message::PingreqCommon::name();
    }

    // Generated validity check functionality
    bool doValid() const
    {
        if (!Base::doValid()) {
            return false;
        }

        return
            ((Base::transportField_flags().field_retain().getValue() == static_cast<typename Base::TransportField_flags::Field_retain::ValueType>(0)) &&
             (Base::transportField_flags().field_qos().getValue() == static_cast<typename Base::TransportField_flags::Field_qos::ValueType>(0)) &&
             (Base::transportField_flags().field_dup().getValue() == static_cast<typename Base::TransportField_flags::Field_dup::ValueType>(0)));
    }
};

} // namespace message

} // namespace cc_mqtt311
