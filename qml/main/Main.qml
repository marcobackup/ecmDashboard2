import QtQuick 2.0
import "gauge"

Item {
    anchors.left: parent.left
    anchors.right: parent.right

    Rectangle {
        anchors.fill: parent
        color: "transparent"

        Speed {
        }

        CarParameter {
            anchors.bottom: parent.bottom
        }

        Image {
            source: "qrc:/resource/image/resource/image/car/carLightOn.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }

        Image {
            source: "qrc:/resource/image/resource/image/tripFlag.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
        }
    }
}
