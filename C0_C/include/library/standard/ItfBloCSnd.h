//**************************************************************************************************
/*!
@file  		ItfBloCSnd.h
@brief	        Can Send Interface
@date           21.07.2013
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBLOCSND__
  #define __ITFBLOCSND__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreEcu.h>
    #include <ItfCore.h>
    #include <ItfBasEleErr.h>
    #include <ItfCoreBoard.h>

// DEFINES & ENUMS  ================================================================================

    //! CAN software BUFFER errors
    enum
    {
        DM_CSND_BOVERF,             //!< 0 -01- Message overflow in message box buffer
        DM_CSND_CNT_MAX = 1,
        DM_CSND_BUS_OFF,            //!< 1 -02- Can bus off
        DM_CSND_CBUS_WARN,          //!< 2 -04- Can bus warning
        DM_CSND_HOVERF,             //!< 3 -08- Can bus hardware buffer overflow
        DM_CSND_SOVERF,             //!< 4 -16- Software buffer overflow
        DM_CSND_ALL_MAX
    };

    //! SndType
    typedef enum
    {
        SNDTYP_CYCLIC,              //!< 0 - Send type: cyclic
        SNDTYP_EVENT,               //!< 1 - Send type: event based
        SNDTYP_CYCEVE,              //!< 2 - Send type: cyclic and event based
        SNDTYP_MSGBUF               //!< 3 - Send type: message buffer
    }ESndType;

    //! SndStart
    typedef enum
    {
        SNDSTART_ACTIVE,            //!< 0 - Send start: active
        SNDSTART_NA,                //!< 1 - Send start: nothing
        SNDSTART_ACTIVE_NO_FIRST    //!< 2 - Send start: active, but don't send first message without change(event)
    }ESndStart;

// CONFIGURATION STRUCTURE =========================================================================

    //! CONFIGURATION OF CBUS
    typedef struct
    {
        //Common
        TChar       achName[BLO_NAME_STR_LEN]; //!< [STR] - Block name
        EBloStatus  eBloProc;                  //!< [ENU] - Block process
        // Fixed settings
        TUint8      u8CBufPosIdx;              //!< [ENU] - CAN send buffer position connection link
        ESndType    eType;                     //!< [DEF] - Send type
        ESndStart   eStart;                    //!< [DEF] - Start transmission
        TUint8      u8MsgBufSize;              //!< [NUM] - Message buffer size
        TBoolean    boBufferCheck;             //!< [DEF] - Buffer overflow check
        TUint16     u16CycTim;                 //!< [ms]  - Cycle time
        TUint16     u16MinCycTim;              //!< [ms]  - Minimum cycle time
        TUint16     u16OffTim;                 //!< [ms]  - 1st offset time
        TBoolean    boExtId;                   //!< [DEF] - Can extended identifier (11/29 Bit)
        TUint32     u32Id;                     //!< [NUM] - Can id
        TUint16     u16CanSigRecLink;          //!< [DEF] - Can signal record position link
        //Fixed safety feature settings
        TBoolean    boSafeInvMsg;              //!< [DEF] - Receive inverse message
        TUint16     u16SafeInvDelay;           //!< [ms]  - Delay time inverse message
        TBoolean    boSafeCnt;                 //!< [DEF] - Check safety counter
        //Error
        TUint8      u8ErrCnt;                  //!< [NUM] - Cnt of valid error case
        TErrCfgFea  atErrFea[DM_CSND_CNT_MAX]; //!< [CLA] - Error number configurations
    }TCSndCfg;

    //! CSND ADRESSE
    typedef struct
    {
        const TCSndCfg* cptCfg;                //!< [STU] - Configuration struct
              TVoid*    pvObj;                 //!< [STU] - Pointer to the private object
              TUint16   u16Stamp;              //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TCSndAdr;


    //! INPUT SUB-BLOCK
    typedef struct
    {
        TBehErrCntl  tBehErrCntl;              //!< [STU] - Error control behavior
        TUint32      u32CanId;                 //!< [DEF] - Can message Id
        TBoolean     boExtId;                  //!< [DEF] - Can extend Id
        ESndStart    eStart;                   //!< [DEF] - Start Send
        ESndType     eType;                    //!< [DEF] - Send on data change
        TBoolean     boSndNow;                 //!< [DEF] - Send the message now - the flag will be reset automatic
    }TCSndInp;

    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        TBehErrSta tBehErrSta;                 //!< [STU] - Error behavior status
        TBoolean   boSndDat;                   //!< [DEF] - Data has send (event - only one task cycle active)
        TBoolean   boSndDatChg;                //!< [DEF] - Data has change
        TUint32    u32SndTim;                  //!< [DEF] - Send time
        TUint32    u32SndPer;                  //!< [ms]  - Send period between the last two send messages
        TUint32    u32SndCnt;                  //!< [NUM] - Count of send CAN messages (from ECU start, overflow not protected)
    }TCSndOut;

    //! CBUS BLOCK
    typedef struct
    {
        TCSndInp tInp;                         //!< [STU] - Block input vector
        TCSndOut tOut;                         //!< [STU] - Block output vector
        TCSndAdr tXAdr;                        //!< [STU] - Private address information
    }TBloCSnd;

    #ifdef COMPILER_SWITCH_CANBUS


    //--------------------------------------------------------------------------------------------------
    //! @brief      Prototype for function used for callback before transmitting CSnd message
    //! @param[inout]  ptMsg - CAN Snd message that can be read/manipulated before sending
    //--------------------------------------------------------------------------------------------------
    typedef TVoid (*TFpvCSndMsgModifyCb) ( TSndMsg *ptMsg );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Set user function to be called before CSnd messages are transmitted
    //! @param[in]  pfvLoadedDefaultsCb - callback function (dflt: NULL)
    //--------------------------------------------------------------------------------------------------
    extern TVoid vBloCSndSetMsgModifyCb( TFpvCSndMsgModifyCb pfvMsgModifyCb );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for CSND block interface (*** needed if the block was not created by the PDT ***)
    //! @param[in]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]  cptCfg         - [PNT] Pointer to config
    //! @retval     R_OKAY         - Function executed without error
    //! @retval     R_NULL_POINTER - NULL Pointer
    //! @retval     R_MEMORY       - Out of memory
    //! @retval     R_OVERFLOW     - Too many messages per send FIFO
    //! @retval     R_CONFIG       - CAN not available or invalid message configuration
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndCreate( TBloCSnd *ptBlo, const TCSndCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for CSND block interface (*** needed if the block was not created by the PDT ***)
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndInit( TBloCSnd *ptBlo );

        //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error status on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCSndGetErrStaBit( TBloCSnd* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum error status information
    //! @param[in]  ptBlo   - [PNT] Pointer to the block
    //! @retval     OKAY    - [BIT] Error state bit coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCSndGetErrStaAll( TBloCSnd* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCSndGetErrEveBit( TBloCSnd* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT] Pointer to the block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error state bit coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCSndGetErrEveAll( TBloCSnd* ptBlo, TBoolean boDetect );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the send action
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      eStart         - Select send action
    //! @param[in]      eType          - Select send type
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangAction( TBloCSnd *ptBlo, ESndStart eStart, ESndType eType );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Send message now
    //! @note           Message is sent as soon as the minimum cycle time has passed after last message
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @retval         R_OKAY         - Function executed without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndNow( TBloCSnd *ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Error control function for the CSnd-Block - that don't must call the  eBloCSndNow(..) function
    //! @param[in,out]  ptBlo          - [PNT] Pointer to Block
    //! @retval         R_NULL_POINTER - Null Pointer
    //! @retval         R_ADDRESS      - wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndErrCntl( TBloCSnd *ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u32Id          - [NUM] Can id
    //! @param[in]      boExtId        - [DEF] Can extended identifier (11/29 Bit)
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanId( TBloCSnd *ptBlo, TUint32 u32Id, TBoolean boExtId );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Pri          - [NUM] Priority       - Bit 28...26 (start with 0) Max-Val: 0x3     DLC:3
    //! @param[in]      u32Pgn         - [NUM] PGN            - Bit 23...8  (start with 0) MAX-Val: 0x3FFFF DLC:18
    //! @param[in]      u8Sa           - [NUM] Source address - Bit 7..0    (start with 0) MAX-Val: 0xFF    DLC:8
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanIdJ1939( TBloCSnd *ptBlo, TUint8 u8Pri, TUint32 u32Pgn, TUint8 u8Sa );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol - only priority
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Pri          - [NUM] Priority - Bit 28...26 (start with 0) Max-Val: 0x3     DLC:3
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanIdJ1939Pri( TBloCSnd *ptBlo, TUint8 u8Pri );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol - only PGN
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u32Pgn         - [NUM] PGN - Bit 23...8  (start with 0) MAX-Val: 0x3FFFF DLC:18
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanIdJ1939Pgn( TBloCSnd *ptBlo, TUint32 u32Pgn );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol - only source address
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Sa           - [NUM] Source address - Bit 7..0    (start with 0) MAX-Val: 0xFF    DLC:8
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanIdJ1939Sa( TBloCSnd *ptBlo,TUint8 u8Sa );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the inverse message (call only in the app StartUp phase)
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u32InvId       - [NUM] Can id for the invert message
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //! @retval         R_SUPPORT      - Don't support the 'invert message Id'
    //! @retval         R_CONFIG       - Message use an 'Invert Flag' no 'Invert Message Id' needed
    //! @retval         R_PHASE        - Function isn't call in the app "Start Up" phase
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanIdInc( TBloCSnd *ptBlo, TUint32 u32InvId );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the timing for the CSnd block
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u16CycTim      - [ms] Cycle time
    //! @param[in]      u16MinCycTim   - [ms] Minimum cycle time
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //! @retval         R_CONFIG       - u16CycTim < u16MinCycTim is not possible
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndChangeCanTiming( TBloCSnd *ptBlo, TUint16 u16CycTim, TUint16 u16MinCycTim );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Reset ALL CSnd message timer for given can bus(to set start offset based on same ecu cycle)\n
    //!             Has only effect with eBloCSndConfigureScheduling(FALSE)/Default scheduling algorithm.\n
    //!             NextSendTime = CurrentTime+OffSet
    //! @param      eCanBus -  CAN bus on which CSnd message timers should be reset
    //! @retval     R_OKAY      - reset done
    //! @retval     R_PARAMETER - invalid can bus given
    //! @retval     R_CONFIG     - CAN not [yet] initialized
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloSndResetCbusTimer( ECanBus eCanBus );


    //--------------------------------------------------------------------------------------------------
    //! @brief      Global configuration for [cyclic] CSND scheduling algorithm
    //! @warning    Option for configurable algorithm might be removed in the future
    //! @pre        call in eAppStartUp(should be set before CSnd transmission starts)
    //! @param      boNewAlgo   - TRUE:  new algorithm(offsets between messages more reliable, slightly worse average performance, offsets based on ecu/match core start)
    //!                         - FALSE: old algorithm[Default](offsets are only re-adjusted at start and after CAN error, drift possible, initial offset time based on eAppStartup)
    //! @param      boReapplyOffset - TRUE:  After a CAN Bus error messages only start sending again after the start offset is expired(messages already in HW buffer might still be sent before)
    //!                             - FALSE: start offset ignored after CAN bus error[Default]
    //! @retval     R_OKAY      - ok
    //! @retval     R_CONFIG    - CAN not initialized [yet]
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndConfigureScheduling( TBoolean boNewAlgo, TBoolean boReapplyOffset );



    //--------------------------------------------------------------------------------------------------
    //! @brief          Get configured CAN ID for CSND block
    //! @param[in]      cptBlo          - [PNT] Pointer to the block
    //! @param[out]     cpu32CanId      - [PNT] Pointer to output for CAN ID
    //! @param[out]     cpboExtended    - [PNT] Pointer to output for CAN ID extended flag
    //! @retval         R_OKAY          - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCSndGetCanId( TBloCSnd* const cptBlo, TUint32* const cpu32CanId, TBoolean* const cpboExtended );

#endif
#endif
