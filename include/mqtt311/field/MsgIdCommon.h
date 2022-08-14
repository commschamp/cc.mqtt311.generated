// Generated by commsdsl2comms v5.0.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref mqtt311::field::MsgId field.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <utility>
#include "mqtt311/MsgId.h"

namespace mqtt311
{

namespace field
{

/// @brief Common types and functions for
///     @ref mqtt311::field::MsgId field.
struct MsgIdCommon
{
    /// @brief Values enumerator for
    ///     @ref mqtt311::field::MsgId field.
    using ValueType = mqtt311::MsgId;

    /// @brief Single value name info entry
    using ValueNameInfo = const char*;

    /// @brief Type returned from @ref valueNamesMap() member function.
    /// @details The @b first value of the pair is pointer to the map array,
    ///     The @b second value of the pair is the size of the array.
    using ValueNamesMapInfo = std::pair<const ValueNameInfo*, std::size_t>;

    /// @brief Name of the @ref mqtt311::field::MsgId field.
    static const char* name()
    {
        return "MsgId";
    }

    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        auto namesMapInfo = valueNamesMap();
        if (namesMapInfo.second <= static_cast<std::size_t>(val)) {
            return nullptr;
        }

        return namesMapInfo.first[static_cast<std::size_t>(val)];
    }

    /// @brief Retrieve map of enum value names
    static ValueNamesMapInfo valueNamesMap()
    {
        static const char* Map[] = {
            nullptr,
            "CONNECT",
            "CONNACK",
            "PUBLISH",
            "PUBACK",
            "PUBREC",
            "PUBREL",
            "PUBCOMP",
            "SUBSCRIBE",
            "SUBACK",
            "UNSUBSCRIBE",
            "UNSUBACK",
            "PINGREQ",
            "PINGRESP",
            "DISCONNECT"
        };
        static const std::size_t MapSize = std::extent<decltype(Map)>::value;

        return std::make_pair(&Map[0], MapSize);
    }
};

/// @brief Values enumerator for
///     @ref mqtt311::field::MsgId field.
using MsgIdVal = MsgIdCommon::ValueType;

} // namespace field

} // namespace mqtt311
