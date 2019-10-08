#ifndef QABSTRACTRECORDER_H
#define QABSTRACTRECORDER_H

#include <QObject>
#include <QAction>
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <qdatanode.h>

class QAbstractRecorder : public QDataNode {
  Q_OBJECT
public:
  explicit QAbstractRecorder(const QString& type, const int id = -1, QObject *parent = 0);

  bool isRecording();
  QAction *record();
  virtual void start() = 0;
  virtual void stop() = 0;

protected:
  QFile *_log;
  const QString _type;
  const int _id;
  QAction *_record;

  virtual void createHeader() = 0;
  virtual void createFooter() = 0;
  virtual QString insertHeader() = 0;

public slots:
  void activate(bool);

};

#endif // QABSTRACTRECORDER_H
