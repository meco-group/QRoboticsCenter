#include "qudpsenderwidget.h"
#include "ui_qudpsenderwidget.h"

QUdpSenderWidget::QUdpSenderWidget(QString name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QUdpSenderWidget)
{
    ui->setupUi(this);
    ui->groupBox->setTitle(name);
}

QUdpSenderWidget::~QUdpSenderWidget()
{
    delete ui;
}

quint16 QUdpSenderWidget::port()
{
    return ui->port->value();
}

void QUdpSenderWidget::setCount(unsigned int value)
{
    ui->label_3->setText(QString::number(value));
}

bool QUdpSenderWidget::enabled()
{
    return ui->groupBox->isChecked();
}

void QUdpSenderWidget::reset()
{
    setCount(0);
    ui->port->setValue(0);
}
