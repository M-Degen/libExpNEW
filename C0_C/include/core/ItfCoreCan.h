//**************************************************************************************************
/*!
@file  	    ItfCoreCan.h
@brief	    CAN Interface
@date       21.03.2012
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCORECAN__
  #define __ITFCORECAN__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreBoard.h>

    #define CAN_DATA_LENGTH     8

    //! Receive message
    typedef struct
    {
        TUint8  au8Data[CAN_DATA_LENGTH];   //!< Data buffer
        TUint8  u8Dlc;                      //!< Data length code
        TUint8  u8Xtd;                      //!< :=FALSE  11bit-Identifier, :=TRUE  29bit-Identifier
        TUint32 u32Id;                      //!< Identifier
    }TRcvMsg;

    //! Transmit message
    typedef struct
    {
        TUint8  au8Data[CAN_DATA_LENGTH];   //!< Data buffer
        TUint8  u8Dlc;                      //!< Data length code
        TUint8  u8Xtd;                      //!< :=FALSE  11bit-Identifier, :=TRUE  29bit-Identifier
        TUint32 u32Id;                      //!< Identifier
    }TSndMsg;

    //! CAN message
    typedef struct
    {
        TUint8  au8Data[CAN_DATA_LENGTH];   //!< Data buffer
        TUint8  u8Dlc;                      //!< Data length code
        TUint8  u8Xtd;                      //!< :=FALSE  11bit-Identifier, :=TRUE  29bit-Identifier
        TUint32 u32Id;                      //!< Identifier
    }TCanMsg;

    //! CAN format
    typedef enum
    {
        DATA_INTEL,                 //! 0 LSB (least significant bit) Format for the CAN variable  (early: LSB_FORMAT)
        DATA_MOTOROLA,              //! 1 MSB (most significant bit) Format for the CAN variable   (early: MSB_FORMAT)
        DATA_ECU                    //! 2 --   pure ecu
    }ECanFormat;

    //! Fifo type
    typedef enum
    {
        CAN_FIFO_RCV,               //!< CAN Fifo Receive Message
        CAN_FIFO_SND                //!< CAN Fifo Send Message
    }ECanFifoType;

    #ifdef COMPILER_SWITCH_TAR_PC

        #define PEAK_NAME_STR_LEN  64

        //! PEAK CAN devices
        typedef enum
        {
            PEAK_DEVICE_PCI,        //!< 0 - PCAN-PCI
            PEAK_DEVICE_USB,        //!< 1 - PCAN-USB
            PEAK_DEVICE_VIRTUAL,    //!< 2 - Virtual PCAN nets
            PEAK_DEVICE_NA          //!< 3 - None
        } EPeakDevice;

        //! PEAK CAN channels
        typedef enum
        {
            PEAK_INTERN,            //!< 0 - Internal channel
            PEAK_CHA_1,             //!< 1 - Device channel 1
            PEAK_CHA_2,             //!< 2 - Device channel 2
            PEAK_CHA_3,             //!< 3 - Device channel 3
            PEAK_CHA_4              //!< 4 - Device channel 4
        } EPeakChan;

    #endif

    #ifdef COMPILER_SWITCH_CANBUS

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get the associated CAN bus number for given CAN hardware buffer number eHwBuf
    //! @details        Valid values are only returned if the CAN HW buffer identified by eHwBuf is initialized on the system.\n
    //!                 If given HW Buffer is not configured this will return CAN_BUS_MAX.
    //! @param[in]      eHwBuf      -  [ENU] CAN hardware buffer
    //! @return         CAN bus number(CAN_BUS_MAX=invalid eHwBuf or CAN Bus not ready)
    //--------------------------------------------------------------------------------------------------
    extern ECanBus eCoreGiveCanBusNo( ECBusHwBuf eHwBuf );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return the status from the can bus
    //! @param[in]  eCanBus        - CAN-Handle (CAN_BUS_0, CAN_BUS_1)
    //! @param[out] pcu8RxErrCnt   - value of the receive error counter
    //! @param[out] pcu8TxErrCnt   - value of the transmit error counter
    //! @retval     R_OKAY           - everything fine
    //! @retval     R_WARN           - controller is in BUS WARN state
    //! @retval     R_NOACT          - controller is in BUS OFF  state
    //! @retval     R_EMPTY          - null pointer has been passed
    //! @retval     R_SUPPORT        - wrong channel number has been passed
    //! @retval     R_CONFIG         - the given channel has not been initialized
    //! @retval     R_UNKNOWN        - unknown error (normally not possible)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCanStatus( ECanBus eCanBus, TUint8 *const pcu8RxErrCnt, TUint8 *const pcu8TxErrCnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get status for given Hardware Buffer eHwBuf
    //! @param[in]      eHwBuf      - [ENU] CAN hardware buffer
    //! @retval         R_OKAY      - CAN bus and hardware buffer are ready
    //! @retval         R_CONFIG    - HW Buffer not valid/CAN not [yet] available
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGiveCanHwBufStatus( ECBusHwBuf eHwBuf );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Return available send calls available for the given HW buffer in the current task cycle
    //! @param[in]  eHwBuf
    //! @param[out] pu8MaxCntPerCyc - maximal possible CAN send calls per cycle, 0 if eHwBuf not initialized
    //! @return     remaining CAN send calls this cycle, 0 if eHwBuf not initialized
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreCanSndHwBufFeeCntPerCyc( ECBusHwBuf eHwBuf, TUint8 *pu8MaxCntPerCyc );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Send Messages out via the ECBusHwBuf
    //! @param[in]      eSndBuf             - [ENU] use that hardware send buffer
    //! @param[out]     ptSndMsg            - [PNT] Pointer to the send that message out
    //! @retval         R_OKAY              - Functions execute without error
    //! @retval         R_OVERFLOW          - CAN-HW-FIFO is full - no data has been transmitted        -> Set the DM_CBUSx_HOVERF_SNDx fault
    //! @retval         R_NOACT             - No Action - Hardware send count per task cycle is reached
    //! @retval         R_UNKNOWN           - Unknown internal device error
    //! @retval         R_NULL_POINTER      - NULL pointer
    //! @retval         R_ADDRESS           - wrong block address
    //! @retval         R_CONFIG            - HW Buffer not valid/CAN not [yet] available
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSndCanSndHwBuf( ECBusHwBuf eSndBuf, TSndMsg *ptSndMsg );

    //--------------------------------------------------------------------------------------------------
    //! @brief Returns unhandled CAN receive messages from the given HW buffer
    //! @details
    //! The function returns CAN messages received by the given HW buffer eRcvBuf in the last cycle
    //! which have no corresponding predefined CAN Signal Record (CSR), SW buffer or protocol. \n
    //! If R_OKAY is returned the receive message is copied to the ptRcvMsg pointer and deleted from the buffer. \n
    //! Call the function as long as R_OKAY is returned to process all messages.
    //! If no [more] messages are available the function returns R_EMPTY. \n
    //! The buffer is cleared each cycle, so the function should be used every cycle to get all unhandled messages.
    //! @param[in] eRcvBuf - [ENU] the queried hardware receive buffer
    //! @param[out] ptRcvMsg - [PNT] Pointer to the receive message
    //! @retval R_OKAY - A receive message was found and successfully copied to the ptRcvMsg pointer
    //! @retval R_EMPTY - The are no more receive messages in this buffer
    //! @retval R_NULL_POINTER - NULL pointer
    //! @retval R_CONFIG - eRcvBuf is not valid
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreRcvCanNoPreDefineRcvMsg( ECBusHwBuf eRcvBuf, TRcvMsg *ptRcvMsg );

    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @note       This function is deprecated - please use ePcCanClientSetNetName() instead
        //! @brief      Rename the Pc Can client name (default-Name is "PCANLight_SIM")
        //! @param[in]  pchName     - client name
        //! @param[in]  u8CanBusNo  - Can bus number
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPcCanClientRename( TChar *pchName, TUint8 u8CanBusNo );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Remove all PC CAN clients from driver
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPcCanClientRemove( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Suppress all positive PC CAN client reports and warnings to the console window
        //!             Used PCANLight_SIM
        //!             -> Client: ECU-C0-Application
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPcCanClientInfoSuppress( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @note       This function is not supported anymore
        //! @retval     R_SUPPORT
        //--------------------------------------------------------------------------------------------------
        extern ERetVal ePcCanClientCloseAll( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the PC CAN client's net name
        //! @param[in]  u8CanNo     - CAN bus number
        //! @param[in]  cpchName    - CAN client's new net name
        //! @retval     R_OKAY          - everything fine
        //! @retval     R_MAXIMUM       - name has been shortened due too string limit
        //! @retval     R_PARAMETER     - invalid CAN bus index
        //! @retval     R_NULL_POINTER  - null pointer has been passed
        //--------------------------------------------------------------------------------------------------
        extern ERetVal ePcCanClientSetNetName( TUint8 u8CanNo, const TChar *cpchName );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the PC CAN client's device
        //! @param[in]  u8CanNo     - CAN bus number
        //! @param[in]  eDevice     - CAN client's new device
        //! @retval     R_OKAY          - everything fine
        //! @retval     R_PARAMETER     - invalid CAN bus index
        //! @retval     R_RANGE         - invalid CAN device
        //! @retval     R_NULL_POINTER  - null pointer has been passed
        //--------------------------------------------------------------------------------------------------
        extern ERetVal ePcCanClientSetDevice( TUint8 u8CanNo, EPeakDevice eDevice );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the PC CAN client's HW channel
        //! @param[in]  u8CanNo     - CAN bus number
        //! @param[in]  eChannel    - CAN client's new channel
        //! @retval     R_OKAY          - everything fine
        //! @retval     R_PARAMETER     - invalid CAN bus index
        //--------------------------------------------------------------------------------------------------
        extern ERetVal ePcCanClientSetChannel( TUint8 u8CanNo, EPeakChan eChannel );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Extend PC CAN client reports
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPcCanClientInfoExtend( TVoid );

    #endif
    #endif

#endif
