#-------------------------------------------------
#
# Project created by QtCreator 2012-03-14T13:34:18
#
#-------------------------------------------------

QT       += core gui

TARGET = lane3D

TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        irrviewer.cpp \
		  myeventreceiver.cpp \
	     cena.cpp \
        irrnode.cpp \
        dialog_cgerais.cpp \
    data.cpp
    

HEADERS  += mainwindow.h \
        irrviewer.h \
    myeventreceiver.h \
    cena.h \
    irrnode.h \
    dialog_cgerais.h \
    data.h
    

FORMS    += mainwindow.ui \
				dialog_cgerais.ui
    

INCLUDEPATH +=  /usr/include/irrlicht \
                /usr/X11R6/include

LIBS += -L/usr/X11R6/lib64 \
        -L/usr/irrlicht/ \
        -lIrrlicht \
        -lGL \
        -lX11 \
        -lQtOpenGL

win32:LIBS += /irrlicht-1.7.2/libWin/libIrrlicht.a
