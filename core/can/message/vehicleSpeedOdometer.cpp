#include "vehicleSpeedOdometer.h"

VehicleSpeedOdometer::VehicleSpeedOdometer() {}

/* SIGNALS
 * encode
 */
uint16_t VehicleSpeedOdometer::vehicleSpeedEncode(double value) {
    return (uint16_t)(value / 0.0625);
}

uint8_t VehicleSpeedOdometer::vehicleSpeedFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t VehicleSpeedOdometer::travelDistanceEncode(double value)  {
    return (uint8_t)(value / 9.8);
}

/* SIGNALS
 * decode
 */
double VehicleSpeedOdometer::vehicleSpeedDecode(uint16_t value) {
    return (double)(value * 0.0625);
}

bool VehicleSpeedOdometer::vehicleSpeedFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

double VehicleSpeedOdometer::travelDistanceDecode(uint8_t value)  {
    return (double)(value * 9.8);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *VehicleSpeedOdometer::serialize(vehicleSpeedOdometerStruct *message) {
}

VehicleSpeedOdometer::vehicleSpeedOdometerStruct VehicleSpeedOdometer::deserialize(uint8_t *data) {
    VehicleSpeedOdometer::vehicleSpeedOdometerStruct deserializedData;
    deserializedData.vehicleSpeed = unpackLeftShiftU16(data[0], 8, 0x1f);
    deserializedData.vehicleSpeed |= unpackRightShiftU16(data[1], 0, 0xff);
    deserializedData.vehicleSpeedFailSts = unpackRightShiftU8(data[2], 7, 0x80);
    deserializedData.travelDistance = unpackRightShiftU8(data[3], 0, 0xff);

    return deserializedData;
}