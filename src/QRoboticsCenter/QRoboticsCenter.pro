# QRoboticsCenter version
VERSION = 6.0

# QT
QT += core gui gamepad
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRoboticsCenter
TEMPLATE = app

DEFINES += QT_NO_PRINTER \
           VERSION=\"\\\"$${VERSION}\\\"\"
PROTOCOL = mavlink

INCLUDEPATH += $$PWD

HEADERS += \
  qaboutdialog.h \
  qroboticscentermainwindow.h

SOURCES += \
  main.cpp \
  qaboutdialog.cpp \
  qroboticscentermainwindow.cpp

FORMS += \
  qaboutdialog.ui

RESOURCES += \
  icons.qrc

DESTDIR = bin

include(../QtModules/QRobotOverview/src/qrobotoverview.pri)
