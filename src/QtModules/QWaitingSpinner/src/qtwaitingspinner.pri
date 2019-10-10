!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

    HEADERS += $$PWD/waitingspinnerwidget.h

    SOURCES += $$PWD/waitingspinnerwidget.cpp

} else {
    message( "Skipping $$PWD: already included" )
}
