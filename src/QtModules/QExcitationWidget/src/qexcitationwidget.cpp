#include "qexcitationwidget.h"

QExcitationWidget::QExcitationWidget(QWidget *parent) : QWidget(parent)
{
    addExcitation("multisine", new QMultisineDataNodeWidget(_channels));
    addExcitation("sweptsine", new QSweptsineDataNodeWidget(_channels));
    addExcitation("steppedsine", new QSteppedsineDataNodeWidget(_channels));

    QVBoxLayout *l = new QVBoxLayout(0);
    l->addWidget(_selection);
    l->addWidget(_stack);
    l->addStretch(1);
    l->addWidget(_enable_button);
    l->addWidget(_disable_button);

    QHBoxLayout *h = new QHBoxLayout(this);
    h->addLayout(l);
    h->addWidget(_channels);
    setLayout(h);

    _selection->setCurrentIndex(0);
    _stack->setCurrentIndex(0);
    QObject::connect(_selection, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), _stack, &QStackedWidget::setCurrentIndex);
    QObject::connect(_enable_button, &QPushButton::clicked, this, &QExcitationWidget::on_excitation_enabled);
    QObject::connect(_disable_button, &QPushButton::clicked, this, &QExcitationWidget::on_excitation_disabled);
}

QPushButton *QExcitationWidget::enableButton()
{
    return _enable_button;
}

QPushButton *QExcitationWidget::disableButton()
{
    return _disable_button;
}

void QExcitationWidget::transmitTo(QDataNode *other)
{
    QListIterator<QExcitationDataNodeWidgetInterface *> i(_excitation_list);
    while(i.hasNext())
        i.next()->transmitTo(other);
}

void QExcitationWidget::addExcitation(const QString name, QExcitationDataNodeWidgetInterface *w)
{
    _selection->addItem(name);
    _stack->addWidget(w->w());
    _excitation_list.append(w);
}

QExcitationDataNodeWidgetInterface *QExcitationWidget::getExcitation()
{
    return getExcitation(_stack->currentIndex());
}

QExcitationDataNodeWidgetInterface *QExcitationWidget::getExcitation(int idx)
{
    return _excitation_list[idx];
}

void QExcitationWidget::on_excitation_enabled()
{
    getExcitation()->enableExcitation();
}

void QExcitationWidget::on_excitation_disabled()
{
    getExcitation()->disableExcitation();
}

