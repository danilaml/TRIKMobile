import QtQuick 2.4
import QtQuick.Window 2.2

Rectangle {
    id: nodeContainer
    width: parent.width
    height: nodeLabel.height + nodeChildrenView.height

    color: "transparent"

    property string textLabel
    property string statusString
    property var folderChildren
    property bool isExpanded: false
    property int childrenHeight: 0
    property int variableHeight: 0

    property int dpm: Screen.pixelDensity

    signal toggled(bool expanded, int newHeight)


    Text {
        id: nodeLabel
        x: 45
        width: parent.width
        height: 9 * dpm
        text: textLabel
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea {
        width: parent.width
        height: 9 * dpm
        onClicked: {
            isExpanded = !isExpanded
            nodeContainer.toggled(isExpanded, childrenHeight)
        }
        onPressAndHold: console.log(this + "pressed and holded")
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
        //height: childrenHeight
        model: folderChildren
        delegate:
            Component {
                Loader {
                    width: parent.width
                    //height: 35
                    source: childrenCount ? "SimpleNodeDelegate.qml" : "LeafDelegate.qml"
                    onLoaded: {
                        item.textLabel = blockType
                        item.statusString = statusString
                        if (childrenCount)
                        {
                            item.folderChildren = childrenModel
                            item.childrenHeight = (childrenModel.rowCount() * 9 * dpm)
                        }
                        else
                        {
                            item.propertyNames = propertyNames
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

