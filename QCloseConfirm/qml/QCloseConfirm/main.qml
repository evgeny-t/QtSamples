import QtQuick 2.0
import QtQuick.Dialogs 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    Connections {
        target: controller
        onClosing: {
            confirmClosing();
            controller.canClose = false;
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            confirmClosing();
            Qt.quit();
        }
    }

    function confirmClosing() {
        // TODO: confirm
    }
}
