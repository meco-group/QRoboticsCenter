#include "qrobotoverview.h"
#include <qrobotwindow.h>

QRobotOverview::QRobotOverview(QWidget *parent) : QWidget(parent) {
  setLayout(new QVBoxLayout(this));
  setMinimumWidth(250);
  // setMinimumHeight(100);

  // show a spinner while searching for a mavlink connection
  _spinner = new WaitingSpinnerWidget(this, false);
  _spinner->setRoundness(100.0);
  _spinner->start();
  layout()->addWidget(_spinner);
  layout()->setAlignment(_spinner, Qt::AlignHCenter);

  // show text indicating the exploration of connections
  QLabel *label = new QLabel(this);
  label->setText("Checking for connection ...");
  layout()->addWidget(label);
  layout()->setAlignment(label, Qt::AlignHCenter);
  QObject::connect(_spinner, &WaitingSpinnerWidget::stopped, label, &QLabel::hide);
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
