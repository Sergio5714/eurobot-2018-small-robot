#ifndef SHOOTER_MOTORS
#define SHOOTER_MOTORS

#include "Robot.h"
#include "stm32f407xx.h"
#include "Board.h"

#define PI_NUMBER                                  3.14159265358f

// Common robot parameters
#define ROBOT_NUMBER_OF_SHOOTER_MOTORS             0x02

//--------------------------------------------- Definitions for motors -----------------------------------------//
// Minimum and maximum speed of motor/wheel in rad/s 
#define SHOOTER_MOTORS_MAX_ROT_SPEED               30.0f
#define SHOOTER_MOTORS_MIN_ROT_SPEED               0.0f

// Parameters of motors
// Gear ratio
#define SHOOTER_MOTOR_GR                           1.0f

// Encoder's ticks per one rotation of initial shaft
#define SHOOTER_MOTOR_ENC_TICKS                    64

// Total number of ticks per one rotation
#define SHOOTER_MOTOR_TOTAL_TICKS                  SHOOTER_MOTOR_GR * SHOOTER_MOTOR_ENC_TICKS

// Ticks to rad coefficient 
#define SHOOTER_TICKS_TO_RAD_COEF                  2*PI_NUMBER / (SHOOTER_MOTOR_TOTAL_TICKS)

#define SHOOTER_MOTOR_SPEED_TO_SHOOT_FIRST         250
#define SHOOTER_MOTOR_SPEED_TO_SHOOT_DIRTY_FIRST   113

#define SHOOTER_MOTOR_SPEED_TO_SHOOT_SECOND        250
#define SHOOTER_MOTOR_SPEED_TO_SHOOT_DIRTY_SECOND  113

#define SHOOTER_MOTOR_SPEED_EPS                    30
#define SHOOTER_MOTOR_RESP_TIMEOUT_TENTH_OF_MILLIS 20000 // 2 sec

typedef enum
{
	CHOSEN_MOTOR_FIRST,
	CHOSEN_MOTOR_SECOND,
} Chosen_Motor_Typedef;

typedef enum
{
	CHOSEN_ENCODER_FIRST,
	CHOSEN_ENCODER_SECOND,
} Chosen_Encoder_Typedef;

typedef struct
{
	float pk; 
	float ik; 
	float dk; 
	float target; 
	float current; 
	float prevError; 
	float sumError; 
	float maxSumError; 
	float maxOutput;
	float minOutput;
	float output; 
	uint8_t pidOn;
	uint8_t pidFinish;
	float pidErrorEnd;
	float pidOutputEnd;
} Pid_Regulator_Struct_Typedef;

//--------------------------------------------- Common functions -----------------------------------------------//
void shooterReadEnc(void);
void shooterChooseEnc(Chosen_Encoder_Typedef encoderNumber);
void shooterSetDutyCycle(Chosen_Motor_Typedef motorNumber, float dutyCycle);

//--------------------------------------------- PID control ----------------------------------------------------//

// Init pid regulator
void pidInit(void);

// Calculate PID regulator
void pidCalc(Pid_Regulator_Struct_Typedef* pidRegulator);


#endif
