#ifndef QMULTISINEEXCITATIONWIDGET_H
#define QMULTISINEEXCITATIONWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QSpinBox>
#include <qexcitationdatanodewidgetinterface.h>
#include <qexcitationchannelwidget.h>

class QMultisineExcitationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QMultisineExcitationWidget(QExcitationChannelWidget *channels, QWidget *parent = 0);

    int realization();
    double amplitude();
    unsigned int channels();

private:
    QSpinBox *_realization_spinbox = new QSpinBox(this);
    QDoubleSpinBox *_amplitude_spinbox = new QDoubleSpinBox(this);
    QExcitationChannelWidget *_channels;

};

class QMultisineDataNodeWidget : public QExcitationDataNodeWidgetInterface
{
    Q_OBJECT
public:
    explicit QMultisineDataNodeWidget(QExcitationChannelWidget *channels, QWidget *parent = 0);

    virtual QWidget* w();
    QMultisineExcitationWidget* multisineWidget();

    virtual void enableExcitation();
    virtual void disableExcitation();

private:
    QMultisineExcitationWidget *_w;

};

#endif // QMULTISINEEXCITATIONWIDGET_H
