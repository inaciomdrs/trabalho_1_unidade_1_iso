#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T23:19:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabalhoMedicaoTempoISO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    statistics.cpp \
    sorting.cpp \
    array_handler.cpp \
    controller.cpp \
    controller_functions.cpp \
    translator.cpp

HEADERS  += mainwindow.h \
    statistics.h \
    data_strucutures.h \
    sorting.h \
    array_handler.h \
    controller.h \
    controller_functions.h \
    translator.h

FORMS    += mainwindow.ui
