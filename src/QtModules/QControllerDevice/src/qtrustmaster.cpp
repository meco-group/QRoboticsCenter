#include "qtrustmaster.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <fcntl.h>

QTrustMaster::QTrustMaster(QObject* parent) :  QControllerDeviceInterface(parent), _fd(0)
{
    _connected = false;
    _state.axisLeftX = 0.0;
    _state.axisLeftY = 0.0;
    _state.axisRightX = 0.0;
}

bool QTrustMaster::connected()
{
    return _connected;
}

void QTrustMaster::start()
{
    _fd = ::open("/dev/input/js0", O_RDONLY|O_NONBLOCK);
    if(_fd <= 0){
        qDebug() << "Error when connecting Trustmaster.";
        _connected = false;
    } else {
        read(_fd,NULL,SSIZE_MAX); //flush all data
        startTimer(50);
        _connected = true;
    }
}

QControllerDeviceInterface::robot_move_cmd_t QTrustMaster::getRobotMoveCmd()
{
    robot_move_cmd_t cmd;

    cmd.x = _state.axisRightX;
    cmd.y = _state.axisRightY;
    cmd.z = _state.axisLeftX;

    return cmd;
}

void QTrustMaster::setControllerState(console_data_t data)
{
    data.type &= ~CONSOLE_DATA_TYPE_INIT;
    switch(data.type){
        case CONSOLE_DATA_TYPE_BUTTON:{
            emit buttonStateChanged(data.number,data.value);
            mapButtons(data.number,data.value);
            break;
        }
        case CONSOLE_DATA_TYPE_AXIS:{
            emit axisStateChanged(data.number,data.value);
            mapAxes(data.number,data.value*0.000030519);
            break;
        }
    }
}

void QTrustMaster::mapButtons(int id, bool value)
{
    switch(id){
    case BUTTON_L1:
        _state.buttonL1 = value;
        if(value)
            emit switchPrevRobot();
        break;
    case BUTTON_L2:
        _state.buttonL2 = value;
        break;
    case BUTTON_L3:
        _state.buttonL3 = value;
        break;
    case BUTTON_R1:
        _state.buttonR1 = value;
        if(value)
            emit switchNextRobot();
        break;
    case BUTTON_R2:
        _state.buttonR2 = value;
        break;
    case BUTTON_R3:
        _state.buttonR3 = value;
        break;
    case BUTTON_A:
        _state.buttonA = value;
        if(value)
            emit toggleRecorder();
        break;
    }
}

void QTrustMaster::mapAxes(int id, double value)
{
    switch(id){
    case AXIS_LEFT_X:
        _state.axisLeftX = value;
        break;
    case AXIS_LEFT_Y:
        _state.axisLeftY = value;
        break;
    case AXIS_RIGHT_X:
        _state.axisRightX = value;
        break;
    case AXIS_RIGHT_Y:
        _state.axisRightY = value;
        break;
    }
}

void QTrustMaster::timerEvent(QTimerEvent*)
{
    console_data_t console_data;
    int bytes_read;

    do {
        bytes_read = read(_fd,(char*)(&console_data),SIZE_OF_CONSOLE_DATA_T);
        if(bytes_read == SIZE_OF_CONSOLE_DATA_T){ //redundant test..
            setControllerState(console_data);
        }
    } while(bytes_read >= SIZE_OF_CONSOLE_DATA_T);

    emit moveCmdChanged(getRobotMoveCmd());
}
