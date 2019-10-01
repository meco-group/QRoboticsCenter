#include "qmultisineexcitationwidget.h"

QMultisineExcitationWidget::QMultisineExcitationWidget(QExcitationChannelWidget *channels, QWidget *parent) :
    QWidget(parent), _channels(channels)
{
    QFormLayout *form = new QFormLayout(0);
    form->addRow("realization",_realization_spinbox);
    form->addRow("amplitude",_amplitude_spinbox);

    _realization_spinbox->setValue(0);
    _amplitude_spinbox->setValue(0);
    _amplitude_spinbox->setDecimals(4);
    _amplitude_spinbox->setRange(0,1e6);

    setLayout(form);
}

int QMultisineExcitationWidget::realization()
{
    return _realization_spinbox->value();
}

double QMultisineExcitationWidget::amplitude()
{
    return _amplitude_spinbox->value();
}

unsigned int QMultisineExcitationWidget::channels()
{
    return _channels->getChannels();
}

QMultisineDataNodeWidget::QMultisineDataNodeWidget(QExcitationChannelWidget *channels, QWidget *parent) :
    QExcitationDataNodeWidgetInterface(parent), _w(new QMultisineExcitationWidget(channels,parent))
{
    //do nothing
}

QWidget* QMultisineDataNodeWidget::w()
{
    return _w;
}

QMultisineExcitationWidget* QMultisineDataNodeWidget::multisineWidget()
{
    return _w;
}

void QMultisineDataNodeWidget::enableExcitation()
{
    signal_multisine_t multisine;
    multisine.channels = _w->channels();
    multisine.id = _w->realization();
    multisine.amplitude = _w->amplitude();
    emit transmit(multisine);
}

void QMultisineDataNodeWidget::disableExcitation()
{
    event_t event;
    event.type = DISABLE_EXCITATION;
    emit transmit(event);
}
