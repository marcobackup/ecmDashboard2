import QtQuick 2.15
import QtQuick.Layouts 1.3

Item {
    width: 190
    height: width
    y: 20
    anchors.horizontalCenter: parent.horizontalCenter

    property real rpm: gaugeController.rpm

    Text {
        id: rpmText
        text: rpm
        font.family: nesLowercaseFont.name
        font.pixelSize: 100
        font.bold: true
        color: "#d9d9d9"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
    Text {
        text: "RPM"
        font.pixelSize: 22
        color: "#d9d9d9"
        anchors.top: rpmText.bottom
        anchors.topMargin: -12
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
