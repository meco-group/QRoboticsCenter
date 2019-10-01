#ifndef QCOMMANDWIDGET_H
#define QCOMMANDWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>
#include <QComboBox>
#include <qtypecommandwidget.h>

class QCommandWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QCommandWidget(QWidget *parent = 0);

    void add(QTypeCommandWidget *w);
    QTypeCommandWidget *currentInputWidget();
    void setCurrentInputWidget(int index);

    void saveState(QString group);
    void restoreState(QString group);

    void transmitTo(QDataNode *other);

protected:
    void timerEvent(QTimerEvent *);

private:
    QList<QTypeCommandWidget*> _ports;

    int _timer_id;

    QHBoxLayout* _layout;
    QHBoxLayout* _controls_layout;
    QVBoxLayout* _button_layout;
    QVBoxLayout* _content_layout;
    QButtonGroup* _buttons;
    QStackedWidget* _stack;
    QComboBox* _frequency;

    void setup();

public slots:
    void startToggled(bool checked);
    void start();
    void stop();
    void reset();

};

#endif // QCOMMANDWIDGET_H
