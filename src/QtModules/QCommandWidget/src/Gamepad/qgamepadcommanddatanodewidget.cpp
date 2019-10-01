#include "qgamepadcommanddatanodewidget.h"

QGamepadCommandDataNodeWidget::QGamepadCommandDataNodeWidget(QString name, QWidget *parent) :
    QTypeCommandInterface(parent),
    _cmd_widget(new QGamepadInputWidget(name,parent))
{
    //do nothing
}

QWidget *QGamepadCommandDataNodeWidget::w()
{
    return _cmd_widget;
}

QGamepadInputWidget *QGamepadCommandDataNodeWidget::commandWidget()
{
    return _cmd_widget;
}

bool QGamepadCommandDataNodeWidget::enabled()
{
    return _cmd_widget->enabled();
}

void QGamepadCommandDataNodeWidget::reset()
{
    //do nothing
}

void QGamepadCommandDataNodeWidget::saveState(QString group)
{
    _cmd_widget->saveState(group);
}

void QGamepadCommandDataNodeWidget::restoreState(QString group)
{
    _cmd_widget->restoreState(group);
}

QGamepadEntry *QGamepadCommandDataNodeWidget::add(QString name)
{
    return _cmd_widget->add(name);
}

void QGamepadCommandDataNodeWidget::on_axis_changed(int axis, double value)
{
    _cmd_widget->on_axis_changed(axis,value);
}
