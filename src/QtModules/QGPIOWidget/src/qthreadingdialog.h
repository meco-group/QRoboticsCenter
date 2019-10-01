#ifndef QTHREADINGDIALOG_H
#define QTHREADINGDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QAction>
#include <qthreadinfowidget.h>

class QThreadingDialog : public QDialog
{
public:
    QThreadingDialog(QWidget *parent = 0);
    QAction *getPopupAction();

private:
    QThreadInfoWidget *_widget;
    QAction *_popup;


protected slots:
    //void closeEvent(QCloseEvent *e);

public slots:
    void threadInfoMsgReceived(mavlink_thread_info_t thread_info);

};

#endif // QTHREADINGDIALOG_H
