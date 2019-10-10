#include "qrobotoverview.h"
#include <qrobotwindow.h>

QRobotOverview::QRobotOverview(QWidget *parent) : QWidget(parent) {
  setLayout(new QVBoxLayout(this));
  setMinimumWidth(250);

  // show a spinner while searching for a mavlink connection
  _spinner = new WaitingSpinnerWidget(this);
  // _spinner->setRoundness(70.0);
  // _spinner->setMinimumTrailOpacity(15.0);
  // _spinner->setTrailFadePercentage(70.0);
  // _spinner->setNumberOfLines(12);
  // _spinner->setLineLength(10);
  // _spinner->setLineWidth(5);
  // _spinner->setInnerRadius(10);
  // _spinner->setRevolutionsPerSecond(1);
  // spinner->setColor(QColor(81, 4, 71));
  _spinner->start(); // gets the show on the road!
}

int QRobotOverview::findRobot(int id) const {
  int index;
  for(index=0; index<_robots.size(); index++) {
    if(_robots[index]->id() == id) {
      return index;
    }
  }

  return -1;
}

void QRobotOverview::closeEvent(QCloseEvent *) {
  QListIterator<QAbstractRobot *> i(_robots);
  while(i.hasNext()) {
    i.next()->window()->close();
  }
}

QAbstractRobot *QRobotOverview::addRobot(QAbstractRobot *robot) {
  int index = findRobot(robot->id());
  if(index < 0) {
    _robots.append(robot);
    robot->setParent(this);
    QRobotButton *b = new QRobotButton(robot, this);
    layout()->addWidget(b);
    QObject::connect(b,&QRobotButton::clicked,robot->window(), &QRobotWindow::show);
    _spinner->stop();
  }

  return robot;
}

QAbstractRobot* QRobotOverview::addRobot(int id, int type) {
  QAbstractRobot* robot = construct_from_type(id, type, this);
  return addRobot(robot);
}

QAbstractRobot *QRobotOverview::addConnection(QSerialProtocol *connection) {
  QAbstractRobot* robot = addRobot(connection->transmitterID(), connection->transmitterType());
  robot->addConnection(connection);
  return robot;
}
