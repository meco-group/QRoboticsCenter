#ifndef QCONTROLLERDEVICEINTERFACE_H
#define QCONTROLLERDEVICEINTERFACE_H

#include <QObject>

class QControllerDeviceInterface : public QObject
{
    Q_OBJECT
public:
    explicit QControllerDeviceInterface(QObject *parent = 0);

    typedef struct controller_state_t {
        double axisLeftX;
        double axisLeftY;
        double axisRightX;
        double axisRightY;
        bool buttonL1;
        double buttonL2;
        bool buttonL3;
        bool buttonR1;
        double buttonR2;
        bool buttonR3;
        bool buttonA;
        bool buttonB;
        bool buttonX;
        bool buttonY;
        bool buttonLeft;
        bool buttonRight;
        bool buttonUp;
        bool buttonDown;
    } controller_state_t;

    typedef struct robot_move_cmd_t{
        double x;
        double y;
        double z;
    } robot_move_cmd_t;

    typedef enum action_cmd_t {
        TOGGLE_RECORD
    } action_cmd_t;

    controller_state_t getState();
    virtual bool connected() = 0;

protected:
    controller_state_t _state;

public slots:
    virtual void start() = 0;

signals:
    void axisStateChanged(int id, double value);
    void buttonStateChanged(int id, bool value);

    void switchNextRobot();
    void switchPrevRobot();
    void toggleRecorder();
    void moveCmdChanged(QControllerDeviceInterface::robot_move_cmd_t move);
    void actionCmdChanged(QControllerDeviceInterface::action_cmd_t action);

};

Q_DECLARE_METATYPE(QControllerDeviceInterface::robot_move_cmd_t)
Q_DECLARE_METATYPE(QControllerDeviceInterface::action_cmd_t)

#endif // QCONTROLLERDEVICEINTERFACE_H
