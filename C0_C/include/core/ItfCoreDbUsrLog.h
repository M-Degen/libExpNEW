//**************************************************************************************************
/*!
@file       ItfCoreDbUsrLog.h
@brief      Core - Factory Setting
@created    30.08.2023        HYDAC/BSC

    PLEASE NOTE: Some functions used in this example here are located in the MST Protocol Interface

    in appconfig.h

    #ifdef COMPILER_SWITCH_FAM_TTC5XX
        #if defined(COMPILER_SWITCH_ECU_TTC580) || defined(COMPILER_SWITCH_ECU_TTC590) || defined(COMPILER_SWITCH_ECU_TTC508)
           #define COMPILER_SWITCH_USR_CHNG_MNGMNT
        #endif
    #endif

    in AppCode.c

    #if defined(COMPILER_SWITCH_USR_CHNG_MNGMNT) && defined(COMPILER_SWITCH_TAR_PC)
    #include <time.h>
    #endif

    #if defined(COMPILER_SWITCH_USR_CHNG_MNGMNT) && defined(COMPILER_SWITCH_TAR_HW)
    #include <ItfCoreDbUsrLog.h>
    #endif

    in AppPreStart:

    #ifdef COMPILER_SWITCH_USR_CHNG_MNGMNT
    vCoreDbUsrLogActivate();
    #endif

    in AppStartUp:

     if( m_boStartUpPhase == 0 )
    {
        .
        .
        .

        #ifdef COMPILER_SWITCH_USR_CHNG_MNGMNT
            vCoreDbUsrLogMstActivate( TRUE / FALSE ); // TRUE == logging is locked (can not be deactivated by mst) -- FALSE == logging is unlocked (can be deactivated by mst)
        #endif

        .
        .
        .
    }
    else
    {
        .
        .
        .

        #if defined(COMPILER_SWITCH_USR_CHNG_MNGMNT) && defined(COMPILER_SWITCH_TAR_PC)
            // variation A initialization with utc timestamp:
            // Should come in as a timestamp like UTC from NTP or custom/equal
            // time(null)(utc from time header) - 1577836800 (+ 50 years in seconds) since 01.01.2020
            eCoreDateTimeInitTsp( (TUint32)( time(NULL) - 1577836800 ) );

            // or USE Engine Time if TRUE
            vCoreDateTimeUseEngineTime( FALSE );

            return R_OKAY;
        #elif defined(COMPILER_SWITCH_USR_CHNG_MNGMNT) && defined(COMPILER_SWITCH_TAR_HW)
            // fill with timestamp as the following:
            // this is utc:
            // 1698223320 seconds since 01.01.1970 or
            // 1698223320 - 1577836800 (+ 50 years in seconds) = 120386520 seconds since 01.01.2020
            // equals 8 hours 42 minutes 0 seconds on the 25.10.23
            eCoreDateTimeInitTsp( 120386520 ); // Should come in as a timestamp like UTC from NTP or equal

            // or USE Engine Time if TRUE
            vCoreDateTimeUseEngineTime( FALSE );

            return R_OKAY;
        #else

        .
        .
        .
    }


    in AppRun
    example how to log from application

    #ifdef COMPILER_SWITCH_USR_CHNG_MNGMNT
        {
          TInt32   i32TempOld = gDb_tNvmMem.i32NvmVar7;
          gDb_tNvmMem.i32NvmVar7++;
          eCoreDbUsrLogAddAppEntry( 0, &gDb_tNvmMem.tListRoot, &gDb_tNvmMem.i32NvmVar7, TINT32, u16CastI16(i32TempOld), u16CastI16(gDb_tNvmMem.i32NvmVar7), ePtcMstGetAccessLevel() );
        }
     #endif


     in AppShutDown
     this saves the log date to the external flash

     #ifdef COMPILER_SWITCH_USR_CHNG_MNGMNT
        return eCoreDbUsrLogDbStore();
     #else


*/
//**************************************************************************************************
#ifndef __ITFCOREDBUSRLOG__
    #define __ITFCOREDBUSRLOG__

#ifdef COMPILER_SWITCH_USR_CHNG_MNGMNT_FEATURE

    #include <ItfCoreDb.h>

    #define CORE_DB_USR_LOG_DFLT_REC            (256*32)    // Variable pro Liste * Array-Dim

    #define CORE_DB_USR_LOG_GRP_NM              4 // max four char as group name
    #define CORE_DB_USR_LOG_USR_NM             12 // max twelve char as short user name
    #define CORE_DB_USR_LOG_USR_NM_LONG        32 // max thirtytwo char as long user name

    #define CORE_DB_USR_LOG_SECTORS_IN_USE     12 // adjust sectors to use, minimum 3, maximum 12 -- if changed & sim is used, be sure to delete C0_FlashExt.dat followed by a clean build


    //! database log action
    typedef enum
    {
        LOG_USER_NAME,          //   0
        LOG_USER_NAME_LONG,     //   1

        LOG_DB_RAM_CHANGE,      //   2 - Everything Okay - RAM Change
        LOG_DB_LIST_STORE,      //   3 - STORE the Full RAM list  (COM-Id =0xFFF1/List-Idx=0xF1, Arr-Idx=List-Idx, other values are invalid)
        LOG_DB_OKAY_SGL_STORE,  //   4 - Everything Okay - NVM Change eCoreDbServerLinkVarStore()
        LOG_DB_NVM_LIST_CHA,    //   5 - Change between NVM-Load-List and NVM-Store-List
        LOG_DB_IDX_CHA,         //   6 - Parameter index was changed (Auto store)
        LOG_DB_RANG_ERR,        //   7 - Min / Max was changed       (Auto store)
        LOG_DB_FRMT_CHA,        //   8 - List format was changed     (Auto store)
        LOG_DB_CRC_ERR,         //   9 - CRC is no longer correct (COM-ID=0xFFF3/List-Idx=0xF3, Arr-Idx=List-Idx, other values are invalid)
        LOG_DB_REC_LIMIT,       //  10 - Reach the Record Limit in that session ( 1364 (2048) new records)
                                //                                (COM-ID=0xFFF4/List-Idx=0xF4, Arr-Idx=List-Idx, other values are invalid)
        LOG_DB_REC_CRC_ERR,     //  11 - Record a invalid         (COM-ID=0xFFF5/List-Idx=0xF5, Arr-Idx=List-Idx, other values are invalid)
        LOG_DB_FULL_RSTR_STRT,  //  12 - Restore is starting     (Auto store)
        LOG_DB_FULL_RSTR_END,   //  13 - Restore has ended       (Auto store)
        LOG_DB_FULL_BCKP,       //  14 - Backup was done         (Auto store)

        // Error Management
        LOG_ERRLIST_DEL,
        LOG_ERRLIST_LOAD,
        LOG_ERRLIST_STORE,
        LOG_ERRLIST_ACTIV,
        LOG_ERRLIST_DEACTIV,
        LOG_ERRFORCE_RM_SET,
        LOG_ERRFORCE_SC_SET,
        LOG_ERRFORCE_RC_SET,
        LOG_ERRFORCE_EX_SET,
        LOG_ERRFORCE_RM_CLEAR,
        LOG_ERRFORCE_SC_CLEAR,
        LOG_ERRFORCE_RC_CLEAR,
        LOG_ERRFORCE_EX_CLEAR,

        LOG_DB_EMPTY = 0xFF      // 255 - Empty entry
    }ECoreDbUsrLogAct;

    //! database log filter action
    typedef enum
    {
        FLT_DB_NVM_LIST_CHA     = 5,    //   5 - Change between NVM-Load-List and NVM-Store-List
        FLT_DB_IDX_CHA          = 6,    //   6 - Parameter index was changed (Auto store)
        FLT_DB_RANG_ERR         = 7,    //   7 - Min / Max was changed       (Auto store)
        FLT_DB_FRMT_CHA         = 8,    //   8 - List format was changed     (Auto store)
        FLT_DB_CRC_ERR          = 9,    //   9 - CRC is no longer correct (COM-ID=0xFFF3/List-Idx=0xF3, Arr-Idx=List-Idx, other values are invalid)
        FLT_DB_MAX              = 10,

        FLT_DB_EMPTY        = 0xFF  // 255 - Empty entry
    }ECoreDbUsrFltLogAct;

    //! database log record
    typedef struct
    {
        TUint8              u8ListIdx;
        TUint8              u8VarIdx;
        TUint8              u8VarArrIdx;
        TUint32             u32OldVal;
        TUint32             u32NewVal;
        TUint8              u8Crc;
    }TCoreDbUsrLogRec;  // >20 Bytes -> 16*16= 256 support a quick write!

    //! database log record
    typedef struct
    {
       TUint32              u32FaultCode;  // gepackt mit u32PackErrorCode(...)
       TUint64              u64Rm;
       TUint32              u32ScRcEx;
    }TCoreDbUsrLogRecErr;

    //! database short name log record
    typedef struct
    {
        TChar           achUserName[CORE_DB_USR_LOG_USR_NM];
    }TCoreDbUsrLogRecName;

    //! database long name log record
    typedef struct
    {
        TChar           achUserName[CORE_DB_USR_LOG_USR_NM_LONG];
    }TCoreDbUsrLogRecNameLong;

    //! database action log record
    typedef struct
    {
        EAccLevel        eAccLev;
        TUint8           u8UserId;
        TUint32          u32LogTime;
        TChar            achGrpName[CORE_DB_USR_LOG_GRP_NM];      //e.g. CORE, APP, MST, DMX, COPE (CanOpen), UDS, ....
        ECoreDbUsrLogAct eLogAct;
    }TCoreDbUsrLogRecAction;

    // use a union to select from different sources
    typedef union
    {
       TCoreDbUsrLogRec             tRecDb;
       TCoreDbUsrLogRecErr          tRecErr;
       TCoreDbUsrLogRecName         tRecUserShort;
       TCoreDbUsrLogRecNameLong     tRecUserLong;
    }UCoreDbUsrLogRec;

    // the actual db record that is stored in the database
    typedef struct
    {
       TCoreDbUsrLogRecAction  tRecAct;
       UCoreDbUsrLogRec        uLogRec;
    }TCoreDbUsrLogRecord;

    //! TUint16 union for communication id & list/var index
    typedef union UDbElem
    {
        TUint16 u16ComId;         //!< ComIdx
        TUint8  au8Idx[2];        //!< ListIdx & VarIx
    }UCoreDbUsrLogElem;

    //! database log default record
    typedef struct
    {
        //UCoreDbUsrLogElem   uElm;
        TUint16             u16ComId;
        TUint8              u8ListIdx;
        TUint8              u8VarIdx;
        TUint8              u8ArrIdx;
        EVarTyp             eVarType;
        TUint8              u8VarDlc;
        TUint32             u32ValOld;
        TUint32             u32ValNew;
    }TCoreDbUsrLogDfltRec;        // 12 Byte

    extern TCoreDbUsrLogDfltRec        g_atCoreDbUsrLogDfltRec[CORE_DB_USR_LOG_DFLT_REC];

    // active user information
    typedef struct
    {
        TUint8  u8OvrallUsrIds;                                     // current count of individual users id available from log db
        TUint8  u8CurrentActvUsrId;                                 // current user id in action
        TChar   achCurrentActvGrp[CORE_DB_USR_LOG_GRP_NM];          // current active group
        TChar   achCurrentActvName[CORE_DB_USR_LOG_USR_NM_LONG];    // current active name
    }TCoreDbUsrLogActvUsrInfo;

    extern TCoreDbUsrLogActvUsrInfo      g_tCoreDbUsrLogActvUsrInfo;

    // phases to know if back or restore is happening
    typedef enum
    {
        RSTR_BCKP_NO_PHASE,
        RSTR_BCKP_PHASE,
        RSTR_PHASE,
        BCKP_PHASE
    }ECoreDbUsrLogRstrBckpPhase;

    extern ECoreDbUsrLogRstrBckpPhase     g_eCoreDbUsrLogFlgBckpRstr;

    // know if log is active or reset & know when to delete all & is mst logging locked & use engine time
    typedef struct
    {
        TBoolean    boLogIsActive;
        TBoolean    boLogIsResetDb;
        TBoolean    boDeleteAll;
        TBoolean    boLogIsLocked;
        TBoolean    boLogIsUsingEngineTime;
        EAccLevel   eLogAccLevel;
    }TCoreDbUsrLogActvInfo;

    extern TCoreDbUsrLogActvInfo         g_tCoreDbUsrLogActvInfo;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Core Db Set Log Usr - Function for the usr log helper to set a user name.
    //! @param[in]  pchGrpName      - characters for group name
    //! @param[in]  pchUserName     - full user name
    //! @param[in]  u32UseTime      - time this function was used
    //! @retval      R_OKAY         - all good
    //! @retval      R_RANGE        - incoming user name too long
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbUsrLogSetUserName( TChar *pchGrpName, TChar *pchUserName, TUint32 u32UseTime );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Activate Usr Log - Function to activate usr log.
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogActivate( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Core Db Usr Log - Function that sets active (locks) MST logging (for application developers)
    //! @param[in]  boActive   - TRUE == logging is locked (can not be deactivated by mst) -- FALSE == logging is unlocked (can be deactivated by mst)
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogMstActivate( TBoolean boActive );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Usr Log status - Function returns current activation state.
    //! @retval  boActivated     - activated
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreDbUsrLogActivated( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the very last record in all sectors
    //! @retval      TCoreDbUsrLogRecord*        - pointer to requested entry
    //--------------------------------------------------------------------------------------------------
    extern TCoreDbUsrLogRecord* ptCoreDbUsrLogGetTheLastEntry( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Reinit Core Db Usr Log Fat
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogReinitLogFat( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get record end
    //! @retval      TCoreDbUsrLogRecord*        - pointer to requested entry
    //--------------------------------------------------------------------------------------------------
    extern TCoreDbUsrLogRecord* ptCoreDbUsrLogGetRecEnd( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get record first
    //! @retval      TCoreDbUsrLogRecord*        - pointer to requested entry
    //--------------------------------------------------------------------------------------------------
    extern TCoreDbUsrLogRecord* ptCoreDbUsrLogGetRecFirst( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get record zero
    //! @retval      TCoreDbUsrLogRecord*        - pointer to requested entry
    //--------------------------------------------------------------------------------------------------
    extern TCoreDbUsrLogRecord* ptCoreDbUsrLogGetRecZero( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      A complete database restore is starting
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogRecordFullRestoreStart( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      A complete database restore is ending
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogRecordFullRestoreEnd( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      A complete database backup is issued
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogRecordFullBackup( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Core Db Usr Log - Function for deleting a flash sector
    //! @retval  R_OKAY     - deletion was queued successful
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbUsrLogDeleteFlash( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief Core Db Usr Log - Store user db logging
    //! @note        Call in the vAppRun or eAppShutDown()
    //! @retval      R_OKAY     - okay
    //! @retval      R_BUSY     - function needs another cycle
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbUsrLogDbStore( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Core Db Usr Log - add db logging APP log entry
    //! @brief       This function will be triggered by protocol after changing parameters.
    //! @param[in]   u8UserId         - User Id (201..220)
    //! @param[in]   ptListRoot       - db list root for the entry point
    //! @param[in]   vpVar            - db variable for the entry point
    //! @param[in]   eType            - db type for the entry point
    //! @param[in]   u32OldVal        - Database old value (must be TUint32)
    //! @param[in]   u32NewVal        - Database new value (must be TUint32)
    //! @param[in]   eAccLevel        - ePtcMstGetAccessLevel()
    //! @retval      R_OKAY           - okay
    //! @retval      R_DB_LIST        - incorrect list root
    //! @retval      R_DB_TYPE        - incorrect type matching
    //! @retval      R_INCONSISTENT   - correct data
    //! @retval      R_NULL_POINTER   - ptDbLink is a null pointer
    //! @retval      R_SUPPORT        - no support
    //! @retval      R_BUFFER_FULL    - no more flash records
    //-------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbUsrLogAddAppEntry( TUint8 u8UserId, TDbListRoot *ptListRoot, TVoid *vpVar,  EVarTyp eType, TUint32 u32OldVal, TUint32 u32NewVal, EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Add user db logging PTC entry
    //! @brief      This function will be triggered by protocol after changing parameters.
    //! @param[in]  u8UserId     - User Id (1..200)
    //! @param[in]  u8ListIdx    - Database list index
    //! @param[in]  u8VarIdx     - Database variable index
    //! @param[in]  u8ArrIdx     - Database array index
    //! @param[in]  u32OldVal    - Database old value (must be TUint32)
    //! @param[in]  u32NewVal    - Database new value (must be TUint32)
    //! @param[in]  eAccLevel    - ePtcMstGetAccessLevel()
    //! @retval     R_OKAY       - fine
    //! @retval     R_SUPPORT    - u8UserId isn't in valid range
    //! @retval     R_EMPTY      - COM-ID not there
    //! @retval     R_RANGE      - Wrong VarMax
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbUsrLogAddPtcEntry( TUint8 u8UserId, TUint8 u8ListIdx, TUint8 u8VarIdx, TUint8 u8ArrIdx, TUint32 u32OldVal, TUint32 u32NewVal, EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Core Db Usr Log - Function returning log entry count
    //! @param[in]      boDftOrNvm  - Default or NVM list
    //! @retval     TUint16         - records count
    //--------------------------------------------------------------------------------------------------
    extern TUint16  u16CoreDbUsrLogEntryCount( TBoolean boDftOrNvm );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Core Db Usr Log - provide positions of usr name & id in log db
    //! @param[in]  u8UserId     - User Id to get (0x00 - 0x18) (24 max users)
    //! @param[in/out]      pu8UsrNameLen   - length of character data of usr name in log db
    //! @param[in/out]      pu8UsrName      - pointer to character data of usr name in log db
    //--------------------------------------------------------------------------------------------------
    extern TVoid  vCoreDbUsrLogUsrPosInDb( TUint8 u8UserId, TUint8* pu8UsrNameLen, TUint8* pu8UsrName  );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if user id exceeds max user possible
    //! @param[in]  u8UserId     - User Id (0..24)
    //! @retval     TRUE / FALSE       - id is in range / id exceeds max
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreDbUsrLogCheckIfUsrIdEceedsMax( TUint8 u8UserId );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Core Db Usr Log - Function that sets the access level allowing delete of MST user log (for application developers)
    //! @brief   ACC_ECU_ENG is set by default
    //! @param[in]  eAccLvl   - access level allowing deletion of MST usr log
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbUsrLogMstSetAccessLevel( EAccLevel eAccLvl );

#endif // COMPILER_SWITCH_USR_CHNG_MNGMNT_FEATURE

#endif
