#ifndef QBALANCINGDATANODEWIDGET_H
#define QBALANCINGDATANODEWIDGET_H

#include <qdatanodewidget.h>
#include <qbalancingwidget.h>

class QBalancingDataNodeWidget : public QDataNodeWidget
{
    Q_OBJECT

public:
    explicit QBalancingDataNodeWidget(QWidget *parent = 0);
    virtual QWidget *w();
    QBalancingWidget *balance();

private:
    QBalancingWidget *_w;

private slots:
    void handleControlModeChanged(int mode);

public slots:
    virtual void receive(pose_t pose);
    virtual void receive(attitude_t attitude);
    virtual void receive(position_t position);

};

#endif // QBALANCINGDATANODEWIDGET_H
