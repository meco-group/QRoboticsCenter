#ifndef QGPIOGAMEPADCOMMAND_H
#define QGPIOGAMEPADCOMMAND_H

#include <qgamepadcommanddatanodewidget.h>

class QGpioGamepadCommand : public QGamepadCommandDataNodeWidget
{
    Q_OBJECT

public:
    explicit QGpioGamepadCommand(QWidget *parent = 0);
    virtual void transmit_packet();

private:
    QGamepadEntry* _fchan[8];
    QGamepadEntry* _ichan[4];

};

#endif // QGPIOGAMEPADCOMMAND_H
