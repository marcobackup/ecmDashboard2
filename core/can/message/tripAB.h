#ifndef TRIP_A_B_H
#define TRIP_A_B_H
#include <cstdint>
#include "core/can/serializer.h"
#include "core/can/deserializer.h"

/* MESSAGE INFORMATION
 * frame_id, length, is_extended
 */
#define TRIP_A_B_FRAME_ID 201408515
#define TRIP_A_B_NAME "TRIP_A_B"
#define TRIP_A_B_LENGTH 8
#define TRIP_A_B_IS_EXTENDED 1

/* SIGNALS
 * names
 */
#define istantaneusFuelConsumption1_NAME "IstantaneusFuelConsumption1" 
#define istantaneusFuelConsumption2_NAME "IstantaneusFuelConsumption2" 
#define istantaneusFuelConsumption3_NAME "IstantaneusFuelConsumption3" 
#define totalOdometer_NAME "TotalOdometer" 
#define istantFuelConsumptionValidData_NAME "IstantFuelConsumptionValidData" 
#define autonomyDistanceValidData_NAME "AutonomyDistanceValidData" 
#define autonomyDistance_NAME "AutonomyDistance" 

/* SIGNALS
 * choices
 */
#define TRIP_A_B_istantFuelConsumptionValidData_Not_Valid_CHOICE (1u)
#define TRIP_A_B_istantFuelConsumptionValidData_Valid_CHOICE (0u)
#define TRIP_A_B_autonomyDistanceValidData_Not_Valid_CHOICE (1u)
#define TRIP_A_B_autonomyDistanceValidData_Valid_CHOICE (0u)

class TripAB : public Serializer, public Deserializer
{
public:
    TripAB();
    typedef struct tripABStruct {
        uint8_t istantaneusFuelConsumption1;
        uint8_t istantaneusFuelConsumption2;
        uint8_t istantaneusFuelConsumption3;
        uint32_t totalOdometer;
        uint8_t istantFuelConsumptionValidData;
        uint8_t autonomyDistanceValidData;
        uint16_t autonomyDistance;
    } tripABStruct;

    /* SIGNALS
    * encode
    */
    uint8_t istantaneusFuelConsumption1Encode(double value);
    uint8_t istantaneusFuelConsumption2Encode(double value);
    uint8_t istantaneusFuelConsumption3Encode(double value);
    uint32_t totalOdometerEncode(double value);
    uint8_t istantFuelConsumptionValidDataEncode(bool value);
    uint8_t autonomyDistanceValidDataEncode(bool value);
    uint16_t autonomyDistanceEncode(double value);

    /* SIGNALS
    * decode
    */
    double istantaneusFuelConsumption1Decode(uint8_t value);
    double istantaneusFuelConsumption2Decode(uint8_t value);
    double istantaneusFuelConsumption3Decode(uint8_t value);
    double totalOdometerDecode(uint32_t value);
    bool istantFuelConsumptionValidDataDecode(uint8_t value);
    bool autonomyDistanceValidDataDecode(uint8_t value);
    double autonomyDistanceDecode(uint16_t value);

    uint8_t *serialize(tripABStruct *payload);
    tripABStruct deserialize(uint8_t *data);
};

#endif