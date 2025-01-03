// Generated by commsdsl2comms v7.0.0

/// @file
/// @brief Contains definition of protocol client default options.

#pragma once

#include "cc_mqtt311/options/DefaultOptions.h"

namespace cc_mqtt311
{

namespace options
{

/// @brief Default client options of the protocol.
template <typename TBase = cc_mqtt311::options::DefaultOptions>
struct ClientDefaultOptionsT : public TBase
{
    /// @brief Extra options for messages.
    struct message : public TBase::message
    {
        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Connack message.
        using Connack =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Connack
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Connect
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Disconnect message.
        using Disconnect =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Disconnect
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Pingreq message.
        using Pingreq =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Pingreq
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Pingresp message.
        using Pingresp =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Pingresp
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Suback message.
        using Suback =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Suback
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Subscribe message.
        using Subscribe =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Subscribe
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Unsuback message.
        using Unsuback =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl,
                typename TBase::message::Unsuback
            >;

        /// @brief Extra options for @ref
        ///     cc_mqtt311::message::Unsubscribe
        ///     message.
        using Unsubscribe =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl,
                typename TBase::message::Unsubscribe
            >;
    }; // struct message
};

/// @brief Alias to @ref ClientDefaultOptionsT with default template parameter.
using ClientDefaultOptions = ClientDefaultOptionsT<>;

} // namespace options

} // namespace cc_mqtt311
