#ifndef QCOMMANDDOCK_H
#define QCOMMANDDOCK_H

#include <qrobotwindowdock.h>
#include <qrobotcommandwidget.h>

class QCommandDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QCommandDock(QRobotWindow *window);
    QRobotCommandWidget *datanode();

protected:
    virtual void showEvent(QShowEvent *);
    virtual void closeEvent(QCloseEvent *);

private:
    QRobotCommandWidget *_command_widget;

};

#endif // QCOMMANDDOCK_H
