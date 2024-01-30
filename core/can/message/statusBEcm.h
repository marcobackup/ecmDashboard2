#ifndef STATUS_B_ECM_H
#define STATUS_B_ECM_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define STATUS_B_ECM_FRAME_ID 69287937
#define STATUS_B_ECM_NAME "STATUS_B_ECM"
#define STATUS_B_ECM_LENGTH 8
#define STATUS_B_ECM_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define gPLGasolineMode_NAME "GPLGasolineMode" 
#define cNGGasolineMode_NAME "CNGGasolineMode" 
#define oilPressureSts_NAME "OilPressureSts" 
#define oilPressureFailSts_NAME "OilPressureFailSts" 
#define fuelWaterPresentSts_NAME "FuelWaterPresentSts" 
#define glowPlugLampSts_NAME "GlowPlugLampSts" 
#define glowPlugFailSts_NAME "GlowPlugFailSts" 
#define fuelWaterPresentFailSts_NAME "FuelWaterPresentFailSts" 
#define cruiseControlLampSts_NAME "CruiseControlLampSts" 
#define compressorSts_NAME "CompressorSts" 
#define eMSFailSts_NAME "EMSFailSts" 
#define engineWaterTempFailSts_NAME "EngineWaterTempFailSts" 
#define fpsActuated_NAME "FpsActuated" 
#define engineWaterTempWarningLightSts_NAME "EngineWaterTempWarningLightSts"
#define engineWaterTemp_NAME "EngineWaterTemp"
//#define fuelConsumption_NAME "FuelConsumption"
#define fuelConsumption_NAME "FuelConsumption" 
#define engineSpeed_NAME "EngineSpeed" 
#define dPFSts_NAME "DPFSts" 
#define fuelConsumptionValidData_NAME "FuelConsumptionValidData" 
#define engineSpeedValidData_NAME "EngineSpeedValidData" 
#define oilLevelSts_NAME "OilLevelSts" 
#define reverseGearSts_NAME "ReverseGearSts" 
#define oilLifeSts_NAME "OilLifeSts" 

/* SIGNALS
 * choices
 */
#define STATUS_B_ECM_gPLGasolineMode_GPL_CHOICE (1u)
#define STATUS_B_ECM_gPLGasolineMode_Gasoline_CHOICE (0u)
#define STATUS_B_ECM_cNGGasolineMode_CNG_CHOICE (1u)
#define STATUS_B_ECM_cNGGasolineMode_Gasoline_CHOICE (0u)
#define STATUS_B_ECM_oilPressureSts_Low_Pressure_CHOICE (1u)
#define STATUS_B_ECM_oilPressureSts_Normal_Pressure_CHOICE (0u)
#define STATUS_B_ECM_oilPressureFailSts_Fail_Present_CHOICE (1u)
#define STATUS_B_ECM_oilPressureFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_B_ECM_fuelWaterPresentSts_Water_Present_CHOICE (1u)
#define STATUS_B_ECM_fuelWaterPresentSts_Water_Not_Present_CHOICE (0u)
#define STATUS_B_ECM_glowPlugLampSts_ON_CHOICE (1u)
#define STATUS_B_ECM_glowPlugLampSts_OFF_CHOICE (0u)
#define STATUS_B_ECM_glowPlugFailSts_Fail_Present_CHOICE (1u)
#define STATUS_B_ECM_glowPlugFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_B_ECM_fuelWaterPresentFailSts_Fail_Present_CHOICE (1u)
#define STATUS_B_ECM_fuelWaterPresentFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_B_ECM_cruiseControlLampSts_Inserted_CHOICE (1u)
#define STATUS_B_ECM_cruiseControlLampSts_Not_inserted_CHOICE (0u)
#define STATUS_B_ECM_compressorSts_Inserted_CHOICE (3u)
#define STATUS_B_ECM_compressorSts_Not_inserted_by_driv_secur_CHOICE (2u)
#define STATUS_B_ECM_compressorSts_Not_inserted_by_ECM_CHOICE (1u)
#define STATUS_B_ECM_eMSFailSts_Fail_EOL_Procedure_Not_Completed_CHOICE (3u)
#define STATUS_B_ECM_eMSFailSts_Fail_Fix_Light_Indication_CHOICE (2u)
#define STATUS_B_ECM_eMSFailSts_Fail_Flash_Light_Indication_CHOICE (1u)
#define STATUS_B_ECM_eMSFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_B_ECM_engineWaterTempFailSts_Fail_Present_CHOICE (1u)
#define STATUS_B_ECM_engineWaterTempFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_B_ECM_fpsActuated_Actuated_CHOICE (1u)
#define STATUS_B_ECM_fpsActuated_Not_Actuated_CHOICE (0u)
#define STATUS_B_ECM_engineWaterTempWarningLightSts_ON_CHOICE (1u)
#define STATUS_B_ECM_engineWaterTempWarningLightSts_OFF_CHOICE (0u)
#define STATUS_B_ECM_dPFSts_Dirty_CHOICE (1u)
#define STATUS_B_ECM_dPFSts_Clean_CHOICE (0u)
#define STATUS_B_ECM_fuelConsumptionValidData_Not_valid_CHOICE (1u)
#define STATUS_B_ECM_fuelConsumptionValidData_Valid_CHOICE (0u)
#define STATUS_B_ECM_engineSpeedValidData_Not_valid_CHOICE (1u)
#define STATUS_B_ECM_engineSpeedValidData_Valid_CHOICE (0u)
#define STATUS_B_ECM_oilLevelSts_LowLevel_CHOICE (1u)
#define STATUS_B_ECM_oilLevelSts_NormalLevel_CHOICE (0u)
#define STATUS_B_ECM_reverseGearSts_Inserted_CHOICE (1u)
#define STATUS_B_ECM_reverseGearSts_Not_Inserted_CHOICE (0u)
#define STATUS_B_ECM_oilLifeSts_Change_Oil_Required_CHOICE (2u)
#define STATUS_B_ECM_oilLifeSts_Oil_Life_Reset_CHOICE (1u)
#define STATUS_B_ECM_oilLifeSts_Normal_Oil_Properties_CHOICE (0u)

class StatusBEcm : public Serializer, public Deserializer
{
public:
    StatusBEcm();
    typedef struct statusBEcmStruct {
        uint8_t gPLGasolineMode;
        uint8_t cNGGasolineMode;
        uint8_t oilPressureSts;
        uint8_t oilPressureFailSts;
        uint8_t fuelWaterPresentSts;
        uint8_t glowPlugLampSts;
        uint8_t glowPlugFailSts;
        uint8_t fuelWaterPresentFailSts;
        uint8_t cruiseControlLampSts;
        uint8_t compressorSts;
        uint8_t eMSFailSts;
        uint8_t engineWaterTempFailSts;
        uint8_t fpsActuated;
        uint8_t engineWaterTempWarningLightSts;
        uint8_t engineWaterTemp;
        //uint16_t fuelConsumption;
        uint16_t fuelConsumption;
        uint8_t engineSpeed;
        uint8_t dPFSts;
        uint8_t fuelConsumptionValidData;
        uint8_t engineSpeedValidData;
        uint8_t oilLevelSts;
        uint8_t reverseGearSts;
        uint8_t oilLifeSts;
    } statusBEcmStruct;

    /* SIGNALS
    * encode
    */
    uint8_t gPLGasolineModeEncode(bool value);
    uint8_t cNGGasolineModeEncode(bool value);
    uint8_t oilPressureStsEncode(bool value);
    uint8_t oilPressureFailStsEncode(bool value);
    uint8_t fuelWaterPresentStsEncode(bool value);
    uint8_t glowPlugLampStsEncode(bool value);
    uint8_t glowPlugFailStsEncode(bool value);
    uint8_t fuelWaterPresentFailStsEncode(bool value);
    uint8_t cruiseControlLampStsEncode(bool value);
    uint8_t compressorStsEncode(double value);
    uint8_t eMSFailStsEncode(double value);
    uint8_t engineWaterTempFailStsEncode(bool value);
    uint8_t fpsActuatedEncode(bool value);
    uint8_t engineWaterTempWarningLightStsEncode(bool value);
    uint8_t engineWaterTempEncode(double value);
    //uint16_t fuelConsumptionEncode(double value);
    uint16_t fuelConsumptionEncode(double value);
    uint8_t engineSpeedEncode(double value);
    uint8_t dPFStsEncode(bool value);
    uint8_t fuelConsumptionValidDataEncode(bool value);
    uint8_t engineSpeedValidDataEncode(bool value);
    uint8_t oilLevelStsEncode(bool value);
    uint8_t reverseGearStsEncode(bool value);
    uint8_t oilLifeStsEncode(double value);

    /* SIGNALS
    * decode
    */
    bool gPLGasolineModeDecode(uint8_t value);
    bool cNGGasolineModeDecode(uint8_t value);
    bool oilPressureStsDecode(uint8_t value);
    bool oilPressureFailStsDecode(uint8_t value);
    bool fuelWaterPresentStsDecode(uint8_t value);
    bool glowPlugLampStsDecode(uint8_t value);
    bool glowPlugFailStsDecode(uint8_t value);
    bool fuelWaterPresentFailStsDecode(uint8_t value);
    bool cruiseControlLampStsDecode(uint8_t value);
    double compressorStsDecode(uint8_t value);
    double eMSFailStsDecode(uint8_t value);
    bool engineWaterTempFailStsDecode(uint8_t value);
    bool fpsActuatedDecode(uint8_t value);
    bool engineWaterTempWarningLightStsDecode(uint8_t value);
    double engineWaterTempDecode(uint8_t value);
    //double fuelConsumptionDecode(uint16_t value);
    double fuelConsumptionDecode(uint16_t value);
    double engineSpeedDecode(uint8_t value);
    bool dPFStsDecode(uint8_t value);
    bool fuelConsumptionValidDataDecode(uint8_t value);
    bool engineSpeedValidDataDecode(uint8_t value);
    bool oilLevelStsDecode(uint8_t value);
    bool reverseGearStsDecode(uint8_t value);
    double oilLifeStsDecode(uint8_t value);

    uint8_t *serialize(statusBEcmStruct *payload);
    statusBEcmStruct deserialize(uint8_t *data);
};

#endif
