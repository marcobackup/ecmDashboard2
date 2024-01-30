#include "tripAB.h"

TripAB::TripAB() {}

/* SIGNALS
 * encode
 */
uint8_t TripAB::istantaneusFuelConsumption1Encode(double value)  {
    return (uint8_t)(value);
}

uint8_t TripAB::istantaneusFuelConsumption2Encode(double value)  {
    return (uint8_t)(value);
}

uint8_t TripAB::istantaneusFuelConsumption3Encode(double value)  {
    return (uint8_t)(value);
}

uint32_t TripAB::totalOdometerEncode(double value) {
    return (uint32_t)(value);
}

uint8_t TripAB::istantFuelConsumptionValidDataEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t TripAB::autonomyDistanceValidDataEncode(bool value)  {
    return (uint8_t)(value);
}

uint16_t TripAB::autonomyDistanceEncode(double value) {
    return (uint16_t)(value);
}

/* SIGNALS
 * decode
 */
double TripAB::istantaneusFuelConsumption1Decode(uint8_t value)  {
    return (double)(value);
}

double TripAB::istantaneusFuelConsumption2Decode(uint8_t value)  {
    return (double)(value);
}

double TripAB::istantaneusFuelConsumption3Decode(uint8_t value)  {
    return (double)(value);
}

double TripAB::totalOdometerDecode(uint32_t value) {
    return (double)(value);
}

bool TripAB::istantFuelConsumptionValidDataDecode(uint8_t value)  {
    return (bool)(value);
}

bool TripAB::autonomyDistanceValidDataDecode(uint8_t value)  {
    return (bool)(value);
}

double TripAB::autonomyDistanceDecode(uint16_t value) {
    return (double)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *TripAB::serialize(tripABStruct *message) {
}

TripAB::tripABStruct TripAB::deserialize(uint8_t *data) {
    TripAB::tripABStruct deserializedData;
    deserializedData.istantaneusFuelConsumption1 = unpackRightShiftU8(data[0], 4, 0xf0);
    deserializedData.istantaneusFuelConsumption2 = unpackRightShiftU8(data[0], 0, 0xf);
    deserializedData.istantaneusFuelConsumption3 = unpackRightShiftU8(data[1], 4, 0xf0);
    deserializedData.totalOdometer = unpackLeftShiftU32(data[1], 16, 0xf);
    deserializedData.totalOdometer |= unpackLeftShiftU32(data[2], 8, 0xff);
    deserializedData.totalOdometer |= unpackRightShiftU32(data[3], 0, 0xff);
    deserializedData.istantFuelConsumptionValidData = unpackRightShiftU8(data[4], 7, 0x80);
    deserializedData.autonomyDistanceValidData = unpackRightShiftU8(data[4], 3, 0x8);
    deserializedData.autonomyDistance = unpackLeftShiftU16(data[4], 8, 0x7);
    deserializedData.autonomyDistance |= unpackRightShiftU16(data[5], 0, 0xff);

    return deserializedData;
}