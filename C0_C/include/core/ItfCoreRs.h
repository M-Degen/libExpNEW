//**************************************************************************************************
/*!
@file  	    ItfCoreRs.h
@brief	    Communication Interface
@date       21.03.2012
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCORERS__
  #define __ITFCORERS__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreBoard.h>

    #ifdef COMPILER_SWITCH_RSBUS

    //! RS bit rate
    typedef enum
    {
        RS_RATE_2400  = 1,     //! Baud rate
        RS_RATE_9600  = 2,     //! Baud rate
        RS_RATE_19200 = 3,     //! Baud rate
        RS_RATE_115200 = 4     //! Baud rate
    }ERsRate;

    //! RS Parity
    typedef enum
    {
        RS_PARITY_NA,          //! No Parity
        RS_PARITY_EVEN,        //! Even Parity
        Rs_PARITY_ODD          //! Odd Parity
    }ERsPar;

    //! RS Stop bit
    typedef enum
    {
        RSSTOP_1,              //!< 1 Stop Bit
        RSSTOP_2               //!< 2 Stop Bit
    }ERsStop;

    //! RS Status
    typedef enum
    {
        RSSTA_OKAY,            //!< Okay
        RSSTA_BUFFER_FULL,     //!< SW receive queue is full and data has been lost
        RSSTA_OVERFLOW,        //!< HW receive buffer overrun
        RSSTA_PARITY           //!< parity check failed
    }ERsBusStaRead;

    #ifdef COMPILER_SWITCH_TAR_PC
    //--------------------------------------------------------------------------------------------------
    //! @brief      Change the rs bus port name
    //! @param[in]  pchComPort e.g. COM7  (COM6 is the system default)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eRsBusChangeComPort( TChar *pchComPort );
    #endif

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization RS Bus
    //! @note       (HW: open COM1, PC: open COM6 - can change with eRsBusChangeComPort(..))
    //! @param[in]  eBaudrate
    //! @param[in]  u8Dlc         Number of data bits per frame (1 .. 8)
    //! @param[in]  eRsPar        Parity configuration
    //! @param[in]  eStopBits     Number of stop bits per frame
    //! @retval     R_OKAY         - functions execute without error
    //! @retval     R_BUSY         - channel has been initialized before
    //! @retval     R_PARAMETER    - range invalid parameter has been passed
    //! @retval     R_UNKONW       - unknown error occurred
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eRsBusInit( ERsRate eBaudrate, TUint8 u8Dlc, ERsPar ePar, ERsStop eStopBits );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Deinitialization rS Bus
    //! @retval     R_OKAY            - functions execute without error
    //! @retval     R_RANGE           - eBus out of range
    //! @retval     R_NOT_INITIALIZED - the channel was not configured
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eRsBusDeInit( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Read RS-Bus
    //! @param[in]  u8DlcMax      Maximum size of data array (pu8Dat) ( optimized for <= 10 )
    //!                           - read bytes must be equal or higher - or the return value is R_EMMPTY
    //! @param[out] pu8Dat        Address where the read data shall be stored (address need)
    //! @param[out] pu8DlcRx      Actually read bytes        (null possible)
    //! @retval     R_OKAY         - functions execute without error
    //! @retval     R_EMPTY        - nothing is there
    //! @retval     R_NULL_POINTER - pu8Dat is NULL
    //! @retval     R_OVERFLOW     - HW receive buffer overrun
    //! @retval     R_INCONSISTENT - a framing error has been detected
    //! @retval     R_CHECKSUM     - parity check failed
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eRsBusRead( TUint8 u8DlcMax, TUint8 *pu8Dat, TUint8 *pu8DlcRx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Write RS-Bus
    //! @param[in]  pu8Dat         Address to the data which shall be written (address need)
    //! @param[in]  u8Dlc          Number of bytes in data array ( optimized for <= 10 )
    //! @param[out] pu8DlcTx       Actually written bytes (can be NULL)
    //! @retval     R_OKAY         - functions execute without error
    //! @retval     R_BUSY         - RS is busy
    //! @retval     R_RANGE        - eBus out of range
    //! @retval     R_NULL_POINTER - pu8Dat is NULL
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eRsBusWrite( TUint8 *pu8Dat, TUint8 u8Dlc, TUint8 *pu8DlcTx );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if the USB cable is connected
    //! @return     ERetVal
    //!                 R_OKAY      is connected
    //!                 R_COMMUNICA is not connected
    //!                 R_SUPPORT   function is not supported
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eRsBusIsConnected( void );

    #endif

#endif
