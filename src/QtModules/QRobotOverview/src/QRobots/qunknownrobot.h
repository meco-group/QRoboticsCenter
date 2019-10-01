#ifndef QUNKNOWNROBOT_H
#define QUNKNOWNROBOT_H

#include <qabstractrobot.h>

class QUnknownRobot : public QAbstractRobot
{
    Q_OBJECT

public:
    QUnknownRobot(const int id, QObject* parent = 0);

    virtual QIcon icon();
    virtual QRobotWindow *window();

private:
    QRobotWindow *_window = new QRobotWindow(this);

};

#endif // QUNKNOWNROBOT_H
