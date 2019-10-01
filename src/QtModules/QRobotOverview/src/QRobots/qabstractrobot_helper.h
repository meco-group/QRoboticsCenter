#ifndef QABSTRACTROBOT_HELPER_H
#define QABSTRACTROBOT_HELPER_H

#include <qabstractrobot.h>

QAbstractRobot* construct_from_type(const int id, const int type, QObject* parent = 0);

#endif // QABSTRACTROBOT_HELPER_H
