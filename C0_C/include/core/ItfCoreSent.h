//**************************************************************************************************
/*!
@file       ItfCoreSent.h
@brief      Single Edge Nibble Transmission (SENT) core interface
@date       27.10.2021
@author     HYDAC/OMO
@example    SENT
  \code{.c}
//--------------------------------------------------------------------------------------------------
// Usage in eAppInit() to initialize SENT pin
//--------------------------------------------------------------------------------------------------
ERetVal eAppInit( TVoid )
{
    // ...

    // Configure SENT pin
    TCoreSentInitCfg tSentCfg =
    {
        .u16TickLen     = 30,                         // tick length is 3us
        .u8FrameLen     = 6,                          // message contains 6 fast data nibbles
        .boEndPulse     = TRUE,                       // message ends with a pause pulse
        .eSerialMode    = SENT_SERIALMODE_ENHANCED,   // the enhanced serial message format is used
        .boStaComCrc    = FALSE,                      // the status and communication nibble is not included in CRC calculation
        .eCrcMode       = SENT_CRCMODE_AUGMENTED,     // the recommended mode (with augmented zero nibble) for CRC calculation is used
        .boSpcEnable    = FALSE,                      // SPC is not used
        .au8ViewCfg     = { 2, 1, 0, 3, 4, 5 },       // the 1st incoming nibble will be stored at index 2 (the 2nd at 1, the 3rd at 0, the 4th at 3, ...)
        .u16StatusStickyTime = 0                      // Amount of time in milliseconds a status persists until it is healed again
    };

    // Initialize sent pin
    ERetVal eRet = eCoreSentInit( PIN_AA4, &tSentCfg );
    if( eRet != R_OKAY )
    {
        // error handling
    }

    // ...
}
//--------------------------------------------------------------------------------------------------
// Usage in eAppRun() to read SENT pin
//--------------------------------------------------------------------------------------------------
TVoid vAppRun( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
{
    ERetVal eRet;
    TUint32 u32FastData, u32Timestamp;
    TUint8  au8FastData[SENT_NIBBLE_MAX];
    TUint8  u8StaCom;
    TSentSerialMsg tSerialData;

    // ...

    // Read (last) fast data frame as value
    eRet = eCoreSentGetFastDataVal( PIN_AA4, &u32FastData, &u32Timestamp );
    if( eRet != R_OKAY )
    {
        // error handling
    }

    // Read (last) fast data frame as array
    eRet = eCoreSentGetFastDataArr( PIN_AA4, au8FastData, &u32Timestamp );
    if( eRet != R_OKAY )
    {
        // error handling
    }

    // Read (last) status+communication nibble
    eRet = eCoreSentGetStaCom( PIN_AA4, &u8StaCom );
    if( eRet != R_OKAY )
    {
        // error handling
    }

    // Read (last) serial data message
    eRet = eCoreSentGetSerialData( PIN_AA4, &tSerialData);
    if( eRet != R_OKAY )
    {
        // error handling
    }

    // ...
}
\endcode
*/
//**************************************************************************************************

#ifndef __ITFCORESENT__
  #define __ITFCORESENT__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreBoard.h>

#ifdef COMPILER_SWITCH_SENT

// DEFINES & ENUMS  ================================================================================
    #define SENT_NIBBLE_MAX 6                   //!< Maximum amount of nibbles in fast data frame (as defined in J2716)

    typedef enum
    {
        SENT_SERIALMODE_NONE,                   //!< 0 - No serial data mode
        SENT_SERIALMODE_SHORT,                  //!< 1 - Short serial message format
        SENT_SERIALMODE_ENHANCED,               //!< 2 - Enhanced serial message format
        SENT_SERIALMODE_UNKNOWN                 //!< 3 - Unknown format
    } ESentSerialMode;

    typedef enum
    {
        SENT_CRCMODE_AUGMENTED,                 //!< 0 - Augments zero nibble to data nibbles for CRC calculation (as recommended by J2716 JAN2010)
        SENT_CRCMODE_LEGACY,                    //!< 1 - CRC calculation without zero nibble (as in J2716 FEB2008 revision and older)
        SENT_CRCMODE_ALTERNATIVE                //!< 2 - Alternative CRC calculation
    } ESentCrcMode;

    typedef struct
    {
        TUint16 u16MsgId;                       //!< [NUM] Message ID
        TUint16 u16Data;                        //!< [NUM] Serial data
    } TSentSerialMsg;

    // Configuration structure for SENT initialization
    typedef struct
    {
        TUint16         u16TickLen;                     //!< [1/10us] Tick length (e.g. 30 for 3us)
        TUint8          u8FrameLen;                     //!< [NUM]    Frame length - fast data nibbles only, without status and communication nibble or CRC
        TBoolean        boEndPulse;                     //!< [BIT]    Optional pause pulse
        ESentSerialMode eSerialMode;                    //!< [ENU]    Serial data mode
        TBoolean        boStaComCrc;                    //!< [BIT]    Include status and communication nibble in CRC calculation
        ESentCrcMode    eCrcMode;                       //!< [ENU]    Mode for 4-bit CRC calculation of fast and short serial data
        TBoolean        boSpcEnable;                    //!< [BIT]    Enable SPC (Short PWM Code) for this pin (NOT SUPPORTED YET)
        TUint8          au8ViewCfg[SENT_NIBBLE_MAX];    //!< [Index]  Incoming nibble sorting (e.g. pointer in au8ViewCfg[0] determines where the first nibble goes)
        TUint16         u16StatusStickyTime;            //!< [ms]     Amount of time a status persists until it is healed again
    } TCoreSentInitCfg;

    //--------------------------------------------------------------------------------------------------
    //! @brief          Initialization function for SENT pin
    //! @param[in]      ePin                - [ENU] SENT Pin
    //! @param[in]      cptInitCfg          - [PNT] Pointer to the configuration structure for initialization
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_MAXIMUM           - Invalid value for SENT_NIBBLE_MAX
    //! @retval         R_NOT_INITIALIZED   - Driver tasks have not been initialized
    //! @retval         R_UNKNOWN           - Unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentInit( EPin ePin, const TCoreSentInitCfg* cptInitCfg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get status of SENT pin
    //! @param[in]      ePin                - [ENU] SENT Pin
    //! @retval         R_OKAY              - SENT pin is okay
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_NOT_INITIALIZED   - Pin has not been initialized before
    //! @retval         R_FRAME_SYN         - SENT pin is not synchronized
    //! @retval         R_UNKNOWN           - Unknown status or error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentGetStatus( EPin ePin );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get last status/communication nibble
    //! @param[in]      ePin                - [ENU] Pin
    //! @param[out]     pu8StaCom           - [NUM] Status/communication nibble
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_NOT_INITIALIZED   - Pin has not been initialized before
    //! @retval         R_FRAME_SYN         - SENT pin is not synchronized
    //! @retval         R_UNKNOWN           - Unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentGetStaCom( EPin ePin, TUint8* pu8StaCom );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get last fast data message as 32-bit value
    //! @note           Least-significant nibble (LSN) of 32-bit value is first nibble of message
    //!                 e.g. 0x00654321
    //!                          \_/\_/
    //!                           |  |
    //!                           |  Data 3 to 1
    //!                           Data 6 to 4
    //! @param[in]      ePin                - [ENU]  Pin
    //! @param[out]     pu32Data            - [NUM]  Fast Data as single 32-bit value
    //! @param[out]     pu32Timestamp       - [10ns] Timestamp
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_NOT_INITIALIZED   - Pin has not been initialized before
    //! @retval         R_FRAME_SYN         - SENT pin is not synchronized
    //! @retval         R_UNKNOWN           - Unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentGetFastDataVal( EPin ePin, TUint32* pu32Data, TUint32* pu32Timestamp );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get last fast data message
    //! @param[in]      ePin                - [ENU]  Pin
    //! @param[out]     au8Data             - [NUM]  Fast Data as array of 8-bit values
    //! @param[out]     pu32Timestamp       - [10ns] Timestamp
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_NOT_INITIALIZED   - Pin has not been initialized before
    //! @retval         R_FRAME_SYN         - SENT pin is not synchronized
    //! @retval         R_UNKNOWN           - Unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentGetFastDataArr( EPin ePin, TUint8 au8Data[SENT_NIBBLE_MAX], TUint32* pu32Timestamp );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get last serial data message
    //! @param[in]      ePin                - [ENU] Pin
    //! @param[out]     ptMsg               - [STU] Serial data message incl. message ID
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_NOT_INITIALIZED   - Pin has not been initialized before
    //! @retval         R_FRAME_SYN         - SENT pin is not synchronized
    //! @retval         R_UNKNOWN           - Unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentGetSerialData( EPin ePin, TSentSerialMsg* ptMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief          De-initialization function for SENT pin
    //! @param[in]      ePin                - [ENU] Pin
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_NULL_POINTER      - Null pointer
    //! @retval         R_PARAMETER         - Invalid parameter has been passed
    //! @retval         R_UNKNOWN           - Unknown error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSentDeInit( EPin ePin );

#endif // COMPILER_SWITCH_SENT
#endif // __ITFCORESENT__
