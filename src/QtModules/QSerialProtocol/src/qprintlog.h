#ifndef QPRINTLOG_H
#define QPRINTLOG_H

#include <qdatanode.h>
#include <QFile>
#include <QDir>
#include <qprintstitcher.h>
#include <QDebug>

class QPrintLog : public QDataNode
{
    Q_OBJECT

public:
    explicit QPrintLog(QObject *parent = 0);
    void open();
    void open(QString filename);

private:
    QPrintStitcher *_stitcher;
    QFile *_log;
    void write(QString line);

public slots:
    virtual void receive(print_t);

signals:
    void newline(QString);

};

#endif // QPRINTLOG_H
