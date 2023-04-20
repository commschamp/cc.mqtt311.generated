// Generated by commsdsl2comms v6.1.0

/// @file
/// @brief Contains definition of <b>"Protocol Name"</b> field.

#pragma once

#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/Length.h"
#include "cc_mqtt311/field/ProtocolNameCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/field/String.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace field
{

/// @brief Definition of <b>"Protocol Name"</b> field.
/// @tparam TOpt Protocol options.
/// @tparam TExtraOpts Extra options.
template <typename TOpt = cc_mqtt311::options::DefaultOptions, typename... TExtraOpts>
class ProtocolName : public
    comms::field::String<
        cc_mqtt311::field::FieldBase<>,
        TExtraOpts...,
        typename TOpt::field::ProtocolName,
        comms::option::def::SequenceSerLengthFieldPrefix<cc_mqtt311::field::Length<TOpt> >
    >
{
    using Base =
        comms::field::String<
            cc_mqtt311::field::FieldBase<>,
            TExtraOpts...,
            typename TOpt::field::ProtocolName,
            comms::option::def::SequenceSerLengthFieldPrefix<cc_mqtt311::field::Length<TOpt> >
        >;
public:
    /// @brief Default constructor.
    ProtocolName()
    {
        static const char Str[] = "MQTT";
        static const std::size_t StrSize = std::extent<decltype(Str)>::value;
        Base::setValue(typename Base::ValueType(&Str[0], StrSize - 1));
    }

    /// @brief Name of the field.
    static const char* name()
    {
        return cc_mqtt311::field::ProtocolNameCommon::name();
    }

    /// @brief Custom validity check
    bool valid() const
    {
        return Base::value() == ProtocolName().value();
    }
};

} // namespace field

} // namespace cc_mqtt311
