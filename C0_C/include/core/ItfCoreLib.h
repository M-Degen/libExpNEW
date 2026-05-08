//**************************************************************************************************
/*!
@file       ItfCoreLib.h
@brief      Core library interface
@date       01.02.2013 
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCORELIB__
    #define __ITFCORELIB__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCore.h>
    #include <ItfCoreBoard.h>

    #define NO_BLOCK_ENUMTYPE_NUM  ((TUint16) 0xFFFF)               //!< No block enum type
    #define NO_SIGNAL_ENUMTYPE_NUM ((TUint16) 0xFFFF)               //!< No signal enum type

    //- Only for the protocol interface and the block can interface to use -------------------------

    #ifdef COMPILER_SWITCH_BLO_60_SIG_60
	 #define BLO_INFO_CUST_MAX           60                         //!< Block info custumer limit
     #define SIG_INFO_CUST_MAX           60                         //!< Signal info custumer limit
    #else
     #define BLO_INFO_CUST_MAX           40                         //!< Block info custumer limit
     #define SIG_INFO_CUST_MAX           30                         //!< Signal info custumer limit
	#endif

	#define PTC_INFO_CUST_MAX             6                         //!< PTC types     - since 7.4.1.0 old value  8
    #define PTC_INFO_CUST_INSTANCE_MAX   12                         //!< PTC instances - since 7.4.1.0 old value 16

    #ifdef COMPILER_SWITCH_FAM_TTC5XX
     #define BLOCAN_INFO_CUST_MAX        16                         //!< Block can types
    #else
     #ifdef COMPILER_SWITCH_FAM_TTC3X
       #define BLOCAN_INFO_CUST_MAX       4                         //!< Block can types
     #else
       #define BLOCAN_INFO_CUST_MAX       8                         //!< Block can types
     #endif
    #endif

    //! Block custumer information  recorder
    typedef struct
    {
        TChar              *pchName;                                //!< Block name
        TUint16            u16Stamp;                                //!< Block stamp
        ERetVal            (*pfeBloCreateInit)( TVoid *pvBlo);      //!< Block create/Init function
        const TVerChapCom* (*pfpctBloVersion) ( TVoid );            //!< Block Information
        TBoolean           (*pfboBloCheck)    ( TVoid );            //!< Block Check
    }TBloInfoCustRec;

    //! Block custumer information
    typedef struct
    {
        TUint8          u8Cnt;                                      //!< Count
        TBloInfoCustRec atRec[BLO_INFO_CUST_MAX];                   //!< Block Record set
    }TBloInfoCust;

    //! Signal custumer information record
    typedef struct
    {
        TChar               *pchName;                               //!< Signal name
        TUint16             u16Stamp;                               //!< Signal stamp
        const TVerChapCom* (*pfpctSigVersion)( TVoid );             //!< Signal Information
        TBoolean           (*pfboSigCheck)   ( TVoid );             //!< Signal Check
    }TSigInfoCustRec;

    //! Signal custumer information
    typedef struct
    {
        TUint8          u8Cnt;                                      //!< Count
        TSigInfoCustRec atRec[SIG_INFO_CUST_MAX];                   //!< Signal Record set
    }TSigInfoCust;

    //! Protocol custumer information record
    typedef struct
    {
        const TChar         *cpchName;                                                  //!< PTC name
        const TVerChapCom* (*pfpctPtcVersion)(TVoid);                                   //!< PTC Information
        TBoolean           (*pfboPtcCheck)   (TVoid);                                   //!< PTC Check
        TVoid              (*pfvPtcAppCall)  (EMainPhase eMainPhase );                  //!< PTC App Call
        TBoolean           (*pfboPtcRcvHwBuf)(ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg );  //!< PTC Can Rcv Hw buffer
        TBoolean           (*pfboPtcSndHwBuf)(ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg );  //!< PTC Can Snd Hw buffer
        ERetVal             *pePtcSndHwSta;                                             //!< PTC Can Snd Status Pointer
    }TPtcInfoCustRec;

    //! Protocol config
    typedef struct
    {
        const TChar      *cpchName;                                 //!< PTC name
        TVoid*           pvPtcCfg;                                  //!< PTC Configuration struct
    }TPtcInfoCfgPtr;

    //! Protocol custumer information
    typedef struct
    {
        TUint8          u8RecCnt;                                   //!< Record Counter
        TPtcInfoCustRec atRec[PTC_INFO_CUST_MAX];                   //!< Signal Record set
        TUint8          u8CfgCnt;                                   //!< Configuration Counter
        TPtcInfoCfgPtr  atCfg[PTC_INFO_CUST_INSTANCE_MAX];          //!< Configuration
    }TPtcInfoCust;

    //! Block can custumer information record
    typedef struct
    {
        TVoid           (*pfvBloAppCall)  (EMainPhase eMainPhase, TVoid *pvMem );                  //!< Transfer App Call
        TBoolean        (*pfboBloRcvHwBuf)(ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg, TVoid *pvMem );  //!< Transfer Can Rcv Hw buffer
        TBoolean        (*pfboBloSndHwBuf)(ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg, TVoid *pvMem );  //!< Transfer Can Snd Hw buffer
        TVoid            *pvMem;
        ERetVal          *peBloSndHwSta;
    }TBloCanInfoCustRec;

    //! Block can custumer information
    typedef struct
    {
        TUint8             u8RecCnt;                                //!< Record Counter
        TBloCanInfoCustRec atRec[BLOCAN_INFO_CUST_MAX];             //!< Signal Record set
    }TBloCanInfoCust;

    //--------------------------------------------------------------------------------------------------
    //! @brief    Check if a block can used a ecu PIN
    //! @param    ePin        - PIN number
    //! @param    cpchBloName - Block name
    //! @param    eBloSta     - Block status
    //! @retval   R_OKAY      - is OK / if PIN is PIN_NA,PIN_SYS or not in used by a other PIN
    //! @retval   R_CONFIG    - is used                  - vPrint("ERR: Pin[%d] is in used from Blo[%s] and Blo[%s]\n", ...);
    //! @retval   R_RANGE     - PIN number is not valid  - vPrint("ERR: Pin[%d] from Blo[%s] is invalid\n", ...)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBloCheckPinFree( EPin ePin, EBloStatus eBloSta, const TChar *cpchBloName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Report block problem
    //! @param[in]  cpchObTypeName - [-] block type name
    //! @param[in]  cpchObjName    - [-] block name
    //! @param[in]  eErrorCode     - [-] error type
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreObjInitProblems( const TChar* cpchObTypeName, const TChar *cpchObjName, ERetVal eErrorCode );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show object problem
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreShowObjInitProblems( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show NULL pointer error with type information
    //! @param[in]  cpchTyp    - object type
    //! return      R_NOT_NAME
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreShowErrorNullName( const TChar *cpchTyp  );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show NULL pointer error with type and object name information
    //! @param[in]  cpchTyp    - object type
    //! @param[in]  cpchObj    - object name
    //! return      R_NULL_POINTER
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreShowErrorNullPointer( const TChar *cpchTyp, const TChar *cpchObj );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show a not registry error
    //! @param[in]  cpchObj    - object name
    //! return      R_NOT_REGISTRY
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreShowErrorRegistry( const TChar *cpchObj );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Register a new block type ( *** needed if the block was created with the PDT [no user function] ***)
    //! @param[in]  cpchName         - Block type name as string
    //! @param[in]  eNo              - Block number
    //! @param[in]  pfeBloCreateInit - Block create/init function
    //! @param[in]  pfcptBloVersion  - Block versions information
    //! @param[in]  pfboBloCheck     - Block versions check
    //! @retval     R_OKAY           - OK
    //! @retval     R_OVERFLOW       - To much objects registered
    //! @retval     R_RANGE          - Object name to long
    //! @retval     R_INCONSISTENT   - eNo isn't sequently [0,1,2...]
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBloRegistry( const TChar *cpchName, EBloTyp eNo, ERetVal (*pfeBloCreateInit)( TVoid *pvBlo ),
                                     const TVerChapCom* (*pfcptBloVersion)(TVoid), TBoolean (*pfboBloCheck)(TVoid) );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Register a block type, from the application [or block layer]
    //! @param[in]  cpchName         - Block type name as string
    //! @param[in]  pfeBloCreateInit - Block create/init function
    //! @param[in]  pfcptBloVersion  - Block versions information
    //! @param[in]  pfboBloCheck     - Block versions check
    //! @retval     R_OKAY           - OK
    //! @retval     R_OVERFLOW       - To much objects registered
    //! @retval     R_RANGE          - Object name to long
    //! @retval     R_DOUBLE_CALL    - Block is double
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBloRegistryAdd( const TChar *cpchName, ERetVal (*pfeBloCreateInit)( TVoid *pvBlo ),
                                        const TVerChapCom* (*pfcptBloVersion)(TVoid), TBoolean (*pfboBloCheck)(TVoid) );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give block enum
    //! @param[in]  cpchName  - Block type name as string
    //! @retval     enum      - - BLO_LIB_NA isn't valid
    //--------------------------------------------------------------------------------------------------
    extern EBloTyp eCoreGiveBlockEnum( const TChar *cpchName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check enum type with the block stamp
    //! @param[in]  eNo       - Block number
    //! @retval     Stamp     - Block stamp
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreGetBloStamp( EBloTyp eNo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check signal address pointer
    //! @param[in]  eNo            - Signal type
    //! @param[in]  vpAdr          - Signal pointer as cast with void
    //! @retval     R_OKAY         - Pointer OK
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - Wrong block address
    //! @retval     R_NOT_REGISTRY - Block not registered
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCheckBloAdrPtr( EBloTyp eNo, TVoid *vpAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check signal stamp
    //! @param[in]  eNo            - Block type
    //! @param[in]  u16Stamp       - Stamp
    //! @retval     R_OKAY         - Pointer OK
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - wrong block address
    //! @retval     R_NOT_REGISTRY - block not registered
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCheckBloStamp( EBloTyp eNo, TUint16 u16Stamp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Malloc memory and store the information there pchType="SIG_LUT" pchName"Left" => "SIG_LUT.Left"
    //! @param[in]  cpchType - Type string pointer (if this parameter is NULL the function does nothing, the retval is NULL)
    //! @param[in]  cpchName - Name string pointer (can be NULL - is an optional parameter)
    //! @param[in]  u8MaxLen - Maximum length of the result string (including the terminating NULL character)
    //! @retval     Pointer  - Char pointer
    //! @retval     NULL     - No memory available
    //--------------------------------------------------------------------------------------------------
    extern TChar *pchCoreCreateNamingSpace( const TChar *cpchType, const TChar* cpchName, TUint8 u8MaxLen );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Register a new signal type (*** needed if the signal was created with the PDT [no user function] ***)
    //! @param[in]  cpchName          - Signal type name as string
    //! @param[in]  eNo               - Signal number
    //! @param[in]  pfcptSigVersion   - Signal information
    //! @param[in]  pfboSigCheck      - Signal check
    //! @retval     R_OKAY            - OK
    //! @retval     R_OVERFLOW        - To much objects registered
    //! @retval     R_RANGE           - Object name to long
    //! @retval     R_INCONSISTENT    - eNo isn't sequently [0,1,2...]
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSigRegistry( const TChar *cpchName, ESigTyp eNo, const TVerChapCom* (*pfcptSigVersion)(TVoid), TBoolean (*pfboSigCheck)(TVoid) );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Register a signal type, from the application [or block layer]
    //! @param[in]  cpchName          - Signal type name as string
    //! @param[in]  pfcptSigVersion   - Signal information
    //! @param[in]  pfboSigCheck      - Signal check
    //! @retval     R_OKAY            - OK
    //! @retval     R_OVERFLOW        - To much objects registered
    //! @retval     R_RANGE           - Object name to long
    //! @retval     R_DOUBLE_CALL     - Block is double
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSigRegistryAdd( const TChar *cpchName, const TVerChapCom* (*pfcptSigVersion) (TVoid), TBoolean (*pfboSigCheck)(TVoid) );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give signal enum
    //! @param[in]  cpchName  - Signal type name as string
    //! @retval     enum      - SIG_LIB_NA isn't valid
    //--------------------------------------------------------------------------------------------------
    extern ESigTyp eCoreGiveSignalEnum( const TChar *cpchName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Signal stamp check function
    //! @param[in]  eNo       - Signal type
    //! @retval     Stamp     - Block stamp
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CoreGetSigStamp( ESigTyp eNo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check signal address pointer
    //! @param[in]  eNo            - Signal type
    //! @param[in]  vpAdr          - Signal pointer as cast with void
    //! @retval     R_OKAY         - Pointer OK
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - Wrong signal address
    //! @retval     R_NOT_REGISTRY - Signal not registered
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCheckSigAdrPtr( ESigTyp eNo, TVoid *vpAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check signal address pointer
    //! @param[in]  eNo            - Signal type
    //! @param[in]  vpAdr          - Signal pointer as cast with void
    //! @retval     R_OKAY         - Pointer OK
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - Wrong signal address
    //! @retval     R_NOT_REGISTRY - Signal not registered
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCheckSigStamp( ESigTyp eNo, TUint16 u16Stamp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Build type name string (overload save)  e.g type.name -> BloDig.Y12
    //! @param[in]  pchDestination - Pointer to the destination array
    //! @param[in]  cpchTyp         - Object type
    //! @param[in]  cpchName        - Object name
    //! @param[in]  u8StrLen       - Maximum number destination array
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreBuildTypNameStr( TChar *pchDestination, const TChar *cpchTyp, const TChar *cpchName, TUint8 u8StrLen );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Core block can transfer (Prepared for use in a block e.g. call the funktion in the block init funktion)
    //! @param[in]  pfvAppCall    - Transfer call - called every cycle
    //!                             (If the function call is not required, NULL must be passed)
    //! @param[in]  pfboCRcvHwBuf - Transfer call - TBoolean(*pfboCanRcvHw)( ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg )
    //!                                                 param[in] eRcvBuf  - hardware receive buffer
    //!                                                 param[in] ptRcvMsg - receive message
    //!                                                 retval    TRUE     - consume the message - message will not be available for processing by other functions
    //!                                                 retval    FALSE    - the message will be handled by the system
    //!                             (If the function call is not required, NULL must be passed)
    //! @param[in]  pfboCSndHwBuf - Transfer call - TBoolean (*pfboSndHwBuf)( ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg)
    //!                                                 param[in] eSndBuf  - hardware send buffer
    //!                                                 param[in] ptSndMsg - send message
    //!                                                 retval    TRUE     - send ptSndMsg out
    //!                                                 retval    FALSE    - dont't send ptSndMsg out
    //!                             (If the function call is not required, NULL must be passed)
    //! @param[in]  peSndHwSta    - Status from the last pfboPtcSndHwBuf function call.
    //!                             (If the value is not required, NULL must be passed)
    //! @param[in]  pvMem         - block/configuration struct memory
    //!
    //!   Important: The function pfboSndHwBuf is not called if an CAN-Overflow/Err came or the CSnd:u8CallCountOfCycle is reached!
    //!              (Possible solution: Use an flag, set it in pfboSndHwBuf(..) and check is in pfvAppCall(..))
    //!              If a message can't be sent, try again in the next task cycle, until the message gets out.
    //!              If that doesn't work, throw an error (DM_xxx_SND_CALL_COUNTER), if that is not implemented:
    //!              use a can hardware send buffer exclusive and the u8CallCountOfCycle must be equal to u8HwSndSize.
    //!              If a message does not go out a DM_xxx_SND_OVERFLOW error is thrown,
    //!              and so it is possible to diagnose the problem of the transmission behavior
    //!
    //! @retval     R_OKAY          - okay
    //! @retval     R_CONFIG        - to much objects registered [TTC5xx=16, TTC3x=4, else=8]
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBloCanTrans( TVoid    (*pfvAppCall)   (EMainPhase eMainPhase, TVoid *pvMem),
                                     TBoolean (*pfboCRcvHwBuf)(ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg, TVoid *pvMem),
                                     TBoolean (*pfboCSndHwBuf)(ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg, TVoid *pvMem),
                                     ERetVal   *peSndHwSta, TVoid *pvMem );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Register a Protocol (*** needed if the protocol was not created with the PDT ***)
    //! @param[in]  cpchName        - Protocol name
    //! @param[in]  pfcptPtcVersion - Protocol version function call
    //! @param[in]  pfboPtcCheck    - Protocol check function
    //! @param[in]  pvPtcCfg        - Protocol configuration struct
    //! @param[in]  pfvPtcAppCall   - Protocol call - called every cycle
    //! @param[in]  pfboPtcCanRcvHw - Protocol call - TBoolean(*pfboPtcCanRcvHw)( ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg )
    //!                                                 param[in] eRcvBuf  - hardware receive buffer
    //!                                                 param[in] ptRcvMsg - receive message
    //!                                                 retval    TRUE     - consume the message - message will not be available for processing by other functions
    //!                                                 retval    FALSE    - the message will be handled by the system
    //! @param[in]  pfboPtcCanSndHw - Protocol call - TBoolean (*pfboPtcSndHwBuf)( ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg)
    //!                                                 param[in] eSndBuf  - hardware send buffer
    //!                                                 param[in] ptSndMsg - send message
    //!                                                 retval    TRUE     - send ptSndMsg out
    //!                                                 retval    FALSE    - dont't send ptSndMsg out
    //!
    //!    The call order of pfvPtcAppCall, pfboPtcRcvHwBuf, pfboPtcSndHwBuf is the following:
    //!         vCoreMain( ... ) [ vAppSafetyInit(..), eAppPreStart(..), eAppStartUp(..), ... vAppRun(..), eAppShutDown(..)]
    //!         if( CAN is ready ){ pfboPtcRcvHwBuf(..) }
    //!         pfvPtcAppCall(..)
    //!         if( CAN is ready ){ pfboPtcSndHwBuf(..) }
    //!
    //!   Important: The function pfboPtcSndHwBuf is not called if an CAN-Overflow/Err came or the CSnd:u8CallCountOfCycle is reached!
    //!              (Possible solution: Use an flag, set it in pfboPtcSndHwBuf(..) and check is in pfvPtcAppCall(..))
    //!              If a message can't be sent, try again in the next task cycle, until the message gets out.
    //!              If that doesn't work, throw an error (DM_PTC_xxx_SND_CALL_COUNTER), if that is not implemented:
    //!              use a can hardware send buffer exclusive and the u8CallCountOfCycle must be equal to u8HwSndSize.
    //!              If a message does not go out a DM_PTC_xxx_SND_OVERFLOW error is thrown,
    //!              and so it is possible to diagnose the problem of the transmission behavior
    //!
    //! @retval     R_OKAY          - okay
    //! @retval     R_MEMORY        - No Memory
    //! @retval     R_OVERFLOW      - to much objects registered
    //! @retval     R_RANGE         - object name to long
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCorePtcRegistry( const TChar *cpchName, const TVerChapCom* (*pfcptPtcVersion)(TVoid), TBoolean (*pfboPtcCheck)(TVoid),
                                     TVoid *pvPtcCfg, TVoid (*pfvPtcAppCall)(EMainPhase eMainPhase),
                                     TBoolean (*pfboPtcRcvHwBuf)(ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg),
                                     TBoolean (*pfboPtcSndHwBuf)(ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg) );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Prototype for eCorePtcShutDown
    //--------------------------------------------------------------------------------------------------
    typedef ERetVal (*TFpePtcUsbShutDown)(TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Sets a separate 'shut done' phase if K15 is 'OFF'
    //! @param[in] pfePtcUsbShutDown
    //!             retval  R_OKAY  - pfePtcUsbShutDown function call never will call again
    //!             retval  !R_OKAY - pfePtcUsbShutDown function call will call again - in the next task
    //! @retval  R_OKAY         - Fine
    //! @retval  R_RANGE        - The protocol 'shut down' function call queue is full
    //! @retval  R_NULL_POINTER - Parameter is a NULL-Pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCorePtcShutDown( TFpePtcUsbShutDown pfePtcUsbShutDown );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Prepare the function pvCorePtcGiveCfg() -> see function 'pvCorePtcGiveCfg()'
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCorePtcPrepareGiveCfg( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give PTC Configuration struct of PTC type - call the function until the result is 'NULL'
    //! @note       To start a new iteration call the function 'vCorePtcPrepareGiveCfg()' first.
    //! @param[in]  cpchTypeName  - PTC type name as string
    //! @param[in]  peSndHwSta    - Status from the last pfboPtcSndHwBuf function call
    //! @retval     vpPtcCfg      - NULL isn't valid
    //--------------------------------------------------------------------------------------------------
    extern TVoid* pvCorePtcGiveCfg( const TChar* cpchPtcTypeName, ERetVal *peSndHwSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the block custumer information field
    //! @return     Pointer
    //--------------------------------------------------------------------------------------------------
    extern const TBloInfoCust *cptCoreBloInfoCust( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the signal custumer information field
    //! @return     Pointer
    //--------------------------------------------------------------------------------------------------
    extern const TSigInfoCust *cptCoreSigInfoCust( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the protocol custumer information field
    //! @return     Pointer
    //--------------------------------------------------------------------------------------------------
    extern const TPtcInfoCust *cptCorePtcInfoCust( TVoid );

#endif
