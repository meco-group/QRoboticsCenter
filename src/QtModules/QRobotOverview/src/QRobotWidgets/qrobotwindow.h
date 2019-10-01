#ifndef QROBOTWINDOW_H
#define QROBOTWINDOW_H

#include <qabstractrobot.h>
class QAbstractRobot;

#include <QStatusBar>
#include <QMenuBar>
#include <QLabel>
#include <qstackedwindow.h>
#include <qgpiodatanodewidget.h>
#include <qrecorderwidget.h>
#include <qcommandwidget.h>

class QThreadingInfoDock;
class QParameterDock;
class QCommandDock;

class QRobotWindow : public QStackedWindow
{
    Q_OBJECT

public:
    explicit QRobotWindow(QAbstractRobot *robot, QWidget *parent = 0);

    QGPIODataNodeWidget *gpio();
    QAbstractRobot *robot();
    QString group();

    virtual void handleNewConnection(QSerialProtocol *connection);

protected:
    QAbstractRobot *_robot;
    QGPIODataNodeWidget *_gpio = new QGPIODataNodeWidget(0);
    QRecorderWidget *_recorder = new QRecorderWidget(0);
    QThreadingInfoDock *_threading_info_dock;
    QParameterDock *_parameter_dock;
    QCommandDock *_command_dock;

    QMenu *_tools_menu;
    QMenu *_connection_menu;
    QMenu *_recorders_menu;

    virtual void showEvent(QShowEvent *);
    virtual void closeEvent(QCloseEvent *);

private slots:
    virtual void activate(bool checked);
    void statusText(QString text);

signals:
    void closing();

};

#endif // QROBOTWINDOW_H
