import QtQuick 2.0
import "main"

Item {
    anchors.fill: parent

    property int theme: 0

    Rectangle {
        anchors.fill: parent
        color: "#161517"

        Image {
            id: mainContainer
            source: {
                if(theme == 0)
                    return "qrc:/resource/image/resource/image/background/backgroundRed.png"
                if(theme == 1)
                    return "qrc:/resource/image/resource/image/background/backgroundDarkblue.png"
                if(theme == 2)
                    return "qrc:/resource/image/resource/image/background/backgroundGold.png"
                if(theme == 3)
                    return "qrc:/resource/image/resource/image/background/backgroundSilver.png"
            }

            TopBar {
                id: topBar
            }

            Main {
                id: main
                anchors.top: topBar.bottom
                anchors.bottom: bottomBar.top

                // alerts handling
                Connections {
                    target: alertQueueHandler
                    function onAlertsQueueChanged() {
                        var frontAlert = alertQueueHandler.getFrontAlert()
                        if(frontAlert !== null) {
                            var dynamicAlert = Qt.createQmlObject('import QtQuick 2.15; Alert {}', parent)
                            dynamicAlert.anchors.right = parent.right
                            dynamicAlert.anchors.bottom = parent.bottom
                            dynamicAlert.anchors.bottomMargin = 68
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
            }

            BottomBar {
                id: bottomBar
            }
        }
    }
}
