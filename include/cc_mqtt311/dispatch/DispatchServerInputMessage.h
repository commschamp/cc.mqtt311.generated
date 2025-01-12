// Generated by commsdsl2comms v7.0.0

/// @file
/// @brief Contains dispatch to handling function(s) for client input input messages.

#pragma once

#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/input/ServerInputMessages.h"
#include "cc_mqtt311/options/DefaultOptions.h"

namespace cc_mqtt311
{

namespace dispatch
{

/// @brief Dispatch message object to its appropriate handling function.
/// @details @b switch statement based (on message ID) cast and dispatch functionality.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref cc_mqtt311::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object. Must define
///     @b handle() member function for every message type it exects
///     to handle and one for the interface class as well.
///     @code
///     using MyInterface = cc_mqtt311::Message<...>;
///     using MyConnect = cc_mqtt311::message::Connect<MyInterface, cc_mqtt311::options::DefaultOptions>;
///     using MyPublish = cc_mqtt311::message::Publish<MyInterface, cc_mqtt311::options::DefaultOptions>;
///     struct MyHandler {
///         void handle(MyConnect& msg) {...}
///         void handle(MyPublish& msg) {...}
///         ...
///         // Handle all unexpected or irrelevant messages.
///         void handle(MyInterface& msg) {...}
///     };
///     @endcode
///     Every @b handle() function may return a value, but every
///     function must return the @b same type.
/// @note Defined in cc_mqtt311/dispatch/DispatchServerInputMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchServerInputMessage(
    cc_mqtt311::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    using InterfaceType = typename std::decay<decltype(msg)>::type;
    switch(id) {
    case cc_mqtt311::MsgId_Connect:
    {
        using MsgType = cc_mqtt311::message::Connect<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Publish:
    {
        using MsgType = cc_mqtt311::message::Publish<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Puback:
    {
        using MsgType = cc_mqtt311::message::Puback<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Pubrec:
    {
        using MsgType = cc_mqtt311::message::Pubrec<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Pubrel:
    {
        using MsgType = cc_mqtt311::message::Pubrel<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Pubcomp:
    {
        using MsgType = cc_mqtt311::message::Pubcomp<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Subscribe:
    {
        using MsgType = cc_mqtt311::message::Subscribe<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Unsubscribe:
    {
        using MsgType = cc_mqtt311::message::Unsubscribe<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Pingreq:
    {
        using MsgType = cc_mqtt311::message::Pingreq<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    case cc_mqtt311::MsgId_Disconnect:
    {
        using MsgType = cc_mqtt311::message::Disconnect<InterfaceType, TProtOptions>;
        return handler.handle(static_cast<MsgType&>(msg));
    }
    default:
        break;
    };

    return handler.handle(msg);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchServerInputMessage(), but receives extra @b idx parameter.
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref cc_mqtt311::options::DefaultOptions.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
///     Expected to be @b 0.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchServerInputMessage()
/// @note Defined in cc_mqtt311/dispatch/DispatchServerInputMessage.h
template<typename TProtOptions, typename TMsg, typename THandler>
auto dispatchServerInputMessage(
    cc_mqtt311::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    if (idx != 0U) {
        return handler.handle(msg);
    }
    return dispatchServerInputMessage<TProtOptions>(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchServerInputMessage(), but passing
///     cc_mqtt311::options::DefaultOptions as first template parameter.
/// @param[in] id Numeric message ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchServerInputMessage()
/// @note Defined in cc_mqtt311/dispatch/DispatchServerInputMessage.h
template<typename TMsg, typename THandler>
auto dispatchServerInputMessageDefaultOptions(
    cc_mqtt311::MsgId id,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchServerInputMessage<cc_mqtt311::options::DefaultOptions>(id, msg, handler);
}

/// @brief Dispatch message object to its appropriate handling function.
/// @details Same as other dispatchServerInputMessageDefaultOptions(), 
///     but receives extra @b idx parameter.
/// @param[in] id Numeric message ID.
/// @param[in] idx Index of the message among messages with the same ID.
/// @param[in] msg Message object held by reference to its interface class.
/// @param[in] handler Reference to handling object.
/// @see dispatchServerInputMessageDefaultOptions()
/// @note Defined in cc_mqtt311/dispatch/DispatchServerInputMessage.h
template<typename TMsg, typename THandler>
auto dispatchServerInputMessageDefaultOptions(
    cc_mqtt311::MsgId id,
    std::size_t idx,
    TMsg& msg,
    THandler& handler) -> decltype(handler.handle(msg))
{
    return dispatchServerInputMessage<cc_mqtt311::options::DefaultOptions>(id, idx, msg, handler);
}

/// @brief Message dispatcher class to be used with
///     @b comms::processAllWithDispatchViaDispatcher() function (or similar).
/// @tparam TProtOptions Protocol options struct used for the application,
///     like @ref cc_mqtt311::options::DefaultOptions.
/// @headerfile cc_mqtt311/dispatch/DispatchServerInputMessage.h
template <typename TProtOptions = cc_mqtt311::options::DefaultOptions>
struct ServerInputMsgDispatcher
{
    /// @brief Class detection tag
    using MsgDispatcherTag = void;

    /// @brief Dispatch message to its handler.
    /// @details Uses appropriate @ref dispatchServerInputMessage() function.
    /// @param[in] id ID of the message.
    /// @param[in] idx Index (or offset) of the message among those having the same numeric ID.
    /// @param[in] msg Reference to message object.
    /// @param[in] handler Reference to handler object.
    /// @return What the @ref dispatchServerInputMessage() function returns.
    template <typename TMsg, typename THandler>
    static auto dispatch(cc_mqtt311::MsgId id, std::size_t idx, TMsg& msg, THandler& handler) ->
        decltype(cc_mqtt311::dispatch::dispatchServerInputMessage<TProtOptions>(id, idx, msg, handler))
    {
        return cc_mqtt311::dispatch::dispatchServerInputMessage<TProtOptions>(id, idx, msg, handler);
    }

    /// @brief Complementary dispatch function.
    /// @details Same as other dispatch without @b TAllMessages template parameter,
    ///     used by  @b comms::processAllWithDispatchViaDispatcher().
    template <typename TAllMessages, typename TMsg, typename THandler>
    static auto dispatch(cc_mqtt311::MsgId id, std::size_t idx, TMsg& msg, THandler& handler) ->
        decltype(dispatch(id, idx, msg, handler))
    {
        return dispatch(id, idx, msg, handler);
    }

    /// @brief Dispatch message to its handler.
    /// @details Uses appropriate @ref dispatchServerInputMessage() function.
    /// @param[in] id ID of the message.
    /// @param[in] msg Reference to message object.
    /// @param[in] handler Reference to handler object.
    /// @return What the @ref dispatchServerInputMessage() function returns.
    template <typename TMsg, typename THandler>
    static auto dispatch(cc_mqtt311::MsgId id, TMsg& msg, THandler& handler) ->
        decltype(cc_mqtt311::dispatch::dispatchServerInputMessage<TProtOptions>(id, msg, handler))
    {
        return cc_mqtt311::dispatch::dispatchServerInputMessage<TProtOptions>(id, msg, handler);
    }

    /// @brief Complementary dispatch function.
    /// @details Same as other dispatch without @b TAllMessages template parameter,
    ///     used by  @b comms::processAllWithDispatchViaDispatcher().
    template <typename TAllMessages, typename TMsg, typename THandler>
    static auto dispatch(cc_mqtt311::MsgId id, TMsg& msg, THandler& handler) ->
        decltype(dispatch(id, msg, handler))
    {
        return dispatch(id, msg, handler);
    }
};

/// @brief Message dispatcher class to be used with
///     @b comms::processAllWithDispatchViaDispatcher() function (or similar).
/// @details Same as ServerInputMsgDispatcher, but passing
///     @ref cc_mqtt311::options::DefaultOptions as template parameter.
/// @note Defined in cc_mqtt311/dispatch/DispatchServerInputMessage.h
using ServerInputMsgDispatcherDefaultOptions =
    ServerInputMsgDispatcher<>;

} // namespace dispatch

} // namespace cc_mqtt311
