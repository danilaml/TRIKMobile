import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    signal sendPressed(var msg)

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")

            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        id: mftest
        anchors.fill: parent

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

        button1.onClicked: myDialog.open()
//        button1.onClicked: listModel1.append({
//                                                "name" : "Grey",
//                                                "colorCode" : "grey"
//                                            })
        //button2.onClicked: messageDialog.show(qsTr("Button 2 pressed"))
        button2.onClicked: removeElement()
        //button3.onClicked: sendPressed("Testing")
        button3.onClicked: {
            console.log(getActionsList());
            sendPressed(getActionsList());
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
        id: myDialog
        title: qsTr("Choose action")
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        ComboBox {
            id : myComboBox
            model : ["Forward", "Backwards", "Left", "Right"]
        }

        onAccepted : {
            //console.log(myComboBox.textAt(myComboBox.currentIndex))
            mftest.listModel1.append({"name":myComboBox.textAt(myComboBox.currentIndex)})
        }

    }

}
