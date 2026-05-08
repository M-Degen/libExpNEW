//**************************************************************************************************
/*!
@file       ItfBloLBus.h
@note       For the TTC5XX and TTC5X
*/
//**************************************************************************************************

#ifndef __ITFBLOLBUS__
  #define __ITFBLOLBUS__

#include <ItfCore.h>
#include <ItfCoreLin.h>
#include <ItfBasEleErr.h>

#ifdef COMPILER_SWITCH_LINBUS

#if defined(COMPILER_SWITCH_FAM_TTC5XX) || defined(COMPILER_SWITCH_FAM_TTC5X)

// DEFINES & ENUMS  ===============================================================================

    #define  LIN_BUS_NODE_MAX  4   //!< the Lin Block can handle x LIN Notes

    //! LIN Bus Errors
    enum
    {
        DM_LIN_BUSOFF,      //!<    1 - LINSTA_PHYSICAL_BUS - physical bus error was detected
        DM_LIN_BUSWAR,      //!<    2 - LINSTA_NO_RESPONSE  - no response from the slave
        DM_LIN_TIMEOUT,     //!<    4 - LINSTA_TIMEOUT      - LIN timeout detected, if frame duration exceeded the maximum frame time

        DM_LIN_INCORRECT,   //!<    8 - Data Incorrect
                            //!<      - LINSTA_BIT             - a bit error was detected
                            //!<      - LINSTA_PARITY          - parity error detected during receiving
                            //!<      - LINSTA_CHECKSUM        - a checksum error occurred
                            //!<      - LINSTA_FRAMING         - an expected stop bit is not found
                            //!<      - LINSTA_INCON_SYN_FIELD - inconsistent synch field error was detected

        DM_LIN_RCV_0,       //!<   16 - Rcv Note 0 have no success
        DM_LIN_RCV_1,       //!<   32 - Rcv Note 1 have no success
        DM_LIN_RCV_2,       //!<   64 - Rcv Note 2 have no success
        DM_LIN_RCV_3,       //!<  128 - Rcv Note 3 have no success

        DM_LIN_SND_0,       //!<  256 - Snd Note 0 have no success
        DM_LIN_SND_1,       //!<  512 - Snd Note 1 have no success
        DM_LIN_SND_2,       //!< 1024 - Snd Note 2 have no success
        DM_LIN_SND_3,       //!< 2048 - Snd Note 3 have no success

        DM_LIN_CNT_MAX
    };

// CONFIGURATION STRUCTURE =========================================================================
    //! Configuration of ERR-Block
    typedef struct
    {   // Common
       TChar       achName[BLO_NAME_STR_LEN];   //!< [STR] - Block Name
       EBloStatus  eBloProc;                    //!< [ENU] - Block Process
       TUint16     u16Bitrate;                  //!< [NUM/DEF] - Is the Baud rate which is to use for the communication over the LIN-BUS
       ELinCstType eChecksumType;               //!< [ENU]     - Is the type of the checksum of the LIN-Frames

       TUint8      u8NodeCnt;                   //!< [NUM] - Current number of node in network
       TUint8      u8NodeTry;                   //!< [NUM] - Count of Snd/Rcv tries in the process work flow
       TUint8      u8NodeMinTicks;              //!< [NUM] - CMinimum delay Ticks per Note
       TUint8      u8SlaveRcvCnt;               //!< [NUM] - CSlave receive counter
       TUint8      u8SlaveSndCnt;               //!< [NUM] - CSlave receive counter

       // Fixed setting
       TUint8      u8ErrCnt;                    //!< [NUM] - Cnt of valid Error Case
       TErrCfgFea  atErrFea[DM_LIN_CNT_MAX];    //!< [CLA] - Error Number Configurations
    } TLBusCfg;

    typedef struct
    {
        TBoolean boNow;                 //!< [DEF] Send now - shift the cycle send (if send - set to 'FALSE')
        TUint16  u16Cyc;                //!< [ms]  Send out with that cycle (0= no auto send)
        TLinMsg  tMsg;                  //!< [STU] Send out message
    }TLinInpSndNote;

    typedef struct
    {
        TBoolean boValid;               //!< [DEF] Message is out
        TUint16  u16OutSinceCycTicks;   //!< [NUM] Message is out since x cycle ticks
        TUint32  u32OutCnt;             //!< [NUM] - Count of send LIN messages (from ECU start, overflow not protected)
    }TLinOutSndNote;

    typedef struct
    {
        TBoolean boNow;                 //!< [DEF] receive now - shift the cycle receive (if receive request is send - set to 'FALSE')
        TUint16  u16Cyc;                //!< [ms] auto receive (0= no auto receive)
        TUint8   u8Dlc;                 //!< Frame Request Data length code
        TUint8   u8Id;                  //!< Frame Request Identifier
    }TLinInpRcvNote;

    typedef struct
    {
        TBoolean boValid;               //!< [DEF] - Message is valid
        TLinMsg  tMsg;                  //!< [STU] - Receive message
        TUint16  u16InSinceCycTicks;    //!< [NUM] - Receive since cycle ticks
        TUint32  u32InCnt;              //!< [NUM] - Count of received LIN messages (from ECU start, overflow not protected)
    }TLinOutRcvNote;

    //! INPUT SUB-BLOCK
    typedef struct
    {
        EBloStatus     eBehProc;                      //!< [ENU] - Block Process Status Options
        TBehErrCntl    tBehErrCntl;                   //!< [STU] - Error Control Behavior
        TLinInpSndNote atSndNote[LIN_BUS_NODE_MAX];   //!< [STU] - Snd Node Input
        TLinInpRcvNote atRcvNote[LIN_BUS_NODE_MAX];   //!< [STU] - Rcv Node Input
    } TLinInp;

    //! OUTPUT SUB-BLOCK
    typedef struct
    {
        EBloStatus     eBehProcSta;                  //!< [ENU] - Block Process Status Options
        TBehErrSta     tBehErrSta;                   //!< [STU] - Error Behavior Status
        TLinOutSndNote atSndNote[LIN_BUS_NODE_MAX];  //!< [STU] - Snd Node Output
        TLinOutRcvNote atRcvNote[LIN_BUS_NODE_MAX];  //!< [STU] - Rcv Node Output
    } TLinOut;

    //! ADDRESS SUB-BLOCK
    typedef struct
    {
        const TLBusCfg* cptCfg;          //!< [STU] - Configuration Struct
              TVoid*    pvObj;           //!< [STU] - Pointer to the private Object
              TUint16   u16Stamp;        //!< [NUM] - Block stamp 'A'xx,'E'  xx is the Block-Id
    }TLinAdr;

    //! BLOCK
    typedef struct
    {
        TLinInp   tInp;                 //!< [STU] - Input vector
        TLinOut   tOut;                 //!< [STU] - Output vector
        TLinAdr   tXAdr;                //!< [STU] - Private Address Information
    } TBloLBus;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization function for LBUS-Block Interface (*** need if the block don't create with the PDT ***)
    //! @param[in]  ptBlo          - [PNT] Pointer to Block
    //! @param[in]  cptCfg         - [PNT] Pointer to the config struct
    //! @retval     R_OKAY         - Functions execute without error
    //! @retval     R_NULL_POINTER - Null Pointer
    //! @retval     R_MEMORY       - Out of memory
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloLBusCreate( TBloLBus *ptBlo, const TLBusCfg* cptCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for CBUS-Block Interface (*** need if the block don't create with the PDT ***)
    //! @param[in,out]  ptBlo          - [PNT] Pointer to Block
    //! @retval         R_OKAY         - Functions execute without error
    //! @retval         R_NULL_POINTER - Null Pointer
    //! @retval         R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloLBusInit( TBloLBus *ptBlo );

     //--------------------------------------------------------------------------------------------------
    //! @brief          LBus-Block is working
    //! @param[in,out]  ptBlo               - [PNT] Pointer to Block
    //! @retval         R_OKAY              - functions execute without error
    //! @retval         R_OVERFLOW          - Is full - no data has been transmitted
    //! @retval         R_UNKNOWN           - Unknown internal device error
    //! @retval         R_NULL_POINTER      - Null Pointer
    //! @retval         R_ADDRESS           - wrong block address
    //! @retval         R_CONFIG            - CBuf-Block is not a send block  (is a receiver CBuf-Block)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloLBus( TBloLBus *ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Deinitialization Lin Bus
    //! @retval     R_OKAY            - functions execute without error
    //! @retval     R_PARAMETER       - range invalid parameter has been passed
    //! @retval     R_NOT_INITIALIZED - the channel was not configured
    //! @retval     R_UNKONW          - unknown error occurred
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloLBusDeInit( );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Reinitialization Lin Bus
    //! @param[in,out]  ptBlo			- [PNT] Pointer to Block
    //! @retval     R_OKAY				- functions execute without error
    //! @retval     R_NULL_POINTER 		- Null Pointer
    //! @retval     R_ADDRESS			- Wrong block address
    //! @retval     R_PARAMETER			- range invalid parameter has been passed
    //! @retval     R_NOT_INITIALIZED	- the channel was not configured
    //! @retval     R_UNKONW			- unknown error occurred
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eBloLBusReInit( TBloLBus *ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Error Status on a specified Bit-Position
    //! @param[in]  ptBlo     - [PNT]   Pointer to Block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error State of the specific Bit-Position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloLBusGetErrStaBit( TBloLBus* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum Error Status Information
    //! @param[in]  ptBlo   - [PNT] Pointer to Block
    //! @retval     OKAY    - [BIT] Error State Bit Coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloLBusGetErrStaAll( TBloLBus* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Error Event on a specified Bit-Position
    //! @param[in]  ptBlo     - [PNT]   Pointer to Block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error State of the specific Bit-Position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloLBusGetErrEveBit( TBloLBus* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Error Event on a specified Bit-Position
    //! @param[in]  ptBlo     - [PNT] Pointer to Block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error State Bit Coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloLBusGetErrEveAll( TBloLBus* ptBlo, TBoolean boDetect );

#endif
#endif
#endif
