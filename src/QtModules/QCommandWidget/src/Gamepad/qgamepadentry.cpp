#include "qgamepadentry.h"
#include <QSettings>

QGamepadEntry::QGamepadEntry(const QString &name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);

    _name->setText(name);
    _gain->setRange(0,1e6);
    _gain->setValue(1.0);
    _reverse->setCheckable(true);
    _reverse->setChecked(false);
    _configure->setCheckable(true);
    _configure->setChecked(false);

    setLayout(new QHBoxLayout());
    layout()->setMargin(0);
    layout()->addWidget(_name);
    layout()->addWidget(_axis_label);
    layout()->addWidget(_gain);
    layout()->addWidget(_reverse);
    layout()->addWidget(_configure);
}

QPushButton *QGamepadEntry::confButton()
{
    return _configure;
}

double QGamepadEntry::value()
{
    return _value;
}

void QGamepadEntry::saveState(QString group)
{
    QSettings settings;

    settings.beginGroup(group + "/" + objectName());
    settings.setValue("axis", _axis);
    settings.setValue("gain", _gain->value());
    settings.setValue("reverse", _reverse->isChecked());
    settings.endGroup();
}

void QGamepadEntry::restoreState(QString group)
{
    QSettings settings;

    settings.beginGroup(group + "/" + objectName());
    if(settings.contains("axis")) { configureAxis(settings.value("axis").toInt()); }
    if(settings.contains("gain")) { _gain->setValue(settings.value("gain").toDouble()); }
    if(settings.contains("reverse")) {_reverse->setChecked(settings.value("reverse").toBool()); }
    settings.endGroup();
}

void QGamepadEntry::compute(double value)
{
    _value = _gain->value()*value;
    if(_reverse->isChecked()) {
        _value = -_value;
    }
}

void QGamepadEntry::configureAxis(int axis)
{
    _axis = axis;
    switch(axis) {
        case QGamepadManager::AxisLeftX: { _axis_label->setText("LeftX"); break; }
        case QGamepadManager::AxisLeftY: { _axis_label->setText("LeftY"); break; }
        case QGamepadManager::AxisRightX: { _axis_label->setText("RightX"); break; }
        case QGamepadManager::AxisRightY: { _axis_label->setText("RightY"); break; }
        default: _axis_label->setText("axis " + QString::number(axis));
    }
}

void QGamepadEntry::configure(int axis, double value)
{
    configureAxis(axis);
    if(value < 0) { _reverse->setChecked(true); }
    else { _reverse->setChecked(false); }
}

void QGamepadEntry::on_axis_changed(int axis, double value)
{
    if(_configure->isChecked()) {
        configure(axis,value);
        _configure->setChecked(false);
    }
    if(_axis == axis) {
        compute(value);
    }
}
