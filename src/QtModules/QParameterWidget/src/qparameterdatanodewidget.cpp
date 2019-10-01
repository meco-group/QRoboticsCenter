#include "qparameterdatanodewidget.h"

QParameterDataNodeWidget::QParameterDataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent),
    _w(new QParameterTableWidget(parent))
{
    QObject::connect(_w->load(), &QPushButton::clicked, this, &QParameterDataNodeWidget::on_load_button_clicked);
    QObject::connect(_w->send(), &QPushButton::clicked, this, &QParameterDataNodeWidget::on_send_button_clicked);
    QObject::connect(_w->store(), &QPushButton::clicked, this, &QParameterDataNodeWidget::on_store_button_clicked);
}

QWidget *QParameterDataNodeWidget::w()
{
    return _w;
}

QParameterTableWidget *QParameterDataNodeWidget::parameterTableWidget()
{
    return _w;
}

void QParameterDataNodeWidget::receive(param_int_t i)
{
    QString name = QString(QByteArray(i.name,10));
    QIntegerParameter p(name, i.pointer, i.value);

//    qDebug() << "name: " << QByteArray(i.name,10);
//    qDebug() << "address: " << i.pointer;
//    qDebug() << "value: " << i.value;

    add(p);
}

void QParameterDataNodeWidget::receive(param_float_t f)
{
    QString name = QString(QByteArray(f.name,10));
    QFloatParameter p(name, f.pointer, f.value);

//    qDebug() << "name: " << QByteArray(f.name,10);
//    qDebug() << "address: " << f.pointer;
//    qDebug() << "value: " << f.value;

    add(p);
}

void QParameterDataNodeWidget::add(QIntegerParameter p)
{
    _int32_parameters.insert(p.name(),p);
    _w->setParameter(p.name(), p.valueString());
}

void QParameterDataNodeWidget::add(QFloatParameter p)
{
    _float_parameters.insert(p.name(),p);
    _w->setParameter(p.name(), p.valueString());
}

// manager as ground throught
void QParameterDataNodeWidget::syncFromManager()
{
    for(auto p = _int32_parameters.begin(); p != _int32_parameters.end(); p++) {
        _w->setParameter(p->name(), p->valueString());
    }
    for(auto p = _float_parameters.begin(); p != _float_parameters.end(); p++) {
        _w->setParameter(p->name(), p->valueString());
    }
}

void QParameterDataNodeWidget::syncFromWidget()
{
    QString name, value;

    for (int k=0; k<_w->table()->rowCount(); k++) {
        name = _w->table()->item(k,0)->text();
        value = _w->table()->item(k,1)->text();

        if(_int32_parameters.contains(name)) {
            const QString t(name);
            _int32_parameters[t].setValueString(value);
            continue;
        }
        if(_float_parameters.contains(name)) {
            _float_parameters[name].setValueString(value);
            continue;
        }
    }
}

void QParameterDataNodeWidget::on_load_button_clicked()
{
    event_t event;
    event.type = PARAMETERS_REQUEST_SEND;
    emit transmit(event);
}

void QParameterDataNodeWidget::on_send_button_clicked()
{
    syncFromWidget();

    for(auto p = _int32_parameters.begin(); p != _int32_parameters.end(); p++) {
        param_int_t param_int;
        memcpy(param_int.name, p->name().toLocal8Bit().data(), p->name().size()+1);
        param_int.value = p->value();
        param_int.pointer = p->offset();

        emit transmit(param_int);
    }
    for(auto p = _float_parameters.begin(); p != _float_parameters.end(); p++) {
        param_float_t param_float;
        memcpy(param_float.name, p->name().toLocal8Bit().data(), p->name().size()+1);
        param_float.value = p->value();
        param_float.pointer = p->offset();
        emit transmit(param_float);
    }
}

void QParameterDataNodeWidget::on_store_button_clicked()
{
    event_t event;
    event.type = PARAMETERS_REQUEST_STORE;
    emit transmit(event);
}
