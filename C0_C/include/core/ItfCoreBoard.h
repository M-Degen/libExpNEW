//**************************************************************************************************
/*!
@file       ItfCoreBoard.h
@brief	    Board Interface
@date       26.10.2020
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREBORD__
   #define __ITFCOREBORD__

    #include <autoconfig.h>
    #include <ItfTypes.h>
    #include <ItfCoreBoardBasic.h>

    #ifdef COMPILER_SWITCH_FAM_TTC5X
        #include <ItfBoardCenTtc5x.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC7X
        #include <ItfBoardCenTtc7x.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC3X
        #include <ItfBoardCenTtc3x.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC5XX
        #include <ItfBoardCenTtc5xx.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        #include <ItfBoardCenTtc23xx.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC20XX
        #include <ItfBoardCenTtc20xx.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_HYOBE
        #include <ItfBoardCenHyObe.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_HYICU
        #include <ItfBoardCenHyIcu.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_HYMEB
        #include <ItfBoardCenHyMeb.h>
    #endif

    #ifdef COMPILER_SWITCH_FAM_UNJO
        #include <ItfBoardCenUnjoBc.h>
    #endif

    //! Options list
    typedef struct
    {
        const TUint8   cu8OptRecMax;              //!< [NUM] Maximal options count
        const TAppPin *cptOpt;                    //!< [PTR] Struct pointer
    }TPinOpt;

    //! Application pin default
    typedef struct
    {
        TUint16 au16DfltVal[PIN_OVER_ALL];        //!< [NUM] Pin default value
    }TAppPinDftVal;

    //! Pin information list
    typedef struct
    {
        const TAppPin *cptAppPin;                 //!< [PTR] Application pin
        const TPinOpt *cptAppOpt;                 //!< [PTR] Application option
        TAppPinDftVal *ptAppSim;                  //!< [PTR] Application simulation
    }TPinInfo;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give pin application type
    //! @param[in]  u8PinIdx
    //! @retval     Application type
    //! @retval     PINTYP_NA   if the pin index is out of range
    //--------------------------------------------------------------------------------------------------
    extern EAppPinTyp eCorePinAppTyp( TUint8 u8PinIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Convert PIN number to a PIN number in a "String style"
    //! @param[in]  ePin       PIN number
    //! return      String pointer
    //--------------------------------------------------------------------------------------------------
    extern TChar *pchCoreGivePinNo( EPin ePin );

    #ifdef COMPILER_SWITCH_ETH_HEXFILE_FLASH
     //--------------------------------------------------------------------------------------------------
     //! @brief      Ethernet 'HEX-File' flashing is in the standby mode - must call in the vAppSafetyInit() function
     //!             or in the main before the while loop
     //!             The standby mode can be locked with the function vCoreEthFlashIgnore().
     //! @retval     R_OKAY        - is okay (since 'the MAIN_SAFETY_PRE_START')
     //! @retval     R_PHASE       - the function is not called in the 'PreStart-Phase'
     //--------------------------------------------------------------------------------------------------
     extern ERetVal eCoreEthFlashStandby( TVoid );

     //--------------------------------------------------------------------------------------------------
     //! @brief     Deactivate the Ethernet flashing standby mode (activate the standby mode with the function eCoreEthFlashStandby() )
     //! @note      The ethernet standby mode cannot be reactivated after calling this function in phases > MAIN_SAFETY_PRE_START
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreEthFlashIgnore( TVoid );
    #endif

    #if defined(COMPILER_SWITCH_WAKE_UP_PIN)  || defined(COMPILER_SWITCH_WAKE_UP_CAN )
     #define WAKEUP_NO_EXIT U16_MAX      //!< defined value for u16WaitAfterWakeUp

     typedef enum
     {
        ECU_START_REQ_UNDEF,            //!< Analysis don't start
        ECU_START_REQ_NO_CONDITION,     //!< Start Request can be K15-Pin or WakeUp-Pin (the signal time are to short)
        ECU_START_REQ_K15,              //!< Ecu is started by the K15 pin
        ECU_START_REQ_WAKEUP            //!< Ecu is started by the WakeUp pin
#ifdef COMPILER_SWITCH_WAKE_UP_CAN
        ,ECU_START_REQ_CAN              //!< Ecu is started by CAN
#endif
     }EEcuStartRequest;

     //--------------------------------------------------------------------------------------------------
     //! @brief      Get the Ecu Start Request
     //! @retval     ECU_START_REQ_UNDEF         - analysis don't start
     //! @retval     ECU_START_REQ_NO_CONDITION  - start request can be K15-Pin or WakeUp-Pin (the signal time are to short)
     //! @retval     ECU_START_REQ_K15           - ecu is started by the K15 pin
     //! @retval     ECU_START_REQ_WAKEUP        - ecu is started by the WakeUp pin
     //! @retval     ECU_START_REQ_CAN           - ecu is started by CAN [ if supported HW, TTC2xxx]
     //--------------------------------------------------------------------------------------------------
     extern EEcuStartRequest eCoreEcuStartReq( TVoid );

     extern EEcuStartRequest g_eEcuStartRequest;

    #endif // defined(COMPILER_SWITCH_WAKE_UP_PIN)  || defined(COMPILER_SWITCH_WAKE_UP_CAN )

    extern const TPinInfo gPinInfo_ctAppPin;      //!< [VAR] Application pin
    extern const TPinInfo gPinInfo_ctAppPin2;     //!< [VAR] Application pin II

#endif
