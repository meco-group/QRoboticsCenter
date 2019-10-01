#ifndef QTREEWIDGETPARAMETER_H
#define QTREEWIDGETPARAMETER_H

#include <QObject>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QTreeWidgetItem>

class QTreeWidgetParameterInterface : public QTreeWidgetItem
{
public:
    QTreeWidgetParameterInterface(QString parameter) :
        QTreeWidgetItem(100)
    {
        _label.setText(parameter);
        _spinbox.setRange(-1e100,1e100);
        _spinbox.setDecimals(5);
    }

    ~QTreeWidgetParameterInterface()
    {
        //do nothing
    }

    double value(){ return _spinbox.value(); }
    void setValue(double value){ _spinbox.setValue(value); }

    virtual void updateWidget() = 0;
    virtual void updateParameter() = 0;

    void setup(){
        this->treeWidget()->setItemWidget(this,0,&_label);
        this->treeWidget()->setItemWidget(this,1,&_spinbox);
    }

protected:
    QDoubleSpinBox _spinbox;
    //QLineEdit _input;
    QLabel _label;
};

template <typename T> class QTreeWidgetParameter : public QTreeWidgetParameterInterface
{
public:
    QTreeWidgetParameter(QString parameter, T *value):
        QTreeWidgetParameterInterface(parameter),
        _value(value)
    {
        _spinbox.setValue(*value);
    }

    ~QTreeWidgetParameter()
    {
        //do nothing
    }

    void updateWidget(){ _spinbox.setValue(*_value); }
    void updateParameter(){ *_value = _spinbox.value(); }

private:
    T *_value;
};

#endif // QTREEWIDGETPARAMETER_H
