import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainwindow
    title: qsTr("TRIKMobile")
    width: 540
    height: 960
    visible: true

    ListView {
        id: blockModelView
        width: parent.width//540
        height: 600
        model: blockModel

        property int dpm: Screen.pixelDensity //dots per mm

        delegate:
            Component {
            Loader {
                width: parent.width
                source: childrenCount ? "SimpleNodeDelegate.qml" : "LeafDelegate.qml"
                onLoaded: {
                    console.warn(Screen.pixelDensity + ", " + blockModelView.dpm)
                    console.log(Screen.pixelDensity + ", " + blockModelView.dpm)
                    item.textLabel = blockType
                    item.statusString = statusString
                    if (childrenCount)
                    {
                        item.folderChildren = childrenOneModel
                        item.childrenHeight = (childrenOneModel.rowCount() * 9 * blockModelView.dpm)
                    }
                    else
                    {
                        item.propertyNames = propertyNames;
                    }
                }
            }
        }
    }
}
