#ifndef SERIAL_PROTOCOL_H
#define SERIAL_PROTOCOL_H

#ifdef SERIAL_PROTOCOL_MAVLINK
   #include <protocol_mavlink.h>
#endif

enum event_id_t {
    PARAMETERS_REQUEST_SEND = 100,
    PARAMETERS_REQUEST_ST0RE = 101
};

#endif // SERIAL_PROTOCOL_H
