TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    connector.cpp \
    connectorhandler.cpp \
    blocks/abstractblock.cpp \
    blocks/forwardblock.cpp \
#    blocks/backwardblock.cpp \
    qmlsignalhandler.cpp \
    scriptgenerator.cpp \
#    blocks/timerblock.cpp \
#    blocks/stopblock.cpp \
#    blocks/sayblock.cpp \
    blockmodel.cpp

HEADERS += \
    connector.h \
    connectorhandler.h \
    blocks/abstractblock.h \
    blocks/forwardblock.h \
#    blocks/backwardblock.h \
    qmlsignalhandler.h \
    scriptgenerator.h \
#    blocks/timerblock.h \
#    blocks/stopblock.h \
#    blocks/sayblock.h \
    blockmodel.h

RESOURCES += qml.qrc \
    templates.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
