#include "messagehandler.h"
#include "core/uarthandler.h"
#include "core/controller.h"
#include "core/alertqueue.h"
#include <QDebug>

#include "core/can/message/environmentalConditions.h"
#include "core/can/message/externalLights.h"
#include "core/can/message/vehicleSpeedOdometer.h"

MessageHandler::MessageHandler(Controller *controller, AlertQueue *alertQueue)
    : controller(controller)
    , alertQueue(alertQueue) {
    EnvironmentalConditions environmentalConditions;
    EnvironmentalConditions::environmentalConditionsStruct environmentalConditionsResponse;
    ExternalLights externalLights;
    ExternalLights::externalLightsStruct externalLightsResponse;
    StatusBcm statusBcm;
    StatusBcm::statusBcmStruct statusBcmResponse;
    StatusBcm2 statusBcm2;
    StatusBcm2::statusBcm2Struct statusBcm2Response;
    StatusBEcm statusBEcm;
    StatusBEcm::statusBEcmStruct statusBEcmResponse;
    StatusBEcm2 statusBEcm2;
    StatusBEcm2::statusBEcm2Struct statusBEcm2Response;
    VehicleSpeedOdometer vehicleSpeedOdometer;
    VehicleSpeedOdometer::vehicleSpeedOdometerStruct vehicleSpeedOdometerResponse;

    // dynamic var
    bool iceOnRoadWarningStatus = false;
    bool lowFuelWarningStatus = false;
    bool highCoolantTemperatureWarningStatus = false;
    bool stopLightFailStatus = false;
    bool rearFogLightFailStatus = false;
    bool drlFailStatus = false;
    bool parkLightFailStatus = false;
    bool plateLightFailStatus = false;
    bool leftTurnLightFailStatus = false;
    bool rightTurnLightFailStatus = false;
    bool steeringWheelFailStatus = false;
}

MessageHandler::~MessageHandler() {
}

void MessageHandler::handleMessageData(UartHandler::rxMessage message) {
    if(message.arbitration_id == 0x63d4000) {
        environmentalConditionsResponse = environmentalConditions.deserialize(message.data);
        const int minEnvironmentalTemperature = 3;
        double environmentalTemperature;

        // environmental temperature
        if(environmentalConditionsResponse.externalTemperatureFailSts == ENVIRONMENTAL_CONDITIONS_externalTemperatureFailSts_Fail_Present_CHOICE) {
            controller->topBar->setEnvironmentalTemperature(0);
        } else {
            environmentalTemperature = environmentalConditions.externalTemperatureDecode(environmentalConditionsResponse.externalTemperature);
            // ice on road warning status
            if(!iceOnRoadWarningStatus) {
                if(environmentalTemperature <= minEnvironmentalTemperature) {
                    iceOnRoadWarningStatus = true;
                    alertQueue->addWarningAlert("qrc:/resource/image/resource/image/weather/snowWeatherIcon.png", "ATTENZIONE", "possibile ghiaccio su strada, prestare attenzione");
                }
            }
            if(environmentalTemperature > minEnvironmentalTemperature)
                iceOnRoadWarningStatus = false;

            controller->topBar->setEnvironmentalTemperature(environmentalTemperature);
        }
    }
    if(message.arbitration_id == 0x2214000) {
        externalLightsResponse = externalLights.deserialize(message.data);

        // left arrow status
        if(externalLightsResponse.lHTurnSignalSts == EXTERNAL_LIGHTS_lHTurnSignalSts_ON_CHOICE)
            controller->topBar->setLeftArrowStatus(true);
        else
            controller->topBar->setLeftArrowStatus(false);

        // right arrow status
        if(externalLightsResponse.rHTurnSignalSts == EXTERNAL_LIGHTS_rHTurnSignalSts_ON_CHOICE)
            controller->topBar->setRightArrowStatus(true);
        else
            controller->topBar->setRightArrowStatus(false);

        // low beam light status
        if(externalLightsResponse.lowBeamSts == EXTERNAL_LIGHTS_lowBeamSts_ON_CHOICE)
            controller->topBar->setLowBeamLightStatus(true);
        else
            controller->topBar->setLowBeamLightStatus(false);

        // high beam light status
        if(externalLightsResponse.highBeamSts == EXTERNAL_LIGHTS_highBeamSts_ON_CHOICE)
            controller->topBar->setHighBeamLightStatus(true);
        else
            controller->topBar->setHighBeamLightStatus(false);
    }
    if(message.arbitration_id == 0x4394000) {
        vehicleSpeedOdometerResponse = vehicleSpeedOdometer.deserialize(message.data);

        // speed
        if(vehicleSpeedOdometerResponse.vehicleSpeedFailSts != VEHICLE_SPEED_ODOMETER_vehicleSpeedFailSts_Fail_present_CHOICE)
            controller->gauge->setSpeed(vehicleSpeedOdometer.vehicleSpeedDecode(vehicleSpeedOdometerResponse.vehicleSpeed));
        else
            controller->gauge->setSpeed(0);
    }
}
