#ifndef QRECORDERWIDGET_H
#define QRECORDERWIDGET_H

#include <QObject>
#include <QLabel>
#include <QMenu>
#include <QDebug>
#include <qabstractrecorder.h>

class QRecorderWidget : public QLabel
{
    Q_OBJECT

public:
    explicit QRecorderWidget(QWidget *parent = 0);
    void add(QAbstractRecorder *);
    void setQuickRecord(QAbstractRecorder *);
    void connectTo(QDataNode *);

    QMenu *menu();
    QAction *quickRecord();

private:
    bool _is_recording;
    int _timerid;
    void timerEvent(QTimerEvent *);

    QList<QAbstractRecorder*> _recorders;
    QMenu *_menu = new QMenu("Recorders");
    QAction *_quick_record = new QAction(this);

public slots:
    void activate(bool active);
    void start();
    void stop();
};

#endif // QRECORDERWIDGET_H
