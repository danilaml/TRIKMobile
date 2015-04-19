import QtQuick 2.0

Rectangle {
    id: leafDelegate
    width: 350
    height: 35

    //color: "transparent"
    color: "steelblue"

    property string textLabel
    property string statusString
    property var propertyNames
//    property string lCurrency

    signal clicked

    Text {
        id: labelText
        //width: 150
        height: parent.height
        text: textLabel
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: labelText.width + 5 //150
        width: 100
        height: parent.height
        text: statusString//propertyNames.toString()
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
        //onClicked: leafDelegate.clicked()
        onPressAndHold: console.log(this + "pressed and holded")
    }
}

