#include "qintegerparameter.h"

QIntegerParameter::QIntegerParameter() :
    QAbstractParameter()
{

}

QIntegerParameter::QIntegerParameter(QString name, int offset, int value) :
    QAbstractParameter(name, offset), _value(value)
{

}

QString QIntegerParameter::valueString()
{
    return QString::number(_value);
}

void QIntegerParameter::setValueString(QString value)
{
    bool ok;
    int newvalue = value.toInt(&ok);
    if(ok){
        setValue(newvalue);
    } else {
        qWarning() << "Cannot convert" << value << "to integer";
    }
}

void QIntegerParameter::setValue(int value)
{
    _value = value;
}

int QIntegerParameter::value()
{
    return _value;
}
