import QtQuick 2.4
import QtQuick.Window 2.2


ListView {
//    id: blockModelView
//    width: parent.width//540
//    height: 600
//    model: blockModel

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
                    item.childrenHeight = (childrenOneModel.rowCount() * 9 * Screen.pixelDensity)
                }
            }
        }
    }
}
