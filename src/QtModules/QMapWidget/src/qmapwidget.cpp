#include "qmapwidget.h"

QMapWidget::QMapWidget(QWidget *parent) :
    QWidget(parent),
    _scale(1.0)
{
    // set sizes
    setRange(1.0);
    setCenter();

    // set black background
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);

    // connect change to update
    QObject::connect(&robot,SIGNAL(poseChanged()),this,SLOT(update()));
}

QRobotElement *QMapWidget::getRobot()
{
    return &robot;
}

QCloudElement *QMapWidget::getCloud()
{
    return &cloud;
}

void QMapWidget::setRange(double radius)
{
    _range = radius;
    setScale();
}

void QMapWidget::setScale()
{
    _scale = qMin(this->width(),this->height())/(2.0*_range);
}

void QMapWidget::setCenter()
{
    _center = QPointF(this->width(),this->height())/2.0;
}

void QMapWidget::paintEvent(QPaintEvent *)
{
    // Draw outer rectangle
    QPainter painter(this);
    painter.drawRect(rect());

    // Setup canvas coordinates
    painter.translate(_center);
    painter.scale(1.0,-1.0);
    QTransform transform = QTransform::fromScale(_scale,_scale);

    // Draw robot and point cloud
    cloud.draw(painter,transform);
    robot.draw(painter,transform);
}

void QMapWidget::resizeEvent(QResizeEvent *)
{
    setScale();
    setCenter();
}

