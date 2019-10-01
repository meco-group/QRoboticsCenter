#include "qrecorderwidget.h"

QRecorderWidget::QRecorderWidget(QWidget *parent) : QLabel(parent), _is_recording(false)
{
    setNum(0);
    setFrameShadow(Sunken);
    setFrameShape(StyledPanel);
    setMinimumSize(80,14);
    setAlignment(Qt::AlignCenter);
    setStyleSheet("QLabel { background-color : Forestgreen; color : black;  border-radius : 4px; border-style: outset; border-width: 1px; border-color: gray;}");

    _quick_record->setShortcut(Qt::CTRL + Qt::Key_R);
    addAction(_quick_record);
}

void QRecorderWidget::add(QAbstractRecorder *rec)
{
    _recorders.append(rec);
    _menu->addAction(rec->record());
    QObject::connect(rec->record(), &QAction::toggled, this, &QRecorderWidget::activate);
}

void QRecorderWidget::setQuickRecord(QAbstractRecorder *rec)
{
    QObject::disconnect(_quick_record, SIGNAL(triggered()));
    QObject::connect(_quick_record, &QAction::triggered, rec->record(), &QAction::toggle);
}

void QRecorderWidget::connectTo(QDataNode *n)
{
    QListIterator<QAbstractRecorder*> i(_recorders);
    while(i.hasNext())
        i.next()->connectTo(n);
}

QMenu *QRecorderWidget::menu()
{
    return _menu;
}

QAction *QRecorderWidget::quickRecord()
{
    return _quick_record;
}

void QRecorderWidget::timerEvent(QTimerEvent *)
{
    setNum(text().toDouble() + 1.0);
}

void QRecorderWidget::activate(bool active)
{
    int running_count = 0;
    QListIterator<QAbstractRecorder*> i(_recorders);
    while(i.hasNext()) {
        running_count += (int)(i.next()->isRecording());
    }

    if(active && (running_count == 1)) {
        start();
    } else if (!active && (running_count==0)) {
        stop();
    }

}

void QRecorderWidget::start()
{
    setStyleSheet("QLabel { background-color : red; color : black; border-radius : 4px; border-style: outset; border-width: 1px; border-color: gray;}");
    _timerid = startTimer(1000);
    setNum(0.0);
}

void QRecorderWidget::stop()
{
    setStyleSheet("QLabel { background-color : Forestgreen; color : black;  border-radius : 4px; border-style: outset; border-width: 1px; border-color: gray;}");
    killTimer(_timerid);
}
