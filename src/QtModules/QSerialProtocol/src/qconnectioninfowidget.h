#ifndef QCONNECTIONINFOWIDGET_H
#define QCONNECTIONINFOWIDGET_H

#include <QWidget>
#include <QBrush>
#include <QString>
#include <QMap>
#include <QElapsedTimer>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qserialprotocol.h>
#include <qcustomplot.h>

#define BAR_WIDTH       0.9
#define RATE_THRESHOLD  2.0
#define REFRESH_COUNT   20

class QConnectionInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QConnectionInfoWidget(QWidget *parent = 0);

protected:
    virtual QSize sizeHint() const;

private:
    QCustomPlot *_plot;
    QSharedPointer<QCPAxisTickerText> _labels;
    QCPBars *_bars_count;
    QCPBars *_bars_rate;

    QMap<QString,unsigned int> _msg_map;
    QElapsedTimer _timer;
    unsigned long _msg_received;

    void setup();
    void updateAxis();
    void updateData();

public slots:
    void receive(QString msg);
    void reset();

};

#endif // QCONNECTIONINFOWIDGET_H
