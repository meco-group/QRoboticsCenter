#include "qcommanddock.h"

QCommandDock::QCommandDock(QRobotWindow *window) :
    QRobotWindowDock("commands", window)
{
    _command_widget = new QRobotCommandWidget(0);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_command_widget);
    window->addDockWidget(Qt::RightDockWidgetArea, this);
}

QRobotCommandWidget *QCommandDock::datanode()
{
    return _command_widget;
}

void QCommandDock::showEvent(QShowEvent *)
{
    _command_widget->restoreState(_window->group());
}

void QCommandDock::closeEvent(QCloseEvent *)
{
    _command_widget->saveState(_window->group());
}
