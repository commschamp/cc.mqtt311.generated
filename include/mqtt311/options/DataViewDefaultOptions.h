// Generated by commsdsl2comms v5.0.0

/// @file
/// @brief Contains definition of protocol data view default options.

#pragma once

#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace options
{

/// @brief Default data view options of the protocol.
template <typename TBase = mqtt311::options::DefaultOptions>
struct DataViewDefaultOptionsT : public TBase
{
    /// @brief Extra options for fields.
    struct field : public TBase::field
    {
        /// @brief Extra options for @ref
        ///     mqtt311::field::BinData field.
        using BinData =
            std::tuple<
                comms::option::app::OrigDataView,
                typename TBase::field::BinData
            >;

        /// @brief Extra options for @ref
        ///     mqtt311::field::ProtocolName field.
        using ProtocolName =
            std::tuple<
                comms::option::app::OrigDataView,
                typename TBase::field::ProtocolName
            >;

        /// @brief Extra options for @ref
        ///     mqtt311::field::String field.
        using String =
            std::tuple<
                comms::option::app::OrigDataView,
                typename TBase::field::String
            >;
    }; // struct field

    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for fields of
        ///     @ref mqtt311::message::Publish message.
        struct PublishFields : public TBase::message::PublishFields
        {
            /// @brief Extra options for @ref
            ///     mqtt311::message::PublishFields::Payload
            ///     field.
            using Payload =
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::message::PublishFields::Payload
                >;
        };
    }; // struct message

    /// @brief Extra options for frames.
    struct frame : public TBase::frame
    {
        /// @brief Extra options for layers of
        ///     @ref mqtt311::frame::Frame frame.
        struct FrameLayers : public TBase::frame::FrameLayers
        {
            /// @brief Extra options for @ref
            ///     mqtt311::frame::FrameLayers::Data layer.
            using Data =
                std::tuple<
                    comms::option::app::OrigDataView,
                    typename TBase::frame::FrameLayers::Data
                >;
        }; // struct FrameLayers
    }; // struct frame
};

/// @brief Alias to @ref DataViewDefaultOptionsT with default template parameter.
using DataViewDefaultOptions = DataViewDefaultOptionsT<>;

} // namespace options

} // namespace mqtt311
