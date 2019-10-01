#ifndef QCONNECTIONINFODOCK_H
#define QCONNECTIONINFODOCK_H

#include <qrobotwindowdock.h>
#include <qconnectioninfodatanodewidget.h>

class QConnectionInfoDock : public QRobotWindowDock
{
public:
    explicit QConnectionInfoDock(QDataNode *connection, QRobotWindow *window);

protected:
    virtual void showEvent(QShowEvent *);

private:
    QConnectionInfoDataNodeWidget *_connection_info_datanode_widget;

};

#endif // QCONNECTIONINFODOCK_H
