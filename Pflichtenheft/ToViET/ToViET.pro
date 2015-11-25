#-------------------------------------------------
#
# Project created by QtCreator 2015-11-18T10:43:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ToViET
TEMPLATE = app


SOURCES += main.cpp \
    GUI.cpp \
    comparisondialog.cpp \
    fileexplorer.cpp \
    propertiesdialog.cpp

HEADERS  += \
    gui.h \
    comparisondialog.h \
    fileexplorer.h \
    propertiesdialog.h

FORMS    += \
    GUI.ui \
    comparisondialog.ui \
    fileexplorer.ui \
    propertiesdialog.ui

RESOURCES += \
    resource.qrc \
    playerbuttons.qrc \
    filter_artefact_icons.qrc
