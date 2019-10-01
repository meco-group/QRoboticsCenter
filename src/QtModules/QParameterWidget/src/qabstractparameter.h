#ifndef QABSTRACTPARAMETER_H
#define QABSTRACTPARAMETER_H

#include <QString>

class QAbstractParameter
{
public:
    QAbstractParameter();
    QAbstractParameter(QString name, int offset);

    QString name();
    int offset();
    virtual QString valueString() = 0;
    virtual void setValueString(QString value) = 0;

private:
    QString _name;
    int _offset;

};

#endif // QABSTRACTPARAMETER_H
