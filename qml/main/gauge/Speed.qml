import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    width: 190
    height: width
    y: 20
    anchors.horizontalCenter: parent.horizontalCenter

    property real speed: gaugeController.speed

    Text {
        id: speedText
        text: speed
        font.family: nesLowercaseFont.name
        font.pixelSize: 100
        font.bold: true
        color: "#d9d9d9"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        text: "KM/H"
        font.pixelSize: 22
        color: "#d9d9d9"
        anchors.top: speedText.bottom
        anchors.topMargin: -12
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
