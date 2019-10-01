#ifndef QPRINTSTITCHER_H
#define QPRINTSTITCHER_H

#include <QObject>
#include <QDebug>

class QPrintStitcher : public QObject
{
    Q_OBJECT

public:
    explicit QPrintStitcher(QObject *parent = 0);

    bool stitch(QString part, int size);
    bool hasLine();
    QString getLine();

private:
    QStringList _lines;
    QString _stream;

};

#endif // QPRINTSTITCHER_H
