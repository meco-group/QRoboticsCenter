#include "qgeneralio.h"

QGeneralIO::QGeneralIO(QString label, QWidget *parent) :
    QWidget(parent),
    _label(new QLineEdit(label,this))
{
    //do nothing
}

QString QGeneralIO::text()
{
    return _label->text();
}

void QGeneralIO::setText(QString text)
{
    _label->setText(text);
}

QLineEdit *QGeneralIO::getLabel()
{
    return _label;
}

void QGeneralIO::setup(QWidget *w)
{
    this->setLayout(new QBoxLayout(QBoxLayout::LeftToRight,this));
    this->layout()->setContentsMargins(0,0,0,0);
    this->layout()->addWidget(_label);
    this->layout()->addWidget(w);
}
