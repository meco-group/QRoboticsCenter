#ifndef QGENERALIO_H
#define QGENERALIO_H

#include <QWidget>
#include <QLayout>
#include <QLineEdit>
#include <QLocalServer>
#include <QLocalSocket>

class QGeneralIO : public QWidget
{
    Q_OBJECT

public:
    explicit QGeneralIO(QString label = "", QWidget *parent = 0);

    QString text();
    void setText(QString text);

    QLineEdit *getLabel();

protected:
    virtual void setup(QWidget* w);

private:
    QLineEdit* _label;

};

#endif // QGENERALIO_H
