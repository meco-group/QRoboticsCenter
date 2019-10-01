#ifndef QOUTPUTWIDGET_H
#define QOUTPUTWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QDebug>
#include <qsenderinterface.h>

class QOutputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QOutputWidget(QString name, QWidget *parent = 0);

    void addSender(QSenderInterface* sender);
    void reset();

protected:
    QList<QSenderInterface*> _senders;

public slots:
    void send(QList<QVariant> list);

};

#endif // QOUTPUTWIDGET_H
