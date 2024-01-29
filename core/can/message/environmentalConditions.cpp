#include "environmentalConditions.h"

EnvironmentalConditions::EnvironmentalConditions() {}

/* SIGNALS
 * encode
 */
uint8_t EnvironmentalConditions::externalTemperatureEncode(double value)  {
    return (uint8_t)(value / 0.5);
}

uint8_t EnvironmentalConditions::externalTemperatureFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t EnvironmentalConditions::batteryVoltageLevelEncode(double value)  {
    return (uint8_t)(value / 0.16);
}

uint8_t EnvironmentalConditions::batteryChargeStsEncode(double value)  {
    return (uint8_t)(value / 5);
}

uint8_t EnvironmentalConditions::currentFailStsIBSEncode(bool value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
double EnvironmentalConditions::externalTemperatureDecode(uint8_t value)  {
    return (double)(((value) * 0.5) - 40);
}

bool EnvironmentalConditions::externalTemperatureFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

double EnvironmentalConditions::batteryVoltageLevelDecode(uint8_t value)  {
    return (double)(value * 0.16);
}

double EnvironmentalConditions::batteryChargeStsDecode(uint8_t value)  {
    return (double)(value * 5);
}

bool EnvironmentalConditions::currentFailStsIBSDecode(uint8_t value)  {
    return (bool)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *EnvironmentalConditions::serialize(environmentalConditionsStruct *message) {
}

EnvironmentalConditions::environmentalConditionsStruct EnvironmentalConditions::deserialize(uint8_t *data) {
    EnvironmentalConditions::environmentalConditionsStruct deserializedData;
    deserializedData.externalTemperature = unpackRightShiftU8(data[0], 0, 0xff);
    deserializedData.externalTemperatureFailSts = unpackRightShiftU8(data[1], 7, 0x80);
    deserializedData.batteryVoltageLevel = unpackRightShiftU8(data[1], 0, 0x7f);
    deserializedData.batteryChargeSts = unpackRightShiftU8(data[3], 3, 0x78);
    deserializedData.currentFailStsIBS = unpackRightShiftU8(data[3], 2, 0x4);

    return deserializedData;
}
