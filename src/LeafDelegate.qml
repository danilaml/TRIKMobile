import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

Rectangle {
    id: leafDelegate
    width: parent.width
    height: 9 * dpm

    color: "steelblue"

    property string textLabel

    property int dpm: Screen.pixelDensity

    signal removeBlock(int index)

    Text {
        id: labelText
        x: parent.x + 5
        height: parent.height
        text: textLabel + " " + statusString
        verticalAlignment: Text.AlignVCenter
    }

    Rectangle {
        height: 1
        width: parent.width
        y: parent.height - 1
        color: "black"
    }

    MouseArea {
        anchors.fill: parent
        height: parent.height
        onPressAndHold: {
            contextMenu.popup()
        }
    }

    Menu {
        id: contextMenu
        MenuItem {
            text: qsTr("Edit")
            visible: propertyNames.length > 0
            onTriggered: editDialog.open()
        }
        MenuItem {
            text: qsTr("Delete")
            onTriggered: removeBlock(index)
        }
    }

    Dialog {
        id: editDialog
        title: qsTr("Edit block")
        standardButtons: StandardButton.Save | StandardButton.Cancel

        signal collectProps()

        property var mapobj: propertyMap
        onAccepted: {collectProps();propertyMap = mapobj}

        Column {
            id: content
            spacing: 5
            Repeater {
                model: propertyNames.length

                delegate: Row {
                    spacing: 5
                    Label {text: propertyNames[index];anchors.verticalCenter: tf.verticalCenter}
                    TextField {
                        id: tf
                        placeholderText: propertyMap[propertyNames[index]]
                        function getPropVal() {
                            if (wasEdited)
                                editDialog.mapobj[propertyNames[index]] = text
                        }
                        property bool wasEdited: false
                        onTextChanged: wasEdited = true
                        Connections {
                             target: editDialog
                             onCollectProps: tf.getPropVal()
                        }
                    }
                }
            }
        }
    }
}

