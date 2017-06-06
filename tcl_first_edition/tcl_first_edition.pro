#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T13:20:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MQ-Studio-TCL
TEMPLATE = app

INCLUDEPATH += D:/opencv/include/opencv
LIBS += -LC:/opencv/lib/ -lcv210 -lcvaux210 -lhighgui210 -lcxcore210

SOURCES += main.cpp\
        mainwindow.cpp \
    mylabel.cpp

HEADERS  += mainwindow.h \
    mylabel.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

RC_FILE = MQicon.rc
