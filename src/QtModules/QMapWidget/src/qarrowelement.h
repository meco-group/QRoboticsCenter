#ifndef QARROWELEMENT_H
#define QARROWELEMENT_H

#include <qpainterelement.h>
#include <QVector2D>

class QArrowElement : public QPainterElement
{
public:
    QArrowElement(QObject *parent = 0);

    void setSize(double size);
    void draw(QPainter &painter, QTransform transform);

private:
    QPolygonF _arrow;
    QVector2D _vector;

public slots:
    void setVector(QVector2D vector);

};

#endif // QARROWELEMENT_H
