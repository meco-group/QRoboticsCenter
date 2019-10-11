#include "qudpreader.h"

quint16 QUdpReader::_next_port = 27500;

QUdpReader::QUdpReader(const int line_size, QObject *parent) :
    QObject(parent),
    _socket(new QUdpSocket(this)),
    _line_size(line_size),
    _lines_read(0)
{
    _socket->bind(_next_port);
    _port = _next_port;
    _next_port++;
}

void QUdpReader::setPort(quint16 port)
{
    _port = port;
    _socket->close();
    if(!(_socket->state() == QAbstractSocket::UnconnectedState || _socket->waitForDisconnected(1000))){
        qDebug() << "UDP error:" << _socket->errorString();
    }
    _socket->bind(_port);
}

quint16 QUdpReader::getPort()
{
    return _port;
}

QUdpSocket *QUdpReader::getSocket()
{
    return _socket;
}

void QUdpReader::reset()
{
    setPort(_port);
    _lines_read = 0;
}

QByteArray QUdpReader::readLine()
{
    QByteArray bytes = QByteArray(0);
    int t_lines_read = 0;
    if(_socket->state() == QAbstractSocket::BoundState){
        while(_socket->hasPendingDatagrams()){
            bytes.resize(_line_size);
            _socket->readDatagram(bytes.data(),bytes.size());
            t_lines_read++;
        }
        _lines_read++;
    } else {
        qDebug() << "Socket state: " << _socket->state();
    }

    return bytes;
}

quint64 QUdpReader::linesRead()
{
    return _lines_read;
}
