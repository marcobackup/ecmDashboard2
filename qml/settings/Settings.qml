import QtQuick 2.15
import QtQuick.Controls 2.15
import "diagnosys"
import "user"

Item {
    anchors.left: parent.left
    anchors.right: parent.right

    Rectangle {
        anchors.fill: parent
        color: "transparent"

        Image {
            source: "qrc:/resource/image/resource/image/settingsMask.png"
            anchors.centerIn: parent
        }

        SwipeView {
            anchors.fill: parent
            anchors.centerIn: parent

            Menu {
            }

            EnvironmentalLight {
            }

            Radio {
            }
        }

        Image {
            source: "qrc:/resource/image/resource/image/tripFlag.png"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom

            Text {
                anchors.centerIn: parent
                color: "#fff"
                text: "USER"
                font.family: nesLowercaseFont.name
                font.pixelSize: 19
            }
        }
    }
}
