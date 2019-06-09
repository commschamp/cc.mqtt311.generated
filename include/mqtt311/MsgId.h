/// @file
/// @brief Contains definition of message ids enumeration.

#pragma once

#include <cstdint>
#include "mqtt311/Version.h"

namespace mqtt311
{

/// @brief Message ids enumeration.
enum MsgId : std::uint8_t
{
    MsgId_Connect = 1, ///< message id of <b>CONNECT</b> message.
    MsgId_Connack = 2, ///< message id of <b>CONNACK</b> message.
    MsgId_Publish = 3, ///< message id of <b>PUBLISH</b> message.
    MsgId_Puback = 4, ///< message id of <b>PUBACK</b> message.
    MsgId_Pubrec = 5, ///< message id of <b>PUBREC</b> message.
    MsgId_Pubrel = 6, ///< message id of <b>PUBREL</b> message.
    MsgId_Pubcomp = 7, ///< message id of <b>PUBCOMP</b> message.
    MsgId_Subscribe = 8, ///< message id of <b>SUBSCRIBE</b> message.
    MsgId_Suback = 9, ///< message id of <b>SUBACK</b> message.
    MsgId_Unsubscribe = 10, ///< message id of <b>UNSUBSCRIBE</b> message.
    MsgId_Unsuback = 11, ///< message id of <b>UNSUBACK</b> message.
    MsgId_Pingreq = 12, ///< message id of <b>PINGREQ</b> message.
    MsgId_Pingresp = 13, ///< message id of <b>PINGRESP</b> message.
    MsgId_Disconnect = 14, ///< message id of <b>DISCONNECT</b> message.
    
};

} // namespace mqtt311


