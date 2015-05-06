import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Item {
    id: nodeContainer
    width: parent.width
    height: nodeLabel.height + nodeChildrenView1.height + nodeChildrenView2.height

    property string textLabel
    property var thenChildren
    property var elseChildren
    property bool isExpanded: false
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
                console.log(nodeChildrenView1.y + " : " + nodeChildrenView2.y);
                console.log(nodeChildrenView1.height + " : " + nodeChildrenView2.height);
            }
            onPressAndHold: {
                console.log(this + "pressed and held")
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

    Connections {
        target: thenChildren
        onBlockAdded: {childrenHeight1 += 9 * dpm;blockAdded(isExpanded)} //rewrite
    }
    Connections {
        target: elseChildren
        onBlockAdded: {childrenHeight2 += 9 * dpm;blockAdded(isExpanded)} //rewrite
    }

    SimpleNodeDelegate {
        id: nodeChildrenView1
        visible: nodeContainer.isExpanded
        x: 30
        y: rect.height
        height: nodeContainer.isExpanded ? (childrenHeight1 + variableHeight1) : 0

        textLabel: "then"
        folderChildren: thenChildren

        onToggled: {
            nodeContainer.toggled(isExpanded, childrenHeight1);
            variableHeight1 += isExpanded ? childrenHeight1 : -childrenHeight1
        }
        onRemoveBlock: {
            folderChildren.removeRow(index);
            childrenHeight1 -= 9 * dpm;
        }
        onAddBlock: nodeContainer.addBlock(index + '.1/' + path)
        onBlockAdded: {
            if (expanded) variableHeight1 += 9 * dpm
        }

    }
    SimpleNodeDelegate {
        id: nodeChildrenView2
        visible: nodeContainer.isExpanded
        x: 30
        //y: nodeChildrenView1.y + nodeChildrenView1.height
        anchors.top: nodeChildrenView1.bottom
        height: nodeContainer.isExpanded ? (childrenHeight2 + variableHeight2) : 0

        textLabel: "else"
        folderChildren: elseChildren

        onToggled: {
            nodeContainer.toggled(isExpanded, childrenHeight2);
            variableHeight2 += isExpanded ? childrenHeight2 : -childrenHeight2
        }
        onRemoveBlock: {
            thenChildren.removeRow(index);
            childrenHeight2 -= 9 * dpm;
        }
        onAddBlock: nodeContainer.addBlock(index + '.2/' + path)
        onBlockAdded: {
            if (expanded) variableHeight2 += 9 * dpm
        }
    }
}
