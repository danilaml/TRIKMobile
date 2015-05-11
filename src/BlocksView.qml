import QtQuick 2.4
import QtQuick.Window 2.2


ListView {
    signal removeBlock(int index)
    signal addBlock(string path)

    displaced: Transition {
        NumberAnimation { property: "y"; duration: 100 }
    }
    remove: Transition {
        NumberAnimation { properties: "opacity,height"; to: 0; duration: 100 }
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
                onRemoveBlock: removeBlock(index)
                onAddBlock: addBlock(path)
            }
        }
    }
}
