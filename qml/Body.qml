import QtQuick 2.0

Item {
    anchors.fill: parent

    Rectangle {
        anchors.fill: parent
        color: "#161517"

        Image {
            id: mainContainer
            source: "qrc:/resource/image/resource/image/background.png"

            TopBar {
                id: topBar
            }

            Rectangle {
                anchors.top: topBar.bottom
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                color: "transparent"

                Gauge {
                    id: gauge
                }
            }
        }
    }
}
