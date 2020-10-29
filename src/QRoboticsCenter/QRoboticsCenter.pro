# QRoboticsCenter version
VERSION_MAJOR = 6
VERSION_MINOR = 1
VERSION_PATCH = 0

# QT
QT += core gui gamepad
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QRoboticsCenter
TEMPLATE = app
CONFIG += debug_and_release

# comment out to deactivate Bluetooth
CONFIG += bluetooth

VERSION = $${VERSION_MAJOR}.$${VERSION_MINOR}.$${VERSION_PATCH}
build_pass: CONFIG(debug, debug|release) {
  DEFINES += "VERSION=\"\\\"$${VERSION}-develop\\\"\""
  CONFIG += console
}
else: build_pass {
  DEFINES += "VERSION=\"\\\"$${VERSION}\\\"\"" \
             QT_NO_DEBUG_OUTPUT
}

# defines
DEFINES += QT_NO_PRINTER
contains(CONFIG, bluetooth) {
  DEFINES += WITH_BLUETOOTH
}

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
