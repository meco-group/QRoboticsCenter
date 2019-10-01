#include "qabstractrobot.h"

#include <qrobotwindow.h>

QAbstractRobot::QAbstractRobot(const int id, const QString type, QObject *parent) :
    QObject(parent),
    _id(id),
    _type(type),
    _log(new QPrintLog(this))
{
    setObjectName(_type + QString::number(_id));

    // setup log
    _log->open(objectName());
}

int QAbstractRobot::id()
{
    return _id;
}

QString QAbstractRobot::type()
{
    return _type;
}

QList<QSerialProtocol *> QAbstractRobot::connections()
{
    return _connections;
}

void QAbstractRobot::connectTo(QDataNode *datanode)
{
    QListIterator<QSerialProtocol*> i(_connections);
    while(i.hasNext())
        i.next()->connectTo(datanode);
}

void QAbstractRobot::addConnection(QSerialProtocol *connection)
{
    _connections.append(connection);
    window()->handleNewConnection(connection);
    //connect what needs to be connected!
    connection->transmitTo(_log);
}

QPrintLog *QAbstractRobot::getLog()
{
    return _log;
}
