!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

    SOURCES += \
		$$PWD/qrecorderwidget.cpp \
		$$PWD/qabstractrecorder.cpp \
		$$PWD/qcsvrecorder.cpp \
		$$PWD/qxmlrecorder.cpp \
		$$PWD/qgpiorecorder.cpp \
    $$PWD/qattituderecorder.cpp \
    $$PWD/qvelocityrecorder.cpp \
    $$PWD/qpositionrecorder.cpp

    HEADERS += \
		$$PWD/qrecorderwidget.h \
		$$PWD/qabstractrecorder.h \
		$$PWD/qcsvrecorder.h \
		$$PWD/qxmlrecorder.h \
		$$PWD/qgpiorecorder.h \
    $$PWD/qattituderecorder.h \
    $$PWD/qvelocityrecorder.h \
    $$PWD/qpositionrecorder.h

    FORMS +=

include(../../QSerialProtocol/src/qserialprotocol.pri)

} else {
    message( "Skipping $$PWD: already included" )
}
