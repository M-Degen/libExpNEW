//**************************************************************************************************
/*!
@file       ItfCorePinTtc2xxx.h
@brief      PIN Interface for TTC2xxx
@date       23.10.2020
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPINTTC2XXX_H__
#define __ITFCOREPINTTC2XXX_H__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>

  #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX

    //! Board possibility
    typedef struct
    {
         EBoardIn    eTypeIn;        //!< [DEF]  Input
         EBoardRes   eTypeInDinRes;  //!< [DEF]  Resistor
         EBoardFrq   eTypeInFrq;     //!< [DEF]  Frequency
         EBoardOut   eTypeOut;       //!< [DEF]  Output
         EBoardHls   eTypeOutSide;   //!< [DEF]  High side/low side
         TUint8      u8OutCurMax;    //!< [A/10] Maximum current on output PIN
    }TBoardOptions;

    //! Adc types
    typedef enum
    {// RANGE  0 - 32767
        // === Digital Inputs ===
        ADC_DIN_D = _ADC_DIN_D,                 //!< [DEF]    Digital value
        ADC_DIN_S = _ADC_DIN_S,                 //!< [DEF]    Digital value status
        // === Voltage ===
        ADC_VIN_V = _ADC_VIN_V,                 //!< [mV]     Analogue in voltage
        ADC_VIN_S = _ADC_VIN_S,                 //!< [DEF]    Analogue in voltage status
        ADC_VIN_D = _ADC_VIN_D,                 //!< [DEF]    Digital value (deduced over the threshold [core feature])
        // === RES ===
        ADC_RES_R = _ADC_RES_R,                 //!< [Ohm]    Analogue in resistor
        ADC_RES_S = _ADC_RES_S,                 //!< [DEF]    Analogue in resistor status
        // === Current ===
        ADC_CIN_C = _ADC_CIN_C,                 //!< [µA]     Analogue in current mode
        ADC_CIN_S = _ADC_CIN_S,                 //!< [DEF]    Analogue in current status
        ADC_CIN_D = _ADC_CIN_D,                 //!< [DEF]    Digital value (deduced over the threshold [core feature])
        // === Counter ===
        ADC_COUNTER = _ADC_COUNTER,             //!< [cnt]   Counter value
        ADC_COUNTER_S = _ADC_COUNTER_S,         //!< [DEF]   Counter value status
        ADC_COUNTER_V = _ADC_COUNTER_V,         //!< [mV]    Analogue voltage on the PIN
        // === Complex ===
        ADC_CPX_F = _ADC_CPX_F,                 //!< [Hz]    Frequency
        ADC_CPX_S = _ADC_CPX_S,                 //!< [Hz]    Frequency status
        ADC_CPX_V = _ADC_CPX_V,                 //!< [mV]    Analogue in voltage mode
        ADC_CPX_HT = _ADC_CPX_HT,               //!< [µs]    Pulse length
                                                //!<            [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                //!<            [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        ADC_CPX_C = _ADC_CPX_C,                 //!< [µA]    Current feedback
        // === Increment ===
        ADC_INC_CNT   = _ADC_INC_CNT,           //!< [cnt]   Increment value - two PIN solution
        ADC_INC_S     = _ADC_INC_S,             //!< [cnt]   Increment value - status
        ADC_INC_MAS_V = _ADC_INC_MAS_V,         //!< [cnt]   Increment value - master PIN voltage
        ADC_INC_SLA_V = _ADC_INC_SLA_V,         //!< [cnt]   Increment value - slave PIN voltage
        // ===  PWM Outputs ===
        ADC_PWM_I_MAX  = _ADC_PWM_I_MAX,        //!< [A/10]  Maximum current on PWM output
        ADC_PWM_OUT_DC = _ADC_PWM_OUT_DC,       //!< [DEF]   Give the set duty cycle (must call after DAC_PWM_D/DC)
        ADC_PWM_S      = _ADC_PWM_S,            //!< [DEF]   PIN status (must call after DAC_PWM_D/DC)
        ADC_PWM_C      = _ADC_PWM_C,            //!< [mA/10] Actual current
        ADC_PWM_CS     = _ADC_PWM_CS,           //!< [DEF]   Actual current PIN status (must call after ADC_PWM_C)
        ADC_PWM_C_FRESH = _ADC_PWM_C_FRESH,     //!< [DEF]   Actual current is fresh (must call after ADC_PWM_C)
        ADC_PWM_V      = _ADC_PWM_V,            //!< [mV]    Voltage for the channel
        // === Digital Output ===
        ADC_DOU_OUT_D  = _ADC_DOU_OUT_D,        //!< [DEF]   Give the set DOU value (Bsp feature [driver feedback])
        ADC_DOU_S      = _ADC_DOU_S,            //!< [DEF]   PIN status  (from last DAC-Call)
        ADC_DOU_V      = _ADC_DOU_V,            //!< [mV]    Channel digital voltage
        ADC_DOU_C_FRESH = _ADC_DOU_C_FRESH,     //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)
        ADC_DOU_C       = _ADC_DOU_C,           //!< [mA/10] Actual current measurement    -> ( Low side PIN only )
        ADC_DOU_CS      = _ADC_DOU_CS,          //!< [DEF]   Status on current measurement -> ( Low side PIN only )
        // === LED Output ===
        ADC_LED_OUT_D  = _ADC_LED_OUT_D,        //!< [ON/OFF]  Give the set LED value
        ADC_LED_S      = _ADC_LED_S,            //!< [DEF]     PIN status
        // === PVG Output ===
        ADC_PVG_OUT_P  = _ADC_PVG_OUT_P,        //!< [%/100]   Give the set percent of Ubat [percent*100 (1500..8500)]
        ADC_PVG_S      = _ADC_PVG_S,            //!< [DEF]     PIN status ()
        ADC_PVG_OUT_V  = _ADC_PVG_OUT_V,        //!< [mV]      Measured voltage in mV. range: 0..32000 (0V..32.000V)
        // === VOU Output ===
        ADC_VOU_OUT_V  = _ADC_VOU_OUT_V,        //!< [mV]      Give the set VOU value
        ADC_VOU_S      = _ADC_VOU_S,            //!< [DEF]     PIN status
        ADC_VOU_V      = _ADC_VOU_V,            //!< [mV]      Voltage feedback

        #ifdef COMPILER_SWITCH_FAM_TTC23XX
        ADC_EOU_OUT_DC = _ADC_EOU_OUT_DC,       //!< [DEF]     Emergency shut_off duty cycle set value
        ADC_EOU_S      = _ADC_EOU_S,            //!< [DEF]     Shutoff PIN status
        ADC_EOU_V      = _ADC_EOU_V,            //!< [mV]      Shutoff voltage feedback
        #endif // COMPILER_SWITCH_FAM_TTC23XX
        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX = _ADC_SYS_UB_ECU_MAX,       //!< [mV]     MAX controller power  (IMPORTENT ECU MAXIMUM SPEC RANGE)
        ADC_SYS_BAT_OPERATE = _ADC_SYS_BAT_OPERATE,     //!< [mV]     Ecu battery operating voltage [1200, 24000]
        ADC_SYS_BAT_CURRENT = _ADC_SYS_BAT_CURRENT,     //!< [mV]     Ecu battery current voltage
        ADC_SYS_K15_D = _ADC_SYS_K15_D,                 //!< [ON/OFF] Ignition
        ADC_SYS_K15_V = _ADC_SYS_K15_V,                 //!< [mV]     Ignition voltage
        ADC_SYS_SAFE_STATE = _ADC_SYS_SAFE_STATE,       //!< [ON/OFF] Safe state

        ADC_SYS_TEMP = _ADC_SYS_TEMP,                   //!< [K]      Temperature (°C = x - ADC_KELVIN_OFFSET)
        ADC_SYS_DC_MAX = _ADC_SYS_DC_MAX,               //!< [-]      Maximum duty cycle on PWM output
        ADC_SYS_REF_VOLTAGE = _ADC_SYS_REF_VOLTAGE,     //!< [mV]     Reference voltage
        ADC_SYS_SENSOR_0_V = _ADC_SYS_SENSOR_0_V,       //!< [mV]     Sensor supply voltage - todo PIN
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        ADC_SYS_SENSOR_1_V = _ADC_SYS_SENSOR_1_V,       //!< [mV]     Sensor supply Voltage - todo PIN
        ADC_SYS_SENSOR_VAR_V = _ADC_SYS_SENSOR_VAR_V,   //!< [mV]     Sensor supply Voltage - todo PIN
    #endif // COMPILER_SWITCH_FAM_TTC23XX
        ADC_SYS_SAFETY_SW_00 = _ADC_SYS_SAFTEY_SW_00,   //!< [ON/OFF] Safety switch A (internal PIN - Without enabling this signal the PWM group with that switch is 'off')
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        ADC_SYS_SAFETY_SW_01 = _ADC_SYS_SAFTEY_SW_01,   //!< [ON/OFF] Safety switch B (internal PIN - Without enabling this signal the PWM group with that switch is 'off')
    #endif // COMPILER_SWITCH_FAM_TTC23XX
        ADC_SYS_WAKEUP = _ADC_SYS_WAKEUP,               //!< [ON/OFF] WakeUp was triggered by Wakeup Pin, value doesn't change during runtime
        ADC_SYS_CAN_WAKEUP = _ADC_SYS_CAN_WAKEUP,       //!< [ON/OFF] WakeUp was triggered by CAN message, value doesn't change during runtime
        ADC_SYS_BAT_CPU_V = _ADC_SYS_BAT_CPU_V          //!< [mV]     Battery cpu, voltage
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
       ,ADC_SYS_WAKEUP_V = _ADC_SYS_WAKEUP_V            //!< [mV]     WakeUp Pin Voltage
    #endif // COMPILER_SWITCH_FAM_TTC23XX
        
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        DAC_DOU_D = _DAC_DOU_D,                        //!< [ON/OFF]       Digital output
        DAC_PWM_D = _DAC_PWM_D,                        //!< [ON/OFF]       PWM output on/off
        DAC_PWM_DC = _DAC_PWM_DC,                      //!< [0..MAX_DUTY]  PWM output in proportional values (ECU_PWM_DOU_MAX_DUTY)
        DAC_LED_D = _DAC_LED_D,                        //!< [ON/OFF]       LED output
        DAC_PVG_P = _DAC_PVG_P,                        //!< [%*100]        Percent of Ubat [percent*100 (1000..9000)]
        DAC_VOU_V = _DAC_VOU_V,                        //!< [mV]           Voltage output  [resistive loads to ground with 10kOhm or higher]
        #ifdef COMPILER_SWITCH_FAM_TTC23XX
        DAC_EOU_DC = _DAC_SYS_EMG_OUT_A,               //!< [0..MAX_DUTY] Emergency out, implemented with dutycycle
        #endif // COMPILER_SWITCH_FAM_TTC23XX
        // === ECU board info ===
        // No channel - only system group
        DAC_SYS_K15 = _DAC_SYS_K15,                    //!< [ON/OFF] K15
        DAC_SAFE_STATE = _DAC_SAFE_STATE,              //!< [ON/OFF] Safe state
        DAC_SYS_WAKEUP = _DAC_SYS_WAKEUP,              //!< [ON/OFF] Wake Up, for power down after a wake up (Not supported!)

        DAC_SYS_SENSOR_0_D = _DAC_SYS_SENSOR_0_D,      //!< [ON/OFF] Switch the sensor supply
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        DAC_SYS_SENSOR_1_D = _DAC_SYS_SENSOR_1_D,      //!< [ON/OFF] Switch the sensor supply
        DAC_SYS_SENSOR_VAR_V = _DAC_SYS_SENSOR_VAR_V,  //!< [VAL_SENSOR_VAR_x] Switch the sensor supply
    #endif // COMPILER_SWITCH_FAM_TTC23XX        
        DAC_SYS_SAFETY_SW_00 = _DAC_SYS_SAFTEY_SW_00,  //!< [ON/OFF] Safety switch A (internal PIN - without enabling this signal the PWM group with that switch is 'off')
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        DAC_SYS_SAFETY_SW_01 = _DAC_SYS_SAFTEY_SW_01   //!< [ON/OFF] Safety switch B (internal PIN - without enabling this signal the PWM group with that switch is 'off')
    #endif // COMPILER_SWITCH_FAM_TTC23XX
    }EDacTyp;

    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX         //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15                //!< Start of DAC system output

    #ifdef COMPILER_SWITCH_FAM_TTC23XX
    enum // Values for the DAC_SYS_SENSOR_VAR_V
    {
        VAL_SENSOR_VAR_OFF,                             //!< [DEF] - Sensor supply is   OFF
        VAL_SENSOR_VAR_5V =  5000U,                     //!< [DEF] - Sensor supply have 5V
        VAL_SENSOR_VAR_6V =  6000U,                     //!< [DEF] - Sensor supply have 6V
        VAL_SENSOR_VAR_7V =  7000U,                     //!< [DEF] - Sensor supply have 7V
        VAL_SENSOR_VAR_8V =  8000U,                     //!< [DEF] - Sensor supply have 8V
        VAL_SENSOR_VAR_9V =  9000U,                     //!< [DEF] - Sensor supply have 9V
        VAL_SENSOR_VAR_10V= 10000U,                     //!< [DEF] - Sensor supply have 10V
        VAL_SENSOR_VAR_11V= 11000U,                     //!< [DEF] - Sensor supply have 11V
        VAL_SENSOR_VAR_12V= 12000U                      //!< [DEF] - Sensor supply have 12V
    };
    #endif // COMPILER_SWITCH_FAM_TTC23XX

    #define PINSTA_BSP_OFFSET 0x80

    //! PIN Status
    typedef enum
    {
        PINSTA_OK                           = _PINSTA_OK,         //!< PIN is OK
        PINSTA_OPEN                         = _PINSTA_OPEN,       //!< PIN is open
        PINSTA_SCGND                        = _PINSTA_SCGND,      //!< PIN is short circuit to ground
        PINSTA_SCPOW                        = _PINSTA_SCPOW,      //!< PIN is short circuit to power
        PINSTA_UNDEF                        = _PINSTA_UNDEF,      //!< PIN is undefined ( no PIN update since ecu start )
        PINSTA_ERRINIT                      = _PINSTA_ERRINIT,    //!< PIN not installed / PIN don't support the request
        PINSTA_ERRUNDEF                     = _PINSTA_ERRUNDEF,   //!< PIN status in undefined error
        PINSTA_ERRINUSED                    = _PINSTA_ERRINUSED,  //!< Output PIN has been used in that cycle
        PINSTA_PROTECTION                   = _PINSTA_PROTECTION, //!< PIN in a protection mode
        PINSTA_PROTECTION_REE               = _PINSTA_PROTECTION_REE, //!< PIN goes from the protection mode to the change protection mode (trigger by re-enable function)
        PINSTA_PROTECTION_FIX               = _PINSTA_PROTECTION_FIX, //!< PIN is a fix protection mode
        PINSTA_SAFESTATE                    = _PINSTA_SAFESTATE,  //!< PIN is in "safe state"
        PINSTA_SWOFF_OPEN                   = _PINSTA_SWOFF_OPEN, //!< PIN 'Group-Switch' is open - switch by the application
        PINSTA_PWD_NOT_FINISHED             = _PINSTA_PWD_NOT_FINISHED, //!< PIN not enough edges to accumulate a result
        PINSTA_PWD_OVERFLOW                 = _PINSTA_PWD_OVERFLOW,     //!< measurement sample has been lost
        PINSTA_PWD_CURRENT_THRESHOLD_HIGH   = _PINSTA_PWD_CURRENT_THRESHOLD_HIGH, //!< Last measurement of current threshold was above 20.5mA
        PINSTA_PWD_CURRENT_THRESHOLD_LOW    = _PINSTA_PWD_CURRENT_THRESHOLD_LOW,  //!< Last measurement of threshold was under 4.5mA
        PINSTA_PWD_INVALID_VOLTAGE          = _PINSTA_PWD_INVALID_VOLTAGE, //!< Invalid voltage value - cpx frequency val (u32PulseWidth, u16Fin) a valid!
        PINSTA_INPUT_RANGE                  = _PINSTA_INPUT_RANGE,  //!< Voltage or current below valid operating range / ADC value out of range
        PINSTA_INPUT_SENSOR                 = _PINSTA_INPUT_SENSOR, //!< CIO-Setting: ADC sensor supply check error
        PINSTA_SEQUENCE                     = _PINSTA_SEQUENCE,   //!< PIN functions called in wrong sequence. Function has been called to often.
        PINSTA_PWM_PERIOD                   = _PINSTA_PWM_PERIOD, //!< PWM period mismatch, probably caused by a short to another signal source
        PINSTA_BUSY                         = _PINSTA_BUSY,       //!< PIN diagnosis busy determining status or last set output not yet applied
        PINSTA_EXTENDED                     = _PINSTA_EXTENDED,   //!< Extended pin status is available
        PINSTA_NA                           = _PINSTA_NA,         //!< PIN Status a not applicable [5 Bits]
        // Extended pin status
        PINSTA_OPEN_STARTUP                 = PINSTA_BSP_OFFSET + _PINSTA_OPEN,        //!< [129] Open-load detected during startup tests. [extended]
        PINSTA_SCGND_STARTUP                = PINSTA_BSP_OFFSET + _PINSTA_SCGND,       //!< [130] Short-to-ground detected during startup tests. [extended]
        PINSTA_SCPOW_STARTUP                = PINSTA_BSP_OFFSET + _PINSTA_SCPOW,       //!< [131] Short-to-battery detected during startup tests. [extended]
        PINSTA_SCOTHER_STARTUP              = PINSTA_BSP_OFFSET + _PINSTA_UNDEF,       //!< [132] Short to other signal source detected during startup tests. [extended]
        PINSTA_RSO_STARTUP                  = PINSTA_BSP_OFFSET + _PINSTA_ERRINIT,     //!< [133] RSO pin error detected during startup tests. [extended]
        PINSTA_FM_FAULT                     = PINSTA_BSP_OFFSET + _PINSTA_ERRUNDEF,    //!< [134] Severe malfunction detected in the measurement mechanism [extended]
        PINSTA_STARTUP                      = PINSTA_BSP_OFFSET + _PINSTA_SEQUENCE,    //!< [155] The PWM driver is in the startup state waiting for the completion of the startup tests.
                                                                                       //!<       User control over the digital outputs is disabled. [extended]
        PINSTA_PWM_PULSELENGTHENED          = PINSTA_BSP_OFFSET + _PINSTA_PWM_PERIOD   //!< [156] If an open-load or short-to-battery condition is present on a PWM pin
                                                                                       //!<       possible reasons: PWM HS short to battery or open load
                                                                                       //!<                         PWM LS short to ground or open load,
                                                                                       //!                          short circuit to other signal source
                                                                                       //!<       can only be distinguished with a duty cycle setting to 0
    }EPinStatus;

    //! Defines the counter behavior
    typedef enum
    {
        FIN_INC_COUNT_A,                   //! Counts up/down on any edge of channel A
        FIN_INC_COUNT_B,                   //! Counts up/down on any edge of channel B
        FIN_INC_COUNT_BOTH                 //! Counts up/down on any edge of the two inputs
    }EFinIncMode;

    //! Defines threshold
    typedef enum
    {
        FIN_THR_THRESH_1_25V,               //!< Switch threshold 1.25V
        FIN_THR_THRESH_2_5V                 //!< Switch threshold 2.5V
    }EFinThrHold;

    //! Pull up/down interface
    typedef enum
    {
        FIN_RES_WEAK_PU     = PINRES_PULLUP_WEAK,              //!< weak pull up
        FIN_RES_STRONG_PU   = PINRES_PULLUP_STRONG,            //!< strong pull up
        FIN_RES_WEAK_PD     = PINRES_PULLDO_WEAK,              //!< weak pull down
        FIN_RES_CL          = PINRES_PULLCUR_LOOP,             //!< current loop mode, TBD
        FIN_RES_NA          = PINRES_NA                        //!< default/not applicable to pin
    } EFinResistor;

    //!Inc Init Setting
    typedef struct
    {
        EFinIncMode   eMode;                //!< [ENU] Defines the counter behavior
        TUint16       u16CountInit;         //!< [NUM] Initial value of incremental counter (0..65535)
        EFinResistor  eRes;                 //!< [ENU] Resistor
    }TFinIncInit;

    //!Inc Value
    typedef struct
    {
        TBoolean    boFresh;                //!< [Bit] PIN value is fresh
        EPinStatus  ePinSta;                //!< [ENU] PIN status (NOTE: If the status is OK the struct value are update.
                                            //!<                         If the status isn't OK, the old value are hold.)
        TUint32     u32Cnt;                 //!< [NUM] Value of the incremental counter (0..16777215)
        TUint16     u16VinMas;              //!< [mV]  ADC value channel 0, Range: 0-5000 (0-5V)
        TUint16     u16VinSla;              //!< [mV]  ADC value channel 1, Range: 0-5000 (0-5V)
    }TFinIncValue;

    //! Pulse high time
    typedef enum
    {
        FIN_PULS_HIGH_TIME,                 //!< configuration to measure pulse high time
        FIN_PULS_LOW_TIME,                  //!< configuration to measure pulse low time
        FIN_PULS_PERIOD_TIME                //!< configuration to measure pulse high and low time (period)
    }EFinPulsMode;

     //! Specify the variable edge
    typedef enum
    {
        FIN_FREQ_RISING_VAR,               //!< rising edge is variable this means, frequency is measured on falling edges
        FIN_FREQ_FALLING_VAR               //!< falling edge is variable this means, frequency is measured on rising edges
    }EFinFreqMode;

     //! Specify the timer resolution
    typedef enum
    {
        FIN_TIM_RESOLUTION_0_125,           //!< 0.125us
        FIN_TIM_RESOLUTION_1_0              //!< 1.0  us
    }EFinTimRes;

    //! FIN complex Init setting
    typedef struct
    {
        EFinFreqMode    eFreqMode;          //!< [ENU] Specify the variable edge
        TUint8          u8CaptCnt;          //!< [NUM] Number of frequency/pulse-width measurements that will be accumulated (1...8)
        EFinResistor    eResistor;          //!< [ENU] Pull up/down interface
        EFinTimRes      ePinTimRes;         //!< [ENU] Timer resolution, default FIN_TIM_RESOLUTION_1_0
    }TFinCpxInit;

    //! Complex Value
    typedef struct
    {
        TBoolean   boFresh;                 //!< [Bit]  PIN value is fresh
        EPinStatus ePinSta;                 //!< [ENU]  PIN status (NOTE: If the status is OK the struct values are updated.
                                            //!<                          If the status isn't OK, the old values are [partially] hold.)
        TUint16    u16Fin;                  //!< [Hz] Accumulated frequency
        TUint32    u32PulseWidth;           //!< [µs]   Accumulated pulse-width
        TUint16    u16Vin;                  //!< [mV]   Feedback Voltage
        TUint16    u16FinMilliPart;         //!< [Hz/1000] Accumulated frequency - only the milli part [u16Fin,u16FinMilliPart hz]
        TUint32    u32Period;               //!< [µs]   Period
        TUint32    u32Cin;                  //!< [µA]   current feedback
        EPinStatus eCinSta;                 //!< [ENU]  pin status for current feedback channel
        TBoolean   boCinFresh;              //!< [Bit]  current feedback value is fresh
    }TComplexVal;

    //! Voltage resolution

    //! VIN range
    typedef enum
    {
        VIN_RANGE_NA,   //!<  NA
        VIN_RANGE_5V,   //!<  5V
        VIN_RANGE_32V   //!< 32V
    }EVinRange;

    //! Voltage supply
    typedef enum
    {
        VIN_PINSUPPLY_NA = PINSUPPLY_NA        //!< NA
        ,VIN_PINSUPPLY_S0 = PINSUPPLY_S0       //!< Sensor Supply S0
    #ifdef COMPILER_SWITCH_FAM_TTC23XX

        ,VIN_PINSUPPLY_S1 = PINSUPPLY_S1       //!< Sensor Supply S1
        ,VIN_PINSUPPLY_S2 = PINSUPPLY_S2       //!< Sensor Supply S2
    #endif // COMPILER_SWITCH_FAM_TTC23XX
    }EVinSupply;

    //! Din range
    typedef enum
    {
        DIN_RANGE_NA,   //!<  NA
        DIN_RANGE_5V,   //!<  5V
        DIN_RANGE_32V   //!< 32V
    }EDinRange;


    //! Power-PIN
    typedef enum
    {
        POW_SAFTEY_SW_00,       //!< 0 - Safety switch 00   (internal PIN - without enabling this signal the PWM group with that switch is 'off')
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        POW_SAFTEY_SW_01        //!< 1 - Safety switch 01   (internal PIN - without enabling this signal the PWM group with that switch is 'off')
    #endif // COMPILER_SWITCH_FAM_TTC23XX
    }EPowerPin;


    //! Dou safety configuration
    typedef struct
    {
        EPin      eRsoPin;              //!< Connected low-side output for application controlled redundant-switch off path.
                                        //!< Only low-side pins configurable
        EAppPinRes ePull;               //!< Pull resistor configuration. Default: PINRES_NO_PULL
        TUint16   u16StickyTime;        //!< [ms] Status sticky time - time for which a status persists until it is healed again
                                        //!<      Default: 0, Max: 2000 ( higher sticky times are set to max value )
    }TDouSafetyCfg;

    //! PWM safety configuration
    typedef struct
    {
        EPin      eRsoPin;              //!< Connected low-side output for application controlled redundant-switch off path.
                                        //!< Only low-side pins configurable.
        EPwmDiagModeType  eDiagMode;    //!< Diagnostic mode.
        TUint16   u16StickyTime;        //!< [ms] Status sticky time - time for which a status persists until it is healed again
                                        //!<      Default: 0, Max: 2000 ( higher sticky times are set to max value )
    }TPwmSafetyCfg;

    //! ADC (Vin, Cin) & Din safety configuration
    typedef struct
    {
        TBoolean  boTestEnable;         //!< Enable startup and runtime checks for configuration switches.  (Default: FALSE)
        TUint16   u16StickyTime;        //!< [ms] Status sticky time - time for which a status persists until it is healed again
                                        //!<      Default: 0, Max: 2000 ( higher sticky times are set to max value )
    }TAdcSafetyCfg;

    //--------------------------------------------------------------------------------------------------
    //! @brief      This PIN support the counter value
    //! @param[in]  ePin     - [ENU] Ecu-PIN
    //! @retval     TRUE     - this PIN support the counter value
    //!             FALSE    - this PIN doesn't support the counter value
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreFinCpxHaveCntVal( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set ecu output power stages and the safety switch status
    //! @param[in]  boOn       On:ON or Off: OFF
    //! @retval     R_OKAY     success
    //! @retval     R_UNKNOWN  no success
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetEcuOutPowSta( TBoolean boOn );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get ecu output power status
    //! @param[out] pboSta  On:ON or Off: OFF
    //! @retval     R_OKAY     success
    //! @retval     R_UNKNOWN  no success
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetEcuOutPowSta( TBoolean *pboSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Allows an application driven safe state
    //!             When this function is called the ecu enters the safe state.
    //! @retval     R_OKAY       - everything fine
    //! @retval     R_UNKNOWN    - unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreEnterSafeState( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Is the Ecu in a safe state?
    //! @param[out] pePin           - PIN_NA: the reason isn't a PIN, ELSE e.g PIN_102: the PIN-Enum
    //! @param[out] peSta           - the PIN reason
    //! @retval     TRUE            - ECU is in 'safe state'
    //! @retval     FALSE           - ECU isn't in 'safe state'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreSafeStateAct( EPin *pePin, EPinStatus *peSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Get Adc value
    //! @note        a. Request of a adc value e.g. ADC_DOU_C give the Dou current on the value pointer back and the
    //!                 PIN status of Dou current as the return value
    //!              b. Request of a status e.g ADC_DOU_CS give the status on the value pointer back and as a return value
    //! @param[in]   eAdcType   - [ENU] ADC type selector
    //! @param[in]   ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[out]  pu16Val    - [VAL] Value - is new if the Fresh-Flag is 'TRUE'
    //!                                         else hold the last value (with Fresh-Flag='TRUE')
    //! @param[out]  pboFresh   - [DEF] Fresh flag
    //! @return      EPinStauts - [ENU] PIN status
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinFreshFb( EAdcTyp eAdcType, EPin ePin, TUint16 *pu16Val, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get adc extended value fresh feedback
    //! @note       a. Request of a adc value e.g. ADC_DOU_C give the Dou current on the value pointer back and the
    //!                PIN status of Dou current as the return value
    //!             b. Request of a status e.g ADC_DOU_CS give the status on the value pointer back and as a return value
    //!             Supported extended values (all other values are only 16Bit values (the max is U16_MAX))
    //!               ADC_CPX_HT, ADC_RES_R, ADC_PWM_C, ADC_COUNTER, ADC_INC_CNT
    //! @param[in]  eAdcType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[out] pu32Val    - [VAL] Value - is new if the fresh flag is 'TRUE'
    //!                                        else hold the last value (with Fresh-Flag='TRUE')
    //! @param[out] pboFresh   - [DEF] Fresh flag
    //! @retval     EPinStatus - [ENU] PIN status
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinExtFreshFb( EAdcTyp eAdcType, EPin ePin, TUint32 *pu32Val, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Adc value - simple
    //! @param[in]  eAdcType   - [ENU] ADC selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @retval     PIN status - [ENU] is the PINSTA convert to a U16-Value (e.g ADC_PWM_S)
    //! @retval     Adc value  - [VAL] if the PINSTA == PINSTA_OK give the ADC value (e.g ADC_PWM_C)
    //! @retval                  [ERR] if the PINSTA != PINSTA_OK the value is 0
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreAdcGetPin( EAdcTyp eAdcType, EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get an extended Adc "u32" value - simple
    //!             Supported values (all other values are only 16Bit values (the max is U16_MAX))
    //!               ADC_CPX_HT, ADC_RES_R, ADC_PWM_C, ADC_COUNTER, ADC_INC_CNT
    //! @param[in]  eAdcType   - [ENU] ADC selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @return     Adc value  - [VAL] if the PINSTA == PINSTA_OK give the ADC value (e.g ADC_PWM_C)
    //! @retval                  [ERR] if the PINSTA != PINSTA_OK the value is 0
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreAdcGetPinExt( EAdcTyp eAdcType, EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Adc status
    //! @param[in]  eAdcType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @retval     PIN Status - [ENU] PIN status
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinSta( EAdcTyp eAdcType, EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Re-initialize a incremental interface
    //! @param[in]  ePin           - [ENU] Ecu-Inc-PIN
    //! @param[in]  ptIncInit      - [STU] Init structure
    //! @retval     R_OKAY         - OK
    //! @retval     R_RANGE        - ePIN not in rang - PIN number not there
    //! @retval     R_CONFIG       - ePin isn't a 'complex FIN PIN'
    //! @retval     R_PARAMETER     - wrong parameter
    //! @retval     R_INCONSISTENT - Fin can't be re-init, because a de-init it not possible
    //! @retval     R_NULL_POINTER - pointer of ptCpxInit is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCorePinReInitFinInc( EPin ePin, TFinIncInit *ptIncInit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Adc incremental interface
    //! @param[in]  ePin           - [ENU] Ecu-Inc-PIN (MASTER-PIN)
    //! @param[in]  ptVal          - [STU] Init structure
    //! @retval     R_OKAY         - OK
    //!             R_UNKNOWN      - ptVal has an error  -> all values are invalid (BSP-function is called)
    //!             R_CONFIG       - wrong configuration -> Incorrect PIN (NO BSP-function is called)
    //! @retval     R_NULL_POINTER - pointer of ptCpxInit is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreAdcGetPinFinInc( EPin ePin, TFinIncValue *ptVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Adc value of a complex frequency input
    //! @brief      TTC2XXX -> eStaPin=> PINSTA_OK, PINSTA_PWD_NOT_FINISHED, PINSTA_ERRINIT
    //! @brief                          PINSTA_PWD_INVALID_VOLTAGE -> all values are valid, except the voltage value
    //! @brief                          PINSTA_ERRUNDEF            -> CPX-Value & VIN-Value are invalid
    //! @brief                tVal   => u16Fin, u32PulseWidth, u16Vin, u16FinMilliPart, u32Period
    //! @param[in]  ePin       - [ENU] Ecu complex PIN like the PINTYPE_FIN
    //! @param[out] ptVal      - [STU] Get the complex value struct back
    //! @retval     R_OKAY         - access is OK        -> check in addition the 'ptVal->ePinSta' status [PIN_OKAY, PINSTA_PWD_xxx]
    //!             R_UNKNOWN      - ptVal has an error  -> all values are invalid (BSP-function is called)
    //!             R_CONFIG       - wrong configuration -> Incorrect PIN (NO BSP-function is called)
    //! @retval     R_NULL_POINTER - pointer of ptVal is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreAdcGetPinFinCpx( EPin ePin, TComplexVal* ptVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get current feedback from the complex pin
    //! @param[in]  ePin         - [ENU] 23xx: PIN_AC4-PIN_AF3, 2038: PIN_G4/F4
    //! @param[out] pu32Cin      - [VAL] current [µA] (optional)
    //! @param[out] pboFresh     - [VAL] fresh        (optional)
    //! @retval     PINSTA_OK
    //! @retval     PINSTA_PROTECTION
    //! @retval     PINSTA_PROTECTION_REE
    //! @retval     PINSTA_PROTECTION_FIX
    //! @retval     PINSTA_PWD_CURRENT_THRESHOLD_HIGH
    //! @retval     PINSTA_PWD_CURRENT_THRESHOLD_LOW
    //! @retval     PINSTA_ERRUNDEF
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinFinCpxCin( EPin ePin, TUint32 *pu32Cin, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set 'Counter' for a pin from type Cnt
    //! @param[in]  ePin       - pin
    //! @param[in]  u16Counter - counter value(only 0 supported currently)
    //! @retval     R_OKAY      - okay
    //! @retval     R_RANGE     - invalid ePin value
    //! @retval     R_CONFIG    - Wrong Pin configuration
    //! @retval     R_PARAMETER - u16Counter != 0
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetCounterOfPinCnt( EPin ePin, TUint16 u16Counter );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set 'counter' for a pin of type inc
    //! @param[in]  ePin       - pin(Channel A or Channel B)
    //! @param[in]  u32Counter - Counter value
    //! @retval     R_OKAY     - okay
    //! @retval     R_CONFIG   - Wrong PIN configuration
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetCounterOfPinInc( EPin ePin, TUint32 u32Counter );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DAC PIN
    //! @param[in]  eDacType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[in]  u16Val     - [...] Set value
    //! @param[out] pboFresh   - [...] Fresh feedback
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreDacSetPinFreshFb( EDacTyp eDacType, EPin ePin, TUint16 u16Val, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DAC PIN
    //! @param[in]  eDacType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu PIN or system PIN
    //! @param[in]  u16Val     - [...] Set value
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreDacSetPin( EDacTyp eDacType, EPin ePin, TUint16 u16Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get from a ePin the PWM shut off group
    //! @param[in]  ePin         - PIN
    //! @param[out] peShutOffGrp - the shut-off-group [Pointer address is NULL return FALSE]
    //! @return     TRUE = have a shut-off-group, FALSE = have no shut-off-group
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreGetPwmShutOffGrp( EPin ePin, EPowerPin *peShutOffGrp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the power state / is a function wrapper for eCoreDacSetPin( ..., PIN_SYS, boOn )
    //! @param[in]  ePin - power PIN
    //! @param[in]  boOn - FALSE,TRUE
    //! @retval     R_OKAY      - everything fine
    //! @retval     R_UNKNOWN   - not fine -> use eCoreDacSetPin( ..., PIN_SYS, boOn ) for more information
    //! @retval     R_BUSY      - switch diagnosis is busy
    //! @retval     R_NOACT     - function called to often
    //! @retval     R_NOT_INITIALIZED - switch has not been initialized
    //! @retval     R_SUPPORT   - don't support the pin
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetPowerPinState( EPowerPin ePin, TBoolean boOn );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the power state / is a function wrapper for eCoreAdcGetPinFreshFb( ..., PIN_SYS, &u16Val, NULL )
    //! @param[in]  ePin  - power PIN
    //! @param[out] pboOn - TRUE  = switch is 'ON'  - everything OK
    //!                     FALSE = switch is 'OFF' - no OK
    //! @retval     R_OKAY      - everything fine
    //! @retval     R_UNKNOWN   - not fine -> use eCoreAdcGetPinFreshFb( ..., PIN_SYS, &u16Val, NULL ) for more information
    //! @retval     R_BUSY      - switch diagnosis is busy
    //! @retval     R_NOACT     - function called to often
    //! @retval     R_NOT_INITIALIZED - switch has not been initialized
    //! @retval     R_SUPPORT   - don't support the pin
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetPowerPinState( EPowerPin ePin, TBoolean *pboOn );

    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @brief  Suppress the internal ecu PIN control logic. E.g. the SafeState reaction of all PIN's
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSimSuppressEcuLogic( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set Adc Value with fresh flag - a bypass for the simulation [only for the PC-VERSION]
        //! @param[in]  eAdcType   [ENUM]               - ADC type selector
        //! @param[in]  ePin       [PIN_xxx/EAdcSysPin] - Ecu-PIN or system PIN
        //! @param[in]  u16Val      Value
        //! @param[in]  boFresh     boFresh
        //! @return     R_OKAY/R_RANGE
        //! Note:       If ADC_VIN_D force to 'FALSE' and ADC_VIN_V is reading the value is the u16DinThrLo (indirect influence)
        //!             If ADC_VIN_D force to 'TRUE'  and ADC_VIN_V is reading the value is the u16DinThrHi (indirect influence)
        //!             If ADC_VIN_V force to 'x'     and ADC_VIN_D is reading the value is an deduced over the threshold (indirect influence)
        //!             If ADC_CIN_D force to 'FALSE' and ADC_CIN_V is reading the value is the u16DinThrLo (indirect influence)
        //!             If ADC_CIN_D force to 'TRUE'  and ADC_CIN_V is reading the value is the u16DinThrHi (indirect influence)
        //!             If ADC_CIN_V force to 'x'     and ADC_CIN_D is reading the value is an deduced over the threshold (indirect influence)
        //!             All other force value have no indirect influence
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimAdcSetPinFresh( EAdcTyp eAdcType, EPin ePin, TUint16 u16Val, TBoolean boFresh );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set Adc value - a bypass for the simulation [only for the PC-VERSION]
        //! @brief      call eCoreSimAdcSetPinFresh( eAdcType, ePin, TRUE )
        //! @param[in]  eAdcType   - [ENU] ADC type selector
        //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
        //! @param[in]  u16Val     - [...] PIN value
        //! @retval     R_OKAY
        //! @retval     R_RANGE
        //! Note:       If ADC_VIN_D force to 'FALSE' and ADC_VIN_V is reading the value is the u16DinThrLo (indirect influence)
        //!             If ADC_VIN_D force to 'TRUE'  and ADC_VIN_V is reading the value is the u16DinThrHi (indirect influence)
        //!             If ADC_VIN_V force to 'x'     and ADC_VIN_D is reading the value is an deduced over the threshold (indirect influence)
        //!             If ADC_CIN_D force to 'FALSE' and ADC_CIN_V is reading the value is the u16DinThrLo (indirect influence)
        //!             If ADC_CIN_D force to 'TRUE'  and ADC_CIN_V is reading the value is the u16DinThrHi (indirect influence)
        //!             If ADC_CIN_V force to 'x'     and ADC_CIN_D is reading the value is an deduced over the threshold (indirect influence)
        //!             All other force value have no indirect influence
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimAdcSetPin( EAdcTyp eAdcType, EPin ePin, TUint16 u16Val );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the fin complex value - a bypass for the simulation [only for the PC-VERSION]
        //! @param[in]  ePin      - [ENU] Ecu-PIN or system PIN
        //! @param[in]  ptVal     - [...] PIN value
        //! @retval     R_OKAY
        //! @retval     R_RANGE
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimAdcFinCpxSetPin( EPin ePin, TComplexVal* ptVal );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the fin incremental value - a bypass for the simulation [only for the PC-VERSION]
        //! @param[in]  ePin    - [ENU] Ecu-PIN or system PIN
        //! @param[in]  ptVal   - [...] PIN value
        //! @retval     R_OKAY
        //! @retval     R_RANGE
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimAdcFinIncSetPin( EPin ePin, TFinIncValue* ptVal );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get DAC PIN Value back - a bypass for the simulation [only for the PC-VERSION]
        //! @param[in]  eDacType   - [ENU] ADC type selector
        //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
        //! @retval     u16Val     - [...] Get the value
        //--------------------------------------------------------------------------------------------------
        extern TUint16 u16CoreSimDacGetPin( EDacTyp eDacType, EPin ePin );

        //--------------------------------------------------------------------------------------------------
        //! @brief  Install the PINs with PINSTA_OKAY/PINSTA_UNDEF  [only for the PC-VERSION]
        //! @param[in]  boUndef=TRUE  -> Install the PIN with PINSTA_UNDEF - is the case of the HW
        //!             boUndef=FALSE -> Install the PIN with PINSTA_OKAY  - is the default
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSimPinInitUndef( TBoolean boUndef );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the current feedback values for the simulation
        //! @param[in]  ePin         - [ENU]  PIN_115, PIN_139, PIN_116, PIN_140, PIN_117, PIN_141
        //! @param[in]  u16Cin       - [µA]   Current Value
        //! @param[in]  boFresh      - [DEF]  Fresh-Flag
        //! @param[in]  eSta         - [STA]  Pin-Status
        //! @retval     PINSTA_OK
        //! @retval     PINSTA_PROTECTION
        //! @retval     PINSTA_PROTECTION_REE
        //! @retval     PINSTA_PROTECTION_FIX
        //! @retval     PINSTA_PWD_CURRENT_THRESHOLD_HIGH
        //! @retval     PINSTA_PWD_CURRENT_THRESHOLD_LOW
        //! @retval     PINSTA_ERRUNDEF
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSimAdcSetPinFinCpxCin( EPin ePin, TUint16 u16Cin, TBoolean boFresh, EPinStatus eSta );

    #endif // COMPILER_SWITCH_TAR_PC

    //--------------------------------------------------------------------------------------------------
    //! @brief     Give the install PIN type back
    //! @param[in] ePin PIN
    //! @retval    PIN type
    //--------------------------------------------------------------------------------------------------
    extern EAppPinTyp eCoreGivePinType( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Deinstall the PIN (the function will check the PIN type and call the deinstall PIN function)
    //! @param[in] ePin     PIN
    //! @retval    R_OKAY   PIN is deinstall / [if the PIN is free it will return also R_OKAY]
    //! @retval    !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallDin
    //! @param[in]  ePin     PIN
    //! @param[in]  eDinRange Din range 5V or 32V
    //! @param[in]  ePinRes  Resistor ( if the resistor is fix, it is possible to use here the
    //!                                 correct resistor or PINRES_CFG_NA. PINRES_NA is not allowed )
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallDin( EPin ePin, EDinRange eDinRange, EAppPinRes ePinRes );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallDin
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallDin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eInstallRes
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallRes( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallRes
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallRes( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVin (standard threshold for ADC_VIN_D low:2000mV high:3500mV)
    //!             To change the threshold use eCoreInstallVinThr(...) instead of this function.
    //! @param[in]  ePin          PIN
    //! @param[in]  eRatioSupply  IF 'VIN_PINSUPPLY_NA' is a absolute measurement else is radiometric measurement
    //! @param[in]  eRange        Range
    //! @param[in]  eRes          Resistor position
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVin( EPin ePin, EVinSupply eRatioSupply, EVinRange eRange, EAppPinRes eRes );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVinThr
    //! @param[in]  ePin          PIN
    //! @param[in]  eRatioSupply  IF 'VIN_PINSUPPLY_NA' is a absolute measurement else is radiometric measurement
    //! @param[in]  eRange        Range
    //! @param[in]  eRes          Resistor position
    //! @param[in]  u16ThrLo [mV] Threshold low
    //! @param[in]  u16ThrHi [mV] Threshold high
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVinThr( EPin ePin, EVinSupply eRatioSupply, EVinRange eRange, EAppPinRes eRes, TUint16 u16ThrLo, TUint16 u16ThrHi );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallDin
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallVin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCin (standard threshold for ADC_CIN_D low: 5000µA high: 15000µA)
    //!             To change the threshold use eCoreInstallCinThr(...) instead of this function.
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCinThr
    //! @param[in]  ePin     PIN
    //! @param[in]  u16ThrLo Threshold low [µA]
    //! @param[in]  u16ThrHi Threshold high [µA]
    //! @retval     R_OKAY        - OK
    //! @retval     R_PIN_FIX     - PIN is fix
    //! @retval     R_CONFIG      - no PIN config
    //! @retval     R_RANGE       - incorrect threshold (e.g. u16ThrLo >= u16ThrHi)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCinThr( EPin ePin, TUint16 u16ThrLo, TUint16 u16ThrHi );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallCin
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallCin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCnt
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCnt( EPin ePin );

     //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCnt
    //! @param[in]  ePin     PIN
    //! @param[in]  ePinRes  Resistor mode
    //! @param[in]  ePinCnt  Counter mode
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCntFull( EPin ePin, EAppPinRes ePinRes, EAppPinCnt ePinCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallCnt
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallCnt( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallInc
    //! @param[in]  ePin      PIN
    //! @param[in]  ptIncInit Init struct
    //! @retval     R_OKAY    OK
    //! @retval     !R_OKAY   incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallInc( EPin ePin, TFinIncInit *ptIncInit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallInc
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallInc( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallCpx
    //! @param[in]  ePin       PIN
    //! @param[in]  ptCpxInit  Init values
    //! @retval     R_OKAY     OK
    //! @retval     !R_OKAY    incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallCpx( EPin ePin, TFinCpxInit *ptCpxInit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Re-initialize a complex  frequency input
    //! @brief      which measures at once: pulse width and frequency and
    //! @brief      depending on hardware "analog voltage" (5x, 7x, 5xx)
    //! @param[in]  ePin           - [ENU] Ecu-FIN-PIN
    //! @param[in]  ptCpxInit      - [STU] Init structure
    //! @retval     R_OKAY         - OK
    //! @retval     R_RANGE        - ePin not in rang - PIN number not there
    //! @retval     R_CONFIG       - ePin isn't a 'Complex FIN PIN'
    //! @retval     R_PARAMETER    - Wrong parameter
    //! @retval     R_INCONSISTENT - Fin can't be reinit, because a deinit it not possible
    //! @retval     R_NULL_POINTER - Pointer of ptCpxInit is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCorePinReInitFinCpx( EPin ePin, TFinCpxInit *ptCpxInit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallCpx
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallCpx( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallDou
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallDou( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallDou
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallDou( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPwm
    //! @param[in]  ePin        PIN
    //! @param[in]  u16PinFreq  PWM frequency
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPwm( EPin ePin, TUint16 u16PinFreq );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Set usage of diag mode for selected pin
    //! @details    use before pin is installed(vAppSafetyInit), setting persists after soft reset
    //! @warning    Reduces diagnostic capabilities, check block behavior
    //! @param[in]  ePin       Pin
    //! @param[in]  eDiagMode  diag mode used
    //! @retval     R_OKAY      - everything fine
    //! @retval     R_RANGE     - invalid pin(no PWM)
    //! @retval     R_CONFIG    - invalid mode
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPwmDiagMode( EPin ePin, EPwmDiagModeType eDiagMode );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallPwm
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPwm( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Install frequency from the PWM PIN!
    //! @pre        Pin has been installed as PWM pin.
    //! @param[in]  ePin     PIN
    //! @retval     frequency in Hz
    //-------------------------------------------------------------------------------------------------
    extern TUint16 u16CorePwmGetFreq( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check the PWM frequency Init value
    //! @param[in]  u16Freq  Hz
    //! @retval     TRUE     Correct frequency
    //! @retval     FALSE    Incorrect frequency
    //-------------------------------------------------------------------------------------------------
    extern TBoolean boCoreCheckPwmFreqInit( TUint16 u16Freq );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallLed
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallLed( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallLed
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallLed( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPvg
    //! @param[in]  ePin          PIN
    //! @param[in]  u16InitValue  init value [1000..9000]
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect [Init value not in range:1000..9000]
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPvg( EPin ePin, TUint16 u16InitValue );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallPvg
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPvg( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVou
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVou( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallVou
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallVou( EPin ePin );

#ifdef COMPILER_SWITCH_FAM_TTC23XX
    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallEou
    //! @param[in]  ePin           Pin
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    ERetVal eCoreInstallEou( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallEou
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    ERetVal eCoreDeInstallEou( EPin ePin );
#endif


    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the DOU PIN
    //!             Important Note: This must set in the vAppSafetyInit-function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptDou       - Safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState   - SafeState active
    //! @param[in]  boDouPinDeact - Deactivate the Dou-PIN (boSafeState must be 'FALSE')
    //!                             only for PIN_149,PIN_173,PIN_152,PIN_176,PIN_155,PIN_179,PIN_158,PIN_182 possible
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App-Phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetDouSafetyCfg( EPin ePin, TDouSafetyCfg *ptDou, TBoolean boSafeState, TBoolean boDouPinDeact );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the DOU PIN
    //!             Important Note: This function can call after eAppStartUp-function
    //! @param[in]  ePin            - PIN
    //! @param[in]  ptDou           - Safety configuration
    //! @param[in]  pboSafeState    - SafeState active
    //! @param[in]  boDouPinDeact   - Deactivate the Dou PIN (boSafeState must be 'FALSE')
    //! @retval     R_OKAY          - Fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_SUPPORT       - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                          (call it for PDT setting in or after the eAppPreStart() phase)
    //! @retval     R_NULL_POINTER  - function parameter pointer is null
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetDouSafetyCfg( EPin ePin, TDouSafetyCfg *ptDou, TBoolean *pboSafeState, TBoolean *pboDouPinDeact );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the PWM PIN
    //!             Important Note: This must set in the vAppSafetyInit-function and before the PIN install function.
    //! @param[in]  ePin     - PIN
    //! @param[in]  ptPwm    - Safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState       - SafeState active
    //! @param[in]  boShutOffGrpDeact - Deactivate the 'Shut-Off-Group', if an error is there
    //!               ShutOffGrp0: PIN_153,PIN_177,PIN_156,PIN_180,PIN_159,PIN_183,PIN_186,PIN_162,PIN_189,PIN_165,PIN_192,PIN_168,PIN_195,PIN_171
    //!               ShutOffGrp1: PIN_154,PIN_178,PIN_157,PIN_181,PIN_160,PIN_184,PIN_187,PIN_163,PIN_190,PIN_166,PIN_193,PIN_169,PIN_196,PIN_172
    //!               ShutOffGrp2: PIN_101,PIN_125,PIN_150,PIN_174,PIN_102,PIN_126,PIN_151,PIN_175
    //!                           (boSafeState must be 'FALSE')
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App-Phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetPwmSafetyCfg( EPin ePin, TPwmSafetyCfg *ptPwm, TBoolean boSafeState, TBoolean boShutOffGrpDeact );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the PWM PIN
    //!             Important Note: This function can call after eAppStartUp-function
    //! @param[in]  ePin            - PIN
    //! @param[in]  ptDou           - Safety configuration
    //! @param[in]  pboSafeState    - SafeState active
    //! @param[in]  pboPwmPinDeact  - Deactivate the Dou-PIN (boSafeState must be 'FALSE')
    //! @retval     R_OKAY          - Fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_SUPPORT       - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                          (call it for PDT setting in or after the eAppPreStart()-Phase)
    //! @retval     R_NULL_POINTER  - function parameter pointer is null
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetPwmSafetyCfg( EPin ePin, TPwmSafetyCfg *ptPwm, TBoolean *pboSafeState, TBoolean *pboShutOffGrpDeact );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Safety Configuration' setting for the Digital Input PIN
    //!             Important Note: This must set in the vAppSafetyInit function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptDin       - Safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong app phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetDinSafetyCfg( EPin ePin, TAdcSafetyCfg *ptDin, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the Digital Input PIN
    //!             Important Note: This function can call after eAppStartUp function
    //! @param[in]  ePin           - PIN
    //! @param[out] ptDin          - Safety configuration
    //! @param[out] pboSafeState   - SafeState active
    //! @retval     R_OKAY         - fine
    //! @retval     R_RANGE        - PIN to high
    //! @retval     R_CONFIG       - No from the type ADC
    //! @retval     R_SUPPORT      - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                         (call it for PDT setting in or after the eAppPreStart()-Phase)
    //! @retval     R_NULL_POINTER - Parameter pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetDinSafetyCfg( EPin ePin, TAdcSafetyCfg *ptDin, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Safety Configuration' setting for the ADC-Pin (voltage measurement)
    //!             Important Note: This must set in the vAppSafetyInit function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptAdc       - Safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong app phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetAdcVinSafetyCfg( EPin ePin, TAdcSafetyCfg *ptAdc, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the ADC PIN (voltage measurement)
    //!             Important Note: This function can call after eAppStartUp function
    //! @param[in]  ePin           - PIN
    //! @param[out] ptAdc          - Safety configuration
    //! @param[out] pboSafeState   - SafeState active
    //! @retval     R_OKAY         - fine
    //! @retval     R_RANGE        - PIN to high
    //! @retval     R_CONFIG       - No from the type ADC
    //! @retval     R_SUPPORT      - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                         (call it for PDT setting in or after the eAppPreStart()-Phase)
    //! @retval     R_NULL_POINTER - Parameter pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetAdcVinSafetyCfg( EPin ePin, TAdcSafetyCfg *ptAdc, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Safety Configuration' setting for the ADC-Pin (current measurement)
    //!             Important Note: This must set in the vAppSafetyInit function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptAdc       - Safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong app phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetAdcCinSafetyCfg( EPin ePin, TAdcSafetyCfg *ptAdc, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the ADC PIN (current measurement)
    //!             Important Note: This function can call after eAppStartUp function
    //! @param[in]  ePin           - PIN
    //! @param[out] ptAdc          - Safety configuration
    //! @param[out] pboSafeState   - SafeState active
    //! @retval     R_OKAY         - fine
    //! @retval     R_RANGE        - PIN to high
    //! @retval     R_CONFIG       - No from the type ADC
    //! @retval     R_SUPPORT      - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                         (call it for PDT setting in or after the eAppPreStart()-Phase)
    //! @retval     R_NULL_POINTER - Parameter pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetAdcCinSafetyCfg( EPin ePin, TAdcSafetyCfg *ptAdc, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the external shut off group
    //! @param[in]  boSafeState    - SafeState active [Default-Value is TRUE]
    //! @retval     R_OKAY         - Fine
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetExtShutOffGrpSafetyCfg( TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' setting for the external shut off group
    //! @param[in]  pboSafeState   - SafeState active [Default-Value is]
    //! @retval     R_OKAY         - Fine
    //! @retval     R_NULL_POINTER - Parameter pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetExtShutOffGrpSafetyCfg( TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Re-config PIN option (can use until the eAppInit() )
    //! @param[in] ePin      - PIN
    //! @param[in] u8OptNo   - Option number
    //! @retval    R_OKAY    - Is fine
    //! @retval    R_CONFIG  - Invalid configuration
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreReConfigPinOpt( EPin ePin, TUint8 u8OptNo );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Re-config PIN option for the extended part (second application)
    //! @brief     (can use until the eAppInit() )
    //! @param[in] ePin      - PIN
    //! @param[in] u8OptNo   - Option number
    //! @retval    R_OKAY    - Is fine
    //! @retval    R_CONFIG  - Invalid configuration
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreReConfigPinOptExt( EPin ePin, TUint8 u8OptNo );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Get current settings for the given application PIN
    //! @note      Returns pointer to a fixed temporary buffer containing the settings. \n
    //!            Consecutive calls of this function will overwrite last result in this buffer
    //! @param[in] ePin      - application PIN( range: PIN_SYS < ePin < PIN_MAX )
    //! @retval    !=NULL    - pointer to PIN settings
    //! @retval    NULL      - invalid pin given
    //--------------------------------------------------------------------------------------------------
    extern const TAppPin *cptAppPinSetting( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Give the all possible PIN option on that board
    //! @param[in]  ePin           - PIN
    //! @param[out] ptOpt          - Output struct
    //! @retval     R_OKAY         - fine
    //! @retval     R_RANGE        - PIN not valid
    //! @retval     R_NULL_POINTER - Output Pointer in NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBoardPinInfo( EPin ePin, TBoardOptions *ptOpt  );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Tries to reset the PIN from protection state
    //! @param[in]  ePin
    //! @param[out] pu8Cnt - Protection reset counter. Indicates how often the application already reset the protection
    //! @retval     PINSTA_OK       - ok
    //! @retval     PINSTA_ERRINIT  - invalid pin [type]
    //! @retval     PINSTA_ERRUNDEF - unknown error/system issue(e.g. os resources exhausted)
    //! @retval     PINSTA_SEQUENCE - pin is not in re-enable state(protection reset impossible)
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCorePinResetProtection( EPin ePin, TUint8 *pu8Cnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get BSP status return values
    //! @param[in]  ePin                - Pin
    //! @param[out] pu32PinStatus       - BSP pin status
    //! @retval     R_OKAY              - ok
    //! @retval     R_NULL_POINTER      - null pointer passed
    //! @retval     R_PIN               - wrong Pin Index
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCorePinGetBspStatus( EPin, TUint32 *pu32PinStatus );

  #endif // COMPILER_SWITCH_PLATFORM_TTC2XXX

#endif // __ITFCOREPINTTC2XXX_H__
