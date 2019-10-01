#include "qprintlog.h"

QPrintLog::QPrintLog(QObject *parent) :
    QDataNode(parent), _stitcher(new QPrintStitcher(this))
{
    //do nothing
}

void QPrintLog::open()
{
    open(parent()->objectName());
}

void QPrintLog::open(QString filename)
{
    _log = new QFile(QDir::tempPath() + QDir::separator() + filename + ".txt",this);
    if(!_log->open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Error opening robot log file";
}

void QPrintLog::write(QString line)
{
    _log->write(line.toLatin1());
    _log->flush(); //force a quick update
}

void QPrintLog::receive(print_t print)
{
    QString line;
    _stitcher->stitch(QString(print.text),32);
    while(_stitcher->hasLine()) {
        line = _stitcher->getLine();
        write(line + '\n');
        emit newline(line);
    }
}
