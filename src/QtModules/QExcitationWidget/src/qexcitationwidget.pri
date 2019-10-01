!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += 

    INCLUDEPATH += $$PWD \

        HEADERS += \
                #$$PWD/qexcitationdialog.h \
                $$PWD/qmultisineexcitationwidget.h \
                $$PWD/qsweptsineexcitationwidget.h \
                $$PWD/qexcitationwidget.h \
                $$PWD/qexcitationwidgetinterface.h \
                $$PWD/qexcitationdatanodewidgetinterface.h \
                $$PWD/qexcitationchannelwidget.h

        SOURCES += \
                #$$PWD/qexcitationdialog.cpp \
                $$PWD/qmultisineexcitationwidget.cpp \
                $$PWD/qsweptsineexcitationwidget.cpp \
                $$PWD/qexcitationwidget.cpp \
                $$PWD/qexcitationwidgetinterface.cpp \
                $$PWD/qexcitationchannelwidget.cpp
                        

    FORMS += \

include(../../QSerialProtocol/src/qserialprotocol.pri)

} else {
    message( "Skipping $$PWD: already included" )
}

HEADERS += \
    $$PWD/qsteppedsineexcitationwidget.h

SOURCES += \
    $$PWD/qsteppedsineexcitationwidget.cpp
