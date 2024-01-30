#include "statusBEps.h"

StatusBEps::StatusBEps() {}

/* SIGNALS
 * encode
 */
uint8_t StatusBEps::electricSteeringFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
bool StatusBEps::electricSteeringFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *StatusBEps::serialize(statusBEpsStruct *message) {
}

StatusBEps::statusBEpsStruct StatusBEps::deserialize(uint8_t *data) {
    StatusBEps::statusBEpsStruct deserializedData;
    deserializedData.electricSteeringFailSts = unpackRightShiftU8(data[1], 7, 0x80);

    return deserializedData;
}