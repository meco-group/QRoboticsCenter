#include "qsweptsineexcitationwidget.h"

QSweptsineExcitationWidget::QSweptsineExcitationWidget(QExcitationChannelWidget *channels, QWidget *parent) :
    QWidget(parent), _channels(channels)
{
    QFormLayout *form = new QFormLayout(0);
    form->addRow("fl",_fl_spinbox);
    form->addRow("fh",_fh_spinbox);
    form->addRow("period",_period_spinbox);
    form->addRow("amplitude",_amplitude_spinbox);

    _fl_spinbox->setRange(0,1e3);
    _fl_spinbox->setValue(1);
    _fh_spinbox->setRange(0,1e3);
    _fh_spinbox->setValue(10);
    _period_spinbox->setRange(0,1e2);
    _period_spinbox->setValue(10);
    _amplitude_spinbox->setRange(0,1e6);
    _amplitude_spinbox->setDecimals(4);
    _amplitude_spinbox->setValue(0);

    setLayout(form);
}

double QSweptsineExcitationWidget::fl()
{
    return _fl_spinbox->value();
}

double QSweptsineExcitationWidget::fh()
{
    return _fh_spinbox->value();
}

double QSweptsineExcitationWidget::period()
{
    return _period_spinbox->value();
}

double QSweptsineExcitationWidget::amplitude()
{
    return _amplitude_spinbox->value();
}

unsigned int QSweptsineExcitationWidget::channels()
{
    return _channels->getChannels();
}


QSweptsineDataNodeWidget::QSweptsineDataNodeWidget(QExcitationChannelWidget *channels, QWidget *parent) :
    QExcitationDataNodeWidgetInterface(parent), _w(new QSweptsineExcitationWidget(channels, parent))
{
    //do nothing
}

QWidget* QSweptsineDataNodeWidget::w()
{
    return _w;
}

QSweptsineExcitationWidget* QSweptsineDataNodeWidget::sweptsineWidget()
{
    return _w;
}

void QSweptsineDataNodeWidget::enableExcitation()
{
    signal_sweptsine_t sweptsine;
    sweptsine.channels = _w->channels();
    sweptsine.fmin = _w->fl();
    sweptsine.fmax = _w->fh();
    sweptsine.period = _w->period();
    sweptsine.amplitude = _w->amplitude();
    emit transmit(sweptsine);
}

void QSweptsineDataNodeWidget::disableExcitation()
{
    event_t event;
    event.type = DISABLE_EXCITATION;
    emit transmit(event);
}
