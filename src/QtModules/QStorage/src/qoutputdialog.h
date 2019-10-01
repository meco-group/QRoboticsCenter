#ifndef QEXTERNALPORTDIALOG_H
#define QEXTERNALPORTDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QAction>
#include <qoutputwidget.h>

class QOutputDialog : public QDialog
{
    Q_OBJECT
public:
    explicit QOutputDialog(QString name, QWidget *parent = 0);
    ~QOutputDialog();

    void addOutputWidget(QOutputWidget *w);
    QOutputWidget* currentOutputWidget();
    QOutputWidget *findOutputWidget(QString name);
    void setCurrentOutputWidget(int index);

    QAction* getPopupAction();

private:
    QList<QOutputWidget*> _ports;

    QAction* _popup;
    int _timer_id;

    QHBoxLayout* _layout;
    QHBoxLayout* _controls_layout;
    QVBoxLayout* _button_layout;
    QVBoxLayout* _content_layout;
    QButtonGroup* _buttons;
    QPushButton* _start;
    QStackedWidget* _stack;

    void layoutSetup();

public slots:
    void sendPacket(QVariant packet);
    void sendPackets(QList<QVariant> list);
    void reset();

};

#endif // QEXTERNALPORTDIALOG_H
