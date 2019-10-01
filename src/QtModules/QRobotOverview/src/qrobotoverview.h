#ifndef QROBOTOVERVIEW_H
#define QROBOTOVERVIEW_H

#include <QWidget>
#include <QVBoxLayout>

#include <qserialprotocol.h>
#include <qabstractrobot_helper.h>
#include <qrobotbutton.h>

class QRobotOverview : public QWidget
{
    Q_OBJECT

public:
    explicit QRobotOverview(QWidget *parent = 0);

    int findRobot(int id) const;

protected:
    virtual void closeEvent(QCloseEvent *);

private:
    QList<QAbstractRobot*> _robots;

public slots:
    QAbstractRobot *addRobot(QAbstractRobot* robot);
    QAbstractRobot *addRobot(int id, int type);
    QAbstractRobot *addConnection(QSerialProtocol* connection);

};

#endif // QROBOTOVERVIEW_H
