//**************************************************************************************************
/*!
@file    ItfBoardCenUnjoBc.h
@brief   CEN Unjo Family
@date    19.05.2022
@author  HYDAC/ASN
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENUNJOBC__
  #define __ITFBOARDCENUNJOBC__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>
   #ifdef COMPILER_SWITCH_FAM_UNJO

    #define COMPILER_SWITCH_CANBUS
        #define _CS_CANBUS_2_
    #define COMPILER_SWITCH_FORCE_FEATURE

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
        CAN_RATE_10K    = 10,
        CAN_RATE_20K    = 20,
        CAN_RATE_25K    = 25,
        CAN_RATE_50K    = 50,
        CAN_RATE_100K   = 100,
        CAN_RATE_125K   = 125,
        CAN_RATE_250K   = 250,
        CAN_RATE_500K   = 500,
        CAN_RATE_800K   = 800,
        CAN_RATE_1000K  = 1000
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
        CBUS1_HWBUF_RCV0,    //!< 14 - Receive hardware buffer
        CBUS1_HWBUF_RCV1,    //!< 15 - Receive hardware buffer
        CBUS1_HWBUF_RCV2,    //!< 16 - Receive hardware buffer
        CBUS1_HWBUF_RCV3,    //!< 17 - Receive hardware buffer
        CBUS1_HWBUF_RCV4,    //!< 18 - Receive hardware buffer
        CBUS1_HWBUF_RCV5,    //!< 19 - Receive hardware buffer
        CBUS1_HWBUF_RCV6,    //!< 20 - Receive hardware buffer
        CBUS1_HWBUF_RCV7,    //!< 21 - Receive hardware buffer
        CBUS1_HWBUF_SND0,    //!< 22 - Send hardware buffer
        CBUS1_HWBUF_SND1,    //!< 23 - Send hardware buffer
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
      IDX_MAX
    };

    #define FIRST_OUTPUT_PIN IDX_07                   //!< Output start
    #define FIRST_MULTI_PIN  IDX_07                   //!< Multi start
    #define SYSPIN_MAX       23                       //!< Maximum of the system pin

    #define PIN_OVER_ALL     (IDX_MAX + SYSPIN_MAX)   //!< Of all pins

    //! Ecu Pins
    typedef enum
    {
        PIN_SYS = IDX_00,   //!<

        PIN_A1  = IDX_01,   /**< A/D/MM.1, Analog/Digital/MultiMode input*/
        PIN_A2  = IDX_02,   /**< A/D/MM.2, Analog/Digital/MultiMode input*/
        PIN_A3  = IDX_03,   /**< A/D/MM.3, Analog/Digital/MultiMode input*/
        PIN_A4  = IDX_04,   /**< A/D/MM.4, Analog/Digital/MultiMode input*/

        PIN_F1  = IDX_05,   /**< NODID/AI.1, Node-ID 1 / Analog In */
        PIN_F2  = IDX_06,   /**< NODID/AI.2, Node-ID 2 / Analog In */

        PIN_G1  = IDX_07,   /**< DO/AI.3, HS/LS On/PWM Amp/Volt In */
        PIN_H1  = IDX_08,   /**< DO/AI.4, HS/LS On/PWM Amp/Volt In */
        PIN_H2  = IDX_09,   /**< DO/TI/DI.1, LS On/PWM / PWD(Timer)/Dig In */
        PIN_G2  = IDX_10,   /**< DO/TI/DI.2, LS On/PWM / PWD(Timer)/Dig In */

        PIN_C3  = IDX_11,   /**< SENT/TI/DX.1, SENT/PWD(Timer)/Digital Input/Output */
        PIN_C4  = IDX_12,   /**< SENT/TI/DX.2, SENT/PWD(Timer)/Digital Input/Output */

        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;

    typedef enum
    {//
        PINRSL_NA,          //!< 0  - Voltage variable: not available
        PINRSL_5V,          //!< 2  - Voltage variable: 5V ref
        PINRSL_32V,         //!< 3  - Voltage variable: 32V ref
        PINRSL_RAT5V,       //!< 4  - Ratiometric Voltage variable: 5V ref
        PINRSL_100K,        //!< 5  - Resistor variable: 100 kilo Ohm ref
        PINRSL_2K,          //!< 6  - Resistor variable: 2 kilo Ohm ref
        PINRSL_4000MA,      //!< 7  - Current variable: 4000 mA ref
        PINRSL_25MA,        //!< 8  - Current variable: 25 mA Ohm ref
        PINRSL_NODE_ID,     //!< 9  - Node ID
        PINRSL_NODE_ID_V    //!< 10 - Node ID as Volatage

    }EPinRsl;

    //! Pin supply
    enum
    {
        PINSUPPLY_NA,                   //!< 0 - No sensor voltage PIN supply
        PINSUPPLY_RAT                   //!< 1 - voltage measurement proportional to sensor supply voltage
    };

    #define PINSUPPLY_UBAT  PINSUPPLY_RAT //!< deprecated, just for compatibility

    // System Pins
    #define PIN_SYS_BAT             (IDX_MAX)    //!< for the Hydac-Family
    #define PIN_SYS_K15             (IDX_MAX+1)  //!< for the Hydac-Family
    #define PIN_SYS_TEMP            (IDX_MAX+2)  //!< for the Hydac-Family
    #define PIN_SYS_REF             (IDX_MAX+3)  //!< for the Hydac-Family

    #define PIN_SYS_TEM_BC          (IDX_MAX+4)  //!< Unjo
    #define PIN_SYS_TEM_BD          (IDX_MAX+5)  //!< Unjo
    #define PIN_SYS_TEM_IGBT        (IDX_MAX+6)  //!< Unjo
    #define PIN_SYS_TEM_MTR         (IDX_MAX+7)  //!< Unjo
    #define PIN_SYS_BAT_TRM         (IDX_MAX+8)  //!< Unjo
    #define PIN_SYS_REF_VBSSNS      (IDX_MAX+9)  //!< Unjo
    #define PIN_SYS_REF_24V         (IDX_MAX+10) //!< Unjo
    #define PIN_SYS_REF_3V3         (IDX_MAX+11) //!< Unjo
    #define PIN_SYS_DC_LNK          (IDX_MAX+12) //!< Unjo
    #define PIN_SYS_CUR_U           (IDX_MAX+13) //!< Unjo
    #define PIN_SYS_CUR_V           (IDX_MAX+14) //!< Unjo
    #define PIN_SYS_CUR_W           (IDX_MAX+15) //!< Unjo
    #define PIN_SYS_STO_1           (IDX_MAX+16) //!< Unjo
    #define PIN_SYS_STO_2           (IDX_MAX+17) //!< Unjo
    #define PIN_SYS_STO_OTE         (IDX_MAX+18) //!< Unjo
    #define PIN_SYS_HVIL_IN         (IDX_MAX+19) //!< Unjo
    #define PIN_SYS_SPWR5V0         (IDX_MAX+20) //!< Unjo
    #define PIN_SYS_SPWRADJ         (IDX_MAX+21) //!< Unjo
    #define PIN_SYS_HVIL_OUT        (IDX_MAX+22) //!< Unjo

    #define PIN_SYS_START  PIN_SYS_BAT          //!< for the Hydac-Family
    #define PIN_SYS_END    PIN_SYS_SPWRADJ      //!< Unjo
    #define PIN_HST_END    PIN_SYS_END          //!< end


    //! PIN general configuration types from PDT (Is also an MST-Interface)
    typedef enum
    {
        PINTYP_NA       =  _PINTYP_NA,          //!< Type: [-]      Not available
        PINTYP_DIN      =  _PINTYP_DIN,         //!< Type: [0/1]    Digital input
        PINTYP_VIN      =  _PINTYP_VIN,         //!< Type: [mV]     Voltage input
        PINTYP_RES      =  _PINTYP_RES,         //!< Type: [Ohm]    Resistive configuration
		PINTYP_CIN      =  _PINTYP_CIN,         //!< Type: [mA]     Current input
		PINTYP_FIN      =  _PINTYP_FIN,         //!< Type: [Hz]     Frequency input
        PINTYP_DOU      =  _PINTYP_DOU,         //!< Type: [0/1]    Digital output
        PINTYP_PWM      =  _PINTYP_PWM,         //!< Type: [duty]   PWM output
        PINTYP_PWM_DUAL =  _PINTYP_PWM_DUAL,    //!< Type: [duty]   PWM output dual pins with one low side switch
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

    #ifdef COMPILER_SWITCH_TAR_HW
        //--------------------------------------------------------------------------------------------------
        //! @brief      Use selective Wake Up Pattern (via CAN)
        //! @param      boUse
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreUseSelectiveWup( TBoolean boUse );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Shutdown from selective Wake Up Pattern
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreShutdownFromSelectiveWup( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set K15 digital thresholds
        //! @param[in]  u16K15HiThr     - [mV] high threshold
        //! @param[in]  u16K15LowThr    - [mV] low threshold
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSetK15DThresholds( TUint16 u16K15HiThr, TUint16 u16K15LowThr );
    #endif

    #endif

#endif
