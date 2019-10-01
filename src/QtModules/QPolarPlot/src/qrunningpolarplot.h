#ifndef QRUNNINGPOLARPLOT_H
#define QRUNNINGPOLARPLOT_H

#include <QWidget>
#include <QDebug>
#include <qpolarplot.h>

class QRunningPolarPlot : public QPolarPlot
{
    Q_OBJECT

public:
    QRunningPolarPlot(int interval = 50, QWidget *parent = 0);

protected:
    virtual void timerEvent(QTimerEvent *e);

private:
    QPointF _last;

public slots:
    void updatePoint(QPointF p);

};

#endif // QRUNNINGPOLARPLOT_H
