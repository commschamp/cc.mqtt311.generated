/// @file
/// @brief Contains definition of <b>"Topic"</b> field.

#pragma once

#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/String.h"

namespace mqtt311
{

namespace field
{

/// @brief Definition of <b>"Topic"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::DefaultOptions, typename... TExtraOpts>
struct Topic : public
    mqtt311::field::String<
       TOpt,
       TExtraOpts...
   >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return "Topic";
    }
    
};

} // namespace field

} // namespace mqtt311


