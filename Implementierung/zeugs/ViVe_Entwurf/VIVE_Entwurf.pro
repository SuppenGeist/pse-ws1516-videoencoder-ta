#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T19:29:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VIVE_Entwurf
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Gui_Elements/exsistingfilters.cpp \
    Gui_Elements/filtercontainer.cpp \
    Gui_Elements/optionbuttonmenu.cpp \
    Gui_Elements/videoplayeroverview.cpp \
    Gui_Elements/filter_tab.cpp \
    Gui_Elements/analysis_tab.cpp \
    Gui_Elements/analysisbox.cpp \
    Gui_Elements/analysisboxcontainer.cpp

HEADERS  += mainwindow.h \
    Gui_Elements/exsistingfilters.h \
    Gui_Elements/filtercontainer.h \
    Gui_Elements/optionbuttonmenu.h \
    Gui_Elements/videoplayeroverview.h \
    Gui_Elements/filter_tab.h \
    Gui_Elements/analysis_tab.h \
    Gui_Elements/analysisbox.h \
    Gui_Elements/analysisboxcontainer.h

FORMS    += mainwindow.ui \
    Gui_Elements/exsistingfilters.ui \
    Gui_Elements/filtercontainer.ui \
    Gui_Elements/optionbuttonmenu.ui \
    Gui_Elements/videoplayeroverview.ui \
    Gui_Elements/filter_tab.ui \
    Gui_Elements/analysis_tab.ui \
    Gui_Elements/analysisbox.ui \
    Gui_Elements/analysisboxcontainer.ui

RESOURCES += \
    resources.qrc
