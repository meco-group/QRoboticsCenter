#ifndef QPARAMETERDOCK_H
#define QPARAMETERDOCK_H

#include <qrobotwindowdock.h>
#include <qparameterdatanodewidget.h>

class QParameterDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QParameterDock(QRobotWindow *window);
    QParameterDataNodeWidget *datanode();

protected:
    virtual void showEvent(QShowEvent *);

private:
    QParameterDataNodeWidget *_parameter_datanode_widget;
    bool _parameters_fetched = false;

};

#endif // QPARAMETERDOCK_H
