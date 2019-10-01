#include "qthreadingdialog.h"

QThreadingDialog::QThreadingDialog(QWidget *parent) :
    QDialog(parent),
    _widget(new QThreadInfoWidget(this)),
    _popup(new QAction("Thread info", this))
{
    setLayout(new QVBoxLayout);
    layout()->addWidget(_widget);
    QObject::connect(_popup,SIGNAL(triggered()),this,SLOT(show()));
}

QAction *QThreadingDialog::getPopupAction()
{
    return _popup;
}

void QThreadingDialog::threadInfoMsgReceived(mavlink_thread_info_t thread_info)
{
    Thread thread;
    thread.setId(thread_info.ID);
    thread.setPriority(thread_info.priority);
    thread.setNumberOfExecutions(thread_info.number_of_executions);
    thread.setDuration(thread_info.duration);
    thread.setLatency(thread_info.latency);
    thread.setTime(thread_info.time);
    thread.setTotalDuration(thread_info.total_duration);
    thread.setTotalLatency(thread_info.total_latency);

    _widget->updateThread(thread);
}

/*void QThreadingDialog::closeEvent(QCloseEvent *e)
{
    setVisible(false);
}*/
