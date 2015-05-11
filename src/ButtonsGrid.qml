import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

GridLayout {
    id: gridLayout1
    columns: 4
    rows: 1

    property alias button5: button5
    property alias button4: button4
    property alias button3: button3
    property alias button1: button1

    Button {
        id: button1
        text: qsTr("Add")
        Layout.fillWidth: true
    }
    Button {
        id: button3
        text: qsTr("Send")
        antialiasing: false
        Layout.fillWidth: true
    }
    Button {
        id: button4
        text: qsTr("Run")
        Layout.fillWidth: true
    }
    Button {
        id: button5
        text: qsTr("Stop")
        Layout.fillWidth: true
    }
}
