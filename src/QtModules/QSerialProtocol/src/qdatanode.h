#ifndef QDATANODE_H
#define QDATANODE_H

#include <QObject>
#include <qserialprotocol_typedefs.h>

class QDataNode : public QObject
{
    Q_OBJECT

public:
    QDataNode(QObject *parent = 0);
    virtual ~QDataNode();

    virtual void transmitTo(QDataNode* other);
    virtual void receiveFrom(QDataNode* other);
    virtual void connectTo(QDataNode* other);

signals:
    void transmit(heartbeat_t);
    void transmit(gpio_t);
    void transmit(gpiox_t);
    void transmit(print_t);
    void transmit(thread_info_t);
    void transmit(event_t);
    void transmit(partition_t);
    void transmit(param_int_t);
    void transmit(param_float_t);
    void transmit(param_string_t);
    void transmit(param_data_t);
    void transmit(attitude_cmd_t);
    void transmit(velocity_cmd_t);
    void transmit(position_cmd_t);
    void transmit(pose_t);
    void transmit(attitude_t);
    void transmit(velocity_t);
    void transmit(position_t);
    void transmit(signal_sweptsine_t);
    void transmit(signal_multisine_t);
    void transmit(signal_steppedsine_t);

public slots:
    virtual void receive(heartbeat_t){}
    virtual void receive(gpio_t){}
    virtual void receive(gpiox_t){}
    virtual void receive(print_t){}
    virtual void receive(thread_info_t){}
    virtual void receive(event_t){}
    virtual void receive(partition_t){}
    virtual void receive(param_int_t){}
    virtual void receive(param_float_t){}
    virtual void receive(param_string_t){}
    virtual void receive(param_data_t){}
    virtual void receive(attitude_cmd_t){}
    virtual void receive(velocity_cmd_t){}
    virtual void receive(position_cmd_t){}
    virtual void receive(pose_t){}
    virtual void receive(attitude_t){}
    virtual void receive(velocity_t){}
    virtual void receive(position_t){}
    virtual void receive(signal_sweptsine_t){}
    virtual void receive(signal_multisine_t){}
    virtual void receive(signal_steppedsine_t){}

};

#endif // QDATANODE_H
