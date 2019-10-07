#include "qgpiogamepadcommand.h"

QGpioGamepadCommand::QGpioGamepadCommand(QWidget *parent) : QGamepadCommandDataNodeWidget("gpiox", parent) {
  for(int k=0; k<QGPIOWIDGET_FLOAT_COUNT; k++) {
    _fchan[k] = add("float" + QString::number(k));
  }
}

void QGpioGamepadCommand::transmit_packet() {
  gpiox_t gpiox;
  gpiox.time = 0;
  for(int k=0; k<QGPIOWIDGET_FLOAT_COUNT; k++) {
    gpiox.gpio_float[k] = _fchan[k]->value();
  }

  transmit(gpiox);
}
