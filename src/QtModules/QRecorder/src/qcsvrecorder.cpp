#include "qcsvrecorder.h"

QCSVRecorder::QCSVRecorder(const QString& type, const int id, QObject *parent) :
  QAbstractRecorder(type, id, parent)
{
  // ...
}

void QCSVRecorder::start() {
  // open file
  QString dir = QDir::homePath() + "/QRCrecords";
  QDir().mkdir(dir);
  _log = new QFile(dir + "/log_" + _type.toLower() + "_" + QDateTime::currentDateTime().toString("dd-MM-yyyy_HH-mm-ss") + ".csv", this);
  _log->open(QIODevice::WriteOnly);

  // create header
  createHeader();

  // send logging events
  event_t event;
  event.type = _id;
  transmit(event);
  event.type = LOG_START;
  transmit(event);
}

void QCSVRecorder::stop() {
  // send logging event
  event_t event;
  event.type = LOG_STOP;
  transmit(event);

  // close file
  createFooter();
  _log->close();
}

void QCSVRecorder::createHeader() {
  QString header;
  header  = "Q" + _type + "Record, "; // record type
  header += "QRC v" + QString(VERSION) + ", "; // QRC version
  header += QDateTime::currentDateTime().toString("dd-MM-yyyy @ HH:mm:ss, "); // date/time
  header += QSysInfo::prettyProductName() + ", ";
  header += QSysInfo::kernelVersion() + ", ";
  header += QSysInfo::currentCpuArchitecture() + "\n";
  header += insertHeader();

  _log->write(header.toLocal8Bit());
}

void QCSVRecorder::createFooter() {
  // ain't got no footer
}
