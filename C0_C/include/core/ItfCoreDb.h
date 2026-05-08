//**************************************************************************************************
/*!
@file       ItfCoreDb.h
@brief      Database Interface
@date       28.04.2011 
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef  __ITFCOREDB__
    #define  __ITFCOREDB__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfBasEleErr.h>
    #include <ItfCore.h>
    #include <ItfCoreBoard.h>

// DEFINES & ENUMS  ================================================================================
    #define DB_STAMP          0xA05A    //!< DB-Stamp

    #define DB_NAME_STR_LEN   (32+1)    //!< Form obj configuration

    #define DB_EXT_LIST_FLA     250     //!< Special Flash Factory Setting List

    #define DB_COMID_UNDEF    0xFFFF    //!< undefined COMID

    //! Variable data types
    typedef enum
    {
        TBOOLEAN,                       //!<  0
        TBIT2,                          //!<  1
        TBIT3,                          //!<  2
        TBIT4,                          //!<  3
        TBIT5,                          //!<  4
        TBIT6,                          //!<  5
        TBIT7,                          //!<  6
        TCHAR,                          //!<  7
        TINT8,                          //!<  8
        TUINT8,                         //!<  9
        TINT16,                         //!< 10
        TUINT16,                        //!< 11
        TINT32,                         //!< 12
        TUINT32,                        //!< 13 - Data type
        TFLOAT32,                       //!< 14 - Data type Float32
        TCNTU8,                         //!< 15 - Message counter data type U8
        TMUXU8,                         //!< 16 - Signal record message multiplexer type U8
        TCNTU16,                        //!< 17 - Message counter data type U16
        TMUXU16,                        //!< 18 - Signal record message multiplexer type U8
        TINCU8,                         //!< 19 - Multiplexer inverse data type U8
        TSTRING,                        //!< 20 - String
        TYPE_NA                         //!< 21 - No Type - important for CAN-INFO-Record
    }EVarTyp;

    //! Data base class type
    typedef enum
    {
        DB_NVM_OPT,                     //!< 0 - options / configurations
                                        //!<     + for example which structure is connected to which input
                                        //!<     + is loaded before the HW initialization, is loaded before all other data
        DB_RAM_ECU,                     //!< 1 - state variables and reset values
                                        //!<     + gets the default values form the code (1 default data set)
                                        //!<     + global variables, accessible with the service tool.
        DB_NVM_PAR,                     //!< 2 - standard parameter, will be saved to the EPROM
                                        //!<     + values are changeable by the Service Tool, will be saved to the EPROM
                                        //!<     + more than one default lists available (machine values, options, ...
                                        //!<      -> which default lists can be managed by the configuration list
        DB_NVM_CAL,                     //!< 3 - values for calibration
                                        //!<     + only one default list
                                        //!<     + intended for application defined special behavior during software update
        DB_NVM_MEM,                     //!< 4 - Memory
                                        //!<     + Memory values will be saved after K15 is off
        DB_NVM_SHA                      //!< 5 - NVM shadow list
    }EDbClass;

    //! Data base class type
    typedef enum
    {
        DB_RAM,                         //!< RAM list type
        DB_NVMEM                        //!< NVMEM list type
    }EDbListType;

    //! List state
    typedef enum
    {
        DB_LIST_DFLT,                   //!< List state: List contains the default values
        DB_LIST_READY,                  //!< List state: List is ready
        DB_LIST_LOADING                 //!< List state: List is currently loading
    }EListStatus;

    //! Variable DB/Version Access Permission
    typedef enum
    {
        VAR_ACCPERM_NONE,                   //!< No Access
        VAR_ACCPERM_READ,                   //!< Only Read Access
        VAR_ACCPERM_WRITE                   //!< Only Write Access
    }EVarRwPerm;

    //! Nvm Server Commands
    typedef enum
    {
       NVM_SERVER_STA_FREE,                 //!< 0 Status Free
       NVM_SERVER_STA_NVM_LOCKED,           //!< 1 Simple Load                                  -> eCoreNvmServerClose()
                                            //!<                                                   eCoreNvmRead(), eCoreNvmWrite()
                                            //!<                                                   eCoreNvmServerOpen()
       NVM_SERVER_STA_DB_VAR_LOAD,          //!< 2 Status Load DB Variable            [ReqNo++] -> eCoreDbLinkVarLoad()
       NVM_SERVER_STA_DB_VAR_STORE,         //!< 3 Status Store DB Variable           [ReqNo++] -> eCoreDbServerLinkVarStore()
       NVM_SERVER_STA_DB_LIST_LOAD,         //!< 4 Status/Command Load DB List(+Head) [ReqNo++] -> eCoreDbLinkLoadList(),  eCoreDbLoadList()
       NVM_SERVER_STA_DB_LIST_STORE,        //!< 5 Status/Command DB List(+Head)      [ReqNo++] -> eCoreDbLinkStoreList(), eCoreDbStoreList()
       NVM_SERVER_STA_DB_LIST_HEAD_STORE,   //!< 6 Status/Command DB List(-Data)      [ReqNo++] -> eCoreDbStoreListHead()
       NVM_SERVER_STA_FAULT_STORE,          //!< 7 Status/Command Fault(Err/Eve)Stack [ReqNo++] -> eCoreErrEveListStore()
       NVM_SERVER_STA_SERVICE,              //!< 8 Status Service Call                          -> auto trigger (gEcu_tSys.tFault.u16FaultStoreTime )

       NVM_SERVER_STA_DB_STAT_FLAG_STORE,   //!< 9 Status Store DB status flags       [ReqNo++] -> eCoreDbDiagRangeCheckReset(), eCoreDbDiagRangeCheckResetList()
                                            //!<                                                   eCoreDbDiagRangeCheckStoreList()

       NVM_SERVER_STA_LICENSE_STORE,        //!< 10 Status Store licenses             [ReqNo++] -> eCoreLicStoreAll()

       NVM_SERVER_STA_FLASH_READ,           //!< 11 External Flash Read               [ReqNo++] -> eQueueFlashRead()
       NVM_SERVER_STA_FLASH_WRITE,          //!< 12 External Flash Write              [ReqNo++] -> eQueueFlashWriteFlash()
       NVM_SERVER_STA_FLASH_CLEAR           //!< 13 External Flash Clear              [ReqNo++] -> eQueueFlashSectorDelete()


    }ENvmServerSta;

    #ifdef COMPILER_SWITCH_ENV_CEN
        #ifdef COMPILER_SWITCH_DB_LIST_64
            #define DB_LIST_MAX    64       //!< Maximum number of DB lists
        #else
            #define DB_LIST_MAX    32       //!< Maximum number of DB lists
        #endif
    #else
        // TTC5x - CoDeSys
        #define DB_LIST_MAX        16       //!< Maximum number of DB lists
    #endif
    // List types

    //RAM and NVMEM list mode
    #define DB_SINGLE               0       //!< Single list
    #define DB_DOUBLE               1       //!< Double list

    // Variable kind
    #define DB_FCT                  0       //!< DB list variable connection with a function pointer
    #define DB_VAR                  1       //!< DB list variable a primitive type variable
   // else Array ->   Dim 2 - 31
    #define DB_ARR_MF             0x20      //!< Array - monotonic falling
    #define DB_ARR_SMF            0x40      //!< Array - strictly monotonic falling
    #define DB_ARR_MR             0x60      //!< Array - monotonic rising
    #define DB_ARR_SMR            0x80      //!< Array - strictly monotonic rising
    // Free 0xA0 / 0xC0 / 0xE0

    // NVMEM address
    #define DB_ADR_NA              U16_MAX  //!< Automatic NVMEM address calculation

// RAM/NVMEM ---------------------------------------------------------------------------------------

    //! [ro] NVMEM head part
    typedef struct
    {
        TUint16  u16DfltParamIdx;           //!< [ro][NUM] List default parameter index
        TUint16  u16FlaParamIdx;            //!< [ro][NUM] Flash parameter index
        TUint16  u16Crc;                    //!< [ro][NUM] CRC of the list (NvMem) for Load-/Store list
        TUint16  u16VarMax;                 //!< [ro][NVM] Variable Cnt (imported for the update detection)
        TUint16  u16ShadowBytes;            //!< [ro][NVM] Size of bytes in list (imported for the update detection)
        TUint16  u16User;                   //!< [ro][NVM] Reserve for the User
    }TDbHeadNvm; // 12 Bytes

    #define DFLT_SET_FALSE  0               //!< Don't Load the default set

     //! [rw] Change Option for the default and flash setting
    typedef struct
    {
        // Command
        TUint8   u8ComandDfltSet;           //!< [rw][NUM] - Load default set, if the value is not equal 'DFLT_SET_FALSE'
        TBoolean boComandFlashSetUpdate;    //!< [rw][NUM] - Flash factory setting update

        // From configurator
        const TUint8   cu8DfltSetParamIdx;  //!< [ro][NUM] - Load default set, if the Dflt-Param-Idx is changing and value not equal 'DFLT_SET_FALSE'
        const TUint8   cu8DfltSetFoundErr;  //!< [ro][NUM] - Load default set, if an DB-List error is found
        const TBoolean cboFlashChaParIdx;   //!< [ro][DEF] - Update the List with the Flash-Setting, if the Flash-Param-Idx is changed
        const TBoolean cboFlashFoundErr;    //!< [ro][DEF] - Update the List with the Flash-Setting, if an error is detected
        const TBoolean cboFlashChaFlaSet;   //!< [ro][DEF] - Update the List with the Flash-Setting, if the flash setting is changed
    }TDbChaOpt;

    //! [rw] RAM/NVMEM List Header for each list
    typedef struct
    {
        // General Information
        TBehErr    tBehErr;                 //!< [rw][STU] - Block error behavior status [status & control]
        TDbChaOpt  tChaOpt;                 //!< [rw][STU] - Change option
        TDbHeadNvm tNvm;                    //!< [ro][STU] - DB-Head-Store values
    }TDbHead;

    //! [ro] List reference
    typedef struct
    {
        TUint8     u8ListIdx;               //!<[ro][NUM] - List Index in database entry
        TVoid*     pvListPoi;               //!<[ro][VOI] - List pointer in database entry (redundant for the safety)
        TEleErrAdr tEleErrAdr;              //!<[ro][STU] - Error element address
        TUint16    u16Stamp;                //!<[ro][NUM] - Safety stamp
    }TDbListRef;

    //! [rw] List behavior
    typedef struct
    {
        EListStatus eStatus;                //!< [ro][ENU] - List information
        TDbHead     tHead;                  //!< [rw][STU] - List header
        TDbListRef  tPrivateRef;            //!< [ro][STU] - List reference
    }TDbListRoot;

    //! [ro] Flash behavior
    typedef struct
    {
        EListStatus eStatus;                //!< [ro][ENU] - List information
        TUint32     u32Crc;                 //!< [ro][NUM] - Flash setting change check number
        TUint32     u32Pw;                  //!< [ro][NUM] - Flash setting password
        TBehErr     *ptBehErr;              //!< [ro][STU] - Error behavior status [status & control]
    }TDbFlashRoot;

// NVMEM ---------------------------------------------------------------------------------------

    //! [ro] Variable information field
    typedef struct
    {
        TUint16 u16AccCode;          //!< [ro][bitCode] Read/write access for
                                     //!< CUS0_1   -> Customer
                                     //!< DEA2_3   -> Dealer
                                     //!< PRO4_5   -> Production
                                     //!< SER6_7   -> Service
                                     //!< OEM8_9   -> OEM
                                     //!< SYS10_11 -> Sys.Int.
                                     //!< ENG12_13 -> Engineer
                                     //!< DEV14_15 -> Development

        TUint16 u16ComId;            //!< [ro][NUM] Comm.ID
        EVarTyp eType;               //!< [ro][DEF] Data type
        TUint8  u8FctVarDim;         //!< [ro][NUM] Data dimension
    }TDbVarInf; //Const

    //! [ro] Variable table for the RAM variable
    typedef struct
    {
        const TDbVarInf  *cptInf;     //!< [ro][STC] Const
        TVoid            *vpVal;      //!< [ro][   ] Value
        const TVoid      *cvpDef;     //!< [ro][   ] Const - Default
        const TVoid      *cvpRng;     //!< [ro][   ] Const - Range
    }TDbVarTabRam;

    //! [ro] Variable table for the NVMEM variable
    typedef struct
    {
        const TDbVarInf  *cptInf;       //!< [ro][STU] Const - Information field
        TVoid            *vpVal;        //!< [ro][   ]       - Value
        const TVoid      *cvpDef;       //!< [ro][   ] Const - Default
        const TVoid      *cvpRng;       //!< [ro][   ] Const - Range
        const TUint16    cu16Adr;       //!< [ro][NUM] const - NvMem address
        const TUint16    cu16ValuePos;  //!< [ro][NUM] const - [bit] position in flags fields of addressable value
    }TDbVarTabNvm;

    //! [ro] Part struct for the TDbList - define of the errors
    typedef struct
    {
        EErrTyp eErrTyp;             //!< [ro][DEF] Type of categories
        EErrCat eErrCat;             //!< [ro][DEF] Error category
        TUint16 u16ErrAccLevel;      //!< [ro][DEF] Error access level
        TUint32 u32ErrNum;           //!< [ro][NUM] Error number
        TUint8  u8ErrMode;           //!< [ro][DEF] Failure mode indicator
        TUint8  u8ErrModeExt;        //!< [ro][DEF] Extern failure mode indicator
        TUint8  u8RestrictMode;      //!< [ro][DEF] Restricted mode [bit position 0-63]
    }TDbListErr;

    //! [ro] DB list definition
    typedef struct
    {
        //** General list settings
        TChar               achName[DB_NAME_STR_LEN];  //!< [ro][STR] List name
        EDbClass            eListClass;                //!< [ro][ENU] List class
        EDbListType         eListType;                 //!< [ro][ENU] List type
        TUint8              u8ListIdx;                 //!< [ro][NUM] List index (start for each ECU by 0)
        TUint16             u16VarMax;                 //!< [ro][NUM] Max variable
        TUint16             u16NumValues;              //!< [ro][NUM] Number of addressable values in list(counting each array value)
        TUint16             u16ShadowBytes;            //!< [ro][NUM] need shadow RAM in byte
        TUint32             u32Password;               //!< [ro][NUM] List password needed for PTC
        TDbListRoot        *ptListRoot;                //!< [ro][NUM] ListRoot
      //** RAM general setting
        const TDbVarTabRam *cptRamVarTab;              //!< [ro][STC] Pointer of the first variable
        TUint8              u8RamMode;                 //!< [ro][DEF] Single/Double
        TBoolean            boRamCrc;                  //!< [ro][DEF] with CRC
      //** NVMEM general setting
        const TDbVarTabNvm *cptNvmVarTab;              //!< [ro][STC] Pointer of the first variable
        TUint8              u8NvmDfltSet;              //!< [ro][NUM] Count of maximal default sets
        TUint16             u16NvmDfltParamIdx;        //!< [ro][NUM] Dflt param Idx for the default sets
        TUint16             u16NvmFlashParamIdx;       //!< [ro][NUM] Flash param Idx for the flash sets
        TUint8              u8NvmLoadDfltSetChaParIdx; //!< [ro][NUM] Dflt param Idx has change - load that default set
        TUint8              u8NvmLoadDfltSetFoundErr;  //!< [ro][NUM] List error is there - load that default set
        TBoolean            boNvmLoadFlashChaParIdx;   //!< [ro][NUM] Flash param Idx has change - load that flash setting
        TBoolean            boNvmLoadFlashFoundErr;    //!< [ro][NUM] List error is there - load that flash setting
        TBoolean            boNvmLoadFlashChaFlaSet;   //!< [ro][NUM] Flash setting has change - load that flash setting
        TBoolean            boNvmValueRangeCheck;      //!< [ro][NUM] List Range Check(Store Flag)
        TUint8              u8NvmListMode;             //!< [ro][DEF] Single/Double - list mode
        TBoolean            boNvmCrc;                  //!< [ro][DEF] with CRC
        TUint16             u16NvmSingleStartAdr;      //!< [ro][NUM] Single NVMEM start address
        TUint16             u16NvmDoubleStartAdr;      //!< [ro][NUM] Double NVMEM start address
       //** Error (RAM/NvMem)
        TDbListErr          atDbErr[4];                //!< [ro][STC] RAM/NVMEM error
    }TDbList; //Const

    //! [ro] Database root
    typedef struct
    {
        TUint8  u8VersMajor;                           //!< [ro][NUM] - Database version number major
        TUint8  u8VerMinor;                            //!< [ro][NUM] - Database version number minor
        TUint32 u32DbmCheckNo;                         //!< [ro][NUM] - Database check number
        TUint8  u8ListMax;                             //!< [ro][NUM] - Count of lists
        const TDbList* pctListTab;                     //!< [ro][STC] - Pointer to the first list entry
    }TDbRoot;

    #define DB_LINK_NA 0xFF                            //!< No DB link for that can record variable
    #define VAR_NA     0                               //!< No special variable value

    //! Db list connection
    typedef struct
    {
        TUint8   u8ListIdx;                            //!< [-] - List index     (start with 0 )
        TUint8   u8VarIdx;                             //!< [-] - Variable index (start with 0 )
        TUint8   u8VarArrIdx;                          //!< [-] - Variable array index (start with 0 )
    }TDbLink;

    //! Db variable link for TINT8
    typedef struct
    {
        TInt8     i8Var;                               //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkI8Var;

    //! Db variable link for TUINT8
    typedef struct
    {
        TUint8    u8Var;                               //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkU8Var;

    //! Db variable Link for TINT16
    typedef struct
    {
        TInt16    i16Var;                              //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkI16Var;

    //! Db variable link for TUINT16
    typedef struct
    {
        TUint16   u16Var;                              //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkU16Var;

    //! Db variable link for TINT32
    typedef struct
    {
        TInt32    i32Var;                              //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkI32Var;

    //! Db variable link for TUINT32
    typedef struct
    {
        TUint32   u32Var;                              //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkU32Var;

    //! Db variable link for TFLOAT32
    typedef struct
    {
        TFloat32  f32Var;                              //!< Value
        TDbLink   tDbLink;                             //!< DB link
    }TDbLinkF32Var;

    //! Variable DB/Version Access Mode
    typedef enum
    {
        VAR_ACCMODE_NONE,                              //!< No Access
        VAR_ACCMODE_READ_ONLY,                         //!< Only Read Access
        VAR_ACCMODE_WRITE_ONLY,                        //!< Only Write Access
        VAR_ACCMODE_READ_WRITE                         //!< Full Access / Read and Write
    }EVarAccMode;

    //! NVMEM Load/Store fading
    typedef struct
    {
        TUint32 u32LoadDbCnt;                          //!< [num]  counts of load db-lists
        TUint32 u32StoreDbCnt;                         //!< [num]  counts of store db-lists
        TUint32 u32StoreErrCnt;                        //!< [num]  counts of store the errors
        TUint32 u32StoreMemCnt;                        //!< [num]  counts or store the mem field
    }TNvMemFading;

    //! Application Information for the Db-Lists
    typedef struct
    {
        TUint8    u8DbVersionMajor;                    //!< [num] Db Major Versions Number
        TUint8    u8DbVersionMinor;                    //!< [num] Db Minor Versions Number
        TUint32   u32DbPrimareCheckSum;                //!< [num] Db CheckSum for the primary application
        TBoolean  boDbSecondAppActive;                 //!< [DEF] The Extended Application Layer is Active
        TUint32   u32DbSecondCheckSum;                 //!< [num] Db CheckSum for the Second Application
        TUint8    u8DbSecondListOffset;                //!< [num] List Offset for the Second Application
    }TDbAppInfo;

    extern const TDbRoot gDb_ctRoot;                   //!< @globvar create by the PDT [DB root entry]
    extern const TDbList gDb_catList[];                //!< @globvar create by the PDT [DB lists entry]

// LIBRARY PROTOTYPES ==============================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show that the Db is there
    //! @retval     TRUE  - is there
    //! @retVal     FALSE - is not there
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreDbIsThere( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy the db application information to the pointer
    //! @param[out] ptDbAppInfo - copy the information to that pointer
    //! @retval     R_OKAY          - information are there
    //! @retval     R_EMPTY         - information is not there (information are ready in the middle of the MAIN_CORE_START_UP)
    //! @retval     R_NULL_POINTER  - the ptDbAppInfo pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbAppInfo( TDbAppInfo *ptDbAppInfo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the nvmem fading information
    //! @param[out] ptFading - copy the fading information to that pointer
    //! @retval     R_OKAY
    //! @retVal     R_NULL_POINTER
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreNvmGetFadint( TNvMemFading *ptFading );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Flash Crc
    //! @return     Crc
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreDbFlashCrc( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Db List Default Index
    //! @param      u8ListIdx - DB List
    //! @retval     Default Parameter Index < U16_MAX
    //! @retval     U16_MAX invalid List Index
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreDbListDfltParamIdx( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Db variable element information
    //! @param[in]  cptDbLink      - List index, Variables index, Array value - (all start with 0)
    //! @param[out] pu16ComId      - ComId               (NULL-Pointer save)
    //! @param[out] peVarType      - Variable type       (NULL-Pointer save)
    //! @param[out] pu8Byte        - Variable Byte Count (NULL-Pointer save)
    //! @param[out] pu16AccCode    - Access Level        (NULL-Pointer save)
    //! @retval     R_OKAY         - fine
    //! @retval     R_DB_LIST      - List-Index out of range
    //! @retval     R_DB_VAR       - Variable-Index out of range
    //! @retval     R_DB_DIM       - Array-Index out of range
    //! @retval     R_INCONSISTENT - DB-List
    //! @retval     R_NULL_POINTER - Pointer is Null
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkVarInfo( const TDbLink *cptDbLink, TUint16 *pu16ComId, EVarTyp *peVarType, TUint8 *pu8Byte, TUint16 *pu16AccCode );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Get Dflt indices for changed parameter and error
    //! @param[in]  u8ListIdx       - List index
    //! @param[out] pu8ChaDfltIdx   - u8NvmLoadDfltSetChaParIdx
    //! @param[out] pu8ErrDfltIdx   - u8NvmLoadDfltSetFoundErr
    //! @retval     R_OKAY         - ok
    //! @retval     R_DB_LIST      - List-Index out of range
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbChaErrDfltIdx( TUint8 u8ListIdx, TUint8* pu8ChaDfltIdx, TUint8* pu8ErrDfltIdx );

    //==============================================================================================
    //              Nvmem Server functions
    //==============================================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Nvm Server Status
    //! @param[out] peRetVal  - internal return value of the last server command,
    //!                         (e.g. result of load db list operation triggered by eCoreDbLoadList() )
    //!                         - R_OKAY    - finished successfully
    //!                         - R_BUSY    - still running
    //!                         - R_UNKNOWN - aborted with error
    //!                         - other     - aborted with process specific error
    //!                         (e.g. load DB List: R_SUPPORT invalid list, R_PARAMETER defaults loaded)
    //! @param[out] pu16ReqNo - request number of the last started nvmem server command. \n
    //!                         This number can be used to identify if status/return value relates to specific user triggered command. \n
    //!                         The request number is increased after successfully starting a nvmem server command
    //!                         ( trigger function returns R_OKAY ). \n
    //!                         u16CoreNvmServerReqNo() can be used to get number immediately after starting a nvmem request.
    //! @return     Server Status - see #ENvmServerSta for possible values and relation to triggering functions
    //--------------------------------------------------------------------------------------------------
    extern ENvmServerSta eCoreNvmServerStatus( ERetVal *peRetVal, TUint16 *pu16ReqNo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Nvm Server Requested Number
    //!               Requested number
    //!                change the number if the function call return R_OKAY
    //!                  NVM_SERVER_STA_DB_VAR_LOAD   -> eCoreDbLinkVarLoad(..)
    //!                  NVM_SERVER_STA_DB_LIST_LOAD  -> eCoreDbLinkLoadList (..), eCoreDbLoadList(..)
    //!                  NVM_SERVER_STA_DB_LIST_STORE -> eCoreDbLinkStoreList(..), eCoreDbStoreList(..)
    //!                  NVM_SERVER_STA_FAULT_STORE   -> eCoreErrEveListStore()
    //! @return     Number
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreNvmServerReqNo( TVoid );

    //==============================================================================================
    //            Data pool action functions - over the LIST-ROOT-POINTER
    //==============================================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the ListRoot back
    //! @param[in]  u8ListIdx   - List index
    //! @param[out] peListType  - Give list type  (if that is not from interest use NULL)
    //! @param[out] peListClass - Give list class (if that is not from interest use NULL)
    //! @retval     TDbListRoot or NULL (it u8ListIdx is to big)
    //--------------------------------------------------------------------------------------------------
    extern TDbListRoot *ptCoreDbGetListRoot( TUint8 u8ListIdx, EDbListType *peListType, EDbClass *peListClass );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the maximum of the data base list
    //! @return     total number of DB lists
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreDbGetListMax( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the maximum of variable in db-List[u8ListIdx] quantity
    //! @param      u8ListIdx
    //! @retval     maximum variable count
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreDbGetListVarMax( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the ShadowBytes
    //! @param[in]  u8ListIdx
    //! @retval     ShadowBytes
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreDbGetShadowBytes( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the Variable Access Mode
    //! @param[in]  eAccLevel     - Access Level
    //! @param[in]  u16AccCode    - Access Code (from DB-Info-Record or from the Ver-Extended-Struct)
    //! @return     Read/Write Mode
    //--------------------------------------------------------------------------------------------------
    extern EVarAccMode eCoreGetVarAccess( EAccLevel eAccLevel, TUint16 u16AccCode );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Automatic DB-List store with K15=OFF (call e.g AppRun() )
    //! @param[in]  u8ListIdx
    //! @retval     R_OKAY  - OK
    //! @retval     R_RANGE - ListIdx to high
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbListShutDownStore( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Command to set the default and/flash settings default to the list load process in the ecu starting process
    //!             This function can only called in the application "Pre Start"/"Start Up" phase.
    //!             If an valid u8DfltSet!=DFLT_SET_FALSE - the list get an auto store.
    //!             If u8DfltSet=DFLT_SET_FALSE an the boFlashUpdate=TRUE, the list will load from the nvmem,
    //!             and if that is successful the flash-setting will overwrite the list values (with no auto store)
    //!             Option lists work ONLY in the "Pre-Start"-phase (that can't check! ->if that is wrong there is no negative return value
    //!             and it is not possible to check the correct Dflt-Set, an incorrect Dflt-Set have no effect)
    //!             In the "Start Up" phase - that will be check, and all list are work there except the "options lists"
    //! @param[in]  ptListRoot    - The Db list
    //! @param[in]  u8DfltSet     - Default set [start with 1..n] ( DFLT_SET_FALSE make nothing )
    //! @param[in]  boFlashUpdate - Flash setting has influence on list value(s)
    //! @retval     R_OKAY
    //! @retval     R_BUSY         - Command isn't taken an other command is running
    //! @retval     R_DB_DEFSET    - Wrong default set
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_PHASE        - Function was not called in the App-"Pre Start" or "Start Up" phase
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbListDfltSetCmdStart( TDbListRoot *ptListRoot, TUint8 u8DfltSet, TBoolean boFlashUpdate );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load NvMem-List from NvMem to the RAM
    //!             -> if there is something wrong - CRC error, flash isn't stamp, NvMem error, list order
    //!                the error default set will load and stored to the NvMem (if possible)
    //!             -> if the parameter Idx has changed
    //!                the Param-default set will load and stored to the NvMem
    //!             -> this function give the task to the 'nvm server device' - to check the request use eCoreNvmServerStatus(..)
    //! @param[in]  ptListRoot     - The Db list
    //! @retval     R_OKAY         - Command is taken
    //! @retval     R_BUSY         - Command isn't taken an other command is running
    //! @retval     R_DB_TYPE      - Wrong DB list
    //! @retval     R_NULL_POINTER - NULL pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLoadList( TDbListRoot *ptListRoot );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load all default values from 'FLASH' into the Ram list
    //! @param[in]  ptListRoot      - The Db list
    //! @param[in]  u8DfltSet       - Default set   [start with 1...]
    //! @retval     R_OKAY
    //! @retval     R_DB_TYPE       - No nvmem list
    //! @retval     R_DB_DEFSET     - Wrong default set
    //! @retval     R_SUPPORT       - Don't support function values
    //! @retval     R_NULL_POINTER  - Wrong NULL pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLoadDfltList( TDbListRoot *ptListRoot, TUint8 u8DfltSet );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load 'flash settings' into given list
    //! @param[in]  ptListRoot      - The Db list index
    //! @retval     R_OKAY          - OK
    //! @retval     R_DB_TYPE       - No valid database list
    //! @retval     R_EMPTY         - Nothing have change
    //! @retval     R_NOACT         - No new Factory Setting
    //! @retval     R_INCONSISTENT  - Factory Setting is inconsistent
    //! @retval     R_RANGE         - Variable not in valid range (one for the write process)
    //! @retval     R_NULL_POINTER  - Parameter is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLoadFlashSetting( TDbListRoot *ptListRoot );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Store the NvMem list to the NvMem (From the RAM to the NvMem)
    //!             -> this function give the task to the 'nvm server device' - to check the request use eCoreNvmServerStatus(..)
    //! @param[in]  ptListRoot - the Db list
    //! @retval     R_OKAY          - store process started, query NvMem server to see if process is finished
    //! @retval     R_BUSY          - is in used
    //! @retval     R_DB_TYPE       - is not the correct type
    //! @retval     R_NULL_POINTER  - ptListRoot is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbStoreList( TDbListRoot *ptListRoot );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Store the NvMem list Head to the NvMem (From the RAM to the NvMem)
    //!             -> this function give the task to the 'nvm server device' - to check the request use eCoreNvmServerStatus(..)
    //! @param[in]  ptListRoot - the Db list
    //! @retval     R_OKAY          - store process started, query NvMem server to see if process is finished
    //! @retval     R_BUSY          - is in used
    //! @retval     R_DB_TYPE       - is not the correct type
    //! @retval     R_NULL_POINTER  - ptListRoot is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbStoreListHead( TDbListRoot *ptListRoot );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return default and range value (only for special locations)
    //! @param[in]  ptListRoot - the Db list
    //! @param[in]  vpVar      - Variable/array-variable-element (element must be in 'ptListRoot')
    //! @param[in]  eType      - Variable type
    //! @param[in]  u8DfltSet  - Default set
    //! @param[out] vpDef      - Default value
    //! @param[out] vpMin      - Minimum value
    //! @param[out] vpMax      - Maximum value
    //! @retval     R_OKAY
    //! @retval     R_DB_DEFSET    - Default set number to high
    //! @retval     R_DB_TYPE      - Variable type not possible
    //! @retval     R_INCONSISTENT - Variable isn't in that list 'ptListRoot'
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbGetDfltRange( TDbListRoot *ptListRoot, TVoid *vpVar, EVarTyp eType, TUint8 u8DfltSet, TVoid *vpDef, TVoid *vpMin, TVoid *vpMax );

    //==============================================================================================
    //            Data pool action functions - over the DB link/index
    //==============================================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load the NvMem list form NvMem to the RAM
    //!             -> if there is something wrong - CRC error, flash isn't stamp, NvMem error, list order
    //!                the error default set will load and store on the NvMem (if possible)
    //!             -> if the parameter Idx has changed
    //!                the Param-default set will load and store on the NvMem
    //!             -> this function give the task to the 'nvm server device' - to check the request use eCoreNvmServerStatus(..)
    //! @param[in]  u8ListIdx      - The Db list index
    //! @retval     R_OKAY         - Command is taken
    //! @retval     R_BUSY         - Command isn't taken a other command is running
    //! @retval     R_DB_TYPE      - Wrong DB list
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkLoadList( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load all default values from 'FLASH' into the Ram list
    //! @param[in]  u8ListIdx       - The Db list index
    //! @param[in]  u8DfltSet       - Default set [start with 1...]
    //! @retval     R_OKAY
    //! @retval     R_DB_TYPE       - No valid database list
    //! @retval     R_DB_DEFSET     - Wrong default set
    //! @retval     R_SUPPORT       - Don't support function values
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkLoadDfltList( TUint8 u8ListIdx,  TUint8 u8DfltSet );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load 'flash settings' into given list identified by u8ListIdx
    //! @param[in]  u8ListIdx       - The Db list index
    //! @retval     R_OKAY          - OK
    //! @retval     R_DB_TYPE       - No valid database list
    //! @retval     R_EMPTY         - Nothing have change
    //! @retval     R_NOACT         - No new Factory Setting
    //! @retval     R_INCONSISTENT  - Factory Setting is inconsistent
    //! @retval     R_RANGE         - Variable not in valid range (one for the write process)
    //! @retval     R_DB_LIST         Invalid u8ListIdx
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkLoadFlashSetting( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Store the NvMem list to the NvMem (From the RAM to the NvMem)
    //!             -> this function give the task to the 'nvm server device' - to check the request use eCoreNvmServerStatus(..)
    //! @param[in]  u8ListIdx       - The Db list index
    //! @retval     R_OKAY          - OK
    //! @retval     R_BUSY          - Is in used
    //! @retval     R_DB_TYPE       - Is not the correct type
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkStoreList( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give over the list root pointer and the variable pointer the db link information
    //! @param[in]  ptListRoot - Pointer of the the list root
    //! @param[in]  vpVar      - Pointer of the variable
    //! @param[in]  eType      - Variable type
    //! @param[out] ptDbLink   - the DB-Link
    //! @retval     R_OKAY           - okay
    //! @retval     R_DB_LIST        - incorrect list root
    //! @retval     R_DB_TYPE        - incorrect type matching
    //! @retval     R_INCONSISTENT   - correct data
    //! @retval     R_NULL_POINTER   - ptDbLink is a null pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbGetDbLink( TDbListRoot *ptListRoot, TVoid *vpVar, EVarTyp eType, TDbLink *ptDbLink );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give over the list root pointer and the variable pointer the db link information
    //! @param[in]  ptListRoot  - Pointer of the the list root
    //! @param[in]  vpVar       - Pointer of the variable
    //! @param[in]  eType       - Variable type
    //! @param[out] ptDbLink    - the DB-Link
    //! @param[out] pu16DbComId - the DB-ComId
    //! @retval     R_OKAY           - okay
    //! @retval     R_DB_LIST        - incorrect list root
    //! @retval     R_DB_TYPE        - incorrect type matching
    //! @retval     R_INCONSISTENT   - correct data
    //! @retval     R_NULL_POINTER   - ptDbLink is a null pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbGetDbLinkComId( TDbListRoot *ptListRoot, TVoid *vpVar, EVarTyp eType, TDbLink *ptDbLink, TUint16 *pu16DbComId );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the default- and range values
    //! @param[in]  cptDbLink  - List index, variable index, array value - (all start with 0)
    //! @param[in]  eVarType   - Variable type - to make a safety type check
    //! @param[in]  u8DfltSet  - Default set - (all start with 0)
    //! @param[out] vpDef      - Default value (NULL - is possible - make nothing)
    //! @param[out] vpMin      - Minimum value (NULL - is possible - make nothing)
    //! @param[out] vpMax      - Maximum value (NULL - is possible - make nothing)
    //! @retval     R_OKAY         - OK
    //! @retval     R_DB_DEFSET    - Default set number to high
    //! @retval     R_INCONSISTENT - Variable isn't in that list 'ptListRoot'
    //! @retval     R_DB_LIST      - List index out of range, invalid list
    //! @retval     R_DB_VAR       - Variable index out of range
    //! @retval     R_DB_DIM       - Array index out of range
    //! @retval     R_DB_TYPE      - given type does not match or unknown db var type
    //! @retval     R_NULL_POINTER - Pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkDfltRange( const TDbLink *cptDbLink, EVarTyp eVarType, TUint8 u8DfltSet, TVoid *vpDef, TVoid *vpMin, TVoid *vpMax );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Read database list element
    //! @param[in]  cptDbLink      - List index, variable index, array value - (all start with 0)
    //! @param[in]  eVarType       - Variable type
    //! @param[out] pvVal          - Variable data
    //! @retval     R_OKAY         - fine
    //! @retval     R_DB_LIST      - List index out of range
    //! @retval     R_DB_VAR       - Variable index out of range
    //! @retval     R_DB_DIM       - Array index out of range
    //! @retval     R_SUPPORT      - no Variable function supported
    //! @retval     R_INCONSISTENT - DB list is inconsistent
    //! @retval     R_PARAMETER    - eVarTyp don't match with the type in the db-list
    //! @retval     R_NULL_POINTER - Pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkVarRead( const TDbLink *cptDbLink, EVarTyp eVarType, TVoid *pvVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Read database list element with fix value as default
    //! @param[in]  cptDbLink      - List index, variable index, array value - (all start with 0)
    //! @param[in]  eVarTyp        - Variable type
    //! @param[in]  pvCfg          - Fix value if the DB list isn't valid
    //! @param[out] pvVal          - Variable data
    //! @param[in]  cpchErrObj     - Error report object -> block or signal class e.g. PRO/LUT
    //! @param[in]  cpchErrName    - Error report name   -> block or signal name  e.g  Y12,LeftValve
    //! @retval     R_OKAY         - fine
    //! @retval     R_DB_LIST      - List index out of range
    //! @retval     R_DB_VAR       - Variable index out of range
    //! @retval     R_DB_DIM       - Array index out of range
    //! @retval     R_SUPPORT      - no variable function supported
    //! @retval     R_RANGE        - Variable not in valid range (one for the write process) MIN/MAX
    //! @retval     R_INCONSISTENT - DB list is inconsistent
    //! @retval     R_PARAMETER    - eVarTyp don't match with the type in the db-list
    //! @retval     R_NULL_POINTER - Pointer is NULL
    //--------------------------------------------------------------------------------------------------
    ERetVal eCoreDbLinkVarReadWithFixVal( const TDbLink *cptDbLink, EVarTyp eVarTyp, TVoid *pvCfg, TVoid *pvVal, const TChar* cpchErrObj, const TChar* cpchErrName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Write database list element [write the value only in the RAM of the db list]
    //! @param[in]  cptDbLink      - List index, Variable index, Array value - (all start with 0)
    //! @param[in]  eVarType       - Variable type
    //! @param[out] pvVal          - Variable data
    //! @retval     R_OKAY         - fine
    //! @retval     R_DB_LIST      - List index out of range
    //! @retval     R_DB_VAR       - Variable index out of range
    //! @retval     R_DB_DIM       - Array index out of range
    //! @retval     R_SUPPORT      - no variable function supported
    //! @retval     R_RANGE        - Variable not in valid range MIN/MAX
    //! @retval     R_INCONSISTENT - DB list is inconsistent
    //! @retval     R_PARAMETER    - eVarTyp don't match with the type in the db-list
    //! @retval     R_NULL_POINTER - Pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkVarWrite( const TDbLink *cptDbLink, EVarTyp eVarType, TVoid *pvVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Write database element over an DB-Device-Server to the NVMEM
    //! @param[in]  cptDbLink      - List index, Variable index, Array value - (all start with 0)
    //! @param[in]  eVarType       - Variable type
    //! @param[in]  boRamUpdate    - Update the RAM value
    //! @param[in]  boRamCompare   - Don't write if the RAM value is equal to to write Value
    //! @param[in]  pvVal          - Variable data
    //! @retval     R_OKAY         - fine (the store request is accepted from the DB-Device-Server)
    //! @retval     R_DB_LIST      - List index out of range
    //! @retval     R_DB_VAR       - Variable index out of range
    //! @retval     R_DB_DIM       - Array index out of range
    //! @retval     R_SUPPORT      - no variable function supported
    //! @retval     R_RANGE        - Variable not in valid range MIN/MAX
    //! @retval     R_INCONSISTENT - DB list is inconsistent
    //! @retval     R_PARAMETER    - eVarTyp doesn't match the type in the db-list
    //! @retval     R_NULL_POINTER - Pointer is NULL
    //! @retval     R_NV_STORE     - Value isn't a nvmem value
    //! @retval     R_BUSY         - nvmem currently busy, try again after > 1 ecu cycle
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbServerLinkVarStore( const TDbLink *cptDbLink, EVarTyp eVarType, TBoolean boRamUpdate, TBoolean boRamCompare, TVoid *pvVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show that all Db Server Store "Pages Jobs" are Ready
    //!             One page can hold 8 variables (this variable must stand in on list)
    //! @param[out]  pu8FreePageCnt - Count of free pages
    //! @retval     TRUE           - Server is empty     - all jobs are finished
    //! @retval     FALSE          - Server is not empty - same jobs are in the Server
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boDbServerStoreIsReady( TUint8 *pu8FreePageCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Load database element from the NVMEM (call the function more cycle until the function returns R_OKAY)
    //!                                                  (or used boDbServerLoadIsReady() to wait same cycles)
    //! @param[in]  cptDbLink      - List index, Variable index, Array value - (all start with 0)
    //! @param[in]  eVarType       - Variable type
    //! @param[in]  boRamUpdate    - Update the ram element
    //! @param[out] pvVal          - Variable data
    //! @param[out] pboUpdate      - Variable data - are ready [set automatically to FALSE after the function call]
    //! @retval     R_OKAY         - fine ( the value is copy to the pvVal pointer)
    //! @retval     R_BUSY         - call the function again with the same parameter
    //! @retval     R_DB_LIST      - List index out of range
    //! @retval     R_DB_VAR       - Variable index out of range
    //! @retval     R_DB_DIM       - Array index out of range
    //! @retval     R_SUPPORT      - no variable function supported
    //! @retval     R_RANGE        - Variable not in valid range MIN/MAX
    //! @retval     R_INCONSISTENT - DB list is inconsistent
    //! @retval     R_PARAMETER    - eVarTyp don't match with the type in the db-list
    //! @retval     R_NULL_POINTER - Pointer is NULL
    //! @retval     R_NV_LOAD      - Value isn't a nvmem value
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbLinkVarLoad( const TDbLink *cptDbLink, EVarTyp eVarType, TBoolean boRamUpdate, TVoid *pvVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show that the DB Server variable load request is ready
    //! @retval     TRUE           - Variable is load
    //! @retval     FALSE          - Variable isn't loaded
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boDbServerLoadIsReady( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check the variable permission
    //! @param[in]  ePerm         - the check permission
    //! @param[in]  eAccLevel     - Access level
    //! @param[in]  u16AccCode    - Access code (from DB-Info-Record or from the Ver-Extended-Struct)
    //! @return     TRUE/FALSE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreCheckVarPermission( EVarRwPerm ePerm, EAccLevel eAccLevel, TUint16 u16AccCode );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Find list entry for given COM-ID the list index and the variable index
    //! @param[in]  u16ComId    - COM ID
    //! @param[out] pu8ListIdx  - give the absolute list index
    //! @param[out] pu8VarIdx   - give the variable index
    //! @param[out] pu8VarDim   - give the variable dimension 1=Single, >1=Array
    //! @param[out] peType      - give data type
    //! @param[out] pu16AccCode - give access code
    //! @param[out] pu8ByteCnt  - give byte cond
    //! @retval     R_OKAY      find -> pu8ListIdx,pu8VarIdx
    //!             R_EMPTY     COM-ID not there
    //!             R_RANGE     Wrong VarMax
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbFindComIdx( TUint16 u16ComId, TUint8 *pu8ListIdx, TUint8 *pu8VarIdx, TUint8 *pu8VarDim, EVarTyp *peType, TUint16 *pu16AccCode, TUint8 *pu8ByteCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Read  database element
    //! @param[in]  eFormat        - CAN-Mode (Normal is DATA_INTEL)
    //! @param[in]  ptDb           - DB Location
    //! @param[out] au8Data        - Variable data               (NULL save)
    //! @param[out] peType         - Variable type               (NULL save)
    //! @param[out] pu8ByteCnt     - Byte count of the variable  (NULL save)
    //! @retval     R_OKAY
    //! @retval     R_DB_LIST      - List-Index out of range
    //! @retval     R_DB_VAR       - Variable-Index out of range
    //! @retval     R_DB_DIM       - Array-Index out of range
    //! @retval     R_SUPPORT      - no Variable-Function supported
    //! @retval     R_INCONSISTENT - DB-List
    //! @retval     R_RANGE        - Variable not in valid range (one for the write process) MIN/MAX
    //! @retval     R_OVERFLOW     - Variable is to big e.g. u8 0xYX 0x00 0x00 0x00
    //! @retval     R_NULL_POINTER - Parameter(cptDb) pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eDbListVarReadCanFormat( ECanFormat eFormat, const TDbLink *cptDb, TUint8 au8Data[4], EVarTyp *peType, TUint8* pu8ByteCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Write database element
    //! @param[in]  eFormat        - CAN-Mode (Normal is DATA_INTEL)
    //! @param[in]  ptDb           - DB Location
    //! @param[out] au8Data        - Variable data
    //! @retval     R_OKAY
    //! @retval     R_DB_LIST      - List-Index out of range
    //! @retval     R_DB_VAR       - Variable-Index out of range
    //! @retval     R_DB_DIM       - Array-Index out of range
    //! @retval     R_SUPPORT      - no Variable-Function supported
    //! @retval     R_INCONSISTENT - DB-List
    //! @retval     R_RANGE        - Variable not in valid range (one for the write process) MIN/MAX
    //! @retval     R_OVERFLOW     - Variable is to big e.g. u8 0xYX 0x00 0x00 0x00
    //! @retval     R_NULL_POINTER - Parameter(cptDb,au8Data) pointer is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eDbListVarWriteCanFormat( ECanFormat eFormat, const TDbLink *cptDb, TUint8 au8Data[4], EVarTyp *peType, TUint8* pu8ByteCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      If data element is a array give the dimension
    //! @param      u8ListIdx - List index
    //! @param      u8VarIdx  - Variable index
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreDbListElmArrCnt( TUint8 u8ListIdx, TUint8 u8VarIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Calculate CRC for given DB-List (Data) based on current RAM values
    //! @param   u8ListIdx     - DB list index
    //! @param   pu8SynMemory  - Memory for the DB-Image (need that Image for the CRC calculation) \n
    //!                          Size must be at least TDbList.u16ShadowBytes of the given DB list
    //! @retval  u16Crc        - (is '0' in a fault case)
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreDbCalCrcList( TUint8 u8ListIdx, TUint8 *pu8SynMemory );

    //--------------------------------------------------------------------------------------------------
    //! @brief      De/Activate extendable NvMem lists
    //! @pre        should be called before loading DB, e.g. vAppFixInit
    //! @details    Configure if values of DB lists are kept, when more vars were added in their config.\n
    //!             Affected DB list should have CRC check enabled, because CRC of existing data will be checked. \n
    //!             Only primary list will be checked.
    //! @warning    Variables MUST ONLY be added to the end of a DB list, otherwise DB values might be corrupted! \n
    //!             If variables are added in between existing ones or swapped, change Parameter version index in PDT.
    //! @param[in]  boEnable    - TRUE: keep existing values, FALSE(Dflt): restore all defaults if format change detected
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbSetExtendableMode( TBoolean boEnable );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set backup list validation handling
    //! @pre        should be called before loading DB, e.g. vAppFixInit
    //! @details    Configure if backup lists are checked and restored if primary was already valid and loaded
    //! @param[in]  boFastCheck - TRUE(Dftl): skip backup list if primary was loaded, FALSE: always check backup
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbSetLoadFast( TBoolean boFastCheck );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set DB var range validation handling during list load for all nvmem lists
    //! @pre        should be called before loading DB, e.g. vAppFixInit
    //! @details    Configure if range of DB variables is checked when loading db list.\n
    //!             For erroneous DB variables their default value is restored(used dflt set :u8NvmLoadDfltSetFoundErr).\n
    //!             Consider performance impact of checking the ranges(one ecu cycle/list)!
    //! @warning    Make sure dflt values are in range(normally checked by PDT/ACB)
    //! @param[in]  boRangeCheck - TRUE(Dflt): check db var range, FALSE: do not check
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbSetLoadRangeCheck( TBoolean boRangeCheck );



    typedef enum
    {
        E_DB_DFLT_BY_APP        = 0, //app or ptc triggered
        E_DB_DFLT_BY_ERR        = 1, //crc/format/stamp error
        E_DB_DFLT_BY_FLASH      = 2, //flash settings changed
        E_DB_DFLT_BY_EXTENSION  = 3, //var added to list, old values possibly not changed
        E_DB_DFLT_UNKNOWN
    } EDbLoadDfltTrigger;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Prototype for function used for callback when loading DB defaults
    //! @param[in]  u8ListIdx         - List index
    //! @param[in]  eDfltTrigger      - mechanism that triggered reseting to defaults
    //--------------------------------------------------------------------------------------------------
    typedef TVoid (*TFpvDbLoadDefaultsCb) ( TUint8 u8ListIdx, EDbLoadDfltTrigger eDfltTrigger );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Prototype for function used for callback when loading DB default value because of range error
    //! @param[in]  u8ListIdx        - List Index
    //! @param[in]  u8VarIdx         - Var Index
    //! @param[in]  u8ArrIdx         - Arr Idx
    //! @param[in]  eType            - Var Type
    //! @param[in]  pvOldVal         - pointer to old value(on stack, need to use/copy immediately)
    //--------------------------------------------------------------------------------------------------
    typedef TVoid (*TFpvDbLoadRangeCheckErrCb) ( TUint8 u8ListIdx, TUint8 u8VarIdx, TUint8 u8ArrIdx, EVarTyp eType, TUint8 u8ByteSize, TVoid* pvOldVal );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set function to be called if list default values are loaded by Application/Ptc
    //! @param[in]  pfvLoadedDefaultsCb - callback function
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbSetLoadedDefaultsCb ( TFpvDbLoadDefaultsCb pfvLoadedDefaultsCb );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set function to be called if DB variable is set to default because of range error
    //! @param[in]  pfvRangeCheckError - callback function
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbSetRangeCheckErrorCb ( TFpvDbLoadRangeCheckErrCb pfvRangeCheckErrorCb );

    //***** interface for retrieving DB variables with non-dflt value ******//

    typedef struct
    {
        TUint8 u8ListIndex;     //! list index given in request(255=ALL)
        EAccLevel eAccLvl;      //! acc level to be used
        TUint8 u8DfltIdx;       //! Idx of default value to be used for compare
        TBoolean boSkipRam;     //! option to skip processing ram lists, TRUE: skip, FALSE: process RAM lists
        TUint8 u8ListClass;     //! option to process only specific type of lists(255=ALL)
    } TDbNonDefCheckInput;

    typedef struct
    {
        TUint8  au8DefVal[4];   //! default value of var used for compare
        TUint8  au8CurVal[4];   //! current value of var used for compare
        TUint16 u16ComId;       //! comid for currently processed variable
        TUint16 u16DiffCounter; //! number of non-default values encountered
        EVarTyp eVarType;       //! type of currently processed variable
        TDbLink tDbLink;        //! DB link for currently processed step
    } TDbNonDefCheckOutput;

    typedef struct
    {
        TUint8 u8MaxListIdx;    //! list index to be checked, calculated depending on input
        TUint8 u8CurrListIdx;   //! current list idx checked
        TUint8 u8CurrVarIdx;    //! current var idx checked
        TUint8 u8CurrArrIdx;    //! current arr idx checked
    } TDbNonDefCheckState;

    typedef struct
    {
        TDbNonDefCheckState tState;     //! internal state, do not set this manually
        TDbNonDefCheckInput tInput;     //! input parameter, set in eCoreDbRunDfltCheck, do not write directly to it
        TDbNonDefCheckOutput tOutput;   //! output parameter, set via eCoreDbInitDfltCheck, should be read only for appl
    } TDbNonDefCheck;


    //--------------------------------------------------------------------------------------------------
    //! @brief      Init DB Dflt check compare functionality to list all DB values with non-dflt values
    //! @param      ptDefCheckObj   - pointer to TDbNonDefCheck object
    //! @param      eAccLvl         - access level
    //! @param      u8ListIdx       - list to be checked, if u8ListIdx==U8_MAX: all lists are checked
    //! @param      u8DfltIdx       - default parameter set to be used for compare
    //! @param      u8ListClass     - Class/Type of lists to be checked(e.g. DB_NVM_PAR, DB_NVM_MEM),\n
    //!                               only considered if u8ListIdx==U8_MAX.\n
    //!                               ALL: U8_MAX\n
    //! @param      u8App           - config if 1app/2app lists are used(0=1app,1=2app, else both)\n
    //!                               WARNING: calls from 2app can currently only access 2app lists and have to use u8App>1
    //! @param      boSkipRam       - TRUE: ram lists are skipped, FALSE: ram lists are checked
    //! @retval     R_OKAY          - init done
    //! @retval     R_NULL_POINTER  - ptDefCheckObj NULL
    //! @retval     R_DB_LOAD       - DBs not available [yet]
    //! @retval     R_DB_LIST       - invalid list index given
    //! @retval     R_DB_TYPE       - RAM-List given with boSkipRam=TRUE(if single list was given)
    //! @retval     R_DB_DEFSET     - Default set number to high(if single list was given)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbInitDfltCheck( TDbNonDefCheck* ptDefCheckObj, EAccLevel eAccLvl, TUint8 u8ListIdx, TUint8 u8DfltIdx,
                                         TUint8 u8ListClass, TUint8 u8App, TBoolean boSkipRam );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Run DB Dflt check compare functionality to list all DB values with non-dflt values
    //! @pre        ptDefCheckObj initialized with eCoreDbInitDfltCheck [before each new run]
    //! @details    If given defaultset is not found, function returns error only for first var not found and skips list.\n
    //!             ptDefCheckObj->tOutput contains the last checked variable(or DB list) before function return.\n
    //!             After each error/non-dflt value the functions returns, to iterate over all variables call until R_NOACT.\n
    //!             Variables not accessible with initialized access level are skipped.
    //! @param      ptDefCheckObj       - pointer to TDbNonDefCheck object
    //! @param      u16MaxVarPerCycle   - max number of variables checked before function returns R_BUSY
    //! @retval     R_OKAY  - value found, check ptDefCheckObj->tOutput, call again for more differences
    //! @retval     R_NOACT - done
    //! @retval     R_BUSY  - still running with no value found, call again(u16MaxComparePerCycle reached)
    //! @retval     R_NULL_POINTER  - ptDefCheckObj is NULL
    //! @retval     R_DB_DEFSET     - default set does not exist\n
    //!                               (only if specific list requested, otherwise lists without given default set skipped)
    //! @retval     others  - issue with DB list/variables not found
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbRunDfltCheck( TDbNonDefCheck* ptDefCheckObj, TUint16 u16MaxComparePerCycle );



    //--------------------------------------------------------------------------------------------------
    //! @brief      Enable/Disable managing of range flags for all DB lists(call in vAppFixInit!), DFLT: disabled
    //! @details    If this feature is activated, each NvMem list will track/store if DB variables are set back to their default values because of out of range errors(min/max).\n
    //!             The flags are kept in RAM for each list and will also be stored to NvMem directly behind the data of each list.\n
    //!             The flags are stored automatically if a list is stored but can also be stored separately.\n
    //!             Normally the flags should only be read and reset by the user but the flags can also be overwritten manually.\n
    //!             For each value(DB variable+array values) one bit is used.\n
    //!             The flag for the xth value(vars and array entries) is stored in the xth bit.
    //!             Therefore ceil(#numvalues/8) bytes are additionally used in RAM and NvMEM for each list if feature is active. \n
    //!             Flags are automatically reset if list format changed.\n
    //!             Cannot be disabled after eAppStartUp.\n
    //!             Enabling the range flags using this functions overwrites the per list setting in the autocode.\n
    //!             Enabling the range flags sets vCoreDbSetLoadRangeCheck( TRUE ).
    //! @param[in]  boRangeFlagActive - TRUE=set/store range flags,FALSE=range flags not used
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDbDiagRangeCheckInit( TBoolean boRangeFlagActive );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Return if range flags are used/stored((call in eAppStartup or later)
    //! @retval     TRUE    - range flags are used/stored
    //! @retval     FALSE   - range flags not used or DB init not done yet(before eAppStartup)
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreDbDiagRangeCheckInitStatus( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Get range flag for a given DB value in RAM
    //! @param      u8ListIdx      - list index
    //! @param      u8VarIdx       - variable index
    //! @param      u8ArrIdx       - array index
    //! @param[out] pboFlag        - address for state of flag to be written to
    //! @retval  R_OKAY          - read ok
    //! @retval  R_SUPPORT       - range flags feature not active
    //! @retval  R_DB_LIST       - wrong list index
    //! @retval  R_DB_TYPE       - wrong list type
    //! @retval  R_DB_VAR        - invalid variable
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbDiagRangeCheckRead( TUint8 u8ListIdx, TUint8 u8VarIdx, TUint8 u8ArrIdx, TBoolean* pboFlag );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Set range flag for a given DB value in RAM
    //! @param   u8ListIdx      - list index
    //! @param   u8VarIdx       - variable index
    //! @param   u8ArrIdx       - array index
    //! @param   boFlag         - new state of flag to be set
    //! @retval  R_OKAY          - set done
    //! @retval  R_SUPPORT       - range flags feature not active
    //! @retval  R_DB_LIST       - wrong list index
    //! @retval  R_DB_TYPE       - wrong list type
    //! @retval  R_DB_VAR        - in valid variable
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbDiagRangeCheckWrite( TUint8 u8ListIdx, TUint8 u8VarIdx, TUint8 u8ArrIdx, TBoolean boFlag );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Reset all range flags for given list and store to NvMem
    //! @param   u8ListIdx      - list index
    //! @retval  R_OKAY          - store process started, query NvMem server to see if process is finished
    //! @retval  R_BUSY          - nvmem server busy
    //! @retval  R_DB_LIST       - wrong list index
    //! @retval  R_SUPPORT       - range flags feature not active
    //! @retval  R_DB_TYPE       - wrong list type
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbDiagRangeCheckResetList( TUint8 u8ListIdx );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Reset all range flags and store to NvMem, call until R_OKAY
    //! @retval  R_OKAY          - done
    //! @retval  R_BUSY          - operation running, call again
    //! @retval  R_SUPPORT       - Range flags not supported
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbDiagRangeCheckReset( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Store range flags for given list to NvMem
    //! @param   u8ListIdx      - list index
    //! @retval  R_OKAY          - store process started, query NvMem server to see if process is finished
    //! @retval  R_BUSY          - nvmem server busy
    //! @retval  R_DB_LIST       - wrong list index
    //! @retval  R_SUPPORT       - range flags feature not active
    //! @retval  R_DB_TYPE       - wrong list type
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreDbDiagRangeCheckStoreList( TUint8 u8ListIdx );


    //--------------------------------------------------------------------------------------------------
    //! @brief   Start storing all licenses via nvm server
    //! @details Store license keys at user defined nvm add(see \ref eCoreLicInit) and stores ecu key by writing nvm info
    //! @retval  R_OKAY          - license store service started
    //! @retval  R_BUSY          - nvm server busy, storing licenses was not started
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreLicStoreAll( TVoid );
#endif

