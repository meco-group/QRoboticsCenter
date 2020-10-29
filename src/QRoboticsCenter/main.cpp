#include <QtGui>
#include <QApplication>

#include <qroboticscentermainwindow.h>
#include <custom_messagehandler.h>

int main(int argc, char *argv[]) {
  qInstallMessageHandler(custom_messagehandler);

  QApplication a(argc, argv);
  a.setApplicationName("QRoboticsCenter");
  a.setOrganizationName("MECO Research Team, KU Leuven");
  a.setApplicationVersion(VERSION);
  a.setApplicationDisplayName("QRoboticsCenter");
  a.setWindowIcon(QIcon(":/icons/QRoboticsCenter_logo.png"));

  QRoboticsCenterMainwindow mainwindow;
  mainwindow.show();

  return a.exec();
}
