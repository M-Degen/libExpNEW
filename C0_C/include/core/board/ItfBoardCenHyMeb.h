//**************************************************************************************************
/*!
@file    ItfBoardCenHyMeb.h
@brief   CEN TTC3x Family
@date    16.08.2019
@author  HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENHYMEB__
  #define __ITFBOARDCENHYMEB__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>
   #ifdef COMPILER_SWITCH_FAM_HYMEB

    #define COMPILER_SWITCH_RSBUS

    #define COMPILER_SWITCH_CANBUS
      #define _CS_CANBUS_2_

    //! CAN bus
    typedef enum
    {
        CAN_BUS0,
		CAN_BUS1,
        CAN_BUS_MAX          //!< avoid the warning
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
        CBUS1_HWBUF_RCV0,    //!<  14 - Receive hardware buffer
        CBUS1_HWBUF_RCV1,    //!<  15 - Receive hardware buffer
        CBUS1_HWBUF_RCV2,    //!<  16 - Receive hardware buffer
        CBUS1_HWBUF_RCV3,    //!<  17 - Receive hardware buffer
        CBUS1_HWBUF_RCV4,    //!<  18 - Receive hardware buffer
        CBUS1_HWBUF_RCV5,    //!<  19 - Receive hardware buffer
        CBUS1_HWBUF_RCV6,    //!<  20 - Receive hardware buffer
        CBUS1_HWBUF_RCV7,    //!<  21 - Receive hardware buffer
        CBUS1_HWBUF_SND0,    //!<  22 - Send hardware buffer
        CBUS1_HWBUF_SND1,    //!<  23 - Send hardware buffer
        CBUS1_HWBUF_SND2,    //!< 24 - Send hardware buffer
        CBUS1_HWBUF_SND3,    //!< 25 - Send hardware buffer => n.a.only 3 buffers are available
        CBUS1_HWBUF_SND4,    //!< 26 - Send hardware buffer => n.a.
        CBUS1_HWBUF_SND5,    //!< 27 - Send hardware buffer => n.a.
        HWBUF_NA = 0xFF      //!<      No hardware buffer
    }ECBusHwBuf;


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
      IDX_09,
      IDX_10,
      IDX_11,
      IDX_12,
      IDX_13,
      IDX_14,
      IDX_15,
      IDX_16,
      IDX_MAX
    };

    #define FIRST_OUTPUT_PIN IDX_09                   //!< Output start
    #define FIRST_MULTI_PIN  IDX_MAX                   //!< Multi start
    #define SYSPIN_MAX       4                        //!< Maximum of the system pin

    #define PIN_OVER_ALL     (IDX_MAX + SYSPIN_MAX)   //!< Of all pins

    //! Ecu Pins
    typedef enum
    {
    	PIN_SYS = IDX_00,

        // G01
        PIN_01  = IDX_01,   //!< Analog Input
		PIN_02  = IDX_02,   //!< Analog Input
		PIN_03  = IDX_03,   //!< Analog Input
		PIN_04  = IDX_04,   //!< Analog Input

        // G02
		PIN_05  = IDX_05,   //!< Digital Input
		PIN_06  = IDX_06,   //!< Digital Input
		PIN_07  = IDX_07,   //!< Digital Input
		PIN_08  = IDX_08,   //!< Digital Input

        // G03
		PIN_09  = IDX_09,   //!< PWM HS
		PIN_10  = IDX_10,   //!< PWM HS
		PIN_11  = IDX_11,   //!< PWM HS
		PIN_12  = IDX_12,   //!< PWM HS

        // G04
		PIN_13  = IDX_13,   //!< Digital Output HS
		PIN_14  = IDX_14,   //!< Digital Output HS
		PIN_15  = IDX_15,   //!< Digital Output HS
		PIN_16  = IDX_16,   //!< Digital Output HS

        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;

    typedef enum
    {//
        PINRSL_NA,                      //!< 0 - Voltage variable: not available
        PINRSL_5V,                      //!< 1 - Voltage variable: 5V ref
        PINRSL_10V,                     //!< 2 - Voltage variable: 10V ref
        PINRSL_30V                      //!< 3 - Voltage variable: 30V ref

    }EPinRsl;

    // System Pins
    #define PIN_SYS_BAT    (IDX_MAX)    //!< for the Hydac-Family
    #define PIN_SYS_K15    (IDX_MAX+1)  //!< for the Hydac-Family
    #define PIN_SYS_TEMP   (IDX_MAX+2)  //!< for the Hydac-Family
    #define PIN_SYS_REF    (IDX_MAX+3)  //!< for the Hydac-Family

    #define PIN_SYS_START  PIN_SYS_BAT   //!< for the Hydac-Family
    #define PIN_SYS_END    PIN_SYS_REF   //!< for the Hydac-Family
    #define PIN_HST_END    PIN_SYS_END   //!< end


    //! Pin supply
    enum
    {
        PINSUPPLY_NA,                       //!< 0 - No sensor voltage PIN supply
        PINSUPPLY_UBAT                      //!< 1 - Voltage PIN supply sensor '0'
    };

    //! PIN general configuration types from PDT (Is also an MST-Interface)
    typedef enum
    {
        PINTYP_NA   =  _PINTYP_NA,          //!< Type: [-]      Not available
        PINTYP_DIN  =  _PINTYP_DIN,         //!< Type: [0/1]    Digital input
        PINTYP_VIN  =  _PINTYP_VIN,         //!< Type: [mV]     Voltage input
		PINTYP_CIN  =  _PINTYP_CIN,         //!< Type: [mA]     Current input
        PINTYP_DOU  =  _PINTYP_DOU,         //!< Type: [0/1]    Digital output
        PINTYP_PWM  =  _PINTYP_PWM,         //!< Type: [duty]  PWM output
    }EAppPinTyp;

    #define CFG_NA         0xFF             //!< Configuration is not possible

    #define PINTHR_DFLT  (U16_MAX-1)        //!< Threshold set to default value [VIN_D Low: 2000, High:  3500 Unit: mV]
                                            //!                                 [CIN_D Low: 5000, High: 15000 Unit: mA]

    #define PINTHR_VIN_THR_LO   2000        //! [mV] Threshold low
    #define PINTHR_VIN_THR_HI   3500        //! [mV] Threshold high
    #define PINTHR_CIN_THR_LO   5000        //! [µA] Threshold low
    #define PINTHR_CIN_THR_HI  15000        //! [µA] Threshold high

    #define ECU_PWM_DOU_MAX_DUTY 10000      //!< 92,25% Duty Cycle [0xEA60]

    //! Resistor
    typedef enum
    {
        PINRES_NA,                          //!< 0 - Resistor: Option not there
        PINRES_PULLUP,                      //!< 1 - Resistor: Pull Up   - 10K Ohm PTD standard value
        PINRES_PULLDO,                      //!< 2 - Resistor: Pull Down - 10K Ohm PTD standard value
        PINRES_CFG_NA                       //!< 3 - Resistor: Configuration not option
    }EAppPinRes;

    //! Critical Mode
    typedef enum
    {
        CIO_NA                                         //!< 0 - not applicable
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
        TUint8     u8Temp;                             //!< [DEF]  Reserve for the furture
        TUint16    u16VinRsl_PwmFreq_PvgInit;          //!< [DEF]  Voltage resolution
                                                       //!<        PINRSL_NA, PINRSL_5V ... PINRSL_32V
                                                       //!< [Hz]   frequency
                                                       //!<        PINPWM_NA, PINPWM_DFLT or NUM

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

    #endif

#endif
