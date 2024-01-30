#include "statusBcm.h"

StatusBcm::StatusBcm() {}

/* SIGNALS
 * encode
 */
uint8_t StatusBcm::brakePadWearStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::brakeFluidLevelStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::handBrakeStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::internalLightStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::sysEOLStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::bonnetStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::rHatchStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::rHRDoorStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::lHRDoorStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::psngrDoorStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::driverDoorStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::keyStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::rechargeStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::lowFuelWarningStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::fuelLevelFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::fuelLevelEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::fpsNotAvailableEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::iMMOCodeWarningLightStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::rainSensorFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm::cityModeStsEncode(bool value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
bool StatusBcm::brakePadWearStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::brakeFluidLevelStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::handBrakeStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::internalLightStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::sysEOLStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::bonnetStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::rHatchStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::rHRDoorStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::lHRDoorStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::psngrDoorStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::driverDoorStsDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBcm::keyStsDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusBcm::rechargeStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::lowFuelWarningStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::fuelLevelFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBcm::fuelLevelDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusBcm::fpsNotAvailableDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBcm::iMMOCodeWarningLightStsDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusBcm::rainSensorFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBcm::cityModeStsDecode(uint8_t value)  {
    return (bool)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *StatusBcm::serialize(statusBcmStruct *message) {
}

StatusBcm::statusBcmStruct StatusBcm::deserialize(uint8_t *data) {
    StatusBcm::statusBcmStruct deserializedData;
    deserializedData.brakePadWearSts = unpackRightShiftU8(data[0], 7, 0x80);
    deserializedData.brakeFluidLevelSts = unpackRightShiftU8(data[0], 6, 0x40);
    deserializedData.handBrakeSts = unpackRightShiftU8(data[0], 5, 0x20);
    deserializedData.internalLightSts = unpackRightShiftU8(data[0], 3, 0x8);
    deserializedData.sysEOLSts = unpackRightShiftU8(data[0], 2, 0x4);
    deserializedData.bonnetSts = unpackRightShiftU8(data[1], 7, 0x80);
    deserializedData.rHatchSts = unpackRightShiftU8(data[1], 6, 0x40);
    deserializedData.rHRDoorSts = unpackRightShiftU8(data[1], 5, 0x20);
    deserializedData.lHRDoorSts = unpackRightShiftU8(data[1], 4, 0x10);
    deserializedData.psngrDoorSts = unpackRightShiftU8(data[1], 3, 0x8);
    deserializedData.driverDoorSts = unpackRightShiftU8(data[1], 2, 0x4);
    deserializedData.keySts = unpackRightShiftU8(data[2], 4, 0xf0);
    deserializedData.rechargeSts = unpackRightShiftU8(data[2], 3, 0x8);
    deserializedData.lowFuelWarningSts = unpackRightShiftU8(data[4], 1, 0x2);
    deserializedData.fuelLevelFailSts = unpackRightShiftU8(data[4], 0, 0x1);
    deserializedData.fuelLevel = unpackRightShiftU8(data[5], 0, 0xff);
    deserializedData.fpsNotAvailable = unpackRightShiftU8(data[6], 7, 0x80);
    deserializedData.iMMOCodeWarningLightSts = unpackRightShiftU8(data[6], 0, 0x7f);
    deserializedData.rainSensorFailSts = unpackRightShiftU8(data[7], 7, 0x80);
    deserializedData.cityModeSts = unpackRightShiftU8(data[7], 0, 0x1);

    return deserializedData;
}