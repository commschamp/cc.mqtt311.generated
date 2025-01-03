// Generated by commsdsl2comms v7.0.0

/// @file
/// @brief Contains message factory with dynamic memory allocation for all the messages.

#pragma once

#include <memory>
#include "cc_mqtt311/input/AllMessages.h"
#include "comms/MsgFactoryCreateFailureReason.h"

namespace cc_mqtt311
{

namespace factory
{

/// @brief Message factory with dynamic memory allocation for all the messages.
/// @details Defines the same public interface as @b comms::MsgFactory and intended for
///     its replacement.
/// @tparam TInterface Interface class of the messages.
/// @tparam TProtOptions Application specific protocol definition options.
template<typename TInterface, typename TProtOptions>
class AllMessagesDynMemMsgFactory
{
public:
    /// @brief Type of the common base class of all the messages.
    using Message = TInterface;

    /// @brief Type of the message ID when passed as a parameter.
    using MsgIdParamType = typename Message::MsgIdParamType;

    /// @brief Type of the message ID.
    using MsgIdType = typename Message::MsgIdType;

    /// @brief Smart pointer to @ref Message which holds allocated message object.
    using MsgPtr = std::unique_ptr<Message>;

    /// @brief Reason for message creation failure
    using CreateFailureReason = comms::MsgFactoryCreateFailureReason;

    /// @brief Type of generic message.
    /// @details Not supported
    using GenericMessage = void;

    /// @brief Create message object given the ID of the message.
    /// @param id ID of the message.
    /// @param idx Relative index (or offset) of the message with the same ID.
    /// @param[out] reason Failure reason in case creation has failed.
    MsgPtr createMsg(MsgIdParamType id, unsigned idx = 0U, CreateFailureReason* reason = nullptr) const
    {
        auto updateReasonFunc =
            [reason](CreateFailureReason val)
            {
                if (reason != nullptr) {
                    *reason = val;
                }
            };

        if (1U <= idx) {
            updateReasonFunc(CreateFailureReason::InvalidId);
            return MsgPtr();
        }

        updateReasonFunc(CreateFailureReason::None);
        switch (id) {
            case cc_mqtt311::MsgId_Connect: return MsgPtr(new cc_mqtt311::message::Connect<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Connack: return MsgPtr(new cc_mqtt311::message::Connack<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Publish: return MsgPtr(new cc_mqtt311::message::Publish<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Puback: return MsgPtr(new cc_mqtt311::message::Puback<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Pubrec: return MsgPtr(new cc_mqtt311::message::Pubrec<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Pubrel: return MsgPtr(new cc_mqtt311::message::Pubrel<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Pubcomp: return MsgPtr(new cc_mqtt311::message::Pubcomp<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Subscribe: return MsgPtr(new cc_mqtt311::message::Subscribe<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Suback: return MsgPtr(new cc_mqtt311::message::Suback<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Unsubscribe: return MsgPtr(new cc_mqtt311::message::Unsubscribe<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Unsuback: return MsgPtr(new cc_mqtt311::message::Unsuback<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Pingreq: return MsgPtr(new cc_mqtt311::message::Pingreq<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Pingresp: return MsgPtr(new cc_mqtt311::message::Pingresp<TInterface, TProtOptions>);
            case cc_mqtt311::MsgId_Disconnect: return MsgPtr(new cc_mqtt311::message::Disconnect<TInterface, TProtOptions>);
            default: break;
        }

        updateReasonFunc(CreateFailureReason::InvalidId);
        return MsgPtr();
    }

    /// @brief Allocate and initialise @b comms::GenericMessage object.
    MsgPtr createGenericMsg(MsgIdParamType id, unsigned idx = 0U) const
    {
        static_cast<void>(id);
        static_cast<void>(idx);
        return MsgPtr();
    }

    /// @brief Inquiry whether allocation is possible
    bool canAllocate() const
    {
        return true;
    }

    /// @brief Get number of message types that have the specified ID.
    /// @param id ID of the message.
    /// @return Number of message classes that report same ID.
    std::size_t msgCount(MsgIdParamType id) const
    {
        switch (id)
        {
            case cc_mqtt311::MsgId_Connect: return 1U;
            case cc_mqtt311::MsgId_Connack: return 1U;
            case cc_mqtt311::MsgId_Publish: return 1U;
            case cc_mqtt311::MsgId_Puback: return 1U;
            case cc_mqtt311::MsgId_Pubrec: return 1U;
            case cc_mqtt311::MsgId_Pubrel: return 1U;
            case cc_mqtt311::MsgId_Pubcomp: return 1U;
            case cc_mqtt311::MsgId_Subscribe: return 1U;
            case cc_mqtt311::MsgId_Suback: return 1U;
            case cc_mqtt311::MsgId_Unsubscribe: return 1U;
            case cc_mqtt311::MsgId_Unsuback: return 1U;
            case cc_mqtt311::MsgId_Pingreq: return 1U;
            case cc_mqtt311::MsgId_Pingresp: return 1U;
            case cc_mqtt311::MsgId_Disconnect: return 1U;
            default: break;
        }

        return 0U;
    }

    /// @brief Compile time inquiry whether all the message classes have unique IDs.
    static constexpr bool hasUniqueIds()
    {
        return true;
    }

    /// @brief Compile time inquiry whether polymorphic dispatch tables are
    ///     generated internally to map message ID to actual type.
    static constexpr bool isDispatchPolymorphic()
    {
        return false;
    }

    /// @brief Compile time inquiry whether static binary search dispatch is
    ///     generated internally to map message ID to actual type.
    static constexpr bool isDispatchStaticBinSearch()
    {
        return false;
    }

    /// @brief Compile time inquiry whether linear switch dispatch is
    ///     generated internally to map message ID to actual type.
    static constexpr bool isDispatchLinearSwitch()
    {
        return false;
    }

    /// @brief Compile time inquiry whether factory supports in-place allocation
    static constexpr bool hasInPlaceAllocation()
    {
        return false;
    }

    /// @brief Compile time inquiry whether factory supports @b comms::GenericMessage allocation.
    static constexpr bool hasGenericMessageSupport()
    {
        return false;
    }

    /// @brief Compile time inquiry whether factory has forced dispatch method
    static constexpr bool hasForcedDispatch()
    {
        return true;
    }
};

} // namespace factory

} // namespace cc_mqtt311
