import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

Item {
    id: nodeContainer
    width: parent.width
    height: rect.height + childrenViewHeight
    property string textLabel
    property var folderChildren
    property bool isExpanded: false
    property bool isMenuEnabled: true
    property int childrenHeight: 0
    property int variableHeight: 0
    property int childrenViewHeight: nodeChildrenView.height
    property int ind: index // stupid qml workaraound

    property int dpm: Screen.pixelDensity

    signal toggled(bool expanded, int newHeight)
    signal removeBlock(int index, int varheight)
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
            text: textLabel + (isMenuEnabled ? (" " + statusString) : "") // for then/else
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                isExpanded = !isExpanded
                nodeContainer.toggled(isExpanded, childrenHeight + variableHeight)
            }
            onPressAndHold: {
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
            text: qsTr("Edit")
            onTriggered: editDialog.open()
        }
        MenuItem {
            text: qsTr("Delete")
            onTriggered: removeBlock(index, childrenHeight)
        }
        MenuItem {
            text: qsTr("Add inner block")
            onTriggered: addBlock(index + '/')
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
                source: childrenCount == 1 ? "SimpleNodeDelegate.qml" : childrenCount == 2 ? "IfElseDelegate.qml" : "LeafDelegate.qml"
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
                    ignoreUnknownSignals: true
                    onToggled: {
                        variableHeight += expanded ? newHeight : -newHeight
                        toggled(expanded, newHeight)
                    }
                    onRemoveBlock: {
                        folderChildren.removeRow(index);
                        nodeContainer.childrenHeight -= 9 * dpm;
                        variableHeight -= varheight
                    }
                    onAddBlock: addBlock(ind + '/' + path)
                    onBlockAdded: {
                        if (expanded) variableHeight += 9 * dpm
                        nodeContainer.blockAdded(expanded)
                    }
                }
            }
        }
    }
}

