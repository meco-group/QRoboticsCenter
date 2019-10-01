#ifndef QTRUSTMASTER_H
#define QTRUSTMASTER_H

#include <qcontrollerdeviceinterface.h>
#include <QDebug>

#define CONSOLE_DATA_TYPE_BUTTON   0x01
#define CONSOLE_DATA_TYPE_AXIS     0x02
#define CONSOLE_DATA_TYPE_INIT     0x80

#define SIZE_OF_CONSOLE_DATA_T  8
typedef struct console_data_t {
  u_int32_t time;   /* event timestamp in milliseconds */
  int16_t value;    /* value */
  u_int8_t type;    /* event type */
  u_int8_t number;  /* axis/button number */
} console_data_t;

class QTrustMaster : public QControllerDeviceInterface
{
public:
    QTrustMaster(QObject *parent = 0);
    bool connected();
    void start();

private:
    int _fd;
    bool _connected;

    const static int AXIS_LEFT_X = 0;
    const static int AXIS_LEFT_Y = 1;
    const static int AXIS_RIGHT_X = 2;
    const static int AXIS_RIGHT_Y = 3;

    const static int BUTTON_L1 = 4;
    const static int BUTTON_L2 = 5;
    const static int BUTTON_L3 = 8;
    const static int BUTTON_R1 = 6;
    const static int BUTTON_R2 = 7;
    const static int BUTTON_R3 = 9;
    const static int BUTTON_A = 0;
    const static int BUTTON_B = 2;
    const static int BUTTON_X = 1;
    const static int BUTTON_Y = 3;

    QControllerDeviceInterface::robot_move_cmd_t getRobotMoveCmd();
    void setControllerState(console_data_t data);

    void mapButtons(int id, bool value);
    void mapAxes(int id, double value);

protected:
    void timerEvent(QTimerEvent *);

};

#endif // QTRUSTMASTER_H
