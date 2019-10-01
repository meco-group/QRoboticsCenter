#ifndef QVELOCITYRECORDER_H
#define QVELOCITYRECORDER_H

#include <qabstractrecorder.h>

class QVelocityRecorder : public QAbstractRecorder
{
    Q_OBJECT
public:
    QVelocityRecorder(QObject* parent = 0);

private:
    virtual QString insertHeader();

public slots:
    virtual void receive(velocity_t velocity);

};

#endif // QVELOCITYRECORDER_H
