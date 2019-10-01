#ifndef QCONNECTIONINFODATANODEWIDGET_H
#define QCONNECTIONINFODATANODEWIDGET_H

#include <qdatanodewidget.h>
#include <qconnectioninfowidget.h>

class QConnectionInfoDataNodeWidget : public QDataNodeWidget
{
public:
    explicit QConnectionInfoDataNodeWidget(QWidget *parent = 0);
    virtual QWidget *w();
    QConnectionInfoWidget *connectionInfoWidget();

private:
    QConnectionInfoWidget *_widget;

public slots:
    virtual void receive(heartbeat_t);
    virtual void receive(gpio_t);
    virtual void receive(print_t);
    virtual void receive(event_t);
    virtual void receive(pose_t);
    virtual void receive(attitude_t);
    virtual void receive(velocity_t);
    virtual void receive(position_t);

};

#endif // QCONNECTIONINFODATANODEWIDGET_H
