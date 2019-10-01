#ifndef QUDPSENDERWIDGET_H
#define QUDPSENDERWIDGET_H

#include <QWidget>

namespace Ui {
class QUdpSenderWidget;
}

class QUdpSenderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QUdpSenderWidget(QString name, QWidget *parent = 0);
    ~QUdpSenderWidget();

    quint16 port();
    void setCount(unsigned int value);

    bool enabled();
    void reset();

private:
    Ui::QUdpSenderWidget *ui;

};

#endif // QUDPSENDERWIDGET_H
