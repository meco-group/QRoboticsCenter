#ifndef QDATAGROUP_H
#define QDATAGROUP_H

#include <qdatanode.h>

class QDataGroup : public QDataNode
{
public:
    explicit QDataGroup(QOject *parent = 0);

    void addDataNode(QDataNode* datanode);

private:
    QList<QDataNode*> _datanodes;

public slots:
    virtual void ontransmit(heartbeat_t heartbeat){ emit transmit(heartbeat); }
    virtual void ontransmit(event_t event){ emit transmit(event); }
    virtual void ontransmit(param_int_t param_int){ emit transmit(param_int); }
    virtual void ontransmit(param_float_t param_float){ emit transmit(param_float); }
    virtual void ontransmit(param_string_t param_string){ emit transmit(param_string); }
    virtual void ontransmit(param_data_t param_data){ emit transmit(param_data); }

    virtual void receive(heartbeat_t);
    virtual void receive(event_t);
    virtual void receive(param_int_t);
    virtual void receive(param_float_t);
    virtual void receive(param_string_t);
    virtual void receive(param_data_t);

};

#endif // QDATAGROUP_H
