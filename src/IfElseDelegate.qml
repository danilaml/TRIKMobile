import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

Item {
    id: nodeContainer
    width: parent.width
    height: rect.height + (isExpanded ? (nodeChildrenView1.height + nodeChildrenView2.height): 0)
    clip: true // good enough, needed for "beautiful" expanding

    property string textLabel
    property var thenChildren
    property var elseChildren
    property bool isExpanded: false
    property int childrenHeight: childrenHeight1 + childrenHeight2
    property int childrenHeight1: 0
    property int childrenHeight2: 0
    property int variableHeight1: 0
    property int variableHeight2: 0

    property int dpm: Screen.pixelDensity

    signal toggled(bool expanded, int newHeight)
    signal removeBlock(int index)
    signal addBlock(string path)
    signal blockAdded(bool expanded)

    Rectangle {
        id: rect
        width: parent.width
        height: 9 * dpm
        color: "lightgreen"

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
                nodeContainer.toggled(isExpanded, nodeChildrenView1.height + nodeChildrenView2.height)
            }
            onPressAndHold: {
                contextMenu.popup()
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
            text: qsTr("Edit condition")
            onTriggered: editDialog.open()
        }
        MenuItem {
            text: qsTr("Delete")
            onTriggered: removeBlock(index)
        }
        MenuItem {
            text: qsTr("Add block to then")
            onTriggered: addBlock('0.' + index + '/')
        }
        MenuItem {
            text: qsTr("Add block to else")
            onTriggered: addBlock('1.' + index + '/')
        }
    }

    Dialog {
        id: editDialog
        title: qsTr("Edit condition")
        standardButtons: StandardButton.Save | StandardButton.Cancel

        Label {text: "condition";anchors.verticalCenter: tf.verticalCenter}
        TextField {
            id: tf
            placeholderText: propertyMap["condition"]
            function getPropVal() {
                if (wasEdited)
                    propertyMap["condition"] = text
            }
            property bool wasEdited: false
            onTextChanged: wasEdited = true
        }
    }

    Connections {
        target: thenChildren
        onBlockAdded: {childrenHeight1 += 9 * dpm;}
    }
    Connections {
        target: elseChildren
        onBlockAdded: {childrenHeight2 += 9 * dpm;}
    }

    SimpleNodeDelegate {
        id: nodeChildrenView1
        visible: nodeContainer.isExpanded
        x: 30
        anchors.top: rect.bottom

        textLabel: "then"
        folderChildren: thenChildren
        childrenHeight: childrenHeight1
        isMenuEnabled: false

        onToggled: {
            variableHeight1 += expanded ? newHeight : -newHeight
            nodeContainer.toggled(expanded, newHeight)
        }
        onRemoveBlock: {
            folderChildren.removeRow(index);
            childrenHeight1 -= 9 * dpm;
        }
        onAddBlock: nodeContainer.addBlock('0.' + path)
        onBlockAdded: {
            if (expanded) variableHeight1 += 9 * dpm
            nodeContainer.blockAdded(expanded)
        }

    }
    SimpleNodeDelegate {
        id: nodeChildrenView2
        visible: nodeContainer.isExpanded
        x: 30
        anchors.top: nodeChildrenView1.bottom

        textLabel: "else"
        folderChildren: elseChildren
        childrenHeight: childrenHeight2
        isMenuEnabled: false

        onToggled: {
            variableHeight2 += expanded ? newHeight : -newHeight
            nodeContainer.toggled(expanded, newHeight)
        }
        onRemoveBlock: {
            thenChildren.removeRow(index);
            childrenHeight2 -= 9 * dpm;
        }
        onAddBlock: nodeContainer.addBlock('1.' + path)
        onBlockAdded: {
            if (expanded) variableHeight2 += 9 * dpm
            nodeContainer.blockAdded(expanded)
        }
    }
}
