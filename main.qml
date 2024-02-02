import QtQuick 2.15
import QtQuick.Window 2.15
import "qml"

Window {
    width: 800
    height: 480
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    visible: true
    title: qsTr("ECM dashboard")

    FontLoader {
        id: nesLowercaseFont
        source: "qrc:/resource/font/resource/font/NES_Lowercase.ttf"
    }

    Component {
        id: loadingScreenComponent

        Rectangle {
            anchors.fill: parent
            color: "#000000"

            Image {
                anchors.centerIn: parent
                width: 180
                height: width
                source: "qrc:/resource/image/resource/image/fiatLogo.png"
            }
        }
    }

    Component {
        id: bodyComponent

        Body {
            id: body
        }
    }

    Loader {
        id: appLoader
        anchors.fill: parent
        sourceComponent: bodyComponent
    }

    Connections {
        target: settingsController

        function onSettingsConfigLoaded() {
            appLoader.sourceComponent = bodyComponent
        }
    }
}
