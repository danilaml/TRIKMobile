import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Item {
    id: nodeContainer
    width: parent.width
    height: rect.height + nodeChildrenView.height

    property string textLabel
    property var folderChildren
    property bool isExpanded: false
    property bool isMenuEnabled: true
    property int childrenHeight: 0
    property int variableHeight: 0
    property int ind: index // stupid qml workaraound

    property int dpm: Screen.pixelDensity

    signal toggled(bool expanded, int newHeight)
    signal removeBlock(int index)
    signal addBlock(string path)
    signal blockAdded(bool expanded)

    Rectangle {
        id: rect
        width: parent.width
        height: 9 * dpm
        color: "orangered"

        Text {
            id: nodeLabel
            x: parent.x + 5
            height: 9 * dpm
            text: textLabel + " " + statusString
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                isExpanded = !isExpanded
                nodeContainer.toggled(isExpanded, childrenHeight)
            }
            onPressAndHold: {
                console.log(this + "pressed and held")
                if (isMenuEnabled) contextMenu.popup()
            }
        }
    }

    Rectangle {
        height: 1
        width: parent.width
        y: 9 * dpm - 1
        color: "black"
    }

    Menu {
        id: contextMenu
        MenuItem {
            visible: propertyNames.length !== 0
            text: "Edit"
        }
        MenuItem {
            text: "Delete"
            onTriggered: removeBlock(index)
        }
        MenuItem {
            text: "Add inner block"
            onTriggered: addBlock(index + '/')
        }
    }

    function childToggled(expanded, height)
    {
        if (expanded)
            variableHeight += height;
        else
            variableHeight -= height;
    }

    Connections {
        target: folderChildren
        onBlockAdded: {childrenHeight += 9 * dpm;blockAdded(isExpanded)}
    }

    ListView {
        id: nodeChildrenView
        visible: isExpanded
        x: 30
        y: rect.height
        width: parent.width - x
        height: isExpanded ? (childrenHeight + variableHeight) : 0
        model: folderChildren
        interactive: false
        displaced: Transition {
            NumberAnimation { property: "y"; duration: 100 }
        }
        remove: Transition {
            NumberAnimation { properties: "opacity,height"; to: 0; duration: 100 }
        }
        Behavior on height {
            NumberAnimation { duration: 100 }
        }
        delegate:
            Component {
            Loader {
                width: parent.width
                source: childrenCount ? "SimpleNodeDelegate.qml" : "LeafDelegate.qml"
                onLoaded: {
                    item.textLabel = blockType
                    if (childrenCount == 1)
                    {
                        item.folderChildren = childrenOneModel
                        item.childrenHeight = childrenOneModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10)
                    } else if (childrenCount == 2) {
                        item.thenChildren = childrenOneModel
                        item.elseChildren = childrenTwoModel
                        item.childrenHeight1 = childrenOneModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10)
                        item.childrenHeight2 = childrenTwoModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10)
                    }
                }
                Connections {
                    target: item
                    //ignoreUnknownSignal: true
                    onToggled: childToggled(item.isExpanded, item.childrenHeight)
                    onRemoveBlock: {
                        folderChildren.removeRow(index);
                        childrenHeight -= 9 * dpm;
                    }
                    onAddBlock: addBlock(ind + '/' + path)
                    onBlockAdded: {
                        if (expanded) variableHeight += 9 * dpm
                    }
                }
            }
        }
    }
}

