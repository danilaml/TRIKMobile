import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: mainwindow
    title: qsTr("TRIKMobile")
    width: 540
    height: 960
    visible: true

    signal sendPressed()
    signal runPressed(string msg)
    signal stopPressed()
    signal ipChanged(string ip)
    signal addBlock(string type, string path)
    signal loadModel(url path)
    signal saveModel(url path)

    property string modeName: "untitled.tmm"

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")

            MenuItem {
                text: qsTr("&Open")
                onTriggered: loadDialog.open();
            }
            MenuItem {
                text: qsTr("&Save")
                onTriggered: saveDialog.open();
            }
            MenuItem {
                text: qsTr("Set &ip")
                onTriggered: robotIpDialog.open();
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    FileDialog {
        id: loadDialog
        title: "Please choose a file"
        nameFilters: [ "TRIK Mobile models (*.tmm )"]
        onAccepted: {
            console.log("You chose: " + loadDialog.fileUrl)
            loadModel(loadDialog.fileUrl)
        }
        onRejected: {
            console.log("Canceled")
        }
    }
    FileDialog {
        id: saveDialog
        title: "Please choose a folder to save " + tmm
        selectFolder: true // qml lack of proper save dialog workaround
        onAccepted: {
            console.log("You chose: " + saveDialog.fileUrl)
            saveModel(saveDialog.fileUrl)
        }
        onRejected: {
            console.log("Canceled")
        }
    }

    Item {
        width: parent.width
        height: parent.height

        BlocksView {
            id: blockModelView
            width: parent.width//540
            height: parent.height - buttons.height//720
            model: blockModel
            clip: true
            onRemoveBlock: blockModel.removeRow(index)
            onAddBlock: {
                addScriptDialog.path = path;
                addScriptDialog.open();
            }
        }

        ButtonsGrid {
            id: buttons
            //anchors.top: blockModelView.bottom
            width: parent.width
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.rightMargin: 5
            anchors.bottomMargin: 5
            anchors.leftMargin: 5

            button1.onClicked: addScriptDialog.open()
            button3.onClicked: sendPressed()
            button4.onClicked: runPressed("test")
            button5.onClicked: stopPressed()
        }
    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    Dialog {
        id : robotIpDialog
        title: qsTr("Set robot ip")
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        property string ip: "192.168.1.1"

        onAccepted: {ip = ipField.text; mainwindow.ipChanged(ip); console.log(ip)}

        TextField {
            id: ipField
            placeholderText: "192.168.1.1"
            inputMethodHints: Qt.ImhFormattedNumbersOnly
            validator: RegExpValidator {
                regExp: /^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/
            }
        }
    }

    Dialog {
        id: addScriptDialog
        title: qsTr("Choose block")
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        property string path : ""
        property var block: null;

        ComboBox {
            id : myComboBox
            model : registeredBlocks
        }

        onAccepted : {
            console.log(registeredBlocks)
            console.log(myComboBox.currentIndex)
            console.log(myComboBox.textAt(myComboBox.currentIndex))
            addBlock(registeredBlocks[myComboBox.currentIndex],path);
            path = "";
        }

    }

}
