#ifndef QSTEPPEDSINEEXCITATIONWIDGET_H
#define QSTEPPEDSINEEXCITATIONWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QSpinBox>
#include <QLabel>
#include <qexcitationdatanodewidgetinterface.h>
#include <qexcitationchannelwidget.h>

class QSteppedsineExcitationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QSteppedsineExcitationWidget(QExcitationChannelWidget *channels, QWidget *parent = 0);

    double fl();
    double fh();
    double fstep();
    double periods();
    double amplitude();
    unsigned int channels();

private:
    QDoubleSpinBox *_fl_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_fh_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_fstep_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_periods_spinbox = new QDoubleSpinBox(this);
    QDoubleSpinBox *_amplitude_spinbox = new QDoubleSpinBox(this);
    QLabel *_duration_label = new QLabel(this);
    QExcitationChannelWidget *_channels;

private slots:
    void updateDurationLabel();

};

class QSteppedsineDataNodeWidget : public QExcitationDataNodeWidgetInterface
{
    Q_OBJECT
public:
    explicit QSteppedsineDataNodeWidget(QExcitationChannelWidget *channels, QWidget *parent = 0);

    virtual QWidget* w();
    QSteppedsineExcitationWidget* steppedsineWidget();

    virtual void enableExcitation();
    virtual void disableExcitation();

private:
    QSteppedsineExcitationWidget *_w;

};

#endif // QSTEPPEDSINEEXCITATIONWIDGET_H
