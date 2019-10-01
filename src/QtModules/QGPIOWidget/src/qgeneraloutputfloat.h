#ifndef QGENERALOUTPUTFLOAT_H
#define QGENERALOUTPUTFLOAT_H

#include <qgeneraloutput.h>
#include <QAbstractSpinBox>
#include <QDoubleSpinBox>

class QGeneralOutputFloat : public QGeneralOutput
{
    Q_OBJECT

public:
    QGeneralOutputFloat(QString label = "", QWidget *parent = 0);

    double valueDouble();
    void setValueDouble(double value);
    float value();
    void setValue(float value);

private:
    QAbstractSpinBox* getSpinBox();
    QDoubleSpinBox* _spinbox;

};

#endif // QGENERALOUTPUTFLOAT_H
