#include "qcloudelement.h"

QCloudElement::QCloudElement(QObject *parent) : QPainterElement(parent)
{
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    setPen(pen);
}

void QCloudElement::addPoint(QPointF point)
{
    _points.append(point);
}

void QCloudElement::draw(QPainter &painter, QTransform transform)
{
    QPainterElement::draw(painter,transform);
    painter.drawPoints(transform.map(_points));
}


