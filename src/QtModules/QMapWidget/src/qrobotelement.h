#ifndef QROBOTELEMENT_H
#define QROBOTELEMENT_H

#include <QObject>
#include <qmarkerelement.h>
#include <qtrajectoryelement.h>
#include <qarrowelement.h>
#include <QVector2D>
#include <QVector3D>

class QRobotElement : public QObject
{
    Q_OBJECT

public:
    QRobotElement(QObject *parent = 0);

    QMarkerElement* getMarker();
    QTrajectoryElement* getTrajectory();
    QArrowElement* getSpeed();

    void draw(QPainter &painter, QTransform transform);

private:
    QMarkerElement      _marker;
    QTrajectoryElement  _trajectory;
    QArrowElement       _speed;

    QVector3D _pose;

signals:
    void poseChanged();

public slots:
    void setPose(QVector3D pose);
    void setPosition(QVector2D position);
    void setOrientation(double orientation);
    void setVelocity(QVector2D velocity);

};

#endif // QROBOTELEMENT_H
