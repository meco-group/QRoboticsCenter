#ifndef QMARKERELEMENT_H
#define QMARKERELEMENT_H

#include <qpainterelement.h>

class QMarkerElement : public QPainterElement
{
public:
    QMarkerElement(QObject *parent = 0);

    void setSize(double size);
    void draw(QPainter &painter, QTransform transform = QTransform());

private:
    QPolygonF _marker;
    double _orientation;

public slots:
    void setOrientation(double orientation);

};

#endif // QMARKERELEMENT_H
