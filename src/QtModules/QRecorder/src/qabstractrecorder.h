#ifndef QABSTRACTRECORDER_H
#define QABSTRACTRECORDER_H

#include <QObject>
#include <QAction>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <qdatanode.h>

class QAbstractRecorder : public QDataNode
{
    Q_OBJECT
public:
    explicit QAbstractRecorder(const QString& type, const int id = -1, QObject *parent = 0);

    bool isRecording();
    QAction *record();
    void start();
    void stop();

protected:
    QFile *_log;

private:
    const QString _type;
    const int _id;
    QAction *_record;

    void createHeader();
    void createFooter();
    virtual QString insertHeader();

public slots:
    void activate(bool);

};

#endif // QABSTRACTRECORDER_H
