// Generated by commsdsl2comms v6.3.0

/// @file
/// @brief Contains definition of protocol bare metal default options.

#pragma once

#include "cc_mqtt311/options/DefaultOptions.h"

#ifndef DEFAULT_SEQ_FIXED_STORAGE_SIZE
/// @brief Define default fixed size for various sequence fields
/// @details May be defined during compile time to change the default value.
#define DEFAULT_SEQ_FIXED_STORAGE_SIZE 32
#endif

namespace cc_mqtt311
{

namespace options
{

/// @brief Default bare metal options of the protocol.
template <typename TBase = cc_mqtt311::options::DefaultOptions>
struct BareMetalDefaultOptionsT : public TBase
{
    /// @brief Extra options for fields.
    struct field : public TBase::field
    {
        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::BinData field.
        using BinData =
            std::tuple<
                comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                typename TBase::field::BinData
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::ProtocolName field.
        using ProtocolName =
            std::tuple<
                comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                typename TBase::field::ProtocolName
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::field::String field.
        using String =
            std::tuple<
                comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                typename TBase::field::String
            >;
    }; // struct field

    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Publish message.
        struct PublishFields : public TBase::message::PublishFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::PublishFields::Payload
            ///     field.
            using Payload =
                std::tuple<
                    comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                    typename TBase::message::PublishFields::Payload
                >;
        };

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Suback message.
        struct SubackFields : public TBase::message::SubackFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::SubackFields::List
            ///     field.
            using List =
                std::tuple<
                    comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                    typename TBase::message::SubackFields::List
                >;
        };

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Subscribe message.
        struct SubscribeFields : public TBase::message::SubscribeFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::SubscribeFields::List
            ///     field.
            using List =
                std::tuple<
                    comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                    typename TBase::message::SubscribeFields::List
                >;
        };

        /// @brief Extra options for fields of
        ///     @ref cc_mqtt311::message::Unsubscribe message.
        struct UnsubscribeFields : public TBase::message::UnsubscribeFields
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::message::UnsubscribeFields::List
            ///     field.
            using List =
                std::tuple<
                    comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE>,
                    typename TBase::message::UnsubscribeFields::List
                >;
        };
    }; // struct message

    /// @brief Extra options for frames.
    struct frame : public TBase::frame
    {
        /// @brief Extra options for layers of
        ///     @ref cc_mqtt311::frame::Frame frame.
        struct FrameLayers : public TBase::frame::FrameLayers
        {
            /// @brief Extra options for @ref
            ///     cc_mqtt311::frame::FrameLayers::Data
            ///     layer.
            using Data =
                std::tuple<
                    comms::option::app::FixedSizeStorage<DEFAULT_SEQ_FIXED_STORAGE_SIZE * 8>,
                    typename TBase::frame::FrameLayers::Data
                >;

            /// @brief Extra options for @ref
            ///     cc_mqtt311::frame::FrameLayers::IdAndFlags
            ///     layer.
            using IdAndFlags =
                std::tuple<
                    comms::option::app::InPlaceAllocation,
                    typename TBase::frame::FrameLayers::IdAndFlags
                >;
        }; // struct FrameLayers
    }; // struct frame
};

/// @brief Alias to @ref BareMetalDefaultOptionsT with default template parameter.
using BareMetalDefaultOptions = BareMetalDefaultOptionsT<>;

} // namespace options

} // namespace cc_mqtt311
