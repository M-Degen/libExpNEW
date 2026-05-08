//**************************************************************************************************
/*!
@file    ItfBoardCenHyIcu.h
@brief   CEN TTC3x Family
@date    01.02.2019
@author  HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENHYICU__
  #define __ITFBOARDCENHYICU__

  #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>
  #ifdef COMPILER_SWITCH_FAM_HYICU

    #define COMPILER_SWITCH_CANBUS
      #define _CS_CANBUS_1_

    //! CAN bus
    typedef enum
    {
        CAN_BUS0,
        CAN_BUS_MAX         //!< avoid the warning
    }ECanBus;

    //! CAN bit rate
    typedef enum
    {
        CAN_RATE_100K       = _CAN_RATE_100K,   //!<  100 kBaud
        CAN_RATE_125K       = _CAN_RATE_125K,   //!<  125 kBaud
        CAN_RATE_250K       = _CAN_RATE_250K,   //!<  250 kBaud
        CAN_RATE_500K       = _CAN_RATE_500K,   //!<  500 kBaud
        CAN_RATE_1000K      = _CAN_RATE_1000K   //!< 1000 kBaud
    }EBitRate;

    //! CAN Bus hardware buffer
    typedef enum
    {
        CBUS0_HWBUF_RCV0,    //!<  0 - Receive hardware buffer
        CBUS0_HWBUF_RCV1,    //!<  1 - Receive hardware buffer
        CBUS0_HWBUF_RCV2,    //!<  2 - Receive hardware buffer
        CBUS0_HWBUF_RCV3,    //!<  3 - Receive hardware buffer
        CBUS0_HWBUF_RCV4,    //!<  4 - Receive hardware buffer
        CBUS0_HWBUF_RCV5,    //!<  5 - Receive hardware buffer
        CBUS0_HWBUF_RCV6,    //!<  6 - Receive hardware buffer
        CBUS0_HWBUF_RCV7,    //!<  7 - Receive hardware buffer
        CBUS0_HWBUF_SND0,    //!<  8 - Send hardware buffer
        CBUS0_HWBUF_SND1,    //!<  9 - Send hardware buffer
        CBUS0_HWBUF_SND2,    //!< 10 - Send hardware buffer
        CBUS0_HWBUF_SND3,    //!< 11 - Send hardware buffer => n.a.only 3 buffers are available
        CBUS0_HWBUF_SND4,    //!< 12 - Send hardware buffer => n.a.
        CBUS0_HWBUF_SND5,    //!< 13 - Send hardware buffer => n.a.
        HWBUF_NA = 0xFF      //!<      No hardware buffer
    }ECBusHwBuf;


#ifdef COMPILER_SWITCH_ECU_HYICU_P1
    //! Pin index
    enum
    {
      IDX_00,
      IDX_01,
      IDX_02,
      IDX_03,
      IDX_04,
      IDX_05,
      IDX_06,
      IDX_07,
      IDX_08,
      IDX_MAX
    };
#else
        // TODO COMPILER_SWITCH_ECU_HYICU_P2
    //! Pin index
    enum
    {
      IDX_00,
      IDX_01,
      IDX_02,
      IDX_03,
      IDX_04,
      IDX_05,
      IDX_06,
      IDX_07,
      IDX_MAX
    };
#endif

#ifdef COMPILER_SWITCH_ECU_HYICU_P1
    #define FIRST_OUTPUT_PIN IDX_04                   //!< Output start
    #define FIRST_MULTI_PIN  IDX_07                   //!< Multi start
    #define SYSPIN_MAX       4                        //!< Maximum of the system pin
#else
    #define FIRST_OUTPUT_PIN IDX_04                   //!< Output start
    #define FIRST_MULTI_PIN  IDX_07                   //!< Multi start
    #define SYSPIN_MAX       4                        //!< Maximum of the system pin
#endif

    #define PIN_OVER_ALL     (IDX_MAX + SYSPIN_MAX)   //!< Of all pins

#ifdef COMPILER_SWITCH_ECU_HYICU_P1
    //! Ecu Pins
    typedef enum
    {
        PIN_SYS = IDX_00,
        PIN_01  = IDX_01,
        PIN_02  = IDX_07,
        PIN_03  = IDX_03,
        PIN_04  = IDX_02,
        PIN_07  = IDX_04,
        PIN_10  = IDX_08,
        PIN_20  = IDX_05,
        PIN_21  = IDX_06,
        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;
#else
    // TODO COMPILER_SWITCH_ECU_HYICU_P2
    //! Ecu Pins
    typedef enum
    {
        PIN_SYS = IDX_00,
        PIN_01  = IDX_01,
        PIN_02  = IDX_02,
        PIN_03  = IDX_03,
        PIN_05  = IDX_07,
        PIN_06  = IDX_04,
        PIN_20  = IDX_05,
        PIN_21  = IDX_06,
        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;
#endif

    typedef enum
    { //
            PINRSL_NA,                      //!< 0 - Voltage variable: not available
            PINRSL_D1,                      //!< 1 - Digital output1 PIN02: D1=D2; PIN07: 0V = Low, Vcc = High
            PINRSL_D2,                      //!< 2 - Digital output2 PIN02: D1=D2; PIN07: 2V = Low, 4V  = High
            PINRSL_4V5,                     //!< 3 - Analog output 0.5 .. 5.5V
            #ifndef COMPILER_SWITCH_ECU_HYICU_P1
            PINSUPPLY_5V0,                      //!< 4 - Analog output 5V
            #endif
            #ifdef COMPILER_SWITCH_ECU_HYICU_P1
            PINRSL_Vin                      //!< 5 - Analog output Vin (not supported yet)
            #else
            PINRSL_VIN,                      //!< 5 - Analog output Vin
            PINRSL_OFF                       //!< 6 - Analog output off
            #endif
    }EPinRsl;

	// System Pins
    #define PIN_SYS_BAT    (IDX_MAX)    //!< for the Hydac-Family
    #define PIN_SYS_K15    (IDX_MAX+1)  //!< for the Hydac-Family
    #define PIN_SYS_TEMP   (IDX_MAX+2)  //!< for the Hydac-Family
    #define PIN_SYS_REF    (IDX_MAX+3)  //!< for the Hydac-Family

    #define PIN_SYS_START  PIN_SYS_BAT   //!< for the Hydac-Family
    #define PIN_SYS_END    PIN_SYS_REF   //!< for the Hydac-Family
    #define PIN_HST_END    PIN_SYS_END   //!< end

    //! PIN general configuration types from PDT (Is also an MST-Interface)
    typedef enum
    {
        PINTYP_NA   =  _PINTYP_NA,        //!< Type: [-]      Not available
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        PINTYP_DIN  =  _PINTYP_DIN,       //!< Type: [0/1]    Digital input
        #endif
        PINTYP_VIN  =  _PINTYP_VIN,       //!< Type: [mV]     Voltage input
        PINTYP_CIN  =  _PINTYP_CIN,       //!< Type: [mA]     Current input
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        PINTYP_DOU  =  _PINTYP_DOU,       //!< Type: [0/1]    Digital output
        #endif
        PINTYP_LED  =  _PINTYP_LED,       //!< Type: [0/1]    LED output
        PINTYP_VOU  =  _PINTYP_VOU,       //!< Type: [mV]     Voltage output
        PINTYP_RAW  =  _PINTYP_RAW,       //!< Type: [raw]    Value input
        PINTYP_COU  =  _PINTYP_COU,       //!< Type: [mA]     Current output
        PINTYP_RAT  =  _PINTYP_RAT,       //!< Type: [mA]     Ratiometric input Vin/Vcc
        #ifdef COMPILER_SWITCH_ECU_HYICU_P1
        PINTYP_SIN  =  _PINTYP_SIN,       //!< Type: [1/min]  Motor Speed input
        #endif
        PINTYP_PIN  =  _PINTYP_PIN,       //!< Type: [µm]     Valve position input
        PINTYP_POU  =  _PINTYP_POU        //!< Type: [µm]     Valve position output
    }EAppPinTyp;

    #define CFG_NA         0xFF       //!< Configuration is not possible
    #define PINTHR_DFLT  (U16_MAX-1)  //!< Threshold set to default value [VIN_D Low: 2000, High: 3500 Unit: mV]
                                      //!                                 [RAW_D Low: 2000  High: 3500 Unit: raw]
                                      //!                                 [PER_D Low: 2000, High: 3500 Unit: %/100]
                                      //!                                 [CIN_D Low: 2000, High: 3500 Unit: mA]
                                      //!                                 [RAT_D Low: 2000, High: 3500 Unit: %/100]
                                      //!                                 [PIN_D Low: 2000, High: 3500 Unit: µm]
                                      //!                                 [SIN_D Low: 2000, High: 3500 Unit: 1/min]

    //! Resistor
    typedef enum
    {
        PINRES_CFG_NA          //!< 0 - Resistor: Option not there
    }EAppPinRes;

    //! Critical Mode
    typedef enum
    {
       CIO_NA                 //!< 0 - not applicable
    }ECioState;

    typedef struct
     {
        TUint8     u8Idx;                              //!< [DEF]  ECU layer index
        TUint16    u16PinNo;                           //!< [NUM]  PIN number
        EAppPinCfg ePinCfg;                            //!< [ENU]  Cfg PIN mapping
        EAppPinTyp ePinTyp;                            //!< [ENU]  PIN configuration
        ECioState  eSafety;                            //!< [ENU]  Safety setting
        EAppPinRes eResPos;                            //!< [ENU]  Resistor position
        TUint16    u16DinThrLo;                        //!< [mV]   Digital threshold LOW
                                                       //!< [DEF]  PINTHR_NA, PINTHR_DFLT or NUM
        TUint16    u16DinThrHi;                        //!< [mV]   Digital threshold HIGH
                                                       //!< [DEF]  PINTHR_NA, PINTHR_DFLT or NUM
        TUint8     u8VinSupply_PwmFbIdx_CntMode;       //!< [DEF]  Voltage var ref
                                                       //!< [DEF]  PINSUPPLY_NA, PINSUPPLY_S1, PINSUPPLY_S2
                                                       //!< [DEF]  PWM current feedback (Ecu Board Index)
                                                       //!<        PINFB_NA, PIN_xxx
        TUint16    u16VinRsl_PwmFreq_PvgInit;          //!< [DEF]  Voltage resolution
                                                       //!<        PINRSL_NA, PINRSL_5V ... PINRSL_32V
                                                       //!< [Hz]   frequency
                                                       //!<        PINPWM_NA, PINPWM_DFLT or NUM#
                                                       //!< [%*100] PVG-channel will be initialized in percent * 100 ( 1000..9000 )
    }TAppPin; // 16 BYTE => ca. 18*52=780 BYTE

    typedef enum
    {
        DIAGSTATE_UNDEF     = 0xFF                     //!<  need that only to keep that interface
    }EDiagState;

    typedef struct
    {
        TUint8 u8DiagState;                            //!<  need that only to keep that interface
    }TDiagStatus;

    //! Diagnostic error code structure
    typedef struct
    {
        TUint8  u8ErrorCode;                           //!<  need that only to keep that interface
        TUint8  u8DeviceNum;                           //!<  need that only to keep that interface
        TUint16 u16FaultyValue;                        //!<  need that only to keep that interface
    }TDiaErrorCode;

    typedef struct
    {
        TInt16 i16RawMin;                              //!<  min digit value
        TInt16 i16RawMax;                              //!<  max digit value
        TInt16 i16ScaleMin;                            //!<  min physical value
        TInt16 i16ScaleMax;                            //!<  min physical value
        TUint8 u8Unit;                                 //!<  unit (0->no unit available, 1->bar, 2->psi, 3->MPa)
        TUint8 u8Decimals;                             //!<  decimals after comma
    }THpiRange;

    //-------------------------------------------------------------------------------------------------
    //! @brief      Write data to FRAM
    //! @param[in]  u32Address   - [NUM] FRAM-Address
    //! @param[in]  u32DataLen   - [NUM] Count of write bytes
    //! @param[out] pu8Byte      - [PTR] Pointer to data that specifies the input stream
    //! @retval     R_OKAY       - Write was OK
    //! @retval     R_BUSY       - FRAM is busy. No data were written to the FRAM.
    //! @retval     R_ADDRESS    - Invalid address offset or range. No data were written to the FRAM.
    //! @retval     R_UNKNOWN    - other mistake
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreFramWrite( TUint32 u32Address, TUint32 u32DataLen, TUint8 *pu8Byte);

    //-------------------------------------------------------------------------------------------------
    //! @brief      Read data from FRAM
    //! @param[in]  u32Address   - [NUM] NvMem-Address
    //! @param[in]  u32DataLen   - [NUM] Count of read bytes
    //! @param[out] pu8Byte      - [PTR] Pointer to data that specifies the input stream
    //! @retval     R_OKAY       - Read was OK
    //! @retval     R_BUSY       - FRAM is busy. No data were read from the FRAM.
    //! @retval     R_ADDRESS    - Invalid address offset or range. No data were read from the FRAM.
    //! @retval     R_UNKNOWN    - other mistake
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreFramRead( TUint32 u32Address, TUint32 u32DataLen, TUint8 *pu8Byte);

    //--------------------------------------------------------------------------------------------------
    //! @brief    Give the Fram status
    //! @retval   R_OKAY        - everything fine, driver is idle
    //! @retval   R_BUSY        - a read or a write operation is ongoing, driver is busy
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreFramStatus( TVoid );

     #ifdef COMPILER_SWITCH_ECU_HYICU_P2

      //--------------------------------------------------------------------------------------------------
      //! @brief    Give the K15 status
      //! @TBoolean TRUE        K15 is on
      //! @TBoolean FALSE       K15 is off
      //--------------------------------------------------------------------------------------------------
      extern TBoolean boCoreK15Status( TVoid );

      //--------------------------------------------------------------------------------------------------
      //! @brief    Application shutdown trigger
      //! @TBoolean R_OKAY        core start shutdown process
      //! @TBoolean R_DEFAULT     There was a problem
      //--------------------------------------------------------------------------------------------------
      extern ERetVal eCoreShutdown( TVoid );

     #endif
    #endif

#endif
