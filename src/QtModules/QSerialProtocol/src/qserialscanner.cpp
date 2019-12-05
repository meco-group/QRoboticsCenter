#include "qserialscanner.h"

QSerialScanner::QSerialScanner(QObject *parent) :
  QObject(parent)
#ifdef WITH_BLUETOOTH
  ,_local_device_BT(new QBluetoothLocalDevice)
#endif
{
  qDebug() << "QSerialScanner::QSerialScanner()";
  this->setupUSB();
#ifdef WITH_BLUETOOTH
  this->setupBT();
#endif
}

void QSerialScanner::query() {
  this->scanUSB();
#ifdef WITH_BLUETOOTH
  this->scanBT();
#endif
}

void QSerialScanner::setupUSB() {
  qDebug() << "QSerialScanner::setupUSB: Setting up USB discovery ...";
  _discovery_agent_USB = new QUSBDeviceDiscoveryAgent();
  connect(_discovery_agent_USB, SIGNAL(deviceDiscovered(QSerialPortInfo)),
          this, SLOT(connectionUSB(QSerialPortInfo)));
}

#ifdef WITH_BLUETOOTH
void QSerialScanner::setupBT() {
  qDebug() << "QSerialScanner::setupBT: Setting up Bluetooth discovery ...";
  _discovery_agent_BT = new QBluetoothDeviceDiscoveryAgent();

  // Bluetooth adaptor configuration
  _local_device_BT->powerOn();
  _local_device_BT->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
  _discovery_agent_BT->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);

  connect(_discovery_agent_BT, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
          this, SLOT(connectionBT(QBluetoothDeviceInfo)));
}
#endif

void QSerialScanner::scanUSB() {
  qDebug() << "QSerialScanner::scanUSB: Starting USB discovery agent ...";
  _discovery_agent_USB->start();
}

#ifdef WITH_BLUETOOTH
void QSerialScanner::scanBT() {
  qDebug() << "QSerialScanner::scanBT: Starting Bluetooth discovery agent ...";
  _discovery_agent_BT->start();
}
#endif

void QSerialScanner::scanUDP() {
  qDebug() << "QSerialScanner::scanUDP: Starting UDP discovery agent ...";
  //_discovery_agent_TCP->start();
}

void QSerialScanner::checkConnection(QSerialProtocol *connection) {
  QHeartbeatDetector *monitor = new QHeartbeatDetector(connection);
  QObject::connect(monitor, &QHeartbeatDetector::alive, this, &QSerialScanner::connectionAlive);
  QObject::connect(monitor, &QHeartbeatDetector::dead, this, &QSerialScanner::connectionDead);
  monitor->start();
}

void QSerialScanner::connectionUSB(QSerialPortInfo info) {
  qDebug() << "QSerialScanner::connectionUSB: USB device discovered:" << info.portName();
  qDebug() << "\tSerial number:" << info.portName();
  qDebug() << "\tBusy:" << info.isBusy();
  qDebug() << "\tNull:" << info.isNull();
  qDebug() << "\tManufaturer:" << info.manufacturer();
  qDebug() << "\tProduct identifier:" << info.productIdentifier();
  qDebug() << "\tSerial numbers:" << info.serialNumber();
  qDebug() << "\tSystem location:" << info.systemLocation();
  qDebug() << "\tVendor identifier:" << info.vendorIdentifier();

  QSerialPort *io_device = new QSerialPort(info);
  io_device->setBaudRate(QSerialPort::Baud115200);
  if(!io_device->open(QIODevice::ReadWrite))
    qDebug() << "QSerialScanner::connectionUSB: Error opening port" << io_device->portName();
  else
    qDebug() << "QSerialScanner::connectionUSB: Successfully opened port" << io_device->portName();

  QSerialProtocol *connection = new QSerialProtocol(io_device, this, io_device->portName());
  checkConnection(connection);
}

#ifdef WITH_BLUETOOTH
void QSerialScanner::connectionBT(QBluetoothDeviceInfo info) {
  QBluetoothSocket *io_device = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
  qDebug() << "QSerialScanner::connectionBT: Created Bluetooth socket.";
  io_device->connectToService(info.address(),QBluetoothUuid(QBluetoothUuid::SerialPort));
  qDebug() << "QSerialScanner::connectionBT: Bluetooth connection established on" << info.name();

  QSerialProtocol *connection = new QSerialProtocol(io_device, this, info.name());
  checkConnection(connection);
}
#endif

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
