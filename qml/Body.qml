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

                // alerts handling
                Connections {
                    target: alertQueueHandler
                    function onAlertsQueueChanged() {
                        var frontAlert = alertQueueHandler.getFrontAlert()
                        if(frontAlert !== null) {
                            var dynamicAlert = Qt.createQmlObject('import QtQuick 2.15; Alert {}', parent)
                            dynamicAlert.anchors.right = parent.right
                            dynamicAlert.anchors.bottom = parent.bottom
                            dynamicAlert.anchors.bottomMargin = 50
                            dynamicAlert.alertType = frontAlert.type
                            dynamicAlert.alertIcon = frontAlert.icon
                            dynamicAlert.alertTitle = frontAlert.title
                            dynamicAlert.alertDescription = frontAlert.description

                            var timer = Qt.createQmlObject('import QtQuick 2.15; Timer {}', parent);
                            timer.interval = 10 * 1000;
                            timer.repeat = false;

                            timer.triggered.connect(function() {
                                dynamicAlert.destroy();
                                timer.destroy();
                            });

                            // start the timer
                            timer.start()
                        }
                    }
                }

                Gauge {
                    id: gauge
                }
            }
        }
    }
}
