import QtQuick 2.0

Rectangle {
    id: leafDelegate
    width: 350
    height: 35

    color: "transparent"
    //color: "steelblue"

    property string textLabel
    property string propertyNames
//    property string lCurrency

    signal clicked

    Text {
        width: 150
        height: parent.height
        text: textLabel
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        x: 150
        width: 100
        height: parent.height
        text: propertyNames
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
        onClicked: leafDelegate.clicked()
    }
}

