#ifndef QVELOCITYGAMEPADCOMMAND_H
#define QVELOCITYGAMEPADCOMMAND_H

#include <qgamepadcommanddatanodewidget.h>

class QVelocityGamepadCommand : public QGamepadCommandDataNodeWidget
{
public:
    QVelocityGamepadCommand(QWidget *parent = 0);
    virtual void transmit_packet();

private:
    QGamepadEntry *_vx;
    QGamepadEntry *_vy;
    QGamepadEntry *_vz;

};

#endif // QVELOCITYGAMEPADCOMMAND_H
