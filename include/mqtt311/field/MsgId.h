/// @file
/// @brief Contains definition of <b>"MsgId"</b> field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace field
{

/// @brief Common functions for
///     @ref mqtt311::field::MsgId field.
struct MsgIdCommon
{
    /// @brief Retrieve name of the enum value
    static const char* valueName(mqtt311::MsgId val)
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
        
        if (MapSize <= static_cast<std::size_t>(val)) {
            return nullptr;
        }
        
        return Map[static_cast<std::size_t>(val)];
    }
    
};

/// @brief Definition of <b>"MsgId"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::options::DefaultOptions, typename... TExtraOpts>
struct MsgId : public
    comms::field::EnumValue<
        mqtt311::field::FieldBase<>,
        mqtt311::MsgId,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<1, 14>
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return "MsgId";
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(mqtt311::MsgId val)
    {
        return mqtt311::field::MsgIdCommon::valueName(val);
    }
    
};

} // namespace field

} // namespace mqtt311


