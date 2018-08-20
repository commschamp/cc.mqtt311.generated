/// @file
/// @brief Contains definition of message ids enumeration.

#pragma once

#include <cstdint>

namespace mqtt311
{

/// @brief Message ids enumeration.
enum MsgId : std::uint8_t
{
    MsgId_Connect = 1, ///< message id @b Connect
    MsgId_Connack = 2, ///< message id @b Connack
    MsgId_Publish = 3, ///< message id @b Publish
    MsgId_Puback = 4, ///< message id @b Puback
    MsgId_Pubrec = 5, ///< message id @b Pubrec
    MsgId_Pubrel = 6, ///< message id @b Pubrel
    MsgId_Pubcomp = 7, ///< message id @b Pubcomp
    MsgId_Subscribe = 8, ///< message id @b Subscribe
    MsgId_Suback = 9, ///< message id @b Suback
    MsgId_Unsubscribe = 10, ///< message id @b Unsubscribe
    MsgId_Unsuback = 11, ///< message id @b Unsuback
    MsgId_Pingreq = 12, ///< message id @b Pingreq
    MsgId_Pingresp = 13, ///< message id @b Pingresp
    MsgId_Disconnect = 14, ///< message id @b Disconnect
    
};

} // namespace mqtt311


