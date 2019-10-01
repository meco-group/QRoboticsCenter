#include "qrobotelement.h"

QRobotElement::QRobotElement(QObject *parent) : QObject(parent)
{

}

QMarkerElement *QRobotElement::getMarker()
{
    return &_marker;
}

QTrajectoryElement *QRobotElement::getTrajectory()
{
    return &_trajectory;
}

QArrowElement *QRobotElement::getSpeed()
{
    return &_speed;
}

void QRobotElement::draw(QPainter &painter, QTransform transform)
{
    _trajectory.draw(painter,transform);
    _speed.draw(painter,transform.translate(_pose.x(),_pose.y())); //translate the transform
    _marker.draw(painter,transform.rotateRadians(_pose.z())); //rotate the translated transform
}

void QRobotElement::setPose(QVector3D pose)
{
    setPosition(pose.toVector2D());
    setOrientation(pose.z());
}

void QRobotElement::setPosition(QVector2D position)
{
    _pose.setX(position.x());
    _pose.setY(position.y());
    _trajectory.addPoint(position.toPointF());
    emit poseChanged();
}

void QRobotElement::setOrientation(double orientation)
{
    _pose.setZ(orientation);
    emit poseChanged();
}

void QRobotElement::setVelocity(QVector2D velocity)
{
    _speed.setVector(velocity);
    emit poseChanged();
}
