#ifndef QCAR_H
#define QCAR_H

#include <qabstractrobot.h>

class QCar : public QAbstractRobot
{
    Q_OBJECT

public:
    explicit QCar(const int id, QObject* parent = 0);

    virtual QIcon icon();
    virtual QRobotWindow* window();

private:
    QRobotWindow *_window = new QRobotWindow(this);

};

#endif // QCAR_H
