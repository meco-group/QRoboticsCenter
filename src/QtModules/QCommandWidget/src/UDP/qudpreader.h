#ifndef QUDPREADER_H
#define QUDPREADER_H

#include <QObject>
#include <QUdpSocket>

class QUdpReader : public QObject{
    Q_OBJECT

public:
    explicit QUdpReader(const int line_size, QObject *parent = 0);

    quint16 getPort();
    QUdpSocket* getSocket();
    void reset();

    QByteArray readLine();
    quint64 linesRead();

private:
    QUdpSocket* _socket;
    quint16 _port;
    static quint16 _next_port;

    const int _line_size;
    quint64 _lines_read;

public slots:
    void setPort(quint16 port);

};

#endif // QUDPREADER_H
