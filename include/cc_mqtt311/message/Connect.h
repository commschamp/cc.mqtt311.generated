// Generated by commsdsl2comms v5.2.0

/// @file
/// @brief Contains definition of <b>"CONNECT"</b> message and its fields.

#pragma once

#include <cstdint>
#include <tuple>
#include "cc_mqtt311/MsgId.h"
#include "cc_mqtt311/field/BinData.h"
#include "cc_mqtt311/field/FieldBase.h"
#include "cc_mqtt311/field/ProtocolName.h"
#include "cc_mqtt311/field/Qos.h"
#include "cc_mqtt311/field/String.h"
#include "cc_mqtt311/message/ConnectCommon.h"
#include "cc_mqtt311/options/DefaultOptions.h"
#include "comms/MessageBase.h"
#include "comms/field/Bitfield.h"
#include "comms/field/BitmaskValue.h"
#include "comms/field/IntValue.h"
#include "comms/field/Optional.h"
#include "comms/options.h"

namespace cc_mqtt311
{

namespace message
{

/// @brief Fields of @ref Connect.
/// @tparam TOpt Extra options
/// @see @ref Connect
/// @headerfile cc_mqtt311/message/Connect.h
template <typename TOpt = cc_mqtt311::options::DefaultOptions>
struct ConnectFields
{
    /// @brief Definition of <b>"Protocol Name"</b> field.
    using ProtocolName =
        cc_mqtt311::field::ProtocolName<
            TOpt
        >;

    /// @brief Definition of <b>"Protocol Level"</b> field.
    class ProtocolLevel : public
        comms::field::IntValue<
            cc_mqtt311::field::FieldBase<>,
            std::uint8_t,
            comms::option::def::DefaultNumValue<4>,
            comms::option::def::ValidNumValue<4>
        >
    {
        using Base =
            comms::field::IntValue<
                cc_mqtt311::field::FieldBase<>,
                std::uint8_t,
                comms::option::def::DefaultNumValue<4>,
                comms::option::def::ValidNumValue<4>
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::ProtocolLevelCommon::hasSpecials();
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::ProtocolLevelCommon::name();
        }
    };

    /// @brief Scope for all the member fields of
    ///     @ref Flags field.
    struct FlagsMembers
    {
        /// @brief Definition of <b>""</b> field.
        class Low : public
            comms::field::BitmaskValue<
                cc_mqtt311::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>,
                comms::option::def::BitmaskReservedBits<0x1U, 0x0U>
            >
        {
            using Base =
                comms::field::BitmaskValue<
                    cc_mqtt311::field::FieldBase<>,
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

            /// @brief Retrieve name of the bit.
            /// @see @ref cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::LowCommon::bitName().
            static const char* bitName(BitIdx idx)
            {
                return
                    cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::LowCommon::bitName(
                        static_cast<std::size_t>(idx));
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::LowCommon::name();
            }
        };

        /// @brief Definition of <b>"Will QoS"</b> field.
        class WillQos : public
            cc_mqtt311::field::Qos<
                TOpt,
                comms::option::def::FixedBitLength<2U>
            >
        {
            using Base =
                cc_mqtt311::field::Qos<
                    TOpt,
                    comms::option::def::FixedBitLength<2U>
                >;
        public:
            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::WillQosCommon::name();
            }
        };

        /// @brief Definition of <b>""</b> field.
        class High : public
            comms::field::BitmaskValue<
                cc_mqtt311::field::FieldBase<>,
                comms::option::def::FixedBitLength<3U>
            >
        {
            using Base =
                comms::field::BitmaskValue<
                    cc_mqtt311::field::FieldBase<>,
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

            /// @brief Retrieve name of the bit.
            /// @see @ref cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::HighCommon::bitName().
            static const char* bitName(BitIdx idx)
            {
                return
                    cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::HighCommon::bitName(
                        static_cast<std::size_t>(idx));
            }

            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::FlagsMembersCommon::HighCommon::name();
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
            cc_mqtt311::field::FieldBase<>,
            typename FlagsMembers::All
        >
    {
        using Base =
            comms::field::Bitfield<
                cc_mqtt311::field::FieldBase<>,
                typename FlagsMembers::All
            >;
    public:
        /// @brief Allow access to internal fields.
        /// @details See definition of @b COMMS_FIELD_MEMBERS_NAMES macro
        ///     related to @b comms::field::Bitfield class from COMMS library
        ///     for details.
        ///
        ///     The generated values, types and access functions are:
        ///     @li @b FieldIdx_low index, @b Field_low type and @b field_low() access function -
        ///         for cc_mqtt311::message::ConnectFields::FlagsMembers::Low member field.
        ///     @li @b FieldIdx_willQos index, @b Field_willQos type and @b field_willQos() access function -
        ///         for cc_mqtt311::message::ConnectFields::FlagsMembers::WillQos member field.
        ///     @li @b FieldIdx_high index, @b Field_high type and @b field_high() access function -
        ///         for cc_mqtt311::message::ConnectFields::FlagsMembers::High member field.
        COMMS_FIELD_MEMBERS_NAMES(
            low,
            willQos,
            high
        );

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::FlagsCommon::name();
        }
    };

    /// @brief Definition of <b>"Keep Alive"</b> field.
    class KeepAlive : public
        comms::field::IntValue<
            cc_mqtt311::field::FieldBase<>,
            std::uint16_t
        >
    {
        using Base =
            comms::field::IntValue<
                cc_mqtt311::field::FieldBase<>,
                std::uint16_t
            >;
    public:
        /// @brief Re-definition of the value type.
        using ValueType = typename Base::ValueType;

        /// @brief Compile time detection of special values presence.
        static constexpr bool hasSpecials()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::KeepAliveCommon::hasSpecials();
        }

        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::KeepAliveCommon::name();
        }
    };

    /// @brief Definition of <b>"Client ID"</b> field.
    class ClientId : public
        cc_mqtt311::field::String<
            TOpt
        >
    {
        using Base =
            cc_mqtt311::field::String<
                TOpt
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::ClientIdCommon::name();
        }
    };

    /// @brief Scope for all the member fields of
    ///     @ref WillTopic field.
    struct WillTopicMembers
    {
        /// @brief Definition of <b>"Will Topic"</b> field.
        class WillTopic : public
            cc_mqtt311::field::String<
                TOpt
            >
        {
            using Base =
                cc_mqtt311::field::String<
                    TOpt
                >;
        public:
            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::WillTopicMembersCommon::WillTopicCommon::name();
            }
        };
    };

    /// @brief Definition of <b>"Will Topic"</b> field.
    class WillTopic : public
        comms::field::Optional<
            typename WillTopicMembers::WillTopic,
            comms::option::def::MissingByDefault
        >
    {
        using Base =
            comms::field::Optional<
                typename WillTopicMembers::WillTopic,
                comms::option::def::MissingByDefault
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::WillTopicCommon::name();
        }
    };

    /// @brief Scope for all the member fields of
    ///     @ref WillMessage field.
    struct WillMessageMembers
    {
        /// @brief Definition of <b>"Will Message"</b> field.
        class WillMessage : public
            cc_mqtt311::field::BinData<
                TOpt
            >
        {
            using Base =
                cc_mqtt311::field::BinData<
                    TOpt
                >;
        public:
            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::WillMessageMembersCommon::WillMessageCommon::name();
            }
        };
    };

    /// @brief Definition of <b>"Will Message"</b> field.
    class WillMessage : public
        comms::field::Optional<
            typename WillMessageMembers::WillMessage,
            comms::option::def::MissingByDefault
        >
    {
        using Base =
            comms::field::Optional<
                typename WillMessageMembers::WillMessage,
                comms::option::def::MissingByDefault
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::WillMessageCommon::name();
        }
    };

    /// @brief Scope for all the member fields of
    ///     @ref UserName field.
    struct UserNameMembers
    {
        /// @brief Definition of <b>"User Name"</b> field.
        class UserName : public
            cc_mqtt311::field::String<
                TOpt
            >
        {
            using Base =
                cc_mqtt311::field::String<
                    TOpt
                >;
        public:
            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::UserNameMembersCommon::UserNameCommon::name();
            }
        };
    };

    /// @brief Definition of <b>"User Name"</b> field.
    class UserName : public
        comms::field::Optional<
            typename UserNameMembers::UserName,
            comms::option::def::MissingByDefault
        >
    {
        using Base =
            comms::field::Optional<
                typename UserNameMembers::UserName,
                comms::option::def::MissingByDefault
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::UserNameCommon::name();
        }
    };

    /// @brief Scope for all the member fields of
    ///     @ref Password field.
    struct PasswordMembers
    {
        /// @brief Definition of <b>"Password"</b> field.
        class Password : public
            cc_mqtt311::field::BinData<
                TOpt
            >
        {
            using Base =
                cc_mqtt311::field::BinData<
                    TOpt
                >;
        public:
            /// @brief Name of the field.
            static const char* name()
            {
                return cc_mqtt311::message::ConnectFieldsCommon::PasswordMembersCommon::PasswordCommon::name();
            }
        };
    };

    /// @brief Definition of <b>"Password"</b> field.
    class Password : public
        comms::field::Optional<
            typename PasswordMembers::Password,
            comms::option::def::MissingByDefault
        >
    {
        using Base =
            comms::field::Optional<
                typename PasswordMembers::Password,
                comms::option::def::MissingByDefault
            >;
    public:
        /// @brief Name of the field.
        static const char* name()
        {
            return cc_mqtt311::message::ConnectFieldsCommon::PasswordCommon::name();
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
/// @headerfile cc_mqtt311/message/Connect.h
template <typename TMsgBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
class Connect : public
    comms::MessageBase<
        TMsgBase,
        typename TOpt::message::Connect,
        comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Connect>,
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
            comms::option::def::StaticNumIdImpl<cc_mqtt311::MsgId_Connect>,
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
    ///     The generated values, types and functions are:
    ///     @li @b FieldIdx_protocolName index, @b Field_protocolName type and @b field_protocolName() access fuction
    ///         for @ref ConnectFields::ProtocolName field.
    ///     @li @b FieldIdx_protocolLevel index, @b Field_protocolLevel type and @b field_protocolLevel() access fuction
    ///         for @ref ConnectFields::ProtocolLevel field.
    ///     @li @b FieldIdx_flags index, @b Field_flags type and @b field_flags() access fuction
    ///         for @ref ConnectFields::Flags field.
    ///     @li @b FieldIdx_keepAlive index, @b Field_keepAlive type and @b field_keepAlive() access fuction
    ///         for @ref ConnectFields::KeepAlive field.
    ///     @li @b FieldIdx_clientId index, @b Field_clientId type and @b field_clientId() access fuction
    ///         for @ref ConnectFields::ClientId field.
    ///     @li @b FieldIdx_willTopic index, @b Field_willTopic type and @b field_willTopic() access fuction
    ///         for @ref ConnectFields::WillTopic field.
    ///     @li @b FieldIdx_willMessage index, @b Field_willMessage type and @b field_willMessage() access fuction
    ///         for @ref ConnectFields::WillMessage field.
    ///     @li @b FieldIdx_userName index, @b Field_userName type and @b field_userName() access fuction
    ///         for @ref ConnectFields::UserName field.
    ///     @li @b FieldIdx_password index, @b Field_password type and @b field_password() access fuction
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
        return cc_mqtt311::message::ConnectCommon::name();
    }

    /// @brief Generated read functionality.
    template <typename TIter>
    comms::ErrorStatus doRead(TIter& iter, std::size_t len)
    {
        auto es = comms::ErrorStatus::Success;
        do {
            es = Base::template doReadUntilAndUpdateLen<FieldIdx_willTopic>(iter, len);
            if (es != comms::ErrorStatus::Success) {
                break;
            }

            readPrepare_willTopic();

            es = Base::template doReadFromUntilAndUpdateLen<FieldIdx_willTopic, FieldIdx_willMessage>(iter, len);
            if (es != comms::ErrorStatus::Success) {
                break;
            }

            readPrepare_willMessage();

            es = Base::template doReadFromUntilAndUpdateLen<FieldIdx_willMessage, FieldIdx_userName>(iter, len);
            if (es != comms::ErrorStatus::Success) {
                break;
            }

            readPrepare_userName();

            es = Base::template doReadFromUntilAndUpdateLen<FieldIdx_userName, FieldIdx_password>(iter, len);
            if (es != comms::ErrorStatus::Success) {
                break;
            }

            readPrepare_password();

            es = Base::template doReadFrom<FieldIdx_password>(iter, len);
        } while (false);
        return es;
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

    /// @brief Generated refresh functionality.
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
    void readPrepare_willTopic()
    {
        refresh_willTopic();
    }

    void readPrepare_willMessage()
    {
        refresh_willMessage();
    }

    void readPrepare_userName()
    {
        refresh_userName();
    }

    void readPrepare_password()
    {
        refresh_password();
    }

    bool refresh_willTopic()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (field_flags().field_low().getBitValue_willFlag()) {
            mode = comms::field::OptionalMode::Exists;
        }

        if (field_willTopic().getMode() == mode) {
            return false;
        }

        field_willTopic().setMode(mode);
        return true;
    }

    bool refresh_willMessage()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (field_flags().field_low().getBitValue_willFlag()) {
            mode = comms::field::OptionalMode::Exists;
        }

        if (field_willMessage().getMode() == mode) {
            return false;
        }

        field_willMessage().setMode(mode);
        return true;
    }

    bool refresh_userName()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (field_flags().field_high().getBitValue_userNameFlag()) {
            mode = comms::field::OptionalMode::Exists;
        }

        if (field_userName().getMode() == mode) {
            return false;
        }

        field_userName().setMode(mode);
        return true;
    }

    bool refresh_password()
    {
        auto mode = comms::field::OptionalMode::Missing;
        if (field_flags().field_high().getBitValue_passwordFlag()) {
            mode = comms::field::OptionalMode::Exists;
        }

        if (field_password().getMode() == mode) {
            return false;
        }

        field_password().setMode(mode);
        return true;
    }
};

} // namespace message

} // namespace cc_mqtt311
