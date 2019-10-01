#include "qparametertablewidget.h"

QParameterTableWidget::QParameterTableWidget(QWidget *parent) :
    QWidget(parent),
    _table(new QTableWidget(this)),
    _load(new QPushButton("load",this)),
    _send(new QPushButton("send",this)),
    _store(new QPushButton("store",this))
{
    _table->setColumnCount(2);
    _table->setRowCount(0);
    _table->setHorizontalHeaderLabels(QStringList({"name","value"}));

    QHeaderView* header = _table->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);

    QHBoxLayout *lh = new QHBoxLayout();
    lh->addWidget(_load);
    lh->addWidget(_send);
    lh->addWidget(_store);

    QVBoxLayout *lv = new QVBoxLayout(this);
    setLayout(lv);
    lv->addWidget(_table);
    lv->addLayout(lh);
}

int QParameterTableWidget::setParameter(QString name, QString value)
{
    int row = -1;

    // Find item based on name
    QList<QTableWidgetItem*> list = _table->findItems(name, Qt::MatchExactly);
    for(int row=(list.size()-1); row>=0; row--){
        if(_table->column(list[row]) != 0) {
            list.removeAt(row);
        }
    }

    // Change the corresponding value
    switch(list.size()) {
    case 0: {
        row = _table->rowCount();
        _table->insertRow(row);
        QTableWidgetItem *name_item = new QTableWidgetItem(name);
        QTableWidgetItem *value_item = new QTableWidgetItem(value);
        value_item->setTextAlignment(Qt::AlignRight);
        _table->setItem(row,0,name_item);
        _table->setItem(row,1,value_item);
        break; }

    case 1: {
        row = _table->row(list[0]);
        _table->item(row,1)->setText(value);
        break; }

    default:
        qWarning() << "More than one parameter found! Implementation error it seems.";
    }

    return row;
}

QTableWidget *QParameterTableWidget::table()
{
    return _table;
}

QPushButton *QParameterTableWidget::load()
{
    return _load;
}

QPushButton *QParameterTableWidget::send()
{
    return _send;
}

QPushButton *QParameterTableWidget::store()
{
    return _store;
}
