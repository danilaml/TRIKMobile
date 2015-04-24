import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Rectangle {
    id: nodeContainer
    width: parent.width
    height: nodeLabel.height + nodeChildrenView.height

    color: "transparent"

    property string textLabel
    property var folderChildren
    property bool isExpanded: false
    property int childrenHeight: 0
    property int variableHeight: 0

    property int dpm: Screen.pixelDensity

    signal toggled(bool expanded, int newHeight)


    Text {
        id: nodeLabel
        x: 45
        height: 9 * dpm
        text: textLabel + " " + statusString
        verticalAlignment: Text.AlignVCenter
    }

//    Text {
//        x: nodeLabel.x + nodeLabel.width + 5 //150
//        //width: 100
//        height: parent.height
//        text: statusString//propertyNames.toString()
//        verticalAlignment: Text.AlignVCenter
//    }

    MouseArea {
        width: parent.width
        height: 9 * dpm
        onClicked: {
            isExpanded = !isExpanded
            nodeContainer.toggled(isExpanded, childrenHeight)
        }
        onPressAndHold: {
            console.log(this + "pressed and held")
            contextMenu.popup()
        }
    }

    Menu {
        id: contextMenu
        MenuItem {
            text: "Edit"
        }
        MenuItem {
            text: "Delete"
        }
    }

    Rectangle {
        height: 1
        width: parent.width
        y: 9 * dpm - 1
        color: "black"
    }

    function childToggled(expanded, height)
    {
        if (expanded)
            variableHeight += height;
        else
            variableHeight -= height;
    }

    ListView {
        id: nodeChildrenView
        visible: isExpanded
        x: 30
        y: nodeLabel.height
        width: parent.width - x
        height: isExpanded ? (childrenHeight + variableHeight) : 0
        model: folderChildren
        interactive: false
        delegate:
            Component {
            Loader {
                width: parent.width
                source: childrenCount ? "SimpleNodeDelegate.qml" : "LeafDelegate.qml"
                onLoaded: {
                    item.textLabel = blockType
                    if (childrenCount)
                    {
                        item.folderChildren = childrenModel
                        item.childrenHeight = (childrenModel.rowCount() * 9 * dpm)
                    }
                }
                Connections {
                    target: item
                    onToggled: childToggled(item.isExpanded, item.childrenHeight)
                }
            }
        }
    }
}

