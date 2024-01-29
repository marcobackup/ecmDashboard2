import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("ECM dashboard")

    property bool status: false

    Rectangle {
        id: rect
        width: 250
        height: width
        anchors.centerIn: parent
        radius: 90
        color: {
            if(status)
                return "#b70009"
            else
                return "#161517"
        }
    }

    MouseArea {
        anchors.fill: rect
        onClicked: {
            status = !status
        }
    }
}
