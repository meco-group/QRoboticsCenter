#include "qgeneralinputfloat.h"

QGeneralInputFloat::QGeneralInputFloat(QString label, QWidget* parent) :
    QGeneralInput(label,parent),
    _value(0.0f)
{

}

float QGeneralInputFloat::value()
{
    return _value;
}

void QGeneralInputFloat::setValue(float value)
{
    _value = value;
}

double QGeneralInputFloat::valueDouble()
{
    return value();
}

void QGeneralInputFloat::setValueDouble(double value)
{
    setValue(value);
}
