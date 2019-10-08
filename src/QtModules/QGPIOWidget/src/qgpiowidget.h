#ifndef QGPIOWIDGET_H
#define QGPIOWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QSettings>
#include <qrunningplot.h>

#include <qgeneraloutput.h>
#include <qgeneraloutputint.h>
#include <qgeneraloutputfloat.h>
#include <qgeneralinput.h>
#include <qgeneralinputint.h>
#include <qgeneralinputfloat.h>

#include <qserialprotocol.h>

#define QGPIOWIDGET_FLOAT_COUNT 12
#define QGPIOWIDGET_IOCOUNT     12
#define QGPIOWIDGET_BUTTONCOUNT  4

namespace Ui {
class QGPIOWidget;
}

class QGPIOWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QGPIOWidget(QWidget *parent = 0);
    ~QGPIOWidget();

    void restoreState(QString group);
    void saveState(QString group);
    QStringList getLabels();

private:
    Ui::QGPIOWidget *ui;

    QGridLayout* _input_layout;
    QGeneralInputFloat* _float_inputs[QGPIOWIDGET_FLOAT_COUNT];

    QRunningPlot* plot;

    QBoxLayout* _output_layout;
    QGeneralOutputFloat* _float_outputs[QGPIOWIDGET_FLOAT_COUNT];
    QPushButton* set_button;

    QGridLayout* grid_layout_buttons;
    QButtonGroup buttons;

    QVector<float> double_list;

    double _time;
    bool _paused;

    int _plot_timer;
    int _gpio_timer;

    void setLabels();

    bool running();
    bool paused();

public slots:
    void setInput(gpiox_t gpiox);
    void sendButtonEvent(int id);
    void inputLabelsSend();

    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void checkCheckboxs();
    void sendGPIO();

signals:
    void eventButtonPressed(int b);
    void setOutput(gpiox_t gpiox);
    void inputLabelsSet(QStringList labels);
};

#endif // QGPIOWIDGET_H
