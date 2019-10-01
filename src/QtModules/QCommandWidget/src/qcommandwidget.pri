!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += network gamepad

    INCLUDEPATH += $$PWD \
                   $$PWD/CSV \
                   $$PWD/UDP \
                   $$PWD/Gamepad

        HEADERS += \
            $$PWD/qcommandwidget.h \
            $$PWD/CSV/qcsvreader.h\
            $$PWD/CSV/qcsvreaderwidget.h \
            $$PWD/UDP/qudpreader.h \
            $$PWD/UDP/qudpreaderwidget.h \
            $$PWD/Gamepad/qvelocitygamepadcommand.h

        SOURCES += \
            $$PWD/qcommandwidget.cpp \
            $$PWD/CSV/qcsvreader.cpp \
            $$PWD/CSV/qcsvreaderwidget.cpp \
            $$PWD/UDP/qudpreader.cpp \
            $$PWD/UDP/qudpreaderwidget.cpp \
            $$PWD/Gamepad/qvelocitygamepadcommand.cpp
                        

    FORMS += $$PWD/CSV/qcsvreaderwidget.ui\
             $$PWD/UDP/qudpportwidget.ui

include(../../QSerialProtocol/src/qserialprotocol.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/CSV/qcsvcommanddatanodewidget.h \
    $$PWD/CSV/qgpiocsvcommand.h \
    $$PWD/CSV/qpositioncmdcsvcommand.h \
    $$PWD/UDP/qtypeudpcommand.h \
    $$PWD/qtypecommandwidget.h \
    $$PWD/qtypecommandinterface.h \
    $$PWD/Gamepad/qgamepadentry.h \
    $$PWD/Gamepad/qgamepadinputwidget.h \
    $$PWD/Gamepad/qgamepadcommanddatanodewidget.h \
    $$PWD/Gamepad/qgamepadcommandwidget.h \
    $$PWD/Gamepad/qgpiogamepadcommand.h

SOURCES += \
    $$PWD/CSV/qcsvcommanddatanodewidget.cpp \
    $$PWD/qtypecommandwidget.cpp \
    $$PWD/CSV/qgpiocsvcommand.cpp \
    $$PWD/CSV/qpositioncmdcsvcommand.cpp \
    $$PWD/Gamepad/qgamepadentry.cpp \
    $$PWD/Gamepad/qgamepadinputwidget.cpp \
    $$PWD/Gamepad/qgamepadcommanddatanodewidget.cpp \
    $$PWD/Gamepad/qgamepadcommandwidget.cpp \
    $$PWD/Gamepad/qgpiogamepadcommand.cpp

FORMS += \
    $$PWD/Gamepad/qgamepadinputwidget.ui
