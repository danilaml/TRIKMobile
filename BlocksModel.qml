import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainwindow
    title: qsTr("TRIKMobile")
    width: 640
    height: 480
    visible: true

    ListView {
        id: blockModelView
        width: 350
        height: 600
        model: blockModel
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
                        item.childrenHeight = (childrenOneModel.rowCount() * 35)
                    }
                    else
                    {
                        item.propertyNames = "test"//propertyNames;
                    }
                }
            }
        }
    }
}
