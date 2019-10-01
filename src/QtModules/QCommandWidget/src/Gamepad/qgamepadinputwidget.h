#ifndef QGAMEPADCOMMANDWIDGET_H
#define QGAMEPADCOMMANDWIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <qgamepadentry.h>
#include <QDebug>

namespace Ui {
class QGamepadInputWidget;
}

class QGamepadInputWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QGamepadInputWidget(QString name, QWidget *parent = 0);
    ~QGamepadInputWidget();

    bool enabled();

    QGamepadEntry *add(QString name);
    virtual void add(QGamepadEntry *entry);
    void saveState(QString group);
    void restoreState(QString group);

private:
    Ui::QGamepadInputWidget *ui;
    QList<QGamepadEntry *> _entries;

public slots:
    void on_axis_changed(int axis, double value);

};

#endif // QGAMEPADCOMMANDWIDGET_H
