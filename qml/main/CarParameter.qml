import QtQuick 2.0
import QtQuick.Layouts 1.3
import "carParameter"

Item {
    width: parent.width
    height: 105

    property real fuelLevel: carParameterController.fuelLevel
    property bool lowFuelLevelWarningStatus: carParameterController.lowFuelLevelWarningStatus
    property real coolantTemperature: carParameterController.coolantTemperature
    property bool highCoolantTemperatureWarningStatus: carParameterController.highCoolantTemperatureWarningStatus
    property real turboPressure: carParameterController.turboPressure
    property real batteryVoltage: carParameterController.batteryVoltage

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
                    text: fuelLevel
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
                    text: coolantTemperature + "°C"
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
                    text: turboPressure + " bar"
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
                    text: {
                        return batteryVoltage.toFixed(1) + "v"
                    }
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: batteryVoltageIcon.bottom
                    anchors.topMargin: 12
               }
            }
        }
    }
}
