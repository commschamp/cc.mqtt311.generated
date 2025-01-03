// Generated by commsdsl2comms v7.0.0

/// @file
/// @brief Contains definition of <b>"BinData"</b> field.

#pragma once

#include <cstdint>
#include "cc_mqtt311/field/BinDataCommon.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/Length.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/field/ArrayList.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace field
{

/// @brief Definition of <b>"BinData"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = cc_mqtt311::options::DefaultOptions, typename... TExtraOpts>
class BinData : public
    comms::field::ArrayList<
        cc_mqtt311::field::FieldBase<>,
        std::uint8_t,
        TExtraOpts...,
        typename TOpt::field::BinData,
        comms::option::def::HasName,
        comms::option::def::SequenceSerLengthFieldPrefix<cc_mqtt311::field::Length<TOpt> >
    >
{
    using Base =
        comms::field::ArrayList<
            cc_mqtt311::field::FieldBase<>,
            std::uint8_t,
            TExtraOpts...,
            typename TOpt::field::BinData,
            comms::option::def::HasName,
            comms::option::def::SequenceSerLengthFieldPrefix<cc_mqtt311::field::Length<TOpt> >
        >;
public:
    /// @brief Name of the field.
    static const char* name()
    {
        return cc_mqtt311::field::BinDataCommon::name();
    }
};

} // namespace field

} // namespace cc_mqtt311
