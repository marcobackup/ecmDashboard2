#ifndef ENVIRONMENTAL_CONDITIONS_H
#define ENVIRONMENTAL_CONDITIONS_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define ENVIRONMENTAL_CONDITIONS_FRAME_ID 104677376
#define ENVIRONMENTAL_CONDITIONS_NAME "ENVIRONMENTAL_CONDITIONS"
#define ENVIRONMENTAL_CONDITIONS_LENGTH 4
#define ENVIRONMENTAL_CONDITIONS_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define externalTemperature_NAME "ExternalTemperature" 
#define externalTemperatureFailSts_NAME "ExternalTemperatureFailSts" 
#define batteryVoltageLevel_NAME "BatteryVoltageLevel" 
#define batteryChargeSts_NAME "BatteryChargeSts" 
#define currentFailStsIBS_NAME "CurrentFailStsIBS" 

/* SIGNALS
 * choices
 */
#define ENVIRONMENTAL_CONDITIONS_externalTemperature_No_Valid_Data_Available_CHOICE (0u)
#define ENVIRONMENTAL_CONDITIONS_externalTemperatureFailSts_Fail_Present_CHOICE (1u)
#define ENVIRONMENTAL_CONDITIONS_externalTemperatureFailSts_Fail_Not_Present_CHOICE (0u)
#define ENVIRONMENTAL_CONDITIONS_batteryChargeSts_No Information Available_CHOICE (15u)
#define ENVIRONMENTAL_CONDITIONS_currentFailStsIBS_At_Least_One_DTC_Present_IN_ECU_CHOICE (1u)
#define ENVIRONMENTAL_CONDITIONS_currentFailStsIBS_No_DTC_Present_In_ECU_CHOICE (0u)

class EnvironmentalConditions : public Serializer, public Deserializer
{
public:
    EnvironmentalConditions();
    typedef struct environmentalConditionsStruct {
        uint8_t externalTemperature;
        uint8_t externalTemperatureFailSts;
        uint8_t batteryVoltageLevel;
        uint8_t batteryChargeSts;
        uint8_t currentFailStsIBS;
    } environmentalConditionsStruct;

    /* SIGNALS
    * encode
    */
    uint8_t externalTemperatureEncode(double value);
    uint8_t externalTemperatureFailStsEncode(bool value);
    uint8_t batteryVoltageLevelEncode(double value);
    uint8_t batteryChargeStsEncode(double value);
    uint8_t currentFailStsIBSEncode(bool value);

    /* SIGNALS
    * decode
    */
    double externalTemperatureDecode(uint8_t value);
    bool externalTemperatureFailStsDecode(uint8_t value);
    double batteryVoltageLevelDecode(uint8_t value);
    double batteryChargeStsDecode(uint8_t value);
    bool currentFailStsIBSDecode(uint8_t value);

    uint8_t *serialize(environmentalConditionsStruct *payload);
    environmentalConditionsStruct deserialize(uint8_t *data);
};

#endif