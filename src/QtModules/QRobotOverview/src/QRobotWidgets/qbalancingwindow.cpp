#include "qbalancingwindow.h"
#include <qattituderecorder.h>
#include <qvelocityrecorder.h>
#include <qpositionrecorder.h>
#include <qvelocitygamepadcommand.h>

QBalancingWindow::QBalancingWindow(QAbstractRobot *robot, QWidget *parent) :
    QRobotWindow(robot, parent),
    _balance(new QBalancingDataNodeWidget(this))
{
    addView(_balance->w());

    _excitation_dock = new QExcitationDock(this);
    _tools_menu->addAction(_excitation_dock->showAction());
    _recorder->add(new QAttitudeRecorder(this));
    _recorder->add(new QVelocityRecorder(this));
    _recorder->add(new QPositionRecorder(this));

    QGamepadCommandWidget *g = _command_dock->datanode()->gamepad();
    g->add(new QVelocityGamepadCommand(g));
}

QBalancingDataNodeWidget *QBalancingWindow::balance()
{
    return _balance;
}

void QBalancingWindow::handleNewConnection(QSerialProtocol *connection)
{
    QRobotWindow::handleNewConnection(connection);
    connection->connectTo(_balance);
    _excitation_dock->datanode()->transmitTo(connection);
}
