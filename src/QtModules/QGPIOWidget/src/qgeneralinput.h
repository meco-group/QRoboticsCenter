#ifndef QGENERALINPUT_H
#define QGENERALINPUT_H

#include <qgeneralio.h>
#include <QCheckBox>

class QGeneralInput : public QGeneralIO
{
    Q_OBJECT
public:
    explicit QGeneralInput(QString label = "", QWidget *parent = 0);

    bool isChecked();
    void setChecked(bool check = true);
    QCheckBox* getCheckBox();

    virtual double valueDouble() = 0;
    virtual void setValueDouble(double value) = 0;

private:
    QCheckBox* _checkbox;

};

#endif // QGENERALINPUT_H
