#include "qtrajectoryelement.h"

QTrajectoryElement::QTrajectoryElement(QObject *parent) : QPainterElement(parent), _length(100)
{
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    setPen(pen);
}

void QTrajectoryElement::setLength(unsigned int length)
{
    _length = length;
}

void QTrajectoryElement::draw(QPainter &painter, QTransform transform)
{
    QPainterElement::draw(painter,transform);
    painter.drawPolyline(transform.map(_trajectory));
}

void QTrajectoryElement::addPoint(QPointF point)
{
    _trajectory.append(point);
    if(_trajectory.size() > _length)
        _trajectory.pop_front();
}


