import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: mainwindow
    title: mainloader.status == Loader.Ready ? "TRIKMobile - " + modelName : "TRIKMobile"
    width: 540
    height: 960
    visible: true

    signal sendPressed(string name)
    signal runPressed(string name)
    signal stopPressed()
    signal ipChanged(string ip)
    signal addBlock(string type, string path)
    signal loadModel(url path)
    signal saveModel(url path)

    property string modelName: "untitled"

    menuBar: MenuBar {
        Menu {
            id: menubar
            title: qsTr("&File")
            visible: false

            MenuItem {
                text: qsTr("&Open")
                onTriggered: loadDialog.open();
            }
            MenuItem {
                text: qsTr("&Save")
                onTriggered: saveDialog.open();
            }
            MenuItem {
                text: qsTr("&Clear model")
                onTriggered: yesnodialog.show(qsTr("Are you sure?"))
            }
            MenuItem {
                text: qsTr("Set &name")
                onTriggered: modelNameDialog.open();
            }
            MenuItem {
                text: qsTr("Set robot &ip")
                onTriggered: robotIpDialog.open();
            }
            MenuItem {
                text: qsTr("Exit to &main menu")
                onTriggered: {
                    mainloader.item.clearModel()
                    mainloader.active = false
                    mainwindow.title = "untitled"
                    menubar.visible = false
                    columns.visible = true
                }
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MessageDialog {
        id: yesnodialog
        title: "Clear model"
        standardButtons: StandardButton.Yes | StandardButton.No

        function show(text) {
            yesnodialog.text = text
            yesnodialog.open()
        }

        onYes: mainloader.item.clearModel() // for now
    }


//    statusBar: StatusBar {
//        RowLayout {
//            anchors.fill: parent
//            Label { text: modelName }
//        }
//    }

    ColumnLayout {
        id: columns
        anchors.fill: parent
        Image {
            Layout.alignment: Qt.AlignCenter
            source: "images/logo.png"
            scale: 2
        }
        Button {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("New model")
            onClicked: mainloader.active = true
        }
        Button {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("Load model")
            onClicked: loadDialog.open()//mainloader.active = true
        }
        Button {
            Layout.alignment: Qt.AlignCenter
            text: qsTr("Exit")
            onClicked: Qt.quit()
        }
    }

    Loader {
        anchors.fill: parent
        id: mainloader
        source: "MainForm.qml"
        active: false
        onLoaded: {
            columns.visible = false
            menubar.visible = true
            connectionsloader.sourceComponent = connections
            item.modelName = Qt.binding(function() {return modelName})
        }
    }
    Loader {id: connectionsloader}
    Component {
        id: connections
        Connections {
            target: mainloader.item
            onSendPressed: sendPressed(name)
            onRunPressed: runPressed(name)
            onStopPressed: stopPressed()
            onIpChanged: ipChanged(ip)
            onAddBlock: addBlock(type, path)
        }
    }

    Dialog {
        id: modelNameDialog
        title: qsTr("Choose model name")
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        Row {
            id: mndrow
            spacing: 5
            Label {text: qsTr("Model name: ");anchors.verticalCenter: tf.verticalCenter}
            TextField {
                id:tf
                text: modelName
                validator: RegExpValidator {regExp:/^[-\w^&'@{}[\],$=!#().%+~][-\w^&'@{}[\],$=!#().%+~ ]+$/}
            }
            Label {text: ".tmm";anchors.verticalCenter: tf.verticalCenter}
        }
        onAccepted: {if (tf.text.length > 0) modelName = tf.text}
    }

    Dialog {
        id : robotIpDialog
        title: qsTr("Set robot ip")
        standardButtons: StandardButton.Ok | StandardButton.Cancel

        property string ip: "192.168.1.1"

        onAccepted: {if (ipField.text) ip = ipField.text; mainwindow.ipChanged(ip); console.debug(ip)}

        TextField {
            id: ipField
            placeholderText: "192.168.1.1"
            inputMethodHints: Qt.ImhFormattedNumbersOnly
            validator: RegExpValidator {
                regExp: /^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/
            }
        }
    }

    FileDialog {
        id: loadDialog
        title: qsTr("Please choose a file")
        nameFilters: [ "TRIK Mobile model (*.tmm)"]
        onAccepted: {
            console.debug("You chose: " + loadDialog.fileUrl)
            loadModel(loadDialog.fileUrl)
            var strpath = loadDialog.fileUrl.toString() // because of some strange TypeError
            modelName = strpath.substring(strpath.lastIndexOf('/') + 1, strpath.toString().lastIndexOf('.'))
            if (!mainloader.active) mainloader.active = true;
        }
        onRejected: {
            console.debug("Canceled")
        }
    }

    FileDialog {
        property bool wasOpened: false

        id: saveDialog
        title: qsTr("Please choose a folder to save ") + modelName
        selectFolder: true // qml lack of proper save dialog workaround
        onAccepted: {
            console.debug("You chose: " + saveDialog.fileUrl)
            saveModel(saveDialog.fileUrl + '/' + modelName + ".tmm")
        }
        onRejected: {
            console.debug("Canceled")
        }
    }
}
