#include "ecmStatus.h"
#include <cstring>

EcmStatus::EcmStatus() {}

/* SIGNALS
 * encode
 */
uint8_t EcmStatus::themeEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t EcmStatus::languageEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t EcmStatus::audio_statusEncode(double value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
double EcmStatus::themeDecode(uint8_t value)  {
    return (double)(value);
}

double EcmStatus::languageDecode(uint8_t value)  {
    return (double)(value);
}

double EcmStatus::audio_statusDecode(uint8_t value)  {
    return (double)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
void EcmStatus::serialize(ecmStatusStruct *message, uint8_t *payload) {
    memset(&payload[0], 0, 8);
    payload[0] |= packRightShiftU8(message->theme, 0, 0xff);
    payload[1] |= packRightShiftU8(message->language, 0, 0xff);
    payload[2] |= packRightShiftU8(message->audio_status, 0, 0xff);
}

EcmStatus::ecmStatusStruct EcmStatus::deserialize(uint8_t *data) {
    EcmStatus::ecmStatusStruct deserializedData;
    deserializedData.theme = unpackRightShiftU8(data[0], 0, 0xff);
    deserializedData.language = unpackRightShiftU8(data[1], 0, 0xff);
    deserializedData.audio_status = unpackRightShiftU8(data[2], 0, 0xff);

    return deserializedData;
}
