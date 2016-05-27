#-------------------------------------------------
#
# Project created by QtCreator 2015-03-02T23:27:38
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameLife
TEMPLATE = app


SOURCES += main.cpp\
        scene.cpp \
    mainwindow.cpp \
    configuration.cpp \
    object.cpp \
    rules.cpp

HEADERS  += scene.h \
    mainwindow.h \
    configuration.h \
    object.h \
    rules.h \
    gameconst.h \
    history.h
