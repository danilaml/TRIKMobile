import QtQuick 2.4
import QtQuick.Window 2.2


ListView {
//    id: blockModelView
//    width: parent.width//540
//    height: 600
//    model: blockModel
    signal removeBlock(int index)

    displaced: Transition {
        NumberAnimation { property: "y"; duration: 100 }
    }
    remove: Transition {
        ParallelAnimation {
            NumberAnimation { property: "opacity"; to: 0; duration: 100 }
            NumberAnimation { properties: "height"; to: 0; duration: 100 }
        }
    }
    delegate:
        Component {
        Loader {
            width: parent.width
            source: childrenCount ? "SimpleNodeDelegate.qml" : "LeafDelegate.qml"
            onLoaded: {
                item.textLabel = blockType
                if (childrenCount)
                {
                    item.folderChildren = childrenOneModel
                    item.childrenHeight = (childrenOneModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10))
                }
            }
            Connections {
                target: item
                onRemoveBlock: removeBlock(index)
            }
        }
    }
}
