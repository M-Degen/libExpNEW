//**************************************************************************************************
/*!
@file       ItfCoreBoardBasic.h
@brief	    Basic types needed for Board Interface
@date       17.01.2020
@author     HYDAC/THU
*/
//**************************************************************************************************

#ifndef __ITFCOREBOARDBASIC__
   #define __ITFCOREBOARDBASIC__

    #include <autoconfig.h>
    #include <ItfTypes.h>

    //! PIN possibles configuration types from PDT
    enum
    {
        _PINTYP_NA        =  0,    //!< Type: [-]      Not available
        _PINTYP_DIN       =  1,    //!< Type: [0/1]    Digital input
        _PINTYP_VIN       =  2,    //!< Type: [mV]     Voltage input
        _PINTYP_RES       =  3,    //!< Type: [Ohm]    Resistive configuration
        _PINTYP_CIN       =  4,    //!< Type: [µA]     Current input
        _PINTYP_FIN       =  5,    //!< Type: [Hz]     Frequency input
        _PINTYP_PUL       =  6,    //!< Type: [µs]     Read pulse value input
        _PINTYP_CNT       =  7,    //!< Type: [cnt]    Counter input
        _PINTYP_CPX       =  8,    //!< Type: [STU]    Complex input
        _PINTYP_INC       =  9,    //!< Type: [cnt]    Incremental input with 2 pins
        _PINTYP_DOU       = 10,    //!< Type: [0/1]    Digital output
        _PINTYP_PWM       = 11,    //!< Type: [duty]   PWM high-side output
        _PINTYP_LED       = 12,    //!< Type: [0/1]    LED output
        _PINTYP_PVG       = 13,    //!< Type: [%/100]  Percent of Ubat [1500..8500]
        _PINTYP_VOU       = 14,    //!< Type: [mV]     Voltage output
        _PINTYP_PWM_DUAL  = 15,    //!< Type: [duty]   PWM output dual pins with one low side switch
        _PINTYP_RAW       = 16,    //!< Type: [raw]    Value input
        _PINTYP_PER       = 17,    //!< Type: [%/100]  Value input
        _PINTYP_COU       = 18,    //!< Type: [mA]     Current output
        _PINTYP_RAT       = 19,    //!< Type: [mA]     Ratiometric input Vin/Vcc
        _PINTYP_SIN       = 20,    //!< Type: [1/min]  Motor Speed input
        _PINTYP_PIN       = 21,    //!< Type: [µm]     Valve position input
        _PINTYP_POU       = 22,    //!< Type: [µm]     Valve position output
        _PINTYP_EIN       = 23,    //!< Type: [-]      Emergency shut-off input
        _PINTYP_EOU       = 24,    //!< Type: [duty]   Emergency shut-off output

        _PINTYP_PWM_LS    = 25,    //!< Type: [duty]   PWM low-side output
        _PINTYP_DOU_LS    = 26     //!< Type: [0/1]    Digital low-side output
    };


    //! Adc types
    enum
    {// RANGE  0 - 32767
        // === Digital Inputs ===
        _ADC_DIN_D                          = 1,    //!< [DEF]   Digital value
        _ADC_DIN_S                          = 2,    //!< [DEF]   Digital value status
        // === Voltage ===
        _ADC_VIN_V                          = 3,    //!< [mV]    Analogue in voltage
        _ADC_VIN_S                          = 4,    //!< [DEF]   Analogue in voltage status
        _ADC_VIN_D                          = 5,    //!< [DEF]   Digital value (deduced over the threshold [core feature])
        // === RES ===
        _ADC_RES_R                          = 6,    //!< [Ohm]   Analogue in resistor
        _ADC_RES_S                          = 7,    //!< [DEF]   Analogue in resistor status
        // === Current ===
        _ADC_CIN_C                          = 8,    //!< [µA]    Analogue in current mode
        _ADC_CIN_S                          = 9,    //!< [DEF]   Analogue in current status
        _ADC_CIN_D                          = 10,   //!< [DEF]   Digital value (deduced over the threshold [core feature])
        // === Frequency ===
        _ADC_FIN_F                          = 11,   //!< [Hz]    Frequency
        _ADC_FIN_S                          = 12,   //!< [DEF]   Frequency status
        _ADC_FIN_V                          = 13,   //!< [mV]    Analogue in voltage
        _ADC_FIN_VS                         = 14,   //!< [DEF]   Analogue in voltage status
        // === Pulse ===
        _ADC_PUL_HT                         = 15,   //!< [ms]    Pulse length (high time) [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                        //                                    [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        _ADC_PUL_S                          = 16,   //!< [DEF]   Pulse length status
        // === Counter ===
        _ADC_COUNTER                        = 17,   //!< [cnt]   Counter value
        _ADC_COUNTER_S                      = 18,   //!< [DEF]   Counter value status
        _ADC_COUNTER_V                      = 19,   //!< [mV]    Voltage on the PIN
        _ADC_COUNTER_D                      = 20,   //!< [mV]    Digital on the PIN (Bsp feature [driver feedback])
        // === Complex ===
        _ADC_CPX_F                          = 21,   //!< [Hz]    Frequency
        _ADC_CPX_S                          = 22,   //!< [Hz]    Frequency status
        _ADC_CPX_V                          = 23,   //!< [mV]    Analogue in voltage mode
        _ADC_CPX_HT                         = 24,   //!< [µs]    Pulse length
                                            //!<            [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                            //!<            [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        _ADC_CPX_CNT                        = 25,   //!< [cnt]   Counter value
        _ADC_CPX_C                          = 26,   //!< [µA]    Current feedback
        _ADC_CPX_CS                         = 27,   //!< [DEF]   Current feedback status
        // === Increment ===
        _ADC_INC_CNT                        = 28,   //!< [cnt]   Increment value - two PIN solution
        _ADC_INC_S                          = 29,   //!< [cnt]   Increment value - status
        _ADC_INC_MAS_V                      = 30,   //!< [cnt]   Increment value - master PIN voltage
        _ADC_INC_SLA_V                      = 31,   //!< [cnt]   Increment value - slave PIN voltage
        _ADC_INC_MAS_D                      = 32,   //!< [cnt]   Increment value - master PIN digital status (Bsp feature [driver feedback])
        _ADC_INC_SLA_D                      = 33,   //!< [cnt]   Increment value - slave PIN digital status  (Bsp feature [driver feedback])

        // ===  PWM Outputs ===
        _ADC_PWM_I_MAX                      = 34,   //!< [A/10]  Maximum current on PWM output
        _ADC_PWM_OUT_DC                     = 35,   //!< [DEF]   Give the set duty cycle (must call after DAC_PWM_D/DC)
        _ADC_PWM_S                          = 36,   //!< [DEF]   PIN status (must call after DAC_PWM_D/DC)
        _ADC_PWM_C                          = 37,   //!< [mA/10] Actual current
        _ADC_PWM_CS                         = 38,   //!< [mA/10] Actual current PIN status (must call after ADC_PWM_C)
        _ADC_PWM_C_FRESH                    = 39,   //!< [DEF]   Actual current is fresh (must call after ADC_PWM_C)
        _ADC_PWM_HT                         = 40,   //!< [µs]    Pulse length (high time)(must call after DAC_PWM_D/DC)
                                                    //!<            [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                    //!<            [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        _ADC_PWM_PERIODE                    = 41,   //!< [µs]    Period feedback for the channels
        _ADC_PWM_V                          = 42,   //!< [mV]    Average voltage

        // === Digital Output ===
        _ADC_DOU_OUT_D                      = 43,   //!< [DEF]   Give the set DOU value (Bsp feature [driver feedback])
        _ADC_DOU_S                          = 44,   //!< [DEF]   PIN status  (from last DAC-Call)
        _ADC_DOU_V                          = 45,   //!< [mV]    Channel digital voltage
        _ADC_DOU_C_FRESH                    = 46,   //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)
        _ADC_DOU_C                          = 47,   //!< [mA/10] Actual current measurement    -> ( Low side PIN only )
        _ADC_DOU_CS                         = 48,   //!< [DEF]   Status on current measurement -> ( Low side PIN only )
        // === LED Output ==
        _ADC_LED_OUT_D                      = 49,   //!< [ON/OFF]  Give the set LED value (Bsp feature [driver feedback])
        _ADC_LED_S                          = 50,   //!< [DEF]     PIN status
        _ADC_LED_VAL                        = 51,   //!< [VAL]     If the LED was turned on this returns the actual current(Range: 0...27.600mA)
                                            //!<           If the LED was turned off this returns the actual voltage(Range: 0...10.500V)
        // === PVG Output ===
        _ADC_PVG_OUT_P                      = 52,   //!< [%/100]   Give the set percent of UBat [percent*100 (1500..8500)]
        _ADC_PVG_S                          = 53,   //!< [DEF]     PIN status (must call after DAC_PVG)
        _ADC_PVG_OUT_V                      = 54,   //!< [mV]      Measured voltage in mV. range: 0..32000 (0V..32.000V)
        // === VOU Output ===
        _ADC_VOU_OUT_V                      = 55,   //!< [mV]      Give the set VOU value
        _ADC_VOU_S                          = 56,   //!< [DEF]     PIN status
        _ADC_VOU_V                          = 57,   //!< [mV]      Voltage feedback
        // === ECU board info ==
        // only system group as PIN always PIN_SYS
        _ADC_SYS_UB_ECU_MAX         		= 58,   //!< [mV]     MAX controller power  (IMPORTANT ECU MAXIMUM SPEC RANGE)
        _ADC_SYS_BAT_OPERATE        		= 59,   //!< [mV]     Ecu battery operate value  [1200, 24000]
        _ADC_SYS_BAT_CURRENT        		= 60,   //!< [mV]     Ecu battery current value
        _ADC_SYS_K15_D              		= 61,   //!< [ON/OFF] Ignition
        _ADC_SYS_K15_V              		= 62,   //!< [mV]     Ignition(reserved)
        _ADC_SYS_SAFE_STATE         		= 63,   //!< [ON/OFF] Safe state [on TTC71 emulate -> all outputs off]
        _ADC_SYS_POWERSTAGE_ENABLE  		= 64,   //!< [ON/OFF] Internal PIN for enabling power stages
        _ADC_SYS_TEMP               		= 65,   //!< [K]      Temperature (Â°C = x - ADC_KELVIN_OFFSET)
        _ADC_SYS_DC_MAX             		= 66,   //!< [-]      Maximum duty cycle on PWM output
        _ADC_SYS_REF_VOLTAGE        		= 67,   //!< [mV]     Reference voltage
                                            		//!           [TTC71 have no support -> Value:0, Pin-Status:PINSTA_ERRINIT]
        _ADC_SYS_SENSOR_0_V         		= 68,   //!< [mV]     Sensor supply voltage - 3X: PIN H3 - 5X: PIN 136 - 5XX: PIN 247
        _ADC_SYS_SENSOR_1_V         		= 69,   //!< [mV]     Sensor supply voltage - 5X: PIN 135 - 5XX: PIN 234
        _ADC_SYS_SENSOR_VAR_V       		= 70,   //!< [mV]     Sensor supply voltage - 5X: PIN 269 - 5XX: PIN 221
        _ADC_SYS_SAFTEY_SW_00       		= 71,   //!< [ON/OFF] Internal PIN for safety switch 0
        _ADC_SYS_SAFTEY_SW_01       		= 72,   //!< [ON/OFF] Internal PIN for safety switch 1
        _ADC_SYS_SAFTEY_SW_02       		= 73,   //!< [ON/OFF] Internal PIN for safety switch 2
        _ADC_SYS_PVG_VOU_00         		= 74,   //!< [ON/OFF] Internal PIN for enable PVG VOU group 0
        _ADC_SYS_PVG_VOU_01         		= 75,   //!< [ON/OFF] Internal PIN for enable PVG VOU group 1
        _ADC_SYS_NODE_ID0           		= 76,   //!< [mV]     Node ID0              - 3X: PIN K0
        _ADC_SYS_NODE_ID1           		= 77,   //!< [mV]     Node ID1              - 3X: PIN J3
        _ADC_SYS_PWM_ENABLE         		= 78,   //!< [ON/OFF] Internal PIN for enabling power stages
        _ADC_SYS_WAKEUP             		= 79,   //!< [ON/OFF] WakeUp Pin
        _ADC_SYS_BAT_CPU_V          		= 80,   //!< [mV]     Battery cpu, voltage
        _ADC_ESO_IN_A               		= 81,   //!< [ON/OFF] shut_off_in A
        _ADC_ESO_IN_B               		= 82,   //!< [ON/OFF] shut_off_in B
        _ADC_EOU_OUT_DC             		= 83,   //!< [ON/OFF] shut_off_out
        _ADC_SYS_WAKEUP_V           		= 84,   //!< [mV]     WakeUp Pin Voltage
        _ADC_SYS_CAN_WAKEUP         		= 85,   //!< [ON/OFF] CAN WakeUp
        _ADC_EOU_S                  		= 86,   //!< [DEF]    Shutoff PIN status
        _ADC_EOU_V                  		= 87,   //!< [mV]     Shutoff voltage feedback
        // Unjo specific board information
        _ADC_SYS_BC_CPU_TEMP                = 88,   // [0.1 Kelvin/bit] Basic Control board temperature
        _ADC_SYS_BD_CPU_TEMP                = 89,   // [0.1 Kelvin/bit] Basic Drive board temperature
        _ADC_SYS_IGBT_CASE_TEMP             = 90,   // [0.1 Kelvin/bit] transistor bridge to the motor temperature
        _ADC_SYS_STATOR_TEMP                = 91,   // [0.1 Kelvin/bit] Motor temperature
        _ADC_SYS_TRM_30                     = 92,   // [1 mV/bit]
        _ADC_SYS_VBSSNS                     = 93,   // [1 mV/bit] boost converter power supply feedback
        _ADC_SYS_24V                        = 94,   // [1 mV/bit] 24V reference
        _ADC_SYS_3V3                        = 95,   // [1 mV/bit] 3V3 reference
        _ADC_SYS_DC_LINK_VOLT               = 96,   // [100 mV/bit]
        _ADC_SYS_INSTANTANEOUS_PHASE_CURR_U = 97,   // [100 mA/bit]
        _ADC_SYS_INSTANTANEOUS_PHASE_CURR_V = 98,   // [100 mA/bit]
        _ADC_SYS_INSTANTANEOUS_PHASE_CURR_W = 99,   // [100 mA/bit]
        _ADC_SYS_DIN_STO_1                  = 100,  // [STO.1 in connector. FALSE: STO not active, TRUE: STO active] Safe Torque
        _ADC_SYS_DIN_STO_2                  = 101,  // [STO.2 in connector. FALSE: STO not active, TRUE: STO active] Safe Torque
        _ADC_SYS_DIN_OTE                    = 102,  // [Output Test Equipment. FALSE: No fault in STO electronics, TRUE: Fault in STO electronics] Safe Torque
        _ADC_SYS_HVIL_IN                    = 103,  // HVIL Input
        _ADC_SYS_HVIL_OUT                   = 104,  // HVIL Output
        _ADC_SYS_HVIL_CUR                   = 105,  // HVIL Current
        _ADC_SYS_SPWR5V0                    = 106,  // [0 or 5000] Sensor Power supply fixed 5.0V
        _ADC_SYS_SPWRADJ                    = 107   // [0 or 5000-16000] Sensor Power supply Adjustable

    };

    //! DAC types
    enum
    {
        _DAC_DOU_D                      = 0,    //!< [ON/OFF]       Digital output
        _DAC_PWM_D                      = 1,    //!< [ON/OFF]       PWM output on/off
        _DAC_PWM_DC                     = 2,    //!< [0..MAX_DUTY]  PWM output in proportional values
        _DAC_LED_D                      = 3,    //!< [ON/OFF]       LED output
        _DAC_PVG_P                      = 4,    //!< [%/100]        Percent of Ubat [percent*100 (1500..8500)]
        _DAC_VOU_V                      = 5,    //!< [mV]           Voltage output
        // === ECU board info ===
        // No channel - only system group
        _DAC_SYS_K15                    = 6,    //!< [ON/OFF] K15
        _DAC_SAFE_STATE                 = 7,    //!< [ON/OFF] Safe state
                                                //!< [on TTC71    emulate -> all outputs off]
                                                //!< [on TTC50/60 emulate -> all outputs off]
        _DAC_SYS_POWERSTAGE_ENABLE      = 8,    //!< [ON/OFF] Internal PIN for enabling power stages

        _DAC_SYS_SENSOR_0_D             = 9,    //!< [ON/OFF]           Switch the sensor supply            - 5X: PIN 136 - 5XX: PIN 247
        _DAC_SYS_SENSOR_1_D             = 10,   //!< [ON/OFF]           Switch the sensor supply            - 5X: PIN 135 - 5XX: PIN 234

        _DAC_SYS_SENSOR_VAR_V           = 11,   //!< [VAL_SENSOR_VAR_x] Set sensor supply to a output level - 5X: PIN 269 - 5XX: PIN 221

        _DAC_SYS_SAFTEY_SW_00           = 12,   //!< [ON/OFF] Internal PIN for safety switch 0
        _DAC_SYS_SAFTEY_SW_01           = 13,   //!< [ON/OFF] Internal PIN for safety switch 1
        _DAC_SYS_SAFTEY_SW_02           = 14,   //!< [ON/OFF] Safety switch 02 (internal PIN - without enabling this signal the PWM group with that switch is 'off')

        _DAC_SYS_PVG_VOU_00             = 15,   //!< [ON/OFF] Internal PIN for enable PVG VOU group 0
        _DAC_SYS_PVG_VOU_01             = 16,   //!< [ON/OFF] Internal PIN for enable PVG VOU group 1

        _DAC_SYS_PWM_ENABLE             = 17,   //!< [ON/OFF] Internal PIN for enabling power stages

        _DAC_SYS_WAKEUP                 = 18,   //!< [ON/OFF] Wake Up, for power down after a wake up)
        _DAC_PWM_DC_RESOLVE_OPEN_SCPOW  = 19,   //!< [0..MAX_DUTY] - is like the DAC_PWM_DC - but with a better PIN status
                                                //!<                 result PINSTA_OPEN_SCPOW from DAC_PWM_DC will be resolved in
                                                //!<                 PINSTA_OPEN or PINSTA_SCPOW
                                                //!< ATTENTION
                                                //!<   - The resolving of a PWM PIN requires to shift an internal feedback signal that is used
                                                //!<     by all PWM PIN. Although this does not influence other PWM PIN, it can affect
                                                //!<     PIN that are configured for the alternative functions digital input and timer input.
                                                //!<     Please refer to the safety manual for detailed information.
                                                //!<
                                                //!<  NOTE
                                                //!<   - After resolving an open load or short circuit to battery condition the PWM channel
                                                //!<     will be automatically disabled and cannot be re-enabled anymore.
        _DAC_SYS_EMG_OUT_A              = 20,   //!< [0..MAX_DUTY] Emergency out, implemented with dutycycle

        _DAC_SYS_SPWR5V0                = 21,   // [0 or 5000] Sensor Power supply fixed 5.0V
        _DAC_SYS_SPWRADJ                = 22    // [0 or 5000-16000] Sensor Power supply Adjustable
    };

    //! PIN Status
    enum
    {
        _PINSTA_OK                           =  0, //!< PIN is OK
        _PINSTA_OPEN                         =  1, //!< PIN is open
        _PINSTA_SCGND                        =  2, //!< PIN is short circuit to ground
        _PINSTA_SCPOW                        =  3, //!< PIN is short circuit to power
        _PINSTA_UNDEF                        =  4, //!< PIN is undefined ( no PIN update since ecu start )
        _PINSTA_ERRINIT                      =  5, //!< PIN not installed / PIN don't support the request
        _PINSTA_ERRUNDEF                     =  6, //!< PIN status in undefined error
        _PINSTA_ERRINUSED                    =  7, //!< Output PIN has been used in that cycle
        _PINSTA_OPEN_SCPOW                   =  8, //!< PIN is an open or short circuit to power
        _PINSTA_WAR_OVER_CUR                 =  9, //!< PIN have over current - output will temporarily be switched off if the current does not decrease
        _PINSTA_PROTECTION                   = 10, //!< PIN in a protection mode
        _PINSTA_PROTECTION_REE               = 11, //!< PIN goes from the protection mode to the re-enable mode (automatic)
        _PINSTA_PROTECTION_FIX               = 12, //!< PIN is a fix protection mode
        _PINSTA_SAFESTATE                    = 13, //!< PIN is in "safe state"
        _PINSTA_SWOFF_OPEN                   = 14, //!< PIN 'Group-Switch' is open - switch by the application
        _PINSTA_DISABLE_FAILED               = 15, //!< The PWM output has been disabled by the main CPU but there is still a signal on the output. The signal can be the result of a open-load condition or a short to another signal source.
        _PINSTA_PWD_NOT_FINISHED             = 16, //!< PIN not enough edges to accumulate a result
        _PINSTA_PWD_OVERFLOW                 = 17, //!< A timer overflow occurred
        _PINSTA_PWD_CAPTURE_ERROR            = 18, //!< The frequency was too high
        _PINSTA_PWD_CURRENT_THRESHOLD_HIGH   = 19, //!< Last measurement of current threshold was above 20.5mA
        _PINSTA_PWD_CURRENT_THRESHOLD_LOW    = 20, //!< Last measurement of threshold was under 4.5mA
        _PINSTA_PWD_HIGH_LEVEL               = 21, //!< only a constant high level is detected
        _PINSTA_PWD_LOW_LEVEL                = 22, //!< only a constant low level is detected
        _PINSTA_PWD_INVALID_VOLTAGE          = 23, //!< Invalid voltage value - Fin, PulseWidth can't trust
        _PINSTA_ERRMM                        = 24, //!< PIN current value can't read - error on Mini-Module
        _PINSTA_INPUT_RANGE                  = 25, //!< CIO-Setting: PWD value out of range / ADC value out of range
        _PINSTA_INPUT_SENSOR                 = 26, //!< CIO-Setting: ADC sensor supply check error
        _PINSTA_SEQUENCE                     = 27, //!< PIN functions called in wrong sequence
        _PINSTA_PWM_PERIOD                   = 28, //!< PWM pulse length/ period mismatch
        _PINSTA_BUSY                         = 29, //!< Pin diagnosis busy determining status
        _PINSTA_EXTENDED                     = 30, //!< Extended pin status is available
        _PINSTA_NA                           = 31  //!< PIN Status a not applicable [5 Bits]
    };

    //! CAN bit rate
    enum
    {
        _CAN_RATE_5K    =    5,     //!<    5 kBaud
        _CAN_RATE_10K   =   10,     //!<   10 kBaud
        _CAN_RATE_20K   =   20,     //!<   20 kBaud
        _CAN_RATE_25K   =   25,     //!<   25 kBaud
        _CAN_RATE_33K   =   33,     //!<   33 kBaud
        _CAN_RATE_47K   =   47,     //!<   47 kBaud
        _CAN_RATE_50K   =   50,     //!<   50 kBaud
        _CAN_RATE_83K   =   83,     //!<   83 kBaud
        _CAN_RATE_95K   =   95,     //!<   95 kBaud
        _CAN_RATE_100K  =  100,     //!<  100 kBaud
        _CAN_RATE_125K  =  125,     //!<  125 kBaud
        _CAN_RATE_250K  =  250,     //!<  250 kBaud
        _CAN_RATE_500K  =  500,     //!<  500 kBaud
        _CAN_RATE_667K  =  667,     //!<  667 kBaud
        _CAN_RATE_800K  =  800,     //!<  800 kBaud
        _CAN_RATE_1000K = 1000,     //!< 1000 kBaud
        _CAN_RATE_2000K = 2000      //!< 2000 kBaud
    };

    //! Pin configuration
    typedef enum
    {
        PIN_FIX,                   //!< 0 - FIX PIN (Pin will be installed by Match - pin is only changeable)
        PIN_CHA,                   //!< 1 - Change Pin (Pin can be reinstalled and installed)
        PIN_OPT,                   //!< 2 - Pin can init. by the application - in the APP-INIT-phase
        PIN_BLO                    //!< 3 - Pin setting is inherited from the block
    }EAppPinCfg;

    //! Input/output types
    typedef enum
    {
        ECUTYP_ADC_NA,             //!< 0 Physic Input: Not available
        ECUTYP_ADC_D,              //!< 1 Physic Input: Digital
        ECUTYP_ADC_V,              //!< 2 Physic Input: Voltage
        ECUTYP_ADC_C,              //!< 3 Physic Input: Current
        ECUTYP_ADC_DV,             //!< 4 Physic Input: Digital/Voltage
        ECUTYP_ADC_DVC,            //!< 5 Physic Input: Digital/Voltage
        ECUTYP_ADC_DVCR,           //!< 6 Physic Input: Voltage/Current/Resistor input/Digital
        ECUTYP_ADC_VC,             //!< 7 Physic Input: Voltage/Current
        ECUTYP_ADC_VCR             //!< 8 Physic Input: Voltage/Current/Resistor input
    }EBoardIn;

    //! Pin Options
    typedef enum
    {
        ECUTYP_OUT_NA,             //!<  0 Physic Output: Not available
        ECUTYP_DOU,                //!<  1 Physic Output: Digital (pure output)
        ECUTYP_DOU_FV,             //!<  2 Physic Output: Digital with voltage feedback
        ECUTYP_DOU_FC,             //!<  3 Physic Output: Digital with current feedback
        ECUTYP_DOU_FCV,            //!<  4 Physic Output: Digital with voltage and current feedback
        ECUTYP_PWM,                //!<  5 Physic Output: PWM (pure output)
        ECUTYP_PWM_FV,             //!<  6 Physic Output: PWM with voltage feedback
        ECUTYP_PWM_FC,             //!<  7 Physic Output: PWM with current feedback
        ECUTYP_PVG_VOU,            //!<  8 Physic Output: PVG, VOU,
        ECUTYP_PVG_VOU_DOU_FCV     //!<  9 Physic Output: PVG, VOU, DOU with VIN & CIN Feedback
    }EBoardOut;

    //! Frequency possibility
    typedef enum
    {
        ECUFRQ_NA,                 //!< Frequency: Not available  (FIN,PUL,INC)
        ECUFRQ_PR,                 //!< Frequency: Primitive - simple
        ECUFRQ_CX                  //!< Frequency: Complex
    }EBoardFrq;

    //! Output side possibility
    typedef enum
    {
        ECUHLS_NA,                 //!< Side: not available - is a INPUT-PIN - no driver type
        ECUHLS_HIG,                //!< Side: ONLY high
        ECUHLS_LOW                 //!< Side: ONLY low
    }EBoardHls;

    //! Counter  Mode
    typedef enum
    {
        PINCNT_RISING,             //!< 0 - count on a rising edge
        PINCNT_FALLING,            //!< 1 - count on a falling edge
        PINCNT_BOTH                //!< 2 - count on a both edges
    }EAppPinCnt;

    //! Resistor possibility
    typedef enum
    {
        ECURES_NA,                 //!< Resistor: Not available
        ECURES_FIXUP,              //!< Resistor: Fix "Pull Up"
        ECURES_FIXDO,              //!< Resistor: Fix "Pull Down"
        ECURES_CHAUD               //!< Resistor: Changeable "Pull Down" or "Pull Up"
    }EBoardRes;

    #ifdef COMPILER_SWITCH_TAR_PC
    //! Emulation Mode for Output Pins
    typedef enum
    {
        EMULMODE_FB_OUT_STA_IN,     //! 0 - Feedback values are set internally (output); pin status is set externally (input)
        EMULMODE_FB_CAL_STA_IN,     //! 1 - Feedback values are calculated internally (output); pin status is set externally (input)
        EMULMODE_FB_IN_STA_IN,      //! 2 - Feedback values and pin status are set externally (inputs)
        EMULMODE_FB_IN_STA_OUT      //! 3 - Feedback values are set externally (input); pin status is (based on feedback values) determined internally (output)
    } EPinEmulMode;
    #endif //COMPILER_SWITCH_TAR_PC

    // COMMON
    #define PIN_CFG 0xFFFF               	//!< Pin not configuration

    // for the Pining page
    #define CFG_NA			0xFF      		//!< Configuration is not possible

    #define PINTHR_NA      	(U16_MAX)     	//!< Threshold is not possible

    #define PINFB_NA       	(U8_MAX)      	//!< No feedback PIN

    #define PINPWM_NA      	(U16_MAX)    	//!< PWM is not possible
    #define PINPWM_DFLT  	(U16_MAX-1)     //!< PWM frequency have the default value

#endif // __ITFCOREBOARDBASIC__
