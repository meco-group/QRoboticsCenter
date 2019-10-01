#include "qbalancingrobot.h"

QBalancingRobot::QBalancingRobot(const int id, const QString type, QObject *parent):
    QAbstractRobot(id,type,parent)
{
    // do nothing
}

QRobotWindow *QBalancingRobot::window()
{
    return _window;
}

QBalancingWindow *QBalancingRobot::balancingWindow()
{
    return _window;
}
