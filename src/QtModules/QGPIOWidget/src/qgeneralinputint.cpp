#include "qgeneralinputint.h"

QGeneralInputInt::QGeneralInputInt(QString label, QWidget* parent) :
    QGeneralInput(label,parent),
    _value(0)
{

}

int QGeneralInputInt::value()
{
    return _value;
}

void QGeneralInputInt::setValue(int value)
{
    _value = value;
}

double QGeneralInputInt::valueDouble()
{
    return value();
}

void QGeneralInputInt::setValueDouble(double value)
{
    setValue(value);
}
