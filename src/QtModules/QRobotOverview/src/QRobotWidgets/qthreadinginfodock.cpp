#include "qthreadinginfodock.h"

QThreadingInfoDock::QThreadingInfoDock(QRobotWindow *window) :
    QRobotWindowDock("threading info", window),
    _thread_info_datanode_widget(new QThreadInfoDataNodeWidget(this))
{
    setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);
    setWidget(_thread_info_datanode_widget->w());
    window->addDockWidget(Qt::BottomDockWidgetArea, this);
}

QThreadInfoDataNodeWidget *QThreadingInfoDock::datanode()
{
    return _thread_info_datanode_widget;
}
