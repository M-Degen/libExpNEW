//**************************************************************************************************
/*!
@file       ItfCorePinHyMeb.h
@brief      PIN Interface
@date       14.11.2014
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPINHYMEB__
    #define __ITFCOREPINHYMEB__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>

  #ifdef COMPILER_SWITCH_FAM_HYMEB

    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX        //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15               //!< Start of DAC system output

    //! PIN Status
    typedef enum
    {
        PINSTA_OK          =  0,                      //!< PIN is OK
        PINSTA_OPEN        =  1,                      //!< PIN is open
        PINSTA_SCGND       =  2,                      //!< PIN is short circuit to ground
        PINSTA_SCPOW       =  3,                      //!< PIN is short circuit to power
        PINSTA_UNDEF       =  4,                      //!< PIN is undefined ( no PIN update since ecu start )
        PINSTA_ERRINIT     =  5,                      //!< PIN not installed / PIN don't support the request
        PINSTA_ERRUNDEF    =  6,                      //!< PIN status in undefined error
        PINSTA_ERRINUSED   =  7,                      //!< Output PIN has been used in that cycle
        PINSTA_NA          = 31                       //!< PIN Status a not applicable [5 Bits]
    }EPinStatus;

    //! Adc types
    typedef enum
    {// RANGE  0 - 32767
        ADC_DIN_D                 =  0,               //!< [0/1]    Digital info           (Enable)                 (P02)
        ADC_VIN_V                 =  1,               //!< [mV]     Analogue in voltage    (Analog input)           (P03,P10)
        ADC_VIN_D                 =  2,               //!< [0/1]    Digital info           (Analog input)           (P03,P10)
        ADC_CIN_C                 =  3,               //!< [mA]     Analogue in current    (Analog input)           (P03,P10)
        ADC_CIN_D                 =  4,               //!< [0/1]    Digital info           (Analog input)           (P03,P10)

        // ===  PWM Outputs ===
        ADC_PWM_I_MAX             =  5,               //!< [A/10]  Maximum current on PWM output
        ADC_PWM_OUT_DC            =  6,               //!< [DEF]   Give the set duty cycle (must call after DAC_PWM_D/DC)
        ADC_PWM_S                 =  7,               //!< [DEF]   PIN status (must call after DAC_PWM_D/DC)
        ADC_PWM_C                 =  8,               //!< [mA/10] Actual current
        ADC_PWM_CS                =  9,               //!< [mA/10] Actual current PIN status (must call after ADC_PWM_C)
        ADC_PWM_C_FRESH           = 10,               //!< [DEF]   Actual current is fresh (must call after ADC_PWM_C)

        ADC_DOU_OUT_D             = 11,               //!< [DEF]   Give the set DOU value (Bsp feature [driver feedback])
        ADC_DOU_S                 = 12,               //!< [DEF]   PIN status  (from last DAC-Call)        ADC_DOU_C_FRESH           = 12,               //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)
        ADC_DOU_C                 = 13,               //!< [mA/10] Actual current measurement    -> ( Low side PIN only )
        ADC_DOU_CS                = 14,               //!< [DEF]   Status on current measurement -> ( Low side PIN only )
        ADC_DOU_C_FRESH           = 15,                          //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)


        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX        = 16,               //!< [mV]     Ecu battery operate value  [24000]
        ADC_SYS_BAT_OPERATE       = 17,               //!< [mV]     Ecu battery operate value  [24000]
        ADC_SYS_BAT_CURRENT       = 18,               //!< [mV]     Ecu battery current value  (not supported)
        ADC_SYS_K15_D             = 19,               //!< [ON/OFF] Ignition
        ADC_SYS_TEMP              = 20                //!< [K]      Temperature (°C = x - ADC_KELVIN_OFFSET)
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        DAC_DOU_D                 = 0,                //!< [ON/OFF]       Digital output
        DAC_PWM_D                 = 1,                //!< [ON/OFF]       PWM output on/off
        DAC_PWM_DC                = 2,                //!< [0..MAX_DUTY]  PWM output in proportional values
        DAC_SYS_K15               = 5,                //!< [ON/OFF] K15   (Virtual)     (-)
    }EDacTyp;

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
    //! @brief      Set ecu output power stages and the safety switch status
    //! @param[in]  boOn       On:ON or Off: OFF
    //! @retval     R_OKAY     success
    //! @retval     R_UNKNOWN  no success
    //--------------------------------------------------------------------------------------------------
    extern  ERetVal eCoreSetEcuOutPowSta( TBoolean boOn);

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

    //! Voltage range
    typedef enum
    {
        VIN_RANGE_5V,   //!<  5V
        VIN_RANGE_10V,  //!< 10V
        VIN_RANGE_30V   //!< 30V
    }EVinRange;

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVin
    //--------------------------------------------------------------------------------------------------
    extern  ERetVal eCoreInstallVin( EPin ePin, EVinRange eRange );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallVinThr
    //--------------------------------------------------------------------------------------------------
    extern  ERetVal eCoreInstallVinThr( EPin ePin, EVinRange eRange, TUint16 u16ThrLo, TUint16 u16ThrHi  );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallDin
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallVin( EPin ePin );


  #endif // COMPILER_SWITCH_FAM_HYMEB

#endif
