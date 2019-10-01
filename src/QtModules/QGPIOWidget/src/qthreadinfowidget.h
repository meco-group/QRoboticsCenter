#ifndef QTHREADINFOWIDGET_H
#define QTHREADINFOWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include <QAction>
#include <qserialprotocol.h>

class QThreadInfoWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit QThreadInfoWidget(QWidget *parent = 0);

    bool hasThread(int id);
    int findThread(int id);

private:
    QList<thread_info_t> _threads;
    void populateRow(int row);
    void updateWidget();
    void updateWidget(int index);
    QString priorityToString(int priority);

public slots:
    void updateThread(thread_info_t thread);

};

#endif // QTHREADINFOWIDGET_H
