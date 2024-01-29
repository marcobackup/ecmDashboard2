import QtQuick 2.15
import QtQuick.Window 2.15
import "qml"

Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("ECM dashboard")

    FontLoader {
        id: nesLowercaseFont
        source: "qrc:/resource/font/resource/font/NES_Lowercase.ttf"
    }

    Body {
        id: body
    }

    Component.onCompleted: {
        alertQueueHandler.addWarningAlert("qrc:/resource/image/resource/image/weather/fullSunWeatherIcon.png", "WELCOME", "Hey Marco, welcome to ECM");
    }
}
