#include "qvelocitygamepadcommand.h"

QVelocityGamepadCommand::QVelocityGamepadCommand(QWidget *parent) :
    QGamepadCommandDataNodeWidget("Velocity",parent)
{
    _vx = add("vx");
    _vy = add("vy");
    _vz = add("vz");
}

void QVelocityGamepadCommand::transmit_packet()
{
    velocity_cmd_t velocity_cmd;
    velocity_cmd.vx = _vx->value();
    velocity_cmd.vy = _vy->value();
    velocity_cmd.vz = _vz->value();
    velocity_cmd.vxFF = 0;
    velocity_cmd.vyFF = 0;
    velocity_cmd.vzFF = 0;

    transmit(velocity_cmd);
}
