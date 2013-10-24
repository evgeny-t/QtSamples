import QtQuick 2.0
import QtQuick.Dialogs 1.0

Rectangle {
    width: 360
    height: 360

    Connections {
        target: controller
        onClosing: {
            controller.canClose = confirmClosing();
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (confirmClosing()) {
                Qt.quit();
            }
        }
    }

    function confirmClosing() {
        // TODO: confirm
        return true;
    }
}
