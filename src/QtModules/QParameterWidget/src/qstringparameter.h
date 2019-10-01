#ifndef QSTRINGPARAMETER_H
#define QSTRINGPARAMETER_H

#include <qabstractparameter.h>
#include <QDebug>

class QStringParameter : public QAbstractParameter
{
public:
    QStringParameter();
    QStringParameter(QString name, int offset, QString value);

    virtual QString valueString();
    virtual void setValueString(QString value);

    QString value();
    void setValue(QString value);

private:
    QString _value;

};

#endif // QSTRINGPARAMETER_H
