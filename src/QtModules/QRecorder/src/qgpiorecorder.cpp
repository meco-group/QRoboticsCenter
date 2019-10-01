#include "qgpiorecorder.h"

QGPIORecorder::QGPIORecorder(QGPIOWidget *gpio, QObject *parent) :
    QAbstractRecorder("GPIO", LOG_GPIO, parent),
    _gpio(gpio)
{

}

QString QGPIORecorder::insertHeader()
{
    QString header;

    // Labels
    header += "\t<labels>\n";
    header += "\t\t<value>time</value>\n";
    QStringList labels = _gpio->getLabels();
    for(int k=0;k<labels.length();k++){
        header += "\t\t<value>" + labels[k] + "</value>\n";
    }
    header += "\t</labels>\n";

    return header;
}

void QGPIORecorder::receive(gpio_t gpio)
{
    if (isRecording()) {
        int k;

        QString line = "\t\t<row>";
        line += QString::number(gpio.time);

        for(k=0;k<8;k++){
            line +=  "\t" + QString::number(gpio.gpio_float[k]);
        }

        for(k=0;k<4;k++){
           line +=  "\t" + QString::number(gpio.gpio_int[k]);
        }

        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}
