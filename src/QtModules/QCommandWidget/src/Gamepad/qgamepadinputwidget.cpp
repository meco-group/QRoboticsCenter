#include "qgamepadinputwidget.h"
#include "ui_qgamepadinputwidget.h"

QGamepadInputWidget::QGamepadInputWidget(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGamepadInputWidget)
{
    setObjectName(name);
    ui->setupUi(this);
    ui->groupBox->setTitle(name);
}

QGamepadInputWidget::~QGamepadInputWidget()
{
    delete ui;
}

bool QGamepadInputWidget::enabled()
{
    return ui->groupBox->isChecked();
}

QGamepadEntry *QGamepadInputWidget::add(QString name)
{
    QGamepadEntry *entry = new QGamepadEntry(name,0);
    add(entry);

    return entry;
}

void QGamepadInputWidget::add(QGamepadEntry *entry)
{
    ui->layout->addWidget(entry);
    _entries.append(entry);
}

void QGamepadInputWidget::saveState(QString group)
{
    QListIterator<QGamepadEntry *> i(_entries);
    while(i.hasNext()) {
        i.next()->saveState(group + "/" + objectName());
    }
}

void QGamepadInputWidget::restoreState(QString group)
{
    QListIterator<QGamepadEntry *> i(_entries);
    while(i.hasNext()) {
        i.next()->restoreState(group + "/" + objectName());
    }
}

void QGamepadInputWidget::on_axis_changed(int axis, double value)
{
    QListIterator<QGamepadEntry *> i(_entries);
    while(i.hasNext()) {
        i.next()->on_axis_changed(axis,value);
    }
}

