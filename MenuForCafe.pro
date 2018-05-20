TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++17
QT += core gui widgets

include($$PWD/core/MenuForCafeCore.pri)

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/mainwindow.cpp

HEADERS += \
    $$PWD/mainwindow.h

FORMS += \
    $$PWD/mainwindow.ui

