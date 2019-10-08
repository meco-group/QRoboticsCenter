#include "qgpiorecorder.h"

QGPIORecorder::QGPIORecorder(QGPIOWidget *gpiox, QObject *parent) :
#ifdef QGPIO_RECORD_CSV
  QCSVRecorder("GPIO", LOG_GPIO, parent), _gpiox(gpiox)
#else
  QXMLRecorder("GPIO", LOG_GPIO, parent), _gpiox(gpiox)
#endif
{
  // ...
}

#ifdef QGPIO_RECORD_CSV
QString QGPIORecorder::insertHeader() {
  QString header = "Time, ";
  QStringList labels = _gpiox->getLabels();
  header += labels.join(", ") + "\n";
  return header;
}

void QGPIORecorder::receive(gpiox_t gpiox) {
  if(isRecording()) {
    QString line = QString::number(gpiox.time);
    for(size_t k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
      line += ", " + QString::number(gpiox.gpio_float[k]);
    }
    line += "\n";
    _log->write(line.toLocal8Bit());
  }
}
#else
QString QGPIORecorder::insertHeader() {
  QString header;

  // Labels
  header += "\t<labels>\n";
  header += "\t\t<value>time</value>\n";
  QStringList labels = _gpiox->getLabels();
  for(size_t k = 0; k < labels.length(); k++) {
    header += "\t\t<value>" + labels[k] + "</value>\n";
  }
  header += "\t</labels>\n";

  return header;
}

void QGPIORecorder::receive(gpiox_t gpiox) {
  if(isRecording()) {
    QString line = "\t\t<row>";
    line += QString::number(gpiox.time);
    for(size_t k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
      line +=  "\t" + QString::number(gpiox.gpio_float[k]);
    }
    line += "</row>\n";

    _log->write(line.toLocal8Bit());
  }
}
#endif
