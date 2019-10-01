!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )
    
    message($${PROTOCOL})
    !defined(PROTOCOL,var) {
        error( "No valid serial protocol set. Possible values are: mavlink" )
    }

    QT += serialport bluetooth

    INCLUDEPATH += $$PWD/$${PROTOCOL} \
                   $$PWD

    HEADERS +=  $$PWD/$${PROTOCOL}/qserialprotocol.h\
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

    SOURCES +=  $$PWD/$${PROTOCOL}/qserialprotocol.cpp\
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
