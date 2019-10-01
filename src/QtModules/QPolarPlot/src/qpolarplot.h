#ifndef QPOLARPLOT_H
#define QPOLARPLOT_H

#include <QWidget>
#include <QPainter>
#include <QPoint>
#include <qdebug.h>

class QPolarPlot : public QWidget
{
    Q_OBJECT
public:
    explicit QPolarPlot(QWidget *parent = 0);

    void setRange(double radius);
    void setScale();
    void setCenter();
    void setSize(size_t size);

    void addCircle(double radius);
    void addPoint(const QPointF &point);
    virtual void popPoint();

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent *e);

private:
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


signals:

public slots:
};

#endif // QPOLARPLOT_H
