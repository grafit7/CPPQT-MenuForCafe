TEMPLATE = app
#QMAKE_CXXFLAGS += -std=c++17
CONFIG += c++14
QT += core gui widgets

include($$PWD/core/MenuForCafeCore.pri)

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp \
    $$PWD/texteditprintmenuvisitor.cpp \
    $$PWD/menuiterator.cpp \
    $$PWD/helpervisitor.cpp \
    $$PWD/adddialog.cpp \
    $$PWD/editordelegate.cpp \
    $$PWD/menucombobox.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/texteditprintmenuvisitor.h \
    $$PWD/menuiterator.h \
    $$PWD/helpervisitor.h \
    $$PWD/adddialog.h \
    $$PWD/editordelegate.h \
    $$PWD/menucombobox.h

FORMS += \
    $$PWD/mainwindow.ui \
    $$PWD/adddialog.ui \
    $$PWD/editordelegate.ui
