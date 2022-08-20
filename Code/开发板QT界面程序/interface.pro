#-------------------------------------------------
#
# Project created by QtCreator 2019-01-01T18:16:26
#
#-------------------------------------------------

QT       += core gui
QT       +=multimedia
QT       +=multimediawidgets
QT       +=network
QT       +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    showmenu.cpp \
    env.cpp \
    history.cpp \
    menuenv.cpp \
    offlinemenu.cpp \
    frminput.cpp \
    stream.cpp \
    threshold.cpp \
    querytime.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    showmenu.h \
    env.h \
    history.h \
    menuenv.h \
    offlinemenu.h \
    frminput.h \
    stream.h \
    threshold.h \
    querytime.h


FORMS += \
        mainwindow.ui \
    login.ui \
    showmenu.ui \
    env.ui \
    history.ui \
    menuenv.ui \
    offlinemenu.ui \
    frminput.ui \
    stream.ui \
    threshold.ui \
    querytime.ui


RESOURCES += \
    src.qrc

DEFINES += QT_MESSAGELOGCONTEXT

