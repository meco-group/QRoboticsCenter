#include "qgpiowidget.h"
#include "ui_qgpiowidget.h"

QGPIOWidget::QGPIOWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QGPIOWidget),
    double_list(QGPIOWIDGET_FLOAT_COUNT,0.0),
    integer_list(QGPIOWIDGET_INT_COUNT,0),
    _time(0),
    _paused(false)
{
    ui->setupUi(this);
    ui->plot->init(40,QGPIOWIDGET_IOCOUNT); //make graph with 12 functions

    _output_layout = new QBoxLayout(QBoxLayout::TopToBottom,0);
    _input_layout = new QGridLayout(0);
    grid_layout_buttons = new QGridLayout(0);
    QObject::connect(&buttons,SIGNAL(buttonClicked(int)),this,SLOT(sendButtonEvent(int)));

    int k;

    for(k = 0;k < 8;k++){
        // Label buttons
        buttons.addButton(new QPushButton("Button " + QString::number(k),this),k);
    }

    for(k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        // Outputs floats
        _float_outputs[k] = new QGeneralOutputFloat();
        _output_layout->addWidget(_float_outputs[k]);
    }

    for(k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        // Outputs ints
        _int_outputs[k] = new QGeneralOutputInt();
        _output_layout->addWidget(_int_outputs[k]);
    }

    for(k = 0;k < 4;k++){
        // Layout buttons
        grid_layout_buttons->addWidget(buttons.button(2*k),k,0);
        grid_layout_buttons->addWidget(buttons.button(2*k+1),k,1);

        // Channels row 1 (floats)
        _float_inputs[k] = new QGeneralInputFloat();
        _input_layout->addWidget(_float_inputs[k],0,k);

        // Channels row 2 (floats)
        _float_inputs[k+4] = new QGeneralInputFloat();
        _input_layout->addWidget(_float_inputs[k+4],1,k);

        // Channels row 3 (ints)
        _int_inputs[k] = new QGeneralInputInt();
        _input_layout->addWidget(_int_inputs[k],2,k);
    }

    for(k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        _float_inputs[k]->setChecked(false);
        QObject::connect(_float_inputs[k]->getCheckBox(),SIGNAL(stateChanged(int)),this,SLOT(checkCheckboxs()));
    }

    for(k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        _int_inputs[k]->setChecked(false);
        QObject::connect(_int_inputs[k]->getCheckBox(),SIGNAL(stateChanged(int)),this,SLOT(checkCheckboxs()));
    }

    for(k = 0;k < 12;k++){
        QPen pen = QPen(QColor::fromHsv(15+30*k,255,255));
        ui->plot->plottable(k)->setPen(pen);
    }

    setLabels();
    //loadSettings();

    checkCheckboxs();
    set_button = new QPushButton("Set");
    _output_layout->addWidget(set_button,QGPIOWIDGET_IOCOUNT);
    QObject::connect(set_button,SIGNAL(released()),this,SLOT(sendGPIO()));

    ui->channels_frame->setLayout(_input_layout);
    ui->frame_send->setLayout(_output_layout);
    ui->frame_buttons->setLayout(grid_layout_buttons);

    //start timer
    _plot_timer = startTimer(20,Qt::PreciseTimer);
    _gpio_timer = startTimer(10,Qt::PreciseTimer);

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

    settings.beginReadArray("IntChannels");
    for(int k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        settings.setArrayIndex(k);
        if(settings.contains("input")){
            if(!settings.value("input").toString().isEmpty())
                _int_inputs[k]->setText(settings.value("input").toString());
        }
        if(settings.contains("output")){
            if(!settings.value("output").toString().isEmpty())
                _int_outputs[k]->setText(settings.value("output").toString());
        }
        _int_inputs[k]->setChecked(settings.value("checked").toBool());
        _int_outputs[k]->setValue(settings.value("value").toInt());
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
    for(int k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        settings.setArrayIndex(k);
        settings.setValue("input",_float_inputs[k]->text());
        settings.setValue("checked",_float_inputs[k]->isChecked());
        settings.setValue("output",_float_outputs[k]->text());
        settings.setValue("value",_float_outputs[k]->value());
    }
    settings.endArray();

    settings.beginWriteArray("IntChannels");
    for(int k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        settings.setArrayIndex(k);
        settings.setValue("input",_int_inputs[k]->text());
        settings.setValue("checked",_int_inputs[k]->isChecked());
        settings.setValue("output",_int_outputs[k]->text());
        settings.setValue("value",_int_outputs[k]->value());
    }
    settings.endArray();
    settings.endGroup();
    settings.endGroup();
}

void QGPIOWidget::setLabels()
{
    int k;
    for(k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        _float_outputs[k]->setText("FloatOut" + QString::number(k));
        _float_inputs[k]->setText("FloatIn" + QString::number(k));
        QObject::connect(_float_outputs[k]->getLabel(),SIGNAL(textChanged(QString)),this,SLOT(inputLabelsSend()));
    }
    for(k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        _int_outputs[k]->setText("IntOut" + QString::number(k));
        _int_inputs[k]->setText("IntIn" + QString::number(k));
        QObject::connect(_int_outputs[k]->getLabel(),SIGNAL(textChanged(QString)),this,SLOT(inputLabelsSend()));
    }
}

QStringList QGPIOWidget::getLabels()
{
    QStringList labels;
    labels.reserve(QGPIOWIDGET_IOCOUNT);

    for(int k = 0;k < QGPIOWIDGET_FLOAT_COUNT;k++){
        labels.append(_float_inputs[k]->text());
    }
    for(int k = 0;k < QGPIOWIDGET_INT_COUNT;k++){
        labels.append(_int_inputs[k]->text());
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

        for(k = 0; k < QGPIOWIDGET_FLOAT_COUNT ; k++){
            ui->plot->addDataPoint(_time, _float_inputs[k]->valueDouble(), k);
        }
        for(k = 0; k < QGPIOWIDGET_INT_COUNT ; k++){
            ui->plot->addDataPoint(_time, _int_inputs[k]->valueDouble(), k+QGPIOWIDGET_FLOAT_COUNT);
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

void QGPIOWidget::setInput(gpio_t gpio)
{
    int k;
    for(k=0;k<QGPIOWIDGET_FLOAT_COUNT;k++)
        _float_inputs[k]->setValue(gpio.gpio_float[k]);
    for(k=0;k<QGPIOWIDGET_INT_COUNT;k++)
        _int_inputs[k]->setValue(gpio.gpio_int[k]);
}

void QGPIOWidget::checkCheckboxs()
{
    for(int k = 0;k < QGPIOWIDGET_FLOAT_COUNT; k++){
        ui->plot->plottable(k)->setVisible(_float_inputs[k]->isChecked());
    }
    for(int k = 0;k < QGPIOWIDGET_INT_COUNT; k++){
        ui->plot->plottable(k+QGPIOWIDGET_FLOAT_COUNT)->setVisible(_int_inputs[k]->isChecked());
    }
}

void QGPIOWidget::inputLabelsSend()
{
    emit inputLabelsSet(getLabels());
}

void QGPIOWidget::sendGPIO()
{
    int k;
    gpio_t gpio;

    gpio.time = 0;
    for(k=0;k<QGPIOWIDGET_FLOAT_COUNT;k++)
        gpio.gpio_float[k] = _float_outputs[k]->value();

    for(k=0;k<QGPIOWIDGET_INT_COUNT;k++)
        gpio.gpio_int[k] = _int_outputs[k]->value();

    emit setOutput(gpio);
}

void QGPIOWidget::sendButtonEvent(int id)
{
    emit eventButtonPressed(id);
}
