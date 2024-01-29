#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include "core/uarthandler.h"
#include "core/controller.h"

#include "core/can/message/environmentalConditions.h"
#include "core/can/message/externalLights.h"
#include "core/can/message/vehicleSpeedOdometer.h"

class MessageHandler {
private:
    Controller *controller;
    EnvironmentalConditions environmentalConditions;
    EnvironmentalConditions::environmentalConditionsStruct environmentalConditionsResponse;
    ExternalLights externalLights;
    ExternalLights::externalLightsStruct externalLightsResponse;
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
    MessageHandler(Controller *controller);
    ~MessageHandler();
    void handleMessageData(UartHandler::rxMessage message);
};

#endif // MESSAGEHANDLER_H
