#ifndef QEXCITATIONWIDGET_H
#define QEXCITATIONWIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QComboBox>
#include <qexcitationchannelwidget.h>
#include <qmultisineexcitationwidget.h>
#include <qsweptsineexcitationwidget.h>
#include <qsteppedsineexcitationwidget.h>

class QExcitationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QExcitationWidget(QWidget *parent = 0);

    QPushButton *enableButton();
    QPushButton *disableButton();
    void transmitTo(QDataNode *other);

private:
    QStackedWidget *_stack = new QStackedWidget();
    QComboBox *_selection = new QComboBox();
    QPushButton *_enable_button = new QPushButton("enable");
    QPushButton *_disable_button = new QPushButton("disable");
    QExcitationChannelWidget *_channels = new QExcitationChannelWidget();
    QList<QExcitationDataNodeWidgetInterface *> _excitation_list;

    void addExcitation(const QString name, QExcitationDataNodeWidgetInterface *w);
    QExcitationDataNodeWidgetInterface *getExcitation();
    QExcitationDataNodeWidgetInterface *getExcitation(int idx);

public slots:
    void on_excitation_enabled();
    void on_excitation_disabled();

};

#endif // QEXCITATIONWIDGET_H
