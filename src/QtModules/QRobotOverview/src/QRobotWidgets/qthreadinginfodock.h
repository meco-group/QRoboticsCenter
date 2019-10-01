#ifndef QTHREADINGINFODOCK_H
#define QTHREADINGINFODOCK_H

#include <qrobotwindowdock.h>
#include <qthreadinfodatanodewidget.h>

class QThreadingInfoDock : public QRobotWindowDock
{
public:
    explicit QThreadingInfoDock(QRobotWindow *window);
    QThreadInfoDataNodeWidget *datanode();

private:
    QThreadInfoDataNodeWidget *_thread_info_datanode_widget;

};

#endif // QTHREADINGINFODOCK_H
