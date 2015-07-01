TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

CONFIG(release, debug|release) {
    DEFINES += QT_NO_DEBUG_OUTPUT
}

SOURCES += main.cpp \
    connector.cpp \
    connectorhandler.cpp \
    qmlsignalhandler.cpp \
    scriptgenerator.cpp \
    blockmodel.cpp \
    blockfactory.cpp \
    blocks/abstractblock.cpp \
    blocks/conditionalBlocks/infiniteblock.cpp \
    blocks/enginesBlocks/forwardblock.cpp \
    blocks/accelerometerBlocks/accelerometerxblock.cpp \
    blocks/backgroundColorsBlocks/greenblock.cpp \
    blocks/conditionalBlocks/dowhileblock.cpp \
    blocks/conditionalBlocks/forblock.cpp \
    blocks/conditionalBlocks/ifblock.cpp \
    blocks/conditionalBlocks/ifelseblock.cpp \
    blocks/conditionalBlocks/negationblock.cpp \
    blocks/conditionalBlocks/whiledoblock.cpp \
    blocks/drawingBlocks/sadsmileblock.cpp \
    blocks/drawingBlocks/smileblock.cpp \
    blocks/enginesBlocks/backwardblock.cpp \
    blocks/enginesBlocks/stopblock.cpp \
    blocks/functionsBlocks/absblock.cpp \
    blocks/gamepadBlocks/gamepadbuttonblock.cpp \
    blocks/gyroscopeBlocks/gyroscopexblock.cpp \
    blocks/ledColorsBlocks/ledgreenblock.cpp \
    blocks/luaPrintingBlocks/additionblock.cpp \
    blocks/messagesBlocks/sendmessageblock.cpp \
    blocks/portsBlocks/gamepadbutton1portblock.cpp \
    blocks/sensorsBlocks/upblock.cpp \
    blocks/signsBlocks/equalsblock.cpp \
    blocks/subprogramsBlocks/implementationblock.cpp \
    blocks/switchBlocks/headblock.cpp \
    blocks/threadsBlocks/callblock.cpp \
    blocks/typesBlocks/intblock.cpp \
    blocks/variablesBlocks/variabledeclarationblock.cpp \
    blocks/videosensorsBlocks/detectlineblock.cpp \
    blocks/waitBlocks/timerblock.cpp \
    blocks/sayblock.cpp \
    blocks/accelerometerBlocks/accelerometeryblock.cpp \
    blocks/accelerometerBlocks/accelerometerzblock.cpp \
    blocks/enginesBlocks/nullifyencoderblock.cpp \
    blocks/drawingBlocks/clearscreenblock.cpp \
    blocks/functionsBlocks/randomizeblock.cpp \
    blocks/functionsBlocks/timeblock.cpp \
    blocks/functionsBlocks/acosblock.cpp \
    blocks/functionsBlocks/asinblock.cpp \
    blocks/functionsBlocks/atanblock.cpp \
    blocks/functionsBlocks/ceilblock.cpp \
    blocks/functionsBlocks/cosblock.cpp \
    blocks/functionsBlocks/expblock.cpp \
    blocks/functionsBlocks/floorblock.cpp \
    blocks/functionsBlocks/lnblock.cpp \
    blocks/functionsBlocks/randomblock.cpp \
    blocks/functionsBlocks/sgnblock.cpp \
    blocks/functionsBlocks/sinblock.cpp \
    blocks/functionsBlocks/sqrtblock.cpp \
    blocks/gamepadBlocks/gamepadconnectionindicatorblock.cpp \
    blocks/gamepadBlocks/gamepadwheelblock.cpp \
    blocks/gamepadBlocks/gamepadpadblock.cpp \
    blocks/gamepadBlocks/gamepadpadpresssensorblock.cpp \
    blocks/gyroscopeBlocks/gyroscopeyblock.cpp \
    blocks/gyroscopeBlocks/gyroscopezblock.cpp \
    blocks/ledColorsBlocks/ledredblock.cpp \
    blocks/ledColorsBlocks/offblock.cpp \
    blocks/ledColorsBlocks/orangeblock.cpp \
    blocks/sensorsBlocks/motionblock.cpp \
    blocks/sensorsBlocks/downblock.cpp \
    blocks/sensorsBlocks/enterblock.cpp \
    blocks/sensorsBlocks/escblock.cpp \
    blocks/sensorsBlocks/leftblock.cpp \
    blocks/sensorsBlocks/rightblock.cpp \
    blocks/signsBlocks/greaterblock.cpp \
    blocks/signsBlocks/lessblock.cpp \
    blocks/signsBlocks/notgreaterblock.cpp \
    blocks/signsBlocks/notlessblock.cpp

HEADERS += \
    connector.h \
    connectorhandler.h \
    qmlsignalhandler.h \
    scriptgenerator.h \
    blockmodel.h \
    blockfactory.h \
    blocks/abstractblock.h \
    blocks/conditionalBlocks/infiniteblock.h \
    blocks/enginesBlocks/forwardblock.h \
    blocks/accelerometerBlocks/accelerometerxblock.h \
    blocks/backgroundColorsBlocks/greenblock.h \
    blocks/conditionalBlocks/dowhileblock.h \
    blocks/conditionalBlocks/forblock.h \
    blocks/conditionalBlocks/ifblock.h \
    blocks/conditionalBlocks/ifelseblock.h \
    blocks/conditionalBlocks/negationblock.h \
    blocks/conditionalBlocks/whiledoblock.h \
    blocks/drawingBlocks/sadsmileblock.h \
    blocks/drawingBlocks/smileblock.h \
    blocks/enginesBlocks/backwardblock.h \
    blocks/enginesBlocks/stopblock.h \
    blocks/functionsBlocks/absblock.h \
    blocks/gamepadBlocks/gamepadbuttonblock.h \
    blocks/gyroscopeBlocks/gyroscopexblock.h \
    blocks/ledColorsBlocks/ledgreenblock.h \
    blocks/luaPrintingBlocks/additionblock.h \
    blocks/messagesBlocks/sendmessageblock.h \
    blocks/portsBlocks/gamepadbutton1portblock.h \
    blocks/sensorsBlocks/upblock.h \
    blocks/signsBlocks/equalsblock.h \
    blocks/subprogramsBlocks/implementationblock.h \
    blocks/switchBlocks/headblock.h \
    blocks/threadsBlocks/callblock.h \
    blocks/typesBlocks/intblock.h \
    blocks/variablesBlocks/variabledeclarationblock.h \
    blocks/videosensorsBlocks/detectlineblock.h \
    blocks/waitBlocks/timerblock.h \
    blocks/sayblock.h \
    blocks/accelerometerBlocks/accelerometeryblock.h \
    blocks/accelerometerBlocks/accelerometerzblock.h \
    blocks/enginesBlocks/nullifyencoderblock.h \
    blocks/drawingBlocks/clearscreenblock.h \
    blocks/functionsBlocks/randomizeblock.h \
    blocks/functionsBlocks/timeblock.h \
    blocks/functionsBlocks/acosblock.h \
    blocks/functionsBlocks/asinblock.h \
    blocks/functionsBlocks/atanblock.h \
    blocks/functionsBlocks/ceilblock.h \
    blocks/functionsBlocks/cosblock.h \
    blocks/functionsBlocks/expblock.h \
    blocks/functionsBlocks/floorblock.h \
    blocks/functionsBlocks/lnblock.h \
    blocks/functionsBlocks/randomblock.h \
    blocks/functionsBlocks/sgnblock.h \
    blocks/functionsBlocks/sinblock.h \
    blocks/functionsBlocks/sqrtblock.h \
    blocks/gamepadBlocks/gamepadconnectionindicatorblock.h \
    blocks/gamepadBlocks/gamepadwheelblock.h \
    blocks/gamepadBlocks/gamepadpadblock.h \
    blocks/gamepadBlocks/gamepadpadpresssensorblock.h \
    blocks/gyroscopeBlocks/gyroscopeyblock.h \
    blocks/gyroscopeBlocks/gyroscopezblock.h \
    blocks/ledColorsBlocks/ledredblock.h \
    blocks/ledColorsBlocks/offblock.h \
    blocks/ledColorsBlocks/orangeblock.h \
    blocks/sensorsBlocks/motionblock.h \
    blocks/sensorsBlocks/downblock.h \
    blocks/sensorsBlocks/enterblock.h \
    blocks/sensorsBlocks/escblock.h \
    blocks/sensorsBlocks/leftblock.h \
    blocks/sensorsBlocks/rightblock.h \
    blocks/signsBlocks/greaterblock.h \
    blocks/signsBlocks/lessblock.h \
    blocks/signsBlocks/notgreaterblock.h \
    blocks/signsBlocks/notlessblock.h

RESOURCES += qml.qrc \
    templates.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
