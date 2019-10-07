#ifndef QTUDPSENDER_H
#define QTUDPSENDER_H

#include <qsenderinterface.h>
#include <QUdpSocket>
#include <qudpsenderwidget.h>
#include <mavlink.h>

template <typename T> class QTUdpSender : public QSenderInterface
{
public:
    QTUdpSender(QString name, QWidget *parent = 0) :
        _socket(new QUdpSocket(parent)),
        _widget(new QUdpSenderWidget(name, parent)),
        _counter(0)
    {

    }

    void sendPacket(T packet){
        _socket->writeDatagram((char*)(&packet), sizeof(T), QHostAddress::LocalHost, _widget->port());
    }

    virtual void sendPacket(QVariant packet){
        if(packet.userType() == qMetaTypeId<T>()){
            sendPacket(packet.value<T>());
            _widget->setCount(++_counter);
        }
    }

    virtual void sendPackets(QList<QVariant> packets){
        QListIterator<QVariant> i(packets);
        while(i.hasNext())
            sendPacket(i.next());
    }

    virtual QWidget* getWidget(){
        return _widget;
    }

    virtual bool enabled(){
        return _widget->enabled();
    }

    virtual void reset(){
        _widget->reset();
        _counter = 0;
    }

private:
    QUdpSocket* _socket;
    QUdpSenderWidget* _widget;
    unsigned int _counter;

};

class QGpioUdpSender: public QTUdpSender<gpiox_t>{
public:
    QGpioUdpSender(QWidget *parent) :
        QTUdpSender<gpiox_t>("gpiox", parent)
    {}
};

#endif // QTUDPSENDER_H
