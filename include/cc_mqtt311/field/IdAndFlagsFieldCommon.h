// Generated by commsdsl2comms v7.0.3

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::field::IdAndFlagsField field.

#pragma once

#include <cstdint>
#include "cc_mqtt311/field/MsgIdCommon.h"

namespace cc_mqtt311
{

namespace field
{

/// @brief Scope for all the common definitions of the member fields of
///     @ref cc_mqtt311::field::IdAndFlagsField field.
struct IdAndFlagsFieldMembersCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::field::IdAndFlagsFieldMembers::Flags field.
    struct FlagsCommon
    {
        /// @brief Re-definition of the value type used by
        ///     cc_mqtt311::field::IdAndFlagsFieldMembers::Flags field.
        using ValueType = std::uint8_t;

        /// @brief Name of the @ref cc_mqtt311::field::IdAndFlagsFieldMembers::Flags field.
        static const char* name()
        {
            return "Flags";
        }

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return false;
        }
    };

    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::field::IdAndFlagsFieldMembers::Id field.
    struct IdCommon : public cc_mqtt311::field::MsgIdCommon
    {
        /// @brief Name of the @ref cc_mqtt311::field::IdAndFlagsFieldMembers::Id field.
        static const char* name()
        {
            return "Id";
        }
    };
};

/// @brief Common types and functions for
///     @ref cc_mqtt311::field::IdAndFlagsField field.
struct IdAndFlagsFieldCommon
{
    /// @brief Name of the @ref cc_mqtt311::field::IdAndFlagsField field.
    static const char* name()
    {
        return "ID + Flags";
    }
};

} // namespace field

} // namespace cc_mqtt311
