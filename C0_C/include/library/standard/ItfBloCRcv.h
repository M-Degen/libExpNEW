//**************************************************************************************************
/*!
@file  		ItfBloCRcv.h
@brief	        Can send interface
@date           21.07.2013
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBLOCRCV__
  #define __ITFBLOCRCV__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreEcu.h>
    #include <ItfCore.h>
    #include <ItfBasEleErr.h>
    #include <ItfCoreBoard.h>

// DEFINES & ENUMS  ================================================================================

    //! CAN Software BUFFER Errors
    enum
    {
        DM_CRCV_TIMEOUT,                    //!< 0 -   1 - Message in timeout
        DM_CRCV_BOVERF,                     //!< 1 -   2 - Message overflow in message box buffer
        DM_CRCV_INVMSG,                     //!< 2 -   4 - Invert message
        DM_CRCV_CNTFAULT,                   //!< 3 -   8 - Counter fault
        DM_CRCV_TIMESLOT,                   //!< 4 -  16 - Time slot
        DM_CRCV_CNT_MAX = 5,
        DM_CRCV_BUS_OFF,                    //!< 5 -  32 - Can bus off
        DM_CRCV_CBUS_WARN,                  //!< 6 -  64 - Can bus warning
        DM_CRCV_CBUS_HOVERF,                //!< 7 - 128 - Can bus hardware buffer overflow
        DM_CRCV_CBUF_SOVERF,                //!< 8 - 256 - Software buffer overflow
        DM_CRCV_ALL_MAX
    };

    //! CAN ID Masken
    #define RCV_MASK_NA      0x1FFFFFFF     //!< use all CAN ID bits
    #define RCV_MASK_PGN      0x3FFFF00     //!< use only the J1939 - PGN part  28-Prio-26, [25-PGN-8], 7-SA-0
    #define RCV_MASK_PGN_SA   0x3FFFFFF     //!< use only the J1939 - PGN part  28-Prio-26, [25-PGN-8 , 7-SA-0]

// CONFIGURATION STRUCTURE =========================================================================

    //! CONFIGURATION OF CBUS
    typedef struct
    {
        //Common
        TChar       achName[BLO_NAME_STR_LEN]; //!< [STR] - Block name
        EBloStatus  eBloProc;                  //!< [ENU] - Block process
        // Fixed settings
        TUint8      u8CBufPosIdx;              //!< [ENU] - CAN send buffer position connection link
        TUint16     u16FirstCheckTim;          //!< [ms]  - First check time - for the timeout
        TUint16     u16CycTimOut;              //!< [ms]  - Cyclic message timeout
        TUint8      u8MsgBufSize;              //!< [NUM] - Message buffer size
        TBoolean    boBufferCheck;             //!< [DEF] - Buffer overflow check
        TBoolean    boExtId;                   //!< [DEF] - Can extended identifier (11/29 bit)
        TUint32     u32Id;                     //!< [NUM] - Can id
        TUint32     u32IdMask;                 //!< [NUM] - Can id mask
        TUint16     u16CanSigRecLink;          //!< [DEF] - Can signal record position link
        //Fixed safety feature settings
        TBoolean    boSafeInvMsg;              //!< [DEF] - Receive inverse message
        TUint16     u16SafeInvRcvSlot;         //!< [ms]  - Check maximum time slot inverse message
        TBoolean    boSafeCnt;                 //!< [DEF] - Check safety counter
        //Error
        TUint8      u8ErrCnt;                  //!< [NUM] - Cnt of valid error case
        TErrCfgFea  atErrFea[DM_CRCV_CNT_MAX]; //!< [CLA] - Error number configurations
    }TCRcvCfg;

    //! CRcv address
    typedef struct
    {
        const TCRcvCfg *cptCfg;                //!< [STU] - Configuration struct
              TVoid    *pvObj;                 //!< [STU] - Pointer to the private object
              TUint16   u16Stamp;              //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TCRcvAdr;

     //! INPUT SUB-BLOCK
    typedef struct
    {
        TBehErrCntl  tBehErrCntl;              //!< [STU] - Error control behavior
    } TCRcvInp;

    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        TBehErrSta tBehErrSta;                 //!< [STU] - Error behavior status
        TBoolean   boRcvDat;                   //!< [DEF] - Data has receive (event - only one task cycle active)
        TBoolean   boRcvDatChg;                //!< [DEF] - Data has change (FLOAT32: the comparison is bit true instead of using epsilon comparison)
        TUint32    u32RcvTim;                  //!< [ms]  - Last receive time
        TUint32    u32RcvPer;                  //!< [ms]  - Receive period between the last two receive messages
        TUint32    u32RcvCnt;                  //!< [NUM] - Count of received CAN messages (from ECU start, overflow not protected)

        TUint32    u32RcvCanId;                //!< [DEF] - [unmasked] received CAN Id of last message, U32_UNDEF if no message was received yet
                                               //! extended/non-extended ID based on configuration, for implicit query use @ref eBloRcvGetReceivedCanId
    } TCRcvOut;

    //! CRCv block
    typedef struct
    {
        TCRcvInp tInp;                         //!< [STU] - Block input vector
        TCRcvOut tOut;                         //!< [STU] - Block output vector
        TCRcvAdr tXAdr;                        //!< [STU] - Private address information
    }TBloCRcv;

    #ifdef COMPILER_SWITCH_CANBUS

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for CRCV block interface (*** needed if the block was not created by the PDT ***)
    //! @param[in]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]  cptCfg         - [PNT] Config struct
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_MEMORY       - Out of memory
    //! @retval     R_OVERFLOW     - To much messages in the receive FIFO
    //! @retval     R_CONFIG       - CAN not available
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvCreate( TBloCRcv *ptBlo, const TCRcvCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for CRCV-Block interface (*** needed if the block was not created by the PDT ***)
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvInit( TBloCRcv *ptBlo );

      //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error status on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCRcvGetErrStaBit( TBloCRcv* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum error status information
    //! @param[in]  ptBlo   - [PNT] Pointer to the block
    //! @retval     OKAY    - [BIT] Error state bit coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCRcvGetErrStaAll( TBloCRcv* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCRcvGetErrEveBit( TBloCRcv* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT] Pointer to the block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error state bit coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCRcvGetErrEveAll( TBloCRcv* ptBlo, TBoolean boDetect );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u32Id          - [NUM] Can id
    //! @param[in]      boExtId        - [DEF] Can extended identifier (11/29 Bit)
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanId( TBloCRcv *ptBlo, TUint32 u32Id, TBoolean boExtId );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Pri          - [NUM] Priority       - Bit 28...26 (start with 0) Max-Val: 0x3     DLC:3
    //! @param[in]      u32Pgn         - [NUM] PGN            - Bit 23...8  (start with 0) MAX-Val: 0x3FFFF DLC:18
    //! @param[in]      u8Sa           - [NUM] Source address - Bit 7..0    (start with 0) MAX-Val: 0xFF    DLC:8
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanIdJ1939( TBloCRcv *ptBlo, TUint8 u8Pri, TUint32 u32Pgn, TUint8 u8Sa );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the Can Id for the J1939 protocol - only priority
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Pri          - [NUM] Priority       - Bit 28...26 (start with 0) Max-Val: 0x3     DLC:3
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanIdJ1939Pri( TBloCRcv *ptBlo, TUint8 u8Pri );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol - only PGN
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u32Pgn         - [NUM] PGN            - Bit 23...8  (start with 0) MAX-Val: 0x3FFFF DLC:18
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanIdJ1939Pgn( TBloCRcv *ptBlo, TUint32 u32Pgn );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the J1939 protocol - only source address
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Sa           - [NUM] Source address - Bit 7..0    (start with 0) MAX-Val: 0xFF    DLC:8
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanIdJ1939Sa( TBloCRcv *ptBlo, TUint8 u8Sa );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the can Id for the invert message ( call only in the eAppStartUp phase )
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u32NegId       - [NUM] Can id for the invert message
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //! @retval         R_SUPPORT      - Don't support the 'invert message Id'
    //! @retval         R_CONFIG       - Message use an 'Invert Flag' no 'Invert Message Id' needed
    //! @retval         R_PHASE        - Function isn't call in the app "Start Up" phase
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanIdInc( TBloCRcv *ptBlo, TUint32 u32NegId );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Map by the invert message a fix 'mask of bits' out, the comparison is here of equal
    //! @param[in,out]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u8Start        - [NUM] Can id for the invert message
    //! @param[in]      u8Size         - [NUM] Can id for the invert message [must <= 32]
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_RANGE        - u8Start or u8Size is to big (see the debug output)
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //! @retval         R_SUPPORT      - Don't support the 'invert message Id'
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvMapInvDataOut( TBloCRcv *ptBlo, TUint8 u8Start, TUint8 u8Size );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Change the timing for the CRcv block
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @param[in]      u16CycTimOut   - [ms] Cycle time out
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvChangeCanTiming( TBloCRcv *ptBlo, TUint16 u16CycTimOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Reset the first check time
    //!                 NewCheckTime = current ecu time[ms] + first check time[ms]
    //!                 if the NewCheckTime is >= 65535[ms] the reset function have no result an more (R_SUPPORT)
    //! @param[in]      ptBlo          - [PNT] Pointer to the block
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_SUPPORT      - NewCheckTime is now 65535 ms, the NewCheckTime is fix by that value
    //! @retval         R_NULL_POINTER - NULL pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCRcvResetFirstCheckTime( TBloCRcv *ptBlo );


    //--------------------------------------------------------------------------------------------------
    //! @brief          returns full/unmasked CAN ID of last message received for given CRcv-Block
    //! @attention      The ID could be from inverted message and thus caused no data update
    //! @param[in]      cptBlo          - [PNT] Pointer to the block
    //! @param[out]     cpu32CanId      - [PNT] Pointer to output for CAN ID, U32_UNDEF if no message was received yet
    //! @param[out]     cpboExtended    - [PNT] Pointer to output for CAN ID extended flag(always matches configured setting)
    //! @retval         R_OKAY          - Functions execute without error
    //! @retval         R_NULL_POINTER  - NULL pointer
    //! @retval         R_ADDRESS       - Wrong block address
    //! @retval         R_EMPTY         - no message received yet
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloRcvGetReceivedCanId( TBloCRcv* const cptBlo, TUint32* const cpu32CanId, TBoolean* const cpboExtended );

#endif
#endif
