#-------------------------------------------------
#
# Project created by QtCreator 2012-03-05T14:17:28
#
#-------------------------------------------------
QT += core gui

TARGET = testeMouse
TEMPLATE = app

SOURCES += main.cpp\
           mainwindow.cpp\
           irrqwidget.cpp \
           myeventreceiver.cpp

HEADERS  += mainwindow.h \
    irrqwidget.h

FORMS    += mainwindow.ui

INCLUDEPATH +=  /irrlicht-1.7.2/include \
                /usr/X11R6/include #/home/er/tmp/irrlicht_src/irrlicht/include

LIBS += -L/usr/X11R6/lib \
        -L/irrlicht-1.7.2/lib/Linux \
        -lIrrlicht \
        -lGL \
        -lX11 \
        -lQtOpenGL

win32:LIBS += /irrlicht-1.7.2/libWin/libIrrlicht.a
