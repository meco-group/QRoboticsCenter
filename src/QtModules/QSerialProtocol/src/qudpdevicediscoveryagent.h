#ifndef QUDPDEVICEDISCOVERYAGENT_H
#define QUDPDEVICEDISCOVERYAGENT_H

#include <QObject>
#include <QtNetwork/QUdpSocket>
#include "qmavlinkconnection.h"

class QUdpDeviceDiscoveryAgent : public QObject
{
    Q_OBJECT
public:
    explicit QUdpDeviceDiscoveryAgent(QObject *parent = 0);
    ~QUdpDeviceDiscoveryAgent();

    void start();

private:
    QUdpSocket* udpSocket;
    QHash<QHostAddress,QMavlinkConnection*> map;

signals:
    void deviceDiscovered(QMavlinkConnection* connection);

public slots:

private slots:
    void readPendingDatagrams();
};

#endif // QUDPDEVICEDISCOVERYAGENT_H
