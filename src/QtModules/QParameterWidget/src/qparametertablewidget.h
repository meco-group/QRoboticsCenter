#ifndef QPARAMETERTABLEWIDGET_H
#define QPARAMETERTABLEWIDGET_H

#include <QTableWidget>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <qdebug.h>

class QParameterTableWidget : public QWidget
{
    Q_OBJECT
public:
    QParameterTableWidget(QWidget *parent = 0);
    int setParameter(QString name, QString value);

    QTableWidget *table();
    QPushButton *load();
    QPushButton *send();
    QPushButton *store();

private:
    QTableWidget *_table;
    QPushButton *_load;
    QPushButton *_send;
    QPushButton *_store;

};

#endif // QPARAMETERTABLEWIDGET_H
