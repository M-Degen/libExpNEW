//**************************************************************************************************
/*!
@file       ItfCorePin.h
@brief      PIN Interface
@date       26.10.2020
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREPIN__
    #define __ITFCOREPIN__

    #include <autoconfig.h>

    #ifdef COMPILER_SWITCH_FAM_TTC5X
        #include <ItfCorePinTtc5x.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC7X
        #include <ItfCorePinTtc7x.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC3X
        #include <ItfCorePinTtc3x.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC5XX
        #include <ItfCorePinTtc5xx.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        #include <ItfCorePinTtc2xxx.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC20XX
        #include <ItfCorePinTtc2xxx.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_HYOBE
        #include <ItfCorePinHyObe.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_HYICU
        #include <ItfCorePinHyIcu.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_HYMEB
        #include <ItfCorePinHyMeb.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_UNJO
        #include <ItfCorePinUnjoBc.h>
    #endif

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
    //! @brief      Configure global automatic trigger(BSP access) behavior for configured pins
    //! @details    Function is used to configure, if the core will automatically call(trigger) ADC/DAC(BSP) functions for configured pins in each cycle,
    //!             if they have not been used by the application/block before.\n
    //!             DAC will be triggered with the last set value(init:0).
    //! @param[in]  boSafetyAutoTrigger         - TRUE: safety pins are automatically triggered(DFLT) \n
    //!                                         - FALSE: safety pins are NOT auto triggered, except for internal phases
    //! @param[in]  boAdcNonSafetyAutoTrigger   - TRUE: input pins are automatically triggered \n
    //!                                         - FALSE: input pins are NOT auto triggered(DFLT)
    //! @param[in]  boDacNonSafetyAutoTrigger   - TRUE: output pins are automatically triggered \n
    //!                                         - FALSE: output pins are NOT auto triggered(DFLT)
    //! @param[in]  boSysAutoTrigger            - TRUE: system pins(ADC) are automatically triggered(DFLT) \n
    //!                                         - FALSE: output pins are NOT auto triggered
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreAutoPinOptions( TBoolean boSafetyAutoTrigger,
                                      TBoolean boAdcNonSafetyAutoTrigger,
                                      TBoolean boDacNonSafetyAutoTrigger,
                                      TBoolean boSysAutoTrigger );

    #ifdef COMPILER_SWITCH_TAR_PC
    //--------------------------------------------------------------------------------------------------
    //! @brief      Set Emulation Mode of (Output) Pin
    //! @param[in]  ePin        - [ENU] (Output) Pin
    //! @param[in]  eEmulMode   - [ENU] Pin Emulation Mode
    //! @retval     R_OKAY      - All good
    //! @retval     R_RANGE     - Pin is out of range
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSimSetPinEmulMode( EPin ePin, EPinEmulMode eEmulMode );

    #endif //COMPILER_SWITCH_TAR_PC
#endif
