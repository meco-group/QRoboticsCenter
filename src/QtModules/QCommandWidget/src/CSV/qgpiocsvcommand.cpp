#include "qgpiocsvcommand.h"

QGpioCsvCommand::QGpioCsvCommand(QWidget *parent) : QCsvReaderDataNodeWidget("gpiox", parent) {
  // ...
}

void QGpioCsvCommand::transmit_packet() {
  gpiox_t gpiox;

  QList<double> values = _csv_reader->readLine();
  while(values.length() < QGPIOWIDGET_FLOAT_COUNT)
    values.append(0.0);

  QListIterator<double> it(values);
  for(int k=0; k<QGPIOWIDGET_FLOAT_COUNT; k++) {
    gpiox.gpio_float[k] = it.next();
  }

  emit transmit(gpiox);
}
