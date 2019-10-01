#ifndef QCSVREADER_H
#define QCSVREADER_H

#include <QObject>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>

class QCsvReader : public QObject
{
    Q_OBJECT

public:
    explicit QCsvReader(QObject *parent = 0);

    bool setFile(QString filename);
    QFile *getFile();
    QString fileName(bool full = true);
    void reset();

    QList<double> readLine(bool *at_end = Q_NULLPTR);
    double progress();

private:
    QFile* _file;
    QTextStream* _stream;

signals:
    void atEnd();

};

#endif // QCSVREADER_H
