/// @file
/// @brief Contains definition of <b>"PUBLISH"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/ArrayList.h"
#include "comms/field/Optional.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/PacketId.h"
#include "mqtt311/field/Topic.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Publish.
/// @tparam TOpt Extra options
/// @see @ref Publish
/// @headerfile "mqtt311/message/Publish.h"
template <typename TOpt = mqtt311::DefaultOptions>
struct PublishFields
{
    /// @brief Definition of <b>"Topic"</b> field.
    using Topic =
        mqtt311::field::Topic<
           TOpt
       >;
    
    /// @brief Definition of <b>"Packet ID"</b> field.
    struct PacketId : public
        comms::field::Optional<
            mqtt311::field::PacketId<TOpt>,
            comms::option::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "Packet ID";
        }
        
    };
    
    /// @brief Definition of <b>"Payload"</b> field.
    struct Payload : public
        comms::field::ArrayList<
            mqtt311::field::FieldBase<>,
            std::uint8_t,
            typename TOpt::message::PublishFields::Payload
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return "Payload";
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
/// @headerfile "mqtt311/message/Publish.h"
template <typename TMsgBase, typename TOpt = mqtt311::DefaultOptions>
class Publish : public
    comms::MessageBase<
        TMsgBase,
        comms::option::StaticNumIdImpl<mqtt311::MsgId_Publish>,
        comms::option::FieldsImpl<typename PublishFields<TOpt>::All>,
        comms::option::MsgType<Publish<TMsgBase, TOpt> >,
        comms::option::HasName,
        comms::option::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            comms::option::StaticNumIdImpl<mqtt311::MsgId_Publish>,
            comms::option::FieldsImpl<typename PublishFields<TOpt>::All>,
            comms::option::MsgType<Publish<TMsgBase, TOpt> >,
            comms::option::HasName,
            comms::option::HasCustomRefresh
        >;

public:
    /// @brief Allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_ACCESS macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated functions are:
    ///     @li @b field_topic() for @ref PublishFields::Topic field.
    ///     @li @b field_packetId() for @ref PublishFields::PacketId field.
    ///     @li @b field_payload() for @ref PublishFields::Payload field.
    COMMS_MSG_FIELDS_ACCESS(
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
        return "PUBLISH";
    }
    
    /// @brief Custom read functionality
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        refresh_packetId(); // make sure the mode of "packet ID" is correct
        return Base::doRead(iter, len);
    }
    
    /// @brief Custom refresh functionality
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        return refresh_packetId() || updated;
    }
    
    
private:
    bool refresh_packetId()
    {
        auto& qosField = Base::transportField_flags().field_qos();
        using QosFieldType = typename std::decay<decltype(qosField)>::type;
        using QosValueType = typename QosFieldType::ValueType;
        
        auto mode = comms::field::OptionalMode::Missing;
        if (QosValueType::AtMostOnceDelivery < qosField.value()) {
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

} // namespace mqtt311


