#include "qcommandwidget.h"

QCommandWidget::QCommandWidget(QWidget *parent) :
    QWidget(parent)
{
    setObjectName("command_widget");

    _layout = new QHBoxLayout();
    _button_layout = new QVBoxLayout();
    _button_layout->addStretch();
    _buttons = new QButtonGroup(this);
    _buttons->setExclusive(true);

    _frequency = new QComboBox();
    _frequency->setFixedWidth(80);
    QList<int> freqs{1,5,10,20,50,100,200};
    QListIterator<int> i(freqs);
    while(i.hasNext()){
        int freq = i.next();
        _frequency->addItem(QString::number(freq) + "Hz", freq);
    }
    _frequency->setCurrentIndex(2);

    _controls_layout = new QHBoxLayout();
    QPushButton* start = new QPushButton("start");
    start->setCheckable(true);
    connect(start,&QPushButton::toggled,this,&QCommandWidget::startToggled);
    QPushButton* reset = new QPushButton("reset");
    connect(reset,&QPushButton::clicked,this,&QCommandWidget::reset);
    _controls_layout->addWidget(start);
    _controls_layout->addWidget(reset);
    _controls_layout->addWidget(_frequency);

    _content_layout = new QVBoxLayout();
    _stack = new QStackedWidget();
    _content_layout->addWidget(_stack,1);
    _content_layout->addLayout(_controls_layout);

    setLayout(_layout);
    _layout->addLayout(_button_layout);
    _layout->addLayout(_content_layout);

    QObject::connect(_buttons,SIGNAL(buttonToggled(int,bool)),_stack,SLOT(setCurrentIndex(int)));
}

void QCommandWidget::setCurrentInputWidget(int index)
{
    if(index<_stack->count()){
        _buttons->button(index)->setChecked(true);
    }
}

void QCommandWidget::saveState(QString group)
{
    QListIterator<QTypeCommandWidget *> i(_ports);
    while(i.hasNext()) {
        i.next()->saveState(group + "/" + objectName());
    }
}

void QCommandWidget::restoreState(QString group)
{
    QListIterator<QTypeCommandWidget *> i(_ports);
    while(i.hasNext()) {
        i.next()->restoreState(group + "/" + objectName());
    }
}

void QCommandWidget::add(QTypeCommandWidget *w)
{
    _ports.append(w);
    QPushButton* button = new QPushButton(w->objectName(),this);
    button->setMinimumSize(80,80);
    button->setMaximumSize(80,80);
    button->setCheckable(true);
    _button_layout->insertWidget(_button_layout->count()-1,button);
    _button_layout->setAlignment(button,Qt::AlignTop);

    _buttons->addButton(button,_stack->count());
    _stack->addWidget(w);
    setCurrentInputWidget(_stack->count()-1);
}

QTypeCommandWidget *QCommandWidget::currentInputWidget()
{
    return _ports.value(_stack->currentIndex());
}

void QCommandWidget::timerEvent(QTimerEvent *)
{
    currentInputWidget()->transmit();
}

void QCommandWidget::startToggled(bool checked)
{
    if(checked){
        start();
    } else {
        stop();
    }
}

void QCommandWidget::start()
{
    _frequency->setEnabled(false);
    _timer_id = startTimer(1000/(_frequency->currentData().toInt()),Qt::PreciseTimer);
}

void QCommandWidget::stop()
{
    _frequency->setEnabled(true);
    killTimer(_timer_id);
}

void QCommandWidget::reset()
{
    currentInputWidget()->reset();
}


void QCommandWidget::transmitTo(QDataNode *other)
{
    QListIterator<QTypeCommandWidget *> i(_ports);
    while(i.hasNext())
        i.next()->transmitTo(other);
}
