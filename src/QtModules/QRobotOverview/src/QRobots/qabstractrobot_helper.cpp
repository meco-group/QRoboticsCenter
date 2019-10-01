#include <qabstractrobot_helper.h>
#include <qcar.h>
#include <qunknownrobot.h>
#include <qballbot.h>
#include <qtiltingtable.h>

QAbstractRobot* construct_from_type(const int id, const int type, QObject* parent) {
    qDebug() << type;
    switch(type) {
        case BALLBOT:
            return new QBallbot(id, parent);
        case SEGBOT:
            //return new segbot()
        case TILTINGTABLE:
            return new QTiltingTable(id, parent);
        case CAR:
            return new QCar(id, parent);
        default:
            return new QUnknownRobot(id, parent);
    }
}
