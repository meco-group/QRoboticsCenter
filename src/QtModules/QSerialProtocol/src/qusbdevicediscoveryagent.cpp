#include "qusbdevicediscoveryagent.h"

QUSBDeviceDiscoveryAgent::QUSBDeviceDiscoveryAgent(QObject *parent) : QObject(parent)
{

}

QUSBDeviceDiscoveryAgent::~QUSBDeviceDiscoveryAgent()
{

}

void QUSBDeviceDiscoveryAgent::start()
{
    QList<QSerialPortInfo> serial_port_list = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &serial_port, serial_port_list) {
        emit deviceDiscovered(serial_port);
    }
}

