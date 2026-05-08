//**************************************************************************************************
/*!
@file       ItfBoardCenUnjoBcParamCtrl.h
@brief      Unjo Param HW & SIM Access
@created    15.07.2023         HYDAC/BSC
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENUNJOBCPARAMCTRL__
  #define __ITFBOARDCENUNJOBCPARAMCTRL__

#include <autoconfig.h>
#ifdef COMPILER_SWITCH_FAM_UNJO

//--------------------------------------------------------------------------------------------------
// INVERTER API
//--------------------------------------------------------------------------------------------------
typedef enum
{
    API_INV_CON_STATUS_OK,                              //!< Motor command successfully completed
    API_INV_CONSTATUS_ALREADY_OPENED,                   //!< Session is already open
    API_INV_CON_STATUS_NOT_OPENED,                      //!< Session has not been opened
    API_INV_CON_STATUS_BUSY,                            //!< Motor command is pending
    API_INV_CON_STATUS_MODE_NOT_SET,                    //!< Motor control mode not specified
    API_INV_CON_STATUS_VALUE_TOO_HIGH,                  //!< Value being set is too high
    API_INV_CON_STATUS_VALUE_TOO_LOW,                   //!< Value being set is too low
    API_INV_CON_STATUS_FREEZE_FRAME_FIFO_EMPTY,
    API_INV_CON_STATUS_NOT_SUPPORTED,
    API_INV_CON_STATUS_UNKNOWN,                         //!< Other error
    API_INV_CON_STATUS_NOT_IMPLEMENTED,
    API_INV_CON_STATUS_REJECTED,
    API_INV_CON_STATUS_SHUTDOWN_DELAYED,
} EInvConApiStatus;

typedef enum
{
    API_INV_CON_INDUCTION_MOTOR,                        //!< Indicating use of induction motor
    API_INV_CON_PM_MOTOR,                               //!< Indicating use of SM-PMSM/I-PMSM
} EInvConApiMotorType;

typedef enum
{
    API_INV_CON_ASC_IDLE,                               //!< Active short circuit is not active
    API_INV_CON_ASC_ACTIVE                              //!< Active short circuit is active
} EInvConApiActiveShortCircuitStatus;

typedef enum
{
    API_INV_CON_POWER_STAGE_ENABLE,                     //!< Send power stage enable command
    API_INV_CON_POWER_STAGE_DISABLE,                    //!< Send power stage disable command
} EInvConApiPowerStageCommand;

typedef enum
{
    API_PARAM_STATUS_OK,                                //!< Everything is fine */
    API_PARAM_STATUS_PARAMETER_NOT_FOUND,               //!< Parameter with specified index, subindex not found
    API_PARAM_STATUS_WRONG_TYPE,                        //!< Parameter with specified index, subindex is of wrong data type
    API_PARAM_STATUS_OUT_OF_BOUNDS,                     //!< Parameter value is outsized of min/max values for this parameter
    API_PARAM_STATUS_CONDITION_NOT_MET,                 //!< Condition(s) for setting value are not met
    API_PARAM_STATUS_INVALID_DST_POINTER,               //!< Invalid destination pointer
    API_PARAM_STATUS_ERROR,                             //!< General Error
} EParamApiStatus;

typedef enum
{
    API_SERVICE_STATUS_OK,                              //!< Everything is fine
    API_SERVICE_STATUS_INVALID_ID,                      //!< Undefined service routine
    API_SERVICE_STATUS_ALREADY_STARTED,                 //!< A service routine is already ongoing
    API_SERVICE_STATUS_NOT_STARTED,                     //!< Service routine has not been started
    API_SERVICE_STATUS_NOT_SUPPORTED,                   //!< Valid ID, but currently not supported
    API_SERVICE_STATUS_NULL_POINTER,                    //!< A NULL pointer has been passed
} EServiceApiStatus;

typedef enum
{
    ROUTINE_SERVICE_NONE,
    ROUTINE_SERVICE_OFFSET_ALIGNMENT,
    ROUTINE_SERVICE_CHANGE_MOTOR_DATA_SET,
    ROUTINE_SERVICE_NUM_OF_ROUTINES,
} EServiceId;

typedef enum
{
    ROUTINE_SERVICE_RESULT_NOT_STARTED,                 //!< Service routine has not been started
    ROUTINE_SERVICE_RESULT_ONGOING,                     //!< Service routine is currently being executed
    ROUTINE_SERVICE_RESULT_COMPLETED,                   //!< Service routine has been successfully completed
    ROUTINE_SERVICE_RESULT_ABORTED,                     //!< Service routine was stopped before completed
    ROUTINE_SERVICE_RESULT_NOT_SUPPORTED,               //!< Service routine is currently not supported
    ROUTINE_SERVICE_RESULT_CONDITIONS_NOT_CORRECT,      //!< Service routine cannot be started
    ROUTINE_SERVICE_RESULT_GENERAL_ERROR,               //!< Service routine ended unsuccessfully
} EServiceRoutineResult;

typedef struct
{
    TUint8  u8Major;
    TUint8  u8Minor;
    TUint8  u8Prel;
    TUint16 u16BuildNumber;
    TChar*  pchBuildString;
} ESystemApiSwVersion;

typedef enum
{
    API_SYSTEM_STATUS_OK,
    API_SYSTEM_STATUS_ERROR_DRIVE_STATE,                //!< Operation blocked by drive state
    API_SYSTEM_STATUS_ERROR_INVALID_SW_COMP,            //!< Invalid software component
    API_SYSTEM_STATUS_STARTUP_NOT_COMPLETED             //!< System is currently booting up
} ESystemApiStatus;

typedef enum
{
    API_SYSTEM_SW_VERSION_BA = 1,
    API_SYSTEM_SW_VERSION_BC,
    API_SYSTEM_SW_VERSION_BD,
    API_SYSTEM_SW_NUM_COMP
} ESystemApiSwComponent;

typedef struct
{
    TUint16  u16ErrorNo;
    TFloat32 f32SpeedActual;
    TFloat32 f32TorqueActual;
    TFloat32 f32CurrentAcActual;
    TFloat32 f32VoltageDcActual;
    TFloat32 f32TemperatureIgbtJunction;
} TErrorInformation;

//--------------------------------------------------------------------------------------------------
// GET structs
//--------------------------------------------------------------------------------------------------

//! Get active error registers
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint32                                     u32ErrorRegister;           //!< Output argument
}TUnjoSimInvConApiGetActiveErrors;

TUnjoSimInvConApiGetActiveErrors                        g_tInvConApiGetActiveErrors;

//! Get active warning registers
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint32                                     u32WarningRegister;         //!< Output argument
}TUnjoSimInvConApiGetActiveWarnings;

TUnjoSimInvConApiGetActiveWarnings                      g_tInvConApiGetActiveWarnings;

// Readout the instantaneous value of the phase current rms
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentAc;               //!< Output argument
}TUnjoSimInvConApiGetCurrentAcActual;

TUnjoSimInvConApiGetCurrentAcActual                     g_tInvConApiGetCurrentAcActual;

// Get the phase current in d-axis
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentD;                //!< Output argument
}TUnjoSimInvConApiGetCurrentDActual;

TUnjoSimInvConApiGetCurrentDActual                      g_tInvConApiGetCurrentDActual;

// Readout the calculated DC current
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentDc;               //!< Output argument
}TUnjoSimInvConApiGetCurrentDcActual;

TUnjoSimInvConApiGetCurrentDcActual                     g_tInvConApiGetCurrentDcActual;

// Readout the phase current in q-axis
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentQ;                //!< Output argument
}TUnjoSimInvConApiGetCurrentQActual;

TUnjoSimInvConApiGetCurrentQActual                      g_tInvConApiGetCurrentQActual;

// Read out phase current limit as a result of the power stage derating
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentLimitPwrStage;    //!< Output argument
}TUnjoSimInvConApiGetCurrentLimitPwrStage;

TUnjoSimInvConApiGetCurrentLimitPwrStage                g_tInvConApiGetCurrentLimitPwrStage;

// Read out phase current (squareroot(d^2 + q^2)) set value as output of the torque controller and MTPA curve
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentSetValue;         //!< Output argument
}TUnjoSimInvConApiGetCurrentSetValue;

TUnjoSimInvConApiGetCurrentSetValue                     g_tInvConApiGetCurrentSetValue;

// Get phase current (squareroot(d^2 + q^2)) set value after current limitation block
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentPostLimit;        //!< Output argument
}TUnjoSimInvConApiGetCurrentPostLimit;

TUnjoSimInvConApiGetCurrentPostLimit                    g_tInvConApiGetCurrentPostLimit;

// Get the frequency set value for V/f control
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32FrequencyPostRamp;       //!< Output argument
}TUnjoSimInvConApiGetFrequencyPostRamp;

TUnjoSimInvConApiGetFrequencyPostRamp                   g_tInvConApiGetFrequencyPostRamp;

// Get the hwc max current
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32HwcMaxCurrent;           //!< Output argument
}TUnjoSimInvConApiGetHwcMaxCurrent;

TUnjoSimInvConApiGetHwcMaxCurrent                       g_tInvConApiGetHwcMaxCurrent;

// Get the hwc max frequency
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32HwcMaxFrequency;         //!< Output argument
}TUnjoSimInvConApiGetHwcMaxFrequency;

TUnjoSimInvConApiGetHwcMaxFrequency                     g_tInvConApiGetHwcMaxFrequency;

// Get the hwc max torque, using motor-data MTPA, according to max possible phase current in hwc
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32HwcMaxTorque;            //!< Output argument
}TUnjoSimInvConApiGetHwcMaxTorque;

TUnjoSimInvConApiGetHwcMaxTorque                        g_tInvConApiGetHwcMaxTorque;

// Get freeze frame of the last error occured
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TErrorInformation                           tFreezeFrame;               //!< Output argument
}TUnjoSimInvConApiGetFreezeFrame;

TUnjoSimInvConApiGetFreezeFrame                         g_tInvConApiGetFreezeFrame;

// Get stored angle offset value in the currently used motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32MdAngleOffset;           //!< Output argument
}TUnjoSimInvConApiGetMdAngleOffset;

TUnjoSimInvConApiGetMdAngleOffset                       g_tInvConApiGetMdAngleOffset;

// Get CRC of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint16                                     u16MotorDataSetCrc;         //!< Output argument
}TUnjoSimInvConApiGetMotorDataSetCrc;

TUnjoSimInvConApiGetMotorDataSetCrc                     g_tInvConApiGetMotorDataSetCrc;

// Get motor ID of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint16                                     u16MdMotorId;               //!< Output argument
}TUnjoSimInvConApiGetMdMotorId;

TUnjoSimInvConApiGetMdMotorId                           g_tInvConApiGetMdMotorId;

// Get motor type of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    EInvConApiMotorType                         eMdMotorType;               //!< Output argument
}TUnjoSimInvConApiGetMdMotorType;

TUnjoSimInvConApiGetMdMotorType                         g_tInvConApiGetMdMotorType;

// Get version of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint16                                     u16MotorDataSetVersion;     //!< Output argument
}TUnjoSimInvConApiGetMotorDataSetVersion;

TUnjoSimInvConApiGetMotorDataSetVersion                 g_tInvConApiGetMotorDataSetVersion;

// Get rated torque of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32MdRatedTorque;           //!< Output argument
}TUnjoSimInvConApiGetMdRatedTorque;

TUnjoSimInvConApiGetMdRatedTorque                       g_tInvConApiGetMdRatedTorque;

// Get max current allowed of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32MdMaxCurrent;            //!< Output argument
}TUnjoSimInvConApiGetMdMaxCurrent;

TUnjoSimInvConApiGetMdMaxCurrent                        g_tInvConApiGetMdMaxCurrent;

// Get max torque of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32MdMaxTorque;             //!< Output argument
}TUnjoSimInvConApiGetMdMaxTorque;

TUnjoSimInvConApiGetMdMaxTorque                         g_tInvConApiGetMdMaxTorque;

// Get max speed of the motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32MdMaxSpeed;              //!< Output argument
}TUnjoSimInvConApiGetMdMaxSpeed;

TUnjoSimInvConApiGetMdMaxSpeed                          g_tInvConApiGetMdMaxSpeed;

//  Get the the ratio of controller output voltage over max possible sinusoidal voltage value
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32ModulationIndex;         //!< Output argument
}TUnjoSimInvConApiGetModulationIndex;

TUnjoSimInvConApiGetModulationIndex                     g_tInvConApiGetModulationIndex;

// Get the the currently active motor data set
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint8                                      u8MotorDataSetNumber;       //!< Output argument
}TUnjoSimInvConApiGetMotorDataSetNumber;

TUnjoSimInvConApiGetMotorDataSetNumber                  g_tInvConApiGetMotorDataSetNumber;

// Get the actual PWM frequency
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32PwmFrequency;            //!< Output argument
}TUnjoSimInvConApiGetPwmFrequency;

TUnjoSimInvConApiGetPwmFrequency                        g_tInvConApiGetPwmFrequency;

// Readout the current speed of motor
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32SpeedActual;             //!< Output argument
}TUnjoSimInvConApiGetSpeedActual;

TUnjoSimInvConApiGetSpeedActual                         g_tInvConApiGetSpeedActual;

// Get speed set value output of speed limit block
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32SpeedPostLimit;          //!< Output argument
}TUnjoSimInvConApiGetSpeedPostLimit;

TUnjoSimInvConApiGetSpeedPostLimit                      g_tInvConApiGetSpeedPostLimit;

// Get the speed set value output of speed ramp generator
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32SpeedPostRamp;           //!< Output argument
}TUnjoSimInvConApiGetSpeedPostRamp;

TUnjoSimInvConApiGetSpeedPostRamp                       g_tInvConApiGetSpeedPostRamp;

//! Read status register
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint32                                     u32StatusRegister;          //!< Output argument
}TUnjoSimInvConApiGetStatusRegister;

TUnjoSimInvConApiGetStatusRegister                      g_tInvConApiGetStatusRegister;

// Get the IGBT junction temperature from BD
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TempPwrStageJunction;    //!< Output argument
}TUnjoSimInvConApiGetTempPwrStageJunction;

TUnjoSimInvConApiGetTempPwrStageJunction                g_tInvConApiGetTempPwrStageJunction;

// Get the calculated applied torque value
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorqueActual;            //!< Output argument
}TUnjoSimInvConApiGetTorqueActual;

TUnjoSimInvConApiGetTorqueActual                        g_tInvConApiGetTorqueActual;

// Get the positive torque limit due to the machine characteristic, speed and dc link voltage
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorquePosLimitMc;        //!< Output argument
}TUnjoSimInvConApiGetTorquePosLimitMc;

TUnjoSimInvConApiGetTorquePosLimitMc                    g_tInvConApiGetTorquePosLimitMc;

// Get the negative torque limit due to the machine characteristic, speed and dc link voltage
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorqueNegLimitMc;        //!< Output argument
}TUnjoSimInvConApiGetTorqueNegLimitMc;

TUnjoSimInvConApiGetTorqueNegLimitMc                    g_tInvConApiGetTorqueNegLimitMc;

// Get the torque limit if inverter is in torque control, voltage control mode or current control mode
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorquePosLimitSpeed;     //!< Output argument
}TUnjoSimInvConApiGetTorquePosLimitSpeed;

TUnjoSimInvConApiGetTorquePosLimitSpeed                 g_tInvConApiGetTorquePosLimitSpeed;

// Get the limitation of the torque due to overvoltage protection
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorqueOvLimitVoltage;    //!< Output argument
}TUnjoSimInvConApiGetTorqueOvLimitVoltage;

TUnjoSimInvConApiGetTorqueOvLimitVoltage                g_tInvConApiGetTorqueOvLimitVoltage;

// Get the limitation of the torque due to undervoltage protection
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorqueUvLimitVoltage;    //!< Output argument
}TUnjoSimInvConApiGetTorqueUvLimitVoltage;

TUnjoSimInvConApiGetTorqueUvLimitVoltage                g_tInvConApiGetTorqueUvLimitVoltage;

// Get the torque limit value output of torque limit block
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorquePostLimit;         //!< Output argument
}TUnjoSimInvConApiGetTorquePostLimit;

TUnjoSimInvConApiGetTorquePostLimit                     g_tInvConApiGetTorquePostLimit;

// Get the torque ramp value output of torque ramp generator
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorquePostRamp;          //!< Output argument
}TUnjoSimInvConApiGetTorquePostRamp;

TUnjoSimInvConApiGetTorquePostRamp                      g_tInvConApiGetTorquePostRamp;

// Get the torque current limit value output of torque current generator
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorquePostCurrentLimit;  //!< Output argument
}TUnjoSimInvConApiGetTorquePostCurrentLimit;

TUnjoSimInvConApiGetTorquePostCurrentLimit              g_tInvConApiGetTorquePostCurrentLimit;

// Get the torque set value
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32TorqueSetValue;          //!< Output argument
}TUnjoSimInvConApiGetTorqueSetValue;

TUnjoSimInvConApiGetTorqueSetValue                      g_tInvConApiGetTorqueSetValue;

// Get the instantaneous motor rms voltage (phase to phase)
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32VoltageAcActual;         //!< Output argument
}TUnjoSimInvConApiGetVoltageAcActual;

TUnjoSimInvConApiGetVoltageAcActual                     g_tInvConApiGetVoltageAcActual;

// Get the actual motor voltage in d axis
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32VoltageDActual;          //!< Output argument
}TUnjoSimInvConApiGetVoltageDActual;

TUnjoSimInvConApiGetVoltageDActual                      g_tInvConApiGetVoltageDActual;

// Get the actual motor voltage in q axis
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32VoltageQActual;          //!< Output argument
}TUnjoSimInvConApiGetVoltageQActual;

TUnjoSimInvConApiGetVoltageQActual                      g_tInvConApiGetVoltageQActual;

// Get status of inv_con_api
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
}TUnjoSimInvConApiGetStatus;

TUnjoSimInvConApiGetStatus                              g_tInvConApiGetStatus;

//--------------------------------------------------------------------------------------------------
// SET structs
//--------------------------------------------------------------------------------------------------

// Current control set value for d-axis
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentD;                //!< Input argument
}TUnjoSimInvConApiSetCurrentD;

TUnjoSimInvConApiSetCurrentD                            g_tInvConApiSetCurrentD;

// Current control set value for q-axis
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32CurrentQ;                //!< Input argument
}TUnjoSimInvConApiSetCurrentQ;

TUnjoSimInvConApiSetCurrentQ                            g_tInvConApiSetCurrentQ;

// Set Frequency for V/f control (target for ramp)
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32Frequency;               //!< Input argument
}TUnjoSimInvConApiSetFrequency;

TUnjoSimInvConApiSetFrequency                           g_tInvConApiSetFrequency;

// Requests the permanent active short circuit
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    EInvConApiActiveShortCircuitStatus          eCommand;                   //!< Input argument
}TUnjoSimInvConApiSetPermActiveShortCircuit;

TUnjoSimInvConApiSetPermActiveShortCircuit              g_tInvConApiSetPermActiveShortCircuit;

// Set the feed forward torque for speed controller
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32SpeedFeedforward;        //!< Input argument
}TUnjoSimInvConApiSetSpeedFeedforward;

TUnjoSimInvConApiSetSpeedFeedforward                    g_tInvConApiSetSpeedFeedforward;

// Set new state for drive power stage
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    EInvConApiPowerStageCommand                 eCommand;                   //!< Input argument
}TUnjoSimInvConApiSetPowerStage;

TUnjoSimInvConApiSetPowerStage                          g_tInvConApiSetPowerStage;

// Set the target speed of the motor
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32Speed;                   //!< Input argument
}TUnjoSimInvConApiSetSpeed;

TUnjoSimInvConApiSetSpeed                               g_tInvConApiSetSpeed;

// Set torque controller
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32Torque;                  //!< Input argument
}TUnjoSimInvConApiSetTorque;

TUnjoSimInvConApiSetTorque                              g_tInvConApiSetTorque;

// Set boost voltage for V/f control
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32VfBoost;                 //!< Input argument
}TUnjoSimInvConApiSetVfBoost;

TUnjoSimInvConApiSetVfBoost                             g_tInvConApiSetVfBoost;

// Set value for voltage controller
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32VoltageDc;               //!< Input argument
}TUnjoSimInvConApiSetVoltageDc;

TUnjoSimInvConApiSetVoltageDc                           g_tInvConApiSetVoltageDc;

// Set the feed forward torque for voltage controller
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32VoltageDcFeedforward;    //!< Input argument
}TUnjoSimInvConApiSetVoltageDcFeedforward;

TUnjoSimInvConApiSetVoltageDcFeedforward                g_tInvConApiSetVoltageDcFeedforward;

//--------------------------------------------------------------------------------------------------
// OTHER structs
//--------------------------------------------------------------------------------------------------

// Request for activating active discharge
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
}TUnjoSimInvConApiActiveDischargeRequest;

TUnjoSimInvConApiActiveDischargeRequest                 g_tInvConApiActiveDischargeRequest;

// Request for activating active discharge integrity test
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
}TUnjoSimInvConApiActiveDischargeIntegrityTestRequest;

TUnjoSimInvConApiActiveDischargeIntegrityTestRequest    g_tInvConApiActiveDischargeIntegrityTestRequest;

// Get last angle offset alignment since the last power cycle
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TFloat32                                    f32AngleOffset;             //!< Output argument
}TUnjoSimInvConApiGetAlignmentProcedureAngleOffset;

TUnjoSimInvConApiGetAlignmentProcedureAngleOffset       g_tInvConApiGetAlignmentProcedureAngleOffset;

// Request to clear errors
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
}TUnjoSimInvConApiErrorReleaseRequest;

TUnjoSimInvConApiErrorReleaseRequest                    g_tInvConApiErrorReleaseRequest;

// Request to reset STO1 Active and STO2 Active
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
}TUnjoSimInvConApiStoReleaseRequest;

TUnjoSimInvConApiStoReleaseRequest                      g_tInvConApiStoReleaseRequest;

// MATCH Core requests shutdown of the basic control board
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
}TUnjoSimInvConApiShutdownRequest;

TUnjoSimInvConApiShutdownRequest                        g_tInvConApiShutdownRequest;

// Displays the status for shutdown
typedef struct
{
    EInvConApiStatus                            eRet;                       //!< status
    TUint32                                     u32ShutdownStatus;          //!< Output argument
}TUnjoSimInvConApiShutdownStatus;

TUnjoSimInvConApiShutdownStatus                         g_tInvConApiShutdownStatus;

//--------------------------------------------------------------------------------------------------
// PARAM API structs
//--------------------------------------------------------------------------------------------------

// Get function for unsigned parameters
typedef struct
{
    EParamApiStatus                             eRet;                       //!< status
    TUint16                                     u16Index;                   //!< Input argument
    TUint8                                      u8SubIndex;                 //!< Input argument
    TUint32                                     u32Dst;                     //!< Output argument
}TUnjoSimParamApiGetUnsigned;

TUnjoSimParamApiGetUnsigned                             g_tParamApiGetUnsigned;

// Set function for unsigned parameters
typedef struct
{
    EParamApiStatus                             eRet;                       //!< status
    TUint16                                     u16Index;                   //!< Input argument
    TUint8                                      u8SubIndex;                 //!< Input argument
    TUint32                                     u32Value;                   //!< Input argument
}TUnjoSimParamApiSetUnsigned;

TUnjoSimParamApiSetUnsigned                             g_tParamApiSetUnsigned;

// Get function for float parameters
typedef struct
{
    EParamApiStatus                             eRet;                       //!< status
    TUint16                                     u16Index;                   //!< Input argument
    TUint8                                      u8SubIndex;                 //!< Input argument
    TFloat32                                    f32Dst;                     //!< Output argument
}TUnjoSimParamApiGetFloat;

TUnjoSimParamApiGetFloat                                g_tParamApiGetFloat;

// Set function for float parameters
typedef struct
{
    EParamApiStatus                             eRet;                       //!< status
    TUint16                                     u16Index;                   //!< Input argument
    TUint8                                      u8SubIndex;                 //!< Input argument
    TFloat32                                    f32Value;                   //!< Input argument
}TUnjoSimParamApiSetFloat;

TUnjoSimParamApiSetFloat                                g_tParamApiSetFloat;

// Get function for CRC32 of the application parameters
typedef struct
{
    EParamApiStatus                             eRet;                       //!< status
    TUint32                                     u32Value;                   //!< Output argument
}TUnjoSimParamApiGetParametersCrc;

TUnjoSimParamApiGetParametersCrc                        g_tParamApiGetParametersCrc;

//--------------------------------------------------------------------------------------------------
// SERVICE API structs
//--------------------------------------------------------------------------------------------------

// Start a new service routine
typedef struct
{
    EServiceApiStatus                        eRet;                       //!< status
    EServiceId                                eId;                        //!< Input argument
    TUint32                                     u32Value;                   //!< Input argument
}TUnjoSimServiceApiStartRoutine;

TUnjoSimServiceApiStartRoutine                          g_tServiceApiStartRoutine;

// Stop an ongoing service routine
typedef struct
{
    EServiceApiStatus                        eRet;                       //!< status
    EServiceId                                eId;                        //!< Input argument
}TUnjoSimServiceApiStopRoutine;

TUnjoSimServiceApiStopRoutine                           g_tServiceApiStopRoutine;

// Get status for a service routine
typedef struct
{
    EServiceApiStatus                        eRet;                       //!< status
    EServiceId                                eId;                        //!< Input argument
    EServiceRoutineResult                    eStatus;                    //!< Ouput argument
}TUnjoSimServiceApiGetStatus;

TUnjoSimServiceApiGetStatus                             g_tServiceApiGetStatus;

//--------------------------------------------------------------------------------------------------
// SYSTEM API structs
//--------------------------------------------------------------------------------------------------

// Get the system timer
typedef struct
{
    TUint32                                     u32TimeUs;                  //!< Output argument
}TUnjoSimSystemApiGetTimeUs;

TUnjoSimSystemApiGetTimeUs                              g_tSystemApiGetTimeUs;

// Get the version of the specified software component
typedef struct
{
    ESystemApiStatus                         eRet;                       //!< status
    ESystemApiSwComponent                   eSwComp;                    //!< Input argument
    ESystemApiSwVersion                     eSwVer;                     //!< Output argument
}TUnjoSimSystemApiGetSwVersion;

TUnjoSimSystemApiGetSwVersion                           g_tSystemApiGetSwVersion;

// Test if system reboot is allowed
typedef struct
{
    ESystemApiStatus                         eRet;                       //!< status
    TBoolean                                    boTreatAsFault;             //!< Input argument
}TUnjoSimSystemApiRebootAllowed;

TUnjoSimSystemApiRebootAllowed                          g_tSystemApiRebootAllowed;

// Reboot system
typedef struct
{
    ESystemApiStatus                         eRet;                       //!< status
    TBoolean                                    boToBootloader;             //!< Input argument
}TUnjoSimSystemApiReboot;

TUnjoSimSystemApiReboot                                 g_tSystemApiReboot;

// Inverter startup (boot) status
typedef struct
{
    ESystemApiStatus                         eRet;                       //!< status
}TUnjoSimSystemApiStartupStatus;

TUnjoSimSystemApiStartupStatus                          g_tSystemApiStartupStatus;

// Set os_sleep via system_api
typedef struct
{
    TUint32                                     u32Time;                  //!< Input argument
}TUnjoSimSystemApiSetTimeSleepUs;

TUnjoSimSystemApiSetTimeSleepUs                         g_tSystemApiSetTimeSleepUs;

#endif

//--------------------------------------------------------------------------------------------------
// INVERTER API
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
// GET functions
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//! @brief      Get active error registers
//! @param[out]  error_register Pointer to error register
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetActiveErrors( TUint32 *pu32ErrorRegister );

//--------------------------------------------------------------------------------------------------
//! @brief      Get currently active warnings
//! @param[out]  warning_register Pointer to warning register
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetActiveWarnings( TUint32 *pu32WarningRegister );

//--------------------------------------------------------------------------------------------------
//! @brief      Readout the instantaneous value of the phase current rms
//! @param[out]  current_ac Pointer to phase current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentAcActual( TFloat32 *pf32CurrentAc );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the phase current in d-axis
//! @param[out]  current_d Pointer to d-axis current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentDActual( TFloat32 *pf32CurrentD );

//--------------------------------------------------------------------------------------------------
//! @brief      Readout the calculated DC current
//! @param[out]  current_dc Pointer to dc current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentDcActual( TFloat32 *pf32CurrentDc );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the phase current in q-axis
//! @param[out]  current_d Pointer to q-axis current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentQActual( TFloat32 *pf32CurrentQ );

//--------------------------------------------------------------------------------------------------
//! @brief      Read out phase current limit as a result of the power stage derating
//! @param[out]  current Pointer to current limit [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentLimitPwrStage( TFloat32 *pf32CurrentPwr );

//--------------------------------------------------------------------------------------------------
//! @brief      Read out phase current (squareroot(d^2 + q^2)) set value as output of the torque controller and MTPA curve
//! @param[out]  current Pointer to current set value [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentSetValue( TFloat32 *pf32CurrentSet );

//--------------------------------------------------------------------------------------------------
//! @brief      Get phase current (squareroot(d^2 + q^2)) set value after current limitation block
//! @param[out]  current Pointer to current set value [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetCurrentPostLimit( TFloat32 *pf32CurrentPostLimit );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the frequency set value for V/f control
//! @param[out]  frequency Pointer to frequency set value [Hz]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetFrequencyPostRamp( TFloat32 *pf32FrequencyPostRamp );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the hwc max current
//! @param[out]  current Pointer to hwc max current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetHwcMaxCurrent( TFloat32 *pf32HwcMaxCurrent );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the hwc max frequency
//! @param[out]  current Pointer to hwc max frequency [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetHwcMaxFrequency( TFloat32 *pf32HwcMaxFrequency );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the hwc max torque, using motor-data MTPA, according to max possible phase current in hwc
//! @param[out]  torque Pointer to hwc max torque value [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetHwcMaxTorque( TFloat32 *pf32HwcMaxTorque );

//--------------------------------------------------------------------------------------------------
//! @brief      Get freeze frame of the last error occured
//! @param[out]  freeze_frame Pointer to error information
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetFreezeFrame( TErrorInformation *ptFreezeFrame );

//--------------------------------------------------------------------------------------------------
//! @brief      Get stored angle offset value in the currently used motor data set
//! @param[out]  angle_offset Pointer to stored angle offset
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdAngleOffset( TFloat32 *pf32MdAngleOffset );

//--------------------------------------------------------------------------------------------------
//! @brief      Get CRC of the motor data set
//! @param[out]  crc Pointer to motor data set CRC
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMotorDataSetCrc( TUint16 *pu16MotorDataSetCrc );

//--------------------------------------------------------------------------------------------------
//! @brief      Get motor ID of the motor data set
//! @param[out]  motor_id Pointer to motor id
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdMotorId( TUint16 *pu16MotorId );

//--------------------------------------------------------------------------------------------------
//! @brief      Get motor type of the motor data set
//! @param[out]  motor_type Pointer to motor id
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdMotorType( EInvConApiMotorType *peMdMotorType );

//--------------------------------------------------------------------------------------------------
//! @brief      Get version of the motor data set
//! @param[out]  version Pointer to version
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMotorDataSetVersion( TUint16 *pu16MotorDataSetVersion );

//--------------------------------------------------------------------------------------------------
//! @brief      Get rated torque of the motor data set
//! @param[out]  torque Pointer to torque [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdRatedTorque( TFloat32 *pf32MdRatedTorque );

//--------------------------------------------------------------------------------------------------
//! @brief      Get max current allowed of the motor data set
//! @param[out]  current Pointer to current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdMaxCurrent( TFloat32 *pf32MdMaxCurrent );

//--------------------------------------------------------------------------------------------------
//! @brief      Get max torque of the motor data set
//! @param[out]  torque Pointer to torque [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdMaxTorque( TFloat32 *pf32MdMaxTorque );

//--------------------------------------------------------------------------------------------------
//! @brief      Get max speed of the motor data set
//! @param[out]  speed Pointer to speed [rpm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMdMaxSpeed( TFloat32 *pf32MdMaxSpeed );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the the ratio of controller output voltage over max possible sinusoidal voltage value
//! @param[out]  modulation_index Pointer to voltage ratio [%]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetModulationIndex( TFloat32 *pf32ModulationIndex );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the the currently active motor data set
//! @param[out]  motor_data_set_number Pointer to motor data set number
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetMotorDataSetNumber( TUint8 *pu8MotorDataSetNumber );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the actual PWM frequency
//! @param[out]  pwm_frequency Pointer to PWM frequency [Hz]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetPwmFrequency( TFloat32 *pf32PwmFrequency );

//--------------------------------------------------------------------------------------------------
//! @brief      Readout the current speed of motor
//! @param[out]  speed Pointer to where motor actual speed shall be stored [rpm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetSpeedActual( TFloat32 *pf32SpeedActual );

//--------------------------------------------------------------------------------------------------
//! @brief      Get speed set value output of speed limit block
//! @param[out]  speed Pointer to speed limit [rpm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetSpeedPostLimit( TFloat32 *pf32SpeedPostLimit );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the speed set value output of speed ramp generator
//! @param[out]  speed Pointer to speed ramp [rpm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetSpeedPostRamp( TFloat32 *pf32SpeedPostRamp );

//--------------------------------------------------------------------------------------------------
//! @brief      Read status register
//! @param[out]  status_reg Pointer to status register
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetStatusRegister( TUint32 *pu32StatusRegister );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the IGBT junction temperature from BD
//! @param[out]  temp Pointer to igbt temperature [Celsius]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTempPwrStageJunction( TFloat32 *pf32TempPwrStageJunction );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the calculated applied torque value
//! @param[out]  torque Pointer to applied torque [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorqueActual( TFloat32 *pf32TorqueActual );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the positive torque limit due to the machine characteristic, speed and dc link voltage
//! @param[out]  torque Pointer to torque limit [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorquePosLimitMc( TFloat32 *pf32TorquePosLimitMc );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the negative torque limit due to the machine characteristic, speed and dc link voltage
//! @param[out]  torque Pointer to torque limit [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorqueNegLimitMc( TFloat32 *pf32TorqueNegLimitMc );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the torque limit if inverter is in torque control, voltage control mode or current control mode
//! @param[out]  torque Pointer to torque limit [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorquePosLimitSpeed( TFloat32 *pf32TorquePosLimitSpeed );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the limitation of the torque due to overvoltage protection
//! @param[out]  torque Pointer to torque limit [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorqueOvLimitVoltage( TFloat32 *pf32TorqueOvLimitVoltage );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the limitation of the torque due to undervoltage protection
//! @param[out]  torque Pointer to torque limit [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorqueUvLimitVoltage( TFloat32 *pf32TorqueUvLimitVoltage );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the torque limit value output of torque limit block
//! @param[out]  torque Pointer to torque set value [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorquePostLimit( TFloat32 *pf32TorquePostLimit );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the torque ramp value output of torque ramp generator
//! @param[out]  torque Pointer to torque set value [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorquePostRamp( TFloat32 *pf32TorquePostRamp );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the torque current limit value output of torque current generator
//! @param[out]  torque Pointer to torque set value [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorquePostCurrentLimit( TFloat32 *pf32TorquePostCurrentLimit );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the torque set value
//! @param[out]  torque Pointer to torque set value [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetTorqueSetValue( TFloat32 *pf32TorqueSetValue );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the instantaneous motor rms voltage (phase to phase)
//! @param[out]  voltage_ac Pointer to instantaneous motor voltage [V]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetVoltageAcActual( TFloat32 *pf32VoltageAcActual );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the actual motor voltage in d axis
//! @param[out]  voltage_d Pointer to d-axis motor voltage [V]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetVoltageDActual( TFloat32 *pf32VoltageDActual );

//--------------------------------------------------------------------------------------------------
//! @brief      Get the actual motor voltage in q axis
//! @param[out]  voltage_q Pointer to q-axis motor voltage [V]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetVoltageQActual( TFloat32 *pf32VoltageQActual );

//--------------------------------------------------------------------------------------------------
//! @brief      Get status of inv_con_api
//! @return status of inv_con_api
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_BUSY
//! @retval API_INV_CON_STATUS_REJECTED
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetStatus( TVoid );

//--------------------------------------------------------------------------------------------------
// SET functions
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//! @brief      Current control set value for d-axis
//! @param[in]  current_d_set Requested set d-axis current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetCurrentD( TFloat32 f32CurrentD );

//--------------------------------------------------------------------------------------------------
//! @brief      Current control set value for q-axis
//! @param[in]  current_q_set Requested set q-axis current [A]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetCurrentQ( TFloat32 f32CurrentQ );

//--------------------------------------------------------------------------------------------------
//! @brief      Set Frequency for V/f control (target for ramp)
//! @param[in]  frequency_set Requested set V/f control frequency [Hz]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetFrequency( TFloat32 f32Frequency );

//--------------------------------------------------------------------------------------------------
//! @brief      Requests the permanent active short circuit
//! @param[in]  command Command to send
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetPermActiveShortCircuit( EInvConApiActiveShortCircuitStatus eCommand );

//--------------------------------------------------------------------------------------------------
//! @brief      Set the feed forward torque for speed controller
//! @param[in]  feedforward Requested to feed forward torque [Nm]
//! @retval API_INV_CON_STATUS_BUSY
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetSpeedFeedforward( TFloat32 f32SpeedFeedforward );

//--------------------------------------------------------------------------------------------------
//! @brief      Set new state for drive power stage
//! @param[in]  command Command to send
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetPowerStage( EInvConApiPowerStageCommand eCommand );

//--------------------------------------------------------------------------------------------------
//! @brief      Set the target speed of the motor
//! @param[in]  speed Requested motor speed [rpm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetSpeed( TFloat32 f32Speed );

//--------------------------------------------------------------------------------------------------
//! @brief      Set torque controller
//! @param[in]  torque_set Requested set torque controller [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetTorque( TFloat32 f32Torque );

//--------------------------------------------------------------------------------------------------
//! @brief      Set boost voltage for V/f control
//! @param[in]  voltage Requested set boost for V/f [V]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetVfBoost( TFloat32 f32VfBoost );

//--------------------------------------------------------------------------------------------------
//! @brief      Set value for voltage controller
//! @param[in]  voltage_dc_set Requested voltage controller [V]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetVoltageDc( TFloat32 f32VoltageDc );

//--------------------------------------------------------------------------------------------------
//! @brief      Set the feed forward torque for voltage controller
//! @param[in]  feedforward Requested feed forward torque [Nm]
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_VALUE_TOO_HIGH
//! @retval API_INV_CON_STATUS_VALUE_TOO_LOW
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiSetVoltageDcFeedforward( TFloat32 f32VoltageDcFeedforward );

//--------------------------------------------------------------------------------------------------
// OTHER functions
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//! @brief      Request for activating active discharge
//! @param[out]  Inverter control API status
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiActiveDischargeRequest( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Request for activating active discharge integrity test
//! @param[out]  Inverter control API status
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiActiveDischargeIntegrityTestRequest( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Get last angle offset alignment since the last power cycle
//! @param[out]  angle_offset Pointer to angle offset
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiGetAlignmentProcedureAngleOffset( TFloat32* pf32AngleOffset );

//--------------------------------------------------------------------------------------------------
//! @brief      Request to clear errors
//! @param[out]  Inverter control API status
//! @retval API_INV_CON_STATUS_OK
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiErrorReleaseRequest( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Request to reset STO1 Active and STO2 Active
//! @param[out]  Inverter control API status
//! @retval API_INV_CON_STATUS_BUSY
//! @retval API_INV_CON_STATUS_UNKNOWN
//! @retval API_INV_CON_STATUS_REJECTED
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiStoReleaseRequest( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      MATCH Core requests shutdown of the basic control board
//! @param[out]  Inverter control API status
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_SHUTDOWN_DELAYED
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiShutdownRequest( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Displays the status for shutdown
//! @param[out]  angle_offset Pointer to angle offset
//! @retval API_INV_CON_STATUS_OK
//! @retval API_INV_CON_STATUS_UNKNOWN
//--------------------------------------------------------------------------------------------------
extern EInvConApiStatus eInvConApiShutdownStatus( TUint32* pu32ShutdownStatus );

//--------------------------------------------------------------------------------------------------
// PARAM API functions
//--------------------------------------------------------------------------------------------------

//! @brief       Get function for unsigned parameters
//! @param[in]  index Index for parameter
//! @param[in]  subindex Subindex for parameter
//! @param[out] dst Destination pointer for return value
//! @retval EParamApiStatus
//--------------------------------------------------------------------------------------------------
extern EParamApiStatus eParamApiGetUnsigned(TUint16 u16Index, TUint8 u8SubIndex, TUint32* pu32Dst);

//! @brief       Set function for unsigned parameters
//! @param[in]  index Index for parameter
//! @param[in]  subindex Subindex for parameter
//! @param[in] value Parameter value
//! @retval EParamApiStatus
//--------------------------------------------------------------------------------------------------
extern EParamApiStatus eParamApiSetUnsigned(TUint16 u16Index, TUint8 u8SubIndex, TUint32 u32Value);

//! @brief       Get function for float parameters
//! @param[in]  index Index for parameter
//! @param[in]  subindex Subindex for parameter
//! @param[out] dst Destination pointer for return value
//! @retval EParamApiStatus
//--------------------------------------------------------------------------------------------------
extern EParamApiStatus eParamApiGetFloat(TUint16 u16Index, TUint8 u8SubIndex, TFloat32* pf32Dst);

//! @brief       Set function for float parameters
//! @param[in]  index Index for parameter
//! @param[in]  subindex Subindex for parameter
//! @param[in] value Parameter value
//! @retval EParamApiStatus
//--------------------------------------------------------------------------------------------------
extern EParamApiStatus eParamApiSetFloat(TUint16 u16Index, TUint8 u8SubIndex, TFloat32 f32Value);

//! @brief       Get function for CRC32 of the application parameters
//! @param[out] value Destination pointer for return value
//! @retval EParamApiStatus
//--------------------------------------------------------------------------------------------------
extern EParamApiStatus eParamApiGetParametersCrc( TUint32* pu32Value );

//--------------------------------------------------------------------------------------------------
// SERVICE API functions
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//! @brief       Start a new service routine
//!
//! e.g. service_api_start_routine(SERVICE_ROUTINE_OFFSET_ALIGNMENT, NULL)
//! when requesting angle offset alignment
//!
//! e.g. service_api_start_routine(SERVICE_ROUTINE_CHANGE_MOTOR_DATA_SET, &md_set)
//! when setting motor data set, where md_set is a uint32_t
//!
//! @param[in]      id Service routine identifier
//! @param[in/out]  arg additional data needed for service routine
//! @retval         EServiceApiStatus
//--------------------------------------------------------------------------------------------------
extern EServiceApiStatus eServiceApiStartRoutine(EServiceId eId, TVoid* pvArg);

//--------------------------------------------------------------------------------------------------
//! @brief Stop an ongoing service routine
//! @param[in] id Service routine identifier
//! @retval EServiceApiStatus
//--------------------------------------------------------------------------------------------------
extern EServiceApiStatus eServiceApiStopRoutine( EServiceId eId );

//--------------------------------------------------------------------------------------------------
//! @brief Get status for a service routine
//! @param[in] id Service routine identifier
//! @param[out] id status Pointer to service_routine_result enum
//! @retval EServiceApiStatus
//--------------------------------------------------------------------------------------------------
extern EServiceApiStatus eServiceApiGetStatus( EServiceId eId, EServiceRoutineResult* peStatus);

//--------------------------------------------------------------------------------------------------
// SYSTEM API functions
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//! @brief      Get the system timer
//! @retval timer in microseconds
//--------------------------------------------------------------------------------------------------
extern TUint32 u32SystemApiGetTimeUs( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief Get the version of the specified software component
//! @param[in] sw_comp The system component
//! @param[out] sw_ver The system version to read
//! @retval system_api_status
//--------------------------------------------------------------------------------------------------
extern ESystemApiStatus eSystemApiGetSwVersion( ESystemApiSwComponent eSwComp, ESystemApiSwVersion* peSwVer );

//--------------------------------------------------------------------------------------------------
//! @brief Test if system reboot is allowed.
//! Returns OK status if reboot is allowed, other status on failure.
//! @param treat_as_fault If true, increment a fault counter if reboot is not allowed
//! @return System API status
//! @retval API_SYSTEM_STATUS_OK if reboot is allowed
//! @retval SYSTEM_API_STATUS_ERROR_DRIVE_STATE if drive is in operational state
//--------------------------------------------------------------------------------------------------
extern ESystemApiStatus eSystemApiRebootAllowed( TBoolean boTreatAsFault );

//--------------------------------------------------------------------------------------------------
//! @brief Reboot system.
//! On success, initiates a system reboot and returns OK status.
//! On failure, returns the error status.
//! @param to_bootloader reboot to bootloader or not
//! @return System API status
//! @retval API_SYSTEM_STATUS_OK if reboot is allowed
//! @retval SYSTEM_API_STATUS_ERROR_DRIVE_STATE if drive is in operational state
//--------------------------------------------------------------------------------------------------
extern ESystemApiStatus eSystemApiReboot( TBoolean boToBootloader );

//--------------------------------------------------------------------------------------------------
//! @brief      Inverter startup (boot) status
//! Returns the status of last startup procedure
//! @return System API status
//! @retval API_SYSTEM_STATUS_OK startup procedure is completed
//! @retval API_SYSTEM_STATUS_STARTUP_NOT_COMPLETED Startup procedure not completed
//--------------------------------------------------------------------------------------------------
extern ESystemApiStatus eSystemApiStartupStatus( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Reset faults on Basic Drive unit
//--------------------------------------------------------------------------------------------------
extern TVoid vSystemApiResetBdFaults( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Set os_sleep via system_api
//--------------------------------------------------------------------------------------------------
extern TVoid vSystemApiSetTimeSleepUs( TUint32 u32Time );

#endif // ITFBOARDCENUNJOBCPARAMCTRL
