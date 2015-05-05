import QtQuick 2.4
import QtQuick.Window 2.2

Item {
    property alias loader : loader
    Loader {
        id: loader
        width: parent.width
        source: childrenCount == 1 ? "SimpleNodeDelegate.qml" : childrenCount == 2 ? "IfElseDelegate.qml" : "LeafDelegate.qml"
        onLoaded: {
            item.textLabel = blockType
            if (childrenCount == 1)
            {
                item.folderChildren = childrenOneModel
                item.childrenHeight = childrenOneModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10)
            } else if (childrenCount == 2) {
                item.folderChildren = childrenOneModel
                item.elseChildren = childrenTwoModel
                item.childrenHeight1 = childrenOneModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10)
                item.childrenHeight2 = childrenTwoModel.rowCount() * 9 * parseInt(Screen.pixelDensity,10)
            }
        }
    }
}

