#include "qfloatparameter.h"

QFloatParameter::QFloatParameter() :
    QAbstractParameter()
{

}

QFloatParameter::QFloatParameter(QString name, int offset, float value) :
    QAbstractParameter(name, offset), _value(value)
{

}

QString QFloatParameter::valueString()
{
    return QString::number(_value);
}

void QFloatParameter::setValueString(QString value)
{
    bool ok;
    float newvalue = value.toFloat(&ok);
    if(ok){
        setValue(newvalue);
    } else {
        qWarning() << "Cannot convert" << value << "to float";
    }
}

void QFloatParameter::setValue(double value)
{
    _value = value;
}

float QFloatParameter::value()
{
    return _value;
}
