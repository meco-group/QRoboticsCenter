#ifndef QTYPEUDPCOMMAND_H
#define QTYPEUDPCOMMAND_H

#include <qtypecommandinterface.h>
#include <qudpreaderwidget.h>

template <typename T> class QTypeUdpCommand : public QTypeCommandInterface
{
public:
    QTypeUdpCommand(const QString& name, QWidget* parent = 0):
        QTypeCommandInterface(parent),
        _udp_reader(new QUdpReaderWidget(sizeof(T), name, parent))
    {

    }

    virtual void transmit_packet(){
        QByteArray line = _udp_reader->readLine();
        if(line.size() > 0) {
            T* t = reinterpret_cast<T*>(line.data());
            emit transmit(*t);
        } else {
            qDebug() << "UDP: no data received";
        }
    }

    virtual QWidget *w() {
        return _udp_reader;
    }

    virtual bool enabled(){
        return _udp_reader->enabled();
    }

    virtual void reset(){
        _udp_reader->getUdpReader()->reset();
    }

    virtual void saveState(QString group) {
        _udp_reader->saveState(group);
    }

    virtual void restoreState(QString group) {
        _udp_reader->restoreState(group);
    }

private:
    QUdpReaderWidget* _udp_reader;

};

class QGpioUdpCommand: public QTypeUdpCommand<gpio_t>{
public:
    QGpioUdpCommand(QWidget *parent) :
        QTypeUdpCommand<gpio_t>("gpio",parent)
    {}
};

class QPositionCmdUdpCommand: public QTypeUdpCommand<position_cmd_t>{
public:
    QPositionCmdUdpCommand(QWidget *parent) :
        QTypeUdpCommand<position_cmd_t>("position cmd",parent)
    {}
};

#endif // QTYPEUDPCOMMAND_H
