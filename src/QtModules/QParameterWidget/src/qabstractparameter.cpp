#include "qabstractparameter.h"

QAbstractParameter::QAbstractParameter()
{

}

QAbstractParameter::QAbstractParameter(QString name, int offset) :
    _name(name), _offset(offset)
{

}

QString QAbstractParameter::name()
{
    return _name;
}

int QAbstractParameter::offset()
{
    return _offset;
}
