!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network

    INCLUDEPATH += $$PWD

    SOURCES +=  $$PWD/qgpiowidget.cpp \
                $$PWD/qgeneraloutput.cpp \
                $$PWD/qgeneraloutputfloat.cpp \
                $$PWD/qgeneraloutputint.cpp \
                $$PWD/qgeneralinput.cpp \
                $$PWD/qgeneralio.cpp \
                $$PWD/qgeneralinputint.cpp \
                $$PWD/qgeneralinputfloat.cpp \
                $$PWD/qgpioinputdialog.cpp

    HEADERS +=  $$PWD/qgpiowidget.h \
                $$PWD/qgeneraloutput.h \
                $$PWD/qgeneraloutputfloat.h \
                $$PWD/qgeneraloutputint.h\
                $$PWD/qgeneralinput.h \
                $$PWD/qgeneralio.h \
                $$PWD/qgeneralinputint.h \
                $$PWD/qgeneralinputfloat.h \
                $$PWD/qgpioinputdialog.h

    FORMS += $$PWD/qgpiowidget.ui\
    $$PWD/qgpioinputdialog.ui

    include(../../QCustomPlot/src/qcustomplot.pri)
    include(../../QSerialProtocol/src/qserialprotocol.pri)
} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    #$$PWD/thread.h \
    #$$PWD/qthreadingdialog.h \
    $$PWD/qgpiodatanodewidget.h \
    $$PWD/qthreadinfodatanodewidget.h \
    $$PWD/qthreadinfowidget.h

SOURCES += \
    #$$PWD/thread.cpp \
    #$$PWD/qthreadingdialog.cpp \
    $$PWD/qgpiodatanodewidget.cpp \
    $$PWD/qthreadinfodatanodewidget.cpp \
    $$PWD/qthreadinfowidget.cpp
