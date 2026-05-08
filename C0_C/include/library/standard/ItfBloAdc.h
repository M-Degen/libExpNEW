//**************************************************************************************************
/*!
@file  		ItfBloAdc.h
@brief	        Adc block interface
@date           15.07.2013
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBLOADC__
  #define __ITFBLOADC__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCore.h>

// DEFINES & ENUMS  ================================================================================

// CONFIGURATION STRUCTURE =========================================================================

    //! CONFIGURATION OF ADC
    typedef struct
    {
        //Common
        TChar        achName[BLO_NAME_STR_LEN];   //!< [STR] - Block name
        EBloStatus   eBloProc;                    //!< [ENU] - Block process
        // Fixed settings
        EAdcTyp      eTyp;                        //!< [ENU] - ADC type
        // Hardware I/O definitions
        TBoolean     boPinConnected;              //!< [DEF] - PIN permanent connected
        EPin         ePin;                        //!< [ENU] - ADC PIN
    }TAdcCfg;

    //! INPUT SUB-BLOCK
    typedef struct
    {
        EBloStatus   eBehProc;                    //!< [ENU] -  Block process status options
    } TAdcInp;

    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        EBloStatus eBehProcSta;                   //!< [ENU] - Block process status options
        TUint16    u16Val;                        //!< [STU] - Read value
        EPinStatus eSta;                          //!< [ENU] - PIN status
    } TAdcOut;

    //! ADDRESS SUB-BLOCK
    typedef struct
    {
        const TAdcCfg* cptCfg;                    //!< [STU] - Configuration struct
        TVoid*         pvObj;                     //!< [STU] - Pointer to the private object
        TUint16        u16Stamp;                  //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TAdcAdr;

    //! BLOCK ADC
    typedef struct
    {
        TAdcInp  tInp;                            //!< [STU] - Block input vector
        TAdcOut  tOut;                            //!< [STU] - Block output vector
        TAdcAdr  tXAdr;                           //!< [STU] - Private address information
    } TBloAdc;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for ADC-Block interface (*** needed if the block was not created with the PDT ***)
    //! @param[in]  ptBlo          - [PNT] Pointer to Block
    //! @param[in]  cptCfg         - Pointer to the config struct
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - Null pointer
    //! @retval     R_MEMORY       - Out of memory
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloAdcCreate( TBloAdc* ptBlo, const TAdcCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for ADC block interface (*** needed if the block was not created with the PDT ***)
    //! @note           if the PIN is PIN_BLO the block support:
    //!                      ADC_DIN_D:    eRet = eCoreInstallDin(cptCfg->ePin, PINRES_PULLDO )
    //!                      ADC_VIN_D:    eRet = eCoreInstallVin(cptCfg->ePin, VIN_PINSUPPLY_NA, VIN_RANGE_5V )
    //!                      ADC_VIN_V:    eRet = eCoreInstallVin(cptCfg->ePin, VIN_PINSUPPLY_NA, VIN_RANGE_5V )
    //!                      ADC_VIN_RES:  eRet = eCoreInstallRes(cptCfg->ePin )
    //!                      ADC_CIN_D:    eRet = eCoreInstallCin(cptCfg->ePin )
    //!                      ADC_CIN_C:    eRet = eCoreInstallCin(cptCfg->ePin )
    //!                      ADC_FIN_V:    eRet = eCoreInstallFin(cptCfg->ePin )
    //!                      ADC_FIN_F:    eRet = eCoreInstallFin(cptCfg->ePin )
    //!                      ADC_PUL_HT:   eRet = eCoreInstallPul(cptCfg->ePin )
    //!                      ADC_COUNTER:  eRet = eCoreInstallCnt(cptCfg->ePin )
    //! @param[in,out]  ptBlo           - [PNT] pointer to block
    //! @retval         R_OKAY          - Functions execute without error
    //! @retval         R_NULL_POINTER  - Null pointer
    //! @retval         R_ADDRESS       - Wrong block address
    //! @retval         R_CONFIG        - if the PIN is PIN_BLO - no PIN config possible
    //! @retval         R_SUPPORT       - if the PIN is PIN_BLO - don't support that ADC-TYP
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloAdcInit( TBloAdc* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get ADC value direct - with ADC object
    //! @param[in,out]  ptBlo           - [PNT] block pointer
    //! @retval         R_OKAY          - Function have success
    //! @retval         R_NULL_POINTER  - Null pointer
    //! @retval         R_ADDRESS       - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloAdc( TBloAdc* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get ADC value direct - with ADC object
    //! @param[in,out]  ptBlo   - [PNT] block pointer
    //! @retval         OKAY    - Adc value
    //! @retval         ERROR   - If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloAdcGetVal( TBloAdc* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get ADC status direct - with ADC object
    //! @param[in,out]  ptBlo      - [PNT] pointer to ADC block
    //! @return         Adc status - [ENU] no error check (see eBloAdc), in error case is the value always 'PINSTA_ERRUNDEF'
    //--------------------------------------------------------------------------------------------------
    extern EPinStatus eBloAdcGetSta( TBloAdc* ptBlo );

#endif
