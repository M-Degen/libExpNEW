//**************************************************************************************************
/*!
@file       ItfBloFla.h
@brief      Data flash factory default settings
@date       04.09.2012
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef  __ITFCOREFLASET__
    #define  __ITFCOREFLASET__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreDb.h>
    #include <ItfCoreBoard.h>
    #include <App_Db.h>

// DEFINES & ENUMS  ================================================================================

    #define FLA_SET_MAX_REC 126                     //!< Max factory elements

     //! Factory Setting Error
    enum
    {
        DM_FLA_READ,                                //!< 0 -01- Read
        DM_FLA_ALL_CNT_MAX
    };

    //! Flash configuration variable record
    typedef struct
    {
        TUint8  u8ListIdx;                          //!< Listen index
        TUint8  u8VarIdx;                           //!< Variable index
        TUint8  u8ElmSize;                          //!< Element size
        TUint8  u8ArrDim;                           //!< Array dimension
        TUint16 u16VarAdrOff;                       //!< Address offset
        TVoid  *pvRamAdr;                           //!< Address to RAM Db list
    }TFlaCfgVarRec;

    //! Flash configuration
    typedef struct
    {
        TChar          achName[BLO_NAME_STR_LEN];   //!< [STR] Block name
        EAccLevel      eLowAccLevel;                //!< [ENU] Lowest access level to set
        TUint32        u32Address;                  //!< [NUM] Start address in flash
                                                    //!<       16 bytes head
                                                    //!<        n data bytes
                                                    //!<        2 stop bytes
        TDbListErr     tErr;                        //!< [STU] Error information
        TVoid          *pvRamList;                  //!< [STU] Ram list
        TUint16        u16ShadowBytes;              //!< [NUM] need shadow RAM in byte
        TUint16        u16VarRecCnt;                //!< [NUM] Count of variable records
        TFlaCfgVarRec  *ptVarRec;                   //!< [STU] Variable record
    }TFlaCfg;

    //! Flash address
    typedef struct
    {
        const  TFlaCfg* cptCfg;                     //!< [STU] - Configuration struct
               TVoid*   pvObj;                      //!< [STU] - Pointer to the private object
               TUint16  u16Stamp;                   //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TFlaAdr;

    //! Flash factory block
    typedef struct
    {
        TBehErr  tBehErr;                           //!< [STU] - Block error behavior status [status & control]
        TFlaAdr  tXAdr;                             //!< [STU] - Private address information
    }TBloFla;

    #ifdef COMPILER_SWITCH_FLASH_SETTING

    //--------------------------------------------------------------------------------------------------
    //! @brief      Transfer the flash setting from the flash in the data base flash list
    //! @retval     R_OKAY     - OKAY       (in the DB-List is the flash setting content )
    //! @retval     R_DEFAULT  - Isn't okay (in the DB-List is the flash setting default contents)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloFlashDbListStatus( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Flash block function
    //!             To manipulate the error E.g
    //!               gFla_tFlaSet.tBehErr.tErrCntl.u16SetErrBitOff = 1;
    //!               eBloFlash( &gFla_tFlaSet );)
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @retval     R_OKAY         - Okay
    //! @retval     R_NULL_POINTER - Null Pointer
    //! @retval     R_ADDRESS      - wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloFlash( TBloFla* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error status on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloFlaGetErrStaBit( TBloFla* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum error status information
    //! @param[in]  ptBlo   - [PNT] Pointer to the block
    //! @retval     OKAY    - [BIT] Error state bit coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloFlaGetErrStaAll( TBloFla* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloFlaGetErrEveBit( TBloFla* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT] Pointer to the block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error state bit coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloFlaGetErrEveAll( TBloFla* ptBlo, TBoolean boDetect );


    //--------------------------------------------------------------------------------------------------
    //! @brief   Skip CRC check for flash settings
    //! @details Only for test purpuses
    //!          Skip the CRC check for flash settings. Should be called in AppFixInit
    //! @param[in]  boSkipCrc    - TRUE  Skip the CRC
    //!                          - FALSE Do not skip
    //! @retval     R_OKAY      - OK
    //!             R_PHASE     - called in wrong phase
    //--------------------------------------------------------------------------------------------------
    extern ERetVal  eCoreSkipFlaCrc( TBoolean boSkipCrc );

    #endif

#endif
