#-------------------------------------------------
#
# Project created by QtCreator 2015-07-29T14:59:06
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TT_Engine
TEMPLATE = app


SOURCES += main.cpp\
        ttmainwindow.cpp \
    ttopenglwidget.cpp \
    ttshader.cpp \
    vertex.cpp \
    ttgameobject.cpp \
    ttstaticmesh.cpp \
    ttmaterial.cpp \
    ttcamera.cpp \
    tttransformation.cpp \
    ttscene.cpp \
    cube.cpp \
    sphere.cpp \
    ttlightsource.cpp

HEADERS  += ttmainwindow.h \
    ttopenglwidget.h \
    ttshader.h \
    vertex.h \
    ttgameobject.h \
    ttstaticmesh.h \
    ttmaterial.h \
    ttcamera.h \
    tttransformation.h \
    ttscene.h \
    cube.h \
    sphere.h \
    ttlightsource.h

FORMS    += ttmainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES +=

INCLUDEPATH += $$PWD/lib/glm
