#include "qexcitationchannelwidget.h"

QExcitationChannelWidget::QExcitationChannelWidget(QWidget *parent) : QWidget(parent)
{
    QFormLayout *l = new QFormLayout(0);
    for(int k=0; k<QEXCITATIONCHANNELWIDGET_NROFCHANS; k++){
        _channels[k] = new QComboBox(this);
        _channels[k]->addItem("0%",0);
        _channels[k]->addItem("25%",1);
        _channels[k]->addItem("50%",2);
        _channels[k]->addItem("100%",3);
        _channels[k] ->setCurrentIndex(0);
        l->addRow("channel " + QString::number(k+1), _channels[k]);
    }

    setLayout(l);
}

unsigned int QExcitationChannelWidget::getChannels()
{
    unsigned int channels = 0;
    for(int k=0;k<QEXCITATIONCHANNELWIDGET_NROFCHANS;k++){
        channels |= ((quint8)(_channels[k]->currentIndex()) << (k<<1));
    }
    return channels;
}
