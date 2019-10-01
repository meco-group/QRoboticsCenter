#include "qrobotwindowdock.h"
#include <qrobotwindow.h>

QRobotWindowDock::QRobotWindowDock(const QString& text, QRobotWindow *window) :
    QDockWidget(text,window), _window(window), _show(new QAction(text,window))
{
    setObjectName(text);
    close();
    QObject::connect(_show, &QAction::triggered, this, &QRobotWindowDock::show);
    QObject::connect(window, &QRobotWindow::closing, this, &QRobotWindowDock::close);
}

QAction *QRobotWindowDock::showAction()
{
    return _show;
}
