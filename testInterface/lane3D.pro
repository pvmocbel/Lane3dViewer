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
    getdimcube.cpp

HEADERS  += mainwindow.h \
        irrviewer.h \
    myeventreceiver.h \
    cena.h \
    irrnode.h \
    getdimcube.h

FORMS    += mainwindow.ui \
    getdimcube.ui

INCLUDEPATH +=  /usr/include/irrlicht \
                /usr/X11R6/include

LIBS += -L/usr/X11R6/lib64 \
        -L/usr/irrlicht/ \
        -lIrrlicht \
        -lGL \
        -lX11 \
        -lQtOpenGL

win32:LIBS += /irrlicht-1.7.2/libWin/libIrrlicht.a
