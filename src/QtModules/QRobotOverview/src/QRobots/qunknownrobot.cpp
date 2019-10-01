#include "qunknownrobot.h"

QUnknownRobot::QUnknownRobot(const int id, QObject *parent) :
    QAbstractRobot(id,"unknown",parent)
{
    //do nothing
}

QIcon QUnknownRobot::icon()
{
    return QIcon(":/robot_icons/unknown.png");
}

QRobotWindow *QUnknownRobot::window()
{
    return _window;
}
