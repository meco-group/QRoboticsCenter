#ifndef QSWEPTSINEEXCITATIONWIDGET_H
#define QSWEPTSINEEXCITATIONWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QSpinBox>
#include <qexcitationdatanodewidgetinterface.h>
#include <qexcitationchannelwidget.h>

class QSweptsineExcitationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSweptsineExcitationWidget(QExcitationChannelWidget *channels, QWidget *parent = 0);

    double fl();
    double fh();
    double period();
    double amplitude();
    unsigned int channels();

private:
    QDoubleSpinBox *_fl_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_fh_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_period_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_amplitude_spinbox = new QDoubleSpinBox(this);
    QExcitationChannelWidget *_channels;

};

class QSweptsineDataNodeWidget : public QExcitationDataNodeWidgetInterface
{
    Q_OBJECT
public:
    explicit QSweptsineDataNodeWidget(QExcitationChannelWidget *channels, QWidget *parent = 0);

    virtual QWidget* w();
    QSweptsineExcitationWidget* sweptsineWidget();

    virtual void enableExcitation();
    virtual void disableExcitation();

private:
    QSweptsineExcitationWidget *_w;

};

#endif // QSWEPTSINEEXCITATIONWIDGET_H
