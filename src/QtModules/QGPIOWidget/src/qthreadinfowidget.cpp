#include "qthreadinfowidget.h"

QThreadInfoWidget::QThreadInfoWidget(QWidget *parent) :
    QTableWidget(0,7,parent)
{
    QStringList header;
    header << "ID" << "priority" << "<duration> [us]" << "<latency> [us]" << "duration [us]" << "latency [us]" << "executions";
    setHorizontalHeaderLabels(header);

    //QHeaderView* hv = horizontalHeader();
    //hv->setSectionResizeMode(QHeaderView::Stretch);
    setMinimumSize(250,150);
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}

bool QThreadInfoWidget::hasThread(int id)
{
    return (findThread(id) >= 0);
}

int QThreadInfoWidget::findThread(int id)
{
    for(int index = 0; index<_threads.length() ; index++){
        if(_threads[index].ID == id){
            return index;
        }
    }
    return -1;
}

void QThreadInfoWidget::populateRow(int row)
{
    for(int k=0; k<7 ; k++){
        setItem(row,k,new QTableWidgetItem(0));
        item(row,k)->setTextAlignment(Qt::AlignRight);
    }

    item(row,0)->setTextAlignment(Qt::AlignLeft);
    item(row,1)->setTextAlignment(Qt::AlignCenter);
}

void QThreadInfoWidget::updateWidget()
{
    for(int k=0;k<_threads.length();k++)
        updateWidget(k);
}

void QThreadInfoWidget::updateWidget(int index)
{
    // Check if new thread
    if(index>=rowCount()){
        insertRow(rowCount());
        populateRow(index);
    }
    // Fill out data
    item(index,0)->setText(QString::number(_threads[index].ID));
    item(index,1)->setText(priorityToString(_threads[index].priority));
    item(index,2)->setText(QString::number(_threads[index].duration/_threads[index].number_of_executions));
    item(index,3)->setText(QString::number(_threads[index].latency/_threads[index].number_of_executions));
    item(index,4)->setText(QString::number(_threads[index].duration));
    item(index,5)->setText(QString::number(_threads[index].latency));
    item(index,6)->setText(QString::number(_threads[index].number_of_executions));
}

QString QThreadInfoWidget::priorityToString(int priority)
{
    switch(priority){
        case 0: return "LOWEST";
        case 1: return "BELOW NORMAL";
        case 2: return "NORMAL";
        case 3: return "ABOVE NORMAL";
        case 4: return "HIGHEST";
        default: return QString::number(priority);
    }
}

void QThreadInfoWidget::updateThread(thread_info_t thread)
{
    int index = findThread(thread.ID);
    if(index >= 0){
        _threads[index] = thread;
    } else {
        _threads.append(thread);
        index = _threads.size() - 1;
    }
    updateWidget(index);
}

