#ifndef QEXCITATIONCHANNELWIDGET_H
#define QEXCITATIONCHANNELWIDGET_H

#include <QWidget>
#include <QFormLayout>
#include <QComboBox>

#define QEXCITATIONCHANNELWIDGET_NROFCHANS 8

class QExcitationChannelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QExcitationChannelWidget(QWidget *parent = 0);

    unsigned int getChannels();

private:
    QComboBox* _channels[QEXCITATIONCHANNELWIDGET_NROFCHANS];

};

#endif // QEXCITATIONCHANNELWIDGET_H
