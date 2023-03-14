// Generated by commsdsl2comms v6.0.0

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::field::Topic field.

#pragma once

#include "cc_mqtt311/field/StringCommon.h"

namespace cc_mqtt311
{

namespace field
{

/// @brief Common types and functions for
///     @ref cc_mqtt311::field::Topic field.
struct TopicCommon : public cc_mqtt311::field::StringCommon
{
    /// @brief Name of the @ref cc_mqtt311::field::Topic field.
    static const char* name()
    {
        return "Topic";
    }
};

} // namespace field

} // namespace cc_mqtt311
