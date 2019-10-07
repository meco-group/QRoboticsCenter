/** @file
 *  @brief MAVLink comm protocol generated from robot_messages.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_ROBOT_MESSAGES_H
#define MAVLINK_ROBOT_MESSAGES_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_ROBOT_MESSAGES.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 31, 14, 14, 0, 0, 0}, {1, 215, 22, 22, 0, 0, 0}, {2, 248, 37, 37, 0, 0, 0}, {3, 172, 52, 52, 0, 0, 0}, {4, 133, 2, 2, 0, 0, 0}, {5, 107, 32, 32, 0, 0, 0}, {10, 115, 15, 15, 0, 0, 0}, {11, 160, 15, 15, 0, 0, 0}, {12, 251, 43, 43, 0, 0, 0}, {13, 24, 43, 43, 0, 0, 0}, {14, 234, 68, 68, 0, 0, 0}, {50, 97, 18, 18, 0, 0, 0}, {51, 114, 28, 28, 0, 0, 0}, {52, 97, 28, 28, 0, 0, 0}, {53, 27, 40, 40, 0, 0, 0}, {54, 19, 12, 12, 0, 0, 0}, {55, 172, 12, 12, 0, 0, 0}, {56, 122, 18, 18, 0, 0, 0}, {70, 158, 48, 48, 0, 0, 0}, {71, 230, 16, 16, 0, 0, 0}, {80, 41, 18, 18, 0, 0, 0}, {81, 237, 7, 7, 0, 0, 0}, {82, 15, 19, 19, 0, 0, 0}, {102, 156, 53, 53, 0, 0, 0}, {103, 102, 5, 5, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_ROBOT_MESSAGES

// ENUM DEFINITIONS



// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_pose.h"
#include "./mavlink_msg_attitude.h"
#include "./mavlink_msg_velocity.h"
#include "./mavlink_msg_position.h"
#include "./mavlink_msg_attitude_cmd.h"
#include "./mavlink_msg_velocity_cmd.h"
#include "./mavlink_msg_position_cmd.h"
#include "./mavlink_msg_radar_cloud.h"
#include "./mavlink_msg_radar_line.h"
#include "./mavlink_msg_signal_sweptsine.h"
#include "./mavlink_msg_signal_multisine.h"
#include "./mavlink_msg_signal_steppedsine.h"
#include "./mavlink_msg_channel_io.h"
#include "./mavlink_msg_channel_io_info.h"

// base include
#include "../microos_messages/microos_messages.h"

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_THREAD_INFO, MAVLINK_MESSAGE_INFO_PARTITION, MAVLINK_MESSAGE_INFO_GPIO, MAVLINK_MESSAGE_INFO_EVENT, MAVLINK_MESSAGE_INFO_PRINT, MAVLINK_MESSAGE_INFO_PARAM_INT, MAVLINK_MESSAGE_INFO_PARAM_FLOAT, MAVLINK_MESSAGE_INFO_PARAM_STRING, MAVLINK_MESSAGE_INFO_PARAM_DATA, MAVLINK_MESSAGE_INFO_GPIOX, MAVLINK_MESSAGE_INFO_POSE, MAVLINK_MESSAGE_INFO_ATTITUDE, MAVLINK_MESSAGE_INFO_VELOCITY, MAVLINK_MESSAGE_INFO_POSITION, MAVLINK_MESSAGE_INFO_ATTITUDE_CMD, MAVLINK_MESSAGE_INFO_VELOCITY_CMD, MAVLINK_MESSAGE_INFO_POSITION_CMD, MAVLINK_MESSAGE_INFO_RADAR_CLOUD, MAVLINK_MESSAGE_INFO_RADAR_LINE, MAVLINK_MESSAGE_INFO_SIGNAL_SWEPTSINE, MAVLINK_MESSAGE_INFO_SIGNAL_MULTISINE, MAVLINK_MESSAGE_INFO_SIGNAL_STEPPEDSINE, MAVLINK_MESSAGE_INFO_CHANNEL_IO, MAVLINK_MESSAGE_INFO_CHANNEL_IO_INFO}
# define MAVLINK_MESSAGE_NAMES {{ "ATTITUDE", 51 }, { "ATTITUDE_CMD", 54 }, { "CHANNEL_IO", 102 }, { "CHANNEL_IO_INFO", 103 }, { "EVENT", 4 }, { "GPIO", 3 }, { "GPIOX", 14 }, { "HEARTBEAT", 0 }, { "PARAM_DATA", 13 }, { "PARAM_FLOAT", 11 }, { "PARAM_INT", 10 }, { "PARAM_STRING", 12 }, { "PARTITION", 2 }, { "POSE", 50 }, { "POSITION", 53 }, { "POSITION_CMD", 56 }, { "PRINT", 5 }, { "RADAR_CLOUD", 70 }, { "RADAR_LINE", 71 }, { "SIGNAL_MULTISINE", 81 }, { "SIGNAL_STEPPEDSINE", 82 }, { "SIGNAL_SWEPTSINE", 80 }, { "THREAD_INFO", 1 }, { "VELOCITY", 52 }, { "VELOCITY_CMD", 55 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_ROBOT_MESSAGES_H
