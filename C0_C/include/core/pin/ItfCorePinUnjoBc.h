//**************************************************************************************************
/*!
@file       ItfCorePinUnjoBc.h
@brief      PIN Interface
@date       19.05.2022
@author     HYDAC/ASN
*/
//**************************************************************************************************

#ifndef __ITFCOREPINUNJOBC__
    #define __ITFCOREPINUNJOBC__

    #include <autoconfig.h>
    #include <ItfCoreBoard.h>

  #ifdef COMPILER_SWITCH_FAM_UNJO

    #define ADC_SYS_START   ADC_SYS_UB_ECU_MAX        //!< Start of ADC system input
    #define DAC_SYS_START   DAC_SYS_K15               //!< Start of DAC system output

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

    //! Adc types
    typedef enum
    {// RANGE  0 - 32767
        // === Digital Inputs ===
        ADC_DIN_D                           =  _ADC_DIN_D,                              //!< [0/1]   Digital info           (Enable)
        ADC_DIN_S                           =  _ADC_DIN_S,                              //!< [DEF]   Digital value status
        // === Voltage ===
        ADC_VIN_V                           =  _ADC_VIN_V,                              //!< [mV]    Analogue in voltage    (Analog input)
        ADC_VIN_S                           =  _ADC_VIN_S,                              //!< [DEF]   Analogue in voltage status
        ADC_VIN_D                           =  _ADC_VIN_D,                              //!< [0/1]   Digital info           (Analog input)
        // === Current ===
        ADC_CIN_C                           =  _ADC_CIN_C,                              //!< [mA]    Analogue in current    (Analog input)
        ADC_CIN_S                           =  _ADC_CIN_S,                              //!< [DEF]   Analogue in current status
        ADC_CIN_D                           =  _ADC_CIN_D,                              //!< [0/1]   Digital info           (Analog input)
        // === RES ===
        ADC_RES_R                           =  _ADC_RES_R,                              //!< [Ohm]   Analogue in resistor
        ADC_RES_S                           =  _ADC_RES_S,                              //!< [DEF]   Analogue in resistor status
        // === Frequency ===
        ADC_FIN_F                           =  _ADC_FIN_F,                              //!< [Hz]    Frequency
        ADC_FIN_S                           =  _ADC_FIN_S,                              //!< [DEF]   Frequency status
        ADC_FIN_V                           =  _ADC_FIN_V,                              //!< [mV]    Analogue in voltage
        ADC_FIN_VS                          =  _ADC_FIN_VS,                             //!< [DEF]   Analogue in voltage status
        // ===  PWM Outputs ===
        ADC_PWM_I_MAX                       =  _ADC_PWM_I_MAX,                          //!< [A/10]  Maximum current on PWM output
        ADC_PWM_OUT_DC                      =  _ADC_PWM_OUT_DC,                         //!< [DEF]   Give the set duty cycle (must call after DAC_PWM_D/DC)
        ADC_PWM_S                           =  _ADC_PWM_S,                              //!< [DEF]   PIN status (must call after DAC_PWM_D/DC)
        ADC_PWM_C                           =  _ADC_PWM_C,                              //!< [mA/10] Actual current
        ADC_PWM_CS                          =  _ADC_PWM_CS,                             //!< [mA/10] Actual current PIN status (must call after ADC_PWM_C)
        ADC_PWM_C_FRESH                     =  _ADC_PWM_C_FRESH,                        //!< [DEF]   Actual current is fresh (must call after ADC_PWM_C)
        // === Digital Output ===
        ADC_DOU_OUT_D                       =  _ADC_DOU_OUT_D,                          //!< [DEF]   Give the set DOU value (Bsp feature [driver feedback])
        ADC_DOU_S                           =  _ADC_DOU_S,                              //!< [DEF]   PIN status  (from last DAC-Call)        ADC_DOU_C_FRESH           = 12,               //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)
        ADC_DOU_V                           =  _ADC_DOU_V,                              //!< [mV]    Channel digital voltage
        ADC_DOU_C                           =  _ADC_DOU_C,                              //!< [mA/10] Actual current measurement    -> ( Low side PIN only )
        ADC_DOU_CS                          =  _ADC_DOU_CS,                             //!< [DEF]   Status on current measurement -> ( Low side PIN only )
        ADC_DOU_C_FRESH                     =  _ADC_DOU_C_FRESH,                        //!< [DEF]   Actual current is fresh (must call after ADC_DOU_C)
        // === LED Output ===
        ADC_LED_OUT_D                       =  _ADC_LED_OUT_D,                          //!< [ON/OFF]  Give the set LED value (Bsp feature [driver feedback])
        ADC_LED_S                           =  _ADC_LED_S,                              //!< [DEF]     PIN status
        ADC_LED_VAL                         =  _ADC_LED_VAL,                            //!< [VAL]     If the LED was turned on this returns the actual current(Range: 0...27.600mA)
                                                                                        //!<           If the LED was turned off this returns the actual voltage(Range: 0...10.500V)
        // === ECU board info ===
        // only system group as PIN always PIN_SYS
        ADC_SYS_UB_ECU_MAX                  =  _ADC_SYS_UB_ECU_MAX,                     //!< [mV] Constant for the max allowed Low voltage (trm 30) supply value
        ADC_SYS_BAT_OPERATE                 =  _ADC_SYS_BAT_OPERATE,                    //!< [mV] Constant for the normal Low voltage (trm 30) supply value
        ADC_SYS_BAT_CURRENT                 =  _ADC_SYS_BAT_CURRENT,                    //!< [mV] Actual low voltage (trm 30) supply
        ADC_SYS_DC_MAX                      =  _ADC_SYS_DC_MAX,                         //!< [-] Maximum duty cycle on PWM output
        ADC_SYS_REF_VOLTAGE                 =  _ADC_SYS_REF_VOLTAGE,                    //!< [mV] Actual Internal 5 V supply (ADC_SYS_5V)
        ADC_SYS_K15_V                       =  _ADC_SYS_K15_V,                          //!< [mV] Ignition voltage
        ADC_SYS_K15_D                       =  _ADC_SYS_K15_D,                          //!< [ON/OFF] Digital value showing trm 15 ON:  ADC_SYS_K15_V > 6 V, OFF:  ADC_SYS_K15_V < 4 V
        ADC_SYS_POWERSTAGE_ENABLE           =  _ADC_SYS_POWERSTAGE_ENABLE,              //!< "get_status_register" -> bit INV_CON_API_POWER_STAGE_ENABLED
        ADC_SYS_TEMP                        =  _ADC_SYS_TEMP,                           //!< [K] Temperature (°C = x - ADC_KELVIN_OFFSET)
        ADC_SYS_BC_CPU_TMP                  =  _ADC_SYS_BC_CPU_TEMP,                    //!< [K] CPU temperature of basic control (BC) processor
        ADC_SYS_BD_CPU_TMP                  =  _ADC_SYS_BD_CPU_TEMP,                    //!< [K] Basic Drive board temperature
        ADC_SYS_IGBT_CASE_TMP               =  _ADC_SYS_IGBT_CASE_TEMP,                 //!< [K] transistor bridge to the motor temperature
        ADC_SYS_STATOR_TMP                  =  _ADC_SYS_STATOR_TEMP,                    //!< [K] Stator temperature
        ADC_SYS_K30                         =  _ADC_SYS_TRM_30,                         //!< [mV]
        ADC_SYS_VBSSNS_FB                   =  _ADC_SYS_VBSSNS,                         //!< [mV] boost converter power supply feedback
        ADC_SYS_24V_REF                     =  _ADC_SYS_24V,                            //!< [mV] 24V reference
        ADC_SYS_3V3_REF                     =  _ADC_SYS_3V3,                            //!< [mV] 3V3 reference
        ADC_SYS_DC_LNK_VOLT                 =  _ADC_SYS_DC_LINK_VOLT,                   //!< [mV]
        ADC_SYS_INSTANT_PHASE_CURR_U        =  _ADC_SYS_INSTANTANEOUS_PHASE_CURR_U,     //!< [mA]
        ADC_SYS_INSTANT_PHASE_CURR_V        =  _ADC_SYS_INSTANTANEOUS_PHASE_CURR_V,     //!< [mA]
        ADC_SYS_INSTANT_PHASE_CURR_W        =  _ADC_SYS_INSTANTANEOUS_PHASE_CURR_W,     //!< [mA]
        ADC_SYS_DIN_STO_1                   =  _ADC_SYS_DIN_STO_1,                      //!< [STO.1 in connector. FALSE: STO not active, TRUE: STO active] Safe Torque
        ADC_SYS_DIN_STO_2                   =  _ADC_SYS_DIN_STO_2,                      //!< [STO.2 in connector. FALSE: STO not active, TRUE: STO active] Safe Torque
        ADC_SYS_DIN_OTE                     =  _ADC_SYS_DIN_OTE,                        //!< [Output Test Equipment. FALSE: No fault in STO electronics, TRUE: Fault in STO electronics] Safe Torque
        ADC_SYS_HVIL_IN                     =  _ADC_SYS_HVIL_IN,                        //!< HVIL Input
        ADC_SYS_HVIL_OUT                    =  _ADC_SYS_HVIL_OUT,                       //!< HVIL Output
        ADC_SYS_HVIL_CUR                    =  _ADC_SYS_HVIL_CUR,                       //!< HVIL Current
        ADC_SYS_SPWR5V0                     =  _ADC_SYS_SPWR5V0,                        //!< [0 or 5000] Sensor Power supply fixed 5.0V
        ADC_SYS_SPWRADJ                     =  _ADC_SYS_SPWRADJ                         //!< [0 or 5000-16000] Sensor Power supply Adjustable
    }EAdcTyp;

    //! DAC types
    typedef enum
    {
        DAC_DOU_D                 =  _DAC_DOU_D,               //!< [ON/OFF]       Digital output
        DAC_PWM_D                 =  _DAC_PWM_D,               //!< [ON/OFF]       PWM output on/off
        DAC_PWM_DC                =  _DAC_PWM_DC,              //!< [0..MAX_DUTY]  PWM output in proportional values
        DAC_SYS_K15               =  _DAC_SYS_K15,             //!< [ON/OFF] K15   (Virtual)     (-)
        DAC_SYS_SPWR5V0           =  _DAC_SYS_SPWR5V0,         //!< [0 or 5000] Sensor Power supply fixed 5.0V
        DAC_SYS_SPWRADJ           =  _DAC_SYS_SPWRADJ          //!< [0 or 5000-16000] Sensor Power supply Adjustable
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
    //! @brief      Get an extended Adc "u32" value - simple
    //!             Supported values (all other values are only 16Bit values (the max is U16_MAX))
    //!               NONE
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

        //--------------------------------------------------------------------------------------------------
        //! @brief  Install the PINs with PINSTA_OKAY/PINSTA_UNDEF  [only for the PC-VERSION]
        //! @param[in]  boUndef=TRUE  -> Install the PIN with PINSTA_UNDEF - is the case of the HW
        //!             boUndef=FALSE -> Install the PIN with PINSTA_OKAY  - is the default
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSimPinInitUndef( TBoolean boUndef );

    #endif // COMPILER_SWITCH_TAR_PC

    //! Voltage range
    typedef enum
    {
        VIN_RANGE_5V,   //!<  5V
        VIN_RANGE_32V   //!< 32V
    }EVinRange;

    //! Voltage supply
    typedef enum
    {
        VIN_PINSUPPLY_NA  = PINSUPPLY_NA,     //!< NA
        VIN_PINSUPPLY_RAT = PINSUPPLY_RAT     //!< voltage measurement proportional to sensor supply voltage
    }EVinSupply;

    #define VIN_PINSUPPLY_UBAT  PINSUPPLY_RAT //!< deprecated, just for compatibility

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
    //! @param[in]  ePin     Pin
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallFin( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallFin
    //! @param[in]  ePin     Pin
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallFin( EPin ePin );

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
    //! @brief      eCoreDeInstallPwm
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPwm( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreInstallPwm
    //! @param[in]  ePin        - PIN
    //! @param[in]  u16PinFreq  - Frequency
    //! @retval     R_OKAY      - OK
    //! @retval     !R_OKAY     - incorrect
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreInstallPwmDual( EPin ePin, TUint16 u16PinFreq );

    //--------------------------------------------------------------------------------------------------
    //! @brief      eCoreDeInstallPwm
    //! @param[in]  ePin     PIN
    //! @retval     R_OKAY   OK
    //! @retval     !R_OKAY  incorrect
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDeInstallPwmDual( EPin ePin );

  #endif // COMPILER_SWITCH_FAM_UNJO

#endif
