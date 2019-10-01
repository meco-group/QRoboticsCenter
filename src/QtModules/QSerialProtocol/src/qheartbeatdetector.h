#ifndef QHEARTBEATDETECTOR_H
#define QHEARTBEATDETECTOR_H

#include <qserialprotocol.h>
#include <QTimer>
#include <QDebug>

class QHeartbeatDetector : public QDataNode
{
    Q_OBJECT

private:
    QTimer _timer;
    QSerialProtocol *_datanode;

public:
    explicit QHeartbeatDetector(QSerialProtocol *datanode);

public slots:
    void receive(heartbeat_t heartbeat);
    void timeout();
    void start();

signals:
    void alive(QSerialProtocol *datanode);
    void dead(QSerialProtocol *datanode);
};

#endif // QHEARTBEATDETECTOR_H
