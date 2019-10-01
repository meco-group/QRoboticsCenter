#include "qgamepadcommandwidget.h"

QGamepadCommandWidget::QGamepadCommandWidget(QString name, QWidget *parent) :
    QTypeCommandWidget(name,parent),
    _gamepads(new QComboBox())
{
    addWidget(_gamepads);

    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadConnected,this,&QGamepadCommandWidget::gamepadConnected);
    QObject::connect(_gamepads, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &QGamepadCommandWidget::gamepadChanged);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadAxisEvent,this,&QGamepadCommandWidget::axisEvent);
    QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadButtonPressEvent,this,&QGamepadCommandWidget::buttonEvent);
    //QObject::connect(QGamepadManager::instance(),&QGamepadManager::gamepadButtonReleaseEvent,this,&QGamepadInputWidget::buttonEvent);

    QList<int> g = QGamepadManager::instance()->connectedGamepads();
    QListIterator<int> i(g);
    while(i.hasNext()) {
        gamepadConnected(i.next());
    }
}

void QGamepadCommandWidget::setSettingsGroup(QString group)
{
    _settings_group = group;
}

int QGamepadCommandWidget::deviceID(int index)
{
    return _gamepads->itemData(index).toInt();
}

int QGamepadCommandWidget::currentDeviceID()
{
    return deviceID(_gamepads->currentIndex());
}

void QGamepadCommandWidget::saveState(QString group)
{
    _settings_group = group;
    saveState(currentDeviceID());
}

void QGamepadCommandWidget::restoreState(QString group)
{
    _settings_group = group;
    restoreState(currentDeviceID());
}

void QGamepadCommandWidget::saveState(int device_id)
{
    if(!_settings_group.isEmpty()) {
        QListIterator<QTypeCommandInterface *> i(_ports);
        while(i.hasNext()) {
            static_cast<QGamepadCommandDataNodeWidget *>(i.next())->commandWidget()->saveState(_settings_group + "/" + QString::number(device_id));
        }
    } else {
        qDebug() << "not saving state because group is empty";
    }
}

void QGamepadCommandWidget::restoreState(int device_id)
{
    if(!_settings_group.isEmpty()) {
        QListIterator<QTypeCommandInterface *> i(_ports);
        while(i.hasNext()) {
            static_cast<QGamepadCommandDataNodeWidget *>(i.next())->commandWidget()->restoreState(_settings_group + "/" + QString::number(device_id));
        }
    } else {
        qDebug() << "not restoring state because group is empty";
    }
}

void QGamepadCommandWidget::gamepadConnected(int deviceID)
{
    qDebug() << "gamepad connected";
    QGamepad g(deviceID);
    if(g.name().isEmpty()){
        _gamepads->addItem("Gamepad " + QString::number(g.deviceId()),QVariant(deviceID));
    } else {
        _gamepads->addItem(g.name(),QVariant(deviceID));
    }
}

void QGamepadCommandWidget::gamepadChanged()
{
    qDebug() << "gamepad changed";
    saveState(deviceID(_index_copy));
    _index_copy = _gamepads->currentIndex();
    restoreState(deviceID(_index_copy));
}

void QGamepadCommandWidget::axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value)
{
    if(deviceID == currentDeviceID()) {
        QListIterator<QTypeCommandInterface *> i(_ports);
        while(i.hasNext()) {
            static_cast<QGamepadCommandDataNodeWidget *>(i.next())->on_axis_changed(axis,value);
        }
    }
}

void QGamepadCommandWidget::buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value)
{
    qDebug() << "button event: " << button << value;
    //if(deviceID == currentDeviceID())
    //do nothing
}
