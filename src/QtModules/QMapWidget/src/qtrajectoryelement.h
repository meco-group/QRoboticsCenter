#ifndef QTRAJECTORYELEMENT_H
#define QTRAJECTORYELEMENT_H

#include <qpainterelement.h>
#include <QPoint>

class QTrajectoryElement : public QPainterElement
{
public:
    QTrajectoryElement(QObject *parent = 0);

    void setLength(unsigned int length);
    void draw(QPainter &painter, QTransform transform);

private:
    QPolygonF _trajectory;
    unsigned int _length;

public slots:
    void addPoint(QPointF point);

};

#endif // QTRAJECTORYELEMENT_H
