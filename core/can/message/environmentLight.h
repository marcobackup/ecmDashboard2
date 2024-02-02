#ifndef ENVIRONMENT_LIGHT_H
#define ENVIRONMENT_LIGHT_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define ENVIRONMENT_LIGHT_FRAME_ID 169279490
#define ENVIRONMENT_LIGHT_NAME "ENVIRONMENT_LIGHT"
#define ENVIRONMENT_LIGHT_LENGTH 3
#define ENVIRONMENT_LIGHT_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define left_light_level_NAME "left_light_level" 
#define left_light_source_NAME "left_light_source" 
#define right_light_source_NAME "right_light_source" 
#define right_light_level_NAME "right_light_level" 

/* SIGNALS
 * choices
 */
#define ENVIRONMENT_LIGHT_left_light_source_user_CHOICE (1u)
#define ENVIRONMENT_LIGHT_left_light_source_car_fade_CHOICE (0u)
#define ENVIRONMENT_LIGHT_right_light_source_user_CHOICE (1u)
#define ENVIRONMENT_LIGHT_right_light_source_car_fade_CHOICE (0u)

class EnvironmentLight : public Serializer, public Deserializer
{
public:
    EnvironmentLight();
    typedef struct environmentLightStruct {
        uint8_t left_light_level;
        uint8_t left_light_source;
        uint8_t right_light_source;
        uint8_t right_light_level;
    } environmentLightStruct;

    /* SIGNALS
    * encode
    */
    uint8_t left_light_levelEncode(double value);
    uint8_t left_light_sourceEncode(double value);
    uint8_t right_light_sourceEncode(double value);
    uint8_t right_light_levelEncode(double value);

    /* SIGNALS
    * decode
    */
    double left_light_levelDecode(uint8_t value);
    double left_light_sourceDecode(uint8_t value);
    double right_light_sourceDecode(uint8_t value);
    double right_light_levelDecode(uint8_t value);

    uint8_t *serialize(environmentLightStruct *payload);
    environmentLightStruct deserialize(uint8_t *data);
};

#endif