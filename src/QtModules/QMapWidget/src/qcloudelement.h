#ifndef QCLOUDELEMENT_H
#define QCLOUDELEMENT_H

#include <qpainterelement.h>

class QCloudElement : public QPainterElement
{
public:
    QCloudElement(QObject *parent = 0);

    void addPoint(QPointF point);
    void draw(QPainter &painter, QTransform transform);

private:
    QPolygonF _points;

};

#endif // QCLOUDELEMENT_H
