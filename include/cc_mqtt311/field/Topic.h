// Generated by commsdsl2comms v7.0.2

/// @file
/// @brief Contains definition of <b>"Topic"</b> field.

#pragma once

#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/String.h"
#include "cc_mqtt311/field/TopicCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace field
{

/// @brief Definition of <b>"Topic"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = cc_mqtt311::options::DefaultOptions, typename... TExtraOpts>
class Topic : public
    cc_mqtt311::field::String<
        TOpt,
        TExtraOpts...,
        typename TOpt::field::Topic,
        comms::option::def::HasName
    >
{
    using Base =
        cc_mqtt311::field::String<
            TOpt,
            TExtraOpts...,
            typename TOpt::field::Topic,
            comms::option::def::HasName
        >;
public:
    /// @brief Name of the field.
    static const char* name()
    {
        return cc_mqtt311::field::TopicCommon::name();
    }
};

} // namespace field

} // namespace cc_mqtt311
