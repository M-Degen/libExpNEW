//**************************************************************************************************
/*!
@file           ItfPtcMst.h
@brief          Protocol interface
@date           01.04.2019
@version        0.9.12.0
@author         HYDAC/NJP
@changelog
-#  0.7.0.1 18.04.2018  Initial version of separate PtcMst
-#  0.7.0.1 18.04.2018  fixed: MST_LIST_ELE_DEFT_READ returns implausible values
-#  0.7.0.1 18.04.2018  fixed: CST_LIST_ELE_WRITE: wrong response for BigEndian
-#  0.7.0.1 19.04.2018  fixed: MST_ERR_LIST_READ unexpectedly returns R_PTC_ERR
-#  0.7.0.1 19.04.2018  fixed: MST_ERR_CODE_DELETE only working with Access Level ACC_ECU_ENG and wrong return codes
-#  0.7.0.1 05.05.2018  fixed: function vCoreSetForceErrRestMode() not setting restricted mode to active
-#  0.7.0.1 18.05.2018  Added the second App in the versions info request
-#  0.7.0.1 18.05.2018  Added Sub-Commands for the error registers
-#  0.7.0.1 18.05.2018  new option by MST_SET_DEBUG_MODE -> Ecu Freeze Mode
-#  0.7.0.1 24.05.2018  better login control
-#  0.7.0.1 05.06.2018  Added MST_GET_APP_PHASE
-#  0.7.0.1 24.08.2018  fixed: MST_EVE_LIST_STORE running into error loop
-#  0.7.0.1 31.08.2018  fixed: MST_ERR_SETSTA_INFO subcmds for 64bit registers can now reset their values
-#  0.8.0.0 10.09.2018  changed version
-#  0.8.0.0 20.09.2018  changed: ACC_ECU_ENG bypass for db var access
-#  0.8.0.0 02.10.2018  fixed: MST_REGISTER_UPDATE
-#  0.8.1.0 28.11.2018  changed: MST_LIST_PARAMNO, list index at byte1, default parameter index at byte 2/3
-#  0.8.1.0 17.12.2018  changed: bypass silent mode for version information(MST_GET_SW_VERSION)
-#  0.8.1.0 17.12.2018  added: function ePtcMstGetAccessLevel to get current access level
-#  0.8.1.0 01.02.2019  changed default access level to ACC_CUSTOMER
-#  0.8.1.0 01.02.2019  added: ePtcMstMapEcuToSingleLevel to define db access for ACC_ECU_CUS/DEV
-#  0.8.2.0 01.04.2019  added: vPtcMstSetMstSa to change ecu sa and vPtcMstInitAfterAppPhase to defer start of mst output
-#  0.9.0.0 15.05.2019  changed: added licensing status to MST startup message at byte 4(HCP_ECU_START)
-#  0.9.0.0 15.05.2019  changed: MST_GET_PTC_VER response: byte 6 is now third PTC version number(u8Index)
-#  0.9.0.0 15.05.2019  removed: vPtcMstChangeType()
-#  0.9.0.0 05.06.2019  changed: MST_GET_PTC_VER -> eType at Byte 7, Bit 6
-#  0.9.0.0 05.08.2019  added: TPtcMstLastCmd* cptPtcMstGetLastCmd to retrieve last handled command
-#  0.9.0.0 06.08.2019  changed: startup message only if protocol is active
-#  0.9.1.0 09.08.2019  changed: one request message per src is buffered
-#  0.9.1.0 12.08.2019  changed: one request handled at a time
-#  0.9.2.0 23.10.2019  fixed: 2app handling was never executed
-#  0.9.2.0 24.10.2019  fixed: error changes detected even if snd can not be called
-#  0.9.3.0 06.12.2019  fixed: uninitialized 2app canids used without 2app
-#  0.9.4.0 10.06.2020  added: list DB vars with non-dflt value
-#  0.9.4.0 10.06.2020  added: mst requests to other controller[s]
-#  0.9.4.0 10.06.2020  fixed: MST_LIST_ELE_DEFT_READ/MST_CID_ELE_DEFT_READ for 16/32bit vars
-#  0.9.4.0 10.06.2020  added: MST_DB_DIAGNOSE_DFLT_CHA, MST_DB_DIAGNOSE_RANG_CHECK, MST_DB_DIAGNOSE_CONTROL
-#  0.9.5.0 25.08.2020  added: MST_LIST_DEFAULT_ALL
-#  0.9.5.0 25.08.2020  changed: link last used for client handling not able to receive requests until vPtcMstReqComUnlockRequest
-#  0.9.5.0 25.09.2020  added: MST_GET_TIMESTAT_MAX, MST_GET_TIMESTAT_AVG
-#  0.9.6.0 25.11.2020  fixed: 2App pos response for MST_LIST_LOAD, MST_LIST_STORE, MST_LIST_DEFAULT_ALL
-#  0.9.7.0 08.03.2021  fixed: TTC5X MST_DIAGNOSE_PIN_IDX returns wrong value for PWM feedback current
-#  0.9.7.0 26.05.2021  added: MST_RESET_TIMESTAT
-#  0.9.8.0 30.11.2021  version for codesys with updated pinforcing
-#  0.9.8.0 10.12.2021  fixed: _requested_ HCP_ECU_START response CAN ID depends on used target id, event uses ID_MODE_MST
-#  0.9.8.1 05.07.2022  changed: handle size of factory setting variables for DB read
-#  0.9.8.1 11.08.2022  added: new licensing services
-#  0.9.8.2 25.11.2022  ttc2xxx updates
-#  0.9.9.0 12.07.2023  ttc2xxx added pin diagnosis extended ( MST_DIAGNOSE_PIN_IDX_EXTD )
-#  0.9.9.0 09.08.2023  #82168 - MST_STORE_ALL_LICENSE: falsche negative Antwort
-#  0.9.9.1 29.08.2023  merge MST User Logging with TTC2xxx
-#  0.9.9.2 28.09.2023  updated PININ / PINOUT checks for TTC2xxx
-#  0.9.10.0 16.02.2024 update user logging
-#  0.9.11.0 10.09.2024 added: MST_LOG_GET_STATE
-#  0.9.11.0 18.09.2024 activating m_vMstGetDiagPin for unjo
-#  0.9.12.0 29.10.2024 introduce MST-CAN-Communication encryption activation via ePtcMstActivateEncryption
-#  0.9.12.0 07.11.2024 adding MST Usr Log vCoreDbUsrLogMstSetAccessLevel & MST_LOG_GET_ACC_LVL & MST_LOG_GET_ACTIVATION_LOCK
-#  0.9.12.0 19.12.2024 adding MST Usr Log MST_LOG_NOTIFY_RESET notifying about a state of the log that needs a fresh restart of the currently running session
*/
//**************************************************************************************************

#ifndef __ITFPTCMST__
    #define __ITFPTCMST__

    #include <ItfCore.h>
    #include <ItfCoreCan.h>
    #include <ItfBasEleErr.h>
    #include <ItfCoreDb.h>
    #include <ItfCoreBoard.h>

    #define DM_PTC_MST_SND_OVERFLOW    0       //!< CAN send overflow fault
    #define DM_PTC_MST_FAULT_MAX       1       //!< Max fault count

    //! Protocol Type
    typedef enum
    {
        PTC_MST_HYDSTD,                        //!< Standard protocol based on list and index number
        PTC_MST_HYDCID                         //!< protocol based on command identifier
    }EMstHydac;

    //! MST Mode
    typedef enum
    {
        PTC_MST_MODE_SILENCE,                  //!< Silence [Ecu Default]
        PTC_MST_MODE_FIRST_TIME,               //!< Open for the first time
        PTC_MST_MODE_FULL_OPEN                 //!< Permanent open
    }EMstMode;

     //! Link Type
    typedef enum
    {
        MST_LINK_CAN=0    //!< CAN connection
        #ifdef COMPILER_SWITCH_RSBUS
        ,MST_LINK_RS=1    //!< RS connection
        #endif
        #ifdef COMPILER_SWITCH_ETHBUS
        ,MST_LINK_ETH     //!< ETH connection
        #endif
        #ifdef COMPILER_SWITCH_ENV_CDS_23
        ,MST_LINK_CDS23   //!< CoDeSys 2.3
        #endif
    }EMstLinkType;


    //! Id-Mode-Selector
    typedef enum
    {
       ID_MODE_BCST,            //<! 0 - MST Interface (Broadcast Interface -> First Application  )
       ID_MODE_BCST_2APP,       //<! 1 - MST Interface (Broadcast Interface -> Second Application )
       ID_MODE_MST,             //<! 2 - MST Interface (Ecu Interface       -> First Application  )
       ID_MODE_MST_2APP,        //<! 3 - MST Interface (Ecu Interface       -> Second Application )
       ID_MODE_CLU,             //<! 4 - MST Interface (Cluster Interface   -> First Application  )
       ID_MODE_CLU_2APP,        //<! 5 - MST Interface (Cluster Interface   -> Second Application )
       ID_MODE_HMG,             //<! 6 - MST Interface (Hmg Interface       -> First Application  )
       ID_MODE_HMG_2APP,        //<! 7 - MST Interface (Hmg Interface       -> Second Application )
       ID_MODE_REM,             //<! 8 - MST Interface (Remote Interface    -> First Application  )
       ID_MODE_REM_2APP,        //<! 9 - MST Interface (Remote Interface    -> Second Application )
       ID_MODE_UNKNOWN          //<! 9 - Unknown - internal handling
    }EIdMode;

     //! Protocol information
    typedef struct
    {
        //! Common
        TChar        achName[PTC_NAME_STR_LEN];  //!< [STR] Block name
        //! Setting
        TBoolean     boActiv;                    //!< [DEF] Protocol active
        EMstHydac    eType;                      //!< [DEF] Protocol type switch
        TUint16      u16MstPrintBufSize;         //!< [DEF] Print buffer Size
        EMstLinkType eLinkType;                  //!< [DEF] Link type
        ECBusHwBuf   eMstSndHwBufNo;             //!< [DEF] CAN send buffer position connection link
        ECBusHwBuf   eMstRcvHwBufNo;             //!< [DEF] CAN receive buffer position connection link
        TBoolean     boBcstActive;               //!< [DEF] Broadcast Active (for FaultUpdate and FaultRegisterUpdate)
        TBoolean     boCanExt;                   //!< [DEF] Extended CAN ID
        TUint8       u8Prio;                     //!< [NUM] Message priority
        TUint8       u8BcstSa;                   //!< [NUM] Broadcast SA
        TUint8       u8EcuSa;                    //!< [NUM] J1939 ECU SA
        TUint8       u8MstSa;                    //!< [NUM] J1939 MST SA
        TUint8       u8CluSa;                    //!< [NUM] J1939 Cluster SA
        TUint8       u8HmgSa;                    //!< [NUM] J1939 HMG SA
        TUint8       u8RemSa;                    //!< [NUM] J1939 Remote Maintenance SA
        ECanFormat   eDbValueFormat;             //!< [DEF] DB - Value Format (Read/Write)
        ECanFormat   eDbComIdFormat;             //!< [DEF] DB - COM-ID Format
        ECanFormat   eOthersFormat;              //!< [DEF] Service Values Format [DFLT: MOTOROLA]
        //! MST result [calc in Init]
        TUint32      u32IdSndBcst;               //!< [NUM] CAN-ID from ECU Broadcast send
        TUint32      u32IdRcvBcst;               //!< [NUM] CAN-ID from ECU Broadcast receive
        TUint32      u32IdSndMst;                //!< [NUM] CAN-ID from ECU send to service tool
        TUint32      u32IdRcvMst;                //!< [NUM] CAN-ID from ECU receive from service tool
        TUint32      u32IdSndClu;                //!< [NUM] CAN-ID from ECU send to cluster
        TUint32      u32IdRcvClu;                //!< [NUM] CAN-ID from ECU receive from cluster
        TUint32      u32IdSndHmg;                //!< [NUM] CAN-ID from ECU send to HMG
        TUint32      u32IdRcvHmg;                //!< [NUM] CAN-ID from ECU receive from HMG
        TUint32      u32IdSndRem;                //!< [NUM] CAN-ID from ECU send to remote maintenance
        TUint32      u32IdRcvRem;                //!< [NUM] CAN-ID from ECU receive from remote maintenance
        // Error
        TErrCfgFea   atErrFea[1];                //!< [CLA] Error configuration
    }TPtcMst;


    //! last command data
    typedef struct
    {
        TUint32     u32TimeStamp;   //!< [ms] controller time when the request got processed
        EIdMode     eIdMode;        //!< mode indicates source of request, see EIdMode
        TUint8      u8Dlc;          //!< length of request can msg
        TBoolean    boUpdated;      //!< TRUE = data was updated/new cmd processed during last cycle, FALSE = no new request last cycle
        TUint8      au8CmdMsg[8];   //!< raw can message for command
        TBoolean    boPosResponse;  //!< TRUE: request was valid and cmd executed, FALSE: negative response for request
    } TPtcMstLastCmd;


    //--------------------------------------------------------------------------------------------------
    //! @brief      MST protocol - version information [function call for the eCorePtcRegistry(..)]
    //! @retval     *cptVer - Pointer to the versions information
    //--------------------------------------------------------------------------------------------------
    extern const TVerChapCom *cptPtcMstVersionsInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      MST protocol - version check [function call for the eCorePtcRegistry(..)]
    //! @retval     TRUE   - is correct
    //! @retval     FALSE  - is incorrect
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boPtcMstVersionCheck( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      MST protocol - application call [function call for the eCorePtcRegistry(..)]
    //! @param[in]  eMainPhase  - show the MainPhase
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstAppCall( EMainPhase eMainPhase );

    //--------------------------------------------------------------------------------------------------
    //! @brief      MST protocol - shut down call [function call for the eCorePtcRegistry(..)]
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstShutDown( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      MST protocol - receive function [function call for the eCorePtcRegistry(..)]
    //! @param[in]  eHwBuf    - CAN hardware buffer
    //! @param[in]  ptRcvMsg  - receive message
    //! @retval     TRUE      - consume the message - message don't affect the system any more
    //! @retval     FALSE     - the message will be handle by the system
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boPtcMstRcvHwBuf( ECBusHwBuf eHwBuf, TRcvMsg* ptRcvMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief     MST protocol - send function [function call for the eCorePtcRegistry(..)]
    //! @param[in] eHwBuf    - CAN hardware buffer
    //! @param[in] ptSndMsg  - send message
    //! @retval    TRUE      - send ptSndMsg out
    //! @retval    FALSE     - dont't send ptSndMsg out
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boPtcMstSndHwBuf( ECBusHwBuf eHwBuf, TSndMsg* ptSndMsg );

    // Service function ================================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief       Control the answering reaction, The function must be call in the vCoreFixInit-FctCallBack()
    //!              Defer request handling by u8ReqWaitTaskCycle cycles after receiving can message.
    //! @param[in]   u8ReqWaitTaskCycle - [DFLT is 0: a request get an answering in the same task cycle]
    //! @retval      R_OKAY   - ok
    //! @retval      R_PHASE  - function must be called in the vCoreFixInit-FctCallBack() -> vAppFixInit
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqReaction( TUint8 u8ReqWaitTaskCycle );

    //--------------------------------------------------------------------------------------------------
    //! @brief     MST protocol - set the access level
    //!            Function must be called before phase MAIN_CORE_COM_READY, e.g. vAppFixInit
    //! @param[in] eAccLevel    - Access Level
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstSetAccessLevel( EAccLevel eAccLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      MST protocol - get current access level
    //! @return     currently active access level
    //--------------------------------------------------------------------------------------------------
    extern EAccLevel ePtcMstGetAccessLevel( TVoid );


    //--------------------------------------------------------------------------------------------------
    //! @brief           Change the vPrintXxx standard stream output
    //! @param[EIdMode]  Id-Mode [Default is ID_MODE_MST]
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstPrintChaIdLink( EIdMode eIdLink );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the MST Error Status / Error over write control
    //! @param[in]  ptErrCntl (NULL - no error control)
    //--------------------------------------------------------------------------------------------------
    extern const TBehErrSta *cptPtcMstErrSta( TBehErrCntl *ptErrCntl );



    //--------------------------------------------------------------------------------------------------
    //! @brief      Locking the print Interface (Locked everything, as well vPrintAlways(...) )
    //!             The release command can be sent over the communication channel (MST), it is the 'HST_SET_DEBUG_MODE' command
    //! @param[in]  eMode - MST Mode
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstSelectDebugMode( EMstMode eMode );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Last Requested Engine time
    //! @return     EngineTime [sec]
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32PtcMstLoginReqEngineTime( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get MST Command
    //!             MST_SET_APPL_CMD [Byte0]:0x0C, [Byte1]: return command
    //! @return     Command from the MST-Tool to the Application (hold the last command)
    //!             Default value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8PtcMstGetCommand( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set MST Command - possibility to overwrite the hold last command
    //! @param[in]  u8Command (Read with the u8PtcMstGetCommand() function)
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstSetCommand( TUint8 u8Command );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Locking the full COM-PTC, except the MST_LOGIN_CONTROL Command
    //!             It is possible the release the 'COM-PTC' via the MST command MST_LOGIN_CONTROL
    //!             This function has to be called before MAIN_CORE_COM_READY, usually in vAppFixInit
    //! @param[in]  pfu32PtcMstLoginAlgmDfltm
    //! @param[in]  boLockVehicleCode - if that is TRUE: MST_GET_LOGIN_VEHICLE_CODE command are locked. (To make it safe)
    //! @param[in]  u8LockInTries     - the tries for the MST_SET_LOGIN_KEY command (0 is also one try, >5 is always 5)
    //!
    //!     Approachable MST command without an correct login code:
    //!         MST_SET_MST_TO_HCP_CMD::MST_GET_PTC_VER
    //!         MST_SET_HCP_TO_MST_CMD::HCP_ECU_START
    //!         MST_LOGIN_CONTROL::MST_SET_LOGIN_KEY (see parameter u8LockInTries)
    //!         MST_LOGIN_CONTROL::MST_GET_LOGIN_VEHICLE_CODE
    //!         MST_LOGIN_CONTROL::MST_GET_LOGIN_ENGINE_TIME
    //!         MST_LOGIN_CONTROL::MST_GET_LOGIN_VEHICLE_SERIAL_NO
    //!         MST_LOGIN_CONTROL::MST_GET_LOGIN_ECU_SERIAL_NO
    //!     all other commands give R_LOGIN error code back
    //!
    //!               Default algorithms:
    //!                 TUint32 u32PtcMstLoginAlgmDflt( TChar achVehicleCode[6], TUint32 u32EngineTime, TUint32 u32VehSerNo )
    //!                 {
    //!                     TUint8  u8I;
    //!                     TUint32 u32Key = u32EngineTime ^ u32VehSerNo;
    //!
    //!                     for( u8I=0; u8I<6; u8I++ )
    //!                     {
    //!                         if( achVehicleCode[u8I] == 0 ){ break; }
    //!                         else
    //!                         {
    //!                             if( achVehicleCode[u8I] < ' ' || achVehicleCode[u8I] > '~' ) // Space[32] .... ~[126]
    //!                             {
    //!                                 u32Key = u32Key + ( 50 << u8I );
    //!                             }
    //!                             else
    //!                             {
    //!                                 u32Key = u32Key + ( (achVehicleCode[u8I] - ' ') << u8I);
    //!                             }
    //!                         }
    //!                     }
    //!                     return u32Key;
    //!                 }
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstLockUntilLogin( TUint32 (*pfu32PtcMstLoginAlgmDfltm)( TChar achVehicleCode[6], TUint32 u32EngineTime, TUint32 u32VehSerNo ), TUint8 u8LockInTries, TBoolean boLockVehicleCode );

    #ifdef COMPILER_SWITCH_SEC_APP

    //--------------------------------------------------------------------------------------------------
    //! @brief      Like vPtcMstLockUntilLogin, but for the 'Second Application'
    //! @param[in]  pfu32PtcMstLoginAlgmDfltm
    //! @param[in]  boLockVehicleCode - currently unused
    //! @param[in]  u8LockInTries     - currently unused
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstExtLockUntilLogin( TUint32 (*pfu32PtcMstLoginAlgmDfltm)( TChar achVehicleCode[6], TUint32 u32EngineTime, TUint32 u32VehSerNo ), TUint8 u8LockInTries, TBoolean boLockVehicleCode );

    #endif


    //--------------------------------------------------------------------------------------------------
    //! @brief       Set mapping for ACC_ECU_CUS/ACC_ECU_DEV to single access levels used for MST DB access
    //!              Note: ACC_ECU_ENG has always RW access in PtcMst
    //! @param[in]   eAccForCus     - single access level to be used for ACC_ECU_CUS
    //! @retval      eAccForDev     - single access level to be used for ACC_ECU_DEV
    //! @retval      R_OKAY         - okay
    //! @retval      R_PARAMETER    - mapping to ECU access level not allowed
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstMapEcuToSingleLevel( EAccLevel eAccForCus, EAccLevel eAccForDev);


    //--------------------------------------------------------------------------------------------------
    //! @brief       Set ECU Source Address for MST (for all clients)
    //!              Note: should be set before configured MST start phase
    //!                    otherwise messages with original id might have been sent already
    //!                    Can only be set after MAIN_CORE_COM_READY!
    //! @param[in]   u8MstSa     - ecu source address
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstSetMstSa( TUint8 u8MstSa );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Set phase after which MST protocol starts sending
    //!              Should be done before reaching MAIN_CORE_COM_READY(in vAppFixInit or eAppPreStart)
    //! @param[in]   ePhase     - match core phase, only ePhase < MAIN_APP_RUN will be set
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstInitAfterAppPhase(EMainPhase ePhase);

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return pointer to last handled command information
    //! return      pointer to last handled mst command, see type TPtcMstLastCmd for content
    //--------------------------------------------------------------------------------------------------
    extern const TPtcMstLastCmd* cptPtcMstGetLastCmd( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Set 'remote maintenance' receive client Source Address
    //! @details     u8RemRcvSa is the source address of a remote ECU or client for ID_MODE_REM
    //!              u8RemRcvSa is used as Target Address in Message when sending request using client functionality with ID_MODE_REM
    //! @warning     This currently updates CAN IDs for both ID_MODE_REM and ID_MODE_REM_2APP(if 2App exists)
    //! @param[in]   u8RemRcvSa     - 'remote maintenance' receive client Source Address
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstChangeRemRcvSa( TUint8 u8RemRcvSa );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Set 'remote maintenance' send client Source Address
    //! @details     u8RemSndSa is the Source Address of this ECU for ID_MODE_REM
    //!              u8RemSndSa is used as source address when sending request using client functionality with ID_MODE_REM
    //! @warning     This currently updates CAN IDs for both ID_MODE_REM and ID_MODE_REM_2APP(if 2App exists)
    //! @param[in]   u8RemSndSa     - 'remote maintenance' receive client Target Address
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstChangeRemSndSa( TUint8 u8RemSndSa );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Stop the MST Request waiting for the handshake answer - stop the timeout wait time.\n
    //!              Process is ready for a new call. E.g. ePtcMstReqWriteListVar(), ePtcMstReqReadListVar(),
    //!              ePtcMstReqReadListVar(), ePtcMstReqStoreList(), ePtcMstReqLoadList(), ePtcMstReqLoadListDfltSet(),
    //!              ePtcMstReqAppCmd()
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPtcMstReqComAnswerStop( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Allow incoming requests from link/CAN Ids previously used for sending MST requests
    //! @retval      R_OKAY - ok
    //! @retval      R_BUSY - client request ongoing, must stop/finish client handling first
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqComUnlockRequest( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Write value in a data base list(MST_LIST_ELE_WRITE)
    //! @note        Call each cycle until return value != R_BUSY
    //! @param[in]   eIdLink        - link(->target address) used for request
    //! @param[in]   u8ListIdx      - list index(on target)
    //! @param[in]   u8VarIdx       - variable index
    //! @param[in]   u8ArrIdx       - array index
    //! @param[in]   pu8Byte        - input buffer containing value to be written\n
    //!                               Byte order will be adapted to locally set eDbValueDB format.
    //! @param[in]   u8ByteCnt      - len of data to be written(1/2/4 bytes)
    //! @param[in]   u16TimeOut     - [ms] timeout for request
    //! @retval      R_OKAY         - request successfully finished
    //! @retval      R_BUSY         - request ongoing
    //! @retval      R_TIMEOUT      - no response within timeout
    //! @retval      R_PARAMETER    - data size(u8ByteCnt) not supported
    //! @retval      R_NULL_POINTER - pu8Byte is NULL
    //! @retval      R_SUPPORT      - eIdLink: mode not supported(e.g. BCST, UNKNOWN, undefined)
    //! @retval      others         - see MST_LIST_ELE_WRITE negative response codes
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqWriteListVar( EIdMode eIdLink, TUint8 u8ListIdx, TUint8 u8VarIdx, TUint8 u8ArrIdx, TUint8 *pu8Byte, TUint8 u8ByteCnt, TUint16 u16TimeOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Read value from data base list(MST_LIST_ELE_READ)
    //! @note        Call each cycle until return value != R_BUSY
    //! @param[in]   eIdLink        - link(->target address) used for request
    //! @param[in]   u8ListIdx      - list index(on target)
    //! @param[in]   u8VarIdx       - variable index
    //! @param[in]   u8ArrIdx       - array index
    //! @param[in]   u8ByteLen      - len of data to be read, 1/2/4
    //! @param[out]  pu8Byte        - output buffer for data, size must match size of DB value. NULL-pointer save, value will not be not copied \n
    //! @param[in]   u16TimeOut     - [ms] timeout for request
    //! @retval      R_OKAY         - request successfully finished
    //! @retval      R_BUSY         - request ongoing
    //! @retval      R_TIMEOUT      - no response within timeout
    //! @retval      R_PARAMETER    - u8ByteLen is not in range
    //! @retval      R_SUPPORT      - eIdLink: mode not supported(e.g. BCST, UNKNOWN, undefined)
    //! @retval      others         - see MST_LIST_ELE_READ negative response codes
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqReadListVar( EIdMode eIdLink, TUint8 u8ListIdx, TUint8 u8VarIdx, TUint8 u8ArrIdx, TUint8 u8ByteLen, TUint8 *pu8Byte, TUint16 u16TimeOut );


    //--------------------------------------------------------------------------------------------------
    //! @brief       Store data base list(MST_LIST_STORE)
    //! @note        Call each cycle until return value != R_BUSY
    //! @param[in]   eIdLink        - link(->target address) used for request
    //! @param[in]   u8ListIdx      - list index(on target)
    //! @param[in]   u16TimeOut     - [ms] timeout for request
    //! @retval      R_OKAY         - request successfully finished
    //! @retval      R_BUSY         - request ongoing
    //! @retval      R_TIMEOUT      - no response within timeout
    //! @retval      R_SUPPORT      - eIdLink: mode not supported(e.g. BCST, UNKNOWN, undefined)
    //! @retval      others         - see MST_LIST_STORE negative response codes
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqStoreList( EIdMode eIdLink, TUint8 u8ListIdx,  TUint16 u16TimeOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Load data base list(MST_LIST_LOAD)
    //! @note        Call each cycle until return value != R_BUSY
    //! @param[in]   eIdLink        - link(->target address) used for request
    //! @param[in]   u8ListIdx      - list index(on target)
    //! @param[in]   u16TimeOut     - [ms] timeout for request
    //! @retval      R_OKAY         - request successfully finished
    //! @retval      R_BUSY         - request ongoing
    //! @retval      R_TIMEOUT      - no response within timeout
    //! @retval      R_SUPPORT      - eIdLink: mode not supported(e.g. BCST, UNKNOWN, undefined)
    //! @retval      others         - see MST_LIST_LOAD negative response codes
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqLoadList( EIdMode eIdLink, TUint8 u8ListIdx, TUint16 u16TimeOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Load default set values(MST_LIST_DEFAULT)
    //! @note        Call each cycle until return value != R_BUSY
    //! @param[in]   eIdLink        - link(->target address) used for request
    //! @param[in]   u8ListIdx      - list index(on target)
    //! @param[in]   u8DfltSet      - default set index
    //! @param[in]   u16TimeOut     - [ms] timeout for request
    //! @retval      R_OKAY         - request successfully finished
    //! @retval      R_BUSY         - request ongoing
    //! @retval      R_TIMEOUT      - no response within timeout
    //! @retval      R_SUPPORT      - eIdLink: mode not supported(e.g. BCST, UNKNOWN, undefined)
    //! @retval      others         - see MST_LIST_DEFAULT negative response codes
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqLoadListDfltSet( EIdMode eIdLink, TUint8 u8ListIdx, TUint8 u8DfltSet, TUint16 u16TimeOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Send User Code(MST_SET_APPL_CMD)
    //! @note        Call each cycle until return value != R_BUSY
    //! @param[in]   eIdLink        - link(->target address) used for request
    //! @param[in]   u8Cmd          - command
    //! @param[in]   u16TimeOut     - [ms] timeout for request
    //! @retval      R_OKAY         - request successfully finished
    //! @retval      R_BUSY         - request ongoing
    //! @retval      R_TIMEOUT      - no response within timeout
    //! @retval      R_SUPPORT      - eIdLink: mode not supported(e.g. BCST, UNKNOWN, undefined)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstReqAppCmd( EIdMode eIdLink, TUint8 u8Cmd, TUint16 u16TimeOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Encrypt MST-CAN-Comunnication
    //! @retval      R_OKAY         - encryption successfully activated
    //! @retval      R_PHASE        - encryption activation called in wrong phase
    //--------------------------------------------------------------------------------------------------
    extern ERetVal ePtcMstActivateEncryption( TVoid );

#endif
