//**************************************************************************************************
/*!
@file      ItfBoardCenTtc3x.h
@brief     CEN TTC3x Family
@date      23.08.2013
@author    HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENTTC3X__
  #define __ITFBOARDCENTTC3X__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>
   #ifdef COMPILER_SWITCH_FAM_TTC3X

    #define COMPILER_SWITCH_BSP_DIAGSTATE_MACHINE
    #define COMPILER_SWITCH_FLASH_SETTING
    #define COMPILER_SWITCH_SEC_APP

    #define COMPILER_SWITCH_INTERNAL_FLASH_ACCESS

    #define COMPILER_SWITCH_FORCE_FEATURE

    #define COMPILER_SWITCH_MAIN_CORE_EMC_BREAK

    #define COMPILER_SWITCH_CANBUS

    #ifdef COMPILER_SWITCH_SUBFAM_TTC32
      #define _CS_CANBUS_2_
    #else
      #define _CS_CANBUS_1_
    #endif

    //! CAN bus
    typedef enum
    {
        CAN_BUS0,           //!< For the TTC30 & TTC32
        #ifdef _CS_CANBUS_2_
        CAN_BUS1,           //!< Only for the TTC32
        #endif
        CAN_BUS_MAX         //!< Maximum
    }ECanBus;

    //! CAN bit rate
    typedef enum
    {
        CAN_RATE_100K       = _CAN_RATE_100K,   //!<  100 kBaud
        CAN_RATE_125K       = _CAN_RATE_125K,   //!<  125 kBaud
        CAN_RATE_250K       = _CAN_RATE_250K,   //!<  250 kBaud
        CAN_RATE_500K       = _CAN_RATE_500K,   //!<  500 kBaud
        CAN_RATE_800K       = _CAN_RATE_800K,   //!<  800 kBaud
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
        CBUS0_HWBUF_SND3,    //!< 11 - Send hardware buffer
        CBUS0_HWBUF_SND4,    //!< 12 - Send hardware buffer
        CBUS0_HWBUF_SND5,    //!< 13 - Send hardware buffer
        #ifdef COMPILER_SWITCH_SUBFAM_TTC32
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
        CBUS1_HWBUF_SND3,    //!< 25 - Send hardware buffer
        CBUS1_HWBUF_SND4,    //!< 26 - Send hardware buffer
        CBUS1_HWBUF_SND5,    //!< 27 - Send hardware buffer
        #endif
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
        IDX_17,
        IDX_18,
        IDX_19,
        IDX_20,
        IDX_21,
        IDX_22,
        IDX_23,
        IDX_24,
        IDX_25,
        IDX_26,
        IDX_27,
        IDX_28,
        IDX_29,
        IDX_30,
        IDX_MAX
    };

    #define FIRST_OUTPUT_PIN IDX_15                   //!< Output start
    #define FIRST_MULTI_PIN  IDX_01                   //!< Multi start
    #define SYSPIN_MAX       5                        //!< Maximum of the system pin

    #define PIN_OVER_ALL     (IDX_MAX + SYSPIN_MAX)   //!< Of all pins

    //! Ecu Pins
    typedef enum
    {
        PIN_SYS = IDX_00,
        PIN_J4  = IDX_01,
        PIN_H4  = IDX_02,
        PIN_E4  = IDX_03,
        PIN_D4  = IDX_04,
        PIN_C4  = IDX_05,
        PIN_B4  = IDX_06,
        PIN_A4  = IDX_07,
        PIN_A3  = IDX_08,
        PIN_G4  = IDX_09,
        PIN_F4  = IDX_10,
        PIN_E3  = IDX_11,
        PIN_D3  = IDX_12,
        PIN_C3  = IDX_13,
        PIN_B3  = IDX_14,
        PIN_H1  = IDX_15,
        PIN_G1  = IDX_16,
        PIN_F1  = IDX_17,
        PIN_E1  = IDX_18,
        PIN_D1  = IDX_19,
        PIN_C1  = IDX_20,
        PIN_K1  = IDX_21,
        PIN_J1  = IDX_22,
        PIN_B1  = IDX_23,
        PIN_A1  = IDX_24,
        PIN_K2  = IDX_25,
        PIN_J2  = IDX_26,
        PIN_H2  = IDX_27,
        PIN_G2  = IDX_28,
        PIN_F2  = IDX_29,
        PIN_E2  = IDX_30,
        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;

    //! Safety pin
    typedef enum
    {
        PIN_SAFETY_SW_NA,   //!< No safety switch is installed
        PIN_SAFETY_SW_0,    //!< PIN_B1
        PIN_SAFETY_SW_1     //!< PIN_A1
    }ESafetyPin;

    //! Voltage reference types
    enum
    { //
        PINRSL_NA,                      //!< 0 - Voltage variable: not available
        PINRSL_5V,                      //!< 1 - Voltage variable: 5V ref
        PINRSL_10V                      //!< 2 - Voltage variable: 10V ref
    };

    //! Pin supply
    enum
    {
        PINSUPPLY_NA,                   //!< 0 - No sensor voltage PIN supply
        PINSUPPLY_RAT                   //!< 1 - voltage measurement proportional to sensor supply voltage
    };

    #define PINSUPPLY_UBAT  PINSUPPLY_RAT //!< deprecated, just for compatibility

    // System Pins
    #define PIN_SYS_BAT    (IDX_MAX)    //!< for the 30x-Family
    #define PIN_SYS_K15    (IDX_MAX+1)  //!< for the 30x-Family
    #define PIN_SYS_TEMP   (IDX_MAX+2)  //!< for the 30x-Family
    #define PIN_SYS_REF    (IDX_MAX+3)  //!< for the 30x-Family
    #define PIN_SYS_S0     (IDX_MAX+4)  //!< for the 30x-Family

    #define PIN_SYS_START  PIN_SYS_BAT  //!< for the 30x-Family
    #define PIN_SYS_END    PIN_SYS_S0   //!< for the 30x-Family
    #define PIN_HST_END    PIN_SYS_END  //!< end


    //! PIN general configuration types from PDT
    typedef enum
    {
        PINTYP_NA        =  _PINTYP_NA,         //!< Type: [-]     Not available
        PINTYP_DIN       =  _PINTYP_DIN,        //!< Type: [0/1]   Digital input
        PINTYP_VIN       =  _PINTYP_VIN,        //!< Type: [mV]    Voltage input
        PINTYP_RES       =  _PINTYP_RES,        //!< Type: [Ohm]   Resistive configuration
        PINTYP_CIN       =  _PINTYP_CIN,        //!< Type: [µA]    Current input
        PINTYP_FIN       =  _PINTYP_FIN,        //!< Type: [Hz]    Frequency input
        PINTYP_PUL       =  _PINTYP_PUL,        //!< Type: [µs]    Read pulse value input
        PINTYP_CNT       =  _PINTYP_CNT,        //!< Type: [cnt]   Counter input
        PINTYP_CPX       =  _PINTYP_CPX,        //!< Type: [STU]   Complex input
        PINTYP_INC       =  _PINTYP_INC,        //!< Type: [cnt]   Incremental input with 2 pins
        PINTYP_DOU       =  _PINTYP_DOU,        //!< Type: [0/1]   Digital output
        PINTYP_PWM       =  _PINTYP_PWM,        //!< Type: [duty]  PWM output
        PINTYP_LED       =  _PINTYP_LED,        //!< Type: [0/1]   LED output
        PINTYP_PVG       =  _PINTYP_PVG,        //!< Type: [%/100] Percent of Ubat [1500..8500]
        PINTYP_VOU       =  _PINTYP_VOU         //!< Type: [mV]    Voltage output
    }EAppPinTyp;

    //! Resistor
    typedef enum
    {
        PINRES_NA,          //!< 0 - Resistor: Option not there
        PINRES_PULLUP,      //!< 1 - Resistor: Pull Up   - 10K Ohm PTD standard value
        PINRES_PULLDO,      //!< 2 - Resistor: Pull Down - 10K Ohm PTD standard value
        PINRES_CFG_NA       //!< 3 - Resistor: Configuration not option
    }EAppPinRes;

    //! Critical Mode
    typedef enum
    {
        CIO_NA,             //!< 0 - not applicable
        CIO_SAFESTA,        //!< 1 - ecu enter the safe state
        CIO_NOREACT         //!< 2 - no reaction - ecu don't enter the safe state, if possible
    }ECioState;

    #define PINPWM_1000        1000     //!< PWM frequency
    #define PINPWM_500          500     //!< PWM frequency
    #define PINPWM_333          333     //!< PWM frequency
    #define PINPWM_250          250     //!< PWM frequency
    #define PINPWM_200          200     //!< PWM frequency
    #define PINPWM_166          166     //!< PWM frequency
    #define PINPWM_142          142     //!< PWM frequency
    #define PINPWM_125          125     //!< PWM frequency
    #define PINPWM_111          111     //!< PWM frequency
    #define PINPWM_100          100     //!< PWM frequency
    #define PINPWM_90            90     //!< PWM frequency
    #define PINPWM_83            83     //!< PWM frequency
    #define PINPWM_76            76     //!< PWM frequency
    #define PINPWM_71            71     //!< PWM frequency
    #define PINPWM_66            66     //!< PWM frequency
    #define PINPWM_62            62     //!< PWM frequency
    #define PINPWM_58            58     //!< PWM frequency
    #define PINPWM_55            55     //!< PWM frequency
    #define PINPWM_52            52     //!< PWM frequency
    #define PINPWM_50            50     //!< PWM frequency
    #define PINPWM_47            47     //!< PWM frequency
    #define PINPWM_45            45     //!< PWM frequency
    #define PINPWM_43            43     //!< PWM frequency
    #define PINPWM_41            41     //!< PWM frequency
    #define PINPWM_40            40     //!< PWM frequency
    #define PINPWM_38            38     //!< PWM frequency
    #define PINPWM_37            37     //!< PWM frequency
    #define PINPWM_35            35     //!< PWM frequency
    #define PINPWM_34            34     //!< PWM frequency
    #define PINPWM_33            33     //!< PWM frequency
    #define PINPWM_32            32     //!< PWM frequency
    #define PINPWM_31            31     //!< PWM frequency
    #define PINPWM_30            30     //!< PWM frequency
    #define PINPWM_29            29     //!< PWM frequency
    #define PINPWM_28            28     //!< PWM frequency
    #define PINPWM_27            27     //!< PWM frequency
    #define PINPWM_26            26     //!< PWM frequency
    #define PINPWM_25            25     //!< PWM frequency
    #define PINPWM_24            24     //!< PWM frequency
    #define PINPWM_23            23     //!< PWM frequency
    #define PINPWM_22            22     //!< PWM frequency
    #define PINPWM_21            21     //!< PWM frequency
    #define PINPWM_20            20     //!< PWM frequency
    #define PINPWM_19            19     //!< PWM frequency
    #define PINPWM_18            18     //!< PWM frequency
    #define PINPWM_17            17     //!< PWM frequency
    #define PINPWM_16            16     //!< PWM frequency
    #define PINPWM_15            15     //!< PWM frequency

    #define PINTHR_DFLT  (U16_MAX-1)    //!< Threshold set to default value [Low: 2000mV, High:  3500mV]
                                        //!<                                [Low: 5000µA, High: 15000µA]

    #define PINTHR_VIN_THR_LO   2000    //!< [mV] Threshold low
    #define PINTHR_VIN_THR_HI   3500    //!< [mV] Threshold high
    #define PINTHR_CIN_THR_LO   5000    //!< [µA] Threshold low
    #define PINTHR_CIN_THR_HI  15000    //!< [µA] Threshold high

    #define ECU_PWM_DOU_MAX_DUTY 60000  //!<  92,25% Duty Cycle [0xEA60]

    #define PWM_FREQDFLT_VAL 200        //!< Default frequency

    //! HDT - Pin layout
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
                                                       //!<        Check whether PWM pin has been installed first.
                                                       //!< [%*100] PVG-channel will be initialized in percent * 100 ( 1000..9000 )
    }TAppPin; // 16 BYTE => ca. 18*52=780 BYTE


    //! Diagnostic state
     typedef enum
     {
         DIAGSTATE_DISABLED  = 0x00,             //!< Diagnostic state machine is disabled
         DIAGSTATE_INIT      = 0x03,             //!< Diagnostic state machine is in init state
         DIAGSTATE_MAIN      = 0x06,             //!< Diagnostic state machine is in main state
         DIAGSTATE_SAFE      = 0x09,             //!< Diagnostic state machine is in safe state
         DIAGSTATE_UNDEF     = 0xFF              //!< Undefined  - BSP call is wrong
     }EDiagState;

     //! Diagnostic error code structure
     typedef struct
     {
         TUint8  u8ErrorCode;                     //!< BSP value: error code
         TUint8  u8DeviceNum;                     //!< BSP value: device number which caused error
         TUint16 u16FaultyValue;                  //!< BSP value: value which caused the error
     }TDiaErrorCode;

     //! Status function for diagnostic state machine
     typedef struct
     {
         EDiagState    eDiagState;             //!<  current state of the diagnostic state machine
         TDiaErrorCode tDiagError;             //!<  error codes of the diagnostic state machine
     }TDiagStatus;

     //--------------------------------------------------------------------------------------------------
     //! @brief      Get the diagnose status
     //! @param[out] ptDiagSta - Diagnose Struct (NULL Save)
     //! @retval     R_OKAY  - fine
     //! @retval     R_UNDEF - struct is not valid
     //--------------------------------------------------------------------------------------------------
     extern ERetVal eCoreGetEcuDiagStatus( TDiagStatus *ptDiagSta );

     //! Ecu reset status
     typedef enum
     {
         ECU_RST_STAT_PORST      = 0,   //!< Reset status for a power on reset
         ECU_RST_STAT_WD         = 1,   //!< Reset status for a window watchdog reset
         ECU_RST_STAT_WDT        = 2,   //!< Reset status for a watchdog timer reset
         ECU_RST_STAT_PHASE      = 3,   //!< Function don't call before the while loop in the main()-Function or 'vAppSafetyInit()
         ECU_RST_STAT_SW         = 4,   //!< Reset status for a Software reset
         ECU_RST_STAT_UNKOWN_ERR = 5    //!< Reset status UNKOWN Error
     }EEcuRst;

     //--------------------------------------------------------------------------------------------------
     //! @brief   Suppress the ecu auto reset if the last ecu shut off was not okay (e.g. a watchdog break)
     //!          Call in the main before the while-loop or in the vAppSafetyInit()
     //! @param   R_OKAY  - okay
     //! @param   R_PHASE - call not in the 'main() before the while-loop' or in the 'vAppSafetyInit()'
     //--------------------------------------------------------------------------------------------------
     extern ERetVal eCoreSuppressEcuAutoReset( TVoid );

     //--------------------------------------------------------------------------------------------------
     //! @brief Get the cause for an ecu reset
     //!        Call in the main before the while-loop or in the vAppSafetyInit()
     //!
     //!     if( R_OKAY == eCoreSuppressEcuAutoReset() ) // Avoid the auto reaction by MATCH Core
     //!     {
     //!         if( ECU_RST_STAT_PORST != eCoreGetEcuResetStatus() ) // Get the last reset status
     //!         {
     //!             // User Code
     //!             return;        // Leave the main()
     //!         }
     //!     }
     //!     else { return; }       // Leave the main() - only an else for safety reasons
     //!
     //!     while( 1 )
     //!     {
     //!         vCoreMain(  &ePhase, ...
     //!
     //! @retval  reset cause - see EEcuRst
     //--------------------------------------------------------------------------------------------------
     extern EEcuRst eCoreGetEcuResetStatus( TVoid );

     #ifdef COMPILER_SWITCH_TAR_PC
         //--------------------------------------------------------------------------------------------------
         //! @brief      Set the ecu reset reason
         //! @param      eEcuRst
         //--------------------------------------------------------------------------------------------------
         extern TVoid vCoreSimEcuResetStatus( EEcuRst eEcuRst );
     #endif

     //--------------------------------------------------------------------------------------------------
     //! @brief      ReInit the IoDriver - Please take care to use that function
     //! @param[in]  pfeReInitIoDriver  - The function call to re init
     //!             NOTE: Don't use that function in combination with the Critical-Input/Output Pin setting.
     //!             NOTE: This function destroys the match safety reaction - but it is possible to managed that by the own.
     //!             NOTE: Keep the function call (error_callback, notify_callback) so short as possible. It is forbidden to use string processing function,
     //!                   therefore all print functions are forbidden
     //!
     //!     #ifdef COMPILER_SWITCH_ECU_TTC77
     //!     #include <IO_Driver.h>
     //!     #include <DIAG_Constants.h>
     //!     #include <DIAG_Functions.h>
     //!
     //!     TUint8 u8ErrCallback( TUint8 u8DiagState,  TUint8 u8WatchdogState, DIAG_ERRORCODE* const ptErr )
     //!     {
     //!         if(ptErr->error_code == DIAG_E_ADC_SENSOR_SUPPLY && ptErr->device_num == IO_PIN_116 ) { return DIAG_ERR_NOACTION;   }
     //!         else                                                                                  { return DIAG_ERR_SAFESTATE;  }
     //!     }
     //!
     //!     ERetVal eReInitIoDriver( TVoid )
     //!     {
     //!         static IO_DRIVER_SAFETY_CONF s_tSafetyCfg;
     //!
     //!         s_tSafetyCfg.command_period      = 10000;  // Task cycle time;
     //!         s_tSafetyCfg.glitch_filter_time  = 180;
     //!         s_tSafetyCfg.timeout_count       = 3;
     //!         s_tSafetyCfg.CPU_check_loopcount = 1;
     //!         s_tSafetyCfg.error_callback      = u8ErrCallback;
     //!         s_tSafetyCfg.wdt_timeout         = s_tSafetyCfg.command_period * 2;
     //!
     //!         if( IO_E_OK == IO_Driver_Init( &s_tSafetyCfg ) ){ return R_OKAY;    }
     //!         else                                            { return R_UNKNOWN; }
     //!     }
     //!     #endif
     //!
     //!     TVoid main( TVoid )
     //!     {
     //!         EMainPhase ePhase = MAIN_CORE_START_UP;
     //!
     //!         vCoreReInitIoDriver( eReInitIoDriver  );
     //!
     //!         while( 1 )
     //!         {...
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreReInitIoDriver( ERetVal (*pfeReInitIoDriver)( TVoid ) );


     //! Bsp Diag Error Code
     typedef struct
     {
         TUint8  u8ErrorCode;                           //!< The error code
         TUint8  u8DeviceNum;                           //!< The device number which caused the error. This can either be an internal Device Diagnostic devices
         TUint32 u32FaultyValue;                        //!< The value which caused the error
     }TBspDiagErrCode;

     #define BSP_DIAG_ERR_NOACTION       0x1            //!< take no action (ignore the error)
     #define BSP_DIAG_ERR_SAFESTATE      0x9            //!< enter the safe state (switch off all outputs)

     //--------------------------------------------------------------------------------------------------
     //! @brief      u8CorePostSafetyCb
     //!             NOTE: This function destroys the match safety reaction - but it is possible to managed that by the own.\n
     //!             NOTE: no effect if there is any pin configured with a non-dflt safety reaction
     //! @param[in]  u8DiagState      - Diagnostic state
     //! @param[in]  u8CoreReaction   - is the core 'match'-reaction
     //! @param[in]  pctErr           - Bsp diagnostic error code
     //! @return     new safe state reaction - [BSP_DIAG_ERR_SAFESTATE or  BSP_DIAG_ERR_NOACTION]
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreSetPostSafetyCbFct( TUint8 (*pfu8CorePostSafetyCb)( TUint8 u8DiagState, TUint8 u8CoreReaction, TBspDiagErrCode *const pctErr ) );

     //--------------------------------------------------------------------------------------------------
     //! @brief      Show Ecu Diag Information - ( SafeState is a print warning, all other are just a print )
     //! @param[in]  boShowOnlyIfSafeState - Give only the status information if 'Safe-State' is active
     //--------------------------------------------------------------------------------------------------
     extern TVoid vCoreShowEcuDiagInfo( TBoolean boShowOnlyIfSafeState );


     //--------------------------------------------------------------------------------------------------
     //! @brief    Pre Read from the NvMem for the Safety Setting (call for the main while loop)
     //!           (Opposition function - eCoreWriteNvmForSafety)
     //!           Work only by a new start (don't work by a soft reset)
     //! #define   SAFETY_DATA_ADDRESS      2000  // Address for the safety option data field
     //! #define   SAFETY_DATA_LEN          6     // Length of data field
     //! #define   SAFETY_TIMEOUT_READ      100   // Timeout for the safety read
     //!
     //! TVoid vPreReadDataForSafetyOptions( TVoid )
     //! {
     //!    TUint16 u16I = 0;
     //!
     //!    if( TRUE == boCoreEcuNewStart() )
     //!    {// is new ecu start ( no soft reset)
     //!        while( R_OKAY != eCorePreReadNvmForSafety( SAFETY_DATA_ADDRESS, SAFETY_DATA_LEN, (TUint8*)g_achData ) )
     //!        {
     //!            u16I++;
     //!
     //!            if( u16I >= SAFETY_TIMEOUT_READ )
     //!            {
     //!                for( u16I = 0; u16I < SAFETY_DATA_LEN; u16I++ )
     //!                {
     //!                    g_achData[u16I] = 0xFF;
     //!                }
     //!                break; // jump out
     //!            }
     //!        }
     //!    }
     //! }
     //!
     //! TVoid main( TVoid )
     //! {
     //!    EMainPhase ePhase = MAIN_CORE_START_UP;
     //!    vCoreInitEcuStatisticTim( gEcu_tSys.tSil.u16EcuTaskTime, 100, &g_tStatistic );
     //!    vPreReadDataForSafetyOptions();
     //!
     //!    while( 1 )
     //!    {
     //!        vCoreMain(  &ePhase, ...
     //!
     //!
     //! @param    u32Address      - [NUM] NvMem address        (no address check)
     //! @param    u32DataLen      - [NUM] Count a write bytes  (no address check)
     //! @param    pu8Byte         - [PTR] Byte pointer
     //! @retval   R_OKAY          - Finish
     //! @retval   R_BUSY          - Busy - not break if the Nvm is defect (The timeout must handle in the application )
     //! @retval   R_PHASE         - the function is called to a wrong place
     //! @retval   R_NULL_POINTER  - pu8Byte is null
     //--------------------------------------------------------------------------------------------------
     extern ERetVal eCorePreReadNvmForSafety( TUint32 u32Address, TUint32 u32DataLen, TUint8 *pu8Byte );

     //--------------------------------------------------------------------------------------------------
     //! @brief    Write to NvMem in combination with eCorePreReadNvmForSafety(...)
     //!
     //! ERetVal eAppShutDown( TCoreInp *ptHcpInp, TCoreOut *ptHcpOut )
     //! {
     //!     ERetVal eRet = eCoreWriteNvmForSafety( SAFETY_DATA_ADDRESS, SAFETY_DATA_LEN, (TUint8*)m_achWriteData );
     //!     if( eRet != R_OKAY )
     //!     {// Not R_OKAY
     //!         if( m_u16WriteSafetyTimeout++ > x )  // x is the timeout time
     //!         {
     //!             m_u16WriteSafetyTimeout = 0;
     //!             return R_TIMEOUT;
     //!         }
     //!     }
     //!     else
     //!     {// R_OKAY
     //!         m_u16WriteSafetyTimeout = 0;
     //!     }
     //!     return eRet;
     //! }
     //!
     //! @param    u32Address   - [NUM] NvMem address
     //! @param    u32DataLen   - [NUM] Count a write bytes
     //! @param    pu8Byte      - [PTR] Byte pointer
     //! @retval   R_OKAY          - Finish
     //! @retval   R_BUSY          - Busy - not break if the Nvm is defect (The timeout must handled in the application. )
     //! @retval   R_USERADDRESS   - Nvm address used by the system
     //! @retval   R_NULL_POINTER  - pu8Byte is null
     //--------------------------------------------------------------------------------------------------
     extern ERetVal eCoreWriteNvmForSafety( TUint32 u32Address, TUint32 u32DataLen, TUint8 *pu8Byte );

     //! StartUp Test Control
     typedef enum
     {
         STARTUP_TEST_INHIBIT,    //!< inhibit startup tests
         STARTUP_TEST_ACTIVATE    //!< activate startup tests
     }EStatUpTestCtrl;

     //--------------------------------------------------------------------------------------------------
     //! @brief     Inhibits the startup tests
     //!            It is only allowed to call this function before the startup tests
     //!            are being executed!
     //!            Example:
     //!             call eCoreStartupTestCtrl( STARTUP_TEST_INHIBIT  ) in the vAppSafetyInit(..)
     //!             call eCoreStartupTestCtrl( STARTUP_TEST_ACTIVATE ) in the eAppPreStart(..)...vAppRun(..)
     //!                 like:  IO_ADC_Get( IO_ADC_UBAT, &u16Temp, &boFresh ) ==  IO_E_OK )
     //!                        {
     //!                             if(u16Temp > 8000 ) // TTC30: User Manual "full operation" until 8V
     //!                             {
     //!                                 eCoreStartupTestCtrl( STARTUP_TEST_ACTIVATE ) // call only ones!
     //!                             }
     //!                         }
     //! @param     eCtrl       - control command for inhibiting/activating startup tests
     //! @retval    R_OKAY      - Everything fine
     //! @retval    R_PARAMETER - Invalid parameter has been passed to this function
     //! @retval    R_UNKNOWN   - Function has not been called before startup tests are being executed
     //--------------------------------------------------------------------------------------------------
     extern ERetVal eCoreStartupTestCtrl( EStatUpTestCtrl eCtrl );

    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set diagnose status
        //! @param[in]  ptDiagSta      - Diagnose struct
        //! @retval     R_OKAY         - struct is valid
        //! @retval     R_NULL_POINTER - ptDiagSta is a NULL pointer
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreSimSetEcuDiagStatus( TDiagStatus *ptDiaStatus );

        // D I A G N O S T I C   S T A T E   M A C H I N E   E R R O R   V A L U E S

        enum
        {
              DIAG_E_NOERROR                = 0,     //!< No error
              DIAG_E_ADC_LIMITS             = 1,     //!< An ADC limit was exceeded or underrun
              DIAG_E_ADC_5V2_SUPPLY         = 2,     //!< The 5.2V supply voltage deviates from its normal level
              DIAG_E_ADC_SENSOR_SUPPLY      = 3,     //!< The sensor supply voltage deviates from its normal level
              DIAG_E_ADC_KL30_MAIN          = 4,     //!< The KL30 voltage level exceeds or underrun its allowed limits
              DIAG_E_ADC_KL30_CPU           = 5,     //!< The KL30_CPU voltage level exceeds or underrun its allowed limits
              DIAG_E_OVER_TEMPERATURE       = 6,     //!< The board temperature exceeds its allowed range
              DIAG_E_MEM_USER_STACK         = 7,     //!< A memory block of the user stack is corrupted
              DIAG_E_MEM_REGISTER           = 8,     //!< Internal register values are corrupted
              DIAG_E_MEM_DSRAM              = 9,     //!< A memory block of the data S-RAM is corrupted
              DIAG_E_MEM_PSRAM              = 10,    //!< A memory block of the program S-RAM is corrupted
              DIAG_E_MEM_DPRAM              = 11,    //!< A memory block of the dual-port RAM is corrupted
              DIAG_E_MEM_ZeroFlag           = 12,    //!< The zero flag was mistakenly raised during a math operation
              DIAG_E_MEM_CarryFlag          = 13,    //!< The carry flag was mistakenly raised during a math operation
              DIAG_E_MEM_NegativeFlag       = 14,    //!< The negative flag was mistakenly raised during a math operation
              DIAG_E_MEM_OverflowFlag       = 15,    //!< The overflow flag was mistakenly raised during a math operation
              DIAG_E_MEM_SYS_STACK_OF       = 16,    //!< An overflow of the system stack occurred
              DIAG_E_MEM_SYS_STACK_UF       = 17,    //!< An underflow of the system stack occurred
              DIAG_E_MEM_SR0_TRAP           = 18,    //!< An SR0 trap occurred and all interrupts have been disabled
              DIAG_E_MEM_CLASS_B_TRAP       = 19,    //!< A class B trap occurred and all interrupts have been disabled
              DIAG_E_PWM_CURRENT_ZERO       = 20,    //!< Current measurement greater zero during startup phase
              DIAG_E_PWM_CURRENT_OFFSET     = 21,    //!< Offset of current measurement circuitry on PWM output not within limits
              DIAG_E_PWM_LIMITS_RANGE       = 22,    //!< Pulse width not within range on PWM output (outside min/max pulse)
              DIAG_E_PWM_LIMITS_TOL         = 23,    //!< Pulse width not within tolerance window on PWM output
              DIAG_E_PWM_PERIOD_MISMATCH    = 24,    //!< Period mismatch on PWM output
              DIAG_E_PWM_CURRENT            = 25,    //!< Current not within limits on current controlled input
              DIAG_E_PWM_CURRENT_DEAD_TIME  = 26,    //!< Set current not reached after dead time elapsed
              DIAG_E_PWM_CURRENT_OFFS_DRIFT = 27,    //!< Current offset too low (due to drift or HW defect)
              DIAG_E_PWD_LIMITS_FREQ        = 28,    //!< Frequency limit error on timer input or counter error on incremental/counter input
              DIAG_E_PWD_LIMITS_PULSE_WIDTH = 29,    //!< Pulse width limit error on timer input
              DIAG_E_CYCLE_TIME             = 30,    //!< Cycle time too high
              DIAG_E_RPP                    = 31,    //!< Insufficient gate drive on reverse polarity protection
              DIAG_E_EXT_WD                 = 32,    //!< External WD has activated the safe state
              DIAG_E_LS_PROT                = 33,    //!< Over-current condition on safety switch
              DIAG_E_OVD_STARTUP            = 34,    //!< Over voltage startup test has failed
              DIAG_E_OVD                    = 35,    //!< Over voltage detection has activated the safe state
              DIAG_E_SAFETY_SW_INT          = 36,    //!< Safety switch check error (internal switch)
              DIAG_E_SAFETY_SW_EXT          = 37,    //!< Safety switch check error (external switch)
              DIAG_E_SAFETY_SW_SHUT_OFF     = 38,    //!< Safety switch check failed during start-up
              DIAG_E_INVALID_DIAG_STATE     = 39,    //!< Invalid diagnostic state
              DIAG_E_INVALID_STARTUP_STATE  = 40,    //!< Invalid diagnostic state in startup state
              DIAG_E_INVALID_MAIN_STATE     = 41,    //!< Invalid diagnostic state in main state
              DIAG_E_WD_STARTUP             = 42,    //!< Watchdog startup test has failed
              DIAG_E_SR_LowNibble           = 43,    //!< The feedback value of the low nibble of the shift register is faulty
              DIAG_E_SR_HighNibble          = 44,    //!< The feedback value of the high nibble of the shift register is faulty
              DIAG_E_FREQ_STARTUP           = 45,    //!< Internal clock frequency drifts from its normal value
              DIAG_E_TIMEOUT                = 46,    //!< A timeout between diagnostic module and IO-Driver has occurred (for example driver functions of safety critical IO not called)
              DIAG_E_APPL_SAFE_STATE        = 47,    //!< Application requested to activate the safe state
              DIAG_E_PLL_VCO_NOT_LOCKED     = 48,    //!< The PLL/VCO lost its lock to the oscillator frequency.
              DIAG_E_SW_INTERNAL            = 49,    //!< Internal SW error detected, maybe SW or HW related
              DIAG_E_INIT_ERROR             = 50,    //!< Error during initialization of diagnostic state machine
              DIAG_E_MAX_ERRORCODES         = 51
        };

         // D I A G N O S T I C   S T A T E   M A C H I N E   S T A T E S
        #define DIAG_STATE_INIT        0x03    //!< Diagnostic state machine is in its initial state (safety-outputs not operational)
        #define DIAG_STATE_STARTUP     0x05    //!< Diagnostic state machine is in startup state performing startup tests (safety-outputs not operational)
        #define DIAG_STATE_MAIN        0x06    //!< Diagnostic state machine is in main state performing runtime tests (safety-outputs operational)
        #define DIAG_STATE_SAFE_STATE  0x09    //!< Diagnostic state machine is in safe state due to errors that have been detected (safety-outputs not operational)
        #define DIAG_STATE_DISABLED    0x00    //!< Diagnostic state machine is disabled, this means the IO-Driver has been configured NON-SAFETY

        #define DIAG_ERR_NOACTION       0x1    //!< Take no action (ignore the error)
        #define DIAG_ERR_SAFESTATE      0x9    //!< Enter the safe state (switch off all outputs)

       #endif

    #endif

#endif
