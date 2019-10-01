#ifndef QRUNNINGPLOT_H
#define QRUNNINGPLOT_H

#include "qcustomplot.h"
#include <QVector>
#include <QWidget>
#include <QMenu>
#include <QInputDialog>
#include <qaxisdialog.h>

#define QRUNNINGPLOT_TYPE_GRAPH 0
#define QRUNNINGPLOT_TYPE_CURVE 1

class QRunningPlot : public QCustomPlot
{
    Q_OBJECT

public:
    explicit QRunningPlot(QWidget *parent = 0);
    void init(double span, quint8 n, quint8 type = QRUNNINGPLOT_TYPE_GRAPH);
    void addDataPoint(double x, double y, quint8 g, double t = 0.0);
    void reDraw();
    void setAxes(QCPAxis *keyAxis, QCPAxis *valueAxis, quint8 g);

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private:
    unsigned int _type;

    bool    _rescale_y;
    double  _span;

private slots:
    void setSpanInput();
    void setAxisInput();

};

/*class QSetSpanAction: public QAction
{
    Q_OBJECT

public:
    explicit QSetSpanAction(const QString &text, QWidget *parent = 0, QRunningPlot *plot = this);

private:

}; */

#endif // QRUNNINGPLOT_H
