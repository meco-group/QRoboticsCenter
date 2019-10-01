#include "qoutputwidget.h"

QOutputWidget::QOutputWidget(QString name, QWidget *parent) :
    QWidget(parent)
{
    setObjectName(name);
    setLayout(new QVBoxLayout(this));
}

void QOutputWidget::addSender(QSenderInterface *sender)
{
    layout()->addWidget(sender->getWidget());
    _senders.append(sender);
}

void QOutputWidget::send(QList<QVariant> list)
{
    for(int i=0; i<_senders.size(); i++){
        if(_senders[i]->enabled()){
            _senders[i]->sendPackets(list);
        }
    }
}

void QOutputWidget::reset()
{
    for(int i=0; i<_senders.size(); i++){
        _senders[i]->reset();
    }
}
