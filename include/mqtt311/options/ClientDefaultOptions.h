/// @file
/// @brief Contains definition of protocol default options for a client.

#pragma once

#include "DefaultOptions.h"

namespace mqtt311
{

namespace options
{

/// @brief Default options of the protocol for a client.
struct ClientDefaultOptions : public DefaultOptions
{
    /// @brief Extra options for messages.
    struct message : public DefaultOptions::message
    {
        /// @brief Extra options for
        ///     @ref mqtt311::message::Connack message.
        using Connack =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Connect message.
        using Connect =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Disconnect message.
        using Disconnect =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Pingreq message.
        using Pingreq =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Pingresp message.
        using Pingresp =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Suback message.
        using Suback =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Subscribe message.
        using Subscribe =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Unsuback message.
        using Unsuback =
            std::tuple<
                comms::option::app::NoWriteImpl,
                comms::option::app::NoRefreshImpl
            >;
        
        /// @brief Extra options for
        ///     @ref mqtt311::message::Unsubscribe message.
        using Unsubscribe =
            std::tuple<
                comms::option::app::NoReadImpl,
                comms::option::app::NoDispatchImpl
            >;
        
    };
    
};

} // namespace options

} // namespace mqtt311

