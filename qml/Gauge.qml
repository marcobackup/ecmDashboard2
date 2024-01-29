import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    width: 190
    height: width
    y: 70
    anchors.horizontalCenter: parent.horizontalCenter

    property real speed: gaugeController.speed

    Rectangle {
        width: parent.width
        height: parent.height
        radius: 360

        Text {
            id: speedText
            text: speed
            font.family: nesLowercaseFont.name
            font.pixelSize: 44
            font.bold: true
            color: "#161517"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        Text {
            text: "KM/H"
            font.pixelSize: 14
            color: "#161517"
            anchors.top: speedText.bottom
            anchors.topMargin: -10
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
