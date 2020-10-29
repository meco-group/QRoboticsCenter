#ifndef SERIAL_PROTOCOL_H
#define SERIAL_PROTOCOL_H

#include <QIODevice>
#include <QAction>
#include <QDebug>
#include <qdatanode.h>
#include <QDebug>

class QSerialProtocol : public QDataNode {
    Q_OBJECT

    friend class QHeartbeatDetector;

private:
    mavlink_message_t _msg;
    mavlink_status_t _status;
    int _packet_count = 0;
    int _packet_drops = 0;

    int _transmitter_id = -1;
    int _transmitter_type = -1;
    void setTransmitterType(int type);

    QIODevice* _io;
    QByteArray _io_buffer;

    QAction *_activate = new QAction("active",this);

protected:
    virtual void timerEvent(QTimerEvent *);

public:
    QSerialProtocol(QIODevice *io, QObject *parent = 0, QString name = "");
    virtual ~QSerialProtocol();

    int packetCount();
    int packetDrops();
    int transmitterID();
    int transmitterType();

    QAction *getActivateAction();

private slots:
    void decode();
    void encode(mavlink_message_t msg);
    void on_activate_toggled();
    void on_info_triggered();

public slots:
    virtual void receive(heartbeat_t);
    virtual void receive(gpio_t);
    virtual void receive(gpiox_t);
    virtual void receive(print_t);
    virtual void receive(thread_info_t);
    virtual void receive(event_t);
    virtual void receive(partition_t);
    virtual void receive(param_int_t);
    virtual void receive(param_float_t);
    virtual void receive(param_string_t);
    virtual void receive(param_data_t);
    virtual void receive(attitude_cmd_t);
    virtual void receive(velocity_cmd_t);
    virtual void receive(position_cmd_t);
    virtual void receive(pose_t);
    virtual void receive(attitude_t);
    virtual void receive(velocity_t);
    virtual void receive(position_t);
    virtual void receive(signal_sweptsine_t);
    virtual void receive(signal_multisine_t);
    virtual void receive(signal_steppedsine_t);

};

#endif // SERIAL_PROTOCOL_H
