import QtQuick 2.0
import QtQuick.Layouts 1.3
import "carParameter"

Item {
    width: parent.width
    height: 105

    RowLayout {
        anchors.fill: parent

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            ColumnLayout {
                anchors.fill: parent

                Image {
                    id: fuelLevelIcon
                    source: "qrc:/resource/image/resource/image/carParameter/fuelLevelIcon.png"
                    width: 60
                    height: width / sourceSize.width * sourceSize.height
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    color: "#fff"
                    font.pixelSize: 22
                    font.family: nesLowercaseFont.name
                    font.bold: true
                    text: "Ciao"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: fuelLevelIcon.bottom
                    anchors.topMargin: 12
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            ColumnLayout {
                anchors.fill: parent

                Image {
                    id: coolantTemperatureIcon
                    source: "qrc:/resource/image/resource/image/carParameter/coolantTemperatureIcon.png"
                    width: 60
                    height: width / sourceSize.width * sourceSize.height
                    anchors.left: parent.left
                }
                Text {
                    color: "#fff"
                    font.pixelSize: 22
                    font.family: nesLowercaseFont.name
                    font.bold: true
                    text: "Ciao"
                    anchors.left: parent.left
                    anchors.top: coolantTemperatureIcon.bottom
                    anchors.topMargin: 12
                }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            ColumnLayout {
                anchors.fill: parent

                Image {
                    id: turboPressureIcon
                    source: "qrc:/resource/image/resource/image/carParameter/turboPressureIcon.png"
                    width: 60
                    height: width / sourceSize.width * sourceSize.height
                    anchors.right: parent.right
                }
                Text {
                    color: "#fff"
                    font.pixelSize: 22
                    font.family: nesLowercaseFont.name
                    font.bold: true
                    text: "Ciao"
                    anchors.right: parent.right
                    anchors.top: turboPressureIcon.bottom
                    anchors.topMargin: 12
               }
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"

            ColumnLayout {
                anchors.fill: parent

                Image {
                    id: batteryVoltageIcon
                    source: "qrc:/resource/image/resource/image/carParameter/fuelLevelIcon.png"
                    width: 60
                    height: width / sourceSize.width * sourceSize.height
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Text {
                    color: "#fff"
                    font.pixelSize: 22
                    font.family: nesLowercaseFont.name
                    font.bold: true
                    text: "Ciao"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: batteryVoltageIcon.bottom
                    anchors.topMargin: 12
               }
            }
        }
    }
}
