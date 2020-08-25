// Generated by commsdsl2comms v3.5.1

/// @file
/// @brief Contains definition of <b>"Qos"</b> field.

#pragma once

#include <cstdint>
#include <type_traits>
#include "comms/field/EnumValue.h"
#include "comms/options.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/QosCommon.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace field
{

/// @brief Definition of <b>"Qos"</b> field.
/// @see @ref mqtt311::field::QosVal
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::options::DefaultOptions, typename... TExtraOpts>
class Qos : public
    comms::field::EnumValue<
        mqtt311::field::FieldBase<>,
        mqtt311::field::QosVal,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<0, 2>
    >
{
    using Base = 
        comms::field::EnumValue<
            mqtt311::field::FieldBase<>,
            mqtt311::field::QosVal,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<0, 2>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Name of the field.
    static const char* name()
    {
        return mqtt311::field::QosCommon::name();
    }
    
    /// @brief Retrieve name of the enum value
    static const char* valueName(ValueType val)
    {
        return mqtt311::field::QosCommon::valueName(val);
    }
    
    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::value());
    }
    
};

} // namespace field

} // namespace mqtt311


