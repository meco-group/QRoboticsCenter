#include "qconnectioninfowidget.h"

QConnectionInfoWidget::QConnectionInfoWidget(QWidget *parent) :
    QWidget(parent),
    _labels(new QCPAxisTickerText),
    _timer()
{
    setup();

    _bars_rate = new QCPBars(_plot->xAxis, _plot->yAxis);
    _bars_rate->setWidth(BAR_WIDTH);

    _bars_count = new QCPBars(_plot->xAxis, _plot->yAxis2);
    _bars_count->setWidth(BAR_WIDTH);

    _bars_count->setBrush(QBrush(QColor(124, 252, 0, 100)));
    _bars_count->setPen(QPen(QColor(30, 130, 30), 1.0));
    _plot->xAxis->setTicker(_labels);
    _plot->xAxis->setTickLabelRotation(-90);
    _plot->xAxis->setTickLabelSide(QCPAxis::lsInside);
    _plot->yAxis->setRange(0,100);
    _plot->yAxis2->setVisible(true);

    this->reset();
}

QSize QConnectionInfoWidget::sizeHint() const
{
    return QSize(250,400);
}

void QConnectionInfoWidget::setup()
{
    _plot = new QCustomPlot(this);
    QPushButton *b = new QPushButton("reset");
    QObject::connect(b,&QPushButton::clicked, this, &QConnectionInfoWidget::reset);

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addSpacerItem(new QSpacerItem(20,6,QSizePolicy::MinimumExpanding));
    hlayout->addWidget(b);

    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addWidget(_plot, 1);
    vlayout->addLayout(hlayout, 0);
}


void QConnectionInfoWidget::updateAxis()
{
    // set range
    _plot->xAxis->setRange(-0.5, _msg_map.count()-0.5);

    // construct ticks
    QVector<double> pos(_msg_map.count());
    for (int k=0; k<_msg_map.count(); k++) { pos[k] = k; }
    _labels->setTicks(pos, QVector<QString>::fromList(_msg_map.keys()));

    // replot data
    updateData();
}

void QConnectionInfoWidget::updateData()
{
    _msg_received = 0; // refreshed
    double rate;

    QList<unsigned int> msg_counts = _msg_map.values();
    QVector<double> rate_bar_pos; rate_bar_pos.reserve(_msg_map.count());
    QVector<double> rate_bar_val; rate_bar_val.reserve(_msg_map.count());
    QVector<double> count_bar_pos; count_bar_pos.reserve(_msg_map.count());
    QVector<double> count_bar_val; count_bar_val.reserve(_msg_map.count());

    for(int k=0;k<_msg_map.count();k++){
        rate = (1000.0*msg_counts[k])/_timer.elapsed();
        if(rate>RATE_THRESHOLD){
            rate_bar_pos.append(k);
            rate_bar_val.append(rate);
        }
        else{
            count_bar_pos.append(k);
            count_bar_val.append(msg_counts[k]);
        }
    }

    _bars_rate->setData(rate_bar_pos, rate_bar_val ,true);
    _bars_count->setData(count_bar_pos, count_bar_val, true);
    _plot->yAxis2->rescale();
    _plot->replot();
}

void QConnectionInfoWidget::receive(QString msg)
{
    // Add data to the message map
    if(_msg_map.contains(msg)) {
        _msg_map[msg]++;
        _msg_received++;
        if(_msg_received > REFRESH_COUNT){ updateData(); }
    } else {
        _msg_map[msg] = 1;
        updateAxis();
    }
}

void QConnectionInfoWidget::reset()
{
    _timer.restart();
    _msg_received = 0;
    _msg_map.clear();
}
