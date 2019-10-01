#include "qudpdevicediscoveryagent.h"

QUdpDeviceDiscoveryAgent::QUdpDeviceDiscoveryAgent(QObject *parent) : QObject(parent)
{
    udpSocket = new QUdpSocket(this);
    udpSocket->bind(65000, QUdpSocket::ShareAddress);
}

QUdpDeviceDiscoveryAgent::~QUdpDeviceDiscoveryAgent()
{

}

void QUdpDeviceDiscoveryAgent::start()
{
    QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void QUdpDeviceDiscoveryAgent::readPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        if(map.contains(sender)){
            map[sender]->mavlinkParseData(&datagram);
        } else {
            QUdpSocket* socket = new QUdpSocket(this);
            socket->bind(sender,senderPort,QAbstractSocket::ShareAddress);
            QMavlinkConnection* connection = new QMavlinkConnection(this,socket,sender.toString(),SERIAL_UDP);
            emit deviceDiscovered(connection);
            connection->mavlinkParseData(&datagram);
        }
    }
}
