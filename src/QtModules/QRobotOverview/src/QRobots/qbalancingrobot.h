#ifndef QBALANCINGROBOT_H
#define QBALANCINGROBOT_H

#include <qabstractrobot.h>
#include <qbalancingwindow.h>

class QBalancingRobot : public QAbstractRobot
{
    Q_OBJECT

public:
    explicit QBalancingRobot(const int id, const QString type, QObject* parent = 0);

    virtual QIcon icon() = 0;
    virtual QRobotWindow *window();
    QBalancingWindow *balancingWindow();

private:
    QBalancingWindow *_window = new QBalancingWindow(this);

};

#endif // QBALANCINGROBOT_H
