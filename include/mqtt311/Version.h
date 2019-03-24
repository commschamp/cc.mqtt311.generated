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


// Generated compile time check for minimal supported version of the COMMS library
static_assert(COMMS_MAKE_VERSION(1, 0, 0) <= comms::version(),
    "The version of COMMS library is too old");

// Extra version check: mqtt311::frame::layer::IdAndFlags uses 
// features introduced in v1.2 of the COMMS library.
static_assert(COMMS_MAKE_VERSION(1, 2, 0) <= comms::version(),
    "The version of COMMS library is too old");

