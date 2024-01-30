#ifndef STATUS_BCM2_H
#define STATUS_BCM2_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define STATUS_BCM2_FRAME_ID 103890944
#define STATUS_BCM2_NAME "STATUS_BCM2"
#define STATUS_BCM2_LENGTH 8
#define STATUS_BCM2_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define batteryLampSts_NAME "BatteryLampSts" 
#define powerModeSts_NAME "PowerModeSts" 
#define driveStyleSts_NAME "DriveStyleSts" 
#define stopStartVisualizationCode_NAME "StopStartVisualizationCode" 
#define stopStartActivationSts_NAME "StopStartActivationSts" 

/* SIGNALS
 * choices
 */
#define STATUS_BCM2_batteryLampSts_ON_Flashing_CHOICE (2u)
#define STATUS_BCM2_batteryLampSts_ON_Fixed_CHOICE (1u)
#define STATUS_BCM2_batteryLampSts_OFF_CHOICE (0u)
#define STATUS_BCM2_powerModeSts_Logistic_Mode_PR_CHOICE (2u)
#define STATUS_BCM2_powerModeSts_Logistic_Mode_ON_CHOICE (1u)
#define STATUS_BCM2_powerModeSts_Standard_Power_CHOICE (0u)
#define STATUS_BCM2_driveStyleSts_Not_Availabe_CHOICE (7u)
#define STATUS_BCM2_driveStyleSts_TracPlus_CHOICE (5u)
#define STATUS_BCM2_driveStyleSts_Eco_CHOICE (4u)
#define STATUS_BCM2_driveStyleSts_Winter_CHOICE (3u)
#define STATUS_BCM2_driveStyleSts_Sport_CHOICE (2u)
#define STATUS_BCM2_driveStyleSts_City_CHOICE (1u)
#define STATUS_BCM2_driveStyleSts_Normal_CHOICE (0u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_7_CHOICE (7u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_6_CHOICE (6u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_5_CHOICE (5u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_4_CHOICE (4u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_3_CHOICE (3u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_2_CHOICE (2u)
#define STATUS_BCM2_stopStartVisualizationCode_Code_1_CHOICE (1u)
#define STATUS_BCM2_stopStartVisualizationCode_No_Visualization_CHOICE (0u)
#define STATUS_BCM2_stopStartActivationSts_Deactivated_CHOICE (1u)
#define STATUS_BCM2_stopStartActivationSts_Activated_CHOICE (0u)

class StatusBcm2 : public Serializer, public Deserializer
{
public:
    StatusBcm2();
    typedef struct statusBcm2Struct {
        uint8_t batteryLampSts;
        uint8_t powerModeSts;
        uint8_t driveStyleSts;
        uint8_t stopStartVisualizationCode;
        uint8_t stopStartActivationSts;
    } statusBcm2Struct;

    /* SIGNALS
    * encode
    */
    uint8_t batteryLampStsEncode(double value);
    uint8_t powerModeStsEncode(double value);
    uint8_t driveStyleStsEncode(double value);
    uint8_t stopStartVisualizationCodeEncode(double value);
    uint8_t stopStartActivationStsEncode(double value);

    /* SIGNALS
    * decode
    */
    double batteryLampStsDecode(uint8_t value);
    double powerModeStsDecode(uint8_t value);
    double driveStyleStsDecode(uint8_t value);
    double stopStartVisualizationCodeDecode(uint8_t value);
    double stopStartActivationStsDecode(uint8_t value);

    uint8_t *serialize(statusBcm2Struct *payload);
    statusBcm2Struct deserialize(uint8_t *data);
};

#endif