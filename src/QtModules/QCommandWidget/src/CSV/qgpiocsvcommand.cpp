#include "qgpiocsvcommand.h"

QGpioCsvCommand::QGpioCsvCommand(QWidget *parent) :
    QCsvReaderDataNodeWidget("gpio",parent)
{

}

void QGpioCsvCommand::transmit_packet()
{
    int k = 0;
    gpio_t gpio;

    QList<double> values = _csv_reader->readLine();
    while(values.length() < 12)
        values.append(0.0);

    QListIterator<double> i(values);
    for(k=0;k<8;k++){
        gpio.gpio_float[k] = i.next();
    }
    for(k=0;k<4;k++){
        gpio.gpio_int[k] = i.next();
    }

    emit transmit(gpio);
}
