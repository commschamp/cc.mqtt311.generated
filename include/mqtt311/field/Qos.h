/// @file
/// @brief Contains definition of <b>"Qos"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/field/FieldBase.h"

namespace mqtt311
{

namespace field
{

/// @brief Values enumerator for @ref mqtt311::field::Qos field.
enum class QosVal : std::uint8_t
{
    AtMostOnceDelivery = 0, ///< value @b AtMostOnceDelivery
    AtLeastOnceDelivery = 1, ///< value @b AtLeastOnceDelivery
    ExactlyOnceDelivery = 2, ///< value @b ExactlyOnceDelivery
    
};

/// @brief Definition of <b>"Qos"</b> field.
/// @see @ref mqtt311::field::QosVal
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::DefaultOptions, typename... TExtraOpts>
struct Qos : public
    comms::field::EnumValue<
        mqtt311::field::FieldBase<>,
        QosVal,
        TExtraOpts...,
        comms::option::ValidNumValueRange<0, 2>
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return "Qos";
    }
    
};

} // namespace field

} // namespace mqtt311


