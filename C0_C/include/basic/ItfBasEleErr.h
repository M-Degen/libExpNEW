//**************************************************************************************************
/*!
@file           ItfBasEleErr.h
@brief          Core error interface
@date           01.02.2011
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREERR__
    #define __ITFCOREERR__

    #include <ItfTypes.h>
    #include <ItfCore.h>

//!--------------------------------------------------------------------------------------------------
//!  Error State Machine Logic
//!
//!  Set and release of a new error status
//!     - If the 'Error Input Bit' changes status from ON to OFF (or vice versa),
//!       the 'Error Status' will change to the new requested status,
//!       only after elapse of the related 'debounce time'
//!
//!  Exclude-Group:
//!     - The Exclude-Group has the highest priority
//!     - The Exclude-Group(EG) freezes the status of a specific error code output.
//!     - The 'Debounce Timer' will be permanently re-initialized as long as the Exclude-Group is active.
//!       -> With an active EG, the 'Debounce Timer' will be re-initialized (set to zero).
//!       -> If an EG shifts to status OFF the `'Debounce Timer' is not blocked anymore.
//!     - Examples:
//!                  Current Error Status      Conditions       New Error Status     Note
//!                 ============================================================================================
//!                  a) ERR_STA_INACT       EG=1 + ERR-BIT=0     ERR_STA_INACT       - no influence by EG (sticks in status 'inactive')
//!                                         EG=1 + ERR-BIT=1     ERR_STA_INACT_EX    - 'active' error requested, but locked by EG
//!                  b) ERR_STA_INACT_EX    EG=0 + ERR-BIT=0     ERR_STA_INACT       - no influence by EG -> back to 'inactive'
//!                                         EG=0 + ERR-BIT=1     ERR_STA_ACTIV       - status change to error 'active'
//!                  c) ERR_STA_ACTIV       EG=1 + ERR-BIT=1     ERR_STA_ACTIV       - no influence by EG (sticks in status 'active')
//!                                         EG=1 + ERR-BIT=0     ERR_STA_ACTIV_EX    - 'inactive' error requested, but locked by EG
//!                  d) ERR_STA_ACTIV_EX    EG=0 + ERR-BIT=1     ERR_STA_ACTIV       - no influence by EG -> back to 'active'
//!                                         EG=0 + ERR-BIT=0     ERR_STA_INACT       - no influence by EG -> change to 'inactive'
//!
//!  Set Condition (SC) & Release Condition (RC):
//!         - SC & RC are influence the error detection behavior only, if there is no influence from the Exclude-Group (EG is 'OFF')
//!         - 'Debouncing' vs. 'no debouncing' error detection after valid Set- or Release Condition
//!           a) 'NO Debouncing' of the error detection after valid a Set- or Release Condition
//!             ('boDetectDboAfterSc' or 'boResetDboAfterRc' == FALSE)
//!               -> The 'Error Input Bit' triggers the start of the debounce timer
//!               -> SC or RC are a prerequisite for changing to a new error status
//!                 (if debounce time is over and than SC/RC changes from OFF to ON -> error status changes immediately)
//!           b) 'Debouncing' of the error detection after valid a Set- or Release Condition
//!             ('boDetectDboAfterSc' or 'boResetDboAfterRc' == TRUE)
//!               -> The 'Error Input Bit' is already requesting a change in error status,
//!                  but the only debounce timer will start only after a valid SC or RC (SC/RC == ON)
//!                 (as long as SC or RC is OFF -> debounce timer will be permanently re-initialized (still at zero))
//!               -> If SC or RC changes back to status 'OFF', the debounce timer will be re-initialized
//!
//!  Matrix Example:
//!
//!     ErrA: TimeDetect=30ms, DetectDboAfterSc=FALSE, TimeReset=30ms, ResetDboAfterRc=FALSE (Debounce time, Condition)
//!     ErrB: TimeDetect=30ms, DetectDboAfterSc=TRUE,  TimeReset=30ms, ResetDboAfterRc=TRUE  (Condition, Debounce time)
//!
//!     --------------------------------------------------------------------------------------------------------------------------------------
//!     TestStep           | 0   1   2   3   4   5   6   7   8   9, 10  11  12  13  14  15  16  17  18  19  20  21,  22, 23, 24  25  26  27  28
//!     --------------------------------------------------------------------------------------------------------------------------------------
//!     ErrorBit-A         | 0,  1,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1,  1,  1,  0,  0,  0,  1,  0,  1,  0,  1,   1,  1,  1,  0,  1,  0,  1
//!     ErrorBit-B         | 0,  1,  0,  1,  1,  0,  0,  1,  1,  0,  0,  1,  1,  1,  0,  0,  0,  1,  0,  1,  0,  1,   1,  1,  1,  0,  1,  0,  1
//!     SetCondition       | 0,  1,  0,  0,  1,  0,  0,  1,  1,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,  1,  0,  1,   0,  1,  1,  0,  0,  0,  0
//!     ReleaseCondition   | 0,  0,  1,  0,  0,  0,  1,  0,  0,  1,  1,  0,  0,  0,  0,  1,  1,  0,  0,  0,  0,  0,   0,  0,  0,  0,  0,  1,  0
//!     Exclude-Group      | 0,  0,  0,  0,  0,  0,  0,  1,  0,  1,  0,  1,  1,  0,  1,  1,  0,  0,  0,  1,  0,  1,   1,  0,  0,  0,  0,  1,  0
//!     --------------------------------------------------------------------------------------------------------------------------------------
//!     Sta-A during D-Tim | D,  D,  A,  D,  A,  A,  D, DE,  D, AE,  A, DE, DE,  D, AE, AE,  A,  D,  D, DE,  D, DE,  DE,  D,  A,  A,  A, AE,  A
//!     Sta-A after  D-Tim | D,  A,  D, DS,  A, AR,  D, DE,  A, AE,  D, DE, DE,  A, AE, AE,  D, DS,  D, DE,  D, DE,  DE,  A,  A, AR,  A, AE,  A
//!     Sta-B during D-Tim | D,  D,  A, DS,  D, AR,  A, DE,  D, AE,  A, DE, DE,  D, AE, AE,  A, DS,  D, DE,  D, DE,  DE,  D,  A, AR,  A, AE,  A
//!     Sta-B after  D-Tim | D,  A,  D, DS,  A, AR,  D, DE,  A, AE,  D, DE, DE,  A, AE, AE,  D, DS,  D, DE,  D, DE,  DE,  A,  A, AR,  A, AE,  A
//!     --------------------------------------------------------------------------------------------------------------------------------------
//!
//!     Legend:
//!         D     = ERR_STA_INACT
//!         DS    = ERR_STA_INACT_SC
//!         DE    = ERR_STA_INACT_EX
//!         A     = ERR_STA_ACTIV
//!         AR    = ERR_STA_ACTIV_RC
//!         AE    = ERR_STA_ACTIV_EX
//!         Sta   = Error Status
//!         D-Tim = debounce timer
//!
//!--------------------------------------------------------------------------------------------------


    // Error Array
    #define LIST_ERR_ROW_MAX    32           //!< Maximum Records in Error-List
    #define LIST_DEV_ROW_MAX    32           //!< Maximum Records in DevErr-List
    #define LIST_EVE_ROW_MAX    32           //!< Maximum Records in Event-List

    //! Error type categories
    typedef enum
    {
        ERR_TYPE_NA,                         //!< 0 -b00 not applicable
        ERR_TYPE_INFO,                       //!< 1 -b01 information
        ERR_TYPE_WARN,                       //!< 2 -b10 warning
        ERR_TYPE_ERROR                       //!< 3 -b11 error
    }EErrTyp;

    //  Failure access level                      CU DE PR SE   OE IN EN DE
                                             //!<
    #define ACC_ALL_NO          0x0000       //!< 00 00 00 00 | 00 00 00 00 - NO access to all level
    #define ACC_ALL_RD          0x5555       //!< 01 01 01 01 | 01 01 01 01 - all levels are read only                    --> ACB set atErrFea[x].boCustumer to TRUE
    #define ACC_ALL_CL1         0xAAAA       //!< 10 10 10 10 | 10 10 10 10 - access to all level actions/clear costumer  --> ACB set atErrFea[x].boCustumer to TRUE
    #define ACC_ALL_CL2         0xFFFF       //!< 11 11 11 11 | 11 11 11 11 - full access to all levels

    #define ACC_OEMNO_ENGRD     0x0004       //!< 00 00 00 00 | 00 00 01 00
    #define ACC_OEMRD_ENGCL1    0x0048       //!< 00 00 00 00 | 01 00 10 00
    #define ACC_OEMCL1_ENGCL2   0x008C       //!< 00 00 00 00 | 10 00 11 00
    #define ACC_OEMCL2_ENGNO    0x00C0       //!< 00 00 00 00 | 11 00 00 00

    //! Error Access Permission
    typedef enum
    {
        ERR_ACCPERM_NO,                      //!< 0 - No Access
        ERR_ACCPERM_RD,                      //!< 1 - Read and no clear                 / Custumer OccCount
        ERR_ACCPERM_CL1,                     //!< 2 - Read and clear in 'Clear Level 1' / Custumer OccCounte    / Clear the Custumer List
        ERR_ACCPERM_CL2                      //!< 3 - Read and clear in 'Clear Level 2' / Engineering OccCounte / Clear the Engineering List
    }EErrAccPerm;

    //! Error sub type categories
    typedef enum
    {
        ERR_CAT0_NOT,                        //!< 0  Error detection OFF
        ERR_CAT1_WHI,                        //!< 1  Messages on information level
        ERR_CAT2_YEL,                        //!< 2  Messages on warning level
        ERR_CAT3_AMB,                        //!< 3  Messages on warning level
        ERR_CAT4_RED,                        //!< 4  Messages on error level
        ERR_CAT5_MAL,                        //!< 5  Messages on critical error level
        ERR_CAT_MAX                          //!<    CAT Maximum count
    }EErrCat;

    //! Error store behavior
    typedef enum
    {
        ERR_STORE_NOT,                      //!< 0  not, error storing is off
        ERR_STORE_ACT,                      //!< 1  only active errors will be saved
        ERR_STORE_HIS,                      //!< 2  save error history list
        ERR_STORE_ALL                       //!< 3  save history and event list
    }EErrStore;

    //! Lamp notification for flash status
    typedef enum
    {
       ERR_FLA_OFF=1,                       //!< 1   No lamp flashing (Solid)
       ERR_FLA_SLOW,                        //!< 2   slow lamp flashing during memory flash
       ERR_FLA_FAST                         //!< 3   fast lamp flashing during memory flash
    }EErrFla;

    //! Error State
    typedef enum
    {
        ERR_STA_INACT,                      //!< 0 State 'Inactive'
        ERR_STA_INACT_SC,                   //!< 1 State 'Inactive Hold' form "set condition"
        ERR_STA_INACT_EX,                   //!< 2 State 'Inactive Hold' form "Exclude Group"
        ERR_STA_ACTIV,                      //!< 3 State 'Active'
        ERR_STA_ACTIV_RC,                   //!< 4 State 'Active Hold' from "reset condition"
        ERR_STA_ACTIV_EX                    //!< 5 State 'Active Hold' form "Exclude Group"
    }EErrSta;

    //! Single error number configuration
    typedef struct
    {
        //!< Error property definitions
        TUint32   u32ErrNum;                //!< [NUM] error number
        TUint8    u8ErrMode;                //!< [DEF] Failure mode indicator
        TUint8    u8ErrModeExt;             //!< [DEF] Failure mode indicator extended
        TUint16   u16ErrAccLevel;           //!< [DEF] Failure access level
        EErrTyp   eErrTyp;                  //!< [ENU] Type of categories
        EErrCat   eErrCat;                  //!< [DEF] Error category/lamp
        EErrStore eErrStore;                //!< [DEF] Error store behavior
        TUint8    u8ExcludeGroup;           //!< [DEF] Error excluded group
        //!< Error set properties
        TUint8    u8SetCond;                //!< [DEF] Error set condition [Bit Position 0-31]
        TUint32   u32TimeDetect;            //!< [ms]  Error detection debouncing
        TBoolean  boDetectDboAfterSc;       //!< [DEF] Error detection debouncing after valid set condition
        //!< Error reset properties
        TUint8    u8ReleaCond;              //!< [DEF] Error release condition [Bit Position 0-31]
        TUint32   u32TimeReset;             //!< [ms]  Error reset debouncing
        TBoolean  boResetDboAfterRc;        //!< [DEF] Error reset debouncing after valid release condition
        ///!< Error output properties
        TUint8    u8RestrictMode;           //!< [DEF] Restricted mode [Bit Position 0-63]
        TUint8    u8InfoVarIdx;             //!< [DEF] Error info page array index
        TBoolean  boCustList;               //!< [DEF] Memorized in customer list
        TUint8    u8DisplayOutput;          //!< [DEF] Customer specific display output
    } TErrCfgFea;

    //! Element error
    typedef struct
    {
        TVoid        *pvObj;                //!< [STU] - Pointer to the private object
        TUint16       u16Stamp;             //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block ID
    } TEleErrAdr;

    //! Core error record
    typedef struct
    {
        const TErrCfgFea *cptCfg;            //!< [STU] Error configuration
        EErrSta           eErrSta;           //!< [ENU] Error status ( -> boErrStaTypeOfActiv() )
        TUint8            u8OccCount;        //!< [NUM] Occurrence counter
    }TCoreErrRec;

    //! Core error record
    typedef struct
    {
        TUint32           u32ErrCode;        //!< [NUM] Error code
        TUint32           u32FirstEngineSec; //!< [sec] First Engine Second
        TUint32           u32EngineSec;      //!< [sec] Engine Second
        TUint8            u8LinkIdx;         //!< [NUM] Index referring to extended fault data
    }TCoreErrRecExt;

    //! Core event record
    typedef struct
    {
        const     TErrCfgFea *cptCfg;       //!< [STU] Error configuration
        EErrSta   eErrSta;                  //!< [ENU] Attribute Flags
    } TCoreEveRec;

    //! Core event extended record
    typedef struct
    {
        TUint32   u32ErrCode;               //!< [NUM] Error code (packed format/unpacked in cptCfg)
        TUint32   u32EngineSec;             //!< [sec] Engine Seconds
        TUint32   u32DuraTimeMs;            //!< [ms]  Duration Time
        TUint16   u16TimeSet;               //!< [ms]  Timer to set Active
        TUint16   u16TimeClr;               //!< [ms]  Timer to set Inactive
    } TCoreEveRecExt;

    #define ERR_CNT_DFLT    0xFF            //!<  TRICK take the block error count

    // Error NONE Defines
    #define RM_NONE         0xFF            //!< No restricted mode
    #define SC_NONE         0xFF            //!< No set condition
    #define RC_NONE         0xFF            //!< No release condition
    #define EG_NONE         0xFF            //!< No excluded group
    #define INF_NONE        0xFF            //!< Error info page array index
    #define DIS_NONE        0xFF            //!< Display output (customer specific)
    #define FMI_NONE        0xFF            //!< FMI    (customer specific)
    #define FMIEX_NONE      0xFF            //!< FMI-EX (customer specific)

    #define ERR_RM_UPDATE   0x01            //!< [1] RM has changed
    #define ERR_SC_UPDATE   0x02            //!< [1] SC has changed
    #define ERR_RC_UPDATE   0x04            //!< [1] RC has changed
    #define ERR_EX_UPDATE   0x08            //!< [1] EX has changed

//a) Constructor

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create the error element
    //! @note       call before match phase MAIN_APP_INIT/eAppInit
    //! @param[in]  ptEleAdr       - Error element address
    //! @param[in]  cpchName       - Identification name
    //! @param[in]  u8MaxErr       - Error count
    //! @param[in]  cptCfgFea      - Error configuration
    //! @param[in]  ptBehErrSta    - init/clear that struct behind that pointer
    //! @param[in]  ptBehErrCntl   - If the Pointer is NULL do nothing, else init/clear that struct behind that pointer
    //! @retval     R_OKAY         - functions execute without error
    //! @retval     R_PHASE        - function was not called before MAIN_APP_INIT
    //! @retval     R_NULL_POINTER - A pointer is NULL
    //! @retval     R_MEMORY       - out of memory
    //! @retval     R_PARAMETER    - u8MaxErr too big
    //! @retval     R_ACCESSLEVEL  - The access level is incorrect [ACC_RD/ACC_CL1 active but the boCustList is FALSE (TRUE is correct), if the eFaultMode "FAULT_MODE_SINGLE" is set]
    //! @retval     R_RANGE        - error code out of range or duplicated
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eEleErrCreate( TEleErrAdr* ptEleAdr, const TChar *cpchName, TUint8 u8MaxErr, const TErrCfgFea* cptCfgFea, TBehErrSta *ptBehErrSta, TBehErrCntl* ptBehErrCntl );

//c) Get status functions and access functions

    //--------------------------------------------------------------------------------------------------
    //! @brief      Error element - Get the name
    //! @param[in]  ptEleAdr    - Error element address
    //! @retval     != NULL     - get signal name
    //! @retval     NULL        - name not valid
    //--------------------------------------------------------------------------------------------------
    extern TChar* pchEleErrGetName( TEleErrAdr* ptEleAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Clear all the error/s of an error element (after this function call the error element is like the first initialization)
    //! @param[in]  ptEleAdr       - Error element address
    //! @param[in]  cpchName       - Object name
    //! @param[out] ptBehErrSta    - Error status behavior
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - Null Pointer(ptEleAdr or ptBehErrSta)
    //! @retval     R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eEleErrClear( TEleErrAdr* ptEleAdr, const TChar *cpchName, TBehErrSta *ptBehErrSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Inquiry error state (call this function for each object), is there an error on the object?
    //! @param[in]  ptEleAdr  - Parameter/state structure
    //! @retval     OKAY      - FALSE = No error, TRUE = One or more errors
    //! @retval     ERROR     - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boEleErrGetSumState( TEleErrAdr* ptEleAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Inquiry error state (call by each object), return the error bit code
    //! @param[in]  ptEleAdr  - Parameter/state structure
    //! @retval     OKAY      - Bit code of the 'Error State/s' for this element
    //! @retval     ERROR     - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16EleErrGetState( TEleErrAdr* ptEleAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Inquiry error state (call by each object) - the return the internal error status
    //! @param[in]  ptEleAdr  - Error object
    //! @param[in]  u8Bit     - Bit position
    //! @return     OKAY      - Bit position
    //! @retval     ERROR     - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boEleErrGetBitState( TEleErrAdr* ptEleAdr, TUint8 u8Bit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Inquiry error requested state, internal error - ignore SC (set cond.) and RC (release cond.) (call by each object)
    //! @param[in]  ptEleAdr  - Error element address
    //! @retval     OKAY      - FALSE = No error, TRUE = One or more errors
    //! @retval     ERROR     - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boEleErrReqGetSumState( TEleErrAdr* ptEleAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Inquiry error request state, internal error - ignore SC (set cond.) and RC (release cond.) (call by each object)
    //! @param[in]  ptEleAdr  - Error element address
    //! @retval     OKAY      - Bit code the 'INTERNAL Error State/s' from the error element
    //! @retval     ERROR     - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16EleErrReqGetState( TEleErrAdr* ptEleAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Inquiry error request state, internal error - ignore SC (set cond.) and RC (release cond.) (call by each object)
    //! @param[in]  ptEleAdr  - Error object
    //! @param[in]  u8Bit     - Bit position
    //! @return     OKAY      - Bit position
    //! @retval     ERROR     - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boEleErrReqGetBitState( TEleErrAdr* ptEleAdr, TUint8 u8Bit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the debounce timer (active/deactive) from a special "Detection Method" (u8Bit)
    //! @param[in]  ptEleAdr  - Error Element Address
    //! @param[in]  u8Bit     - Error Bit
    //! @param[in]  boActiv   - TRUE= give active debounce timer, FALSE = give deactive debounce timer
    //! @return     u32Tim    - Debounce time
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32EleErrGetDebounceTim( TEleErrAdr* ptEleAdr, TUint8 u8Bit, TBoolean boActiv );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the number of total initialized exclude groups in system
    //! @return     Number of initalized exclude groups
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8EleErrGetExcGrpNoMax( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Change the fault detection, if the detected error condition is trending towards an active state and u8EleCallTime is greater than 0,
    //!             when an inactive impulse is detected, it doesn't reset the entire detection time, but rather increments the detection time by
    //!             2*u8EleCallTime milliseconds.
    //! @note       This detection mode needs more CPU time (ca. 10 commands more, depends on the error behavior)
    //! @param[in]  ptEleAdr       - Error Element Address
    //! @param[in]  u8EleCallTime  - Time in milliseconds between vEleErrSetBloFaultCode()-function calls, e.g. block cycle time, must be <=127ms
    //! @retval     R_OKAY         - Function executes without error
    //! @retval     R_NULL_POINTER - Null Pointer
    //! @retval     R_ADDRESS      - Wrong block address
    //! @retval     R_PARAMETER    - u8EleCallTime > 127ms
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eEleErrAccumDebounce( TEleErrAdr* ptEleAdr, TUint8 u8EleCallTime );



//d) Cyclic signal function

    //--------------------------------------------------------------------------------------------------
    //! @brief  Set Error State by Failure Code (call by each object)
    //! @note   Between the eEleErrCreate(..) and one cycle before the 'eAppInit-Phase' this function remember the 'u16Code'
    //!         parameter and OR-gating this values (u16MemCode|=u16Code') for a call one cycle before the 'eAppInit-Phase'.
    //!         In this case, the parameter 'ptErrOverCntl' is ignored, and 'ptErrSta' don't return a value.
    //!         [E.g. vEleErrSetBloFaultCode( ptEleAdr, NULL, u16MemCode, NULL )]
    //!         If the debouncing is '0', the set/release condition and exclude group is fulfill the fault state change
    //!         and the behavior can use in the 'eAppInit-Phase'.
    //!         From the 'eAppInit-Phase' the normal failure process starts.
    //!         -  Change the 'Error State' in dependence of the set condition, detection debouncing, excluded group for the activate an error
    //!         -  Change the 'Error State' in dependence of the release condition, reset debouncing, excluded group for the deactivate an error
    //! @param[in]  ptEleAdr      - Error element address
    //! @param[in]  ptErrOverCntl - Error override control (NULL-Pointer has no effect, is possible)
    //! @param[in]  u16Code       - Error code
    //! @param[out] ptErrSta      - Error status behavior  (NULL-Pointer has no effect, is possible)
    //--------------------------------------------------------------------------------------------------
    extern TVoid vEleErrSetBloFaultCode( TEleErrAdr *ptEleAdr, TBehErrCntl *ptErrOverCntl,  TUint16 u16Code, TBehErrSta *ptErrSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set error state by failure code
    //! @param[in]  ptEleAdr    Error element address
    //! @param[in]  u16Code     Error code
    //! @retval     OKAY        - FALSE  error status not change
    //! @retval     OKAY        - TRUE   error status change
    //! @retval     ERROR       - If a wrong ptBlo addr was given, the return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boEleErrSetFaultCode( TEleErrAdr* ptEleAdr, TUint16 u16Code );

//e) Help function

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show that the error list is loaded and all error elements a restored
    //! @retval     TRUE  - Error list is loaded and all error elements in the blocks a restored
    //! @retval     FALSE - Block and Error report request not ready
    //--------------------------------------------------------------------------------------------------
    extern  TBoolean boCoreErrElementsRestored( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if Error Status is a type of 'Active' ( ERR_STA_ACTIV, ERR_STA_ACTIV_RC, ERR_STA_ACTIV_EX )
    //! @param[in]  eErrSta            Error State
    //--------------------------------------------------------------------------------------------------
    extern  TBoolean boErrStaTypeOfActiv( EErrSta eErrSta );

     //--------------------------------------------------------------------------------------------------
    //! @brief       Extract the error code
    //! @param[in]   u32Code     pack error code
    //! @param[out]  pu32Spn     19 Bit - SPN or DTC  (1-524287)
    //! @param[out]  pu8Fmi       5 Bit - FMI or DTC  (0-31)
    //! @param[out]  pu8FmiExt    8 Bit - FMIEXT      (0-255)
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreErrCodeUnPack( TUint32 u32Code, TUint32* pu32Spn, TUint8* pu8Fmi, TUint8* pu8FmiExt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Pack the error code
    //! @param[in]  u32Spn     19 Bit - SPN or DTC
    //! @param[in]  u8Fmi       5 Bit - FMI or DTC
    //! @param[in]  u8FmiExt    8 Bit - FMIEXT
    //! @return     u32ErrCode
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreErrCodePack( TUint32 u32Spn, TUint8 u8Fmi, TUint8 u8FmiExt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show that an Error Register has changed
    //! @return     ERR_RM_UPDATE 0x01 -> RM has changed (Bit 0)
    //!             ERR_SC_UPDATE 0x02 -> SC has changed (Bit 1)
    //!             ERR_RC_UPDATE 0x04 -> RC has changed (Bit 2)
    //!             ERR_EX_UPDATE 0x08 -> EX has changed (Bit 3)
    //--------------------------------------------------------------------------------------------------
    extern TUint8   u8CoreErrRegisterUpdateEvent( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error Restricted Mode' register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint64  u64CoreGetErrRestModeReg( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the 'Error Restricted Mode' bit position
    //! @param[in]  u8Pos error bit position
    //! @return     FALSE/TRUE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreGetErrRestMode( TUint8 u8Pos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the Display Output register
    //! @return     FALSE/TRUE
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64CoreGetErrDisOutReg( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the 'Error Display Output' bit position
    //! @param[in]  u8Pos       - bit position
    //! @return     FALSE/TRUE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreGetErrDisOut( TUint8 u8Pos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give Error Signal struct
    //! @param[out] ptSigCat       - target
    //! @retval     R_OKAY         - fine
    //! @retval     R_NULL_POINTER - pointer
    //---------------------------------------
    extern ERetVal eCoreGetErrSignal( TErrSignal *ptSigCat );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error Excluded Group' register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint64  u64CoreGetErrExcGroupReg( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the 'Error Excluded Group' bit position
    //! @param[in]  u8Pos       - error bit position
    //! @return     FALSE/TRUE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreGetErrExcGroup( TUint8 u8Pos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error set condition' register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint32  u32CoreGetErrSetCondReg( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error set condition' register
    //! @param      u32SetCondBits
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetErrSetCondReg( TUint32 u32SetCondBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error release condition' register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint32  u32CoreGetErrRelCondReg( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set a 'Error Set Condition' bit position
    //! @param[in]  u8Pos       - Error bit position
    //! @param[in]  boStatus    - Error status
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetErrSetCond( TUint8 u8Pos, TBoolean boStatus );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error Release Condition' register
    //! @param      u32RelCondBits
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetErrRelCondReg( TUint32 u32RelCondBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set a 'Error Release Condition' bit position
    //! @param[in]  u8Pos       - Error bit position
    //! @param[in]  boStatus    - Error status
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetErrRelCond( TUint8 u8Pos, TBoolean boStatus );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error Restricted Mode' register positive force register
    //! @param      u64RestModeSetBit - Register
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetForceErrRestMode( TUint64 u64RestModeSetBit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error Restricted Mode' positive force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64CoreGetForceErrRestMode( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Clear the 'Error Restricted Mode' negative force register
    //! @note       The clear command overwrites the vCoreSetForceErrRestMode() function call
    //! @param      u64RestModeClrBit - Register
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetForceErrRestModeClr( TUint64 u64RestModeClr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error Restricted Mode' negative force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64CoreGetForceErrRestModeClr( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error set condition' positive force register
    //! @note       The core 'SC-Register' will be set immediately
    //! @param      u32SetCondBits - Register, Set Condition Bits to be forced
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetForceErrSetCond( TUint32 u32SetCondBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error set condition' positive force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreGetForceErrSetCond( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error set condition' negative force register
    //! @note       The clear command overwrites the vCoreSetForceErrSetCond() function call
    //! @param      u32SetCondBitsClr - Register
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetForceErrSetCondClr( TUint32 u32SetCondBitsClr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error set condition' negative force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreGetForceErrSetCondClr( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error release condition' positive force register
    //! @note       The core 'RC-Register' will be set immediately
    //! @param      u32RelCondBits - Register, Release Condition Bits to be forced
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetForceErrRelCond( TUint32 u32RelCondBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error release condition' positive force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint32  u32CoreGetForceErrRelCond( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error release condition' negative force register
    //! @note       The clear command overwrites the vCoreSetForceErrRelCond() function call
    //! @param      u32RelCondBitsClr - Register
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetForceErrRelCondClr( TUint32 u32RelCondBitsClr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error release condition' negative force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint32  u32CoreGetForceErrRelCondClr( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error Excluded Group' positive force register
    //! @param      u64ExcGroupBitSet - Register
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetForceErrExcGroup( TUint64 u64ExcGroupBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error Excluded Group' positive force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint64  u64CoreGetForceErrExcGroup( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the 'Error Excluded Group' negative force register
    //! @note       The clear command overwrites the vCoreSetForceErrExcGroup() function call
    //! @param      u64ExcGroupBits - Register
    //--------------------------------------------------------------------------------------------------
    extern TVoid    vCoreSetForceErrExcGroupClr( TUint64 u64ExcGroupBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the 'Error Excluded Group' negative force register
    //! @return     Register
    //--------------------------------------------------------------------------------------------------
    extern TUint64  u64CoreGetForceErrExcGroupClr( TVoid );

    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error Restricted Mode' register positive force register
        //! @param      u64RestModeSetBit - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrRestMode( TUint64 u64RestModeSetBit );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error Restricted Mode' positive force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint64  u64CoreSimGetForceErrRestMode( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Clear the 'Error Restricted Mode' negative force register
        //! @note       The clear command overwrites the vCoreSetForceErrRestMode() function call
        //! @param      u64RestModeClrBit - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrRestModeClr( TUint64 u64RestModeClr );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Clear the 'Error Restricted Mode' negative force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint64  u64CoreSimGetForceErrRestModeClr( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error set condition' positive force register
        //! @param      u32SetCondBitSet - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrSetCond( TUint32 u32SetCondBits );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error set condition' positive force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint32 u32CoreSimGetForceErrSetCond( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error set condition' negative force register
        //! @note       The clear command overwrites the vCoreSetForceErrSetCond() function call
        //! @param      u32SetCondBitsClr - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrSetCondClr( TUint32 u32SetCondBitsClr );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error set condition' negative force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint32  u32CoreSimGetForceErrSetCondClr( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error release condition' positive force register
        //! @param      u32RelCondBitSet - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrRelCond( TUint32 u32RelCondBits );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error release condition' positive force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint32  u32CoreSimGetForceErrRelCond( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error release condition' negative force register
        //! @note       The clear command overwrites the vCoreSetForceErrRelCond() function call
        //! @param      u32RelCondBitsClr - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrRelCondClr( TUint32 u32RelCondBitsClr );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error release condition' negative force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint32  u32CoreSimGetForceErrRelCondClr( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error Excluded Group' positive force register
        //! @param      u64ExcGroupBitSet - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrExcGroup( TUint64 u64ExcGroupBits );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error Excluded Group' positive force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint64  u64CoreSimGetForceErrExcGroup( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the 'Error Excluded Group' negative force register
        //! @note       The clear command overwrites the vCoreSetForceErrExcGroup() function call
        //! @param      u64ExcGroupBits - Register
        //--------------------------------------------------------------------------------------------------
        extern TVoid    vCoreSimSetForceErrExcGroupClr( TUint64 u64ExcGroupBits );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Get the 'Error Excluded Group' negative force register
        //! @return     Register
        //--------------------------------------------------------------------------------------------------
        extern TUint64  u64CoreSimGetForceErrExcGroupClr( TVoid );

    #endif

    //--------------------------------------------------------------------------------------------------
    //! @brief      Belong to eAccLevel to a ECU-Access level (ACC_ECU_DEV/ACC_ECU_CUS/ACC_ECU_ENG)
    //! @param      eAccLevel
    //! @return     FALSE/TRUE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreFaultIsEcuGroup( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the Error Access Mode
    //! @param[in]  eAccLevel     - Access Level
    //! @param[in]  u16AccLevel   - Access Code
    //! @return     Error Access Permission
    //--------------------------------------------------------------------------------------------------
    extern EErrAccPerm eCoreFaultGiveSingleAccess( EAccLevel eAccLevel, TUint16 u16AccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      'Development fault stack' activate/deactivate
    //! @brief      Note: the 'Development fault stack' is by default "Active"
    //! @param[in]  boActiv  - TRUE:= Activate, FALSE:= Deactivated
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDevelopmentFaultStackActiv( TBoolean boActiv );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Clear the 'error fault stack'
    //!             When the access level is set to ACC_ECU_ENG, all errors are set to inactive and the
    //!             full NVM fault list is deleted. If the access level is not set to ACC_ECU_ENG,
    //!             only inactive faults are deleted from the NVM fault list
    //! @param[in]  eAccLevel     - Access level
    //! @retval     R_OKAY        - fine
    //! @retval     R_ACCESSLEVEL - wrong access level
    //! @retval     R_PHASE       - Function called before the AppInit-Phase, that is not allowed.
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreErrFaultStackClear( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Save the Fault Stack
    //!             -> this function give the task to the 'nvm server device' - to check the request use eCoreNvmServerSta(..)
    //! @retval     R_OKAY        - ok
    //! @retval     R_BUSY        - busy - don't save
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCorrErrSaveFaultStack( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show a change on the error fault list (MUST BE CALLED EACH TASK CYCLE!)
    //!             Errors changes will be reported with a one cycle delay, intended only to be used for
    //!             non time critical updates e.g. for creating custom error lists
    //!             For immediate error reactions use Restricted Modes!
    //! @param[in]  eAccLevel - Access level
    //! @retval     TRUE      - Error fault stack has changed in the last task cycle
    //! @retval     FALSE     - No change
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreErrFaultChange( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get from the error fault list the CAT counter for each CAT member
    //! @param[in]  eAccLevel
    //! @param[out] au8CatCnt
    //! @return     Number of errors in list for given access level
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreErrFaultGetCatCnt( EAccLevel eAccLevel, TUint8 au8CatCnt[ERR_CAT_MAX] );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Give the Counter of the error fault list (only for the ECU-Fault-Access-Level)
    //! @param[out]  pu8CusCnt - Ecu Custumer Counter    (null pointer save)
    //! @param[out]  pu8EngCnt - Ecu Engineering Counter (null pointer save)
    //! @param[out]  pu8DevCnt - Ecu Development Counter (null pointer save)
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreErrFaultEcuCounter( TUint8 *pu8CusCnt, TUint8 *pu8EngCnt, TUint8 *pu8DevCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show the count of there error fault list members
    //! @param[in]  eAccLevel   - Access level
    //! @return     u8Cnt       - Error count
    //--------------------------------------------------------------------------------------------------
    extern TUint8  u8CoreErrFaultCounter( EAccLevel eAccLevel, EErrFilterMode eMode );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Copy the error fault list to the pointer field, the oldest came of index 0
    //! @param[in]   eAccLevel - Access level
    //! @param[out]  ptRec     - Record field [size of the field LIST_ERR_ROW_MAX](NULL Pointer - return 0)
    //! @param[out]  ptExt     - Record field [size of the field LIST_ERR_ROW_MAX](NULL Pointer - don't copy it)
    //! @return      u8Cnt     - Count of copied rows
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreErrFaultStackCopy( EAccLevel eAccLevel, TCoreErrRec *ptRec, TCoreErrRecExt *ptExt );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Copy the error fault list to the pointer field, the oldest came of index 0
    //! @param[in]   eAccLevel - Access level
    //! @param[in]   eMode     - Filter mode
    //! @param[out]  ptRec     - Record field [size of the field LIST_ERR_ROW_MAX](NULL Pointer - return 0)
    //! @param[out]  ptExt     - Record field [size of the field LIST_ERR_ROW_MAX](NULL Pointer - don't copy it)
    //! @return      u8Cnt     - Count of copied rows
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreErrFaultFilterStackCopy( EAccLevel eAccLevel, EErrFilterMode eMode, TCoreErrRec *ptRec, TCoreErrRecExt *ptExt );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Get the error record from the error list
    //! @param[in]   eAccLevel - Access level
    //! @param[in]   u32Code   - Pack error code [u32CoreErrCodePack( cptCfg->u32ErrNum, cptCfg->u8ErrMode, cptCfg->u8ErrModeExt )]
    //! @param[out]  ptRec     - Record (NULL Pointer - return R_NULL_POINTER)
    //! @param[out]  ptExt     - Record (NULL Pointer - don't copy it)
    //! @retval      R_OKAY         - ok
    //! @retval      R_ACCESSLEVEL  - wrong access level
    //! @retval      R_EMPTY        - error code isn't there
    //! @retval      R_NULL_POINTER - ptRec is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreErrFaultGetRec( EAccLevel eAccLevel, TUint32 u32Code, TCoreErrRec *ptRec, TCoreErrRecExt *ptExt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Delete in the error fault list the error code
    //! @param[in]  u32Code           - Pack error code [u32CoreErrCodePack( cptCfg->u32ErrNum, cptCfg->u8ErrMode, cptCfg->u8ErrModeExt )]
    //! @param[in]  eAccLevel         - Access level
    //! @retval     R_OKAY            - ok
    //! @retval     R_RANGE           - don't find the error code
    //! @retval     R_ACCESSLEVEL     - wrong access level
    //! @retval     R_INCONSISTENT    - it not possible to delete an active CL1-Error in a single mode or
    //!                                 an  active error in the ACC_ECU_CUS mode
    //! @retval     R_NOT_INITIALIZED - error element not initialized
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreErrListCodeDelete( TUint32 u32Code, EAccLevel  eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Change the status of error element member via the error code number
    //!             The TimeDetect/TimeReset and ExcludeGroup/SetCond/ReleaCond are not considered for change
    //! @param[in]  eAccLevel  - Access level
    //! @param[in]  u32ErrCode - Error number
    //! @param[in]  eStatus    - Request error status
    //! @retval     R_OKAY            - Error element member have change to active or no active
    //! @retval     R_NOACT           - Error element is in the request state - no change need
    //! @retval     R_RANGE           - No Code found
    //! @retval     R_ACCESSLEVEL     - Wrong Access Level
    //! @retval     R_NOT_INITIALIZED - Error element not initialized (boCoreErrElementsRestored() must return TRUE)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetErrCodeChaStatus( EAccLevel eAccLevel, TUint32 u32ErrCode, EErrSta eStatus );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the last reset time of the error list in seconds
    //! @return      time in seconds
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreErrListLastResetTime( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the last reset time of the fault development list in seconds
    //! @return      time in seconds
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreDevListLastResetTime( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      'Event fault stack' activate/deactivate action - the function should be called in the main function before the while-loop
    //! @brief      Note: the 'Event fault stack' is by default "Active"
    //! @param[in]  boActiv  - TRUE:= Active;  FALSE:=Inactive
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreEventFaultStackActiv( TBoolean boActiv );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show a change on the event fault list (MUST CALL EACH TASK CYCLE!)
    //! @deprecated since 7.3.4.4, should not be used for new projects!
    //! @param[in]  eAccLevel - Access level (works only with ACC_ECU_ENG)
    //! @retval     TRUE      - Error faults stack has changed since the last task cycle
    //! @retval     FALSE     - No change
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreEveFaultChange( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Copy the event fault list to the pointer field, the oldest came of index 0
    //! @param[in]   eAccLevel   - Access level (need ACC_ECU_ENG, else return 0)
    //! @param[out]  ptRec       - Record field [size of the field LIST_EVE_ROW_MAX](NULL Pointer - return 0)
    //! @param[out]  ptExt       - Record field [size of the field LIST_EVE_ROW_MAX](NULL Pointer - don't copy it)
    //! @return      u8Cnt       - Event count
    //--------------------------------------------------------------------------------------------------
    extern TUint8  u8CoreEveFaultStackCopy( EAccLevel eAccLevel, TCoreEveRec *ptRec, TCoreEveRecExt *ptRecExt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Clear the 'event fault stack'
    //! @param[in]  eAccLevel     - Access level (need ACC_ECU_ENG)
    //! retval      R_OKAY        - fine
    //! retval      R_ACCESSLEVEL - wrong access level
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreEveFaultStackClear( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Give the Counter of the event fault list
    //! @param[in] eAccLevel     - Access level (need ACC_ECU_ENG, else return 0)
    //! @return    Counter
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreEveFaultCounter( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Delete in the event fault list the error code
    //! @param[in]  u32Code   - Pack error code [u32CoreErrCodePack( cptCfg->u32ErrNum, cptCfg->u8ErrMode, cptCfg->u8ErrModeExt )]
    //! @param[in]  eAccLevel - Access level
    //! @retval     R_OKAY  - ok
    //! @retval     R_RANGE - don't find the error code
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreEveListCodeDelete( TUint32 u32Code );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the last reset time of the fault event list in seconds
    //! @return     time in seconds
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CoreEveListLastResetTime( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Store the Error and Event List
    //! @retval     R_OKAY  - ok
    //! @retval     R_BUSY  - is busy
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreErrEveListStore( TVoid );

    // ==============================================================================================================
    // !! The use of these functions in the application leads immediately to the exclusion of the HYDAC liability. !!
    // !! The use of the entire application with all the components used a call at your own risk.                  !!
    // !! IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED                !!
    // ==============================================================================================================
    #if defined(COMPILER_SWITCH_CORE_BUILD) || defined(COMPILER_SWITCH_PTC_BUILD)

     #define ERR_LINK_IDX_FREE   0xFF  //! indicator that the error list have no linked extended error record (e.g. an freeze frame)

     //--------------------------------------------------------------------------------------------------
     //! @brief      Set application feedback function (for freeze frame support)
     //! @detail     Given function in pfvCoreErrAppCallFeedbackFunc will be called not only in app but also internal phases.\n
     //!             This is intended for background service functionality to store/update freezeframe data
     //! param[in]   pfvCoreErrAppCallFeedbackFunc   - Err call - for each app phase
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreErrAppCallFeedbackFunc( TVoid (*pfvCoreErrAppCallFeedbackFunc)(EMainPhase eMainPhase) );

     //--------------------------------------------------------------------------------------------------
     //! @brief      Set error init finished feedback function (for freeze frame support)
     //! @detail     Given function in pfvCoreErrInitFeedbackFunc will be called before AppInit when all error elements and DB lists are initialized.
     //!             Can be used for example to restore freezeframe data/links.
     //! param[in]   pfvCoreInitFeedbackFunc   - callback function for initialize something before the error list can change
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreErrInitFeedbackFunc( TVoid (*pfvCoreErrInitFeedbackFunc)( TVoid ) );

     //--------------------------------------------------------------------------------------------------
     //! @brief      Prototype for callback function used when error is added/changed/deleted in list
     //! @param[in]     cptCfg          error configuration
     //! @param[in]     boList          TRUE: error code in error list / FALSE: error code is not in error list
     //! @param[in]     boActive        TRUE: error is active / FALSE error inactive
     //! @param[in]     u8EngOccCnt     engineering occurrence count
     //! @param[in]     u8CusOccCnt     customer occurrence count
     //! @param[in,out] pu8LinkIdx      link index for error, should be set for new error
     //--------------------------------------------------------------------------------------------------
     typedef TVoid (*TFpvCoreErrChangedFeedback)( const TErrCfgFea *cptCfg, TBoolean boList, TBoolean boActive,
                                                  TUint8 u8EngOccCnt, TUint8 u8CusOccCnt, TUint8* pu8LinkIdx );

     //--------------------------------------------------------------------------------------------------
     //! @brief      Set error list feedback functions (for freeze frame support)
     //! param[in]   pfvCoreErrChangedFeedback   - callback function triggered by changes to error in list
     //! WARNING:
     //!    This callback function might be triggered multiple times per cycle, so has to be very fast
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreErrSetFeedbackFunc( TFpvCoreErrChangedFeedback pfvCoreErrChangedFeedback );

     //--------------------------------------------------------------------------------------------------
     //! @brief      Set error list stored feedback function (for freeze frame support)
     //! param[in]   pfvCoreErrStoredFeedback   - callback function triggered when error list is stored
     //! WARNING:
     //!    pfvCoreErrStoredFeedback is usually triggered if other nvmem operations are run/started
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreErrStoFeedbackFunc( TVoid (*pfvCoreErrStoredFeedback)( TVoid ));

     //--------------------------------------------------------------------------------------------------
     //! @brief      Set if updating of error bits should be globally disabled \n
     //!             Function should only be called in app phase >=MAIN_APP_PRE_START
     //! @warning    Normally not to be called by application, the user should ensure that there will be no conflicts.
     //! @param      boDisable - TRUE=disable updating err status, FALSE=enable [DFLT: FALSE]
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreErrDisableUpdating( TBoolean boDisable );

    #endif

#endif
