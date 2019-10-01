#ifndef QGAMEPADCOMMANDDATANODEWIDGET_H
#define QGAMEPADCOMMANDDATANODEWIDGET_H

#include <qtypecommandinterface.h>
#include <qgamepadinputwidget.h>

class QGamepadCommandDataNodeWidget : public QTypeCommandInterface
{
public:
    QGamepadCommandDataNodeWidget(QString name, QWidget *parent = 0);

    virtual QWidget *w();
    QGamepadInputWidget *commandWidget();

    virtual bool enabled();
    virtual void reset();

    virtual void saveState(QString group);
    virtual void restoreState(QString group);

    QGamepadEntry *add(QString name);

private:
    QGamepadInputWidget* _cmd_widget;

public slots:
    void on_axis_changed(int axis, double value);

};

#endif // QGAMEPADCOMMANDDATANODEWIDGET_H
