// Generated by commsdsl2comms v6.3.3

/// @file
/// @brief Contains common template parameters independent functionality of
///    @ref cc_mqtt311::message::Suback message and its fields.

#pragma once

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <utility>
#include "cc_mqtt311/field/PacketIdCommon.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Common types and functions for fields of 
///     @ref cc_mqtt311::message::Suback message.
/// @see cc_mqtt311::message::SubackFields
struct SubackFieldsCommon
{
    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::SubackFields::PacketId field.
    using PacketIdCommon = cc_mqtt311::field::PacketIdCommon;

    /// @brief Scope for all the common definitions of the member fields of
    ///     @ref cc_mqtt311::message::SubackFields::List field.
    struct ListMembersCommon
    {
        /// @brief Common types and functions for
        ///     @ref cc_mqtt311::message::SubackFields::ListMembers::ReturnCode field.
        struct ReturnCodeCommon
        {
            /// @brief Values enumerator for
            ///     @ref cc_mqtt311::message::SubackFields::ListMembers::ReturnCode field.
            enum class ValueType : std::uint8_t
            {
                Qos0 = 0, ///< value <b>Max QoS 0</b>. 
                Qos1 = 1, ///< value <b>Max QoS 1</b>. 
                Qos2 = 2, ///< value <b>Max QoS 2</b>. 
                Failure = 128, ///< value @b Failure. 

                // --- Extra values generated for convenience ---
                FirstValue = 0, ///< First defined value.
                LastValue = 128, ///< Last defined value.
                ValuesLimit = 129, ///< Upper limit for defined values.
            };

            /// @brief Single value name info entry
            using ValueNameInfo = std::pair<ValueType, const char*>;

            /// @brief Type returned from @ref valueNamesMap() member function.
            /// @details The @b first value of the pair is pointer to the map array,
            ///     The @b second value of the pair is the size of the array.
            using ValueNamesMapInfo = std::pair<const ValueNameInfo*, std::size_t>;

            /// @brief Name of the @ref cc_mqtt311::message::SubackFields::ListMembers::ReturnCode field.
            static const char* name()
            {
                return "Return Code";
            }

            /// @brief Retrieve name of the enum value
            static const char* valueName(ValueType val)
            {
                auto namesMapInfo = valueNamesMap();
                auto begIter = namesMapInfo.first;
                auto endIter = begIter + namesMapInfo.second;
                auto iter = std::lower_bound(
                    begIter, endIter, val,
                    [](const ValueNameInfo& info, ValueType v) -> bool
                    {
                        return info.first < v;
                    });

                if ((iter == endIter) || (iter->first != val)) {
                    return nullptr;
                }

                return iter->second;
            }

            /// @brief Retrieve map of enum value names
            static ValueNamesMapInfo valueNamesMap()
            {
                static const ValueNameInfo Map[] = {
                    std::make_pair(ValueType::Qos0, "Max QoS 0"),
                    std::make_pair(ValueType::Qos1, "Max QoS 1"),
                    std::make_pair(ValueType::Qos2, "Max QoS 2"),
                    std::make_pair(ValueType::Failure, "Failure")
                };
                static const std::size_t MapSize = std::extent<decltype(Map)>::value;

                return std::make_pair(&Map[0], MapSize);
            }
        };

        /// @brief Values enumerator for
        ///     @ref cc_mqtt311::message::SubackFields::ListMembers::ReturnCode field.
        using ReturnCodeVal = ReturnCodeCommon::ValueType;
    };

    /// @brief Common types and functions for
    ///     @ref cc_mqtt311::message::SubackFields::List field.
    struct ListCommon
    {
        /// @brief Name of the @ref cc_mqtt311::message::SubackFields::List field.
        static const char* name()
        {
            return "List";
        }
    };
};

/// @brief Common types and functions of 
///     @ref cc_mqtt311::message::Suback message.
struct SubackCommon
{
    /// @brief Name of the @ref cc_mqtt311::message::Suback message.
    static const char* name()
    {
        return "SUBACK";
    }
};

} // namespace message

} // namespace cc_mqtt311
