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
            source: {
                if(bottomBarController.handBrakeStatus || bottomBarController.bonnetStatus) {
                    return "qrc:/resource/image/resource/image/car/carParked.png"
                } else {
                    if(topBarController.lowBeamLightStatus || topBarController.highBeamLightStatus)
                        return "qrc:/resource/image/resource/image/car/carLightOn.png"
                    else
                        return "qrc:/resource/image/resource/image/car/carLightOff.png"
                }
            }
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
