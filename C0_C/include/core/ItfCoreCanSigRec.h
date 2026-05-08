//**************************************************************************************************
/*!
@file       ItfCoreCanSigRec.h
@brief      Versions Interface
@data       04.07.2013
@author     HYDAC/NJP

Transforms the can message value into the can record value (received CanValue -> CanSignalRecord)

   A) The can value is a special value (exception - highest priority) 
        Can value      = Special value
        Rec value      = Special value
        RecCan-Status = SIG_SPECIAL

   B)  The can value is located in the range between MIN and MAX (CAN value is the basis)
        Can value      = basis value
        Rec value      = (Can value*Factor) + Offset
        RecCan-Status = SIG_OKAY;

   C) The can value is not in the range between MIN and MAX and the can value is no special value (CAN value is the basis)
       depending on the error reaction:
          case ERSIG_INIT: Can value = Init value
          case ERSIG_DFLT: Can value = default value
          case ERSIG_HOLD: Can value = former raw value
        Can value       = Can value
        Structure value  = (Can value*factor) + offset
        RecCan-Status  = SIG_ERR_MIN oder SIG_ERR_MAX


Transforms the can record to a can message (send: CanSignalRecord -> CanValue):

   A ) The Rec value is a special value (exception - highest priority)
        Can value      = Special value
        Structure value = Special value
        RecCan-Status = SIG_SPECIAL

   B ) The can value is located in the range between MIN and MAX and the can value is no special value  (structure value is the basis)
         Can value_Temp = (Structure value - Offset) \ Factor
         Can value_Temp in range (MIN, MAX)
         Can value      = Can value_Temp
         Structure value = Basis value
         RecCan-Status = SIG_OKAY

   C ) The can value is not in the range between MIN and MAX and the can value is no special value (Structure value is determinated)
        Can value_Temp  = (Structure value - Offset) \ factor
        Can value_Temp not in range (MIN, MAX)
        depending on error reaction:
          case ERSIG_INIT: Can value = Init value
          case ERSIG_DFLT: Can value = default value
          case ERSIG_HOLD: Can value = former raw value
        Can value      = Can value
        Structure value = (Can value*Factor) + Offset
        RecCanStatus  = SIG_ERR_MIN or SIG_ERR_MAX

----------------------------------------------------------------------------------------------------
*/
//**************************************************************************************************

#ifndef __ITFCORECANSIGREC__
    #define __ITFCORECANSIGREC__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreDb.h>
    #include <ItfBasConv.h>
    #include <ItfCoreBoard.h>

    #ifdef COMPILER_SWITCH_CANBUS

// DEFINES & ENUMS  ================================================================================

    #define CSR_STAMP             0xA06A                                   //!< Can record stamp
    #define CANREC_NAME_STR_LEN   (32+1)                                   //!< Can record name length
    #define CANREC_SPECIAL_DIM    4                                        //!< Can record special Dim

    #define CRCMUX_START          5000                                     //!< Start point for can signal multiplexer
    #define REC_NO_2APP_OPFFSET   10000                                    //!< Offset for the second application
    #define CRCMUX_START_2APP     (REC_NO_2APP_OPFFSET + CRCMUX_START)     //!< Start point for can signal multiplexer

    // App1 Single:     0 -  4999
    // App1 Mux:     5000 <  9999
    // App2 Single: 10000 < 14999
    // App2 Mux:    15000 < I16_MAX

    #define CRCMUX_NONE          U16_MAX           //!< No connection to a multiplexer
    #define CRCMUX_UNDEF         I16_MAX           //!< Show that the mux CSnd/CRcv is undefined

    //! Error reaction
    typedef enum
    {
        ERSIG_INIT,                                //!< 0 - In error case back to init
        ERSIG_DFLT,                                //!< 1 - In error case back to default
        ERSIG_HOLD                                 //!< 2 - In error case hold the old value - if the old vale not in 'MIN/MAX Range' take the init Value
    }EErSig;                                       //!<                                        is a problem of the first init.

    //! Store behavior DB-List. variable
    typedef enum
    {
        SBSIG_MANUALLY,                            //!< 0 - Store by user
        SBSIG_DOWN                                 //!< 1 - Store if controller shut down
                                                   //!< SBSIG_CHANGE - Store by value change - is to high-risk, to the NVMEM can damage
    }ESbSig;

	//! signal value status
    typedef enum
    {
        SIG_OKAY,                                  //!< 0 - Signal is OK
        SIG_SPECIAL,                               //!< 1 - Signal is special value
        SIG_ERR_MIN,                               //!< 2 - Signal error value to low
        SIG_ERR_MAX,                               //!< 3 - Signal error value to high
        SIG_ERR_NA                                 //!< 4 - Signal error position isn't valid
    }ESigSta;

  // TYPEDEF  ========================================================================================

    //! CanSigRec boolean range structure
    typedef struct
    {
        TBoolean boMin;                              //!< [ro][NUM] Minimum
        TBoolean boMax;                              //!< [ro][NUM] Maximum
        TBoolean boInit;                             //!< [ro][NUM] Init
        TBoolean boDflt;                             //!< [ro][NUM] Default
    }TCanSigRecRng_bo;

    //! CanSigRec char range structure
    typedef struct
    {
        TChar chMin;                               //!< [ro][NUM] Minimum
        TChar chMax;                               //!< [ro][NUM] Maximum
        TChar chInit;                              //!< [ro][NUM] Init
        TChar chDflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_ch;

    //! CanSigRec signed8 range structure
    typedef struct
    {
        TInt8 i8Min;                               //!< [ro][NUM] Minimum
        TInt8 i8Max;                               //!< [ro][NUM] Maximum
        TInt8 i8Init;                              //!< [ro][NUM] Init
        TInt8 i8Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_i8;


    //! CanSigRec unsigned8 range structure
    typedef struct
    {
       TUint8 u8Min;                               //!< [ro][NUM] Minimum
       TUint8 u8Max;                               //!< [ro][NUM] Maximum
       TUint8 u8Init;                              //!< [ro][NUM] Init
       TUint8 u8Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_u8;


    //! CanSigRec signed16 range structure
    typedef struct
    {
        TInt16 i16Min;                               //!< [ro][NUM] Minimum
        TInt16 i16Max;                               //!< [ro][NUM] Maximum
        TInt16 i16Init;                              //!< [ro][NUM] Init
        TInt16 i16Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_i16;


    //! CanSigRec unsigned16 range structure
    typedef struct
    {
       TUint16 u16Min;                               //!< [ro][NUM] Minimum
       TUint16 u16Max;                               //!< [ro][NUM] Maximum
       TUint16 u16Init;                              //!< [ro][NUM] Init
       TUint16 u16Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_u16;


    //! CanSigRec signed32 range structure
    typedef struct
    {
        TInt32 i32Min;                               //!< [ro][NUM] Minimum
        TInt32 i32Max;                               //!< [ro][NUM] Maximum
        TInt32 i32Init;                              //!< [ro][NUM] Init
        TInt32 i32Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_i32;


    //! CanSigRec unsigned32 range structure
    typedef struct
    {
       TUint32 u32Min;                               //!< [ro][NUM] Minimum
       TUint32 u32Max;                               //!< [ro][NUM] Maximum
       TUint32 u32Init;                              //!< [ro][NUM] Init
       TUint32 u32Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_u32;

    //! CanSigRec float32 range structure
    typedef struct
    {
       TFloat32 f32Min;                               //!< [ro][NUM] Minimum
       TFloat32 f32Max;                               //!< [ro][NUM] Maximum
       TFloat32 f32Init;                              //!< [ro][NUM] Init
       TFloat32 f32Dflt;                              //!< [ro][NUM] Default
    }TCanSigRecRng_f32;

    //! CanSigRec DB information
    typedef struct
    {
       TDbLink tDbLink;                             //!< [ro][STU] DB-Link
       ESbSig  eSbSig;                              //!< [ro][ENU] Store behavior DB-List. variable
    }TCsrDbInfo;

    //! CanSigRec variable record
    typedef struct
    {
       TCsrDbInfo tDbInfo;                          //!< [ro][STU] DB-List.var link
       EErSig     eErSig;                           //!< [ro][ENU] Error reaction
       EVarTyp    eCanType;                         //!< [ro][ENU] CAN Layer Data type
       EVarTyp    eAppType;                         //!< [ro][ENU] App Layer Data type
       TUint8     u8Start;                          //!< [ro][NUM] Start
       TUint8     u8Size;                           //!< [ro][NUM] Size
       TUint8     u8SpecialCnt;                     //!< [ro][NUM] Special value content

       TInt32     i32Off;                           //!< [ro][NUM] Offset
       TInt32     i32Mul;                           //!< [ro][NUM] Multiplier
       TInt32     i32Div;                           //!< [ro][NUM] Divisor
    }TCanSigRecInf;

    //! RecDat variable record
    typedef struct
    {
        TCanSigRecInf *ptInf;                       //!< [ro][PTR] Pointer information field
        TVoid         *pvRng;                       //!< [ro][PTR] Pointer TCanSigRecRng_*
        TVoid         *pvVal;                       //!< [ro][PTR] Pointer data value
        TVoid         *pvOldVal;                    //!< [ro][PTR] Pointer to old valid values

        ESigSta       *peErr;                       //!< [ro][PTR] Pointer to record errors

        TVoid         *pvSpecialValCan;             //!< [ro][PTR] Special Values CAN
        TVoid         *pvSpecialValApp;             //!< [ro][PTR] Special Values App
    }TRecDat;

    //! CanSigRec root structure ( Root->{ Rec[x=Type]->_xInf }* n )
    typedef struct
    {
        TChar         achName[CANREC_NAME_STR_LEN]; //!< [ro][STR] Name
        TUint8        u8Dlc;                        //!< [ro][NUM] DLC of can message
        TUint8        u8CanByteDflt;                //!< [ro][NUM] CAN message default
        ECanFormat    eCanFormat;                   //!< [ro][NUM] CAN format
        TUint8        u8MasterReceiveId;            //!< [ro][NUM] Receive Id
        TUint8        u8RecCnt;                     //!< [ro][NUM] Count of record
        const TRecDat *cptRecDat;                   //!< [ro][PTR] Pointer to record data (Dflt, Init, Range, Special-Values)
        TUint16       u16RecNo;                     //!< [ro][NUM] Record number
        TUint16       u16Stamp;                     //!< [ro][NUM] Safety stamp
    }TCanSigRecRoot;

    //! Can signal record root tab
    typedef struct
    {
        TUint16 u16CanRecCnt;                       //!< Count of can records
        TVoid   *vpFirstCanRec;                     //!< First can record
        TUint16 u16CanRecMuxCnt;                    //!< Count of can records
        TVoid   *vpFirstCanMuxRec;                  //!< First can record
        TUint16 *pu16FirstCanMuxRecCnt;             //!< First can record
    }TCanSigRecRootTab;

    extern const TCanSigRecRootTab g_ctCanSigRecRootTab;    //!< Can signal record root tab

// FUNCTION  =======================================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get can signal record error status
    //! @param[in]  ptRoot  - CAN signal record root
    //! @param[in]  u8Pos   - Position
    //! @return     Can signal status
    //--------------------------------------------------------------------------------------------------
    extern ESigSta eCoreGetCanSigRecErrSta( TCanSigRecRoot *ptRoot, TUint8 u8Pos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Send 'Can Signal Record' over the own message buffer out.
    //! @param[in]  cptRoot  - CAN signal record root
    //! @retval     R_OKAY          - OK
    //! @retval     R_OVERFLOW      - Buffer is full
    //! @retval     R_CONFIG        - BloCSnd-Obj must have a buffer. (u8MsgBufSize >= 1)
    //! @retval     R_NULL_POINTER  - ptRoot is a Null pointer
    //! @retval     R_ADDRESS       - ptRoot is stamp
    //! @retval     R_RANGE         - cptRoot->u16RecNo isn't valid
    //! @retval     R_CONFIG        - isn't a send message
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBufSetCanSigRecSndOut( const TCanSigRecRoot *cptRoot );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Send 'Can Signal Record' over the own message buffer out.
    //!             Try to send the message with the minimum cycle time out
    //! @param[in]  cpvMux  - CAN signal record root
    //! @retval     R_OKAY          - OK
    //! @retval     R_OVERFLOW      - Buffer is full
    //! @retval     R_CONFIG        - BloCSnd-Obj must have a buffer. (u8MsgBufSize >= 1)
    //! @retval     R_SUPPORT       - The Mux-selector is CRCMUX_UNDEF
    //! @retval     R_NULL_POINTER  - ptRoot is a Null pointer
    //! @retval     R_ADDRESS       - ptRoot is stamp
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreBufSetCanSigRecSndOutMux( const TVoid *cpvMux );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the receive 'Can Signal Record' current buffer counter - for that CSR-root-pointer
    //! @param[in]  cptRoot   - CAN signal record root
    //! @param[out] pu8MsgCnt - message counter
    //! @retval     R_OKAY          - OK
    //! @retval     R_EMPTY         - Buffer is empty
    //! @retval     R_NULL_POINTER  - ptRoot is a Null pointer
    //! @retval     R_ADDRESS       - ptRoot is stamp
    //! @retval     R_CONFIG        - ptRoot is no receive buffer
    //! @retval     R_RANGE         - internal range error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetCanSigRecMsgCnt( const TCanSigRecRoot *cptRoot, TUint8 *pu8MsgCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the receive message from the own Rcv-Signal-Can-Buffer - for that CSR-root-pointer
    //! @param[in]  cptRoot  - CAN signal record root
    //! @param[out] ptMsg    - Receive message pointer
    //! @retval     R_OKAY          - OK
    //! @retval     R_EMPTY         - Buffer is empty
    //! @retval     R_NULL_POINTER  - ptRoot is a Null pointer
    //! @retval     R_ADDRESS       - ptRoot is stamp
    //! @retval     R_CONFIG        - ptRoot is no receive buffer
    //! @retval     R_RANGE         - ptRoot internal error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetCanSigRegMsgData( const TCanSigRecRoot *cptRoot, TRcvMsg *ptMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Set the 'Can Record Struct' via 'Can Data Bytes' - for that CSR-root-pointer
    //! @param[in]   cptRoot    - Can record root
    //! @param[in]   au8CanData - Can message data
    //! @param[out]  pboCha     - Can record have changed (If Pointer is NULL give no information)
    //! @retval      R_OKAY          - is OK
    //! @retval      R_NULL_POINTER  - cptRoot or au8CanData is a null pointer
    //! @retval      R_ADDRESS       - ptRoot is stamp
    //! @retval      R_CONFIG        - ptRoot is no receive buffer
    //! @retval      R_RANGE         - internal range error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetSigRecCanDataUpdate( const TCanSigRecRoot *cptRoot, TUint8 au8CanData[8], TBoolean *pboCha );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the receive 'Can Signal Record' current buffer counter - for that MUX-root
    //! @param[in]  cpvMux     - Can record MUX root
    //! @param[out] pu8MsgCnt  - Pointer of the message counter
    //! @retval     R_OKAY          - OK
    //! @retval     R_EMPTY         - Buffer is empty
    //! @retval     R_NULL_POINTER  - cpvMux is a Null pointer
    //! @retval     R_ADDRESS       - cpvMux is stamp
    //! @retval     R_CONFIG        - BloCSnd-Obj must have a buffer. (u8MsgBufSize >= 1)
    //! @retval     R_RANGE         - internal range error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetSigRecBufMsgCntMux( const TVoid *cpvMux, TUint8 *pu8MsgCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the receive message from the own Rcv-Signal-Can-Buffer - for that MUX-root
    //! @param[in]  cpvMux  - CAN signal record root
    //! @param[out] ptMsg   - Receive message pointer
    //! @retval     R_OKAY          - OK
    //! @retval     R_EMPTY         - Buffer is empty
    //! @retval     R_CONFIG        - BloCSnd-Obj must have a buffer. (u8MsgBufSize >= 1)
    //! @retval     R_NULL_POINTER  - ptRoot is a Null pointer
    //! @retval     R_ADDRESS       - cpvMux is stamp
    //! @retval     R_CONFIG        - ptRoot is no receive buffer
    //! @retval     R_RANGE         - ptRoot internal error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetMsgFromRcvBufMux( const TVoid *cpvMux, TRcvMsg *ptMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Set the 'Can Record Struct' via 'Can Data Bytes' - for that MUX-root
    //! @param[in]   cpvMux     - Can record MUX root
    //! @param[in]   au8CanData - Can message data
    //! @param[out]  pboCha     - Can record have changed (If Pointer is NULL give no information)
    //! @retval      R_OKAY          - is OK
    //! @retval      R_CONFIG        - BloCSnd-Obj must have a buffer. (u8MsgBufSize >= 1)
    //! @retval      R_NULL_POINTER  - cptRoot or au8CanData is a null pointer
    //! @retval      R_CONFIG        - ptRoot is no receive buffer
    //! @retval      R_RANGE         - internal range error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetSigRecFromCanDataBufMux( const TVoid *cpvMux, TUint8 au8CanData[8], TBoolean *pboCha );

#else // CDS2.3
    #define CSR_STAMP             0x0                                   //!< Can record stamp
#endif

#endif
