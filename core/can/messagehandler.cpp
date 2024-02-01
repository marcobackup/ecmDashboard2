#include "messagehandler.h"
#include "core/uarthandler.h"
#include "core/controller.h"
#include "core/alertqueue.h"
#include <QDebug>

#include "core/can/message/environmentalConditions.h"
#include "core/can/message/externalLights.h"
#include "core/can/message/statusBcm.h"
#include "core/can/message/statusBcm2.h"
#include "core/can/message/statusBEcm.h"
#include "core/can/message/statusBEcm2.h"
#include "core/can/message/statusBEps.h"
#include "core/can/message/statusSdm.h"
#include "core/can/message/tripAB.h"
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
    StatusBEps statusBEps;
    StatusBEps::statusBEpsStruct statusBEpsResponse;
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

        // battery voltage
        controller->carParameter->setBatteryVoltage(environmentalConditions.batteryVoltageLevelDecode(environmentalConditionsResponse.batteryVoltageLevel));
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

        /*
         * light fault status
         */

        // stop light fault
        if(externalLightsResponse.lHStopLightFailSts == EXTERNAL_LIGHTS_lHStopLightFailSts_Fail_Present_CHOICE) {
            if(!stopLightFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI STOP", "attenzione, far controllare luci stop");
                stopLightFailStatus = true;
            }
        } else
            stopLightFailStatus = false;

        // rear fog light fault
        if(externalLightsResponse.lHRearFogLightFailSts == EXTERNAL_LIGHTS_lHRearFogLightFailSts_Fail_Present_CHOICE) {
            if(!rearFogLightFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI RETRONEBBIA", "attenzione, far controllare luci retronebbia");
                rearFogLightFailStatus = true;
            }
        } else
            rearFogLightFailStatus = false;

        // drl fault
        if(externalLightsResponse.dRLFault == EXTERNAL_LIGHTS_dRLFault_True_CHOICE) {
            if(!drlFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI DIURNE", "attenzione, far controllare luci diurne");
                drlFailStatus = true;
            }
        } else
            drlFailStatus = false;

        // plate light fault
        if(externalLightsResponse.plateLightFailSts == EXTERNAL_LIGHTS_plateLightFailSts_Fail_Present_CHOICE) {
            if(!plateLightFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI TARGA", "attenzione, far controllare luci targa");
                plateLightFailStatus = true;
            }
        } else
            plateLightFailStatus = false;

        // park light fault
        if(externalLightsResponse.rHFParkTailLightFailSts == EXTERNAL_LIGHTS_rHFParkTailLightFailSts_Fail_Present_CHOICE ||
            externalLightsResponse.lHFParkTailLightFailSts == EXTERNAL_LIGHTS_lHFParkTailLightFailSts_Fail_Present_CHOICE) {
            if(!parkLightFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI DI POSIZIONE", "attenzione, far controllare luci di posizione");
                parkLightFailStatus = true;
            }
        } else
            parkLightFailStatus = false;

        // left turn light fault
        if(externalLightsResponse.lHFTurnLightFailSts == EXTERNAL_LIGHTS_lHFParkTailLightFailSts_Fail_Present_CHOICE) {
            if(!leftTurnLightFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI FRECCE", "attenzione, far controllare luci freccia sinistra");
                leftTurnLightFailStatus = true;
            }
        } else
            leftTurnLightFailStatus = false;

        // right turn light fault
        if(externalLightsResponse.rHFTurnLightFailSts == EXTERNAL_LIGHTS_rHFParkTailLightFailSts_Fail_Present_CHOICE) {
            if(!rightTurnLightFailStatus) {
                alertQueue->addFaultAlert("qrc:/resource/image/resource/image/indicatorLight/lightFault.png", "LUCI FRECCE", "attenzione, far controllare luci freccia destra");
                rightTurnLightFailStatus = true;
            }
        } else
            rightTurnLightFailStatus = false;

        if(stopLightFailStatus || rearFogLightFailStatus || drlFailStatus || parkLightFailStatus || plateLightFailStatus || leftTurnLightFailStatus || rightTurnLightFailStatus)
            controller->bottomBar->setLightFaultStatus(true);
        else
            controller->bottomBar->setLightFaultStatus(false);
    }
    if(message.arbitration_id == 0x6214000) {
        statusBcmResponse = statusBcm.deserialize(message.data);

        // handbrake status
        if(statusBcmResponse.handBrakeSts == STATUS_BCM_handBrakeSts_ON_CHOICE)
            controller->bottomBar->setHandBrakeStatus(true);
        else
            controller->bottomBar->setHandBrakeStatus(false);

        // bonnet status
        if(statusBcmResponse.bonnetSts == STATUS_BCM_bonnetSts_Open_CHOICE)
            controller->bottomBar->setBonnetStatus(true);
        else
            controller->bottomBar->setBonnetStatus(false);

        // hatch status
        if(statusBcmResponse.rHatchSts == STATUS_BCM_rHatchSts_Open_CHOICE)
            controller->bottomBar->setBonnetStatus(true);
        else
            controller->bottomBar->setBonnetStatus(false);

        // fuel level
        if(statusBcmResponse.fuelLevelFailSts != STATUS_BCM_fuelLevelFailSts_Fail_Present_CHOICE)
            controller->carParameter->setFuelLevel(statusBcm.fuelLevelDecode(statusBcmResponse.fuelLevel));
        else
            controller->carParameter->setFuelLevel(0);

        // low fuel level warning status
        if(statusBcmResponse.lowFuelWarningSts == STATUS_BCM_lowFuelWarningSts_ON_CHOICE)
            controller->carParameter->setLowFuelLevelWarningStatus(true);
        else
            controller->carParameter->setLowFuelLevelWarningStatus(false);
    }
    if(message.arbitration_id == 0x4214001) {
        statusBEcmResponse = statusBEcm.deserialize(message.data);

        // rpm
        if(statusBEcmResponse.engineSpeedValidData != STATUS_B_ECM_engineSpeedValidData_Not_valid_CHOICE)
            controller->gauge->setRpm(statusBEcm.engineSpeedDecode(statusBEcmResponse.engineSpeed));
        else
            controller->gauge->setRpm(0);

        // coolant temperature
        if(statusBEcmResponse.engineWaterTempFailSts != STATUS_B_ECM_engineWaterTempFailSts_Fail_Present_CHOICE)
            controller->carParameter->setCoolantTemperature(statusBEcm.engineWaterTempDecode(statusBEcmResponse.engineWaterTemp));
        else
            controller->carParameter->setCoolantTemperature(0);

        // high coolant temperature warning status
        if(statusBEcmResponse.engineWaterTempWarningLightSts == STATUS_B_ECM_engineWaterTempWarningLightSts_ON_CHOICE)
            controller->carParameter->setHighCoolantTemperatureWarningStatus(true);
        else
            controller->carParameter->setHighCoolantTemperatureWarningStatus(false);
    }
    if(message.arbitration_id == 0x4294001) {
        statusBEcm2Response = statusBEcm2.deserialize(message.data);

        // turbo pressure
        controller->carParameter->setBoostPressure(statusBEcm2.boostPressureIndicationDecode(statusBEcm2Response.boostPressureIndication));
    }
    if(message.arbitration_id == 0x4214002) {
        statusBEpsResponse = statusBEps.deserialize(message.data);

        // steering wheel fault status
        if(statusBEpsResponse.electricSteeringFailSts == STATUS_B_EPS_electricSteeringFailSts_Fail_Present_CHOICE)
            controller->bottomBar->setSteeringWheelFaultStatus(true);
        else
            controller->bottomBar->setSteeringWheelFaultStatus(false);
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
