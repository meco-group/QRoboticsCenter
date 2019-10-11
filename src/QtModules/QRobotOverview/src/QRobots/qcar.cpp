#include "qcar.h"

QCar::QCar(const int id, QObject *parent) : QAbstractRobot(id, "car", parent) { }

QIcon QCar::icon() {
  return QIcon(":/robot_icons/car.png");
}

QRobotWindow *QCar::window() {
  return _window;
}
