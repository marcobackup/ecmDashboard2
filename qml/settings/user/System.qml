import QtQuick 2.15
import QtGraphicalEffects 1.15

Item {
    y: 115

    property int index: 0

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
            name: "DISATTIVO"
            value: "audio_off"
        }
        ListElement {
            name: "ATTIVO"
            value: "audio_on"
        }
        ListElement {
            name: "TORNA INDIETRO"
            value: "go_home"
        }
    }

    property ListModel aboutMenu: ListModel {
        ListElement {
            name: "Grafica e firmware\nsviluppato da"
        }
        ListElement {
            name: "marcosgro03@gmail.com"
        }
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
            currentIndex: index
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
                        font.pixelSize: 18
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            switch(model.value) {
                                case "home_theme":
                                    menuList.model = themeMenu
                                    index = settingsController.theme
                                    break
                                case "theme_darkred":
                                    settingsController.theme = 0
                                    index = settingsController.theme
                                    break
                                case "theme_darkblue":
                                    settingsController.theme = 1
                                    index = settingsController.theme
                                    break
                                case "theme_gold":
                                    settingsController.theme = 2
                                    index = settingsController.theme
                                    break
                                case "theme_silver":
                                    settingsController.theme = 3
                                    index = settingsController.theme
                                    break
                                case "home_language":
                                    menuList.model = languageMenu
                                    index = settingsController.language
                                    break
                                case "language_italian":
                                    settingsController.language = 0
                                    index = settingsController.language
                                    break
                                case "language_englishus":
                                    settingsController.language = 1
                                    index = settingsController.language
                                    break
                                case "language_englishuk":
                                    settingsController.language = 2
                                    index = settingsController.language
                                    break
                                case "language_spanish":
                                    settingsController.language = 3
                                    index = settingsController.language
                                    break
                                case "language_french":
                                    settingsController.language = 4
                                    index = settingsController.language
                                    break
                                case "home_audio":
                                    menuList.model = audioMenu
                                    index = settingsController.audioStatus
                                    break
                                case "audio_on":
                                    settingsController.audioStatus = true
                                    index = 1
                                    break
                                case "audio_off":
                                    settingsController.audioStatus = false
                                    index = 0
                                    break
                                case "home_about":
                                    menuList.model = aboutMenu
                                    break
                                case "go_home":
                                    menuList.model = homeMenu
                                    break
                            }
                        }
                    }
                }
            }
        }
    }
}
