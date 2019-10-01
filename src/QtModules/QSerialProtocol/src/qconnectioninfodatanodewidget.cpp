#include "qconnectioninfodatanodewidget.h"

QConnectionInfoDataNodeWidget::QConnectionInfoDataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent), _widget(new QConnectionInfoWidget(parent))
{

}

QWidget *QConnectionInfoDataNodeWidget::w()
{
    return _widget;
}

QConnectionInfoWidget *QConnectionInfoDataNodeWidget::connectionInfoWidget()
{
    return _widget;
}

void QConnectionInfoDataNodeWidget::receive(heartbeat_t)
{
    _widget->receive("heartbeat");
}

void QConnectionInfoDataNodeWidget::receive(gpio_t)
{
    _widget->receive("gpio");
}

void QConnectionInfoDataNodeWidget::receive(print_t)
{
    _widget->receive("print");
}

void QConnectionInfoDataNodeWidget::receive(event_t)
{
    _widget->receive("event");
}

void QConnectionInfoDataNodeWidget::receive(pose_t)
{
    _widget->receive("pose");
}

void QConnectionInfoDataNodeWidget::receive(attitude_t)
{
    _widget->receive("attitude");
}

void QConnectionInfoDataNodeWidget::receive(velocity_t)
{
    _widget->receive("velocity");
}

void QConnectionInfoDataNodeWidget::receive(position_t)
{
    _widget->receive("position");
}
