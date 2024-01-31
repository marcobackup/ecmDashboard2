QT += quick
QT += serialport
QT += multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        core/controller/alert.cpp \
        core/alertqueue.cpp \
        core/controller.cpp \
        core/controller/bottombar.cpp \
        core/controller/carparameter.cpp \
        core/controller/settings.cpp \
        core/controller/trip.cpp \
        core/controller/gauge.cpp \
        core/controller/topbar.cpp \
        core/soundhandler.cpp \
        core/uarthandler.cpp \
        core/can/deserializer.cpp \
        core/can/serializer.cpp \
        core/can/messagehandler.cpp \
        core/can/message/environmentalConditions.cpp \
        core/can/message/externalLights.cpp \
        core/can/message/vehicleSpeedOdometer.cpp \
        core/can/message/statusBcm.cpp \
        core/can/message/statusBcm2.cpp \
        core/can/message/statusBEcm.cpp \
        core/can/message/statusBEcm2.cpp \
        core/can/message/statusBEps.cpp \
        core/can/message/statusSdm.cpp \
        core/can/message/tripAB.cpp \
        main.cpp

RESOURCES += resource.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    core/controller/alert.h \
    core/alertqueue.h \
    core/controller/bottombar.h \
    core/controller/carparameter.h \
    core/controller/gauge.h \
    core/controller/settings.h \
    core/controller/topbar.h \
    core/controller/trip.h \
    core/soundhandler.h \
    core/uarthandler.h
