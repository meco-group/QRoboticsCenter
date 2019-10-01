!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += 

    INCLUDEPATH += $$PWD \

        HEADERS += \
    $$PWD/qoutputwidget.h \
    $$PWD/qsenderinterface.h \
    $$PWD/qtudpsender.h \
    $$PWD/qudpsenderwidget.h \
    $$PWD/qoutputdialog.h

        SOURCES += \
    $$PWD/qoutputwidget.cpp \
    $$PWD/qudpsenderwidget.cpp \
    $$PWD/qoutputdialog.cpp
                        

    FORMS += \
    $$PWD/qudpsenderwidget.ui

include(../../QMavlinkConnection/src/qmavlinkconnection.pri)

} else {
    message( "Skipping $$PWD: already included" )
}
