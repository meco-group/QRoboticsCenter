#ifndef QROBOTBUTTON_H
#define QROBOTBUTTON_H

#include <QObject>
#include <qpushbutton.h>
#include <qstylepainter.h>
#include <QStyleOptionButton>
#include <qabstractrobot.h>

class QRobotButton : public QPushButton
{
    Q_OBJECT

public:
    explicit QRobotButton(QAbstractRobot* robot, QWidget *parent = 0);

protected:
    virtual void paintEvent(QPaintEvent *);

private:
    const static size_t _icon_size = 60;
    const int _id;

};

#endif // QROBOTBUTTON_H
