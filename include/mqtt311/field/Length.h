// Generated by commsdsl2comms v4.0.0

/// @file
/// @brief Contains definition of <b>"Length"</b> field.

#pragma once

#include <cstdint>
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/LengthCommon.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace field
{


/// @brief Definition of <b>"Length"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = mqtt311::options::DefaultOptions, typename... TExtraOpts>
class Length : public
    comms::field::IntValue<
        mqtt311::field::FieldBase<>,
        std::uint16_t,
        TExtraOpts...
    >
{
    using Base =
        comms::field::IntValue<
            mqtt311::field::FieldBase<>,
            std::uint16_t,
            TExtraOpts...
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;
    
    /// @brief Compile time detection of special values presence.
    static constexpr bool hasSpecials()
    {
        return mqtt311::field::LengthCommon::hasSpecials();
    }
    
    
    /// @brief Name of the field.
    static const char* name()
    {
        return mqtt311::field::LengthCommon::name();
    }
    

};


} // namespace field

} // namespace mqtt311

