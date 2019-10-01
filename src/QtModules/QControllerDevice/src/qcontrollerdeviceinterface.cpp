#include "qcontrollerdeviceinterface.h"

QControllerDeviceInterface::QControllerDeviceInterface(QObject *parent) : QObject(parent)
{

}

QControllerDeviceInterface::controller_state_t QControllerDeviceInterface::getState()
{
    return _state;
}
