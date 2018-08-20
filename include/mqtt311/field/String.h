/// @file
/// @brief Contains definition of <b>"String"<\b> field.

#pragma once

#include "comms/field/String.h"
#include "comms/options.h"
#include "mqtt311/DefaultOptions.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/Length.h"

namespace mqtt311
{

namespace field
{

/// @brief Definition of <b>"String"<\b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::DefaultOptions, typename... TExtraOpts>
struct String : public
    comms::field::String<
        mqtt311::field::FieldBase<>,
        typename TOpt::field::String,
        TExtraOpts...,
        comms::option::SequenceSerLengthFieldPrefix<mqtt311::field::Length<TOpt> >
    >
{
    /// @brief Name of the field.
    static const char* name()
    {
        return "String";
    }
    
};

} // namespace field

} // namespace mqtt311


