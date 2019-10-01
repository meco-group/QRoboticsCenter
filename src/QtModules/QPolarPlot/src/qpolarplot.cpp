#include "qpolarplot.h"

int _xaxis;
int _yaxis;

QPointF _center;
double _scale;
double _range;
size_t _size;

QList<double> _circles;
QPolygonF _points;

QPen _circle_pen;
QPen _line_pen;

QPolarPlot::QPolarPlot(QWidget *parent) : QWidget(parent),
    _xaxis(-1),
    _yaxis(-1),
    _range(1),
    _size(1),
    _circle_pen(QPen(Qt::gray,3)),
    _line_pen(QPen(Qt::blue,3))
{
    setScale();
    setCenter();

    // set black background
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void QPolarPlot::setRange(double radius)
{
    _range = radius;
    setScale();
}

void QPolarPlot::setScale()
{
    _scale = qMin(this->width(),this->height())/(2.0*_range);
}

void QPolarPlot::setCenter()
{
    _center = QPointF(this->width(),this->height())/2.0;
}

void QPolarPlot::setSize(size_t size)
{
    _size = size;
}

void QPolarPlot::addCircle(double radius)
{
    _circles.append(radius);
    update();
}

void QPolarPlot::addPoint(const QPointF &point)
{
    _points.append(point);
    if(_points.size()>_size)
        popPoint();
    update();
}

void QPolarPlot::popPoint()
{
    _points.pop_front();
}

void QPolarPlot::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawRect(rect());

    painter.translate(_center);
    painter.setPen(_circle_pen);
    QTransform transform = QTransform::fromScale(_scale,_scale);
    QListIterator<double> i(_circles);
    double r;
    while(i.hasNext()){
        r = i.next();
        painter.drawEllipse(transform.mapRect(QRectF(QPointF(r,r),QPointF(-r,-r))));
    }

    painter.setPen(_line_pen);
    painter.drawPolyline(transform.map(_points));
}

void QPolarPlot::resizeEvent(QResizeEvent *e)
{
    setScale();
    setCenter();
}
