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

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")

            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("&Set ip")
                onTriggered: robotIpDialog.open();
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
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

            function removeElement() {
                if (listModel1.count)
                    listModel1.remove(listModel1.count - 1)
            }

            function getActionsList() {
                var result = [];
                for (var i = 0; i < listModel1.count; i++) {
                    result.push(listModel1.get(i).name);
                }
                return result;
            }

            button1.onClicked: addScriptDialog.open()
            button2.onClicked: removeElement()
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
            validator: RegExpValidator {
                regExp: /^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/
            }
        }
    }

    Dialog {
        id: addScriptDialog
        title: qsTr("Choose action")
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        ComboBox {
            id : myComboBox
            model : ["Forward", "Backwards", "Left", "Right"]
        }

        onAccepted : {
            console.log(myComboBox.textAt(myComboBox.currentIndex))
            //mftest.listModel1.append({"name":myComboBox.textAt(myComboBox.currentIndex)})
        }

    }

}
