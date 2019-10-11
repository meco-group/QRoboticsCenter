#include "qserialscanner.h"

QSerialScanner::QSerialScanner(QObject *parent) :
    QObject(parent),
    _local_device_BT(new QBluetoothLocalDevice)
{
    this->setupUSB();
    this->setupBT();
}

void QSerialScanner::query() {
    this->scanUSB();
    this->scanBT();
}

void QSerialScanner::setupUSB() {
    qDebug() << "Setting up USB discovery ...";
    _discovery_agent_USB = new QUSBDeviceDiscoveryAgent();
    connect(_discovery_agent_USB, SIGNAL(deviceDiscovered(QSerialPortInfo)),
            this, SLOT(connectionUSB(QSerialPortInfo)));
}

void QSerialScanner::setupBT() {
    qDebug() << "Setting up Bluetooth discovery ...";
    _discovery_agent_BT = new QBluetoothDeviceDiscoveryAgent();

    // Bluetooth adaptor configuration
    _local_device_BT->powerOn();
    _local_device_BT->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
    _discovery_agent_BT->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);

    connect(_discovery_agent_BT, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
            this, SLOT(connectionBT(QBluetoothDeviceInfo)));
}

void QSerialScanner::scanUSB() {
    _discovery_agent_USB->start();
}

void QSerialScanner::scanBT() {
    _discovery_agent_BT->start();
}

void QSerialScanner::scanUDP() {
    //_discovery_agent_TCP->start();
}

void QSerialScanner::checkConnection(QSerialProtocol *connection) {
    QHeartbeatDetector *monitor = new QHeartbeatDetector(connection);
    QObject::connect(monitor, &QHeartbeatDetector::alive, this, &QSerialScanner::connectionAlive);
    QObject::connect(monitor, &QHeartbeatDetector::dead, this, &QSerialScanner::connectionDead);
    monitor->start();
}

void QSerialScanner::connectionUSB(QSerialPortInfo info) {
    QSerialPort *io_device = new QSerialPort(info);
    io_device->setBaudRate(QSerialPort::Baud115200);
    if(!io_device->open(QIODevice::ReadWrite)){
        qDebug() << "Error opening port" << io_device->portName();
    }

    QSerialProtocol *connection = new QSerialProtocol(io_device, this);
    connection->setObjectName(io_device->portName());
    checkConnection(connection);
}

void QSerialScanner::connectionBT(QBluetoothDeviceInfo info) {
    QBluetoothSocket *io_device = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    qDebug() << "Created Bluetooth socket.";
    io_device->connectToService(info.address(),QBluetoothUuid(QBluetoothUuid::SerialPort));
    qDebug() << "Bluetooth connection established.";

    QSerialProtocol *connection = new QSerialProtocol(io_device,this);
    connection->setObjectName(info.name());
    checkConnection(connection);
}

void QSerialScanner::connectionUDP(QString server, int port) {
    /*QTcpSocket* socket = new QTcpSocket;
    socket->connectToHost(server, port);

    if(socket->waitForConnected(30000)){
        this->handleMavlinkConnection(socket, server, SERIAL_TCP);
    } else {
        qDebug() << "Error when connecting to host " + server + ":" + QString::number(port);
        qDebug() << socket->errorString();
    }*/
    //checkConnection(connection);
}

void QSerialScanner::connectionAlive(QDataNode *datanode) {
    emit connectionFound((QSerialProtocol*)datanode);
    qDebug() << "MAVlink detected on device" << datanode->objectName();
}

void QSerialScanner::connectionDead(QDataNode *datanode) {
    datanode->deleteLater();
    qDebug() << "No MAVlink detected on device" << datanode->objectName();
}
