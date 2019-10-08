#ifndef QXMLRECORDER_H
#define QXMLRECORDER_H

#include <QObject>
#include <qabstractrecorder.h>

class QXMLRecorder : public QAbstractRecorder {
  Q_OBJECT
public:
  explicit QXMLRecorder(const QString& type, const int id = -1, QObject *parent = 0);

  void start();
  void stop();

private:
  void createHeader();
  void createFooter();
  virtual QString insertHeader() = 0;

};

#endif // QXMLRECORDER_H
