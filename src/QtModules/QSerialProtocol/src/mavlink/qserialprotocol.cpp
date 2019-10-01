#include <qserialprotocol.h>

void QSerialProtocol::setTransmitterType(int type)
{
    _transmitter_type = type;
}

void QSerialProtocol::timerEvent(QTimerEvent *)
{
    if(_io->isOpen()) {
        _io->write(_io_buffer.left(32));
        _io_buffer.remove(0,32);
    }
}

QSerialProtocol::QSerialProtocol(QIODevice *io, QObject *parent) :
    QDataNode(parent), _io(io)
{
    QObject::connect(_io, &QIODevice::readyRead, this, &QSerialProtocol::decode);

    _activate->setCheckable(true);
    _activate->setChecked(true);
    QObject::connect(_activate, &QAction::toggled, this, &QSerialProtocol::on_activate_toggled);
    startTimer(10);
}

QSerialProtocol::~QSerialProtocol()
{
    _io->close();
}

void QSerialProtocol::decode()
{

#define MAVLINK_DECODE(s) \
    s##_t s; \
    mavlink_msg_##s##_decode(&_msg,&s); \
    transmit(s); \
    break;

    QByteArray b = _io->readAll();
    for(int k=0;k<b.length();k++){
        if(mavlink_parse_char(0, b.at(k), &_msg, &_status)){
            _packet_count++;
            if(_transmitter_id < 0) {
                _transmitter_id = _msg.sysid;
            } else if(_transmitter_id != _msg.sysid){
                qDebug() << "System id appears to have changed";
            }
            switch(_msg.msgid) {
                case MAVLINK_MSG_ID_HEARTBEAT: { MAVLINK_DECODE(heartbeat) }
                case MAVLINK_MSG_ID_GPIO: { MAVLINK_DECODE(gpio) }
                case MAVLINK_MSG_ID_PRINT: { MAVLINK_DECODE(print) }
                case MAVLINK_MSG_ID_THREAD_INFO: { MAVLINK_DECODE(thread_info) }
                case MAVLINK_MSG_ID_EVENT: { MAVLINK_DECODE(event) }
                case MAVLINK_MSG_ID_PARTITION: { MAVLINK_DECODE(partition) }
                case MAVLINK_MSG_ID_PARAM_INT: { MAVLINK_DECODE(param_int) }
                case MAVLINK_MSG_ID_PARAM_FLOAT: { MAVLINK_DECODE(param_float) }
                case MAVLINK_MSG_ID_PARAM_STRING: { MAVLINK_DECODE(param_string) }
                case MAVLINK_MSG_ID_PARAM_DATA: { MAVLINK_DECODE(param_data) }
                case MAVLINK_MSG_ID_POSE: { MAVLINK_DECODE(pose) }
                case MAVLINK_MSG_ID_ATTITUDE: { MAVLINK_DECODE(attitude) }
                case MAVLINK_MSG_ID_VELOCITY: { MAVLINK_DECODE(velocity) }
                case MAVLINK_MSG_ID_POSITION: { MAVLINK_DECODE(position) }
                case MAVLINK_MSG_ID_ATTITUDE_CMD: { MAVLINK_DECODE(attitude_cmd) }
                case MAVLINK_MSG_ID_VELOCITY_CMD: { MAVLINK_DECODE(velocity_cmd) }
                case MAVLINK_MSG_ID_POSITION_CMD: { MAVLINK_DECODE(position_cmd) }
                case MAVLINK_MSG_ID_SIGNAL_SWEPTSINE: { MAVLINK_DECODE(signal_sweptsine) }
                case MAVLINK_MSG_ID_SIGNAL_MULTISINE: { MAVLINK_DECODE(signal_multisine) }
                case MAVLINK_MSG_ID_SIGNAL_STEPPEDSINE: {MAVLINK_DECODE(signal_steppedsine) }
                default: {
                    //qDebug() << "Unknown msg id: cannot decode.";
                }
            }
        }
        _packet_drops += _status.packet_rx_drop_count;
    }
}

void QSerialProtocol::encode(mavlink_message_t msg)
{
    QByteArray b(128,0);
    int bytes = mavlink_msg_to_send_buffer((uint8_t*)(b.data()), &msg);
    b.truncate(bytes);
    _io_buffer.append(b);
}

void QSerialProtocol::on_activate_toggled()
{
    if(_activate->isChecked()){
        _io->open(QIODevice::ReadWrite);
    } else {
        _io->close();
    }
}

void QSerialProtocol::on_info_triggered()
{

}

#define MAVLINK_RECEIVE(s) \
    void QSerialProtocol::receive(s##_t s) {\
        mavlink_message_t msg; \
        mavlink_msg_##s##_encode(0,0,&msg,&s); \
        encode(msg); }

MAVLINK_RECEIVE(heartbeat)
MAVLINK_RECEIVE(gpio)
MAVLINK_RECEIVE(print)
MAVLINK_RECEIVE(thread_info)
MAVLINK_RECEIVE(event)
MAVLINK_RECEIVE(partition)
MAVLINK_RECEIVE(param_int)
MAVLINK_RECEIVE(param_float)
MAVLINK_RECEIVE(param_string)
MAVLINK_RECEIVE(param_data)
MAVLINK_RECEIVE(attitude_cmd)
MAVLINK_RECEIVE(velocity_cmd)
MAVLINK_RECEIVE(position_cmd)
MAVLINK_RECEIVE(pose)
MAVLINK_RECEIVE(attitude)
MAVLINK_RECEIVE(velocity)
MAVLINK_RECEIVE(position)
MAVLINK_RECEIVE(signal_sweptsine)
MAVLINK_RECEIVE(signal_multisine)
MAVLINK_RECEIVE(signal_steppedsine)

int QSerialProtocol::packetCount()
{
    return _packet_count;
}

int QSerialProtocol::packetDrops()
{
    return _packet_drops;
}

int QSerialProtocol::transmitterID()
{
    return _transmitter_id;
}

int QSerialProtocol::transmitterType()
{
    return _transmitter_type;
}

QAction *QSerialProtocol::getActivateAction()
{
    return _activate;
}

