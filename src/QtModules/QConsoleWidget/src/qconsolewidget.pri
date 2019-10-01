!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

    SOURCES +=  $$PWD/qconsolewidget.cpp

    HEADERS +=  $$PWD/qconsolewidget.h

    FORMS +=    $$PWD/qconsolewidget.ui
} else {
    message( "Skipping $$PWD: already included" )
}
