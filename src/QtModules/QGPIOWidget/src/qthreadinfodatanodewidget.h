#ifndef QTHREADINFODATANODEWIDGET_H
#define QTHREADINFODATANODEWIDGET_H

#include <QDockWidget>
#include <qdatanodewidget.h>
#include <qthreadinfowidget.h>

class QThreadInfoDataNodeWidget : public QDataNodeWidget
{
    Q_OBJECT

public:
    explicit QThreadInfoDataNodeWidget(QWidget *parent = 0);
    virtual QWidget *w();

private:
    QThreadInfoWidget *_threading;

public slots:
    virtual void receive(thread_info_t);

};

#endif // QTHREADINFODATANODEWIDGET_H
