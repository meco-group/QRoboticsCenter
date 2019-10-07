#ifndef QGPIORECORDER_H
#define QGPIORECORDER_H

#include <qabstractrecorder.h>
#include <qrobotwindow.h>

class QGPIORecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QGPIORecorder(QGPIOWidget *gpiox, QObject* parent = 0);

private:
    QGPIOWidget* _gpiox;

    virtual QString insertHeader();

public slots:
    virtual void receive(gpiox_t gpiox);

};

#endif // QGPIORECORDER_H
