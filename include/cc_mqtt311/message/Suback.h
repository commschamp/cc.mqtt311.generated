// Generated by commsdsl2comms v7.0.2

/// @file
/// @brief Contains definition of <b>"SUBACK"</b> message and its fields.

#pragma once

#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/PacketId.h"
#include "cc_mqtt311/message/SubackCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Suback.
/// @tparam TOpt Extra options
/// @see @ref Suback
/// @headerfile cc_mqtt311/message/Suback.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct SubackFields
{
    /// @brief Definition of <b>"Packet ID"</b> field.
    using PacketId =
        cc_mqtt311::field::PacketId<
            TOpt,
            comms::option::def::HasName
        >;

    /// @brief Scope for all the member fields of
    ///     @ref List field.
    struct ListMembers
    {
        /// @brief Definition of <b>"Return Code"</b> field.
        /// @see @ref cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::ValueType
        class ReturnCode : public
            comms::field::EnumValue<
                cc_mqtt311::field::FieldBase<>,
                cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::ValueType,
                comms::option::def::HasName,
                comms::option::def::ValidNumValueRange<0, 2>,
                comms::option::def::ValidNumValue<128>
            >
        {
            using Base =
                comms::field::EnumValue<
                    cc_mqtt311::field::FieldBase<>,
                    cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::ValueType,
                    comms::option::def::HasName,
                    comms::option::def::ValidNumValueRange<0, 2>,
                    comms::option::def::ValidNumValue<128>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;

            /// @brief Single value name info entry.
            using ValueNameInfo = cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::ValueNameInfo;

            /// @brief Type returned from @ref valueNamesMap() member function.
            /// @see @ref cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::ValueNamesMapInfo.
            using ValueNamesMapInfo = cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::ValueNamesMapInfo;

            /// @brief Retrieve name of the enum value.
            /// @see @ref cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::valueName().
            static const char* valueName(ValueType val)
            {
                return cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::valueName(val);
            }

            /// @brief Retrieve name of the enum value.
            /// @see @ref cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::valueName().
            static const char* valueNameOf(ValueType val)
            {
                return cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::valueName(val);
            }

            /// @brief Retrieve name of the @b current value
            const char* valueName() const
            {
                return valueName(Base::getValue());
            }

            /// @brief Retrieve map of enum value names.
            /// @see @ref cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::valueNamesMap().
            static ValueNamesMapInfo valueNamesMap()
            {
                return cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::valueNamesMap();
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::SubackFieldsCommon::ListMembersCommon::ReturnCodeCommon::name();
            }
        };
    };

    /// @brief Definition of <b>"List"</b> field.
    class List : public
        comms::field::ArrayList<
            cc_mqtt311::field::FieldBase<>,
            typename ListMembers::ReturnCode,
            typename TOpt::message::SubackFields::List,
            comms::option::def::HasName
        >
    {
        using Base =
            comms::field::ArrayList<
                cc_mqtt311::field::FieldBase<>,
                typename ListMembers::ReturnCode,
                typename TOpt::message::SubackFields::List,
                comms::option::def::HasName
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::SubackFieldsCommon::ListCommon::name();
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
/// @headerfile cc_mqtt311/message/Suback.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Suback : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Suback,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Suback>,
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
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Suback>,
            comms::option::def::FieldsImpl<typename SubackFields<TOpt>::All>,
            comms::option::def::MsgType<Suback<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_packetId index, @b Field_packetId type and @b field_packetId() access fuction
    ///         for @ref SubackFields::PacketId field.
    ///     @li @b FieldIdx_list index, @b Field_list type and @b field_list() access fuction
    ///         for @ref SubackFields::List field.
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
        return cc_mqtt311::message::SubackCommon::name();
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
             (Base::transportField_flags().field_dup().getValue() == static_cast<typename Base::TransportField_flags::Field_dup::ValueType>(0)) &&
             (!field_list().getValue().empty()));
    }
};

} // namespace message

} // namespace cc_mqtt311
