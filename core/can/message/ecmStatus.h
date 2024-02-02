#ifndef ECM_STATUS_H
#define ECM_STATUS_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define ECM_STATUS_FRAME_ID 169279489
#define ECM_STATUS_NAME "ECM_STATUS"
#define ECM_STATUS_LENGTH 3
#define ECM_STATUS_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define theme_NAME "theme" 
#define language_NAME "language" 
#define audio_status_NAME "audio_status" 

/* SIGNALS
 * choices
 */
#define ECM_STATUS_theme_silver theme_CHOICE (3u)
#define ECM_STATUS_theme_gold theme_CHOICE (2u)
#define ECM_STATUS_theme_darkblue theme_CHOICE (1u)
#define ECM_STATUS_theme_darkred theme_CHOICE (0u)
#define ECM_STATUS_language_french_CHOICE (4u)
#define ECM_STATUS_language_spanish_CHOICE (3u)
#define ECM_STATUS_language_english_uk_CHOICE (2u)
#define ECM_STATUS_language_english_us_CHOICE (1u)
#define ECM_STATUS_language_italian_CHOICE (0u)
#define ECM_STATUS_audio_status_ON_CHOICE (1u)
#define ECM_STATUS_audio_status_OFF_CHOICE (0u)

class EcmStatus : public Serializer, public Deserializer
{
public:
    EcmStatus();
    typedef struct ecmStatusStruct {
        uint8_t theme;
        uint8_t language;
        uint8_t audio_status;
    } ecmStatusStruct;

    /* SIGNALS
    * encode
    */
    uint8_t themeEncode(double value);
    uint8_t languageEncode(double value);
    uint8_t audio_statusEncode(double value);

    /* SIGNALS
    * decode
    */
    double themeDecode(uint8_t value);
    double languageDecode(uint8_t value);
    double audio_statusDecode(uint8_t value);

    void serialize(ecmStatusStruct *payload, uint8_t *);
    ecmStatusStruct deserialize(uint8_t *data);
};

#endif
