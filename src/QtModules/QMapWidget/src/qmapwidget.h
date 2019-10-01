#ifndef QMAPWIDGET_H
#define QMAPWIDGET_H

#include <QWidget>
#include <qrobotelement.h>
#include <qcloudelement.h>

class QMapWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QMapWidget(QWidget *parent = 0);
    void setRange(double radius);

    QRobotElement *getRobot();
    QCloudElement *getCloud();

protected:
    virtual void paintEvent(QPaintEvent *e);
    virtual void resizeEvent(QResizeEvent *);

private:
    QRobotElement robot;
    QCloudElement cloud;

    QPointF _center;
    double _scale;
    double _range;

    void setScale();
    void setCenter();
};

#endif // QMAPWIDGET_H
