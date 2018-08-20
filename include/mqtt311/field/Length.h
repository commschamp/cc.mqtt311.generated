/// @file
/// @brief Contains definition of <b>"Length"<\b> field.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/field/FieldBase.h"

namespace mqtt311
{

namespace field
{

/// @brief Definition of <b>"Length"<\b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::DefaultOptions, typename... TExtraOpts>
struct Length : public
    comms::field::IntValue<
        mqtt311::field::FieldBase<>,
        std::uint16_t,
        typename TOpt::field::Length,
        TExtraOpts...
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return "Length";
    }
    
};

} // namespace field

} // namespace mqtt311


