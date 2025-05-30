// Generated by commsdsl2comms v7.1.0

/// @file
/// @brief Contains definition of <b>"PUBLISH"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/PacketId.h"
#include "cc_mqtt311/field/Topic.h"
#include "cc_mqtt311/message/PublishCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Optional.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Publish.
/// @tparam TOpt Extra options
/// @see @ref Publish
/// @headerfile cc_mqtt311/message/Publish.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct PublishFields
{
    /// @brief Definition of <b>"Topic"</b> field.
    using Topic =
        cc_mqtt311::field::Topic<
            TOpt,
            typename TOpt::message::PublishFields::Topic,
            comms::option::def::HasName
        >;

    /// @brief Definition of <b>"Packet ID"</b> field.
    class PacketId : public
        comms::field::Optional<
            cc_mqtt311::field::PacketId<TOpt>,
            comms::option::def::HasName,
            comms::option::def::MissingByDefault
        >
    {
        using Base =
            comms::field::Optional<
                cc_mqtt311::field::PacketId<TOpt>,
                comms::option::def::HasName,
                comms::option::def::MissingByDefault
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::PublishFieldsCommon::PacketIdCommon::name();
        }
    };

    /// @brief Definition of <b>"Payload"</b> field.
    class Payload : public
        comms::field::ArrayList<
            cc_mqtt311::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::PublishFields::Payload,
            comms::option::def::HasName
        >
    {
        using Base =
            comms::field::ArrayList<
                cc_mqtt311::field::FieldBase<>,
                std::uint8_t,
                typename TOpt::message::PublishFields::Payload,
                comms::option::def::HasName
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::PublishFieldsCommon::PayloadCommon::name();
        }
    };

    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        Topic,
        PacketId,
        Payload
    >;
};

/// @brief Definition of <b>"PUBLISH"</b> message class.
/// @details
///     See @ref PublishFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile cc_mqtt311/message/Publish.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Publish : public
    comms::MessageBase<
        TMsgBase,
        comms::option::def::StaticNumIdImpl<3 /* 0x3 */>,
        comms::option::def::FieldsImpl<typename PublishFields<TOpt>::All>,
        comms::option::def::MsgType<Publish<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::def::StaticNumIdImpl<3 /* 0x3 */>,
            comms::option::def::FieldsImpl<typename PublishFields<TOpt>::All>,
            comms::option::def::MsgType<Publish<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_topic index, @b Field_topic type and @b field_topic() access fuction
    ///         for @ref PublishFields::Topic field.
    ///     @li @b FieldIdx_packetId index, @b Field_packetId type and @b field_packetId() access fuction
    ///         for @ref PublishFields::PacketId field.
    ///     @li @b FieldIdx_payload index, @b Field_payload type and @b field_payload() access fuction
    ///         for @ref PublishFields::Payload field.
    COMMS_MSG_FIELDS_NAMES(
        topic,
        packetId,
        payload
    );

    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 2U, "Unexpected min serialisation length");

    /// @brief Name of the message.
    static const char* doName()
    {
        return cc_mqtt311::message::PublishCommon::name();
    }

    /// @brief Generated read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = comms::ErrorStatus::Success;
        do {
            es = Base::template doReadUntilAndUpdateLen<FieldIdx_packetId>(iter, len);
            if (es != comms::ErrorStatus::Success) {
                break;
            }

            readPrepare_packetId();

            es = Base::template doReadFrom<FieldIdx_packetId>(iter, len);
        } while (false);

        return es;
    }

    /// @brief Generated refresh functionality.
    bool doRefresh()
    {
       bool updated = Base::doRefresh();
       updated = refresh_packetId() || updated;
       return updated;
    }

private:
    void readPrepare_packetId()
    {
        refresh_packetId();
    }

    bool refresh_packetId()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (Base::transportField_flags().field_qos().getValue() > static_cast<typename Base::TransportField_flags::Field_qos::ValueType>(0)) {
            mode = comms::field::OptionalMode::Exists;
        }

        if (field_packetId().getMode() == mode) {
            return false;
        }

        field_packetId().setMode(mode);
        return true;
    }
};

} // namespace message

} // namespace cc_mqtt311
