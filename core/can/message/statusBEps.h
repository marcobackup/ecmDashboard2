#ifndef STATUS_B_EPS_H
#define STATUS_B_EPS_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define STATUS_B_EPS_FRAME_ID 69287938
#define STATUS_B_EPS_NAME "STATUS_B_EPS"
#define STATUS_B_EPS_LENGTH 2
#define STATUS_B_EPS_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define electricSteeringFailSts_NAME "ElectricSteeringFailSts" 

/* SIGNALS
 * choices
 */
#define STATUS_B_EPS_electricSteeringFailSts_Fail_Present_CHOICE (1u)
#define STATUS_B_EPS_electricSteeringFailSts_Fail_Not_Present_CHOICE (0u)

class StatusBEps : public Serializer, public Deserializer
{
public:
    StatusBEps();
    typedef struct statusBEpsStruct {
        uint8_t electricSteeringFailSts;
    } statusBEpsStruct;

    /* SIGNALS
    * encode
    */
    uint8_t electricSteeringFailStsEncode(bool value);

    /* SIGNALS
    * decode
    */
    bool electricSteeringFailStsDecode(uint8_t value);

    uint8_t *serialize(statusBEpsStruct *payload);
    statusBEpsStruct deserialize(uint8_t *data);
};

#endif