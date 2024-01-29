#ifndef EXTERNAL_LIGHTS_H
#define EXTERNAL_LIGHTS_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define EXTERNAL_LIGHTS_FRAME_ID 35733504
#define EXTERNAL_LIGHTS_NAME "EXTERNAL_LIGHTS"
#define EXTERNAL_LIGHTS_LENGTH 6
#define EXTERNAL_LIGHTS_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define lHParkTailLightSts_NAME "LHParkTailLightSts" 
#define highBeamSts_NAME "HighBeamSts" 
#define lowBeamSts_NAME "LowBeamSts" 
#define fogLightSts_NAME "FogLightSts" 
#define rearFogLightSts_NAME "RearFogLightSts" 
#define lHTurnSignalSts_NAME "LHTurnSignalSts" 
#define rHTurnSignalSts_NAME "RHTurnSignalSts" 
#define rHeatedWindowSts_NAME "RHeatedWindowSts" 
#define rHFTurnLightFailSts_NAME "RHFTurnLightFailSts" 
#define lHFTurnLightFailSts_NAME "LHFTurnLightFailSts" 
#define lHStopLightFailSts_NAME "LHStopLightFailSts" 
#define lHRearFogLightFailSts_NAME "LHRearFogLightFailSts" 
#define rHFParkTailLightFailSts_NAME "RHFParkTailLightFailSts" 
#define lHFParkTailLightFailSts_NAME "LHFParkTailLightFailSts" 
#define plateLightFailSts_NAME "PlateLightFailSts" 
#define dRLFault_NAME "DRLFault" 

/* SIGNALS
 * choices
 */
#define EXTERNAL_LIGHTS_lHParkTailLightSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_lHParkTailLightSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_highBeamSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_highBeamSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_lowBeamSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_lowBeamSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_fogLightSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_fogLightSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_rearFogLightSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_rearFogLightSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_lHTurnSignalSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_lHTurnSignalSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_rHTurnSignalSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_rHTurnSignalSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_rHeatedWindowSts_ON_CHOICE (1u)
#define EXTERNAL_LIGHTS_rHeatedWindowSts_OFF_CHOICE (0u)
#define EXTERNAL_LIGHTS_rHFTurnLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_rHFTurnLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_lHFTurnLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_lHFTurnLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_lHStopLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_lHStopLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_lHRearFogLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_lHRearFogLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_rHFParkTailLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_rHFParkTailLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_lHFParkTailLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_lHFParkTailLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_plateLightFailSts_Fail_Present_CHOICE (1u)
#define EXTERNAL_LIGHTS_plateLightFailSts_Fail_Not_Present_CHOICE (0u)
#define EXTERNAL_LIGHTS_dRLFault_True_CHOICE (1u)
#define EXTERNAL_LIGHTS_dRLFault_False_CHOICE (0u)

class ExternalLights : public Serializer, public Deserializer
{
public:
    ExternalLights();
    typedef struct externalLightsStruct {
        uint8_t lHParkTailLightSts;
        uint8_t highBeamSts;
        uint8_t lowBeamSts;
        uint8_t fogLightSts;
        uint8_t rearFogLightSts;
        uint8_t lHTurnSignalSts;
        uint8_t rHTurnSignalSts;
        uint8_t rHeatedWindowSts;
        uint8_t rHFTurnLightFailSts;
        uint8_t lHFTurnLightFailSts;
        uint8_t lHStopLightFailSts;
        uint8_t lHRearFogLightFailSts;
        uint8_t rHFParkTailLightFailSts;
        uint8_t lHFParkTailLightFailSts;
        uint8_t plateLightFailSts;
        uint8_t dRLFault;
    } externalLightsStruct;

    /* SIGNALS
    * encode
    */
    uint8_t lHParkTailLightStsEncode(bool value);
    uint8_t highBeamStsEncode(bool value);
    uint8_t lowBeamStsEncode(bool value);
    uint8_t fogLightStsEncode(bool value);
    uint8_t rearFogLightStsEncode(bool value);
    uint8_t lHTurnSignalStsEncode(bool value);
    uint8_t rHTurnSignalStsEncode(bool value);
    uint8_t rHeatedWindowStsEncode(bool value);
    uint8_t rHFTurnLightFailStsEncode(bool value);
    uint8_t lHFTurnLightFailStsEncode(bool value);
    uint8_t lHStopLightFailStsEncode(bool value);
    uint8_t lHRearFogLightFailStsEncode(bool value);
    uint8_t rHFParkTailLightFailStsEncode(bool value);
    uint8_t lHFParkTailLightFailStsEncode(bool value);
    uint8_t plateLightFailStsEncode(bool value);
    uint8_t dRLFaultEncode(bool value);

    /* SIGNALS
    * decode
    */
    bool lHParkTailLightStsDecode(uint8_t value);
    bool highBeamStsDecode(uint8_t value);
    bool lowBeamStsDecode(uint8_t value);
    bool fogLightStsDecode(uint8_t value);
    bool rearFogLightStsDecode(uint8_t value);
    bool lHTurnSignalStsDecode(uint8_t value);
    bool rHTurnSignalStsDecode(uint8_t value);
    bool rHeatedWindowStsDecode(uint8_t value);
    bool rHFTurnLightFailStsDecode(uint8_t value);
    bool lHFTurnLightFailStsDecode(uint8_t value);
    bool lHStopLightFailStsDecode(uint8_t value);
    bool lHRearFogLightFailStsDecode(uint8_t value);
    bool rHFParkTailLightFailStsDecode(uint8_t value);
    bool lHFParkTailLightFailStsDecode(uint8_t value);
    bool plateLightFailStsDecode(uint8_t value);
    bool dRLFaultDecode(uint8_t value);

    uint8_t *serialize(externalLightsStruct *payload);
    externalLightsStruct deserialize(uint8_t *data);
};

#endif