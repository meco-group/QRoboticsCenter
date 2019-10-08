#ifndef QGPIORECORDER_H
#define QGPIORECORDER_H

#include <qcsvrecorder.h>
#include <qrobotwindow.h>

#define QGPIO_RECORD_CSV  // comment out or #undef to use XML output

class QGPIORecorder :
#ifdef QGPIO_RECORD_CSV
  public QCSVRecorder
#else
  public QXMLRecorder
#endif
{
  Q_OBJECT
public:
  QGPIORecorder(QGPIOWidget *gpiox, QObject* parent = 0);

private:
  QGPIOWidget* _gpiox;
  virtual QString insertHeader();

public slots:
  virtual void receive(gpiox_t gpiox);
};

#endif // QGPIORECORDER_H
