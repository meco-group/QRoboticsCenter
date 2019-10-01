#include "qtypecommandwidget.h"

QTypeCommandWidget::QTypeCommandWidget(QString name, QWidget *parent) : QWidget(parent)
{
    setObjectName(name);
    _layout->addStretch(1.0);
    setLayout(_layout);
}

void QTypeCommandWidget::add(QTypeCommandInterface *port)
{
    addWidget(port->w());
    _ports.append(port);
}

void QTypeCommandWidget::addWidget(QWidget *widget)
{
    _layout->insertWidget(_layout->count()-1, widget);
}

void QTypeCommandWidget::transmitTo(QDataNode *other)
{
    QListIterator<QTypeCommandInterface *> i(_ports);
    while(i.hasNext()) {
        i.next()->transmitTo(other);
    }
}

void QTypeCommandWidget::saveState(QString group)
{
    QListIterator<QTypeCommandInterface *> i(_ports);
    while(i.hasNext()) {
        i.next()->saveState(group + "/" + objectName());
    }
}

void QTypeCommandWidget::restoreState(QString group)
{
    QListIterator<QTypeCommandInterface *> i(_ports);
    while(i.hasNext()) {
        i.next()->restoreState(group + "/" + objectName());
    }
}

void QTypeCommandWidget::transmit()
{
    for(int i=0; i<_ports.size(); i++){
        if(_ports[i]->enabled()) {
            _ports[i]->transmit_packet();
        }
    }
}

void QTypeCommandWidget::reset()
{
    for(int i=0; i<_ports.size(); i++){
        _ports[i]->reset();
    }
}
