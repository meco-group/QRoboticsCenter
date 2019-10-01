#ifndef QSENDERINTERFACE_H
#define QSENDERINTERFACE_H

#include <qvariant.h>
#include <qwidget.h>

class QSenderInterface
{
public:
    virtual void sendPacket(QVariant packet) = 0;
    virtual void sendPackets(QList<QVariant> packets) = 0;
    virtual QWidget* getWidget() = 0;

    virtual bool enabled() = 0;
    virtual void reset() = 0;

};

#endif // QSENDERINTERFACE_H
