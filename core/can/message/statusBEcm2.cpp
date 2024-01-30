#include "statusBEcm2.h"

StatusBEcm2::StatusBEcm2() {}

/* SIGNALS
 * encode
 */
uint8_t StatusBEcm2::engineOilTempEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::boostPressureIndicationEncode(double value)  {
    return (uint8_t)(value / 15);
}

uint8_t StatusBEcm2::gearShiftIndicationEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::cNGGasolineModeEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::alternativeFuelFillingTankEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::stopStartStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::engineStopStartStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::startRelayBCMFeedbackFaultEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::startRelayECMFeedbackFaultEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::fuelModeDriverReqStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusBEcm2::sAMInfoEncode(double value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
double StatusBEcm2::engineOilTempDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBEcm2::boostPressureIndicationDecode(uint8_t value)  {
    return (double)(value * 15);
}

double StatusBEcm2::gearShiftIndicationDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusBEcm2::cNGGasolineModeDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBEcm2::alternativeFuelFillingTankDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBEcm2::stopStartStsDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBEcm2::engineStopStartStsDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusBEcm2::startRelayBCMFeedbackFaultDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm2::startRelayECMFeedbackFaultDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusBEcm2::fuelModeDriverReqStsDecode(uint8_t value)  {
    return (bool)(value);
}

double StatusBEcm2::sAMInfoDecode(uint8_t value)  {
    return (double)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *StatusBEcm2::serialize(statusBEcm2Struct *message) {
}

StatusBEcm2::statusBEcm2Struct StatusBEcm2::deserialize(uint8_t *data) {
    StatusBEcm2::statusBEcm2Struct deserializedData;
    deserializedData.engineOilTemp = unpackRightShiftU8(data[1], 0, 0x7);
    deserializedData.boostPressureIndication = unpackRightShiftU8(data[2], 0, 0xff);
    deserializedData.gearShiftIndication = unpackRightShiftU8(data[3], 0, 0x3);
    deserializedData.cNGGasolineMode = unpackRightShiftU8(data[4], 7, 0x80);
    deserializedData.alternativeFuelFillingTank = unpackRightShiftU8(data[4], 0, 0x7f);
    deserializedData.stopStartSts = unpackRightShiftU8(data[5], 6, 0xc0);
    deserializedData.engineStopStartSts = unpackRightShiftU8(data[5], 4, 0x30);
    deserializedData.startRelayBCMFeedbackFault = unpackRightShiftU8(data[5], 3, 0x8);
    deserializedData.startRelayECMFeedbackFault = unpackRightShiftU8(data[5], 2, 0x4);
    deserializedData.fuelModeDriverReqSts = unpackRightShiftU8(data[5], 0, 0x1);
    deserializedData.sAMInfo = unpackRightShiftU8(data[6], 3, 0x78);

    return deserializedData;
}