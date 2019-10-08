#ifndef QATTITUDERECORDER_H
#define QATTITUDERECORDER_H

#include <qxmlrecorder.h>

class QAttitudeRecorder : public QXMLRecorder
{
    Q_OBJECT
public:
    QAttitudeRecorder(QObject* parent = 0);

private:
    virtual QString insertHeader();

public slots:
    virtual void receive(attitude_t attitude);

};

#endif // QATTITUDERECORDER_H
