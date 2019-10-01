#include "qrunningpolarplot.h"

QRunningPolarPlot::QRunningPolarPlot(int interval, QWidget *parent) : QPolarPlot(parent), _last(QPointF(0.0,0.0))
{
    startTimer(interval);
}

void QRunningPolarPlot::timerEvent(QTimerEvent *e)
{
    addPoint(_last);
    repaint();
}

void QRunningPolarPlot::updatePoint(QPointF p)
{
    _last = p;
    qDebug() << "updated";
}
