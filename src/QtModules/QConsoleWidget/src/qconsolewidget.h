#ifndef QCONSOLEWIDGET_H
#define QCONSOLEWIDGET_H

#include <QWidget>
#include <QString>
#include <QStringList>
#include <QKeyEvent>
//#include "commandparser.h"

#define QCONSOLEWIDGET_MAXLINECOUNT 40

namespace Ui {
class QConsoleWidget;
}

class QConsoleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QConsoleWidget(QWidget *parent = 0);
    ~QConsoleWidget();

    void setSendName(QString name);
    void setReceiveName(QString name);
    QString sendName();
    QString receiveName();

public slots:
    void addSendMsg(QString msg, bool display_name = true);
    void addRecvMsg(QString msg, bool display_name = false);

private:
    Ui::QConsoleWidget *ui;

    QString _send_name;
    QString _recv_name;
    QStringList _send_msgs;
    QStringList _recv_msgs;

    int _insert_cmd;

    void keyPressEvent(QKeyEvent *e);

signals:
    void command(QString);
    //void mavlinkMsgSend(mavlink_message_t msg);

private slots:
    void on_consoleLineEdit_returnPressed();
};

#endif // QCONSOLEWIDGET_H
