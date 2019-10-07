#include "qgpiorecorder.h"

QGPIORecorder::QGPIORecorder(QGPIOWidget *gpiox, QObject *parent) :
    QAbstractRecorder("GPIO", LOG_GPIO, parent),
    _gpiox(gpiox)
{

}

QString QGPIORecorder::insertHeader()
{
    QString header;

    // Labels
    header += "\t<labels>\n";
    header += "\t\t<value>time</value>\n";
    QStringList labels = _gpiox->getLabels();
    for(int k=0;k<labels.length();k++){
        header += "\t\t<value>" + labels[k] + "</value>\n";
    }
    header += "\t</labels>\n";

    return header;
}

void QGPIORecorder::receive(gpiox_t gpiox)
{
    if (isRecording()) {
        int k;

        QString line = "\t\t<row>";
        line += QString::number(gpiox.time);

        for(k=0;k<QGPIOWIDGET_FLOAT_COUNT;k++){
            line +=  "\t" + QString::number(gpiox.gpio_float[k]);
        }

        line += "</row>\n";

        _log->write(line.toLocal8Bit());
    }
}
