#include "qgpiogamepadcommand.h"

QGpioGamepadCommand::QGpioGamepadCommand(QWidget *parent) :
    QGamepadCommandDataNodeWidget("Gpio",parent)
{
    for(int k=0; k<8; k++) {
        _fchan[k] = add("float" + QString::number(k));
    }
    for(int k=0; k<4; k++) {
        _ichan[k] = add("int" + QString::number(k));
    }
}

void QGpioGamepadCommand::transmit_packet()
{
    gpio_t gpio;
    gpio.time = 0;
    for(int k=0; k<8; k++) {
        gpio.gpio_float[k] = _fchan[k]->value();
    }
    for(int k=0; k<4; k++) {
        gpio.gpio_int[k] = _ichan[k]->value();
    }

    transmit(gpio);
}
