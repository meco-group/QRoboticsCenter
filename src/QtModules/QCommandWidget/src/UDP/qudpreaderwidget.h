#ifndef QUDPREADERWIDGET_H
#define QUDPREADERWIDGET_H

#include <QWidget>
#include <qudpreader.h>
#include <QSettings>

namespace Ui {
class QUdpReaderWidget;
}

class QUdpReaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QUdpReaderWidget(quint64 line_size, QString name, QWidget *parent = 0);
    ~QUdpReaderWidget();

    QUdpReader* getUdpReader();
    QByteArray readLine();
    bool enabled();

    void saveState(QString group);
    void restoreState(QString group);

private:
    void updatePort();

private slots:
    void on_incoming_port_valueChanged(int arg1);

private:
    Ui::QUdpReaderWidget *ui;
    QUdpReader* _udp_port;

};

#endif // QUDPREADERWIDGET_H
