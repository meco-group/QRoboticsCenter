#ifndef QGPIOINPUTDIALOG_H
#define QGPIOINPUTDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <qgpiowidget.h>

namespace Ui {
class QGPIOInputDialog;
}

class QGPIOInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QGPIOInputDialog(QWidget *parent = 0);
    ~QGPIOInputDialog();

    QAction *getPopupAction();

private:
    Ui::QGPIOInputDialog *ui;

    QFile* _file;
    QTextStream* _stream;
    quint64 _csv_begin;
    int _timer_id;
    bool _repeat;

    QAction *_popup;

    void readHeader();
    void readCsvLine();
    void resetCsv();

    void saveSettings();
    void loadSettings();

    void timerEvent(QTimerEvent *e);
    void closeEvent(QCloseEvent *e);

signals:
    void setGpioOutput(gpiox_t gpiox);

public slots:
    bool setFile(QString absolute_path);
    void openFile();
    void handleStartButton(bool checked);
    void start();
    void stop();

};

#endif // QGPIOINPUTDIALOG_H
