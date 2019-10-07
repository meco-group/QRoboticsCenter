#ifndef QGPIODATANODEWIDGET_H
#define QGPIODATANODEWIDGET_H

#include <qdatanodewidget.h>
#include <qgpiowidget.h>

class QGPIODataNodeWidget : public QDataNodeWidget
{
    Q_OBJECT

public:
    explicit QGPIODataNodeWidget(QWidget *parent = 0);
    virtual QWidget *w();
    virtual QGPIOWidget *gpiow();

    void saveState(QString group);
    void restoreState(QString group);

private:
    QGPIOWidget *_gpiox;

public slots:
    virtual void receive(gpiox_t);
    void onEventButtonPressed(int b);
    void onOutputSet(gpiox_t gpiox);

};

#endif // QGPIODATANODEWIDGET_H
