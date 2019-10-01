#include "qthreadinfodatanodewidget.h"

QThreadInfoDataNodeWidget::QThreadInfoDataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent), _threading(new QThreadInfoWidget(parent))
{
    //do nothing
}

QWidget *QThreadInfoDataNodeWidget::w()
{
    return _threading;
}

void QThreadInfoDataNodeWidget::receive(thread_info_t thread_info)
{
    _threading->updateThread(thread_info);
}
