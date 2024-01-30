#include "statusSdm.h"

StatusSdm::StatusSdm() {}

/* SIGNALS
 * encode
 */
uint8_t StatusSdm::airBagFailStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::psngrBagStsEncode(double value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::fpsCommandEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::fpsFailStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR3RowDxSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR3RowSxSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR2RowDxSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR2RowCentralSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR2RowSxSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR1RowDxSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR1RowCentralSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR1RowSxSeatConfigStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR3RowDxSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR3RowSxSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR2RowDxSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR2RowCentralSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR2RowSxSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR1RowDxSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR1RowCentralSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::sBR1RowSxSeatStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputPedestrianStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputRolloverStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputRearStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputDriverSideStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputPsngrSideStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputFront2LevelStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputFront1LevelStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::crashOutputFrontPtStsEncode(bool value)  {
    return (uint8_t)(value);
}

uint8_t StatusSdm::fpsConfirmEncode(bool value)  {
    return (uint8_t)(value);
}

/* SIGNALS
 * decode
 */
double StatusSdm::airBagFailStsDecode(uint8_t value)  {
    return (double)(value);
}

double StatusSdm::psngrBagStsDecode(uint8_t value)  {
    return (double)(value);
}

bool StatusSdm::fpsCommandDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::fpsFailStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR3RowDxSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR3RowSxSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR2RowDxSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR2RowCentralSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR2RowSxSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR1RowDxSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR1RowCentralSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR1RowSxSeatConfigStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR3RowDxSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR3RowSxSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR2RowDxSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR2RowCentralSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR2RowSxSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR1RowDxSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR1RowCentralSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::sBR1RowSxSeatStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputPedestrianStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputRolloverStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputRearStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputDriverSideStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputPsngrSideStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputFront2LevelStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputFront1LevelStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::crashOutputFrontPtStsDecode(uint8_t value)  {
    return (bool)(value);
}

bool StatusSdm::fpsConfirmDecode(uint8_t value)  {
    return (bool)(value);
}

/* MESSAGE
 * serialize, deserialize
 */
uint8_t *StatusSdm::serialize(statusSdmStruct *message) {
}

StatusSdm::statusSdmStruct StatusSdm::deserialize(uint8_t *data) {
    StatusSdm::statusSdmStruct deserializedData;
    deserializedData.airBagFailSts = unpackRightShiftU8(data[0], 6, 0xc0);
    deserializedData.psngrBagSts = unpackRightShiftU8(data[0], 4, 0x30);
    deserializedData.fpsCommand = unpackRightShiftU8(data[0], 1, 0x2);
    deserializedData.fpsFailSts = unpackRightShiftU8(data[0], 0, 0x1);
    deserializedData.sBR3RowDxSeatConfigSts = unpackRightShiftU8(data[1], 7, 0x80);
    deserializedData.sBR3RowSxSeatConfigSts = unpackRightShiftU8(data[1], 6, 0x40);
    deserializedData.sBR2RowDxSeatConfigSts = unpackRightShiftU8(data[1], 5, 0x20);
    deserializedData.sBR2RowCentralSeatConfigSts = unpackRightShiftU8(data[1], 4, 0x10);
    deserializedData.sBR2RowSxSeatConfigSts = unpackRightShiftU8(data[1], 3, 0x8);
    deserializedData.sBR1RowDxSeatConfigSts = unpackRightShiftU8(data[1], 2, 0x4);
    deserializedData.sBR1RowCentralSeatConfigSts = unpackRightShiftU8(data[1], 1, 0x2);
    deserializedData.sBR1RowSxSeatConfigSts = unpackRightShiftU8(data[1], 0, 0x1);
    deserializedData.sBR3RowDxSeatSts = unpackRightShiftU8(data[2], 7, 0x80);
    deserializedData.sBR3RowSxSeatSts = unpackRightShiftU8(data[2], 6, 0x40);
    deserializedData.sBR2RowDxSeatSts = unpackRightShiftU8(data[2], 5, 0x20);
    deserializedData.sBR2RowCentralSeatSts = unpackRightShiftU8(data[2], 4, 0x10);
    deserializedData.sBR2RowSxSeatSts = unpackRightShiftU8(data[2], 3, 0x8);
    deserializedData.sBR1RowDxSeatSts = unpackRightShiftU8(data[2], 2, 0x4);
    deserializedData.sBR1RowCentralSeatSts = unpackRightShiftU8(data[2], 1, 0x2);
    deserializedData.sBR1RowSxSeatSts = unpackRightShiftU8(data[2], 0, 0x1);
    deserializedData.crashOutputPedestrianSts = unpackRightShiftU8(data[3], 7, 0x80);
    deserializedData.crashOutputRolloverSts = unpackRightShiftU8(data[3], 6, 0x40);
    deserializedData.crashOutputRearSts = unpackRightShiftU8(data[3], 5, 0x20);
    deserializedData.crashOutputDriverSideSts = unpackRightShiftU8(data[3], 4, 0x10);
    deserializedData.crashOutputPsngrSideSts = unpackRightShiftU8(data[3], 3, 0x8);
    deserializedData.crashOutputFront2LevelSts = unpackRightShiftU8(data[3], 2, 0x4);
    deserializedData.crashOutputFront1LevelSts = unpackRightShiftU8(data[3], 1, 0x2);
    deserializedData.crashOutputFrontPtSts = unpackRightShiftU8(data[3], 0, 0x1);
    deserializedData.fpsConfirm = unpackRightShiftU8(data[4], 7, 0x80);

    return deserializedData;
}