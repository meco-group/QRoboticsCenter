#include "qbalancingdatanodewidget.h"

QBalancingDataNodeWidget::QBalancingDataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent), _w(new QBalancingWidget(parent))
{
    QObject::connect(_w, &QBalancingWidget::controlModeChanged, this, &QBalancingDataNodeWidget::handleControlModeChanged);
}

QWidget *QBalancingDataNodeWidget::w()
{
    return _w;
}

QBalancingWidget *QBalancingDataNodeWidget::balance()
{
    return _w;
}

void QBalancingDataNodeWidget::handleControlModeChanged(int mode)
{
    event_t e;
    switch(mode){
        case 0: { e.type = STATE_REQUEST_IDLE; break; }
        case 1: { e.type = STATE_REQUEST_ATTITUDE; break; }
        case 2: { e.type = STATE_REQUEST_VELOCITY; break; }
        case 3: { e.type = STATE_REQUEST_POSITION; break; }
    }
    emit transmit(e);
}

void QBalancingDataNodeWidget::receive(pose_t pose)
{
    QVector3D v = QVector3D(pose.roll, pose.pitch, pose.yaw)*0.0001;
    _w->updateAttitude(v);
    v = QVector3D(pose.x, pose.y, pose.z)*0.001;
    _w->updatePosition(v);
}

void QBalancingDataNodeWidget::receive(attitude_t attitude)
{
    QVector3D v = QVector3D(attitude.roll, attitude.pitch, attitude.yaw)*0.0001;
    _w->updateAttitude(v);
}

void QBalancingDataNodeWidget::receive(position_t position)
{
    QVector3D v = QVector3D(position.x, position.y, position.z)*0.001;
    _w->updatePosition(v);
}
