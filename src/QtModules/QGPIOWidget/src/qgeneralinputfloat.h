#ifndef QGENERALINPUTFLOAT_H
#define QGENERALINPUTFLOAT_H

#include <qgeneralinput.h>

class QGeneralInputFloat : public QGeneralInput
{
    Q_OBJECT

public:
    explicit QGeneralInputFloat(QString label = "", QWidget *parent = 0);

    float value();
    void setValue(float value);
    double valueDouble();
    void setValueDouble(double value);

private:
    float _value;

};

#endif // QGENERALINPUTFLOAT_H
