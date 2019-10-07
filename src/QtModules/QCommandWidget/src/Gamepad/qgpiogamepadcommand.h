#ifndef QGPIOGAMEPADCOMMAND_H
#define QGPIOGAMEPADCOMMAND_H

#include <qgpiowidget.h>
#include <qgamepadcommanddatanodewidget.h>

class QGpioGamepadCommand : public QGamepadCommandDataNodeWidget
{
    Q_OBJECT

public:
    explicit QGpioGamepadCommand(QWidget *parent = 0);
    virtual void transmit_packet();

private:
    QGamepadEntry* _fchan[QGPIOWIDGET_FLOAT_COUNT];

};

#endif // QGPIOGAMEPADCOMMAND_H
