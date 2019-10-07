#include "qrobotwindow.h"

#include <qabstractrobot.h>
#include <qthreadinginfodock.h>
#include <qconnectioninfodock.h>
#include <qparameterdock.h>
#include <qcommanddock.h>
#include <qgpiorecorder.h>
#include <qrobotcommandwidget.h>

QRobotWindow::QRobotWindow(QAbstractRobot *robot, QWidget *parent) :
    QStackedWindow(parent), _robot(robot)
{
    // Set object name
    setObjectName(robot->type() + QString::number(robot->id()) + "_window");
    setWindowTitle(robot->objectName());
    //setWindowIcon(robot->icon());

    addView(_gpiox->w());
    menuBar()->setNativeMenuBar(false); // Set menubar not native as it causes command tab not to be displayed

    // Setup threading
    _tools_menu = menuBar()->addMenu("Tools");
    _threading_info_dock = new QThreadingInfoDock(this);
    _tools_menu->addAction(_threading_info_dock->showAction());
    _parameter_dock = new QParameterDock(this);
    _tools_menu->addAction(_parameter_dock->showAction());

    // Setup connections
    _connection_menu = menuBar()->addMenu("Connections");

    // Setup recorders
    _recorders_menu = _recorder->menu();
    menuBar()->addMenu(_recorders_menu);
    statusBar()->addPermanentWidget(_recorder);
    QGPIORecorder *rec = new QGPIORecorder(_gpiox->gpiow(), this);
    _recorder->add(rec);
    _recorder->setQuickRecord(rec);

    // Add command action
    _command_dock = new QCommandDock(this);
    menuBar()->addAction(_command_dock->showAction());

    // Add activate action
    QAction *activate = new QAction("activate",this);
    activate->setShortcut(Qt::CTRL + Qt::Key_X);
    activate->setCheckable(true);
    this->addAction(activate);
    QObject::connect(activate, &QAction::toggled, this, &QRobotWindow::activate);
    activate->setChecked(true);

    // String stitcher
    QObject::connect(_robot->getLog(), &QPrintLog::newline, this, &QRobotWindow::statusText);
}

void QRobotWindow::handleNewConnection(QSerialProtocol *connection)
{
    _gpiox->connectTo(connection);
    _recorder->connectTo(connection);
    _threading_info_dock->datanode()->connectTo(connection);
    _parameter_dock->datanode()->connectTo(connection);
    _command_dock->datanode()->transmitTo(connection);

    QMenu *m = _connection_menu->addMenu(connection->objectName());
    QConnectionInfoDock *connection_info_dock = new QConnectionInfoDock(connection,this);
    m->addAction(connection_info_dock->showAction());
    m->addAction(connection->getActivateAction());
}

void QRobotWindow::activate(bool checked)
{
    setStackEnabled(checked);
    QListIterator<QSerialProtocol*> i(_robot->connections());
    while(i.hasNext())
        i.next()->getActivateAction()->setChecked(checked);
}

void QRobotWindow::statusText(QString text)
{
    statusBar()->showMessage(text, 5000);
}

QGPIODataNodeWidget *QRobotWindow::gpiox()
{
    return _gpiox;
}

QAbstractRobot *QRobotWindow::robot()
{
    return _robot;
}

QString QRobotWindow::group()
{
    return _robot->objectName();
}

void QRobotWindow::showEvent(QShowEvent *)
{
    QSettings settings;
    settings.beginGroup(group());
    restoreGeometry(settings.value("geometry").toByteArray());
    QMainWindow::restoreState(settings.value("windowState").toByteArray());
    settings.endGroup();

    _gpiox->restoreState(group());
}

void QRobotWindow::closeEvent(QCloseEvent *)
{
    if(isVisible()) {
        QSettings settings;
        settings.beginGroup(group());
        settings.setValue("geometry", saveGeometry());
        settings.setValue("windowState", saveState());
        settings.endGroup();

        _gpiox->saveState(group());

        emit closing();
    }
}
