#include "externalLights.h"

ExternalLights::ExternalLights() {}

/* SIGNALS
 * encode
 */
uint8_t ExternalLights::lHParkTailLightStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::highBeamStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::lowBeamStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::fogLightStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::rearFogLightStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::lHTurnSignalStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::rHTurnSignalStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::rHeatedWindowStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::rHFTurnLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::lHFTurnLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::lHStopLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::lHRearFogLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::rHFParkTailLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::lHFParkTailLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::plateLightFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t ExternalLights::dRLFaultEncode(bool value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
bool ExternalLights::lHParkTailLightStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::highBeamStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::lowBeamStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::fogLightStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::rearFogLightStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::lHTurnSignalStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::rHTurnSignalStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::rHeatedWindowStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::rHFTurnLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::lHFTurnLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::lHStopLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::lHRearFogLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::rHFParkTailLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::lHFParkTailLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::plateLightFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool ExternalLights::dRLFaultDecode(uint8_t value)  {
    return (bool)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *ExternalLights::serialize(externalLightsStruct *message) {
}

ExternalLights::externalLightsStruct ExternalLights::deserialize(uint8_t *data) {
    ExternalLights::externalLightsStruct deserializedData;
    deserializedData.lHParkTailLightSts = unpackRightShiftU8(data[1], 5, 0x20);
    deserializedData.highBeamSts = unpackRightShiftU8(data[1], 4, 0x10);
    deserializedData.lowBeamSts = unpackRightShiftU8(data[1], 3, 0x8);
    deserializedData.fogLightSts = unpackRightShiftU8(data[1], 2, 0x4);
    deserializedData.rearFogLightSts = unpackRightShiftU8(data[1], 1, 0x2);
    deserializedData.lHTurnSignalSts = unpackRightShiftU8(data[2], 6, 0x40);
    deserializedData.rHTurnSignalSts = unpackRightShiftU8(data[2], 5, 0x20);
    deserializedData.rHeatedWindowSts = unpackRightShiftU8(data[2], 4, 0x10);
    deserializedData.rHFTurnLightFailSts = unpackRightShiftU8(data[3], 7, 0x80);
    deserializedData.lHFTurnLightFailSts = unpackRightShiftU8(data[3], 6, 0x40);
    deserializedData.lHStopLightFailSts = unpackRightShiftU8(data[3], 4, 0x10);
    deserializedData.lHRearFogLightFailSts = unpackRightShiftU8(data[3], 1, 0x2);
    deserializedData.rHFParkTailLightFailSts = unpackRightShiftU8(data[4], 5, 0x20);
    deserializedData.lHFParkTailLightFailSts = unpackRightShiftU8(data[4], 4, 0x10);
    deserializedData.plateLightFailSts = unpackRightShiftU8(data[4], 3, 0x8);
    deserializedData.dRLFault = unpackRightShiftU8(data[4], 2, 0x4);

    return deserializedData;
}