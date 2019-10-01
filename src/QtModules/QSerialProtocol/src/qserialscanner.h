#ifndef QSERIALSCANNER_H
#define QSERIALSCANNER_H

#include <QObject>
#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothServiceInfo>
#include <QBluetoothSocket>

#include <qserialprotocol.h>
#include <qheartbeatdetector.h>
#include <qusbdevicediscoveryagent.h>
//#include <qudpdevicediscoveryagent.h>

class QSerialScanner : public QObject
{
    Q_OBJECT

public:
    explicit QSerialScanner(QObject *parent = 0);

    QSerialProtocol* findConnection(QString name);

    void setupUSB();
    void setupBT();
    void setupTCP();

private:
    QUSBDeviceDiscoveryAgent        *_discovery_agent_USB;
    QBluetoothDeviceDiscoveryAgent  *_discovery_agent_BT;
    QBluetoothLocalDevice           *_local_device_BT;

    void checkConnection(QSerialProtocol* connection);

signals:
    void connectionFound(QSerialProtocol *connection);

public slots:
    void query();

    void connectionUSB(QSerialPortInfo info);
    void connectionBT(QBluetoothDeviceInfo info);
    void connectionUDP(QString server, int port);

    void scanUSB();
    void scanBT();
    void scanUDP();

private slots:
    void connectionAlive(QDataNode* datanode);
    void connectionDead(QDataNode* datanode);

};

#endif // QSERIALSCANNER_H
