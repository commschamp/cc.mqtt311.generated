// Generated by commsdsl2comms v3.5.1

/// @file
/// @brief Contains definition of <b>"CONNECT"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "comms/MessageBase.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/IntValue.h"
#include "comms/field/Optional.h"
#include "comms/options.h"
#include "mqtt311/MsgId.h"
#include "mqtt311/field/BinData.h"
#include "mqtt311/field/FieldBase.h"
#include "mqtt311/field/ProtocolName.h"
#include "mqtt311/field/Qos.h"
#include "mqtt311/field/String.h"
#include "mqtt311/message/ConnectCommon.h"
#include "mqtt311/options/DefaultOptions.h"

namespace mqtt311
{

namespace message
{

/// @brief Fields of @ref Connect.
/// @tparam TOpt Extra options
/// @see @ref Connect
/// @headerfile "mqtt311/message/Connect.h"
template <typename TOpt = mqtt311::options::DefaultOptions>
struct ConnectFields
{
    /// @brief Definition of <b>"Protocol Name"</b> field.
    using ProtocolName =
        mqtt311::field::ProtocolName<
            TOpt
        >;
    
    /// @brief Definition of <b>"Protocol Level"</b> field.
    struct ProtocolLevel : public
        comms::field::IntValue<
            mqtt311::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::DefaultNumValue<4>,
            comms::option::def::ValidNumValue<4>
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::ProtocolLevelCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref Flags bitfield.
    struct FlagsMembers
    {
        /// @brief Definition of <b>""</b> field.
        class Low : public
            comms::field::BitmaskValue<
                mqtt311::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>,
                comms::option::def::BitmaskReservedBits<0x1U, 0x0U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    mqtt311::field::FieldBase<>,
                    comms::option::def::FixedBitLength<3U>,
                    comms::option::def::BitmaskReservedBits<0x1U, 0x0U>
                >;
        public:
            /// @brief Provide names for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values:
            ///      @li @b BitIdx_cleanSession.
            ///      @li @b BitIdx_willFlag.
            COMMS_BITMASK_BITS(
                cleanSession=1,
                willFlag=2
            );
            
            /// @brief Generates independent access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_ACCESS macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///     The generated access functions are:
            ///      @li @b getBitValue_cleanSession() and @b setBitValue_cleanSession().
            ///      @li @b getBitValue_willFlag() and @b setBitValue_willFlag().
            COMMS_BITMASK_BITS_ACCESS(
                cleanSession,
                willFlag
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::LowCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::LowCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief Definition of <b>"Will QoS"</b> field.
        struct WillQos : public
            mqtt311::field::Qos<
                TOpt,
                comms::option::def::FixedBitLength<2U>
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::WillQosCommon::name();
            }
            
        };
        
        /// @brief Definition of <b>""</b> field.
        class High : public
            comms::field::BitmaskValue<
                mqtt311::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>
            >
        {
            using Base = 
                comms::field::BitmaskValue<
                    mqtt311::field::FieldBase<>,
                    comms::option::def::FixedBitLength<3U>
                >;
        public:
            /// @brief Provides names and generates access functions for internal bits.
            /// @details See definition of @b COMMS_BITMASK_BITS_SEQ macro
            ///     related to @b comms::field::BitmaskValue class from COMMS library
            ///     for details.
            ///
            ///      The generated enum values and functions are:
            ///      @li @b BitIdx_willRetain, @b getBitValue_willRetain() and @b setBitValue_willRetain().
            ///      @li @b BitIdx_passwordFlag, @b getBitValue_passwordFlag() and @b setBitValue_passwordFlag().
            ///      @li @b BitIdx_userNameFlag, @b getBitValue_userNameFlag() and @b setBitValue_userNameFlag().
            COMMS_BITMASK_BITS_SEQ(
                willRetain,
                passwordFlag,
                userNameFlag
            );
            
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::HighCommon::name();
            }
            
            /// @brief Retrieve name of the bit.
            static const char* bitName(BitIdx idx)
            {
                return
                    mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::HighCommon::bitName(
                        static_cast<std::size_t>(idx));
            }
            
        };
        
        /// @brief All members bundled in @b std::tuple.
        using All =
            std::tuple<
               Low,
               WillQos,
               High
            >;
    };
    
    /// @brief Definition of <b>"Connect Flags"</b> field.
    class Flags : public
        comms::field::Bitfield<
            mqtt311::field::FieldBase<>,
            typename FlagsMembers::All
        >
    {
        using Base = 
            comms::field::Bitfield<
                mqtt311::field::FieldBase<>,
                typename FlagsMembers::All
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
        ///     related to @b comms::field::Bitfield class from COMMS library
        ///     for details.
        ///
        ///     The generated types and access functions are:
        ///     @li @b Field_low type and @b field_low() access function -
        ///         for FlagsMembers::Low member field.
        ///     @li @b Field_willQos type and @b field_willQos() access function -
        ///         for FlagsMembers::WillQos member field.
        ///     @li @b Field_high type and @b field_high() access function -
        ///         for FlagsMembers::High member field.
        COMMS_FIELD_MEMBERS_NAMES(
            low,
            willQos,
            high
        );
        
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::FlagsCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"Keep Alive"</b> field.
    struct KeepAlive : public
        comms::field::IntValue<
            mqtt311::field::FieldBase<>,
            std::uint16_t
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::KeepAliveCommon::name();
        }
        
    };
    
    /// @brief Definition of <b>"Client ID"</b> field.
    struct ClientId : public
        mqtt311::field::String<
            TOpt
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::ClientIdCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref WillTopic optional.
    struct WillTopicMembers
    {
        /// @brief Definition of <b>"Will Topic"</b> field.
        struct WillTopic : public
            mqtt311::field::String<
                TOpt
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::WillTopicMembersCommon::WillTopicCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"Will Topic"</b> field.
    struct WillTopic : public
        comms::field::Optional<
            typename WillTopicMembers::WillTopic,
            comms::option::def::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::WillTopicCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref WillMessage optional.
    struct WillMessageMembers
    {
        /// @brief Definition of <b>"Will Message"</b> field.
        struct WillMessage : public
            mqtt311::field::BinData<
                TOpt
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::WillMessageMembersCommon::WillMessageCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"Will Message"</b> field.
    struct WillMessage : public
        comms::field::Optional<
            typename WillMessageMembers::WillMessage,
            comms::option::def::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::WillMessageCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref UserName optional.
    struct UserNameMembers
    {
        /// @brief Definition of <b>"User Name"</b> field.
        struct UserName : public
            mqtt311::field::String<
                TOpt
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::UserNameMembersCommon::UserNameCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"User Name"</b> field.
    struct UserName : public
        comms::field::Optional<
            typename UserNameMembers::UserName,
            comms::option::def::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::UserNameCommon::name();
        }
        
    };
    
    /// @brief Scope for all the member fields of
    ///     @ref Password optional.
    struct PasswordMembers
    {
        /// @brief Definition of <b>"Password"</b> field.
        struct Password : public
            mqtt311::field::BinData<
                TOpt
            >
        {
            /// @brief Name of the field.
            static const char* name()
            {
                return mqtt311::message::ConnectFieldsCommon::PasswordMembersCommon::PasswordCommon::name();
            }
            
        };
        
    };
    
    /// @brief Definition of <b>"Password"</b> field.
    struct Password : public
        comms::field::Optional<
            typename PasswordMembers::Password,
            comms::option::def::MissingByDefault
        >
    {
        /// @brief Name of the field.
        static const char* name()
        {
            return mqtt311::message::ConnectFieldsCommon::PasswordCommon::name();
        }
        
    };
    
    /// @brief All the fields bundled in std::tuple.
    using All = std::tuple<
        ProtocolName,
        ProtocolLevel,
        Flags,
        KeepAlive,
        ClientId,
        WillTopic,
        WillMessage,
        UserName,
        Password
    >;
};

/// @brief Definition of <b>"CONNECT"</b> message class.
/// @details
///     See @ref ConnectFields for definition of the fields this message contains.
/// @tparam TMsgBase Base (interface) class.
/// @tparam TOpt Extra options
/// @headerfile "mqtt311/message/Connect.h"
template <typename TMsgBase, typename TOpt = mqtt311::options::DefaultOptions>
class Connect : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Connect,
        comms::option::def::StaticNumIdImpl<mqtt311::MsgId_Connect>,
        comms::option::def::FieldsImpl<typename ConnectFields<TOpt>::All>,
        comms::option::def::MsgType<Connect<TMsgBase, TOpt> >,
        comms::option::def::HasName,
        comms::option::def::HasCustomRefresh
    >
{
    // Redefinition of the base class type
    using Base =
        comms::MessageBase<
            TMsgBase,
            typename TOpt::message::Connect,
            comms::option::def::StaticNumIdImpl<mqtt311::MsgId_Connect>,
            comms::option::def::FieldsImpl<typename ConnectFields<TOpt>::All>,
            comms::option::def::MsgType<Connect<TMsgBase, TOpt> >,
            comms::option::def::HasName,
            comms::option::def::HasCustomRefresh
        >;

public:
    /// @brief Provide names and allow access to internal fields.
    /// @details See definition of @b COMMS_MSG_FIELDS_NAMES macro
    ///     related to @b comms::MessageBase class from COMMS library
    ///     for details.
    ///
    ///     The generated types and functions are:
    ///     @li @b Field_protocolName type and @b field_protocolName() access fuction
    ///         for @ref ConnectFields::ProtocolName field.
    ///     @li @b Field_protocolLevel type and @b field_protocolLevel() access fuction
    ///         for @ref ConnectFields::ProtocolLevel field.
    ///     @li @b Field_flags type and @b field_flags() access fuction
    ///         for @ref ConnectFields::Flags field.
    ///     @li @b Field_keepAlive type and @b field_keepAlive() access fuction
    ///         for @ref ConnectFields::KeepAlive field.
    ///     @li @b Field_clientId type and @b field_clientId() access fuction
    ///         for @ref ConnectFields::ClientId field.
    ///     @li @b Field_willTopic type and @b field_willTopic() access fuction
    ///         for @ref ConnectFields::WillTopic field.
    ///     @li @b Field_willMessage type and @b field_willMessage() access fuction
    ///         for @ref ConnectFields::WillMessage field.
    ///     @li @b Field_userName type and @b field_userName() access fuction
    ///         for @ref ConnectFields::UserName field.
    ///     @li @b Field_password type and @b field_password() access fuction
    ///         for @ref ConnectFields::Password field.
    COMMS_MSG_FIELDS_NAMES(
        protocolName,
        protocolLevel,
        flags,
        keepAlive,
        clientId,
        willTopic,
        willMessage,
        userName,
        password
    );
    
    // Compile time check for serialisation length.
    static const std::size_t MsgMinLen = Base::doMinLength();
    static_assert(MsgMinLen == 8U, "Unexpected min serialisation length");
    
    /// @brief Name of the message.
    static const char* doName()
    {
        return mqtt311::message::ConnectCommon::name();
    }
    
    /// @brief Custom read functionality
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = Base::template doReadUntilAndUpdateLen<FieldIdx_clientId>(iter, len);
        if (es != comms::ErrorStatus::Success) {
            return es;
        }
        
        doRefresh();
        return Base::template doReadFrom<FieldIdx_clientId>(iter, len);
    }
    
    /// @brief Updated validity check
    bool doValid() const
    {
        if ((!Base::doValid()) || (!Base::flagsZeroed())) {
            return false;
        }
        
        return 
            (!field_flags().field_high().getBitValue_passwordFlag()) ||
            (field_flags().field_high().getBitValue_userNameFlag());
    }
    
    /// @brief Custom refresh functionality
    bool doRefresh()
    {
        bool updated = Base::doRefresh();
        updated = refresh_willTopic() || updated;
        updated = refresh_willMessage() || updated;
        updated = refresh_userName() || updated;
        updated = refresh_password() || updated;
        return updated;
    }
    
    
private:
    template <typename TOptField>
    static bool refreshOptionalField(bool exists, TOptField& optField)
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (exists) {
            mode = comms::field::OptionalMode::Exists;
        }
        
        if (optField.getMode() == mode) {
            return false;
        }
        
        optField.setMode(mode);
        return true;
    }
    
    bool refresh_willTopic()
    {
        return refreshOptionalField(field_flags().field_low().getBitValue_willFlag(), field_willTopic());
    }
    
    bool refresh_willMessage()
    {
        return refreshOptionalField(field_flags().field_low().getBitValue_willFlag(), field_willMessage());
    }
    
    bool refresh_userName()
    {
        return refreshOptionalField(field_flags().field_high().getBitValue_userNameFlag(), field_userName());
    }
    
    bool refresh_password()
    {
        return refreshOptionalField(field_flags().field_high().getBitValue_passwordFlag(), field_password());
    }
    
    
    
};

} // namespace message

} // namespace mqtt311


