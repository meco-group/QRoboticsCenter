!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

    SOURCES += \
		$$PWD/qcontrollerdeviceinterface.cpp \
		$$PWD/qtrustmaster.cpp 
    HEADERS +=  \
		$$PWD/qcontrollerdeviceinterface.h \
		$$PWD/qtrustmaster.h
    FORMS +=

} else {
    message( "Skipping $$PWD: already included" )
}

