#include "qdatanode.h"

QDataNode::QDataNode(QObject *parent) : QObject(parent)
{

}

QDataNode::~QDataNode(){
    //do nothing here
}

void QDataNode::transmitTo(QDataNode *other)
{

#define QDATANODE_CONNECT(s) \
    QObject::connect(this, static_cast<void (QDataNode::*)(s)>(&QDataNode::transmit), \
                     other, static_cast<void (QDataNode::*)(s)>(&QDataNode::receive));

    QDATANODE_CONNECT(heartbeat_t);
    QDATANODE_CONNECT(gpio_t);
    QDATANODE_CONNECT(gpiox_t);
    QDATANODE_CONNECT(print_t);
    QDATANODE_CONNECT(thread_info_t);
    QDATANODE_CONNECT(event_t);
    QDATANODE_CONNECT(partition_t);
    QDATANODE_CONNECT(param_int_t);
    QDATANODE_CONNECT(param_float_t);
    QDATANODE_CONNECT(param_string_t);
    QDATANODE_CONNECT(param_data_t);
    QDATANODE_CONNECT(attitude_cmd_t);
    QDATANODE_CONNECT(velocity_cmd_t);
    QDATANODE_CONNECT(position_cmd_t);
    QDATANODE_CONNECT(pose_t);
    QDATANODE_CONNECT(attitude_t);
    QDATANODE_CONNECT(velocity_t);
    QDATANODE_CONNECT(position_t);
    QDATANODE_CONNECT(signal_sweptsine_t);
    QDATANODE_CONNECT(signal_multisine_t);
    QDATANODE_CONNECT(signal_steppedsine_t);
}

void QDataNode::receiveFrom(QDataNode *other)
{
    other->transmitTo(this);
}

void QDataNode::connectTo(QDataNode *other)
{
    transmitTo(other);
    receiveFrom(other);
}
