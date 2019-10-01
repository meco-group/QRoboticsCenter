#ifndef QGENERALINPUTINT_H
#define QGENERALINPUTINT_H

#include <qgeneralinput.h>

class QGeneralInputInt : public QGeneralInput
{
    Q_OBJECT

public:
    explicit QGeneralInputInt(QString label = "", QWidget *parent = 0);

    int value();
    void setValue(int value);
    double valueDouble();
    void setValueDouble(double value);

private:
    int _value;

};

#endif // QGENERALINPUTINT_H
