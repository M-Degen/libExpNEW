//**************************************************************************************************
/*!
@file  		    ItfBloCBus.h
@brief	        Can bus interface
@date           21.07.2013
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBLOCBUS__
  #define __ITFBLOCBUS__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreEcu.h>
    #include <ItfCore.h>
    #include <ItfBasEleErr.h>
    #include <ItfCoreBoard.h>

    #ifdef COMPILER_SWITCH_CANBUS


// DEFINES & ENUMS  ================================================================================

// GENERAL CAN MESSAGE FRAME ***********************************************************************

    #define  CBUS_BUF_HW_RCV_MAX 8      //!< Can buffer receive
    #define  CBUS_BUF_HW_SND_MAX 6      //!< Can buffer send

    #define  CBUSX_HWBUF_MAX (((TUint8)CAN_BUS_MAX)*(CBUS_BUF_HW_RCV_MAX+CBUS_BUF_HW_SND_MAX))  //!< Maximal Can Hardware Buffer Size

    //! CAN BUS Errors
    enum
    {
        DM_CBUS_OFF,                    //!< 0 -    01 - Can bus off
        DM_CBUS_WARN,                   //!< 1 -    02 - Can warning
        DM_CBUS_HOVERF_RCV0,            //!< 2 -    04 - Can receive hardware buffer 0 overflow
        DM_CBUS_HOVERF_RCV1,            //!< 3 -    08 - Can receive hardware buffer 1 overflow
        DM_CBUS_HOVERF_RCV2,            //!< 4 -    16 - Can receive hardware buffer 2 overflow
        DM_CBUS_HOVERF_RCV3,            //!< 5 -    32 - Can receive hardware buffer 3 overflow
        DM_CBUS_HOVERF_RCV4,            //!< 6 -    64 - Can receive hardware buffer 4 overflow
        DM_CBUS_HOVERF_RCV5,            //!< 7 -   128 - Can receive hardware buffer 5 overflow
        DM_CBUS_HOVERF_RCV6,            //!< 8 -   256 - Can receive hardware buffer 6 overflow
        DM_CBUS_HOVERF_RCV7,            //!< 9 -   512 - Can receive hardware buffer 7 overflow
        DM_CBUS_HOVERF_SND0,            //!<10 -  1024 - Can send hardware buffer 0 overflow
        DM_CBUS_HOVERF_SND1,            //!<11 -  2048 - Can send hardware buffer 1 overflow
        DM_CBUS_HOVERF_SND2,            //!<12 -  4096 - Can send hardware buffer 2 overflow
        DM_CBUS_HOVERF_SND3,            //!<13 -  8192 - Can send hardware buffer 3 overflow
        DM_CBUS_HOVERF_SND4,            //!<14 - 16384 - Can send hardware buffer 4 overflow
        DM_CBUS_HOVERF_SND5,            //!<15 - 32768 - Can send hardware buffer 5 overflow
        DM_CBUS_CNT_MAX
    };

// CONFIGURATION STRUCTURE =========================================================================

    //! CONFIGURATION OF CBUF RECEIVE
    typedef struct
    {
        TUint8    u8HwRcvSize;          //!< [NUM] - Can hardware Msg buffer [MAX 255
        TUint8    u8CallCountOfCycle;   //!< [NUM] - Cyclic can buffer call [count of cycles]
        TBoolean  boExtId;              //!< [DEF] - Can-Rcv extended identifier (11/29 Bit)
        TUint32   u32Id;                //!< [NUM] - Can-Rcv id (only with acceptance mask)
        TUint32   u32AccMask;           //!< [NUM] - Can-Rcv acceptance mask [-]
    }TCBufHwRcv;

    //! CONFIGURATION OF CBUF SEND
    typedef struct
    {
        TUint8    u8HwSndSize;          //!< [NUM] - Can hardware Msg buffer [MAX 255]
        TUint8    u8CallCountOfCycle;   //!< [NUM] - Cyclic can buffer call  [count of cycles]
    }TCBufHwSnd;

    //! CONFIGURATION OF CBUS
    typedef struct
    {
        //Common
        TChar       achName[BLO_NAME_STR_LEN];         //!< [STR] - Block name
        EBloStatus  eBloProc;                          //!< [ENU] - Block process
        // Fixed settings
        ECanBus     eCanBus;                           //!< [ENU] - CAN bus positions index
        EBitRate    eBitrate;                          //!< [ENU] - CAN bit rate [kBaud]
        #ifdef COMPILER_SWITCH_TAR_PC
        TChar       achPeakNetName[PEAK_NAME_STR_LEN]; //!< [STR] - Peak register net name
        EPeakDevice ePeakDevice;                       //!< [ENU] - Peak CAN device
        EPeakChan   ePeakChannel;                      //!< [ENU] - Peak device CAN channel
        #endif
        TCBufHwRcv  atBufHwRcv[CBUS_BUF_HW_RCV_MAX];   //!< [STU] - CAN hardware buffer receive
        TCBufHwSnd  atBufHwSnd[CBUS_BUF_HW_SND_MAX];   //!< [STU] - CAN hardware buffer send
        //Error
        TUint8      u8ErrCnt;                          //!< [NUM] - Cnt of valid error case
        TErrCfgFea  atErrFea[DM_CBUS_CNT_MAX];         //!< [CLA] - Error number configurations
    }TCBusCfg;

    //! CBUS address
    typedef struct
    {
        const TCBusCfg* cptCfg;                       //!< [STU] - Configuration struct
              TVoid*    pvObj;                        //!< [STU] - Pointer to the private object
              TUint16   u16Stamp;                     //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TCBusAdr;

    //! INPUT SUB-BLOCK
    typedef struct
    {
        TBehErrCntl  tBehErrCntl;                     //!< [STU] - Error control behavior
    } TCBusInp;

    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        TBehErrSta tBehErrSta;                        //!< [STU] - Error behavior status
    } TCBusOut;

    //! CBus block
    typedef struct
    {
        TCBusInp tInp;                                //!< [STU] - Block input vector
        TCBusOut tOut;                                //!< [STU] - Block Output vector
        TCBusAdr tXAdr;                               //!< [STU] - Private address information
    }TBloCBus;

     #ifdef COMPILER_SWITCH_CANBUS

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for CBUS block interface (*** needed if the block was not created by the PDT ***)
    //! @param[in]  ptBlo          - Pointer to the block
    //! @param[in]  cptCfg         - Pointer to the config struct
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_MEMORY       - Out of memory
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBusCreate( TBloCBus *ptBlo, const TCBusCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for CBUS block interface (*** needed if the block was not created by the PDT ***)
    //! @pre            Call in MAIN_APP_PRE_START/eAppPreStart
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @retval         R_OKAY         - functions execute without error
    //! @retval         R_NULL_POINTER - Null Pointer
    //! @retval         R_ADDRESS      - wrong block address
    //! @retval         R_BUSY         - channel has been initialized before
    //! @retval         R_PARAMETER    - invalid parameter has been passed
    //! @retval         R_RANGE        - invalid channel ID has been passed
    //! @retval         R_UNKNOWN      - unknown error (normally not possible)
    //! @retval         R_SUPPORT      - try to init again
    //! @retval         R_MEMORY       - out of memory
    //! @retval         R_INCONSISTENT - non-consecutive buffer configuration
    //! @retval         R_CONFIG       - this function should call from the PDT
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBusInit( TBloCBus *ptBlo );

    #ifdef COMPILER_SWITCH_TAR_HW
    //--------------------------------------------------------------------------------------------------
    //! @brief      ReInitialization function for CBUS-Block
    //! @param[in]  ptBlo          - [PNT] Pointer to Block
    //! @param[in]  eBitrate       - [ENU] CAN bit rate
    //! @retval     R_OKAY         - functions execute without error
    //! @retval     R_INCONSISTENT - Can bus must call before with eBloCBusInit(..) [auto. call via PDT]
    //! @retval     R_NULL_POINTER - Null Pointer
    //! @retval     R_BUSY         - channel has been initialized before (normally not possible)
    //! @retval     R_PARAMETER    - invalid parameter has been passed (normally not possible)
    //! @retval     R_RANGE        - invalid channel ID has been passed (normally not possible)
    //! @retval     R_CONFIG       - can't create the HW-Buffer (normally not possible)
    //! @retval     R_UNKNOWN      - unknown error (normally not possible)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBusReInit( TBloCBus *ptBlo, EBitRate eBitrate );
    #endif

    //--------------------------------------------------------------------------------------------------
    //! @brief          Send Messages out via the CBus block out
    //! @param[in,out]  ptBlo               - [PNT] Pointer to the block
    //! @param[in]      eSndBuf             - [ENU] use that hardware send buffer
    //! @param[out]     ptSndMsg            - [PNT] Pointer to the send that message out
    //! @retval         R_OKAY              - functions execute without error
    //! @retval         R_OVERFLOW          - CAN-HW-FIFO is full - no data has been transmitted        -> Set the DM_CBUSx_HOVERF_SNDx fault
    //! @retval         R_NOACT             - No Action - Hardware send count per task cycle is reached -> Set the DM_CBUSx_HOVERF_SNDx fault
    //! @retval         R_UNKNOWN           - Unknown internal device error
    //! @retval         R_NULL_POINTER      - NULL pointer
    //! @retval         R_ADDRESS           - wrong block address
    //! @retval         R_CONFIG            - CBuf block is not a send block  (is a receiver CBuf block)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBusSnd( TBloCBus *ptBlo, ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error status on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCBusGetErrStaBit( TBloCBus* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum error status information
    //! @param[in]  ptBlo   - [PNT] Pointer to the block
    //! @retval     OKAY    - [BIT] Error state bit coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCBusGetErrStaAll( TBloCBus* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCBusGetErrEveBit( TBloCBus* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT] Pointer to the block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error state bit coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCBusGetErrEveAll( TBloCBus* ptBlo, TBoolean boDetect );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get CAN bus buffer overflow error status
    //! @param[in]      ptBlo   - [PNT]     Pointer to the block
    //! @param[in]      eCBuf   - [Index]   CAN Bus buffer enum
    //! @retval         TRUE    - [BO]      Error is active
    //! @retval         FALSE   - [BO]      Error is inactive / Wrong ptBlo-Addr
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCBusGetCBufErrSta( TBloCBus* ptBlo, ECBusHwBuf eCBuf );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set max messages sent/handled per cycle for given tx err counter thresholds, call in eAppStartUp
    //! @details    Function can be used to reduce the number of CAN/CSR messages handled per cycle when CAN transmit errors occur.
    //!             mappings/intervals for error counter to possible can tx messages per cycle on given bus:
    //!             - [0,        u8TxErr1] -> configured hw tx buffer counter
    //!             - [u8TxErr1, u8TxErr2] -> u8CntPerCycle1
    //!             - [u8TxErr2, 255]      -> u8CntPerCycle2
    //! @param[inout]   cptBlo          - CBUS Block Pointer
    //! @param[in]      u8TxErr1        - first tx error counter threshold
    //! @param[in]      u8CntPerCycle1  - max can messages sent/handled per cycle, 0 = mapping not used
    //! @param[in]      u8TxErr2        - second tx error counter threshold
    //! @param[in]      u8CntPerCycle2  - max can messages sent/handled per cycle, 0 = mapping not used
    //! @retval         R_OKAY          - ok, values set
    //! @retval         R_NULL_POINTER  - Null Pointer(ptBlo)
    //! @retval         R_ADDRESS       - wrong block address(ptBlo)
    //! @retval         R_CONFIG        - can bus not initialized
    //! @retval         R_INCONSISTENT  - u8TxErr1 > u8TxErr2
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBusSetTxErrCntCalls( TBloCBus* ptBlo, TUint8 u8TxErr1, TUint8 u8CntPerCycle1, TUint8 u8TxErr2, TUint8  u8CntPerCycle2 );

#endif
#endif
#endif
