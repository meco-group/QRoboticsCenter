#include "qrobotcommandwidget.h"

QRobotCommandWidget::QRobotCommandWidget(QWidget *parent) :
    QCommandWidget(parent),
    _csv(new QTypeCommandWidget("CSV",this)),
    _udp(new QTypeCommandWidget("UDP",this)),
    _gamepad(new QGamepadCommandWidget("Gamepad",this))
{
    add(_csv);
    add(_udp);
    add(_gamepad);
    _csv->add(new QGpioCsvCommand(_csv));
    _udp->add(new QGpioUdpCommand(_udp));
    _gamepad->add(new QGpioGamepadCommand(_gamepad));
}
