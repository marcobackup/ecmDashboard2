#include "environmentLight.h"

EnvironmentLight::EnvironmentLight() {}

/* SIGNALS
 * encode
 */
uint8_t EnvironmentLight::left_light_levelEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t EnvironmentLight::left_light_sourceEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t EnvironmentLight::right_light_sourceEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t EnvironmentLight::right_light_levelEncode(double value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
double EnvironmentLight::left_light_levelDecode(uint8_t value)  {
    return (double)(value);
}

double EnvironmentLight::left_light_sourceDecode(uint8_t value)  {
    return (double)(value);
}

double EnvironmentLight::right_light_sourceDecode(uint8_t value)  {
    return (double)(value);
}

double EnvironmentLight::right_light_levelDecode(uint8_t value)  {
    return (double)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *EnvironmentLight::serialize(environmentLightStruct *message) {
    uint8_t *payload;
    payload[0] = packRightShiftU8(message->left_light_level, 0, 0xff);
    payload[1] = packRightShiftU8(message->left_light_source, 6, 0xc0);
    payload[1] = packRightShiftU8(message->right_light_source, 4, 0x30);
    payload[2] = packRightShiftU8(message->right_light_level, 0, 0xff);
    return payload;
}

EnvironmentLight::environmentLightStruct EnvironmentLight::deserialize(uint8_t *data) {
    EnvironmentLight::environmentLightStruct deserializedData;
    deserializedData.left_light_level = unpackRightShiftU8(data[0], 0, 0xff);
    deserializedData.left_light_source = unpackRightShiftU8(data[1], 6, 0xc0);
    deserializedData.right_light_source = unpackRightShiftU8(data[1], 4, 0x30);
    deserializedData.right_light_level = unpackRightShiftU8(data[2], 0, 0xff);

    return deserializedData;
}
