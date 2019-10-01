#ifndef QEXCITATIONDOCK_H
#define QEXCITATIONDOCK_H

#include <qrobotwindowdock.h>
#include <qexcitationwidget.h>

class QExcitationDock : public QRobotWindowDock
{
    Q_OBJECT
public:
    explicit QExcitationDock(QRobotWindow *window);
    QExcitationWidget *datanode();

private:
    QExcitationWidget *_excitation_widget;

};

#endif // QEXCITATIONDOCK_H
