#ifndef QCSVREADERWIDGET_H
#define QCSVREADERWIDGET_H

#include <QWidget>
#include <qcsvreader.h>
#include <qfileinfo.h>
#include <qfiledialog.h>

namespace Ui {
class QCsvReaderWidget;
}

class QCsvReaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QCsvReaderWidget(QString name, QWidget *parent = 0);
    ~QCsvReaderWidget();

    QCsvReader* getCsvReader();
    QList<double> readLine();

    bool enabled();
    void reset();

    void saveState(QString group);
    void restoreState(QString group);

private:
    void updateFileName();
    void updateProgressBar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QCsvReaderWidget *ui;
    QCsvReader* _csv_reader;

};

#endif // QCSVREADERWIDGET_H
