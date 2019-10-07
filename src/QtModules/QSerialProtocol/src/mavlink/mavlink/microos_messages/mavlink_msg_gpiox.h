#pragma once
// MESSAGE GPIOX PACKING

#define MAVLINK_MSG_ID_GPIOX 14

MAVPACKED(
typedef struct __mavlink_gpiox_t {
 uint32_t time; /*<  Time at which the message was sent*/
 float gpio_float[12]; /*<  12 gpio floating point values*/
}) mavlink_gpiox_t;

#define MAVLINK_MSG_ID_GPIOX_LEN 52
#define MAVLINK_MSG_ID_GPIOX_MIN_LEN 52
#define MAVLINK_MSG_ID_14_LEN 52
#define MAVLINK_MSG_ID_14_MIN_LEN 52

#define MAVLINK_MSG_ID_GPIOX_CRC 221
#define MAVLINK_MSG_ID_14_CRC 221

#define MAVLINK_MSG_GPIOX_FIELD_GPIO_FLOAT_LEN 12

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPIOX { \
    14, \
    "GPIOX", \
    2, \
    {  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gpiox_t, time) }, \
         { "gpio_float", NULL, MAVLINK_TYPE_FLOAT, 12, 4, offsetof(mavlink_gpiox_t, gpio_float) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPIOX { \
    "GPIOX", \
    2, \
    {  { "time", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_gpiox_t, time) }, \
         { "gpio_float", NULL, MAVLINK_TYPE_FLOAT, 12, 4, offsetof(mavlink_gpiox_t, gpio_float) }, \
         } \
}
#endif

/**
 * @brief Pack a gpiox message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time  Time at which the message was sent
 * @param gpio_float  12 gpio floating point values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gpiox_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time, const float *gpio_float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPIOX_LEN];
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_float_array(buf, 4, gpio_float, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPIOX_LEN);
#else
    mavlink_gpiox_t packet;
    packet.time = time;
    mav_array_memcpy(packet.gpio_float, gpio_float, sizeof(float)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPIOX_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPIOX;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
}

/**
 * @brief Pack a gpiox message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time  Time at which the message was sent
 * @param gpio_float  12 gpio floating point values
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gpiox_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time,const float *gpio_float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPIOX_LEN];
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_float_array(buf, 4, gpio_float, 12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPIOX_LEN);
#else
    mavlink_gpiox_t packet;
    packet.time = time;
    mav_array_memcpy(packet.gpio_float, gpio_float, sizeof(float)*12);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPIOX_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPIOX;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
}

/**
 * @brief Encode a gpiox struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gpiox C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gpiox_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gpiox_t* gpiox)
{
    return mavlink_msg_gpiox_pack(system_id, component_id, msg, gpiox->time, gpiox->gpio_float);
}

/**
 * @brief Encode a gpiox struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gpiox C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gpiox_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gpiox_t* gpiox)
{
    return mavlink_msg_gpiox_pack_chan(system_id, component_id, chan, msg, gpiox->time, gpiox->gpio_float);
}

/**
 * @brief Send a gpiox message
 * @param chan MAVLink channel to send the message
 *
 * @param time  Time at which the message was sent
 * @param gpio_float  12 gpio floating point values
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gpiox_send(mavlink_channel_t chan, uint32_t time, const float *gpio_float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPIOX_LEN];
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_float_array(buf, 4, gpio_float, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIOX, buf, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
#else
    mavlink_gpiox_t packet;
    packet.time = time;
    mav_array_memcpy(packet.gpio_float, gpio_float, sizeof(float)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIOX, (const char *)&packet, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
#endif
}

/**
 * @brief Send a gpiox message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gpiox_send_struct(mavlink_channel_t chan, const mavlink_gpiox_t* gpiox)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gpiox_send(chan, gpiox->time, gpiox->gpio_float);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIOX, (const char *)gpiox, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPIOX_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gpiox_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time, const float *gpio_float)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time);
    _mav_put_float_array(buf, 4, gpio_float, 12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIOX, buf, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
#else
    mavlink_gpiox_t *packet = (mavlink_gpiox_t *)msgbuf;
    packet->time = time;
    mav_array_memcpy(packet->gpio_float, gpio_float, sizeof(float)*12);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPIOX, (const char *)packet, MAVLINK_MSG_ID_GPIOX_MIN_LEN, MAVLINK_MSG_ID_GPIOX_LEN, MAVLINK_MSG_ID_GPIOX_CRC);
#endif
}
#endif

#endif

// MESSAGE GPIOX UNPACKING


/**
 * @brief Get field time from gpiox message
 *
 * @return  Time at which the message was sent
 */
static inline uint32_t mavlink_msg_gpiox_get_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field gpio_float from gpiox message
 *
 * @return  12 gpio floating point values
 */
static inline uint16_t mavlink_msg_gpiox_get_gpio_float(const mavlink_message_t* msg, float *gpio_float)
{
    return _MAV_RETURN_float_array(msg, gpio_float, 12,  4);
}

/**
 * @brief Decode a gpiox message into a struct
 *
 * @param msg The message to decode
 * @param gpiox C-struct to decode the message contents into
 */
static inline void mavlink_msg_gpiox_decode(const mavlink_message_t* msg, mavlink_gpiox_t* gpiox)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gpiox->time = mavlink_msg_gpiox_get_time(msg);
    mavlink_msg_gpiox_get_gpio_float(msg, gpiox->gpio_float);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPIOX_LEN? msg->len : MAVLINK_MSG_ID_GPIOX_LEN;
        memset(gpiox, 0, MAVLINK_MSG_ID_GPIOX_LEN);
    memcpy(gpiox, _MAV_PAYLOAD(msg), len);
#endif
}
