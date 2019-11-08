!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += serialport
    contains(CONFIG, bluetooth) {
      QT += bluetooth
    }

    INCLUDEPATH += $$PWD/mavlink \
                   $$PWD

    HEADERS +=  $$PWD/mavlink/qserialprotocol.h\
                $$PWD/qdatanode.h \
                $$PWD/qheartbeatdetector.h \
                $$PWD/mavlink/qserialprotocol_typedefs.h \
                $$PWD/qdatanodewidget.h \
                #$$PWD/qmavlinkconnectionlogger.h \
                #$$PWD/qudpdevicediscoveryagent.h \
                $$PWD/qusbdevicediscoveryagent.h \
                $$PWD/qserialscanner.h \
                $$PWD/qconnectioninfodatanodewidget.h \
                $$PWD/qconnectioninfowidget.h \
                $$PWD/qprintlog.h \
                $$PWD/qprintstitcher.h

    SOURCES +=  $$PWD/mavlink/qserialprotocol.cpp\
                $$PWD/qdatanode.cpp \
                $$PWD/qheartbeatdetector.cpp \
                $$PWD/qdatanodewidget.cpp \
                #$$PWD/qmavlinkconnectionlogger.cpp \
                #$$PWD/qudpdevicediscoveryagent.cpp \
                $$PWD/qusbdevicediscoveryagent.cpp\
                $$PWD/qserialscanner.cpp\
                $$PWD/qconnectioninfodatanodewidget.cpp \
                $$PWD/qconnectioninfowidget.cpp \
                $$PWD/qprintlog.cpp \
                $$PWD/qprintstitcher.cpp

    FORMS +=

include(../../QCustomPlot/src/qcustomplot.pri)

} else {
    message( "Skipping $$PWD: already included" )
}
