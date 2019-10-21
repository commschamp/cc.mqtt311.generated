/// @file
/// @brief Contains definition of <b>"Frame"</b> frame class.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/field/Bitfield.h"
#include "comms/field/IntValue.h"
#include "comms/options.h"
#include "comms/protocol/MsgDataLayer.h"
#include "comms/protocol/MsgSizeLayer.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/MsgId.h"
#include "mqtt311/frame/layer/IdAndFlags.h"
#include "mqtt311/input/AllMessages.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace frame
{

/// @brief Layers definition of @ref Frame frame class.
/// @tparam TOpt Protocol options.
/// @see @ref Frame
/// @headerfile "mqtt311/frame/Frame.h"
template <typename TOpt = mqtt311::options::DefaultOptions>
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
        struct Size : public
            comms::field::IntValue<
                mqtt311::field::FieldBase<comms::option::def::LittleEndian>,
                std::uint32_t,
                comms::option::def::VarLength<1U, 4U>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return "Size";
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
        /// @brief Scope for all the member fields of @ref IdAndFlagsField bitfield.
        struct IdAndFlagsFieldMembers
        {
            /// @brief Definition of <b>"Flags"</b> field.
            struct Flags : public
                comms::field::IntValue<
                    mqtt311::field::FieldBase<>,
                    std::uint8_t,
                    comms::option::def::FixedBitLength<4U>
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return "Flags";
                }
                
            };
            
            /// @brief Definition of <b>"Id"</b> field.
            struct Id : public
                mqtt311::field::MsgId<
                    TOpt,
                    comms::option::def::FixedBitLength<4U>
                >
            {
                /// @brief Name of the field.
                static const char* name()
                {
                    return "Id";
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
                mqtt311::field::FieldBase<>,
                typename IdAndFlagsFieldMembers::All
            >
        {
            using Base = 
                comms::field::Bitfield<
                    mqtt311::field::FieldBase<>,
                    typename IdAndFlagsFieldMembers::All
                >;
        public:
            /// @brief Allow access to internal fields.
            /// @details See definition of @b COMMS_FIELD_MEMBERS_ACCESS macro
            ///     related to @b comms::field::Bitfield class from COMMS library
            ///     for details.
            ///
            ///     The generated access functions are:
            ///     @li @b field_flags() - for IdAndFlagsFieldMembers::Flags member field.
            ///     @li @b field_id() - for IdAndFlagsFieldMembers::Id member field.
            COMMS_FIELD_MEMBERS_ACCESS(
                flags,
                id
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return "ID + Flags";
            }
            
        };
        
    };
    
    /// @brief Definition of layer "IdAndFlags".
    template <typename TMessage, typename TAllMessages>
    using IdAndFlags =
        mqtt311::frame::layer::IdAndFlags<
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
/// @headerfile "mqtt311/frame/Frame.h"
template <
   typename TMessage,
   typename TAllMessages = mqtt311::input::AllMessages<TMessage>,
   typename TOpt = mqtt311::options::DefaultOptions
>
class Frame : public
    FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>
{
    using Base =
        typename FrameLayers<TOpt>::template Stack<TMessage, TAllMessages>;
public:
    /// @brief Allow access to frame definition layers.
    /// @details See definition of @b COMMS_PROTOCOL_LAYERS_ACCESS macro
    ///     from COMMS library for details.
    ///
    ///     The generated functions are:
    ///     @li layer_data() for @ref FrameLayers::Data layer.
    ///     @li layer_size() for @ref FrameLayers::Size layer.
    ///     @li layer_idAndFlags() for @ref FrameLayers::IdAndFlags layer.
    COMMS_PROTOCOL_LAYERS_ACCESS(
        data,
        size,
        idAndFlags
    );
};

} // namespace frame

} // namespace mqtt311


