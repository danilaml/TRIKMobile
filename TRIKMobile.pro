TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    scriptgenerator.cpp \
    connector.cpp \
    connectorhandler.cpp

HEADERS += scriptgenerator.h \
    connector.h \
    connectorhandler.h

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
