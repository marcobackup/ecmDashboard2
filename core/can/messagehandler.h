#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include "core/uarthandler.h"
#include "core/controller.h"
#include "core/alertqueue.h"

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

class MessageHandler {
private:
    Controller *controller;
    AlertQueue *alertQueue;
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
    bool iceOnRoadWarningStatus;
    bool lowFuelWarningStatus;
    bool highCoolantTemperatureWarningStatus;
    bool stopLightFailStatus;
    bool rearFogLightFailStatus;
    bool drlFailStatus;
    bool parkLightFailStatus;
    bool plateLightFailStatus;
    bool leftTurnLightFailStatus;
    bool rightTurnLightFailStatus;
    bool steeringWheelFailStatus;
public:
    MessageHandler(Controller *controller, AlertQueue *alertQueue);
    ~MessageHandler();
    void handleMessageData(UartHandler::rxMessage message);
};

#endif // MESSAGEHANDLER_H
