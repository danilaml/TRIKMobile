TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    scriptgenerator.cpp \
    connector.cpp \
    connectorhandler.cpp \
    blocks/abstractblock.cpp \
    blocks/forwardblock.cpp \
    blocks/backwardblock.cpp

HEADERS += scriptgenerator.h \
    connector.h \
    connectorhandler.h \
    blocks/abstractblock.h \
    blocks/forwardblock.h \
    blocks/backwardblock.h

RESOURCES += qml.qrc \
    templates.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
