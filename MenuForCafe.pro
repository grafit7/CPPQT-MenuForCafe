TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17
QT += core gui widgets

include($$PWD/core/MenuForCafeCore.pri)

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp \
    texteditprintmenuvisitor.cpp \
    menuiterator.cpp \
    helpervisitor.cpp

HEADERS += \
    $$PWD/mainwindow.h \
    texteditprintmenuvisitor.h \
    menuiterator.h \
    helpervisitor.h

FORMS += \
    $$PWD/mainwindow.ui

