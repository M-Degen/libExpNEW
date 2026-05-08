//**************************************************************************************************
/*!
@file  		    ItfBloDac.h
@brief	        DAC Block Interface
@date           21.03.2012
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBLODAC__
  #define __ITFBLODAC__

// INCLUDES ========================================================================================
	#include <ItfTypes.h>
    #include <ItfCoreEcu.h>
    #include <ItfCore.h>

// DEFINES & ENUMS  ================================================================================

// CONFIGURATION STRUCTURE =========================================================================
  	//! Configuration of DAC
	typedef struct
	{
        // Common
	    TChar       achName[BLO_NAME_STR_LEN];  //!< [STR] - Block name
        EBloStatus  eBloProc;                   //!< [ENU] - Block process
        // Fixed setting
        EDacTyp     eTyp;                       //!< [ENU] - DAC type
        // Hardware I/O definitions
        TBoolean    boPinConnected;             //!< [DEF] - PIN permanent connected
        EPin        ePin;                       //!< [ENU] - DAC PIN
	}TDacCfg;

	//! INPUT SUB-BLOCK
    typedef struct
    {
        EBloStatus  eBehProc;                   //!< [ENU] - Block process status options
        TUint16     u16Val;                     //!< [---] - Set value
    } TDacInp;

    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        EBloStatus eBehProcSta;                 //!< [ENU] - Block process status options
        EPinStatus eSta;                        //!< [ENU] - PIN status
    } TDacOut;

    //! ADDRESS SUB-BLOCK
    typedef struct
    {
        const TDacCfg* cptCfg;                  //!< [STU] - Configuration struct
        TVoid*         pvObj;                   //!< [STU] - Pointer to the private object
        TUint16        u16Stamp;                //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TDacAdr;

    //! BLOCK DAC
    typedef struct
    {
        TDacInp  tInp;                          //!< [STU] - Block input vector
        TDacOut  tOut;                          //!< [STU] - Block output vector
        TDacAdr  tXAdr;                         //!< [STU] - Private address information
    } TBloDac;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create the DAC block  (*** needed if the block was not created by the PDT ***)
    //! @param[in]  ptBlo          - Block pointer
    //! @param[in]  cptCfg         - Pointer to the config struct
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_MEMORY       - Out of memory
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloDacCreate( TBloDac* ptBlo, const TDacCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for ERR block interface (*** needed if the block was not created by the PDT ***)
    //! @param[in]  ptBlo      - [PNT] Block pointer
    //! @note       if the the pin is PIN_BLO the block support:
    //!               DAC_DOU_D:    eRet = eCoreInstallDou( cptCfg->ePin                     )
    //!               DAC_PWM_D:    eRet = eCoreInstallPwm( cptCfg->ePin, PINPWM_100, PIN_NA )
    //!               DAC_PWM_DC:   eRet = eCoreInstallPwm( cptCfg->ePin, PINPWM_100, PIN_NA )
    //!               #if defined( COMPILER_SWITCH_FAM_TTC3X) || defined( COMPILER_SWITCH_FAM_TTC5XX )
    //!               case DAC_LED: eRet = eCoreInstallLed( cptCfg->ePin     )
    //!               case DAC_PVG: eRet = eCoreInstallPvg( cptCfg->ePin,  0 )
    //!               case DAC_VOU: eRet = eCoreInstallVou( cptCfg->ePin     )
    //!               #endif
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - Wrong block address
    //! @retval     R_CONFIG       - if the pin is PIN_BLO - no pin config possible
    //! @retval     R_SUPPORT      - if the pin is PIN_BLO - don't support that ADC-TYP
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloDacInit( TBloDac* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DAC PIN - with DAC block
    //! @param[in]  ptBlo          - [PNT] Block pointer
    //! @retval     R_OKAY         - OK
    //! @retval     R_RANGE        - Wrong PIN range
    //! @retval     R_CONFIG       - Wrong group
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloDac( TBloDac* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Set DAC PIN - with DAC block
    //! @param[in,out]  ptBlo  - [PNT] Block pointer
    //! @param[in]      u16Val - Set Value
    //! @retval                - PIN status
    //! @retval         ERROR  - If wrong ptBlo-Addr, return value is 'PINSTA_UNDEF'
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eBloDacSetVal( TBloDac* ptBlo, TUint16 u16Val );

#endif
