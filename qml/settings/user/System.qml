import QtQuick 2.0
import QtQuick 2.15
import QtGraphicalEffects 1.15

Item {
    y: 115

    property ListModel homeMenu: ListModel {
        ListElement {
            name: "TEMA"
            value: "home_theme"
        }
        ListElement {
            name: "LINGUA"
            value: "home_language"
        }
        ListElement {
            name: "AUDIO"
            value: "home_audio"
        }
        ListElement {
            name: "INFORMAZIONI"
            value: "home_about"
        }
    }

    property ListModel themeMenu: ListModel {
        ListElement {
            name: "ROSSO SCURO"
            value: "theme_darkred"
        }
        ListElement {
            name: "BLU SCURO"
            value: "theme_darkblue"
        }
        ListElement {
            name: "ORO"
            value: "theme_gold"
        }
        ListElement {
            name: "ARGENTO"
            value: "theme_silver"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel languageMenu: ListModel {
        ListElement {
            name: "ITALIANO"
            value: "language_italian"
        }
        ListElement {
            name: "INGLESE (us)"
            value: "language_englishus"
        }
        ListElement {
            name: "INGLESE (uk)"
            value: "language_englishuk"
        }
        ListElement {
            name: "SPAGNOLO"
            value: "language_spanish"
        }
        ListElement {
            name: "FRANCESE"
            value: "language_french"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel audioMenu: ListModel {
        ListElement {
            name: "ATTIVO"
            value: "audio_on"
        }
        ListElement {
            name: "DISATTIVO"
            value: "audio_off"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel aboutMenu: ListModel {
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    Image {
        source: "qrc:/resource/image/resource/image/settings/systemMenuMask.png"
        anchors.horizontalCenter: parent.horizontalCenter

        ListView {
            id: menuList
            width: parent.width / 1.5
            height: parent.height / 1.5
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            currentIndex: 0
            clip: true

            model: homeMenu

            delegate: Item {
                width: menuList.width
                height: menuList.height / 3

                Rectangle {
                    id: menuItem
                    width: parent.width
                    height: menuList.height / 2
                    color: index === menuList.currentIndex ? "#121111" : "#161517"

                    Text {
                        anchors.centerIn: parent
                        text: model.name
                        color: "#fff"
                        font.family: nesLowercaseFont.name
                        font.pixelSize: 16
                    }
                }
            }
        }
    }
}
