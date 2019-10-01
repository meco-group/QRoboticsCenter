!contains( included_modules, $$PWD ) {
    included_modules += $$PWD
    message( "Including $$PWD" )

    QT +=

    INCLUDEPATH += $$PWD

	HEADERS += \
		$$PWD/qrunningpolarplot.h \
		$$PWD/qpolarplot.h

	SOURCES += \
		$$PWD/qpolarplot.cpp \
		$$PWD/qrunningpolarplot.cpp
                        

    FORMS += 

} else {
    message( "Skipping $$PWD: already included" )
}

