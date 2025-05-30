// Generated by commsdsl2comms v7.1.0

/// @file
/// @brief Contains definition of <b>"Frame"</b> frame class.

#pragma once

#include <cstdint>
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/IdAndFlagsField.h"
#include "cc_mqtt311/frame/FrameCommon.h"
#include "cc_mqtt311/frame/layer/IdAndFlags.h"
#include "cc_mqtt311/input/AllMessages.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/field/IntValue.h"
#include "comms/frame/MsgDataLayer.h"
#include "comms/frame/MsgSizeLayer.h"
#include "comms/options.h"

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
    /// @brief Scope for field(s) of @ref Data layer.
    struct DataMembers
    {
        /// @brief Custom field for @ref cc_mqtt311::frame::FrameLayers::Data layer
        class Field : public
            comms::field::ArrayList<
                cc_mqtt311::field::FieldBase<>,
                std::uint8_t,
                typename TOpt::frame::FrameLayers::DataMembers::Field,
                comms::option::def::HasName
            >
        {
        public:
            static const char* name()
            {
                return "Data";
            }
        };
    };

    /// @brief Definition of layer "Data".
    using Data =
        comms::frame::MsgDataLayer<
            comms::option::def::FieldType<typename DataMembers::Field>
        >;

    /// @brief Scope for field(s) of @ref Size layer.
    struct SizeMembers
    {
        /// @brief Definition of <b>"Size"</b> field.
        class Size : public
            comms::field::IntValue<
                cc_mqtt311::field::FieldBase<comms::option::def::LittleEndian>,
                std::uint32_t,
                comms::option::def::HasName,
                comms::option::def::VarLength<1U, 4U>
            >
        {
            using Base =
                comms::field::IntValue<
                    cc_mqtt311::field::FieldBase<comms::option::def::LittleEndian>,
                    std::uint32_t,
                    comms::option::def::HasName,
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
        comms::frame::MsgSizeLayer<
            typename SizeMembers::Size,
            Data
        >;

    /// @brief Definition of layer "IdAndFlags".
    template <typename TMessage, typename TAllMessages>
    using IdAndFlags =
        cc_mqtt311::frame::layer::IdAndFlags<
            cc_mqtt311::field::IdAndFlagsField<
                TOpt
            >,
            TMessage,
            TAllMessages,
            Size,
            typename TOpt::frame::FrameLayers::IdAndFlags
        >;

    /// @brief Final framing layers stack definition.
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
    /// @details See definition of @b COMMS_FRAME_LAYERS_NAMES macro
    ///     from COMMS library for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Layer_data type and @b layer_data() function
    ///         for @ref FrameLayers::Data layer.
    ///     @li @b Layer_size type and @b layer_size() function
    ///         for @ref FrameLayers::Size layer.
    ///     @li @b Layer_idAndFlags type and @b layer_idAndFlags() function
    ///         for @ref FrameLayers::IdAndFlags layer.
    COMMS_FRAME_LAYERS_NAMES(
        data,
        size,
        idAndFlags
    );
};

} // namespace frame

} // namespace cc_mqtt311
