#ifndef STATUS_B_ECM2_H
#define STATUS_B_ECM2_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define STATUS_B_ECM2_FRAME_ID 69812225
#define STATUS_B_ECM2_NAME "STATUS_B_ECM2"
#define STATUS_B_ECM2_LENGTH 8
#define STATUS_B_ECM2_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define engineOilTemp_NAME "EngineOilTemp" 
#define boostPressureIndication_NAME "BoostPressureIndication" 
#define gearShiftIndication_NAME "GearShiftIndication" 
#define cNGGasolineMode_NAME "CNGGasolineMode" 
#define alternativeFuelFillingTank_NAME "AlternativeFuelFillingTank" 
#define stopStartSts_NAME "StopStartSts" 
#define engineStopStartSts_NAME "EngineStopStartSts" 
#define startRelayBCMFeedbackFault_NAME "StartRelayBCMFeedbackFault" 
#define startRelayECMFeedbackFault_NAME "StartRelayECMFeedbackFault" 
#define fuelModeDriverReqSts_NAME "FuelModeDriverReqSts" 
#define sAMInfo_NAME "SAMInfo" 

/* SIGNALS
 * choices
 */
#define STATUS_B_ECM2_engineOilTemp_Not_Valid_CHOICE (7u)
#define STATUS_B_ECM2_engineOilTemp_Sixth_Level_CHOICE (6u)
#define STATUS_B_ECM2_engineOilTemp_Fifth_Level_CHOICE (5u)
#define STATUS_B_ECM2_engineOilTemp_Fourth_Level_CHOICE (4u)
#define STATUS_B_ECM2_engineOilTemp_Third_Level	_CHOICE (3u)
#define STATUS_B_ECM2_engineOilTemp_Second_Level_CHOICE (2u)
#define STATUS_B_ECM2_engineOilTemp_Fisrt_Level_CHOICE (1u)
#define STATUS_B_ECM2_boostPressureIndication_Not_Valid_CHOICE (255u)
#define STATUS_B_ECM2_gearShiftIndication_Strategy_Not_Available_ECM_Fail_CHOICE (3u)
#define STATUS_B_ECM2_gearShiftIndication_Upshift_Suggestion_by_ECM_CHOICE (2u)
#define STATUS_B_ECM2_gearShiftIndication_Downshift_Suggestion_by_ECM_CHOICE (1u)
#define STATUS_B_ECM2_gearShiftIndication_No_Gearshift_Suggestion_by_ECM_CHOICE (0u)
#define STATUS_B_ECM2_cNGGasolineMode_CNG_CHOICE (1u)
#define STATUS_B_ECM2_cNGGasolineMode_Gasoline_CHOICE (0u)
#define STATUS_B_ECM2_alternativeFuelFillingTank_Not_Valid_CHOICE (127u)
#define STATUS_B_ECM2_stopStartSts_Safety_Disable_Request_CHOICE (3u)
#define STATUS_B_ECM2_stopStartSts_Functional_Disable_Request_CHOICE (2u)
#define STATUS_B_ECM2_stopStartSts_ON_CHOICE (1u)
#define STATUS_B_ECM2_stopStartSts_OFF_CHOICE (0u)
#define STATUS_B_ECM2_engineStopStartSts_Engine_Stopping_CHOICE (3u)
#define STATUS_B_ECM2_engineStopStartSts_Engine_Stall_CHOICE (2u)
#define STATUS_B_ECM2_engineStopStartSts_Engine_Not_in_Stop_CHOICE (1u)
#define STATUS_B_ECM2_engineStopStartSts_Engine_Stop_CHOICE (0u)
#define STATUS_B_ECM2_startRelayBCMFeedbackFault_True_CHOICE (1u)
#define STATUS_B_ECM2_startRelayBCMFeedbackFault_False_CHOICE (0u)
#define STATUS_B_ECM2_startRelayECMFeedbackFault_True_CHOICE (1u)
#define STATUS_B_ECM2_startRelayECMFeedbackFault_False_CHOICE (0u)
#define STATUS_B_ECM2_fuelModeDriverReqSts_OtherFuel_CHOICE (1u)
#define STATUS_B_ECM2_fuelModeDriverReqSts_Gasoline_CHOICE (0u)
#define STATUS_B_ECM2_sAMInfo_Not_Valid_CHOICE (15u)
#define STATUS_B_ECM2_sAMInfo_Battery_Regeneration_CHOICE (11u)
#define STATUS_B_ECM2_sAMInfo_SAM_recovery_CHOICE (10u)
#define STATUS_B_ECM2_sAMInfo_Shut_OFF_CHOICE (9u)
#define STATUS_B_ECM2_sAMInfo_Auto_Shut_OFF_CHOICE (8u)
#define STATUS_B_ECM2_sAMInfo_QuickCharge_CHOICE (7u)
#define STATUS_B_ECM2_sAMInfo_RegenerativeBraking_CHOICE (6u)
#define STATUS_B_ECM2_sAMInfo_Steady_State_CHOICE (5u)
#define STATUS_B_ECM2_sAMInfo_PassiveBoost_CHOICE (4u)
#define STATUS_B_ECM2_sAMInfo_ColdEngineManagement_CHOICE (3u)
#define STATUS_B_ECM2_sAMInfo_Cranking_management_CHOICE (2u)
#define STATUS_B_ECM2_sAMInfo_Engine_OFF_CHOICE (1u)
#define STATUS_B_ECM2_sAMInfo_SAMOFF_CHOICE (0u)

class StatusBEcm2 : public Serializer, public Deserializer
{
public:
    StatusBEcm2();
    typedef struct statusBEcm2Struct {
        uint8_t engineOilTemp;
        uint8_t boostPressureIndication;
        uint8_t gearShiftIndication;
        uint8_t cNGGasolineMode;
        uint8_t alternativeFuelFillingTank;
        uint8_t stopStartSts;
        uint8_t engineStopStartSts;
        uint8_t startRelayBCMFeedbackFault;
        uint8_t startRelayECMFeedbackFault;
        uint8_t fuelModeDriverReqSts;
        uint8_t sAMInfo;
    } statusBEcm2Struct;

    /* SIGNALS
    * encode
    */
    uint8_t engineOilTempEncode(double value);
    uint8_t boostPressureIndicationEncode(double value);
    uint8_t gearShiftIndicationEncode(double value);
    uint8_t cNGGasolineModeEncode(bool value);
    uint8_t alternativeFuelFillingTankEncode(double value);
    uint8_t stopStartStsEncode(double value);
    uint8_t engineStopStartStsEncode(double value);
    uint8_t startRelayBCMFeedbackFaultEncode(bool value);
    uint8_t startRelayECMFeedbackFaultEncode(bool value);
    uint8_t fuelModeDriverReqStsEncode(bool value);
    uint8_t sAMInfoEncode(double value);

    /* SIGNALS
    * decode
    */
    double engineOilTempDecode(uint8_t value);
    double boostPressureIndicationDecode(uint8_t value);
    double gearShiftIndicationDecode(uint8_t value);
    bool cNGGasolineModeDecode(uint8_t value);
    double alternativeFuelFillingTankDecode(uint8_t value);
    double stopStartStsDecode(uint8_t value);
    double engineStopStartStsDecode(uint8_t value);
    bool startRelayBCMFeedbackFaultDecode(uint8_t value);
    bool startRelayECMFeedbackFaultDecode(uint8_t value);
    bool fuelModeDriverReqStsDecode(uint8_t value);
    double sAMInfoDecode(uint8_t value);

    uint8_t *serialize(statusBEcm2Struct *payload);
    statusBEcm2Struct deserialize(uint8_t *data);
};

#endif