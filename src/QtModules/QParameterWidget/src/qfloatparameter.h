#ifndef QFLOATPARAMETER_H
#define QFLOATPARAMETER_H

#include <qabstractparameter.h>
#include <QDebug>

class QFloatParameter : public QAbstractParameter
{
public:
    QFloatParameter();
    QFloatParameter(QString name, int offset, float value);

    virtual QString valueString();
    virtual void setValueString(QString value);

    void setValue(double value);
    float value();

private:
    float _value;

};

#endif // QFLOATPARAMETER_H
