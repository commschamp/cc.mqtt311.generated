// Generated by commsdsl2comms v5.1.3

/// @file
/// @brief Contains definition of the AllMessages messages bundle.

#pragma once

#include <tuple>
#include "cc_mqtt311/message/Connack.h"
#include "cc_mqtt311/message/Connect.h"
#include "cc_mqtt311/message/Disconnect.h"
#include "cc_mqtt311/message/Pingreq.h"
#include "cc_mqtt311/message/Pingresp.h"
#include "cc_mqtt311/message/Puback.h"
#include "cc_mqtt311/message/Pubcomp.h"
#include "cc_mqtt311/message/Publish.h"
#include "cc_mqtt311/message/Pubrec.h"
#include "cc_mqtt311/message/Pubrel.h"
#include "cc_mqtt311/message/Suback.h"
#include "cc_mqtt311/message/Subscribe.h"
#include "cc_mqtt311/message/Unsuback.h"
#include "cc_mqtt311/message/Unsubscribe.h"
#include "cc_mqtt311/options/DefaultOptions.h"

namespace cc_mqtt311
{

namespace input
{

/// @brief Messages of the protocol in ascending order.
/// @tparam TBase Base class of all the messages.
/// @tparam TOpt Protocol definition options.
template <typename TBase, typename TOpt = cc_mqtt311::options::DefaultOptions>
using AllMessages =
    std::tuple<
        cc_mqtt311::message::Connect<TBase, TOpt>,
        cc_mqtt311::message::Connack<TBase, TOpt>,
        cc_mqtt311::message::Publish<TBase, TOpt>,
        cc_mqtt311::message::Puback<TBase, TOpt>,
        cc_mqtt311::message::Pubrec<TBase, TOpt>,
        cc_mqtt311::message::Pubrel<TBase, TOpt>,
        cc_mqtt311::message::Pubcomp<TBase, TOpt>,
        cc_mqtt311::message::Subscribe<TBase, TOpt>,
        cc_mqtt311::message::Suback<TBase, TOpt>,
        cc_mqtt311::message::Unsubscribe<TBase, TOpt>,
        cc_mqtt311::message::Unsuback<TBase, TOpt>,
        cc_mqtt311::message::Pingreq<TBase, TOpt>,
        cc_mqtt311::message::Pingresp<TBase, TOpt>,
        cc_mqtt311::message::Disconnect<TBase, TOpt>
    >;

} // namespace input

} // namespace cc_mqtt311
