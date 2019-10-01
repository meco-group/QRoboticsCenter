#ifndef QTILTINGTABLE_H
#define QTILTINGTABLE_H

#include <qbalancingrobot.h>

class QTiltingTable : public QBalancingRobot
{
    Q_OBJECT

public:
    explicit QTiltingTable(int id, QObject *parent = 0);
    //void setup();

    virtual QIcon icon();
};

#endif // QTILTINGTABLE_H
