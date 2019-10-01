#include "qrunningplot.h"

QRunningPlot::QRunningPlot(QWidget *parent) :
    QCustomPlot(parent),
    _rescale_y(true)
{
    //do nothing
}

void QRunningPlot::init(double span, quint8 n, quint8 type)
{
    this->_span = span;
    this->_type = type;

    QVector<double> x(100);
    QVector<double> y(100);

    for(int i=-x.size(); i<0; i++){
        x[i+x.size()] = i*0.05;
        y[i+x.size()] = 0;
    }

    for(int i=0;i<n;i++){
        switch(_type){
        case QRUNNINGPLOT_TYPE_GRAPH:{
            //this->addPlottable(
            QCPGraph *g = new QCPGraph(this->xAxis,this->yAxis);
            g->setData(x, y);
            break;}
        case QRUNNINGPLOT_TYPE_CURVE:{
            new QCPCurve(this->xAxis,this->yAxis);
            //((QCPCurve*)(this->plottable(i)))->setData(x, y, y);
            break;}
        default:{
            QCPGraph *g = new QCPGraph(this->xAxis,this->yAxis);
            g->setData(x, y);
            break;}
        }
    }
}

void QRunningPlot::addDataPoint(double x, double y, quint8 g, double t){
    switch(_type){
        case QRUNNINGPLOT_TYPE_GRAPH:
            ((QCPGraph*)(this->plottable(g)))->data()->removeBefore(x-_span);
            ((QCPGraph*)(this->plottable(g)))->addData(x, y);
            break;
        case QRUNNINGPLOT_TYPE_CURVE:
            ((QCPCurve*)(this->plottable(g)))->data()->removeBefore(t-_span);
            ((QCPCurve*)(this->plottable(g)))->addData(t, x, y);
            break;
        default:
            ((QCPGraph*)(this->plottable(g)))->data()->removeBefore(x-_span);
            ((QCPGraph*)(this->plottable(g)))->addData(x, y);
            break;
    }
}

void QRunningPlot::reDraw()
{
    this->xAxis->rescale(true);
    this->xAxis2->rescale(true);
    if(_rescale_y){
        this->yAxis->rescale(true);
        this->yAxis2->rescale(true);
    }
    this->replot();
}

void QRunningPlot::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    QAction setXaxisAction("x axis",this);
    QAction setYaxisAction("y axis",this);
    menu.addAction(&setXaxisAction);
    menu.addAction(&setYaxisAction);
    QObject::connect(&setXaxisAction, SIGNAL(triggered()), this, SLOT(setSpanInput()));
    QObject::connect(&setYaxisAction, SIGNAL(triggered()), this, SLOT(setAxisInput()));
    menu.exec(event->globalPos());
}

void QRunningPlot::setSpanInput()
{
    this->_span = abs(QInputDialog::getInt(0, tr("Horizon settings"), tr("Time horizon:"), QLineEdit::Normal));
}

void QRunningPlot::setAxisInput()
{
    QAxisDialog *dialog = new QAxisDialog(this->yAxis, &_rescale_y, this->parentWidget());
    dialog->exec();
}

void QRunningPlot::setAxes(QCPAxis *keyAxis, QCPAxis *valueAxis, quint8 g){
    this->plottable(g)->setKeyAxis(keyAxis);
    this->plottable(g)->setValueAxis(valueAxis);
}
