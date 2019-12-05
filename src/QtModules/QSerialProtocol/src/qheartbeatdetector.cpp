#include "qheartbeatdetector.h"

QHeartbeatDetector::QHeartbeatDetector(QSerialProtocol *datanode) :
    _datanode(datanode)
{
  qDebug() << "QHeartbeatDetector::QHeartbeatDetector()";
  connectTo(_datanode);

  _timer.setSingleShot(true);
  _timer.setInterval(3000);
  QObject::connect(&_timer, SIGNAL(timeout()), this, SLOT(timeout()));
}

void QHeartbeatDetector::receive(heartbeat_t heartbeat) {
  _timer.stop();
  _datanode->setTransmitterType(heartbeat.type);
  emit alive(_datanode);
  qDebug() << "QHeartbeatDetector::receive: Heartbeat detected on" << _datanode->objectName();
  deleteLater();
}

void QHeartbeatDetector::timeout() {
  emit dead(_datanode);
  qDebug() << "QHeartbeatDetector::timeout: Heartbeat detector timed out on" << _datanode->objectName();
  deleteLater();
}

void QHeartbeatDetector::start() {
  _timer.start();
  qDebug() << "QHeartbeatDetector::start: Heartbeat detector started on" << _datanode->objectName();
}
