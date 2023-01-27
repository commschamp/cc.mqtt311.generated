// Generated by commsdsl2comms v5.2.0

/// @file
/// @brief Contains definition of <b>"Qos"</b> field.

#pragma once

#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/QosCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/field/EnumValue.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace field
{

/// @brief Definition of <b>"Qos"</b> field.
/// @see @ref cc_mqtt311::field::QosCommon::ValueType
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = cc_mqtt311::options::DefaultOptions, typename... TExtraOpts>
class Qos : public
    comms::field::EnumValue<
        cc_mqtt311::field::FieldBase<>,
        cc_mqtt311::field::QosCommon::ValueType,
        TExtraOpts...,
        comms::option::def::ValidNumValueRange<0, 2>
    >
{
    using Base =
        comms::field::EnumValue<
            cc_mqtt311::field::FieldBase<>,
            cc_mqtt311::field::QosCommon::ValueType,
            TExtraOpts...,
            comms::option::def::ValidNumValueRange<0, 2>
        >;
public:
    /// @brief Re-definition of the value type.
    using ValueType = typename Base::ValueType;

    /// @brief Single value name info entry.
    using ValueNameInfo = cc_mqtt311::field::QosCommon::ValueNameInfo;

    /// @brief Type returned from @ref valueNamesMap() member function.
    /// @see @ref cc_mqtt311::field::QosCommon::ValueNamesMapInfo.
    using ValueNamesMapInfo = cc_mqtt311::field::QosCommon::ValueNamesMapInfo;

    /// @brief Retrieve name of the enum value.
    /// @see @ref cc_mqtt311::field::QosCommon::valueName().
    static const char* valueName(ValueType val)
    {
        return cc_mqtt311::field::QosCommon::valueName(val);
    }

    /// @brief Retrieve name of the enum value.
    /// @see @ref cc_mqtt311::field::QosCommon::valueName().
    static const char* valueNameOf(ValueType val)
    {
        return cc_mqtt311::field::QosCommon::valueName(val);
    }

    /// @brief Retrieve name of the @b current value
    const char* valueName() const
    {
        return valueName(Base::getValue());
    }

    /// @brief Retrieve map of enum value names.
    /// @see @ref cc_mqtt311::field::QosCommon::valueNamesMap().
    static ValueNamesMapInfo valueNamesMap()
    {
        return cc_mqtt311::field::QosCommon::valueNamesMap();
    }

    /// @brief Name of the field.
    static const char* name()
    {
        return cc_mqtt311::field::QosCommon::name();
    }
};

} // namespace field

} // namespace cc_mqtt311
