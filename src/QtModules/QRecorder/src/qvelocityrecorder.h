#ifndef QVELOCITYRECORDER_H
#define QVELOCITYRECORDER_H

#include <qxmlrecorder.h>

class QVelocityRecorder : public QXMLRecorder
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
