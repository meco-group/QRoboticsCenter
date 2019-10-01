#include "qgeneraloutputfloat.h"

QGeneralOutputFloat::QGeneralOutputFloat(QString label, QWidget *parent) :
    QGeneralOutput(label, parent),
    _spinbox(new QDoubleSpinBox(this))
{
    setup();
    _spinbox->setRange(-1e100,1e100);
    _spinbox->setDecimals(4);
}

double QGeneralOutputFloat::valueDouble()
{
    return value();
}

void QGeneralOutputFloat::setValueDouble(double value)
{
    setValue(value);
}

float QGeneralOutputFloat::value()
{
    return _spinbox->value();
}

void QGeneralOutputFloat::setValue(float value)
{
    _spinbox->setValue(value);
}

QAbstractSpinBox *QGeneralOutputFloat::getSpinBox()
{
    return _spinbox;
}
