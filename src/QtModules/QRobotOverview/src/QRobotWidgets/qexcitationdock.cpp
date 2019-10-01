#include "qexcitationdock.h"

QExcitationDock::QExcitationDock(QRobotWindow *window) :
    QRobotWindowDock("excitation", window), _excitation_widget(new QExcitationWidget(this))
{
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_excitation_widget);
    window->addDockWidget(Qt::RightDockWidgetArea, this);
}

QExcitationWidget *QExcitationDock::datanode()
{
    return _excitation_widget;
}
