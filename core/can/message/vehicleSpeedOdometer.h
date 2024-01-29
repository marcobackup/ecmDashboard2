#ifndef VEHICLE_SPEED_ODOMETER_H
#define VEHICLE_SPEED_ODOMETER_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define VEHICLE_SPEED_ODOMETER_FRAME_ID 70860800
#define VEHICLE_SPEED_ODOMETER_NAME "VEHICLE_SPEED_ODOMETER"
#define VEHICLE_SPEED_ODOMETER_LENGTH 4
#define VEHICLE_SPEED_ODOMETER_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define vehicleSpeed_NAME "VehicleSpeed" 
#define vehicleSpeedFailSts_NAME "VehicleSpeedFailSts" 
#define travelDistance_NAME "TravelDistance" 

/* SIGNALS
 * choices
 */
#define VEHICLE_SPEED_ODOMETER_vehicleSpeedFailSts_Fail_present_CHOICE (1u)
#define VEHICLE_SPEED_ODOMETER_vehicleSpeedFailSts_Fail_not_present_CHOICE (0u)

class VehicleSpeedOdometer : public Serializer, public Deserializer
{
public:
    VehicleSpeedOdometer();
    typedef struct vehicleSpeedOdometerStruct {
        uint16_t vehicleSpeed;
        uint8_t vehicleSpeedFailSts;
        uint8_t travelDistance;
    } vehicleSpeedOdometerStruct;

    /* SIGNALS
    * encode
    */
    uint16_t vehicleSpeedEncode(double value);
    uint8_t vehicleSpeedFailStsEncode(bool value);
    uint8_t travelDistanceEncode(double value);

    /* SIGNALS
    * decode
    */
    double vehicleSpeedDecode(uint16_t value);
    bool vehicleSpeedFailStsDecode(uint8_t value);
    double travelDistanceDecode(uint8_t value);

    uint8_t *serialize(vehicleSpeedOdometerStruct *payload);
    vehicleSpeedOdometerStruct deserialize(uint8_t *data);
};

#endif