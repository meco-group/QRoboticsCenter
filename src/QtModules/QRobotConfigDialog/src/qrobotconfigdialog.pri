!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

    SOURCES += $$PWD/qrobotconfigdialog.cpp

    HEADERS += $$PWD/qrobotconfigdialog.h \
               $$PWD/qtreewidgetparameter.h

    FORMS += $$PWD/qrobotconfigdialog.ui
}
