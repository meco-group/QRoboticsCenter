!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += 

    INCLUDEPATH += $$PWD \
                   $$PWD/QRobots \
                   $$PWD/QRobotWidgets \

    HEADERS += \
        $$PWD/qrobotoverview.h \
        $$PWD/qrobotbutton.h \
        $$PWD/qstackedwindow.h \
        $$PWD/QRobots/qabstractrobot.h \
        $$PWD/QRobots/qabstractrobot_helper.h \
        $$PWD/QRobots/qunknownrobot.h \
        $$PWD/QRobots/qcar.h \
        $$PWD/QRobots/qbalancingrobot.h \
        $$PWD/QRobots/qtiltingtable.h \
        $$PWD/QRobots/qballbot.h \
        $$PWD/QRobotWidgets/qrobotwindow.h \
        $$PWD/QRobotWidgets/qbalancingwindow.h \
        $$PWD/QRobotWidgets/qbalancingwidget.h \
        $$PWD/QRobotWidgets/qbalancingdatanodewidget.h \
        $$PWD/QRobotWidgets/qrobotcommandwidget.h

    SOURCES += \
        $$PWD/qrobotoverview.cpp \
        $$PWD/qrobotbutton.cpp \
        $$PWD/qstackedwindow.cpp \
        $$PWD/QRobots/qabstractrobot.cpp \
        $$PWD/QRobots/qabstractrobot_helper.cpp \
        $$PWD/QRobots/qunknownrobot.cpp \
        $$PWD/QRobots/qcar.cpp \
        $$PWD/QRobots/qbalancingrobot.cpp \
        $$PWD/QRobots/qtiltingtable.cpp \
        $$PWD/QRobots/qballbot.cpp \
        $$PWD/QRobotWidgets/qrobotwindow.cpp \
        $$PWD/QRobotWidgets/qbalancingwindow.cpp \
        $$PWD/QRobotWidgets/qbalancingwidget.cpp \
        $$PWD/QRobotWidgets/qbalancingdatanodewidget.cpp \
        $$PWD/QRobotWidgets/qrobotcommandwidget.cpp

    RESOURCES += \
        $$PWD/QRobots/robot_icons.qrc

    FORMS += \
        $$PWD/QRobotWidgets/qbalancingwidget.ui

include(../../QSerialProtocol/src/qserialprotocol.pri)
include(../../QGPIOWidget/src/qgpiowidget.pri)
include(../../QRecorder/src/qrecorder.pri)
include(../../QMapWidget/src/qmapwidget.pri)
include(../../QPolarPlot/src/qpolarplot.pri)
include(../../QExcitationWidget/src/qexcitationwidget.pri)
include(../../QParameterWidget/src/qparameterwidget.pri)
include(../../QCommandWidget/src/qcommandwidget.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/QRobotWidgets/qparameterdock.h \
    $$PWD/QRobotWidgets/qrobotwindowdock.h \
    $$PWD/QRobotWidgets/qthreadinginfodock.h \
    $$PWD/QRobotWidgets/qconnectioninfodock.h \
    $$PWD/QRobotWidgets/qcommanddock.h \
    $$PWD/QRobotWidgets/qexcitationdock.h

SOURCES += \
    $$PWD/QRobotWidgets/qparameterdock.cpp \
    $$PWD/QRobotWidgets/qrobotwindowdock.cpp \
    $$PWD/QRobotWidgets/qthreadinginfodock.cpp \
    $$PWD/QRobotWidgets/qconnectioninfodock.cpp \
    $$PWD/QRobotWidgets/qcommanddock.cpp \
    $$PWD/QRobotWidgets/qexcitationdock.cpp
