#ifndef QCSVRECORDER_H
#define QCSVRECORDER_H

#include <QObject>
#include <qabstractrecorder.h>

class QCSVRecorder : public QAbstractRecorder {
  Q_OBJECT
public:
  explicit QCSVRecorder(const QString& type, const int id = -1, QObject *parent = 0);

  void start();
  void stop();

private:
  void createHeader();
  void createFooter();
  virtual QString insertHeader() = 0;

};

#endif // QCSVRECORDER_H
