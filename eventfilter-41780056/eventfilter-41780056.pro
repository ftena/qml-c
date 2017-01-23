TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    myeventfilter.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    myeventfilter.h
