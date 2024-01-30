#ifndef STATUS_BCM_H
#define STATUS_BCM_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define STATUS_BCM_FRAME_ID 102842368
#define STATUS_BCM_NAME "STATUS_BCM"
#define STATUS_BCM_LENGTH 8
#define STATUS_BCM_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define brakePadWearSts_NAME "BrakePadWearSts" 
#define brakeFluidLevelSts_NAME "BrakeFluidLevelSts" 
#define handBrakeSts_NAME "HandBrakeSts" 
#define internalLightSts_NAME "InternalLightSts" 
#define sysEOLSts_NAME "SysEOLSts" 
#define bonnetSts_NAME "BonnetSts" 
#define rHatchSts_NAME "RHatchSts" 
#define rHRDoorSts_NAME "RHRDoorSts" 
#define lHRDoorSts_NAME "LHRDoorSts" 
#define psngrDoorSts_NAME "PsngrDoorSts" 
#define driverDoorSts_NAME "DriverDoorSts" 
#define keySts_NAME "KeySts" 
#define rechargeSts_NAME "RechargeSts" 
#define lowFuelWarningSts_NAME "LowFuelWarningSts" 
#define fuelLevelFailSts_NAME "FuelLevelFailSts" 
#define fuelLevel_NAME "FuelLevel" 
#define fpsNotAvailable_NAME "FpsNotAvailable" 
#define iMMOCodeWarningLightSts_NAME "IMMOCodeWarningLightSts" 
#define rainSensorFailSts_NAME "RainSensorFailSts" 
#define cityModeSts_NAME "CityModeSts" 

/* SIGNALS
 * choices
 */
#define STATUS_BCM_brakePadWearSts_NOT_OK_CHOICE (1u)
#define STATUS_BCM_brakePadWearSts_OK_CHOICE (0u)
#define STATUS_BCM_brakeFluidLevelSts_Low_level_CHOICE (1u)
#define STATUS_BCM_brakeFluidLevelSts_OK_CHOICE (0u)
#define STATUS_BCM_handBrakeSts_ON_CHOICE (1u)
#define STATUS_BCM_handBrakeSts_OFF_CHOICE (0u)
#define STATUS_BCM_internalLightSts_Active_CHOICE (1u)
#define STATUS_BCM_internalLightSts_Not_Active_CHOICE (0u)
#define STATUS_BCM_sysEOLSts_EOL_Not_Ready_CHOICE (1u)
#define STATUS_BCM_sysEOLSts_EOL_Ready_CHOICE (0u)
#define STATUS_BCM_bonnetSts_Open_CHOICE (1u)
#define STATUS_BCM_bonnetSts_Closed_CHOICE (0u)
#define STATUS_BCM_rHatchSts_Open_CHOICE (1u)
#define STATUS_BCM_rHatchSts_Closed_CHOICE (0u)
#define STATUS_BCM_rHRDoorSts_Open_CHOICE (1u)
#define STATUS_BCM_rHRDoorSts_Closed_CHOICE (0u)
#define STATUS_BCM_lHRDoorSts_Open_CHOICE (1u)
#define STATUS_BCM_lHRDoorSts_Closed_CHOICE (0u)
#define STATUS_BCM_psngrDoorSts_Open_CHOICE (1u)
#define STATUS_BCM_psngrDoorSts_Closed_CHOICE (0u)
#define STATUS_BCM_driverDoorSts_Open_CHOICE (1u)
#define STATUS_BCM_driverDoorSts_Closed_CHOICE (0u)
#define STATUS_BCM_keySts_Crank_On_CHOICE (12u)
#define STATUS_BCM_keySts_Pw_On_CHOICE (4u)
#define STATUS_BCM_keySts_Park_CHOICE (2u)
#define STATUS_BCM_keySts_Stop_CHOICE (1u)
#define STATUS_BCM_rechargeSts_Not_Charging_CHOICE (1u)
#define STATUS_BCM_rechargeSts_Charging_CHOICE (0u)
#define STATUS_BCM_lowFuelWarningSts_ON_CHOICE (1u)
#define STATUS_BCM_lowFuelWarningSts_OFF_CHOICE (0u)
#define STATUS_BCM_fuelLevelFailSts_Fail_Present_CHOICE (1u)
#define STATUS_BCM_fuelLevelFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_BCM_fpsNotAvailable_FPS_Not_Available_CHOICE (1u)
#define STATUS_BCM_fpsNotAvailable_FPS_Available_CHOICE (0u)
#define STATUS_BCM_rainSensorFailSts_Fail_present_CHOICE (1u)
#define STATUS_BCM_rainSensorFailSts_Fail_not_present_CHOICE (0u)
#define STATUS_BCM_cityModeSts_City_CHOICE (1u)
#define STATUS_BCM_cityModeSts_Normal_CHOICE (0u)

class StatusBcm : public Serializer, public Deserializer
{
public:
    StatusBcm();
    typedef struct statusBcmStruct {
        uint8_t brakePadWearSts;
        uint8_t brakeFluidLevelSts;
        uint8_t handBrakeSts;
        uint8_t internalLightSts;
        uint8_t sysEOLSts;
        uint8_t bonnetSts;
        uint8_t rHatchSts;
        uint8_t rHRDoorSts;
        uint8_t lHRDoorSts;
        uint8_t psngrDoorSts;
        uint8_t driverDoorSts;
        uint8_t keySts;
        uint8_t rechargeSts;
        uint8_t lowFuelWarningSts;
        uint8_t fuelLevelFailSts;
        uint8_t fuelLevel;
        uint8_t fpsNotAvailable;
        uint8_t iMMOCodeWarningLightSts;
        uint8_t rainSensorFailSts;
        uint8_t cityModeSts;
    } statusBcmStruct;

    /* SIGNALS
    * encode
    */
    uint8_t brakePadWearStsEncode(bool value);
    uint8_t brakeFluidLevelStsEncode(bool value);
    uint8_t handBrakeStsEncode(bool value);
    uint8_t internalLightStsEncode(bool value);
    uint8_t sysEOLStsEncode(bool value);
    uint8_t bonnetStsEncode(bool value);
    uint8_t rHatchStsEncode(bool value);
    uint8_t rHRDoorStsEncode(bool value);
    uint8_t lHRDoorStsEncode(bool value);
    uint8_t psngrDoorStsEncode(bool value);
    uint8_t driverDoorStsEncode(bool value);
    uint8_t keyStsEncode(double value);
    uint8_t rechargeStsEncode(bool value);
    uint8_t lowFuelWarningStsEncode(bool value);
    uint8_t fuelLevelFailStsEncode(bool value);
    uint8_t fuelLevelEncode(double value);
    uint8_t fpsNotAvailableEncode(bool value);
    uint8_t iMMOCodeWarningLightStsEncode(double value);
    uint8_t rainSensorFailStsEncode(bool value);
    uint8_t cityModeStsEncode(bool value);

    /* SIGNALS
    * decode
    */
    bool brakePadWearStsDecode(uint8_t value);
    bool brakeFluidLevelStsDecode(uint8_t value);
    bool handBrakeStsDecode(uint8_t value);
    bool internalLightStsDecode(uint8_t value);
    bool sysEOLStsDecode(uint8_t value);
    bool bonnetStsDecode(uint8_t value);
    bool rHatchStsDecode(uint8_t value);
    bool rHRDoorStsDecode(uint8_t value);
    bool lHRDoorStsDecode(uint8_t value);
    bool psngrDoorStsDecode(uint8_t value);
    bool driverDoorStsDecode(uint8_t value);
    double keyStsDecode(uint8_t value);
    bool rechargeStsDecode(uint8_t value);
    bool lowFuelWarningStsDecode(uint8_t value);
    bool fuelLevelFailStsDecode(uint8_t value);
    double fuelLevelDecode(uint8_t value);
    bool fpsNotAvailableDecode(uint8_t value);
    double iMMOCodeWarningLightStsDecode(uint8_t value);
    bool rainSensorFailStsDecode(uint8_t value);
    bool cityModeStsDecode(uint8_t value);

    uint8_t *serialize(statusBcmStruct *payload);
    statusBcmStruct deserialize(uint8_t *data);
};

#endif