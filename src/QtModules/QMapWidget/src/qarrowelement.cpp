#include "qarrowelement.h"

QArrowElement::QArrowElement(QObject *parent) : QPainterElement(parent)
{
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);
    setPen(pen);

    QBrush brush;
    brush.setColor(Qt::black);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    setSize(1.0);
}

void QArrowElement::setSize(double size)
{
    if(size > 0.0){
        QPainterElement::setSize(size);
        _arrow = QPolygonF();
        _arrow.append(QPointF(0.0,0.0)*size);
        _arrow.append(QPointF(4.5,0.0)*size);
        _arrow.append(QPointF(4.25,0.35)*size);
        _arrow.append(QPointF(5.0,0.0)*size);
        _arrow.append(QPointF(4.25,-0.35)*size);
        _arrow.append(QPointF(4.5,0.0)*size);
    }
}

void QArrowElement::draw(QPainter &painter, QTransform transform)
{
    QPainterElement::draw(painter,transform);
    QTransform rotate(_vector.x(),_vector.y(),-_vector.y(),_vector.x(),0.0,0.0);
    painter.drawPolygon((rotate*transform).map(_arrow));
}

void QArrowElement::setVector(QVector2D vector)
{
    _vector = vector;
}
