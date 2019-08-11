/// @file
/// @brief Contains protocol version definition.

#pragma once

#include "comms/version.h"

/// @brief Version of the protocol specification.
#define MQTT311_SPEC_VERSION (0U)

/// @brief Major version of the protocol library.
#define MQTT311_MAJOR_VERSION (0U)

/// @brief Minor version of the protocol library.
#define MQTT311_MINOR_VERSION (9U)

/// @brief Patch version of the protocol library.
#define MQTT311_PATCH_VERSION (0U)

/// @brief Full version of the protocol library as single number.
#define MQTT311_VERSION (COMMS_MAKE_VERSION(MQTT311_MAJOR_VERSION, MQTT311_MINOR_VERSION, MQTT311_PATCH_VERSION))


namespace mqtt311
{

/// @brief Version of the protocol specification.
inline constexpr unsigned specVersion()
{
    return MQTT311_SPEC_VERSION;
}

/// @brief Major version of the protocol library
inline constexpr unsigned versionMajor()
{
    return MQTT311_MAJOR_VERSION;
}

/// @brief Minor version of the protocol library
inline constexpr unsigned versionMinor()
{
    return MQTT311_MINOR_VERSION;
}

/// @brief Patch version of the protocol library
inline constexpr unsigned versionPatch()
{
    return MQTT311_PATCH_VERSION;
}

/// @brief Full version of the protocol library as single number
inline constexpr unsigned version()
{
    return MQTT311_VERSION;
}


} // namespace mqtt311


// Generated compile time check for minimal supported version of the COMMS library
static_assert(COMMS_MAKE_VERSION(2, 0, 1) <= comms::version(),
    "The version of COMMS library is too old");

