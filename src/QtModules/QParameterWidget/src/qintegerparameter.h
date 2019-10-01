#ifndef QINTEGERPARAMETER_H
#define QINTEGERPARAMETER_H

#include <qabstractparameter.h>
#include <QDebug>

class QIntegerParameter : public QAbstractParameter
{
public:
    QIntegerParameter();
    QIntegerParameter(QString name, int offset, int value);

    virtual QString valueString();
    virtual void setValueString(QString value);

    void setValue(int value);
    int value();

private:
    int _value;

};

#endif // QINTEGERPARAMETER_H
