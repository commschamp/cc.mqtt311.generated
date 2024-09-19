// Generated by commsdsl2comms v6.3.4

/// @file
/// @brief Contains definition of <b>"Frame"</b> frame class.

#pragma once

#include <cstdint>
#include <tuple>
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/MsgId.h"
#include "cc_mqtt311/frame/FrameCommon.h"
#include "cc_mqtt311/frame/layer/IdAndFlags.h"
#include "cc_mqtt311/input/AllMessages.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/field/Bitfield.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "comms/protocol/MsgDataLayer.h"
#include "comms/protocol/MsgSizeLayer.h"

namespace cc_mqtt311
{

namespace frame
{

/// @brief Layers definition of @ref Frame frame class.
/// @tparam TOpt Protocol options.
/// @see @ref Frame
/// @headerfile cc_mqtt311/frame/Frame.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct FrameLayers
{
    /// @brief Definition of layer "Data".
    using Data =
        comms::protocol::MsgDataLayer<
            typename TOpt::frame::FrameLayers::Data
        >;

    /// @brief Scope for field(s) of @ref Size layer.
    struct SizeMembers
    {
        /// @brief Definition of <b>"Size"</b> field.
        class Size : public
            comms::field::IntValue<
                cc_mqtt311::field::FieldBase<comms::option::def::LittleEndian>,
                std::uint32_t,
                comms::option::def::VarLength<1U, 4U>
            >
        {
            using Base =
                comms::field::IntValue<
                    cc_mqtt311::field::FieldBase<comms::option::def::LittleEndian>,
                    std::uint32_t,
                    comms::option::def::VarLength<1U, 4U>
                >;
        public:
            /// @brief Re-definition of the value type.
            using ValueType = typename Base::ValueType;

            /// @brief Compile time detection of special values presence.
            static constexpr bool hasSpecials()
            {
                return cc_mqtt311::frame::FrameLayersCommon::SizeMembersCommon::SizeCommon::hasSpecials();
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::frame::FrameLayersCommon::SizeMembersCommon::SizeCommon::name();
            }
        };
    };

    /// @brief Definition of layer "Size".
    using Size =
        comms::protocol::MsgSizeLayer<
            typename SizeMembers::Size,
            Data
        >;

    /// @brief Scope for field(s) of @ref IdAndFlags layer.
    struct IdAndFlagsMembers
    {
        /// @brief Scope for all the member fields of
        ///     @ref IdAndFlagsField field.
        struct IdAndFlagsFieldMembers
        {
            /// @brief Definition of <b>"Flags"</b> field.
            class Flags : public
                comms::field::IntValue<
                    cc_mqtt311::field::FieldBase<>,
                    std::uint8_t,
                    comms::option::def::FixedBitLength<4U>
                >
            {
                using Base =
                    comms::field::IntValue<
                        cc_mqtt311::field::FieldBase<>,
                        std::uint8_t,
                        comms::option::def::FixedBitLength<4U>
                    >;
            public:
                /// @brief Re-definition of the value type.
                using ValueType = typename Base::ValueType;

                /// @brief Compile time detection of special values presence.
                static constexpr bool hasSpecials()
                {
                    return cc_mqtt311::frame::FrameLayersCommon::IdAndFlagsMembersCommon::IdAndFlagsFieldMembersCommon::FlagsCommon::hasSpecials();
                }

                /// @brief Name of the field.
                static const char* name()
                {
                    return cc_mqtt311::frame::FrameLayersCommon::IdAndFlagsMembersCommon::IdAndFlagsFieldMembersCommon::FlagsCommon::name();
                }
            };

            /// @brief Definition of <b>"Id"</b> field.
            class Id : public
                cc_mqtt311::field::MsgId<
                    TOpt,
                    comms::option::def::FixedBitLength<4U>
                >
            {
                using Base =
                    cc_mqtt311::field::MsgId<
                        TOpt,
                        comms::option::def::FixedBitLength<4U>
                    >;
            public:
                /// @brief Name of the field.
                static const char* name()
                {
                    return cc_mqtt311::frame::FrameLayersCommon::IdAndFlagsMembersCommon::IdAndFlagsFieldMembersCommon::IdCommon::name();
                }
            };

            /// @brief All members bundled in @b std::tuple.
            using All =
                std::tuple<
                   Flags,
                   Id
                >;
        };

        /// @brief Definition of <b>"ID + Flags"</b> field.
        class IdAndFlagsField : public
            comms::field::Bitfield<
                cc_mqtt311::field::FieldBase<>,
                typename IdAndFlagsFieldMembers::All,
                comms::option::def::HasVersionDependentMembers<false>
            >
        {
            using Base =
                comms::field::Bitfield<
                    cc_mqtt311::field::FieldBase<>,
                    typename IdAndFlagsFieldMembers::All,
                    comms::option::def::HasVersionDependentMembers<false>
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
            ///     related to @b comms::field::Bitfield class from COMMS library
            ///     for details.
            ///
            ///     The generated values, types and access functions are:
            ///     @li @b FieldIdx_flags index, @b Field_flags type and @b field_flags() access function -
            ///         for cc_mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlagsFieldMembers::Flags member field.
            ///     @li @b FieldIdx_id index, @b Field_id type and @b field_id() access function -
            ///         for cc_mqtt311::frame::FrameLayers::IdAndFlagsMembers::IdAndFlagsFieldMembers::Id member field.
            COMMS_FIELD_MEMBERS_NAMES(
                flags,
                id
            );

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::frame::FrameLayersCommon::IdAndFlagsMembersCommon::IdAndFlagsFieldCommon::name();
            }
        };
    };

    /// @brief Definition of layer "IdAndFlags".
    template <typename TMessage, typename TAllMessages>
    using IdAndFlags =
        cc_mqtt311::frame::layer::IdAndFlags<
            typename IdAndFlagsMembers::IdAndFlagsField,
            TMessage,
            TAllMessages,
            Size,
            typename TOpt::frame::FrameLayers::IdAndFlags
        >;

    /// @brief Final protocol stack definition.
    template<typename TMessage, typename TAllMessages>
    using Stack = IdAndFlags<TMessage, TAllMessages>;
};

/// @brief Definition of <b>"Frame"</b> frame class.
/// @tparam TMessage Common interface class of all the messages
/// @tparam TAllMessages All supported input messages.
/// @tparam TOpt Frame definition options
/// @headerfile cc_mqtt311/frame/Frame.h
template <
   typename TMessage,
   typename TAllMessages = cc_mqtt311::input::AllMessages<TMessage>,
   typename TOpt = cc_mqtt311::options::DefaultOptions
>
class Frame : public
    FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>
{
    using Base = typename
        FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>;
public:
    /// @brief Allow access to frame definition layers.
    /// @details See definition of @b COMMS_PROTOCOL_LAYERS_NAMES macro
    ///     from COMMS library for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Layer_data type and @b layer_data() function
    ///         for @ref FrameLayers::Data layer.
    ///     @li @b Layer_size type and @b layer_size() function
    ///         for @ref FrameLayers::Size layer.
    ///     @li @b Layer_idAndFlags type and @b layer_idAndFlags() function
    ///         for @ref FrameLayers::IdAndFlags layer.
    COMMS_PROTOCOL_LAYERS_NAMES(
        data,
        size,
        idAndFlags
    );
};

} // namespace frame

} // namespace cc_mqtt311
