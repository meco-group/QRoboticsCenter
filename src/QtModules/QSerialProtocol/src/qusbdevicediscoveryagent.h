#ifndef QUSBDEVICEDISCOVERYAGENT_H
#define QUSBDEVICEDISCOVERYAGENT_H

#include <QObject>
#include <QDebug>
#include <QSerialPortInfo>

class QUSBDeviceDiscoveryAgent : public QObject
{
    Q_OBJECT
public:
    explicit QUSBDeviceDiscoveryAgent(QObject *parent = 0);
    ~QUSBDeviceDiscoveryAgent();

    void start();

signals:
    void deviceDiscovered(QSerialPortInfo info);

public slots:
};

#endif // QUSBDEVICEDISCOVERYAGENT_H
