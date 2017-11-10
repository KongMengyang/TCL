#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T13:20:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MQ-Studio-TCL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylabel.cpp \
    logindlg.cpp

HEADERS  += mainwindow.h \
    mylabel.h \
    logindlg.h

FORMS    += mainwindow.ui \
    logindlg.ui

RESOURCES += \
    res.qrc

RC_FILE = MQicon.rc


INCLUDEPATH += D:/opencv/build/include

CONFIG(debug, debug|release): {
LIBS += -LD:/opencv/build/x64/vc12/lib \
-lopencv_core2413d \
-lopencv_imgproc2413d \
-lopencv_highgui2413d \
-lopencv_ml2413d \
-lopencv_video2413d \
-lopencv_features2d2413d \
-lopencv_calib3d2413d \
-lopencv_objdetect2413d \
-lopencv_contrib2413d \
-lopencv_legacy2413d \
-lopencv_flann2413d
} else:CONFIG(release, debug|release): {
LIBS += -LD:/opencv/build/x64/vc12/lib \
-lopencv_core2413 \
-lopencv_imgproc2413 \
-lopencv_highgui2413 \
-lopencv_ml2413 \
-lopencv_video2413 \
-lopencv_features2d2413 \
-lopencv_calib3d2413 \
-lopencv_objdetect2413 \
-lopencv_contrib2413 \
-lopencv_legacy2413 \
-lopencv_flann2413
}
