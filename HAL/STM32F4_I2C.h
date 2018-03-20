#ifndef STM32F4_I2C
 #define STM32F4_I2C
 
#include "stm32f4xx.h"

// Typedef for mode of I2C message
typedef enum
{
	I2C_MODE_WRITE,
	I2C_MODE_READ,
} I2C_MODE;

// Typedef for I2C module status
typedef enum
{
	I2C_ACTIVE_MODE,
	I2C_ACKNOWLEDGE_ERROR,
	I2C_TIMEOUT_ERROR,
	I2C_ARBITRATION_LOST_ERROR,
	I2C_BUS_ERROR,
} I2C_Status_Typedef;


// Typedef for I2C module with state
typedef struct
{
	I2C_TypeDef* module;
	I2C_Status_Typedef status;
} I2C_Module_With_State_Typedef;

#define I2C_ADDRESS(addr, mode) ((addr<<1)| mode)

// Timeout 
#define NUMBER_OF_TICKS_TIMEOUT 4000 // Approximately 1 millisecond

//--------------------------------------------- Initialization and reset -------------------------------------//

// Initialization of I2C
void I2CInit(I2C_Module_With_State_Typedef* I2Cx);

// Enable of I2C
void I2CEnable(I2C_TypeDef* I2Cx);

// Disable I2C
void I2CDisable(I2C_TypeDef* I2Cx);

// Reset I2C bus
void I2CReset(I2C_Module_With_State_Typedef* I2Cx);

// Check I2C bus
void I2CCheckBus(I2C_Module_With_State_Typedef* I2Cx);

//--------------------------------------------- Inner functions ----------------------------------------------//

// Generate stop conditions
static void I2CStop(I2C_TypeDef* I2Cx);

// Set acknowledgement bit
static void I2CSetAck(I2C_TypeDef* I2Cx);

// Clear acknowledgement bit
static void I2CUnSetAck(I2C_TypeDef* I2Cx);

// Clear adress sent flag
static void I2CClearAddrFlag(I2C_TypeDef* I2Cx);

// Set POS flag
static void I2CSetPOS(I2C_TypeDef* I2Cx);

// Clear POS flag
static void I2CUnSetPOS(I2C_TypeDef* I2Cx);

// Read data register DR
void I2CReadDR(I2C_TypeDef* I2Cx, uint8_t *byte);

//--------------------------------------------- Inner functions that require status --------------------------//

// Generate start conditions
I2C_Status_Typedef I2CStart(I2C_Module_With_State_Typedef* I2Cx);

// Send adress byte with read or write mode
I2C_Status_Typedef I2CSendAddr(I2C_Module_With_State_Typedef* I2Cx, uint8_t Addr, I2C_MODE Mode);

// Wait for one byte to be received
I2C_Status_Typedef I2CWaitForByte(I2C_Module_With_State_Typedef* I2Cx);

// Wait for byte transfer finished event
I2C_Status_Typedef I2CWaitForBTF(I2C_Module_With_State_Typedef* I2Cx);

// Wait for stop flag to be cleared
I2C_Status_Typedef I2CWaitForStopToBeCleared(I2C_Module_With_State_Typedef* I2Cx);

// Wait for busy line
I2C_Status_Typedef I2CWaitBusyLine(I2C_Module_With_State_Typedef* I2Cx);

//--------------------------------------------- High level functions -----------------------------------------//
// Send predefined number of bytes
ErrorStatus I2CSendBytes(I2C_Module_With_State_Typedef* I2Cx, uint8_t* bytesArray, uint32_t numberOfBytes, uint8_t SlaveAddr);

// Read predefined number of bytes
ErrorStatus I2CReadBytes(I2C_Module_With_State_Typedef* I2Cx, uint8_t* buffer, uint32_t numberOfBytesToBeRead, uint8_t SlaveAddr);

// Search I2C devices on bus
void I2CSearch(I2C_Module_With_State_Typedef* I2Cx);


#endif