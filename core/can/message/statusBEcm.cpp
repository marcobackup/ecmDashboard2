#include "statusBEcm.h"

StatusBEcm::StatusBEcm() {}

/* SIGNALS
 * encode
 */
uint8_t StatusBEcm::gPLGasolineModeEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::cNGGasolineModeEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::oilPressureStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::oilPressureFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::fuelWaterPresentStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::glowPlugLampStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::glowPlugFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::fuelWaterPresentFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::cruiseControlLampStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::compressorStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::eMSFailStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::engineWaterTempFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::fpsActuatedEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::engineWaterTempWarningLightStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::engineWaterTempEncode(double value)  {
    return (uint8_t)(value);
}

/*
uint16_t StatusBEcm::fuelConsumptionEncode(double value) {
    return (uint16_t)(value / 0.00049);
}
*/

uint16_t StatusBEcm::fuelConsumptionEncode(double value) {
    return (uint16_t)(value / 0.0022);
}

uint8_t StatusBEcm::engineSpeedEncode(double value)  {
    return (uint8_t)(value / 32);
}

uint8_t StatusBEcm::dPFStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::fuelConsumptionValidDataEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::engineSpeedValidDataEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::oilLevelStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::reverseGearStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm::oilLifeStsEncode(double value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
bool StatusBEcm::gPLGasolineModeDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::cNGGasolineModeDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::oilPressureStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::oilPressureFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::fuelWaterPresentStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::glowPlugLampStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::glowPlugFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::fuelWaterPresentFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::cruiseControlLampStsDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBEcm::compressorStsDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBEcm::eMSFailStsDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusBEcm::engineWaterTempFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::fpsActuatedDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::engineWaterTempWarningLightStsDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBEcm::engineWaterTempDecode(uint8_t value)  {
    return (double)(value);
}

/*
double StatusBEcm::fuelConsumptionDecode(uint16_t value) {
    return (double)(value * 0.00049);
}
*/

double StatusBEcm::fuelConsumptionDecode(uint16_t value) {
    return (double)(value * 0.0022);
}

double StatusBEcm::engineSpeedDecode(uint8_t value)  {
    return (double)(value * 32);
}

bool StatusBEcm::dPFStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::fuelConsumptionValidDataDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::engineSpeedValidDataDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::oilLevelStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm::reverseGearStsDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBEcm::oilLifeStsDecode(uint8_t value)  {
    return (double)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *StatusBEcm::serialize(statusBEcmStruct *message) {
}

StatusBEcm::statusBEcmStruct StatusBEcm::deserialize(uint8_t *data) {
    StatusBEcm::statusBEcmStruct deserializedData;
    deserializedData.gPLGasolineMode = unpackRightShiftU8(data[0], 6, 0x40);
    deserializedData.cNGGasolineMode = unpackRightShiftU8(data[0], 5, 0x20);
    deserializedData.oilPressureSts = unpackRightShiftU8(data[1], 7, 0x80);
    deserializedData.oilPressureFailSts = unpackRightShiftU8(data[1], 6, 0x40);
    deserializedData.fuelWaterPresentSts = unpackRightShiftU8(data[1], 5, 0x20);
    deserializedData.glowPlugLampSts = unpackRightShiftU8(data[1], 4, 0x10);
    deserializedData.glowPlugFailSts = unpackRightShiftU8(data[1], 3, 0x8);
    deserializedData.fuelWaterPresentFailSts = unpackRightShiftU8(data[1], 2, 0x4);
    deserializedData.cruiseControlLampSts = unpackRightShiftU8(data[1], 1, 0x2);
    deserializedData.compressorSts = unpackRightShiftU8(data[2], 6, 0xc0);
    deserializedData.eMSFailSts = unpackRightShiftU8(data[2], 3, 0x18);
    deserializedData.engineWaterTempFailSts = unpackRightShiftU8(data[2], 2, 0x4);
    deserializedData.fpsActuated = unpackRightShiftU8(data[2], 1, 0x2);
    deserializedData.engineWaterTempWarningLightSts = unpackRightShiftU8(data[2], 0, 0x1);
    deserializedData.engineWaterTemp = unpackRightShiftU8(data[3], 0, 0xff);
    deserializedData.fuelConsumption = unpackLeftShiftU16(data[4], 8, 0xff);
    deserializedData.fuelConsumption |= unpackRightShiftU16(data[5], 0, 0xff);
    // deserializedData.fuelConsumption = unpackLeftShiftU16(data[4], 8, 0xff);
    // deserializedData.fuelConsumption |= unpackRightShiftU16(data[5], 0, 0xff);
    deserializedData.engineSpeed = unpackRightShiftU8(data[6], 0, 0xff);
    deserializedData.dPFSts = unpackRightShiftU8(data[7], 7, 0x80);
    deserializedData.fuelConsumptionValidData = unpackRightShiftU8(data[7], 6, 0x40);
    deserializedData.engineSpeedValidData = unpackRightShiftU8(data[7], 5, 0x20);
    deserializedData.oilLevelSts = unpackRightShiftU8(data[7], 4, 0x10);
    deserializedData.reverseGearSts = unpackRightShiftU8(data[7], 2, 0x4);
    deserializedData.oilLifeSts = unpackRightShiftU8(data[7], 0, 0x3);

    return deserializedData;
}
