#include "statusBcm2.h"

StatusBcm2::StatusBcm2() {}

/* SIGNALS
 * encode
 */
uint8_t StatusBcm2::batteryLampStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm2::powerModeStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm2::driveStyleStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm2::stopStartVisualizationCodeEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusBcm2::stopStartActivationStsEncode(double value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
double StatusBcm2::batteryLampStsDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBcm2::powerModeStsDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBcm2::driveStyleStsDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBcm2::stopStartVisualizationCodeDecode(uint8_t value)  {
    return (double)(value);
}

double StatusBcm2::stopStartActivationStsDecode(uint8_t value)  {
    return (double)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *StatusBcm2::serialize(statusBcm2Struct *message) {
}

StatusBcm2::statusBcm2Struct StatusBcm2::deserialize(uint8_t *data) {
    StatusBcm2::statusBcm2Struct deserializedData;
    deserializedData.batteryLampSts = unpackRightShiftU8(data[0], 6, 0xc0);
    deserializedData.powerModeSts = unpackRightShiftU8(data[0], 1, 0x6);
    deserializedData.driveStyleSts = unpackRightShiftU8(data[5], 0, 0x7);
    deserializedData.stopStartVisualizationCode = unpackRightShiftU8(data[6], 5, 0xe0);
    deserializedData.stopStartActivationSts = unpackRightShiftU8(data[6], 2, 0xc);

    return deserializedData;
}