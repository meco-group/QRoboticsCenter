!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

include(../../QSerialProtocol/src/qserialprotocol.pri)

    QT += 

    INCLUDEPATH += $$PWD \

    HEADERS += \
        $$PWD/qintegerparameter.h \
        $$PWD/qfloatparameter.h \
        $$PWD/qstringparameter.h \
        $$PWD/qparametertablewidget.h \
        $$PWD/qabstractparameter.h \
        $$PWD/qparameterdatanodewidget.h

    SOURCES += \
        $$PWD/qintegerparameter.cpp \
        $$PWD/qfloatparameter.cpp \
        $$PWD/qstringparameter.cpp \
        $$PWD/qparametertablewidget.cpp \
        $$PWD/qabstractparameter.cpp \
        $$PWD/qparameterdatanodewidget.cpp
                        

    FORMS += \

} else {
    message( "Skipping $$PWD: already included" )
}
