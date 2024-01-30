#ifndef STATUS_SDM_H
#define STATUS_SDM_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define STATUS_SDM_FRAME_ID 102842394
#define STATUS_SDM_NAME "STATUS_SDM"
#define STATUS_SDM_LENGTH 8
#define STATUS_SDM_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define airBagFailSts_NAME "AirBagFailSts" 
#define psngrBagSts_NAME "PsngrBagSts" 
#define fpsCommand_NAME "FpsCommand" 
#define fpsFailSts_NAME "FpsFailSts" 
#define sBR3RowDxSeatConfigSts_NAME "SBR3RowDxSeatConfigSts" 
#define sBR3RowSxSeatConfigSts_NAME "SBR3RowSxSeatConfigSts" 
#define sBR2RowDxSeatConfigSts_NAME "SBR2RowDxSeatConfigSts" 
#define sBR2RowCentralSeatConfigSts_NAME "SBR2RowCentralSeatConfigSts" 
#define sBR2RowSxSeatConfigSts_NAME "SBR2RowSxSeatConfigSts" 
#define sBR1RowDxSeatConfigSts_NAME "SBR1RowDxSeatConfigSts" 
#define sBR1RowCentralSeatConfigSts_NAME "SBR1RowCentralSeatConfigSts" 
#define sBR1RowSxSeatConfigSts_NAME "SBR1RowSxSeatConfigSts" 
#define sBR3RowDxSeatSts_NAME "SBR3RowDxSeatSts" 
#define sBR3RowSxSeatSts_NAME "SBR3RowSxSeatSts" 
#define sBR2RowDxSeatSts_NAME "SBR2RowDxSeatSts" 
#define sBR2RowCentralSeatSts_NAME "SBR2RowCentralSeatSts" 
#define sBR2RowSxSeatSts_NAME "SBR2RowSxSeatSts" 
#define sBR1RowDxSeatSts_NAME "SBR1RowDxSeatSts" 
#define sBR1RowCentralSeatSts_NAME "SBR1RowCentralSeatSts" 
#define sBR1RowSxSeatSts_NAME "SBR1RowSxSeatSts" 
#define crashOutputPedestrianSts_NAME "CrashOutputPedestrianSts" 
#define crashOutputRolloverSts_NAME "CrashOutputRolloverSts" 
#define crashOutputRearSts_NAME "CrashOutputRearSts" 
#define crashOutputDriverSideSts_NAME "CrashOutputDriverSideSts" 
#define crashOutputPsngrSideSts_NAME "CrashOutputPsngrSideSts" 
#define crashOutputFront2LevelSts_NAME "CrashOutputFront2LevelSts" 
#define crashOutputFront1LevelSts_NAME "CrashOutputFront1LevelSts" 
#define crashOutputFrontPtSts_NAME "CrashOutputFrontPtSts" 
#define fpsConfirm_NAME "FpsConfirm" 

/* SIGNALS
 * choices
 */
#define STATUS_SDM_airBagFailSts_Fail_Present_Lamp_ON_CHOICE (2u)
#define STATUS_SDM_airBagFailSts_Fail_Not_Present_Lamp_Flashing_CHOICE (1u)
#define STATUS_SDM_airBagFailSts_Fail_Not_Present_Lamp_OFF_CHOICE (0u)
#define STATUS_SDM_psngrBagSts_PassengerBagNotActive_Lamp_ON_CHOICE (2u)
#define STATUS_SDM_psngrBagSts_PassengerBagActive_Lamp_Flashing_CHOICE (1u)
#define STATUS_SDM_psngrBagSts_PassengerBagActive_Lamp_OFF_CHOICE (0u)
#define STATUS_SDM_fpsCommand_Actuate_CHOICE (1u)
#define STATUS_SDM_fpsCommand_Do_Not_Actuate_CHOICE (0u)
#define STATUS_SDM_fpsFailSts_Fail_Present_CHOICE (1u)
#define STATUS_SDM_fpsFailSts_Fail_Not_Present_CHOICE (0u)
#define STATUS_SDM_sBR3RowDxSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR3RowDxSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR3RowSxSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR3RowSxSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR2RowDxSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR2RowDxSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR2RowCentralSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR2RowCentralSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR2RowSxSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR2RowSxSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR1RowDxSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR1RowDxSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR1RowCentralSeatConfigSts_Seat Checked_CHOICE (1u)
#define STATUS_SDM_sBR1RowCentralSeatConfigSts_Seat Not Checked_CHOICE (0u)
#define STATUS_SDM_sBR1RowSxSeatConfigSts_Seat_Checked_CHOICE (1u)
#define STATUS_SDM_sBR1RowSxSeatConfigSts_Seat_Not_Checked_CHOICE (0u)
#define STATUS_SDM_sBR3RowDxSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR3RowDxSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR3RowSxSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR3RowSxSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR2RowDxSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR2RowDxSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR2RowCentralSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR2RowCentralSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR2RowSxSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR2RowSxSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR1RowDxSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR1RowDxSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR1RowCentralSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR1RowCentralSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_sBR1RowSxSeatSts_Seat Belt Not Fasten_CHOICE (1u)
#define STATUS_SDM_sBR1RowSxSeatSts_Seat Belt Fasten_CHOICE (0u)
#define STATUS_SDM_crashOutputPedestrianSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputPedestrianSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputRolloverSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputRolloverSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputRearSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputRearSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputDriverSideSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputDriverSideSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputPsngrSideSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputPsngrSideSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputFront2LevelSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputFront2LevelSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputFront1LevelSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputFront1LevelSts_No Crash_CHOICE (0u)
#define STATUS_SDM_crashOutputFrontPtSts_Crash_CHOICE (1u)
#define STATUS_SDM_crashOutputFrontPtSts_No Crash_CHOICE (0u)
#define STATUS_SDM_fpsConfirm_Do_Not_Actuate_CHOICE (1u)
#define STATUS_SDM_fpsConfirm_Actuate_CHOICE (0u)

class StatusSdm : public Serializer, public Deserializer
{
public:
    StatusSdm();
    typedef struct statusSdmStruct {
        uint8_t airBagFailSts;
        uint8_t psngrBagSts;
        uint8_t fpsCommand;
        uint8_t fpsFailSts;
        uint8_t sBR3RowDxSeatConfigSts;
        uint8_t sBR3RowSxSeatConfigSts;
        uint8_t sBR2RowDxSeatConfigSts;
        uint8_t sBR2RowCentralSeatConfigSts;
        uint8_t sBR2RowSxSeatConfigSts;
        uint8_t sBR1RowDxSeatConfigSts;
        uint8_t sBR1RowCentralSeatConfigSts;
        uint8_t sBR1RowSxSeatConfigSts;
        uint8_t sBR3RowDxSeatSts;
        uint8_t sBR3RowSxSeatSts;
        uint8_t sBR2RowDxSeatSts;
        uint8_t sBR2RowCentralSeatSts;
        uint8_t sBR2RowSxSeatSts;
        uint8_t sBR1RowDxSeatSts;
        uint8_t sBR1RowCentralSeatSts;
        uint8_t sBR1RowSxSeatSts;
        uint8_t crashOutputPedestrianSts;
        uint8_t crashOutputRolloverSts;
        uint8_t crashOutputRearSts;
        uint8_t crashOutputDriverSideSts;
        uint8_t crashOutputPsngrSideSts;
        uint8_t crashOutputFront2LevelSts;
        uint8_t crashOutputFront1LevelSts;
        uint8_t crashOutputFrontPtSts;
        uint8_t fpsConfirm;
    } statusSdmStruct;

    /* SIGNALS
    * encode
    */
    uint8_t airBagFailStsEncode(double value);
    uint8_t psngrBagStsEncode(double value);
    uint8_t fpsCommandEncode(bool value);
    uint8_t fpsFailStsEncode(bool value);
    uint8_t sBR3RowDxSeatConfigStsEncode(bool value);
    uint8_t sBR3RowSxSeatConfigStsEncode(bool value);
    uint8_t sBR2RowDxSeatConfigStsEncode(bool value);
    uint8_t sBR2RowCentralSeatConfigStsEncode(bool value);
    uint8_t sBR2RowSxSeatConfigStsEncode(bool value);
    uint8_t sBR1RowDxSeatConfigStsEncode(bool value);
    uint8_t sBR1RowCentralSeatConfigStsEncode(bool value);
    uint8_t sBR1RowSxSeatConfigStsEncode(bool value);
    uint8_t sBR3RowDxSeatStsEncode(bool value);
    uint8_t sBR3RowSxSeatStsEncode(bool value);
    uint8_t sBR2RowDxSeatStsEncode(bool value);
    uint8_t sBR2RowCentralSeatStsEncode(bool value);
    uint8_t sBR2RowSxSeatStsEncode(bool value);
    uint8_t sBR1RowDxSeatStsEncode(bool value);
    uint8_t sBR1RowCentralSeatStsEncode(bool value);
    uint8_t sBR1RowSxSeatStsEncode(bool value);
    uint8_t crashOutputPedestrianStsEncode(bool value);
    uint8_t crashOutputRolloverStsEncode(bool value);
    uint8_t crashOutputRearStsEncode(bool value);
    uint8_t crashOutputDriverSideStsEncode(bool value);
    uint8_t crashOutputPsngrSideStsEncode(bool value);
    uint8_t crashOutputFront2LevelStsEncode(bool value);
    uint8_t crashOutputFront1LevelStsEncode(bool value);
    uint8_t crashOutputFrontPtStsEncode(bool value);
    uint8_t fpsConfirmEncode(bool value);

    /* SIGNALS
    * decode
    */
    double airBagFailStsDecode(uint8_t value);
    double psngrBagStsDecode(uint8_t value);
    bool fpsCommandDecode(uint8_t value);
    bool fpsFailStsDecode(uint8_t value);
    bool sBR3RowDxSeatConfigStsDecode(uint8_t value);
    bool sBR3RowSxSeatConfigStsDecode(uint8_t value);
    bool sBR2RowDxSeatConfigStsDecode(uint8_t value);
    bool sBR2RowCentralSeatConfigStsDecode(uint8_t value);
    bool sBR2RowSxSeatConfigStsDecode(uint8_t value);
    bool sBR1RowDxSeatConfigStsDecode(uint8_t value);
    bool sBR1RowCentralSeatConfigStsDecode(uint8_t value);
    bool sBR1RowSxSeatConfigStsDecode(uint8_t value);
    bool sBR3RowDxSeatStsDecode(uint8_t value);
    bool sBR3RowSxSeatStsDecode(uint8_t value);
    bool sBR2RowDxSeatStsDecode(uint8_t value);
    bool sBR2RowCentralSeatStsDecode(uint8_t value);
    bool sBR2RowSxSeatStsDecode(uint8_t value);
    bool sBR1RowDxSeatStsDecode(uint8_t value);
    bool sBR1RowCentralSeatStsDecode(uint8_t value);
    bool sBR1RowSxSeatStsDecode(uint8_t value);
    bool crashOutputPedestrianStsDecode(uint8_t value);
    bool crashOutputRolloverStsDecode(uint8_t value);
    bool crashOutputRearStsDecode(uint8_t value);
    bool crashOutputDriverSideStsDecode(uint8_t value);
    bool crashOutputPsngrSideStsDecode(uint8_t value);
    bool crashOutputFront2LevelStsDecode(uint8_t value);
    bool crashOutputFront1LevelStsDecode(uint8_t value);
    bool crashOutputFrontPtStsDecode(uint8_t value);
    bool fpsConfirmDecode(uint8_t value);

    uint8_t *serialize(statusSdmStruct *payload);
    statusSdmStruct deserialize(uint8_t *data);
};

#endif