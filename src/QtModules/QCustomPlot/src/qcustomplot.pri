!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT += printsupport

    INCLUDEPATH += $$PWD

    SOURCES +=  $$PWD/qcustomplot.cpp \
                $$PWD/qrunningplot.cpp \
                $$PWD/qaxisdialog.cpp
    HEADERS +=  $$PWD/qcustomplot.h \
                $$PWD/qrunningplot.h \
                $$PWD/qaxisdialog.h

    FORMS += $$PWD/qaxisdialog.ui
} else {
    message( "Skipping $$PWD: already included" )
}
