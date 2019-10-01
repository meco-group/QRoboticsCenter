#ifndef QABSTRACTROBOT_H
#define QABSTRACTROBOT_H

#include <QObject>
#include <QIcon>
#include <qserialprotocol.h>
#include <qprintlog.h>

#include <qrobotwindow.h>
class QRobotWindow;

class QAbstractRobot : public QObject
{
    Q_OBJECT

public:
    explicit QAbstractRobot(const int id, const QString type, QObject *parent = 0);

    virtual QIcon icon() = 0;
    virtual QRobotWindow *window() = 0;

    int id();
    QString type();
    QList<QSerialProtocol *> connections();
    QPrintLog *getLog();

    void connectTo(QDataNode *datanode);

private:
    const int _id;
    const QString _type;
    QList<QSerialProtocol*> _connections;
    QPrintLog* _log;

public slots:
    void addConnection(QSerialProtocol *connection);

};

#endif // QABSTRACTROBOT_H
