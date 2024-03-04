// Generated by commsdsl2comms v6.3.0

/// @file
/// @brief Contains definition of <b>"SUBSCRIBE"</b> message and its fields.

#pragma once

#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/PacketId.h"
#include "cc_mqtt311/field/Qos.h"
#include "cc_mqtt311/field/Topic.h"
#include "cc_mqtt311/message/SubscribeCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Bundle.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Subscribe.
/// @tparam TOpt Extra options
/// @see @ref Subscribe
/// @headerfile cc_mqtt311/message/Subscribe.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct SubscribeFields
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
        /// @brief Scope for all the member fields of
        ///     @ref Element field.
        struct ElementMembers
        {
            /// @brief Definition of <b>"Topic"</b> field.
            using Topic =
                cc_mqtt311::field::Topic<
                    TOpt,
                    typename TOpt::message::SubscribeFields::ListMembers::ElementMembers::Topic
                >;

            /// @brief Definition of <b>"Qos"</b> field.
            using Qos =
                cc_mqtt311::field::Qos<
                    TOpt
                >;

            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   Topic,
                   Qos
                >;
        };

        /// @brief Definition of <b>""</b> field.
        class Element : public
            comms::field::Bundle<
                cc_mqtt311::field::FieldBase<>,
                typename ElementMembers::All,
                comms::option::def::HasVersionDependentMembers<false>
            >
        {
            using Base =
                comms::field::Bundle<
                    cc_mqtt311::field::FieldBase<>,
                    typename ElementMembers::All,
                    comms::option::def::HasVersionDependentMembers<false>
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
            ///     related to @b comms::field::Bundle class from COMMS library
            ///     for details.
            ///
            ///     The generated values, types and access functions are:
            ///     @li @b FieldIdx_topic index, @b Field_topic type and @b field_topic() access function -
            ///         for cc_mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Topic member field.
            ///     @li @b FieldIdx_qos index, @b Field_qos type and @b field_qos() access function -
            ///         for cc_mqtt311::message::SubscribeFields::ListMembers::ElementMembers::Qos member field.
            COMMS_FIELD_MEMBERS_NAMES(
                topic,
                qos
            );

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::SubscribeFieldsCommon::ListMembersCommon::ElementCommon::name();
            }
        };
    };

    /// @brief Definition of <b>"List"</b> field.
    class List : public
        comms::field::ArrayList<
            cc_mqtt311::field::FieldBase<>,
            typename ListMembers::Element,
            typename TOpt::message::SubscribeFields::List
        >
    {
        using Base =
            comms::field::ArrayList<
                cc_mqtt311::field::FieldBase<>,
                typename ListMembers::Element,
                typename TOpt::message::SubscribeFields::List
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::SubscribeFieldsCommon::ListCommon::name();
        }
    };

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        PacketId,
        List
    >;
};

/// @brief Definition of <b>"SUBSCRIBE"</b> message class.
/// @details
///     See @ref SubscribeFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile cc_mqtt311/message/Subscribe.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Subscribe : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Subscribe,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Subscribe>,
        comms::option::def::FieldsImpl<typename SubscribeFields<TOpt>::All>,
        comms::option::def::MsgType<Subscribe<TMsgBase, TOpt> >,
        comms::option::def::HasName
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Subscribe,
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Subscribe>,
            comms::option::def::FieldsImpl<typename SubscribeFields<TOpt>::All>,
            comms::option::def::MsgType<Subscribe<TMsgBase, TOpt> >,
            comms::option::def::HasName
        >;

public:
    Subscribe()
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
    ///         for @ref SubscribeFields::PacketId field.
    ///     @li @b FieldIdx_list index, @b Field_list type and @b field_list() access fuction
    ///         for @ref SubscribeFields::List field.
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
        return cc_mqtt311::message::SubscribeCommon::name();
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
             (Base::transportField_flags().field_dup().getValue() == static_cast<typename Base::TransportField_flags::Field_dup::ValueType>(0)) &&
             (!field_list().getValue().empty()));
    }
};

} // namespace message

} // namespace cc_mqtt311
