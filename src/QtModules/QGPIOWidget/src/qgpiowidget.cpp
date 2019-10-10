#include "qgpiowidget.h"
#include "ui_qgpiowidget.h"

QGPIOWidget::QGPIOWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGPIOWidget),
    double_list(QGPIOWIDGET_FLOAT_COUNT, 0.0),
    _time(0),
    _paused(false)
{
  ui->setupUi(this);
  ui->plot->init(40, QGPIOWIDGET_IOCOUNT); //make graph with 12 functions

  _output_layout = new QBoxLayout(QBoxLayout::TopToBottom,0);
  _input_layout = new QGridLayout(0);
  grid_layout_buttons = new QGridLayout(0);
  QObject::connect(&buttons, SIGNAL(buttonClicked(int)), this, SLOT(sendButtonEvent(int)));

  int k;
  for(k = 0; k < QGPIOWIDGET_BUTTONCOUNT; k++) {
    // Label buttons
    buttons.addButton(new QPushButton("Button " + QString::number(k), this), k);
    // Layout buttons
    grid_layout_buttons->addWidget(buttons.button(k), k, 0);
  }

  for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
    // Outputs floats
    _float_outputs[k] = new QGeneralOutputFloat();
    _output_layout->addWidget(_float_outputs[k]);
  }

  for(k = 0; k < 4; k++) {
    // row 1
    _float_inputs[k] = new QGeneralInputFloat();
    _input_layout->addWidget(_float_inputs[k], 0, k);
    // row 2
    _float_inputs[k+4] = new QGeneralInputFloat();
    _input_layout->addWidget(_float_inputs[k+4], 1, k);
    // row 3
    _float_inputs[k+8] = new QGeneralInputFloat();
    _input_layout->addWidget(_float_inputs[k+8], 2, k);
  }

  for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
    _float_inputs[k]->setChecked(false);
    QObject::connect(_float_inputs[k]->getCheckBox(), SIGNAL(stateChanged(int)), this, SLOT(checkCheckboxs()));
  }

  for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
    QPen pen = QPen(QColor::fromHsv(25*k, 255, 255));
    ui->plot->plottable(k)->setPen(pen);
  }

  setLabels();
  //loadSettings();

  checkCheckboxs();
  set_button = new QPushButton("Set");
  _output_layout->addWidget(set_button, QGPIOWIDGET_IOCOUNT);
  QObject::connect(set_button, SIGNAL(released()), this, SLOT(sendGPIO()));

  ui->channels_frame->setLayout(_input_layout);
  ui->frame_send->setLayout(_output_layout);
  ui->frame_buttons->setLayout(grid_layout_buttons);

  //start timer
  _plot_timer = startTimer(50, Qt::PreciseTimer);
  _gpio_timer = startTimer(10, Qt::PreciseTimer);

  setAttribute(Qt::WA_DeleteOnClose);
  show();
}

QGPIOWidget::~QGPIOWidget()
{
    //saveSettings();
    delete ui;
}

void QGPIOWidget::restoreState(QString group)
{
    QSettings settings;

    // set parent group
    settings.beginGroup(group);

    // set window group
    settings.beginGroup("QGPIOWidget");

    // restore window settings
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());

    // restore channel names
    settings.beginReadArray("FloatChannels");
    for(int k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        settings.setArrayIndex(k);
        if(settings.contains("input")){
            if(!settings.value("input").toString().isEmpty())
                _float_inputs[k]->setText(settings.value("input").toString());
        }
        if(settings.contains("output")){
            if(!settings.value("output").toString().isEmpty())
                _float_outputs[k]->setText(settings.value("output").toString());
        }
        _float_inputs[k]->setChecked(settings.value("checked").toBool());
        _float_outputs[k]->setValue(settings.value("value").toDouble());
    }
    settings.endArray();

    settings.endGroup();
    settings.endGroup();
}

void QGPIOWidget::saveState(QString group)
{
    QSettings settings;

    // set parent group
    settings.beginGroup(group);

    // set window group
    settings.beginGroup("QGPIOWidget");

    // save window settings
    settings.setValue("size", size());
    settings.setValue("pos", pos());

    // save channel states
    settings.beginWriteArray("FloatChannels");
    for(int k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++){
        settings.setArrayIndex(k);
        settings.setValue("input",_float_inputs[k]->text());
        settings.setValue("checked",_float_inputs[k]->isChecked());
        settings.setValue("output",_float_outputs[k]->text());
        settings.setValue("value",_float_outputs[k]->value());
    }
    settings.endArray();

    settings.endGroup();
    settings.endGroup();
}

void QGPIOWidget::setLabels()
{
    int k;
    for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
        _float_outputs[k]->setText("FloatOut" + QString::number(k));
        _float_inputs[k]->setText("FloatIn" + QString::number(k));
        QObject::connect(_float_outputs[k]->getLabel(),SIGNAL(textChanged(QString)),this,SLOT(inputLabelsSend()));
    }
}

QStringList QGPIOWidget::getLabels()
{
    QStringList labels;
    labels.reserve(QGPIOWIDGET_IOCOUNT);

    for(int k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
        labels.append(_float_inputs[k]->text());
    }

    return labels;
}

bool QGPIOWidget::running()
{
    return !_paused;
}

bool QGPIOWidget::paused()
{
    return _paused;
}

void QGPIOWidget::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == _gpio_timer){
        //do something with gpio stuff?
    } else if(event->timerId() == _plot_timer) {
        int k;
        _time += 0.05;

        for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT; k++) {
            ui->plot->addDataPoint(_time, _float_inputs[k]->valueDouble(), k);
        }

        if(running()){
            ui->plot->reDraw();
        }
    }
}

void QGPIOWidget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_P:
        _paused = !_paused;
        break;
    }
}

void QGPIOWidget::setInput(gpiox_t gpiox)
{
    int k;
    for(k=0; k<QGPIOWIDGET_FLOAT_COUNT; k++)
        _float_inputs[k]->setValue(gpiox.gpio_float[k]);
}

void QGPIOWidget::checkCheckboxs()
{
    for(int k = 0;k < QGPIOWIDGET_FLOAT_COUNT; k++){
        ui->plot->plottable(k)->setVisible(_float_inputs[k]->isChecked());
    }
}

void QGPIOWidget::inputLabelsSend()
{
    emit inputLabelsSet(getLabels());
}

void QGPIOWidget::sendGPIO()
{
    int k;
    gpiox_t gpiox;

    gpiox.time = 0;
    for(k=0; k<QGPIOWIDGET_FLOAT_COUNT; k++)
        gpiox.gpio_float[k] = _float_outputs[k]->value();


    emit setOutput(gpiox);
}

void QGPIOWidget::sendButtonEvent(int id)
{
    emit eventButtonPressed(id);
}
