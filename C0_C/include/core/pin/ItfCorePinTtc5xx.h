//**************************************************************************************************
/*!
@file       ItfCorePinTtc5xx.h
@brief      PIN Interface
@date       14.11.2014
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPINTTC5XX__
    #define __ITFCOREPINTTC5XX__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>
    #include <ItfCoreBoardBasic.h>

  #ifdef COMPILER_SWITCH_FAM_TTC5XX

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
        ADC_DIN_D = _ADC_DIN_D,                     //!< [DEF]    Digital value
        ADC_DIN_S = _ADC_DIN_S,                                         //!< [DEF]    Digital value status
        // === Voltage ===
        ADC_VIN_V = _ADC_VIN_V,                                         //!< [mV]     Analogue in voltage
        ADC_VIN_S = _ADC_VIN_S,                                         //!< [DEF]    Analogue in voltage status
        ADC_VIN_D = _ADC_VIN_D,                                         //!< [DEF]    Digital value (deduced over the threshold [core feature])
        // === RES ===
        ADC_RES_R = _ADC_RES_R,                                         //!< [Ohm]    Analogue in resistor
        ADC_RES_S = _ADC_RES_S,                                         //!< [DEF]    Analogue in resistor status
        // === Current ===
        ADC_CIN_C = _ADC_CIN_C,                                         //!< [µA]     Analogue in current mode
        ADC_CIN_S = _ADC_CIN_S,                                         //!< [DEF]    Analogue in current status
        ADC_CIN_D = _ADC_CIN_D,                                         //!< [DEF]    Digital value (deduced over the threshold [core feature])
        // === Counter ===
        ADC_COUNTER = _ADC_COUNTER,                                     //!< [cnt]   Counter value
        ADC_COUNTER_S = _ADC_COUNTER_S,                                 //!< [DEF]   Counter value status
        ADC_COUNTER_D = _ADC_COUNTER_D,                                 //!< [mV]    Digital on the PIN (Bsp feature [driver feedback])
        // === Complex ===
        ADC_CPX_F = _ADC_CPX_F,                                         //!< [Hz]    Frequency
        ADC_CPX_S = _ADC_CPX_S,                                         //!< [Hz]    Frequency status
        ADC_CPX_V = _ADC_CPX_V,                                         //!< [mV]    Analogue in voltage mode
        ADC_CPX_HT = _ADC_CPX_HT,                                       //!< [µs]    Pulse length
                                                                        //!<            [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                                        //!<            [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        ADC_CPX_CNT = _ADC_CPX_CNT,                                     //!< [cnt]   Counter value
        ADC_CPX_C = _ADC_CPX_C,                                         //!< [µA]    Current feedback
        // === Increment ===
        ADC_INC_CNT = _ADC_INC_CNT,                                     //!< [cnt]   Increment value - two PIN solution
        ADC_INC_S  = _ADC_INC_S,                                        //!< [cnt]   Increment value - status
        ADC_INC_MAS_V = _ADC_INC_MAS_V,                                 //!< [cnt]   Increment value - master PIN voltage
        ADC_INC_SLA_V = _ADC_INC_SLA_V,                                 //!< [cnt]   Increment value - slave PIN voltage
        ADC_INC_MAS_D = _ADC_INC_MAS_D,                                 //!< [cnt]   Increment value - master PIN digital status (Bsp feature [driver feedback])
        ADC_INC_SLA_D = _ADC_INC_SLA_D,                                 //!< [cnt]   Increment value - slave PIN digital status  (Bsp feature [driver feedback])
        // ===  PWM Outputs ===
        ADC_PWM_I_MAX = _ADC_PWM_I_MAX,                                 //!< [A/10]  Maximum current on PWM output
        ADC_PWM_OUT_DC = _ADC_PWM_OUT_DC,                               //!< [DEF]   Give the set duty cycle (must call after DAC_PWM_D/DC)
        ADC_PWM_S = _ADC_PWM_S,                                         //!< [DEF]   PIN status (must call after DAC_PWM_D/DC)
        ADC_PWM_C = _ADC_PWM_C,                                         //!< [mA/10] Actual current
        ADC_PWM_CS = _ADC_PWM_CS,                                       //!< [mA/10] Actual current PIN status (must call after ADC_PWM_C)
        ADC_PWM_C_FRESH = _ADC_PWM_C_FRESH,                             //!< [DEF]   Actual current is fresh (must call after ADC_PWM_C)
        ADC_PWM_HT = _ADC_PWM_HT,                                       //!< [µs]    Pulse length (high time)(must call after DAC_PWM_D/DC)
                                                                        //!<            [only 16Bit low part:  eCoreAdcGetPinFreshFb(..)]
        ADC_PWM_PERIODE = _ADC_PWM_PERIODE,                             //!< [µs]    Period feedback for the channels
        // === Digital Output ===
        ADC_DOU_OUT_D = _ADC_DOU_OUT_D,                                 //!< [DEF]   Give the set DOU value (Bsp feature [driver feedback])
        ADC_DOU_S = _ADC_DOU_S,                                         //!< [DEF]   PIN status  (from last DAC-Call)
        ADC_DOU_V = _ADC_DOU_V,                                         //!< [mV]    Channel digital voltage
        ADC_DOU_C_FRESH = _ADC_DOU_C_FRESH,                             //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)
        ADC_DOU_C = _ADC_DOU_C,                                         //!< [mA/10] Actual current measurement    -> ( Low side PIN only )
        ADC_DOU_CS = _ADC_DOU_CS,                                       //!< [DEF]   Status on current measurement -> ( Low side PIN only )

        // === LED Output ===
        ADC_LED_OUT_D = _ADC_LED_OUT_D,                                 //!< [ON/OFF]  Give the set LED value (Bsp feature [driver feedback])
        ADC_LED_S = _ADC_LED_S,                                         //!< [DEF]     PIN status

        #ifndef COMPILER_SWITCH_ECU_TTC540
      // === PVG Output ===
        ADC_PVG_OUT_P = _ADC_PVG_OUT_P,                                 //!< [%/100]   Give the set percent of Ubat [percent*100 (1500..8500)]
        ADC_PVG_S = _ADC_PVG_S,                                         //!< [DEF]     PIN status ()
        ADC_PVG_OUT_V = _ADC_PVG_OUT_V,                                 //!< [mV]      Measured voltage in mV. range: 0..32000 (0V..32.000V)
        // === VOU Output ===
        ADC_VOU_OUT_V = _ADC_VOU_OUT_V,                                 //!< [mV]      Give the set VOU value
        ADC_VOU_S = _ADC_VOU_S,                                         //!< [DEF]     PIN status
        ADC_VOU_V = _ADC_VOU_V,                                         //!< [mV]      Voltage feedback
        #endif

        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX = _ADC_SYS_UB_ECU_MAX,                       //!< [mV]     MAX controller power  (IMPORTENT ECU MAXIMUM SPEC RANGE)
        ADC_SYS_BAT_OPERATE = _ADC_SYS_BAT_OPERATE,                     //!< [mV]     Ecu operate battery voltage [1200, 24000]
        ADC_SYS_BAT_CURRENT = _ADC_SYS_BAT_CURRENT,                     //!< [mV]     Ecu current battery voltage
        ADC_SYS_K15_D = _ADC_SYS_K15_D,                                 //!< [ON/OFF] Ignition
        ADC_SYS_SAFE_STATE = _ADC_SYS_SAFE_STATE,                       //!< [ON/OFF] Safe state [on TTC71 emulate -> all outputs off]
        ADC_SYS_POWERSTAGE_ENABLE = _ADC_SYS_POWERSTAGE_ENABLE,         //!< [ON/OFF] Internal PIN for enabling power stages
        ADC_SYS_TEMP = _ADC_SYS_TEMP,                                   //!< [K]      Temperature (°C = x - ADC_KELVIN_OFFSET)
        ADC_SYS_DC_MAX = _ADC_SYS_DC_MAX,                               //!< [-]      Maximum duty cycle on PWM output
        ADC_SYS_REF_VOLTAGE = _ADC_SYS_REF_VOLTAGE,                     //!< [mV]     Reference voltage
                                                                        //!           [TTC71 have no support -> Value:0, Pin-Status:PINSTA_ERRINIT]
        ADC_SYS_SENSOR_0_V = _ADC_SYS_SENSOR_0_V,                       //!< [mV]     Sensor supply voltage - PIN 247
        #ifndef COMPILER_SWITCH_ECU_TTC508
        ADC_SYS_SENSOR_1_V = _ADC_SYS_SENSOR_1_V,                       //!< [mV]     Sensor supply Voltage - PIN 234
        ADC_SYS_SENSOR_VAR_V = _ADC_SYS_SENSOR_VAR_V,                   //!< [mV]     Sensor supply Voltage - PIN 221
        #endif
        ADC_SYS_SAFTEY_SW_00 = _ADC_SYS_SAFTEY_SW_00,                   //!< [ON/OFF] Safety switch 00 (internal PIN - Without enabling this signal the PWM group with that switch is 'off')
        ADC_SYS_SAFTEY_SW_01 = _ADC_SYS_SAFTEY_SW_01,                   //!< [ON/OFF] Safety switch 01 (internal PIN - Without enabling this signal the PWM group with that switch is 'off')
        #ifdef COMPILER_SWITCH_ECU_TTC580
        ADC_SYS_SAFTEY_SW_02 = _ADC_SYS_SAFTEY_SW_02,                   //!< [ON/OFF] Safety switch 02 (internal PIN - Without enabling this signal the PWM group with that switch is 'off')
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC590
        ADC_SYS_SAFTEY_SW_02 = _ADC_SYS_SAFTEY_SW_02,                   //!< [ON/OFF] Safety switch 02 (internal PIN - Without enabling this signal the PWM group with that switch is 'off')
        #endif
        ADC_SYS_WAKEUP  = _ADC_SYS_WAKEUP                               //!< [ON/OFF] WakeUp, for power down after a wake up)
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        DAC_DOU_D = _DAC_DOU_D,                                         //!< [ON/OFF]       Digital output
        DAC_PWM_D = _DAC_PWM_D,                                         //!< [ON/OFF]       PWM output on/off
        DAC_PWM_DC = _DAC_PWM_DC,                                       //!< [0..MAX_DUTY]  PWM output in proportional values
        #ifdef COMPILER_SWITCH_ECU_TTC508
        DAC_LED_D = _DAC_LED_D,                                         //!< [ON/OFF]       LED output
        DAC_PVG_P = _DAC_PVG_P,                                         //!< [%/100]        Percent of Ubat [percent*100 (1000..9000)]
        DAC_VOU_V = _DAC_VOU_V,                                         //!< [mV]           Voltage output  [resistive loads to ground with 10kOhm or higher]
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC510
        DAC_LED_D = _DAC_LED_D,                                         //!< [ON/OFF]       LED output
        DAC_PVG_P = _DAC_PVG_P,                                         //!< [%/100]        Percent of Ubat [percent*100 (1000..9000)]
        DAC_VOU_V = _DAC_VOU_V,                                         //!< [mV]           Voltage output  [resistive loads to ground with 10kOhm or higher]
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC540
        DAC_LED_D = _DAC_LED_D,                                         //!< [ON/OFF]       LED output
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC580
        DAC_LED_D = _DAC_LED_D,                                         //!< [ON/OFF]       LED output
        DAC_PVG_P = _DAC_PVG_P,                                         //!< [%/100]        Percent of Ubat [percent*100 (1000..9000)]
        DAC_VOU_V = _DAC_VOU_V,                                         //!< [mV]           Voltage output  [resistive loads to ground with 10kOhm or higher]
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC590
        DAC_LED_D = _DAC_LED_D,                                         //!< [ON/OFF]       LED output
        DAC_PVG_P = _DAC_PVG_P,                                         //!< [%/100]        Percent of Ubat [percent*100 (1000..9000)]
        DAC_VOU_V = _DAC_VOU_V,                                         //!< [mV]           Voltage output  [resistive loads to ground with 10kOhm or higher]
        #endif
        // === ECU board info ===
        // No channel - only system group
        DAC_SYS_K15 = _DAC_SYS_K15,                                     //!< [ON/OFF] K15
        DAC_SAFE_STATE = _DAC_SAFE_STATE,                               //!< [ON/OFF] Safe state
                                                                        //!< [on TTC71    emulate -> all outputs off]
                                                                        //!< [on TTC50/60 emulate -> all outputs off]
        DAC_SYS_POWERSTAGE_ENABLE = _DAC_SYS_POWERSTAGE_ENABLE,         //!< [ON/OFF] Internal PIN for enabling power stages
        DAC_SYS_SENSOR_0_D = _DAC_SYS_SENSOR_0_D,                       //!< [ON/OFF] Switch the sensor supply            - PIN 247
        #ifndef COMPILER_SWITCH_ECU_TTC508
        DAC_SYS_SENSOR_1_D = _DAC_SYS_SENSOR_1_D,                       //!< [ON/OFF] Switch the sensor supply            - PIN 234
        DAC_SYS_SENSOR_VAR_V = _DAC_SYS_SENSOR_VAR_V,                   //!< [VAL_SENSOR_VAR_x] Switch the sensor supply  - PIN 221
        #endif
        DAC_SYS_SAFTEY_SW_00 = _DAC_SYS_SAFTEY_SW_00,                   //!< [ON/OFF] Safety switch 00 (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        DAC_SYS_SAFTEY_SW_01 = _DAC_SYS_SAFTEY_SW_01,                   //!< [ON/OFF] Safety switch 01 (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        #ifdef COMPILER_SWITCH_ECU_TTC580
        DAC_SYS_SAFTEY_SW_02 = _DAC_SYS_SAFTEY_SW_02,                   //!< [ON/OFF] Safety switch 02 (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC590
        DAC_SYS_SAFTEY_SW_02 = _DAC_SYS_SAFTEY_SW_02,                   //!< [ON/OFF] Safety switch 02 (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        #endif
        DAC_SYS_WAKEUP = _DAC_SYS_WAKEUP,                               //!< [ON/OFF] Wake Up, for power down after a wake up)
        DAC_PWM_DC_RESOLVE_OPEN_SCPOW = _DAC_PWM_DC_RESOLVE_OPEN_SCPOW  //!< [0..MAX_DUTY] - is like the DAC_PWM_DC - but with a better PIN status
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
    }EDacTyp;

    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX         //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15                //!< Start of DAC system output

    enum // Values for the DAC_SYS_SENSOR_VAR_V
    {
        VAL_SENSOR_VAR_OFF,                             //!< [DEF] - Sensor supply is   OFF
        VAL_SENSOR_VAR_5V,                              //!< [DEF] - Sensor supply have 5V
        VAL_SENSOR_VAR_6V,                              //!< [DEF] - Sensor supply have 6V
        VAL_SENSOR_VAR_7V,                              //!< [DEF] - Sensor supply have 7V
        VAL_SENSOR_VAR_8V,                              //!< [DEF] - Sensor supply have 8V
        VAL_SENSOR_VAR_9V,                              //!< [DEF] - Sensor supply have 9V
        VAL_SENSOR_VAR_10V                              //!< [DEF] - Sensor supply have 10V
    };

    //! PIN Status
    typedef enum
    {
        PINSTA_OK                           =  _PINSTA_OK,                          //!< PIN is OK
        PINSTA_OPEN                         =  _PINSTA_OPEN,                        //!< PIN is open
        PINSTA_SCGND                        =  _PINSTA_SCGND,                       //!< PIN is short circuit to ground
        PINSTA_SCPOW                        =  _PINSTA_SCPOW,                       //!< PIN is short circuit to power
        PINSTA_UNDEF                        =  _PINSTA_UNDEF,                       //!< PIN is undefined ( no PIN update since ecu start )
        PINSTA_ERRINIT                      =  _PINSTA_ERRINIT,                     //!< PIN not installed / PIN don't support the request
        PINSTA_ERRUNDEF                     =  _PINSTA_ERRUNDEF,                    //!< PIN status in undefined error
        PINSTA_ERRINUSED                    =  _PINSTA_ERRINUSED,                   //!< Output PIN has been used in that cycle
        PINSTA_OPEN_SCPOW                   =  _PINSTA_OPEN_SCPOW,                  //!< PIN is an open or short circuit to power
        PINSTA_PROTECTION                   =  _PINSTA_PROTECTION,                  //!< PIN in a protection mode
        PINSTA_PROTECTION_REE               =  _PINSTA_PROTECTION_REE,              //!< PIN goes from the protection mode to the change protection mode (trigger by re-enable function)
        PINSTA_PROTECTION_FIX               =  _PINSTA_PROTECTION_FIX,              //!< PIN is a fix protection mode
        PINSTA_SAFESTATE                    =  _PINSTA_SAFESTATE,                   //!< PIN is in "safe state"
        PINSTA_SWOFF_OPEN                   =  _PINSTA_SWOFF_OPEN,                  //!< PIN 'Group-Switch' is open - switch by the application
        PINSTA_PWD_NOT_FINISHED             =  _PINSTA_PWD_NOT_FINISHED,            //!< PIN not enough edges to accumulate a result
        PINSTA_PWD_OVERFLOW                 =  _PINSTA_PWD_OVERFLOW,                //!< A timer overflow occurred
        PINSTA_PWD_CURRENT_THRESHOLD_HIGH   =  _PINSTA_PWD_CURRENT_THRESHOLD_HIGH,  //!< Last measurement of current threshold was above 20.5mA
        PINSTA_PWD_CURRENT_THRESHOLD_LOW    =  _PINSTA_PWD_CURRENT_THRESHOLD_LOW,   //!< Last measurement of threshold was under 4.5mA
        PINSTA_PWD_INVALID_VOLTAGE          =  _PINSTA_PWD_INVALID_VOLTAGE,         //!< Invalid voltage value - cpx frequency val (u32PulseWidth, u16Fin) a valid!
        PINSTA_INPUT_RANGE                  =  _PINSTA_INPUT_RANGE,                 //!< CIO-Setting: PWD value out of range / ADC value out of range
        PINSTA_INPUT_SENSOR                 =  _PINSTA_INPUT_SENSOR,                //!< CIO-Setting: ADC sensor supply check error
        PINSTA_NA                           =  _PINSTA_NA                           //!< PIN Status a not applicable [5 Bits]
    }EPinStatus;

    //! Defines the counter behavior
    typedef enum
    {
        FIN_INC_TWO_COUNT,                  //! Counts up/down on any edge of the two inputs
        FIN_INC_ONE_COUNT                   //! Counts up/down on any edge of one channel
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
        FIN_RES_PU_10K,                   //!< Pull up 10 kOhm
        FIN_RES_PD_10K,                   //!< Pull down 10 kOhm
        FIN_RES_PD_90                     //!< Pull down 90 Ohm (for 7mA/14mA sensors)
    }EFinResistor;

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
        TUint16     u16Cnt;                 //!< [NUM] Value of the incremental counter (0..65535)
        TUint16     u16VinMas;              //!< [mV]  ADC value channel 0, Range: 0-5000 (0-5V)
        TUint16     u16VinSla;              //!< [mV]  ADC value channel 1, Range: 0-5000 (0-5V)
        TBoolean    boDinMas;               //!< [DEF] Digital value of PIN 0 (primary channel)
        TBoolean    boDinSla;               //!< [DEF] Digital value of PIN 1 (secondary channel)
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
        FIN_TIM_RESOLUTION_0_2,            //!< 0.2us
        FIN_TIM_RESOLUTION_0_4,            //!< 0.4us
        FIN_TIM_RESOLUTION_0_8,            //!< 0.8us
        FIN_TIM_RESOLUTION_1_6,            //!< 1.6us
        FIN_TIM_RESOLUTION_3_2             //!< 3.2us
    }EFinTimRes;

    //! FIN complex Init setting
    typedef struct
    {
        EFinPulsMode    ePulsMode;        //!< [ENU] configuration to measure pulse high time
        EFinFreqMode    eFreqMode;        //!< [ENU] Specify the variable edge
        TUint8        u8CaptCnt;          //!< [NUM] Number of frequency/pulse-width measurements that will be accumulated (1...8)
        EFinResistor  eResistor;          //!< [ENU] Pull up/down interface [FIN_RES_PD_90 - use eCoreAdcGetPinFinCpxCin(..) to get the current]
    }TFinCpxInit;

    //! Complex Value
    typedef struct
    {
        TBoolean   boFresh;                 //!< [Bit]  PIN value is fresh
        EPinStatus ePinSta;                 //!< [ENU]  PIN status (NOTE: If the status is OK the struct value are update.
                                            //!<                          If the status isn't OK, the old value are hold.)
        TUint16    u16Fin;                  //!< [Hz] Accumulated frequency
        TUint32    u32PulseWidth;           //!< [µs]        Accumulated pulse-width
        TUint16    u16Vin;                  //!< [mV]        Feedback Voltage
        TUint16    u16Cnt;                  //!< [NUM]  only for PIN_115, PIN_139, PIN_116, PIN_140, PIN_117, PIN_141
                                            //!<        -  Value of the incremental counter (Start: 0/ Rang: 0..65535)
                                            //!<        -  Note: boCoreFinCpxHaveCntVal( ePin ) can be used to get the answer if
                                            //!<                 the PIN support the counter value
                                            //!<        -  for all other PIN the value is U16_UNDEF
        TUint16    u16FinMilliPart;         //!< [Hz/1000] Accumulated frequency - only the milli part [u16Fin,u16FinMilliPart hz]

        TUint16    u16Cin;                  //!< [µA]   current feedback
        EPinStatus eCinSta;                 //!< [ENU]  pin status for current feedback channel
        TBoolean   boCinFresh;              //!< [Bit]  current feedback value is fresh
    }TComplexVal;

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
    //! @brief      Get adc extended value fresh feedback
    //! @note       a. Request of a adc value e.g. ADC_DOU_C give the Dou current on the value pointer back and the
    //!                PIN status of Dou current as the return value
    //!             b. Request of a status e.g ADC_DOU_CS give the status on the value pointer back and as a return value
    //!             Supported values (all other values are only 16Bit values (the max is U16_MAX))
    //!               ADC_PUL_HT: TTC3x, TTC5x, TTC77
    //!               ADC_PWM_HT: TTC3x, TTC5x, TTC77
    //!               ADC_CPX_HT: TTC3x, TTC5x, TTC77, TTC5xx
    //!               ADC_RES_R:  TTC5xx
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
    //!               ADC_PUL_HT: TTC3x, TTC5x, TTC77
    //!               ADC_PWM_HT: TTC3x, TTC5x, TTC77
    //!               ADC_CPX_HT: TTC3x, TTC5x, TTC77, TTC5xx
    //! @param[in]  eAdcType   - [ENU] ADC selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @retval     PIN status - [ENU] is the PINSTA convert to a U16-Value (e.g ADC_PWM_S)
    //! @retval     Adc value  - [VAL] if the PINSTA == PINSTA_OK give the ADC value (e.g ADC_PWM_C)
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
    //! @retval     R_UNKNOWN      - ptVal has an error  -> all values are invalid (BSP-function is called)
    //! @retval     R_CONFIG       - wrong configuration -> Incorrect PIN (NO BSP-function is called)
    //! @retval     R_NULL_POINTER - pointer of ptCpxInit is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreAdcGetPinFinInc( EPin ePin, TFinIncValue *ptVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Adc value of a complex frequency input
    //! @brief      TTC3X  -> eStaPin=> PINSTA_OK, PINSTA_PWD_NOT_FINISHED, PINSTA_PWD_OVERFLOW, PINSTA_PWD_CAPTURE_ERROR
    //! @brief                tVal   => u16Fin, u32PulseWidth, u16Dc, u16Vin
    //! @brief      TTC5X  -> eStaPin=> PINSTA_OK, PINSTA_PWD_NOT_FINISHED, PINSTA_PWD_OVERFLOW, PINSTA_PWD_CAPTURE_ERROR,
    //! @brief                          PINSTA_PWD_CURRENT_THRESHOLD_HIGH, PINSTA_PWD_CURRENT_THRESHOLD_LOW
    //! @brief                tVal   => u16Fin, u32PulseWidth
    //! @brief      TTC7X  -> eStaPin=> PINSTA_OK, PINSTA_PWD_NOT_FINISHED, PINSTA_PWD_CAPTURE_ERROR, PINSTA_PWD_OVERFLOW
    //! @brief                tVal   => u16Fin, u32PulseWidth, u16Vin
    //! @brief      TTC5XX -> eStaPin=> PINSTA_OK, PINSTA_PWD_NOT_FINISHED, PINSTA_PWD_OVERFLOW
    //! @brief                          PINSTA_PWD_INVALID_CPX     -> only the voltage value are valid
    //! @brief                          PINSTA_PWD_INVALID_VOLTAGE -> all values are valid, except the voltage value
    //! @brief                          PINSTA_ERRUNDEF            -> CPX-Value & VIN-Value are invalid (but BSP-Function was called)
    //! @brief                tVal   => u16Fin, u32PulseWidth, u16Vin, u16Cnt
    //!                                 NOTE: u16Vin - PIN:101,125,150,174,102,126,151,175 are not supported - the value is always U16_UNDEF
    //!                                 NOTE: u16Cnt - PIN:115,139,116,140,117,141 are supported - all other pins have the value U16_UNDEF
    //! @param[in]  ePin       - [ENU] Ecu complex PIN like the PINTYPE_FIN
    //! @param[out] ptVal      - [STU] Get the complex value struct back
    //! @retval     R_OKAY         - access is OK        -> check in addition the 'ptVal->ePinSta' status [PIN_OKAY, PINSTA_PWD_xxx]
    //!             R_UNKNOWN      - ptVal has an error  -> all values are invalid (BSP-function is called)
    //!             R_CONFIG       - wrong configuration -> Incorrect PIN (NO BSP-function is called)
    //! @retval     R_NULL_POINTER - pointer of ptCpxInit is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreAdcGetPinFinCpx( EPin ePin, TComplexVal* ptVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get current feedback from the complex pin
    //! @param[in]  ePin         - [ENU]  PIN_115, PIN_139, PIN_116, PIN_140, PIN_117, PIN_141
    //! @param[out] pu16Cin      - [VAL] current [µA] (optional)
    //! @param[out] pboFresh     - [VAL] fresh        (optional)
    //! @retval     PINSTA_OK
    //! @retval     PINSTA_PROTECTION
    //! @retval     PINSTA_PROTECTION_REE
    //! @retval     PINSTA_PROTECTION_FIX
    //! @retval     PINSTA_PWD_CURRENT_THRESHOLD_HIGH
    //! @retval     PINSTA_PWD_CURRENT_THRESHOLD_LOW
    //! @retval     PINSTA_ERRUNDEF
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinFinCpxCin( EPin ePin, TUint16 *pu16Cin, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set 'counter' or a PIN from type Cnt
    //! @param[in]  ePin       - PIN must be an PIN how are config as a counter
    //! @param[in]  u16Counter - Counter value
    //! @retval     R_OKAY     - OK
    //! @retval     R_CONFIG   - Wrong PIN configuration
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetCounterOfPinCnt( EPin ePin, TUint16 u16Counter );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set 'counter' or a PIN from type inc
    //! @param[in]  ePin       - PIN must be an PIN how are config as a counter
    //! @param[in]  u16Counter - Counter value
    //! @retval     R_OKAY     - OK
    //! @retval     R_CONFIG   - Wrong PIN configuration
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetCounterOfPinInc( EPin ePin, TUint16 u16Counter );



    //! Power-PIN
    typedef enum
    {
        POW_POWERSTAGE_ENABLE,  //!< 0 - Power stage enable (internal PIN - without enabling this signal all power outputs remain low)
        POW_SAFTEY_SW_00,       //!< 1 - Safety switch 00   (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        POW_SAFTEY_SW_01,       //!< 2 - Safety switch 01   (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        #ifdef COMPILER_SWITCH_ECU_TTC580
        POW_SAFTEY_SW_02,       //!< 3 - Safety switch 02 (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        #endif
        #ifdef COMPILER_SWITCH_ECU_TTC590
        POW_SAFTEY_SW_02,       //!< 3 - Safety switch 02 (internal PIN - without enabling this signal the PWM group with that switch is 'off')
        #endif
        POW_WAKEUP              //!< 4 - Wake Up, for power down after a wake up)
    }EPowerPin;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get from a ePin the PWM shut off group
    //! @param[in]  ePin         - PIN
    //! @param[out] peShutOffGrp - the shut-off-group [Pointer address is NULL return FALSE]
    //! @return     TRUE = have a shut-off-group, FALSE = have no shut-off-group
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreGetPwmShutOffGrp( EPin ePin, EPowerPin *peShutOffGrp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Install the  external shut off functionality. This requires 2 analog inputs for each group.
    //!             Call in the AppInit()-Phase. The following pins are used for each group:
    //!             POW_SAFTEY_SW_00 (shut off group 0): PIN112(BAT+), PIN136(OPEN)
    //!             POW_SAFTEY_SW_01 (shut off group 1): PIN113(BAT+), PIN137(OPEN)
    //!             POW_SAFTEY_SW_02 (shut off group 2): PIN114(BAT+), PIN138(OPEN)
    //! @param[in]  eShutOffGrp - Shut off group
    //! @retval     R_OKAY      - Everything fine
    //! @retval     R_CONFIG    - One or both PIN is/are in used (with error report)
    //! @retval     R_RANGE     - Power PIN is not valid         (with error report)
    //! @retval     R_UNKNOWN   - Something is wrong             (with error report)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreEnableExtShutOffInit( EPowerPin eShutOffGrp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Is the enable external shut off group init?
    //! @param[in]  eShutOffGrp - shut off group
    //! @retval     TRUE     - Yes
    //! @retval     FALSE    - No
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreIsEnableExtShutOffInit( EPowerPin eShutOffGrp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      The external shut off functionality requires 2 analog inputs for each group.
    //!             The following pins are used for each group:
    //!             POW_SAFTEY_SW_00 (shut off group 0): PIN112, PIN136
    //!             POW_SAFTEY_SW_01 (shut off group 1): PIN113, PIN137
    //!             POW_SAFTEY_SW_02 (shut off group 2): PIN114, PIN138
    //! @param[in]  eShutOffGrp - shut off group
    //! @param[out] pboSta      - status  - TRUE : The PWM-PIN's of that Shut-Off-Group are off - all PWM are off
    //!                                   - FALSE: The PWM-PIN's of that Shut-Off-Group are on  - normal mode
    //! @retval     R_OKAY    - Everything fine
    //! @retval     R_CONFIG  - There ExtShutOff-Group isn't enabled with the function eCoreEnableExtShutOffInit(...) (with error report)
    //! @retval     R_RANGE   - Power PIN is not valid          (with error report)
    //! @retval     R_UNKNOWN - Something is wrong              (with error report)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreEnableExtShutOffGetSta( EPowerPin eShutOffGrp, TBoolean *pboSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the power state / is a function wrapper for eCoreDacSetPin( ..., PIN_SYS, boOn )
    //! @param[in]  ePin - power PIN
    //! @param[in]  boOn - FALSE,TRUE
    //! @retval     R_OKAY      - everything fine
    //! @retval     R_UNKNOWN   - not fine -> use eCoreDacSetPin( ..., PIN_SYS, boOn ) for more information
    //! @retval     R_SUPPORT   - don't support the PIN
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetPowerPinState( EPowerPin ePin, TBoolean boOn );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the power state / is a function wrapper for eCoreAdcGetPinFreshFb( ..., PIN_SYS, &u16Val, NULL )
    //! @param[in]  ePin  - power PIN
    //! @param[out] pboOn - TRUE  = switch is 'ON'  - everything OK
    //!                     FALSE = switch is 'OFF' - no OK
    //! @retval     R_OKAY      - everything fine
    //! @retval     R_UNKNOWN   - not fine -> use eCoreAdcGetPinFreshFb( ..., PIN_SYS, &u16Val, NULL ) for more information
    //! @retval     R_SUPPORT   - don't support the PIN
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

    //! Adc safety configuration
    typedef struct
    {
        TUint8  u8AdcValMin;                //!< [%] Minimum value  TTC5XX[4..96], TTC5X&TTC77[0..100]
        TUint8  u8AdcValMax;                //!< [%] Maximum value TTC5XX[4..96], TTC5X&TTC77[0..100]
        EPin    eRedundantPin;              //!< Redundant PIN
                                            //!    - Analog 3 Mode Inputs shall use PIN_NA
                                            //!      If the ratiometric measurement mode is used, the
                                            //!      channel must not use VIN_PINSUPPLY_S2
                                            //!    - Analog 2 Mode Inputs shall use a redundant pin.
                                            //!      Redundant pin shall be an Analog 2 Mode Inputs pin.
                                            //!      The redundant pin needs to be configured with adc
                                            //!      safety configuration as well. The redundant pin of
                                            //!      the redundant pin's safety configuration shall be PIN_NA
                                            //!      Every redundant channel can only be used once as redundant
                                            //!      channel.
                                            //!      It is not allowed to have a redundant pin which is not
                                            //!      used by a primary pin.
                                            //!      If the ratiometric measurement mode is used, the primary
                                            //!      and the redundant channel must use different sensor
                                            //!      supplies (but not VIN_PINSUPPLY_S2).
    }TAdcSafetyCfg;

    //! Dou safety configuration
    typedef struct
    {
        EPin   eLowSidePin;                 //!< Low side PIN
    }TDouSafetyCfg;

    //! Inc safety configuration
    typedef struct
    {
        TUint16 u16IncInitVal;              //!< Increment value init (bigger as min lower as max!!)
        TUint16 u16IncValMin;               //!< Increment value min (TTC5XX counter limit [1..65534])
        TUint16 u16IncValMax;               //!< Increment value max (TTC5XX counter limit [1..65534])
    }TIncSafetyCfg;

    //! Cnt safety configuration
    typedef struct
    {
        TUint16 u16CntInitVal;              //!< Counter value init (bigger as min lower as max!!)
        TUint16 u16CntValMin;               //!< Counter value min (TTC5XX counter limit [1..65534])
        TUint16 u16CntValMax;               //!< Counter value max (TTC5XX counter limit [1..65534])
    }TCntSafetyCfg;

    //! Cpx safety configuration
    typedef struct
    {
        TUint32  u32FinValMin;              //!< Lower PWD frequency limit in mHz [100..20000000]
        TUint32  u32FinValMax;              //!< Upper PWD frequency limit in mHz [100..20000000]
        TUint32  u32PulValMin;              //!< Lower PWD pulse limit in us [20..10000000]
        TUint32  u32PulValMax;              //!< Upper PWD pulse limit in us [20..10000000]
    }TCpxSafetyCfg;


    //! PWM safety configuration
    typedef struct
    {
        TBoolean   boEnableCinCheck;          //!< Check active
        TUint16    u16CouMax;                 //!< [mA] Current max
        EPin       eLowSidePin;               //!< Low side PIN
    }TPwmSafetyCfg;

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
    //! @param[in]  ePinRes  Resistor ( if the resistor is fix, it is possible to use here the
    //!                                 correct resistor or PINRES_CFG_NA. PINRES_NA is not allowed )
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallDin( EPin ePin, EAppPinRes ePinRes );

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

    //! Voltage resolution

   //! Voltage range
    typedef enum
    {
        VIN_RANGE_5V,   //!<  5V
        VIN_RANGE_10V,  //!< 10V
        VIN_RANGE_32V   //!< 32V
    }EVinRange;

    //! Voltage supply
    typedef enum
    {
        VIN_PINSUPPLY_NA = PINSUPPLY_NA,        //!< NA
        #ifdef COMPILER_SWITCH_ECU_TTC508
        VIN_PINSUPPLY_S0 = PINSUPPLY_S0         //!< Sensor Supply S0
        #else
        VIN_PINSUPPLY_S0 = PINSUPPLY_S0,        //!< Sensor Supply S0
        VIN_PINSUPPLY_S1 = PINSUPPLY_S1,        //!< Sensor Supply S1
        VIN_PINSUPPLY_S2 = PINSUPPLY_S2         //!< Sensor Supply S2
        #endif
    }EVinSupply;

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVin (standard threshold for ADC_VIN_D low:2000mV high:3500mV)
    //!             To change the threshold use eCoreInstallVinThr(...) instead of this function.
    //! @param[in]  ePin          PIN
    //! @param[in]  eRatioSupply  IF 'VIN_PINSUPPLY_NA' is a absolute measurement else is radiometric measurement
    //! @param[in]  eRange        Range
    //! @param[in]  eRes          PIN Resistor
    //! @param[in]  u16ThrLo [mV] Threshold low
    //! @param[in]  u16ThrHi [mV] Threshold high
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVin( EPin ePin, EVinSupply eRatioSupply, EVinRange eRange, EAppPinRes eRes );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVinThr
    //! @param[in]  ePin          PIN
    //! @param[in]  eRatioSupply  IF 'VIN_PINSUPPLY_NA' is a absolute measurement else is radiometric measurement
    //! @param[in]  eRange        Range
    //! @param[in]  eRes          PIN Resistor
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
    //! @param[in]  ePin        - PIN
    //! @param[in]  u16PinFreq  - Frequency
    //! @retval     R_OKAY      - OK
    //! @retval     !R_OKAY     - incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPwm( EPin ePin, TUint16 u16PinFreq );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Set usage of diag margin for selected pin
    //! @details    use before pin is installed(vAppSafetyInit), setting persists after soft reset
    //! @warning    Reduces diagnostic capabilities, check block behavior and might cause pin status indicating an error
    //!             for very high or very low duty cycles. Check block behavior.
    //! @param[in]  ePin       - Pin
    //! @param[in]  boMargin   - TRUE: diag margin used, FALSE: not used
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPwmDiagMarginMode( EPin ePin, TBoolean boMargin );

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

    #ifdef COMPILER_SWITCH_ECU_TTC508
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
    #endif
    #ifdef COMPILER_SWITCH_ECU_TTC510
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
    #endif

    #ifdef COMPILER_SWITCH_ECU_TTC580
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
    #endif


#ifdef COMPILER_SWITCH_ECU_TTC590
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
#endif

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the ADC PIN
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
    extern ERetVal eCoreSetAdcSafetyCfg( EPin ePin, TAdcSafetyCfg *ptAdc, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the ADC PIN
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
    extern ERetVal eCoreGetAdcSafetyCfg( EPin ePin, TAdcSafetyCfg *ptAdc, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the INC PIN
    //!             Important Note: This must set in the vAppSafetyInit function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptInc       - safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App-Phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetIncSafetyCfg( EPin ePin, TIncSafetyCfg *ptInc, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the INC PIN
    //!             Important Note: This function can call after eAppStartUp-function
    //! @param[in]  ePin            - PIN
    //! @param[out] ptAdc           - Safety configuration
    //! @param[out] pboSafeState    - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN to high
    //! @retval     R_CONFIG        - No from the Type INC
    //! @retval     R_SUPPORT       - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                          (call it for PDT setting in or after the eAppPreStart()-Phase)
    //! @retval     R_NULL_POINTER - Parameter Pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetIncSafetyCfg( EPin ePin, TIncSafetyCfg *ptInc, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the Cnt PIN
    //!             Important Note: This must set in the vAppSafetyInit function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptCnt       - Safety configuration pointer / NULL - Take the default values
    //! @param[in]  boSafeState - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App-Phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetCntSafetyCfg( EPin ePin, TCntSafetyCfg *ptCnt, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the Cnt PIN
    //!             Important Note: This function can call after eAppStartUp function
    //! @param[in]  ePin            - PIN
    //! @param[in]  ptCnt           - Safety configuration
    //! @param[in]  pboSafeState    - Safe state active
    //! @retval     R_OKAY         - fine
    //! @retval     R_RANGE        - PIN to high
    //! @retval     R_CONFIG       - No from the type ADC
    //! @retval     R_SUPPORT      - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                         (call it for PDT setting in or after the eAppPreStart()-phase)
    //! @retval     R_NULL_POINTER - Parameter pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetCntSafetyCfg( EPin ePin, TCntSafetyCfg *ptCnt, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the Cpx PIN
    //!             Important Note: This must set in the vAppSafetyInit-function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptCpx       - Safety configuration pointer / NULL - take the default values
    //! @param[in]  boSafeState - Safe state active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetCpxSafetyCfg( EPin ePin, TCpxSafetyCfg *ptCpx, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the Cpx PIN
    //!             Important Note: This function can call after eAppStartUp-function
    //! @param[in]  ePin            - PIN
    //! @param[in]  ptCpx           - Safety configuration
    //! @param[in]  pboSafeState    - SafeState active
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_CONFIG        - No from the type CPX
    //! @retval     R_SUPPORT       - PIN have no safety setting (call it for manual after eCoreSetXxSafetyCfg() call)
    //!                                                          (call it for PDT setting in or after the eAppPreStart() phase)
    //! @retval     R_NULL_POINTER  - Parameter Pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetCpxSafetyCfg( EPin ePin, TCpxSafetyCfg *ptCpx, TBoolean *pboSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'safety configuration' setting for the DAC PIN
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
    //! @brief      Get the 'safety configuration' for the Dou PIN
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
    //! @brief      Reset the PIN from protection
    //! @param[in]  ePin
    //! @param[out] pu8Cnt - Protection reset counter. Indicates how often the application already reset the protection
    //! @retval     PINSTA_OK
    //! @retval     PINSTA_PROTECTION
    //! @retval     PINSTA_PROTECTION_REE
    //! @retval     PINSTA_PROTECTION_FIX
    //! @retval     PINSTA_ERRUNDEF
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCorePinResetProtection( EPin ePin, TUint8 *pu8Cnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set callback to install safety pins immediately after fixed pins have been initialized
    //! @details    Callback is only executed after hard reset. \n
    //!             Return value of callback function currently not used, use R_OKAY. \n
    //!             Only intended to set safety pins, handled pins should be configured to PIN_CHA+PINTYP_NA in PDT.\n
    //!             Function given with pfeSafetyPinInstallCb should install all safety pins that are to be manually installed! \n
    //!             Only last function set will be called by core.
    //! @pre        Call in vAppSafetyInit, safety configuration must be set before/not in callback!
    //! @param      pfeSafetyPinInstallCb - application defined function to install safety pins
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetSafetyPinInstall( ERetVal (*pfeSafetyPinInstallCb) ( TVoid ) );

  #endif // COMPILER_SWITCH_FAM_TTC5XX

#endif
