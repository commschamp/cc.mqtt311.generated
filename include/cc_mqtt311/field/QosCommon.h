// Generated by commsdsl2comms v6.0.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::field::Qos field.

#pragma once

#include <cstdint>
#include <type_traits>
#include <utility>

namespace cc_mqtt311
{

namespace field
{

/// @brief Common types and functions for
///     @ref cc_mqtt311::field::Qos field.
struct QosCommon
{
    /// @brief Values enumerator for
    ///     @ref cc_mqtt311::field::Qos field.
    enum class ValueType : std::uint8_t
    {
        AtMostOnceDelivery = 0, ///< value @b AtMostOnceDelivery. 
        AtLeastOnceDelivery = 1, ///< value @b AtLeastOnceDelivery. 
        ExactlyOnceDelivery = 2, ///< value @b ExactlyOnceDelivery. 

        // --- Extra values generated for convenience ---
        FirstValue = 0, ///< First defined value.
        LastValue = 2, ///< Last defined value.
        ValuesLimit = 3, ///< Upper limit for defined values.
    };

    /// @brief Single value name info entry
    using ValueNameInfo = const char*;

    /// @brief Type returned from @ref valueNamesMap() member function.
    /// @details The @b first value of the pair is pointer to the map array,
    ///     The @b second value of the pair is the size of the array.
    using ValueNamesMapInfo = std::pair<const ValueNameInfo*, std::size_t>;

    /// @brief Name of the @ref cc_mqtt311::field::Qos field.
    static const char* name()
    {
        return "Qos";
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
            "AtMostOnceDelivery",
            "AtLeastOnceDelivery",
            "ExactlyOnceDelivery"
        };
        static const std::size_t MapSize = std::extent<decltype(Map)>::value;

        return std::make_pair(&Map[0], MapSize);
    }
};

/// @brief Values enumerator for
///     @ref cc_mqtt311::field::Qos field.
using QosVal = QosCommon::ValueType;

} // namespace field

} // namespace cc_mqtt311
