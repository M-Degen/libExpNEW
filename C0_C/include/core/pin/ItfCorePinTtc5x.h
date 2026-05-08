//**************************************************************************************************
/*!
@file       ItfCorePinTtc5x.h
@brief      PIN Interface
@date       14.11.2014
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPINTTC5X__
    #define __ITFCOREPINTTC5X__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>
    #include <ItfCoreBoardBasic.h>

  #ifdef COMPILER_SWITCH_FAM_TTC5X

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
        ADC_DIN_D = _ADC_DIN_D,                                 //!< [DEF]   Digital value
        ADC_DIN_S = _ADC_DIN_S,                                 //!< [DEF]   Digital value status
        // === Voltage ===
        ADC_VIN_V = _ADC_VIN_V,                                 //!< [mV]    Analogue in voltage
        ADC_VIN_S = _ADC_VIN_S,                                 //!< [DEF]   Analogue in voltage status
        ADC_VIN_D = _ADC_VIN_D,                                 //!< [DEF]   Digital value (deduced over the threshold [core feature])
        // === RES ===
        ADC_RES_R = _ADC_RES_R,                                 //!< [Ohm]   Analogue in resistor
        ADC_RES_S = _ADC_RES_S,                                 //!< [DEF]   Analogue in resistor status
        // === Current ===
        ADC_CIN_C = _ADC_CIN_C,                                 //!< [µA]   Analogue in current mode
        ADC_CIN_S = _ADC_CIN_S,                                 //!< [DEF]   Analogue in current status
        ADC_CIN_D = _ADC_CIN_D,                                 //!< [DEF]   Digital value (deduced over the threshold [core feature])
        // === Frequency ===
        ADC_FIN_F = _ADC_FIN_F,                                 //!< [Hz]    Frequency
        ADC_FIN_S = _ADC_FIN_S,                                 //!< [DEF]   Frequency status
        ADC_FIN_V = _ADC_FIN_V,                                 //!< [mV]    Analogue in voltage mode
        ADC_FIN_VS = _ADC_FIN_VS,                               //!< [DEF]   Analogue in voltage status
        // === Pulse ===
        ADC_PUL_HT = _ADC_PUL_HT,                               //!< [µs]   Pulse length (high time) [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                                //                                     [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        ADC_PUL_S = _ADC_PUL_S,                                 //!< [DEF]   Pulse status
        // === Counter ===
        ADC_COUNTER = _ADC_COUNTER,                             //!< [cnt]   Counter value
        ADC_COUNTER_S = _ADC_COUNTER_S,                         //!< [DEF]   Counter value status
        // === Complex ===
        ADC_CPX_F = _ADC_CPX_F,                                 //!< [Hz]    Frequency
        ADC_CPX_S = _ADC_CPX_S,                                 //!< [Hz]    Frequency status
        ADC_CPX_HT = _ADC_CPX_HT,                               //!< [µs]    Pulse length
                                                                //!<            [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                                //!<            [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        // === Increment ===
        ADC_INC_CNT = _ADC_INC_CNT,                             //!< [cnt]   Increment value - two PIN solution
        ADC_INC_S  = _ADC_INC_S,                                //!< [cnt]   Increment value - status
        ADC_INC_MAS_V = _ADC_INC_MAS_V,                         //!< [cnt]   Increment value - master PIN voltage
        ADC_INC_SLA_V = _ADC_INC_SLA_V,                         //!< [cnt]   Increment value - slave PIN voltage
        // ===  PWM Outputs ===
        ADC_PWM_I_MAX = _ADC_PWM_I_MAX,                         //!< [A/10]  Maximum current on PWM output
        ADC_PWM_OUT_DC = _ADC_PWM_OUT_DC,                       //!< [DEF]   Give the set duty cycle (must call after DAC_PWM_D/DC)
        ADC_PWM_S = _ADC_PWM_S,                                 //!< [DEF]   PIN status (must call after DAC_PWM_D/DC)
        ADC_PWM_C = _ADC_PWM_C,                                 //!< [mA/10] Actual current measurement(via Low side PIN)
        ADC_PWM_C_FRESH = _ADC_PWM_C_FRESH,                     //!< [DEF]   Actual current is fresh (must call after ADC_PWM_C)
        ADC_PWM_CS = _ADC_PWM_CS,                               //!< [mA/10] Actual current PIN status (must call after ADC_PWM_C)
        ADC_PWM_HT = _ADC_PWM_HT,                               //!< [µs]    Pulse length (high time)(must call after DAC_PWM_D/DC)
                                                                //!<            [16Bit low part:   eCoreAdcGetPinFreshFb(..)]
                                                                //!<            [32Bit full value: eCoreAdcGetPinExtFreshFb(..)]
        // === Digital Output ===
        ADC_DOU_OUT_D = _ADC_DOU_OUT_D,                         //!< [DEF]   Give the set DOU value (Bsp feature [driver feedback])
        ADC_DOU_S = _ADC_DOU_S,                                 //!< [DEF]   PIN status  (from last DAC-Call)
        ADC_DOU_V = _ADC_DOU_V,                                 //!< [mV]    Channel digital voltage
        ADC_DOU_C_FRESH = _ADC_DOU_C_FRESH,                     //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C) - just usable for PWM current, deprecated
        ADC_DOU_C = _ADC_DOU_C,                                 //!< [mA/10] Actual current measurement    -> ( Low side PIN only ) - just usable for PWM current, deprecated
        ADC_DOU_CS = _ADC_DOU_CS,                               //!< [DEF]   Status on current measurement -> ( Low side PIN only ) - just usable for PWM current, deprecated
        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX = _ADC_SYS_UB_ECU_MAX,               //!< [mV]     MAX controller power  (IMPORTANT ECU MAXIMUM SPEC RANGE)
        ADC_SYS_BAT_OPERATE = _ADC_SYS_BAT_OPERATE,             //!< [mV]     Ecu operate battery voltage [1200, 24000]
        ADC_SYS_BAT_CURRENT = _ADC_SYS_BAT_CURRENT,             //!< [mV]     Ecu current battery voltage
        ADC_SYS_K15_D = _ADC_SYS_K15_D,                         //!< [ON/OFF] Ignition
        ADC_SYS_SAFE_STATE = _ADC_SYS_SAFE_STATE,               //!< [ON/OFF] Safe state [on TTC71 emulate -> all outputs off]
        ADC_SYS_POWERSTAGE_ENABLE = _ADC_SYS_POWERSTAGE_ENABLE, //!< [ON/OFF] Internal PIN for enabling power stages
        ADC_SYS_TEMP = _ADC_SYS_TEMP,                           //!< [K]      Temperature (°C = x - ADC_KELVIN_OFFSET)
        ADC_SYS_DC_MAX = _ADC_SYS_DC_MAX,                       //!< [-]      Maximum duty cycle on PWM output
        ADC_SYS_REF_VOLTAGE = _ADC_SYS_REF_VOLTAGE,             //!< [mV]     Reference voltage(no reliable values due to BSP)
        ADC_SYS_SENSOR_0_V = _ADC_SYS_SENSOR_0_V,               //!< [mV]     Sensor supply voltage - PIN 136
        ADC_SYS_SENSOR_1_V = _ADC_SYS_SENSOR_1_V,               //!< [mV]     Sensor supply voltage - PIN 135
        ADC_SYS_SENSOR_VAR_V = _ADC_SYS_SENSOR_VAR_V,           //!< [mV]     Sensor supply voltage - PIN 269
        ADC_SYS_PWM_ENABLE = _ADC_SYS_PWM_ENABLE,               //!< [ON/OFF] Internal PIN for enabling power stages
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        DAC_DOU_D = _DAC_DOU_D,                                 //!< [ON/OFF]       Digital output
        DAC_PWM_D = _DAC_PWM_D,                                 //!< [ON/OFF]       PWM output on/off
        DAC_PWM_DC = _DAC_PWM_DC,                               //!< [0..MAX_DUTY]  PWM output in proportional values
        // === ECU board info ===
        // No channel - only system group
        DAC_SYS_K15 = _DAC_SYS_K15,                             //!< [ON/OFF] K15
        DAC_SAFE_STATE = _DAC_SAFE_STATE,                       //!< [ON/OFF] Safe state
                                                                //!< [on TTC71    emulate -> all outputs off]
                                                                //!< [on TTC50/60 emulate -> all outputs off]
        DAC_SYS_POWERSTAGE_ENABLE = _DAC_SYS_POWERSTAGE_ENABLE, //!< [ON/OFF] Internal PIN for enabling power stages
        DAC_SYS_SENSOR_0_D = _DAC_SYS_SENSOR_0_D,               //!< [ON/OFF]           Switch the sensor supply            - PIN 136
        DAC_SYS_SENSOR_1_D = _DAC_SYS_SENSOR_1_D,               //!< [ON/OFF]           Switch the sensor supply            - PIN 135
        DAC_SYS_SENSOR_VAR_V = _DAC_SYS_SENSOR_VAR_V,           //!< [VAL_SENSOR_VAR_x] Set sensor supply to a output level - PIN 269
        DAC_SYS_PWM_ENABLE = _DAC_SYS_PWM_ENABLE,               //!< [ON/OFF] Internal PIN for enabling power stages
    }EDacTyp;

    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX                  //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15                         //!< Start of DAC system output

    #ifdef COMPILER_SWITCH_FAM_TTC5X
        enum // Values for the DAC_SYS_SENSOR_VAR_V
        {
            VAL_SENSOR_VAR_8_5V     = 1,                    //!< [DEF] - Sensor supply have 8,5V
            VAL_SENSOR_VAR_10V      = 2,                    //!< [DEF] - Sensor supply have 10V
            VAL_SENSOR_VAR_14_5V    = 3                     //!< [DEF] - Sensor supply have 14,5V
        };
    #endif

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
        PINSTA_PROTECTION_FIX               =  _PINSTA_PROTECTION_FIX,              //!< PIN is a fix protection mode
        PINSTA_PWD_NOT_FINISHED             =  _PINSTA_PWD_NOT_FINISHED,            //!< PIN not enough edges to accumulate a result
        PINSTA_PWD_OVERFLOW                 =  _PINSTA_PWD_OVERFLOW,                //!< A timer overflow occurred
        PINSTA_PWD_CAPTURE_ERROR            =  _PINSTA_PWD_CAPTURE_ERROR,           //!< The frequency was too high
        PINSTA_PWD_CURRENT_THRESHOLD_HIGH   =  _PINSTA_PWD_CURRENT_THRESHOLD_HIGH,  //!< Last measurement of current threshold was above 20.5mA
        PINSTA_PWD_CURRENT_THRESHOLD_LOW    =  _PINSTA_PWD_CURRENT_THRESHOLD_LOW,   //!< Last measurement of threshold was under 4.5mA
        PINSTA_PWD_HIGH_LEVEL               =  _PINSTA_PWD_HIGH_LEVEL,              //!< only a constant high level is detected
        PINSTA_PWD_LOW_LEVEL                =  _PINSTA_PWD_LOW_LEVEL,               //!< only a constant low level is detected
        PINSTA_PWD_INVALID_VOLTAGE          =  _PINSTA_PWD_INVALID_VOLTAGE,         //!< Invalid voltage value - Fin, PulseWidth can't trust
        PINSTA_ERRMM                        =  _PINSTA_ERRMM,                       //!< PIN current value can't read - error on Mini-Module
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
        FIN_RES_PD_1K8,                   //!< Pull down 1.8 kOhm
        FIN_RES_PD_110                    //!< Pull down 110 Ohm
    }EFinResistor;

    //!Inc Init Setting
    typedef struct
    {
        EFinIncMode   eMode;                //!< [ENU] Defines the counter behavior
        TUint16       u16CountInit;         //!< [NUM] Initial value of incremental counter (0..65535)
        EFinResistor  eRes;                 //!< [ENU] Resistor
        EFinThrHold   eThreshold;           //!< [ENU] Defines input threshold
    }TFinIncInit;

    //!Inc Value
    typedef struct
    {
        TBoolean    boFresh;                //!< [Bit] PIN value is fresh
        EPinStatus  ePinSta;                //!< [ENU] PIN status (NOTE: If the status is OK the struct value are update.
                                            //!<                         If the status isn't OK, the old value are hold.)
        TUint16     u16Cnt;                 //!< [NUM] Value of the incremental counter (0..65535)
        TUint16     u16VinMas;              //!< [mV]  ADC value channel 0, Range: 0..32785 (0..32.785V) (NOTE: is U16_ERROR if the PINSTA is not PINSTA_OK)
        TUint16     u16VinSla;              //!< [mV]  ADC value channel 0, Range: 0..32785 (0..32.785V) (NOTE: is U16_ERROR if the PINSTA is not PINSTA_OK)
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
        EFinPulsMode    ePulsMode;          //!< [ENU] configuration to measure pulse high time
        EFinFreqMode    eFreqMode;          //!< [ENU] Specify the variable edge
        EFinTimRes    eTimRes;            //!< [ENU] Specify the timer resolution
        TUint8        u8CaptCnt;          //!< [NUM] Number of frequency/pulse-width measurements that will be accumulated (0...8)
        EFinThrHold   eThrHold;           //!< [ENU] Defines threshold
        EFinResistor  eResistor;          //!< [ENU] Pull up/down interface
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
    }TComplexVal;


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
    //!             TTC50/60 -> only simulated by call to eCoreSetEcuOutPowSta( FALSE )
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
    //! @return      EPinStatus - [ENU] PIN status
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinFreshFb( EAdcTyp eAdcType, EPin ePin, TUint16 *pu16Val, TBoolean *pboFresh );

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
    //!             R_UNKNOWN      - ptVal has an error  -> all values are invalid (BSP-function is called)
    //!             R_CONFIG       - wrong configuration -> Incorrect PIN (NO BSP-function is called)
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


    //! Power PIN
    typedef enum
    {
        POW_POWERSTAGE_ENABLE,  //!< 0 - Power stage enable (internal PIN - without enabling this signal all power outputs remain low)
        POW_PWM_ENABLE          //!< 1 - PWM enable
    }EPowerPin;

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

    #endif // COMPILER_SWITCH_TAR_PC

    //! Adc safety configuration
    typedef struct
    {
        TUint8  u8AdcValMin;                //!< [%] Minimum value  TTC5XX[4..96], TTC5X&TTC77[0..100]
        TUint8  u8AdcValMax;                //!< [%] Maximum value TTC5XX[4..96], TTC5X&TTC77[0..100]
        EPin    eRedundantPin;              //!< Redundant PIN
    }TAdcSafetyCfg;

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
        TUint16  u16FinValMin;              //!< Upper PWD frequency limit in Hz [1..65534]
        TUint16  u16FinValMax;              //!< Lower PWD frequency limit in Hz [1..65534]
        TUint32  u32PulValMin;              //!< Upper PWD pulse limit in us [1..4294967294]
        TUint32  u32PulValMax;              //!< Lower PWD pulse limit in us [1..4294967294]
    }TCpxSafetyCfg;


    //! PWM safety configuration
    typedef struct
    {
        TUint8     u8CoilRes;                //!< [Ohm] resistance of the coil
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
        VIN_RANGE_15V,  //!< 15V
        VIN_RANGE_20V,  //!< 20V
        VIN_RANGE_25V,  //!< 25V
        VIN_RANGE_30V,  //!< 30V
        VIN_RANGE_32V   //!< 32V
    }EVinRange;

    //! Voltage supply
    typedef enum
    {
        VIN_PINSUPPLY_NA = PINSUPPLY_NA,        //!< NA
        VIN_PINSUPPLY_S0 = PINSUPPLY_S0,        //!< Sensor Supply S0
        VIN_PINSUPPLY_S1 = PINSUPPLY_S1         //!< Sensor Supply S1
    }EVinSupply;

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVin (standard threshold for ADC_VIN_D low:2000mV high:3500mV)
    //!             To change the threshold use eCoreInstallVinThr(...) instead of this function.
    //! @param[in]  ePin          PIN
    //! @param[in]  eRatioSupply  IF 'VIN_PINSUPPLY_NA' is a absolute measurement else is radiometric measurement
    //! @param[in]  eRange        Range
    //! @param[in]  eRes          PIN resistor
    //! @retval     R_OKAY        OK
    //! @retval     !R_OKAY       incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallVin( EPin ePin, EVinSupply eRatioSupply, EVinRange eRange, EAppPinRes eRes );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVinThr
    //! @param[in]  ePin          PIN
    //! @param[in]  eRatioSupply  IF 'VIN_PINSUPPLY_NA' is a absolute measurement else is radiometric measurement
    //! @param[in]  eRange        Range
    //! @param[in]  eRes          PIN resistor
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
    //! @brief      eCoreInstallFin
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallFin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallFin
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallFin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPul
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPul( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallPul
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPul( EPin ePin );

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
    //! @param[in]  ePin       PIN
    //! @param[in]  u16PinFreq PinFreq
    //! @param[in]  ePinFb     Feedback PIN or (EPin)PINFB_NA if feedback pin is not used
    //! @retval     R_OKAY     OK
    //! @retval     !R_OKAY    incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPwm( EPin ePin, TUint16 u16PinFreq, EPin ePinFb );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPwmDiagMargin
    //!             Affects the behavior of the function eCoreInstallPwm(..). If the parameter boOn is TRUE,
    //!             the 'diagnostic margin' is activated for each following eCoreInstallPwm-call.
    //!             An active 'diagnostic margin' allows to distinguish a PINSTA_SCGND or a PINSTA_OKAY
    //!             for a pwm pin which is switched OFF with 0% Duty Cycle.
    //!             Important: The pin needs a low driven impulse (i.e. a small PWM pulse that is permanently on)
    //!             for the following call of the function eCoreDacSetPin( DAC_PWM_D , PIN_118, 0 ).
    //!             Without a 'diagnostic margin' is the return value always PINSTA_SCGND.
    //!
    //! @Note       The function work only if the install pwm have no current feedback-Pin
    //!             like eCoreInstallPwm( x, x, (EPin)PINFB_NA  )
    //!
    //!             The TTC94 pins: 116, 104, 115, 103 have always the margin ON.
    //!             The function have for this pins no effect. (For this pins is the default value true)
    //!
    //! @param[in]  boOn  TRUE: margin is on; FALSE: no margin will be applied [Default=FALSE]
    //!                   Imported: The set value is soft reset stable
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreInstallPwmDiagMargin( TBoolean boOn );

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
    //! @brief      Set the 'safety configuration' setting for the PWM-PIN
    //!             Important Note: This must set in the vAppSafetyInit-function and before the PIN install function.
    //! @param[in]  ePin        - PIN
    //! @param[in]  ptPwm       - Safety configuration pointer / NULL - take the default values
    //! @param[in]  boSafeState - SafeState active
    //! @retval     R_OKAY          - Fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App phase
    //! @retval     R_CONFIG        - PIN have a other safety setting
    //! @retval     R_MEMORY        - Don't have memory for the safety setting
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetPwmSafetyCfg( EPin ePin, TPwmSafetyCfg *ptPwm, TBoolean boSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'safety configuration' for the PWM-PIN
    //!             Important Note: This function can call after eAppStartUp-function
    //! @param[in]  ePin            - PIN
    //! @param[in]  ptDou           - Safety configuration
    //! @param[in]  pboSafeState    - SafeState active
    //! @param[in]  pboPwmPinDeact  - Deactivate the Dou-PIN (boSafeState must be 'FALSE')
    //! @retval     R_OKAY          - fine
    //! @retval     R_RANGE         - PIN is out of range
    //! @retval     R_PHASE         - Call in the wrong App-Phase
    //! @retval     R_SUPPORT       - No safety PIN
    //! @retval     R_RANGE         - PIN to high
    //! @retval     R_CONFIG        - No from the Type PWM
    //! @retval     R_NULL_POINTER  - Parameter pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetPwmSafetyCfg( EPin ePin, TPwmSafetyCfg *ptPwm, TBoolean *pboSafeState );

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
    //! @brief      Open the 'LS Dou Current Measurement Pin' in combination with the 'HS PWM'
    //! @param[in]  ePinDouCm - DOU current measurement low side pin
    //! @param[in]  ePinPwm   - PWM high side pin (single pin or the dual master pin)
    //! @param[in]  u16PwmFrq - PWM Frequency
    //! @retval     R_OKAY     Pin is now open                      -> print out:
    //!                                                                ECU-Pin INFO: DOU LS-Switch [Pin]
    //!                                                                MIN-PIN: INFO: Open LS-Switch-MM [Pin]
    //! @retval     R_BUSY     Pin is in process to open            -> no print out
    //! @retval     R_RANGE    Pin is out of Range                  -> print out: No Pin
    //! @retval     R_SUPPORT  Mini module is not presented at ECU  -> print out: No MM-Module CurrSwi
    //!
    //!  Little example:
    //!
    //!     static TUint8 m_u8Phase = 0;   // reset in the eAppShutDown() - important for the soft reset
    //!
    //!     TVoid vCheckPwmDouLs( TVoid )
    //!     {
    //!         EPin ePwm=PIN_118, eLS=PIN_120; TUint16 u16DC=0;     // PWM-SINGLE  /DOU-LS ECU-Pin
    //!        //EPin ePwm=PIN_106, eLS=PIN_122; TUint16 u16DC=0;    // PWM-SINGLE /DOU-LS MiniModul-Pin
    //!        //EPin ePwm=PIN_116, eLS=PIN_108; TUint16 u16DC=0;    // PWM-DUAL   /DOU-LS ECU-Pin
    //!
    //!         if( m_u8Phase == 0 )
    //!         {
    //!             if( PINSTA_OPEN_SCPOW == eCoreDacSetPin( DAC_PWM_DC, ePwm, 3000 )){  m_u8Phase++; }
    //!         }
    //!         else if( m_u8Phase == 1 )
    //!         {
    //!             if( R_OKAY == eCoreOpenPwmHsDouLsChain( eLS, ePwm, 200 ) ){ m_u8Phase++; }
    //!         }
    //!         else if( m_u8Phase == 2 )
    //!         {
    //!             if( R_OKAY == eCoreClosePwmHsDouLsChain( eLS, ePwm, 200, u16DC ) ){ m_u8Phase = 0; }
    //!         }
    //!     }
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreOpenPwmHsDouLsChain( EPin ePinDouCm, EPin ePinPwm, TUint16 u16PwmFrq );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Close the 'LS Dou Current Measurement Pin' in combination with the 'HS PWM'
    //!             Please call that function in each task cycle until the return value is R_OKAY
    //!             If the ePinDouCm is a mini module pin and the mini module status isn't R_OKAY it is not
    //!             possible to close the chain.
    //! @param[in]  ePinDouCm - DOU current measurement low side pin
    //! @param[in]  ePinPwm   - PWM high side pin
    //!                          - Single PWM pin option - pin is configured as PINTYP_PWM
    //!                          - Dual PWM master pin   - pin configured as PINTYP_PWMDUAL
    //! @param[in]  u16PwmFrq - PWM Frequency
    //! @param[in]  u16PwmDc  - Single option:  0: The pwm pin install by calling that fct. automatic with diag_margin=TRUE [recommendation],
    //!                                            [NOTE: diag_margin=TRUE the pwm get an little impulse for the 'open load' detection
    //!                                                   100us(lower boundary) and 250us(upper boundary) used for diagnostic]
    //!                                        !0: Without diag_margin -> the value is the duty cycle set option
    //!                                            [NOTE: you need here an little DC-Value (impulse) - to prevent the 'open load' ]
    //!                       - Dual option:    0: Alternating driving driver [recommendation]
    //!                                            [Only on one channel the given duty cycle will be applied (active channel) and on the
    //!                                             other channel (passive channel) a small diagnostic signal will be outputed]
    //!                                        !0: The value is the duty cycle set option (no diag_margin supported by the BSP)
    //! @retval     R_OKAY      Pin is close                         -> print out:
    //!                                                                   ECU-PIN: INFO: Close LS-Switch [Pin]
    //!                                                                   MM-PIN: "INFO: Close LS-Switch-MM [Pin]
    //! @retval     R_BUSY     Pin is open [in process try to close] -> no print out
    //! @retval     R_NOACT    Pin isn't okay [open again, next try] -> print out:
    //!                                                                   ECU-PIN: INFO: Go On Open LS-Switch [Pin]
    //!                                                                   MM-PIN:  INFO: Go On Open LS-Switch-MM [Pin]
    //!                                                              call that function in the NEXT task cycle again and the process start again
    //! @retval     R_RANGE    Pin is out of Range                   -> print out: "No Pin"
    //! @retval     R_SUPPORT  Mini module is not presented at ECU   -> no print out
    //! @note       see also the little example eCoreOpenPwmHsDouLsChain() function
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreClosePwmHsDouLsChain( EPin ePinDouCm, EPin ePinPwm, TUint16 u16PwmFrq, TUint16 u16PwmDc );

  #endif // COMPILER_SWITCH_FAM_TTC5X

#endif
