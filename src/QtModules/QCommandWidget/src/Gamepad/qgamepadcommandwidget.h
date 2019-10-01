#ifndef QGAMEPADINPUTWIDGET_H
#define QGAMEPADINPUTWIDGET_H

#include <QGamepad>
#include <QGamepadManager>
#include <QComboBox>
#include <qtypecommandwidget.h>
#include <qgamepadcommanddatanodewidget.h>

/*TODO: avoid up and downcasting from QTypeCommandInterface to QGamepadCommandDataNodeWidget */

class QGamepadCommandWidget : public QTypeCommandWidget
{
public:
    QGamepadCommandWidget(QString name, QWidget *parent = 0);

    void setSettingsGroup(QString group);
    void saveState(QString group);
    void restoreState(QString group);

private:
    QComboBox *_gamepads;
    int _index_copy = -1;
    QString _settings_group = "";

    int deviceID(int index);
    int currentDeviceID();

    void saveState(int device_id);
    void restoreState(int device_id);

public slots:
    void gamepadConnected(int deviceID);
    void gamepadChanged();
    void axisEvent(int deviceID, QGamepadManager::GamepadAxis axis, double value);
    void buttonEvent(int deviceID, QGamepadManager::GamepadButton button, double value);

};

#endif // QGAMEPADINPUTWIDGET_H
