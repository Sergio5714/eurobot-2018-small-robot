#ifndef ROBOT_COMMANDS
#define ROBOT_COMMANDS

#include "Communication.h"
#include "Robot.h"

extern float wheelsSpeed[ROBOT_NUMBER_OF_MOTORS];
extern float robotTargetSpeedCs1[3];
extern float robotSpeedCs1[3];
extern float robotCoordCs1[3];
extern float robotCoordCsGlobal[3];
extern float accelerationMax[3];
extern Sorter_Manipulator_Typedef sorterManipulators[NUMBER_OF_SORTERS];

extern float shooterMotorSpeed;
extern Pid_Regulator_Struct_Typedef pidRegulator;
extern Chosen_Motor_Typedef chosenShooter;
extern uint32_t regulationStartTime;
extern uint32_t timeOfStart;
extern Range_Finders_Struct_Typedef rangeFinders;

enum
{
	ECHO                          = 0x01,
	
	SET_PWM                       = 0x03,
	SET_DIR_BIT                   = 0x04,
	CLEAR_DIR_BIT                 = 0x05,
	
	SET_ALL_MOTOR_SPEEDS          = 0x06,
	GET_ALL_WHEELS_SPEEDS         = 0x07,
	
	SET_SPEED_ROBOT_CS1           = 0x08,
	GET_SPEED_ROBOT_CS1           = 0x09,
	GET_COORD_ROBOT_CS1           = 0x0A,
	
	SET_ANGLE_DNMX                = 0x0B,
	GET_ANGLE_DNMX                = 0x0C,
	
	SET_COORD_ROBOT_CS_GLOBAL     = 0x0E,
	GET_COORD_ROBOT_CS_GLOBAL     = 0x0F,
	
	TURN_FORW_KIN_ON_OFF          = 0x0D,
	
	GET_ODOMETRY_MOVEMENT_STATUS  = 0xA0,
	GET_STARTUP_STATUS            = 0xA3,
	FORCED_START                  = 0xA4,
	
	MAKE_FUNNY_ACTION             = 0xB6,
	
	ODOMETRY_MOVEMENT             = 0xA2,
	
	GET_SORTER_STATUS             = 0xC0,
	MOVE_LATCH_OF_SORTER          = 0xC1,
	MOVE_HEAP_GRIPPER             = 0xC2,
	MOVE_BOTTOM_SORTER            = 0xC3,
	TURN_ON_AND_OFF_MOTORS        = 0xC4,
	GET_SHOOTER_MOTOR_SPEED       = 0xC5,
	
	GET_DATA_AND_STATUS_FROM_RF   = 0xD1,
	
	TURN_COLL_AVOID_ON_OFF        = 0xE0,
};

void checkCommandAndExecute(void);
#endif
