import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    id: item1
    width: 480
    height: 640

    property alias listView1: listView1
    property alias button5: button5
    property alias button4: button4
    property alias button3: button3
    property alias button2: button2
    property alias button1: button1
    property alias listModel1: listModel1

    GridLayout {
        id: gridLayout1
        x: 0
        height: 46
        columns: 3
        rows: 2
        anchors.top: parent.verticalCenter
        anchors.topMargin: 140
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.rightMargin: 5
        anchors.bottomMargin: 0
        anchors.leftMargin: 5


        Button {
            id: button1
            x: 0
            text: qsTr("Add")
            Layout.fillHeight: false
            Layout.fillWidth: true
            scale: 1
            transformOrigin: Item.Center
        }
        Button {
            id: button2
            text: qsTr("Remove")
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
            width: 75
            text: qsTr("Stop")
            Layout.fillWidth: true
        }
    }

    ListView {
        id: listView1
        x: 129
        width: 110
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.bottom: gridLayout1.top
        anchors.bottomMargin: 1
        anchors.horizontalCenter: parent.horizontalCenter
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10

                Rectangle {
                    width: 100
                    height: 35
                    color: "lightgrey"
                    Text {
                        text: name
                        font.bold: true
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
            }
        }
        model: ListModel {
            id: listModel1
            ListElement {
                name: "Forward"
            }

            ListElement {
                name: "Backwards"
            }

            ListElement {
                name: "Left"
            }

            ListElement {
                name: "Right"
            }
        }
    }

}
