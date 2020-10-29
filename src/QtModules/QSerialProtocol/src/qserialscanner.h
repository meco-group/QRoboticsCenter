#ifndef QSERIALSCANNER_H
#define QSERIALSCANNER_H

#include <QObject>
#include <QtSerialPort>
#include <QSerialPortInfo>
#ifdef WITH_BLUETOOTH
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothServiceInfo>
#include <QBluetoothSocket>
#endif

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
    void setupTCP();
#ifdef WITH_BLUETOOTH
    void setupBT();
#endif


private:
    QUSBDeviceDiscoveryAgent        *_discovery_agent_USB;
#ifdef WITH_BLUETOOTH
    QBluetoothDeviceDiscoveryAgent  *_discovery_agent_BT;
    QBluetoothLocalDevice           *_local_device_BT;
#endif

    void checkConnection(QSerialProtocol* connection);

signals:
    void connectionFound(QSerialProtocol *connection);

public slots:
    void query();

    void connectionUSB(QSerialPortInfo info);
    void scanUSB();

#ifdef WITH_BLUETOOTH
    void connectionBT(QBluetoothDeviceInfo info);
    void scanBT();
#endif

    void connectionUDP(QString server, int port);
    void scanUDP();

private slots:
    void connectionAlive(QDataNode* datanode);
    void connectionDead(QDataNode* datanode);

};

#endif // QSERIALSCANNER_H
