import QtQuick 2.4
import QtQuick.Window 2.2

Rectangle {
    id: leafDelegate
    width: parent.width
    height: 9 * dpm

    //color: "transparent"
    color: "steelblue"

    property string textLabel
    property string statusString
    property var propertyNames

    property int dpm: Screen.pixelDensity

    signal clicked

    Text {
        id: labelText
        //width: 150
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
        onPressAndHold: console.log(this + "pressed and holded")
    }
}

