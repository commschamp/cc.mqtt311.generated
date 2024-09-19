// Generated by commsdsl2comms v6.3.4

/// @file
/// @brief Contains protocol version definition.

#pragma once

#include "comms/version.h"

/// @brief Version of the protocol specification.
#define CC_MQTT311_SPEC_VERSION (0U)

/// @brief Major version of the protocol library.
#define CC_MQTT311_MAJOR_VERSION (2)

/// @brief Minor version of the protocol library.
#define CC_MQTT311_MINOR_VERSION (8)

/// @brief Patch version of the protocol library.
#define CC_MQTT311_PATCH_VERSION (1)

/// @brief Full version of the protocol library as single number.
#define CC_MQTT311_VERSION (COMMS_MAKE_VERSION(CC_MQTT311_MAJOR_VERSION, CC_MQTT311_MINOR_VERSION, CC_MQTT311_PATCH_VERSION))

namespace cc_mqtt311
{

/// @brief Version of the protocol specification.
inline constexpr unsigned specVersion()
{
    return CC_MQTT311_SPEC_VERSION;
}

/// @brief Major version of the protocol library
inline constexpr unsigned versionMajor()
{
    return CC_MQTT311_MAJOR_VERSION;
}

/// @brief Minor version of the protocol library
inline constexpr unsigned versionMinor()
{
    return CC_MQTT311_MINOR_VERSION;
}

/// @brief Patch version of the protocol library
inline constexpr unsigned versionPatch()
{
    return CC_MQTT311_PATCH_VERSION;
}

/// @brief Full version of the protocol library as a single number
inline constexpr unsigned version()
{
    return CC_MQTT311_VERSION;
}

} // namespace cc_mqtt311

// Generated compile time check for minimal supported version of the COMMS library
static_assert(COMMS_MAKE_VERSION(5, 2, 7) <= comms::version(),
    "The version of COMMS library is too old");
