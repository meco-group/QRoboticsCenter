#include "qstringparameter.h"

QStringParameter::QStringParameter() :
    QAbstractParameter()
{

}

QStringParameter::QStringParameter(QString name, int offset, QString value) :
    QAbstractParameter(name, offset), _value(value)
{

}

QString QStringParameter::valueString()
{
    return _value;
}

void QStringParameter::setValueString(QString value)
{
    _value = value;
}

QString QStringParameter::value()
{
    return _value;
}

void QStringParameter::setValue(QString value)
{
    _value = value;
}
