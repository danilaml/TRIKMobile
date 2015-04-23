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

    signal clicked

    Text {
        id: labelText
        height: parent.height
        text: textLabel + " " + statusString
        verticalAlignment: Text.AlignVCenter
    }
//    Text {
//        x: labelText.width + 5 //150
//        //width: 100
//        height: parent.height
//        text: statusString//propertyNames.toString()
//        verticalAlignment: Text.AlignVCenter
//    }
    Rectangle {
        height: 1
        width: parent.width
        y: parent.height - 1
        color: "black"
    }

    MouseArea {
        anchors.fill: parent
        height: parent.height
        //onClicked: leafDelegate.clicked()
        onPressAndHold: {
            console.log(this + "pressed and held")
            contextMenu.popup()
        }
    }

    Menu {
        id: contextMenu
        MenuItem {
            text: "Edit"
            onTriggered: editDialog.open()
        }
        MenuItem {
            text: "Delete"
        }
    }

    Dialog {
        id: editDialog
        title: qsTr("Edit block")
        standardButtons: StandardButton.Save | StandardButton.Cancel

        signal collectProps

        property var mapobj: propertyMap
        onAccepted: {collectProps();propertyMap = mapobj}

        Column{
            id: content
            spacing: 5
            Repeater {
                model: propertyNames.length

                delegate: Row {
                    spacing: 5
                    Label {text: propertyNames[index]}
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

