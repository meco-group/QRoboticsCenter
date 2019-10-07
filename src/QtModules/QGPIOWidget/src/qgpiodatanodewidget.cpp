#include "qgpiodatanodewidget.h"

QGPIODataNodeWidget::QGPIODataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent), _gpiox(new QGPIOWidget(parent))
{
    QObject::connect(_gpiox, &QGPIOWidget::setOutput, this, &QGPIODataNodeWidget::onOutputSet);
    QObject::connect(_gpiox, &QGPIOWidget::eventButtonPressed, this, &QGPIODataNodeWidget::onEventButtonPressed);
    QObject::connect(this, SIGNAL(transmit(gpiox_t)), _gpiox, SLOT(setInput(gpiox_t)));
}

QWidget *QGPIODataNodeWidget::w()
{
    return _gpiox;
}

QGPIOWidget *QGPIODataNodeWidget::gpiow()
{
    return _gpiox;
}

void QGPIODataNodeWidget::saveState(QString group)
{
    _gpiox->saveState(group);
}

void QGPIODataNodeWidget::restoreState(QString group)
{
    _gpiox->restoreState(group);
}

void QGPIODataNodeWidget::receive(gpiox_t gpiox)
{
    _gpiox->setInput(gpiox);
}

void QGPIODataNodeWidget::onEventButtonPressed(int b)
{
    event_t event;
    event.type = b + BUTTON_OFFSET;
    transmit(event);
}

void QGPIODataNodeWidget::onOutputSet(gpiox_t gpiox)
{
    transmit(gpiox);
}
