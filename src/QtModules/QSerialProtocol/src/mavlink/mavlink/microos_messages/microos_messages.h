/** @file
 *  @brief MAVLink comm protocol generated from microos_messages.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_MICROOS_MESSAGES_H
#define MAVLINK_MICROOS_MESSAGES_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_MICROOS_MESSAGES.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 1

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{0, 31, 14, 14, 0, 0, 0}, {1, 215, 22, 22, 0, 0, 0}, {2, 248, 37, 37, 0, 0, 0}, {3, 172, 52, 52, 0, 0, 0}, {4, 133, 2, 2, 0, 0, 0}, {5, 107, 32, 32, 0, 0, 0}, {10, 115, 15, 15, 0, 0, 0}, {11, 160, 15, 15, 0, 0, 0}, {12, 251, 43, 43, 0, 0, 0}, {13, 24, 43, 43, 0, 0, 0}, {14, 234, 68, 68, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_MICROOS_MESSAGES

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
#include "./mavlink_msg_heartbeat.h"
#include "./mavlink_msg_thread_info.h"
#include "./mavlink_msg_partition.h"
#include "./mavlink_msg_gpio.h"
#include "./mavlink_msg_event.h"
#include "./mavlink_msg_print.h"
#include "./mavlink_msg_param_int.h"
#include "./mavlink_msg_param_float.h"
#include "./mavlink_msg_param_string.h"
#include "./mavlink_msg_param_data.h"
#include "./mavlink_msg_gpiox.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 1

#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_HEARTBEAT, MAVLINK_MESSAGE_INFO_THREAD_INFO, MAVLINK_MESSAGE_INFO_PARTITION, MAVLINK_MESSAGE_INFO_GPIO, MAVLINK_MESSAGE_INFO_EVENT, MAVLINK_MESSAGE_INFO_PRINT, MAVLINK_MESSAGE_INFO_PARAM_INT, MAVLINK_MESSAGE_INFO_PARAM_FLOAT, MAVLINK_MESSAGE_INFO_PARAM_STRING, MAVLINK_MESSAGE_INFO_PARAM_DATA, MAVLINK_MESSAGE_INFO_GPIOX}
# define MAVLINK_MESSAGE_NAMES {{ "EVENT", 4 }, { "GPIO", 3 }, { "GPIOX", 14 }, { "HEARTBEAT", 0 }, { "PARAM_DATA", 13 }, { "PARAM_FLOAT", 11 }, { "PARAM_INT", 10 }, { "PARAM_STRING", 12 }, { "PARTITION", 2 }, { "PRINT", 5 }, { "THREAD_INFO", 1 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_MICROOS_MESSAGES_H
