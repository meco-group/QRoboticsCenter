#include "qpainterelement.h"

QPainterElement::QPainterElement(QObject *parent) : QObject(parent)
{

}

void QPainterElement::setPen(const QPen &pen)
{
    _pen = pen;
}

void QPainterElement::setBrush(const QBrush &brush)
{
    _brush = brush;
}

void QPainterElement::setSize(double size)
{
    _size = size;
}

void QPainterElement::draw(QPainter &painter, QTransform transform)
{
    painter.setPen(_pen);
    painter.setBrush(_brush);
}
