#include "qparameterdock.h"

QParameterDock::QParameterDock(QRobotWindow *window) :
    QRobotWindowDock("parameters", window),
    _parameter_datanode_widget(new QParameterDataNodeWidget(this))
{
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    setWidget(_parameter_datanode_widget->w());
    window->addDockWidget(Qt::RightDockWidgetArea, this);
}

QParameterDataNodeWidget *QParameterDock::datanode()
{
    return _parameter_datanode_widget;
}

void QParameterDock::showEvent(QShowEvent *)
{
    if(!_parameters_fetched) {
        _parameters_fetched = true;
        _parameter_datanode_widget->parameterTableWidget()->load()->click();
    }
}
