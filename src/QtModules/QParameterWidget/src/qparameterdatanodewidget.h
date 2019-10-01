#ifndef QPARAMETERDATANODEWIDGET_H
#define QPARAMETERDATANODEWIDGET_H

#include <qdatanodewidget.h>
#include <qparametertablewidget.h>
#include <qintegerparameter.h>
#include <qfloatparameter.h>

class QParameterDataNodeWidget : public QDataNodeWidget
{
    Q_OBJECT
public:
    explicit QParameterDataNodeWidget(QWidget *parent = 0);

    virtual QWidget *w();
    QParameterTableWidget *parameterTableWidget();
    virtual void receive(param_int_t);
    virtual void receive(param_float_t);
    void add(QIntegerParameter p);
    void add(QFloatParameter p);

private:
    QParameterTableWidget *_w;
    QMap<QString,QIntegerParameter> _int32_parameters;
    QMap<QString,QFloatParameter> _float_parameters;

    void syncFromManager();
    void syncFromWidget();

private slots:
    void on_load_button_clicked();
    void on_send_button_clicked();
    void on_store_button_clicked();

};

#endif // QPARAMETERDATANODEWIDGET_H
