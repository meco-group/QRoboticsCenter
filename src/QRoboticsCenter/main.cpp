#include <QtGui>
#include <QApplication>

#include <qroboticscentermainwindow.h>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setApplicationName("QRoboticsCenter");
  a.setOrganizationName("RobSoft");
  a.setApplicationVersion(QString(VERSION));
  a.setApplicationDisplayName("QRoboticsCenter");
  a.setWindowIcon(QIcon(":/icons/QRoboticsCenter_logo.png"));

  QRoboticsCenterMainwindow mainwindow;
  mainwindow.show();

  return a.exec();
}
