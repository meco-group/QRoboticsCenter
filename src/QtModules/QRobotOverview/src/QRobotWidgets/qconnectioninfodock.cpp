#include "qconnectioninfodock.h"

QConnectionInfoDock::QConnectionInfoDock(QDataNode* connection, QRobotWindow *window) :
    QRobotWindowDock(connection->objectName() + " info", window),
    _connection_info_datanode_widget(new QConnectionInfoDataNodeWidget(this))
{
    _connection_info_datanode_widget->connectTo(connection);
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_connection_info_datanode_widget->w());
    window->addDockWidget(Qt::RightDockWidgetArea, this);
}

void QConnectionInfoDock::showEvent(QShowEvent *)
{
    _connection_info_datanode_widget->connectionInfoWidget()->reset();
}
