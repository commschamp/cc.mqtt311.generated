/// @file
/// @brief Contains protocol version definition.

#pragma once

#include "comms/version.h"

/// @brief Version of the protocol library as single numeric value
#define MQTT311_VERSION (0U)

namespace mqtt311
{

/// @brief Version of the protocol library as single numeric value
inline constexpr unsigned version()
{
    return MQTT311_VERSION;
}

} // namespace mqtt311


static_assert(COMMS_MAKE_VERSION(1, 0, 0) <= comms::version(),
    "The version of COMMS library is too old");

