//**************************************************************************************************
/*!
@file  		    ItfBloCBuf.h
@brief	        Can Bus Interface
@date           21.07.2013
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBLOCBUF__
  #define __ITFBLOCBUF__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfBasEleErr.h>
    #include <ItfCoreEcu.h>
    #include <ItfCoreCan.h>
    #include <ItfBloCBus.h>
    #include <ItfCoreBoard.h>

    #ifdef COMPILER_SWITCH_CANBUS

// DEFINES & ENUMS  ================================================================================
    #ifdef COMPILER_SWITCH_FAM_TTC5XX
     #define   BUF_SW_RCV_MAX            24        //!< Maximum receive software buffer   TTC5xx:   Max: 8*7=56 [njp044] old 16
     #define   BUF_SW_SND_MAX            36        //!< Maximum send software buffer      TTC5xx:   Max: 6*7=36 [njp044] old 16
    #else
     #ifdef COMPILER_SWITCH_FAM_TTC3X
      #define  BUF_SW_RCV_MAX            4         //!< Maximum receive software buffer   TTC30:    Max 8*1= 8 | TTC32: Max 8*2= 16
      #define  BUF_SW_SND_MAX            4         //!< Maximum send software buffer      TTC30:    Max 6*1= 6 | TTC32: Max 6*2= 12
     #else
      #define  BUF_SW_RCV_MAX           16         //!< Maximum receive software buffer   TTC5x/7x: Max 8*2= 16
      #define  BUF_SW_SND_MAX           16         //!< Maximum send software buffer      TTC5x/7x: Max 8*2= 12
     #endif
    #endif

    #define  SWBUF_NA                 0xFF         //!< No software buffer

    //! CAN Software BUFFER Errors
    enum
    {
        DM_CBUF_SOVERF,                            //!< 0 -01- Software buffer overflow
        DM_CBUF_CNT_MAX = 1,
        DM_CBUF_CBUS_OFF,                          //!< 1 -02- Can bus off
        DM_CBUF_CBUS_WARN,                         //!< 2 -04- Can bus warning
        DM_CBUF_CBUS_HOVERF,                       //!< 3 -08- Can bus hardware overflow
        DM_CBUF_ALL_CNT_MAX
    };

// CONFIGURATION STRUCTURE =========================================================================

    //! CONFIGURATION OF CBUF
    typedef struct
    {
        //Common
        TChar       achName[BLO_NAME_STR_LEN];     //!< [STR] - Block name
        TUint8      u8CBufPosIdx;                  //!< [ENU] - CBUF the own count index
        EBloStatus  eBloProc;                      //!< [ENU] - Block process
        // Fixed settings
        ECBusHwBuf  eCBusHwBufNo;                  //!< [ENU] - CBUF position connection link
        TUint8      u8CallCountOfCycle;            //!< [NUM] - Cyclic can buffer call [count of cycles]
        TUint8      u8SwBufSize;                   //!< [NUM] - CBUF Can software message buffer
        //Error
        TUint8      u8ErrCnt;                      //!< [NUM] - Cnt of valid error case
        TErrCfgFea  atErrFea[DM_CBUF_CNT_MAX];     //!< [CLA] - Error number configurations
    }TCBufCfg;

    //! CBUF address
    typedef struct
    {
        const TCBufCfg* cptCfg;                    //!< [STU] - Configuration struct
              TVoid*    pvObj;                     //!< [STU] - Pointer to the private object
              TUint16   u16Stamp;                  //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TCBufAdr;

   //! INPUT SUB-BLOCK
    typedef struct
    {
        TBehErrCntl  tBehErrCntl;                  //!< [STU] - Error control behavior
    } TCBufInp;


    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        TBehErrSta tBehErrSta;                     //!< [STU] - Error behavior status
    } TCBufOut;

    //! CBUF block
    typedef struct
    {
        TCBufInp tInp;                             //!< [STU] - Block input vector
        TCBufOut tOut;                             //!< [STU] - Block output vector
        TCBufAdr tXAdr;                            //!< [STU] - Private address information
    }TBloCBuf;

    #ifdef COMPILER_SWITCH_CANBUS

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for CBUF-Block interface (*** needed if the block was not created with the PDT ***)
    //! @param[in]  ptBlo          - [PNT] Pointer to the block
    //! @param[in]  cptCfg         - Pointer to the config struct
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - Null pointer
    //! @retval     R_MEMORY       - Out of memory
    //! @retval     R_CONFIG       - HW Buffer not valid/CAN not available
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBufCreate( TBloCBuf *ptBlo, const TCBufCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for CBUF block interface (*** needed if the block was not created with the PDT ***)
    //! @param[in,out]  ptBlo             - [PNT] Pointer to the block
    //! @retval         R_OKAY            - Functions execute without error
    //! @retval         R_NULL_POINTER    - Null pointer
    //! @retval         R_ADDRESS         - Wrong block address
    //! @retval         R_OVERFLOW        - No more HW message objects are available
    //! @retval         R_RANGE           - No more free handles are available
    //! @retval         R_SUPPORT         - Invalid channel number has been passed
    //! @retval         R_PARAMETER       - A parameter is out of range
    //! @retval         R_EMPTY           - Null pointer has been passed
    //! @retval         R_CONFIG          - Channel has not been initialized
    //! @retval         R_MEMORY          - Unable to create the software fifo
    //! @retval         R_UNKNOWN         - Unknown error (normal not possible)
    //! @retval         R_MAXIMUM         - To much CBUF Block
    //! @retval         R_NOT_INITIALIZED - No valid CAN_BUF Enum
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBufInit( TBloCBuf *ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Send messages out via the CBuf block
    //! @param[in,out]  ptBlo               - [PNT] Pointer to the block
    //! @param[out]     ptSndMsg            - [PNT] Pointer to the send that message out
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_ADDRESS           - Wrong block address
    //! @retval         R_CONFIG            - CBuf block is not a send block  (is a receiver CBuf-Block)
    //! @retval         R_EMPTY             - The ptSndMsg pointer is a NULL pointer
    //! @retval         R_OVERFLOW          - The message is not taken the CBuffer is full
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBufSnd( TBloCBuf *ptBlo, TSndMsg *ptSndMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Give the not PreDefine receive messages back (Message with no receive message connection)
    //!                 Call the function until the return value is R_OKAY (the receive message is copy to the ptRcvMsg pointer)
    //!                 If the return value is R_EMPTY there are no receive message any more.
    //! @param[in,out]  ptBlo               - [PNT] Pointer to the block
    //! @param[out]     ptRcvMsg            - [PNT] Pointer to the send that message out
    //! @retval         R_OKAY              - Functions execute without error -> on the ptRcvMsg pointer send the message
    //! @retval         R_NULL_POINTER      - NULL pointer
    //! @retval         R_ADDRESS           - Wrong block address
    //! @retval         R_CONFIG            - CBuf block is not a receive block  (is a send CBuf-Block)
    //! @retval         R_EMPTY             - The are no more receive messages
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloCBufGetNoPreDefineRcvMsg( TBloCBuf *ptBlo, TRcvMsg *ptRcvMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error status on a specified Bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error state of the specific Bit position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCBufGetErrStaBit( TBloCBuf* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum error status information
    //! @param[in]  ptBlo   - [PNT] Pointer to the block
    //! @retval     OKAY    - [BIT] Error state Bit coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCBufGetErrStaAll( TBloCBuf* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified Bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error state of the specific Bit position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloCBufGetErrEveBit( TBloCBuf* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified Bit position
    //! @param[in]  ptBlo     - [PNT] Pointer to the block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error state bit coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloCBufGetErrEveAll( TBloCBuf* ptBlo, TBoolean boDetect );

#endif
#endif
#endif
