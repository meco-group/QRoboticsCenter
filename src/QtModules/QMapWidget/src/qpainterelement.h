#ifndef QPAINTERELEMENT_H
#define QPAINTERELEMENT_H

#include <QObject>
#include <QPainter>

class QPainterElement : public QObject
{
    Q_OBJECT
public:
    explicit QPainterElement(QObject *parent = 0);

    virtual void setPen(const QPen &pen);
    virtual void setBrush(const QBrush &brush);
    virtual void setSize(double size);

    virtual void draw(QPainter &painter, QTransform transform = QTransform());

private:
    QPen    _pen;
    QBrush  _brush;
    double  _size;

signals:

public slots:
};

#endif // QPAINTERELEMENT_H
