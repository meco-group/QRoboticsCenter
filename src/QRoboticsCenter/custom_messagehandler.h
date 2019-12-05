#ifndef CUSTOM_MESSAGEHANDLER_H
#define CUSTOM_MESSAGEHANDLER_H

void custom_messagehandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
  QByteArray localMsg = msg.toLocal8Bit();
  // const char *file = context.file ? context.file : "";
  const char* function = context.function ? context.function : "";
  const char* timestamp = QTime::currentTime().toString(Qt::ISODateWithMs).toLocal8Bit().data();
  switch (type) {
    case QtDebugMsg:
      fprintf(stderr, "[DEBUG] [%s] %s: %s\n", timestamp, function, localMsg.constData());
      break;
    case QtInfoMsg:
      fprintf(stderr, "[INFOM] [%s] %s: %s\n", timestamp, function, localMsg.constData());
      break;
    case QtWarningMsg:
      fprintf(stderr, "[WARNG] [%s] %s: %s\n", timestamp, function, localMsg.constData());
      break;
    case QtCriticalMsg:
      fprintf(stderr, "[CRITL] [%s] %s: %s\n", timestamp, function, localMsg.constData());
      break;
    case QtFatalMsg:
      fprintf(stderr, "[FATAL] [%s] %s: %s\n", timestamp, function, localMsg.constData());
      break;
  }
}

#endif // CUSTOM_MESSAGEHANDLER_H
