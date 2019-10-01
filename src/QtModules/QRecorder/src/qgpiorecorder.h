#ifndef QGPIORECORDER_H
#define QGPIORECORDER_H

#include <qabstractrecorder.h>
#include <qrobotwindow.h>

class QGPIORecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QGPIORecorder(QGPIOWidget *gpio, QObject* parent = 0);

private:
    QGPIOWidget* _gpio;

    virtual QString insertHeader();

public slots:
    virtual void receive(gpio_t gpio);

};

#endif // QGPIORECORDER_H
