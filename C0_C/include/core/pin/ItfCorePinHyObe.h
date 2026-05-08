//**************************************************************************************************
/*!
@file       ItfCorePinHyObe.h
@brief      PIN Interface
@date       14.11.2014
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPINHYOBE__
    #define __ITFCOREPINHYOBE__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>

  #ifdef COMPILER_SWITCH_FAM_HYOBE

    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX        //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15               //!< Start of DAC system output

    //! Adc types
    //! PIN Status
    typedef enum
    {
        PINSTA_OK          =  0,                      //!< PIN is OK
        //PINSTA_OPEN       =  1,                      //!< PIN is open
        //PINSTA_SCGND      =  2,                      //!< PIN is short circuit to ground
        //PINSTA_SCPOW      =  3,                      //!< PIN is short circuit to power
        PINSTA_UNDEF       =  4,                      //!< PIN is undefined ( no PIN update since ecu start )
        PINSTA_ERRINIT     =  5,                      //!< PIN not installed / PIN don't support the request
        PINSTA_ERRUNDEF    =  6,                      //!< PIN status in undefined error
        PINSTA_ERRINUSED   =  7,                      //!< Output PIN has been used in that cycle
        PINSTA_SAFESTATE   = 12,                      //!< PIN is in "safe state"
        PINSTA_NA          = 31                       //!< PIN Status a not applicable [5 Bits]
    }EPinStatus;

    typedef enum
    {// RANGE  0 - 32767
        ADC_DIN_D                 =  0,               //!< [0/1]    Digital info           (Enable)         (P01)
        ADC_VIN_V                 =  1,               //!< [mV]     Analogue in voltage    (Analog input)   (P03,P05,P06,P07,P08,P09,P10)
        ADC_VIN_V_OFF             =  2,               //!< [mV]     Analogue in voltage    (Analog input)   (P03)  -10..+10 V offset
        ADC_VIN_D                 =  3,               //!< [0/1]    Digital info           (Analog input)   (P03,P05,P06,P07,P08,P09,P10)
        ADC_CIN_C                 =  4,               //!< [mV]     Analogue in current    (Analog input)   (P03,P05,P06,P07)
        ADC_CIN_D                 =  5,               //!< [0/1]    Digital info           (Analog input)   (P03,P05,P06,P07)
        ADC_RAW_V                 =  6,               //!< [raw]    raw value              (Pressure sensor)(P11,P12)
        ADC_RAW_D                 =  7,               //!< [0/1]    Digital info           (Pressure sensor)(P11,P12)
        ADC_PERC_V                =  8,               //!< [%/100]  Percent 1/100          (Path sensor)    (P13)
        ADC_PERC_D                =  9,               //!< [0/1]    Digital info           (Path sensor)    (P13)
        ADC_COU_OUT_C             =  10,              //!< [mA]     Give the set Current   (Power stage)    (P14,P15)
        ADC_COU_C                 =  11,              //!< [mA]     Feedback Current       (Power stage)    (P14,P15)
                                                      //!<          -> ADC_SYS_POWERSTATE_SUPPLY give the supply voltage from P14,P15
        ADC_LED_OUT_D             =  12,              //!< [ON/OFF] Give the set LED value (LED)            (P16,P17)
        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX        =  13,               //!< [mV]     Ecu operate battery voltage  [24000]
        ADC_SYS_BAT_OPERATE       =  14,               //!< [mV]     Ecu operate battery voltage  [24000]
        ADC_SYS_BAT_CURRENT       =  15,               //!< [mV]     Ecu current battery voltage  (not supported)
        ADC_SYS_K15_D             =  16,               //!< [ON/OFF] Ignition
        ADC_SYS_TEMP              =  17,               //!< [K]      Temperature (°C = x - ADC_KELVIN_OFFSET)
        ADC_SYS_REF_VOLTAGE       =  18,               //!< [mV]     Reference voltage (Processor voltage)
        ADC_SYS_POWERSTATE_SUPPLY =  19,               //!< [mV]     Give the supply voltage from (Power stage) (P14&P15 (both!))
        ADC_SYS_PS1_ENABLED       =  20,               //!< [0/1]    Feedback if Powerstage P14 is enabled
        ADC_SYS_PS2_ENABLED       =  21,               //!< [0/1]    Feedback if Powerstage P15 is enabled
        ADC_SYS_PS1_FAULT         =  22,               //!< [0/1]    Feedback if Powerstage has fault
        ADC_SYS_PS2_FAULT         =  23,               //!< [0/1]    Feedback if Powerstage has fault
        ADC_SYS_READY_FAULT       =  24                //!< [0/1]    Feedback if Ready has fault
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        DAC_DOU_D                     = 0,             //!< [0/1]    Digital Out               (Ready)(P02)
        DAC_VOU_V                     = 1,             //!< [V]      Voltage Out               (P04)
        DAC_VOU_V_OFF                 = 2,             //!< [V]      Voltage Out               (P04) -10..+10 V offset
        DAC_COU_C                     = 3,             //!< [mA]     Current Out               (Powerstage)(P14,P15,P04)
        DAC_LED_D                     = 4,             //!< [ON/OFF] LED output                (LED)        (P16,P17)
        DAC_SYS_K15                   = 5,             //!< [ON/OFF] K15                       (Virtual)    (-)
        DAC_SYS_POWERSTAGE_P14_ENABLE = 6,             //!< [ON/OFF] Enabling power stages for (Power stage)(P14)
        DAC_SYS_POWERSTAGE_P15_ENABLE = 7              //!< [ON/OFF] Enabling power stages for (Power stage)(P15)
    }EDacTyp;

    typedef enum
    {
        DITHER_NONE,                                   //!< no dither
        DITHER_SINUS,                                  //!< sinus form
        DITHER_SQUARE,                                 //!< rectangle form
        DITHER_SAW_UP,                                 //!< saw tooth form (slow rising and falling edge)
        DITHER_SAW_DOWN,                               //!< saw tooth form (slow falling and rising edge)
        DITHER_TRIANGLE                                //!< triangle form
    }EDitherForm;


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
    //! @brief      Get Adc Value
    //! @param[in]  eAdcType   - ADC_DIN_D, ADC_VIN_D, ADC_VIN_V, ADC_RES_R, ...
    //! @param[in]  ePin       - Pin Index
    //! @retval     Pin status - [ENU] is the PINSTA convert to a I16-Value (e.g ADC_PWM_S)
    //! @retval     Adc value  - [VAL] if the PINSTA == PINSTA_OK give the ADC value (e.g ADC_PWM_C
    //! @retval                  [ERR] if the PINSTA != PINSTA_OK the value is 0
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CoreAdcGetPin( EAdcTyp eAdcType, EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Get Adc value
    //! @note        a. Request of a adc value e.g. ADC_DOU_C give the Dou current on the value pointer back and the
    //!                 PIN status of Dou current as the return value
    //!              b. Request of a status e.g ADC_DOU_CS give the status on the value pointer back and as a return value
    //! @param[in]   eAdcType   - [ENU] ADC type selector
    //! @param[in]   ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[out]  pu16Val    - [VAL] Value
    //! @param[out]  pboFresh   - [DEF] In a correct pin access, the value is always TRUE (Keep the compatibility)
    //!                                 (only if the pin is incorrect the value is false)
    //! @return      EPinStauts - [ENU] PIN status
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreAdcGetPinFreshFb( EAdcTyp eAdcType, EPin ePin, TUint16 *pu16Val, TBoolean *pboFresh );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DAC PIN
    //! @param[in]  eDacType   - [ENU] ADC type selector
    //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
    //! @param[in]  u16Val     - [...] Set value
    //! @param[out]  pboFresh  - [DEF] In a correct pin access, the value is always TRUE (Keep the compatibility)
    //!                                (only if the pin is incorrect the value is false)
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
    //! @brief      eCoreCouSetDitherType
    //! @param[in]  ePin         - [ENU] Ecu PIN
    //! @param[in]  eForm        - [ENU] Set form
    //! @param[in]  i32Amplitude - [mA]  Set the amplitude ( DAC MIN:100, DAC MAX:4000)
    //! @return     EPinStatus
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eCoreCouSetDitherType( EPin ePin, EDitherForm eForm, TInt32 i32Amplitude );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreCouSetDitherFreq
    //! @param[in]  u32Hz        - [hz]  Frequency (20..500)
    //! @return     ERetVal
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCouSetDitherFreq( TUint32 u32Hz );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreCouGetDutyCycle Get duty cycle of Powerstages
    //! @param[in]  ePin            - Powerstage index
    //! @param[out] pu32DutyCycle   - [%]  [0..10000]
    //! @return     ERetVal
    //! @return         R_OKAY      - ok
    //! @return         R_RANGE     - index out of range
    //! @return         R_UNKNOWN   - duty cycle is not correctly measured
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCouGetDutyCycle( EPin ePin, TUint32* pu32DutyCycle );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreCouSetTargetFreq
    //! @param[in]  ePin         - Powerstage index
    //! @param[in]  i32Hz        - [hz]  Frequency
    //! @return     ERetVal
    //! @return         R_OKAY   - done
    //! @return         R_RANGE  - index or frequency out of range
    //! @return         R_BUSY   - in test mode, not completed
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCouSetTargetFreq( EPin ePin, TInt32 i32Hz );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreCouFreqCtrl - Activation or deactivation of ps frequency control
    //! @param[in]  ePin         - Powerstage index
    //! @param[in]  boState      - true: activ, false: deactive
    //! @return     ERetVal
    //! @return         R_OKAY   - done
    //! @return         R_RANGE  - index or frequency out of range
    //! @return         R_BUSY   - in test mode, not completed
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCouFreqCtrl( EPin ePin, TBoolean boState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set ecu output power stages and the safety switch status
    //! @param[in]  boOn       On:ON or Off: OFF
    //! @retval     R_OKAY     success
    //! @retval     R_UNKNOWN  no success
    //--------------------------------------------------------------------------------------------------
    extern  ERetVal eCoreSetEcuOutPowSta( TBoolean boOn );

    //**************************************************************************************************
    // HPI functions
    //**************************************************************************************************
    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetMinPress - Get the HPI minimal pressure
    //! @param[in]  ePin         - Pin number -> HPI index
    //! @return         TRUE     - sensor is available
    //! @return         FALSE    - sensor is not available
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreHpiSensorIsAvailable ( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetMinPress - Get the HPI minimal pressure
    //! @param[in]  ePin         - HPI index
    //! @param[out] pi32MinPress - HPI sensor digit pressure value
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_BUSY    - minimal pressure was requested, wait for valid value
    //! @return         R_RANGE   - index out of range
    //! @return         R_SUPPORT - no HPI sensors available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetMinPress( EPin ePin, TInt32* pi32MinPress );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetMaxPress - Get the HPI maximal pressure
    //! @param[in]  ePin         - HPI index
    //! @param[out] pi32MaxPress - HPI sensor digit pressure value
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_BUSY    - maximal pressure was requested, wait for valid value
    //! @return         R_RANGE   - index out of range
    //! @return         R_SUPPORT - no HPI sensors available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetMaxPress( EPin ePin, TInt32* pi32MaxPress );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetTemp - Get the HPI sensor temperature
    //! @param[in]  ePin         - HPI index
    //! @param[out] pi32Temp     - HPI sensor temperature
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_BUSY    - temperature was requested, wait for valid value
    //! @return         R_RANGE   - index out of range
    //! @return         R_SUPPORT - no HPI sensors available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetTemp( EPin ePin, TInt32* pi32Temp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiGetRange - Get the HPI sensor range
    //! @param[in]  ePin         - HPI index
    //! @param[out] ptRange      - HPI sensor range
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_RANGE   - index or frequency out of range
    //! @return         R_SUPPORT - no HPI sensors or measurement information available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiGetRange( EPin ePin, THpiRange* ptRange );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreHpiConvPressure - Convert pressure digit value to physical value
    //! @param[in]  ePin         - HPI index
    //! @param[in]  i32DigVal    - digit value
    //! @param[out] pi32PhyVal   - physical value
    //! @param[out] ptRange      - HPI sensor range
    //! @return     ERetVal
    //! @return         R_OKAY    - done
    //! @return         R_RANGE   - index or frequency out of range
    //! @return         R_SUPPORT - no HPI sensors or measurement information available
    //! @return         R_UNKNOWN - could not read information from HPI sensor
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreHpiConvPressure( EPin ePin, TInt32 i32DigVal, TInt32* pi32PhyVal, THpiRange* ptRange );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreIoGetSensorRange - Get the IO sensor range for sensor A/B/C
    //! @param[in]  ePin          - Pin index
    //! @param[out] peAdcType     - sensor range converted to ADC type
    //! @return     ERetVal
    //! @return      R_OKAY         - done
    //! @return      R_PIN          - wrong pin index
    //! @return      R_NULL_POINTER - peAdcType is null pointer
    //! @return      R_UNKNOWN      - unknown error, should never appear
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreIoGetSensorRange( EPin ePin, EAdcTyp* peAdcType );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreIoGetTargetValueRange - Get the target value range
    //! @param[out] peAdcType     - target value range converted to ADC type
    //! @return     ERetVal
    //! @return      R_OKAY         - done
    //! @return      R_NULL_POINTER - peAdcType is null pointer
    //! @return      R_UNKNOWN      - unknown error, should never appear
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreIoGetTargetValueRange( EAdcTyp* peAdcType );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreIoGetMonitorValueRange - Get the target value range
    //! @param[out] peDacType     - sensor range converted to ADC type
    //! @return     ERetVal
    //! @return      R_OKAY         - done
    //! @return      R_NULL_POINTER - peDacType is null pointer
    //! @return      R_UNKNOWN      - unknown error, should never appear
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreIoGetMonitorValueRange( EDacTyp* peDacType );


    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @brief  Suppress the internal ecu PIN control logic. E.g. the SafeState reaction of all PIN's
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSimSuppressEcuLogic( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set Adc value - a bypass for the simulation [only for the PC-VERSION]
        //! @brief      call eCoreSimAdcSetPinFresh( eAdcType, ePin, TRUE )
        //! @param[in]  eAdcType   - [ENU] ADC type selector
        //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
        //! @param[in]  u16Val     - [...] PIN value
        //! @retval     R_OKAY
        //! @retval     R_RANGE
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimAdcSetPin( EAdcTyp eAdcType, EPin ePin, TUint16 u16Val );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get DAC PIN Value back - a bypass for the simulation [only for the PC-VERSION]
        //! @param[in]  eDacType   - [ENU] ADC type selector
        //! @param[in]  ePin       - [ENU] Ecu-PIN or system PIN
        //! @retval     u16Val     - [...] Get the value
        //--------------------------------------------------------------------------------------------------
        extern TUint16 u16CoreSimDacGetPin( EDacTyp eDacType, EPin ePin );

    #endif // COMPILER_SWITCH_TAR_PC

  #endif // COMPILER_SWITCH_FAM_HYOBE

#endif
