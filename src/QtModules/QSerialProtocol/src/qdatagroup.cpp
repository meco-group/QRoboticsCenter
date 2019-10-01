#include "qdatagroup.h"

QDataGroup::QDataGroup(QObject *parent) : QDataNode(parent)
{

}


void QDataGroup::addDataNode(QDataNode *datanode)
{
    _datanodes.append(datanode);

    QObject::connect(datanode, SIGNAL(transmit(heartbeat_t)), this, SLOT(ontransmit(heartbeat_t)));
    QObject::connect(datanode, SIGNAL(transmit(event_t)), this, SLOT(ontransmit(event_t)));
    QObject::connect(datanode, SIGNAL(transmit(param_int_t)), this, SLOT(ontransmit(param_int_t)));
    QObject::connect(datanode, SIGNAL(transmit(param_float_t)), this, SLOT(ontransmit(param_float_t)));
    QObject::connect(datanode, SIGNAL(transmit(param_string_t)), this, SLOT(ontransmit(param_string_t)));
    QObject::connect(datanode, SIGNAL(transmit(param_data_t)), this, SLOT(ontransmit(param_data_t)));
}

void QDataGroup::receive(heartbeat_t heartbeat)
{
    QListIterator<QDataNode*> i(_datanodes);
    while(i.hasNext())
        i.next()->receive(heartbeat);
}

void QDataGroup::receive(event_t event)
{
    QListIterator<QDataNode*> i(_datanodes);
    while(i.hasNext())
        i.next()->receive(event);
}

void QDataGroup::receive(param_int_t param_int)
{
    QListIterator<QDataNode*> i(_datanodes);
    while(i.hasNext())
        i.next()->receive(param_int);
}

void QDataGroup::receive(param_float_t param_float)
{
    QListIterator<QDataNode*> i(_datanodes);
    while(i.hasNext())
        i.next()->receive(param_float);
}

void QDataGroup::receive(param_string_t param_string)
{
    QListIterator<QDataNode*> i(_datanodes);
    while(i.hasNext())
        i.next()->receive(param_string);
}

void QDataGroup::receive(param_data_t param_data)
{
    QListIterator<QDataNode*> i(_datanodes);
    while(i.hasNext())
        i.next()->receive(param_data);
}
