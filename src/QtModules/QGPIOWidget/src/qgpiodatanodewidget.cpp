#include "qgpiodatanodewidget.h"

QGPIODataNodeWidget::QGPIODataNodeWidget(QWidget *parent) :
    QDataNodeWidget(parent), _gpio(new QGPIOWidget(parent))
{
    QObject::connect(_gpio, &QGPIOWidget::setOutput, this, &QGPIODataNodeWidget::onOutputSet);
    QObject::connect(_gpio, &QGPIOWidget::eventButtonPressed, this, &QGPIODataNodeWidget::onEventButtonPressed);
    QObject::connect(this, SIGNAL(transmit(gpio_t)), _gpio, SLOT(setInput(gpio_t)));
}

QWidget *QGPIODataNodeWidget::w()
{
    return _gpio;
}

QGPIOWidget *QGPIODataNodeWidget::gpiow()
{
    return _gpio;
}

void QGPIODataNodeWidget::saveState(QString group)
{
    _gpio->saveState(group);
}

void QGPIODataNodeWidget::restoreState(QString group)
{
    _gpio->restoreState(group);
}

void QGPIODataNodeWidget::receive(gpio_t gpio)
{
    _gpio->setInput(gpio);
}

void QGPIODataNodeWidget::onEventButtonPressed(int b)
{
    event_t event;
    event.type = b + BUTTON_OFFSET;
    transmit(event);
}

void QGPIODataNodeWidget::onOutputSet(gpio_t gpio)
{
    transmit(gpio);
}
