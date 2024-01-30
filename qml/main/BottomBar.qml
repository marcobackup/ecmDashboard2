import QtQuick 2.0

Item {
    width: parent.width
    height: 50
    anchors.bottom: parent.bottom

    property bool handBrakeStatus;
    property bool steeringWheelFaultStatus;
    property bool sbrRLStatus;
    property bool sbrRCStatus;
    property bool sbrRRStatus;
    property bool bonnetStatus;
    property bool lightFaultStatus;

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#000000"

    }
}
