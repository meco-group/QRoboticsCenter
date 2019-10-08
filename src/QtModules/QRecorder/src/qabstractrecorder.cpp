#include "qabstractrecorder.h"

QAbstractRecorder::QAbstractRecorder(const QString& type, const int id, QObject *parent) :
  QDataNode(parent), _type(type), _id(id), _record(new QAction(_type, parent))
{
  _record->setCheckable(true);
  _record->setChecked(false);
  QObject::connect(_record, &QAction::toggled, this, &QAbstractRecorder::activate);
}

bool QAbstractRecorder::isRecording() {
  return _record->isChecked();
}

QAction *QAbstractRecorder::record() {
  return _record;
}

void QAbstractRecorder::activate(bool active) {
  if(active) start();
  else stop();
}
