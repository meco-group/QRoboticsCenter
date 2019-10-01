#ifndef QAXISDIALOG_H
#define QAXISDIALOG_H

#include <QDialog>
#include <qcustomplot.h>

namespace Ui {
class QAxisDialog;
}

class QAxisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QAxisDialog(QCPAxis *axis, bool *autoscale, QWidget *parent = 0);
    ~QAxisDialog();

    static QDialog::DialogCode setSettings(QCPAxis *axis, bool *autoscale);

private:
    Ui::QAxisDialog *ui;
    QCPAxis *_axis;
    bool *_autoscale;

    void setReadOnly();
    void setEditable();

    void closeEvent(QCloseEvent* e);

private slots:
    void handleCheckboxToggled(bool autoscale);
};

#endif // QAXISDIALOG_H
