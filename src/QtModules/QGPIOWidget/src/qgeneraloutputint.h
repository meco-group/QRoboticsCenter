#ifndef QGENERALOUTPUTINT_H
#define QGENERALOUTPUTINT_H

#include <qgeneraloutput.h>
#include <QSpinBox>

class QGeneralOutputInt : public QGeneralOutput
{
    Q_OBJECT

public:
    QGeneralOutputInt(QString label = "", QWidget *parent = 0);

    double valueDouble();
    void setValueDouble(double value);
    int value();
    void setValue(int value);

private:
    QAbstractSpinBox* getSpinBox();
    QSpinBox* _spinbox;

};

#endif // QGENERALOUTPUTINT_H
