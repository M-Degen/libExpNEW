//**************************************************************************************************
/*!
@file      ItfBoardCenTtc5x.h
@brief     CEN TTC5x family
@date      13.07.2010
@author    HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENTTC5X__
  #define __ITFBOARDCENTTC5X__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>
   #ifdef COMPILER_SWITCH_FAM_TTC5X

    #define COMPILER_SWITCH_BSP_DIAGSTATE_MACHINE

    #if defined(COMPILER_SWITCH_ECU_TTC60)|| defined(COMPILER_SWITCH_ECU_TTC90)
      #define COMPILER_SWITCH_MINI_MODUL
    #endif

    #ifdef COMPILER_SWITCH_ENV_CEN

       #define COMPILER_SWITCH_FLASH_SETTING
       #define COMPILER_SWITCH_FORCE_FEATURE

       #define COMPILER_SWITCH_INTERNAL_FLASH_ACCESS

       #define COMPILER_SWITCH_SEC_APP

       #define COMPILER_SWITCH_RSBUS
       #define COMPILER_SWITCH_LINBUS

       #define COMPILER_SWITCH_CANBUS
        #ifdef COMPILER_SWITCH_ECU_TTC94
           #define _CS_CANBUS_4_
        #else
           #define _CS_CANBUS_2_
        #endif

       #if defined(COMPILER_SWITCH_ECU_TTC90)|| defined(COMPILER_SWITCH_ECU_TTC94)
         #define COMPILER_SWITCH_INIT_WATCHDOG
       #endif

       //! Can bus list
       typedef enum
       {
           CAN_BUS0,                            //!< CAN bus 0
           CAN_BUS1,                            //!< CAN bus 1
           #ifdef _CS_CANBUS_4_
           CAN_BUS2,                            //!< CAN bus 2
           CAN_BUS3,                            //!< CAN bus 3
           #endif
           CAN_BUS_MAX                          //!< Max
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

       //! CAN bus hardware buffer
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

           #ifdef COMPILER_SWITCH_ECU_TTC94
           CBUS2_HWBUF_RCV0,    //!<  0 - Receive hardware buffer
           CBUS2_HWBUF_RCV1,    //!<  1 - Receive hardware buffer
           CBUS2_HWBUF_RCV2,    //!<  2 - Receive hardware buffer
           CBUS2_HWBUF_RCV3,    //!<  3 - Receive hardware buffer
           CBUS2_HWBUF_RCV4,    //!<  4 - Receive hardware buffer
           CBUS2_HWBUF_RCV5,    //!<  5 - Receive hardware buffer
           CBUS2_HWBUF_RCV6,    //!<  6 - Receive hardware buffer
           CBUS2_HWBUF_RCV7,    //!<  7 - Receive hardware buffer
           CBUS2_HWBUF_SND0,    //!<  8 - Send hardware buffer
           CBUS2_HWBUF_SND1,    //!<  9 - Send hardware buffer
           CBUS2_HWBUF_SND2,    //!< 10 - Send hardware buffer
           CBUS2_HWBUF_SND3,    //!< 11 - Send hardware buffer
           CBUS2_HWBUF_SND4,    //!< 12 - Send hardware buffer
           CBUS2_HWBUF_SND5,    //!< 13 - Send hardware buffer

           CBUS3_HWBUF_RCV0,    //!< 14 - Receive hardware buffer
           CBUS3_HWBUF_RCV1,    //!< 15 - Receive hardware buffer
           CBUS3_HWBUF_RCV2,    //!< 16 - Receive hardware buffer
           CBUS3_HWBUF_RCV3,    //!< 17 - Receive hardware buffer
           CBUS3_HWBUF_RCV4,    //!< 18 - Receive hardware buffer
           CBUS3_HWBUF_RCV5,    //!< 19 - Receive hardware buffer
           CBUS3_HWBUF_RCV6,    //!< 20 - Receive hardware buffer
           CBUS3_HWBUF_RCV7,    //!< 21 - Receive hardware buffer
           CBUS3_HWBUF_SND0,    //!< 22 - Send hardware buffer
           CBUS3_HWBUF_SND1,    //!< 23 - Send hardware buffer
           CBUS3_HWBUF_SND2,    //!< 24 - Send hardware buffer
           CBUS3_HWBUF_SND3,    //!< 25 - Send hardware buffer
           CBUS3_HWBUF_SND4,    //!< 26 - Send hardware buffer
           CBUS3_HWBUF_SND5,    //!< 27 - Send hardware buffer
           #endif
           HWBUF_NA = 0xFF      //!<    - No hardware buffer
       }ECBusHwBuf;
    #else

      // need for the simple can simulation

      typedef enum
      {
          HWBUF_NA = 0xFF       //!< No hardware buffer
      }ECBusHwBuf;

      typedef enum
      {
          CAN_BUS0,             //!< CAN bus 0
          CAN_BUS1,             //!< CAN bus 1
          CAN_BUS_MAX           //!< Max
      }ECanBus;

    #endif

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
        IDX_31,
        IDX_32,
        IDX_33,
        IDX_34,
        IDX_35,
        IDX_36,
        IDX_37,
        IDX_38,
        IDX_39,
        IDX_40,
        IDX_41,
        IDX_42,
        IDX_43,
        IDX_44,
        IDX_45,
        IDX_46,
        IDX_47,
        IDX_48,
        IDX_49,
        IDX_50,
        IDX_51,
        IDX_52,
        IDX_MAX
    };

    #define FIRST_OUTPUT_PIN    IDX_29                 //!< First output PIN
    #define FIRST_MULTI_PIN     IDX_29                 //!< First multiple PIN
    #define SYSPIN_MAX          7                      //!< System PIN

    #define PIN_OVER_ALL       (IDX_MAX + SYSPIN_MAX)  //!< All PINs

    //! PIN list
    typedef enum
    {
        PIN_SYS = IDX_00,
        PIN_152 = IDX_01,
        PIN_140 = IDX_02,
        PIN_151 = IDX_03,
        PIN_139 = IDX_04,
        PIN_150 = IDX_05,
        PIN_138 = IDX_06,
        PIN_149 = IDX_07,
        PIN_137 = IDX_08,
        PIN_126 = IDX_09,
        PIN_114 = IDX_10,
        PIN_125 = IDX_11,
        PIN_113 = IDX_12,
        PIN_124 = IDX_13,
        PIN_112 = IDX_14,
        PIN_123 = IDX_15,
        PIN_111 = IDX_16,
        PIN_263 = IDX_17,
        PIN_256 = IDX_18,
        PIN_262 = IDX_19,
        PIN_255 = IDX_20,
        PIN_261 = IDX_21,
        PIN_254 = IDX_22,
        PIN_260 = IDX_23,
        PIN_253 = IDX_24,
        PIN_275 = IDX_25,
        PIN_268 = IDX_26,
        PIN_274 = IDX_27,
        PIN_267 = IDX_28,
        PIN_118 = IDX_29,
        PIN_106 = IDX_30,
        PIN_117 = IDX_31,
        PIN_105 = IDX_32,
        PIN_116 = IDX_33,
        PIN_104 = IDX_34,
        PIN_115 = IDX_35,
        PIN_103 = IDX_36,
        PIN_144 = IDX_37,
        PIN_132 = IDX_38,
        PIN_143 = IDX_39,
        PIN_131 = IDX_40,
        PIN_142 = IDX_41,
        PIN_130 = IDX_42,
        PIN_141 = IDX_43,
        PIN_129 = IDX_44,
        PIN_120 = IDX_45,
        PIN_108 = IDX_46,
        PIN_119 = IDX_47,
        PIN_107 = IDX_48,
        PIN_122 = IDX_49,
        PIN_110 = IDX_50,
        PIN_121 = IDX_51,
        PIN_109 = IDX_52,
        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;

    #define START_BORD_CM_IDX   PIN_120     //!< IDX_45 - Start board PIN
    #define END_BORD_CM_IDX     PIN_107     //!< IDX_48 - End board PIN
    #define START_MIN_CM_IDX    PIN_122     //!< IDX_49 - Start mini module PIN
    #define END_MIN_CM_IDX      PIN_109     //!< IDX_52 - End mini module PIN

    //! Voltage reference types
    enum
    { //
        PINRSL_NA,           //!< 0 - Voltage variable: Not available
        PINRSL_5V,           //!< 1 - Voltage variable: 5V Ref
        PINRSL_10V,          //!< 2 - Voltage variable: 10V Ref
        PINRSL_15V,          //!< 3 - Voltage variable: 15V Ref
        PINRSL_20V,          //!< 4 - Voltage variable: 20V Ref
        PINRSL_25V,          //!< 5 - Voltage variable: 25V Ref
        PINRSL_30V,          //!< 6 - Voltage variable: 30V Ref
        PINRSL_32V,          //!< 7 - Voltage variable: 32V Ref
    };

    //! PIN supply
    enum
    {
        PINSUPPLY_NA,       //!< 0 - No sensor voltage PIN supply
        PINSUPPLY_S0,       //!< 1 - Voltage PIN supply sensor '0'
        PINSUPPLY_S1        //!< 2 - Voltage PIN supply sensor '1'
    };

    //! System PINs
    #define PIN_SYS_BAT    (IDX_MAX)    //!< System PIN battery
    #define PIN_SYS_K15    (IDX_MAX+1)  //!< System PIN K15
    #define PIN_SYS_TEMP   (IDX_MAX+2)  //!< System PIN temperature
    #define PIN_SYS_REF    (IDX_MAX+3)  //!< System PIN reference voltage
    #define PIN_SYS_S0     (IDX_MAX+4)  //!< System PIN Sensor supply 0
    #define PIN_SYS_S1     (IDX_MAX+5)  //!< System PIN Sensor supply 1
    #define PIN_SYS_S2     (IDX_MAX+6)  //!< System PIN Sensor supply variable

    #define PIN_SYS_START  PIN_SYS_BAT  //!<  Start of the system PINs
    #define PIN_SYS_END    PIN_SYS_S2   //!<  End of the system PINs
    #define PIN_HST_END    PIN_SYS_END  //!<  End

    //! PIN general configuration types from PDT
    typedef enum
    {
        PINTYP_NA        = _PINTYP_NA,         //!< Type: [-]     Not available
        PINTYP_DIN       = _PINTYP_DIN,        //!< Type: [0/1]   Digital input
        PINTYP_VIN       = _PINTYP_VIN,        //!< Type: [mV]    Voltage input
        PINTYP_RES       = _PINTYP_RES,        //!< Type: [Ohm]   Resistive configuration
        PINTYP_CIN       = _PINTYP_CIN,        //!< Type: [µA]    Current input
        PINTYP_FIN       = _PINTYP_FIN,        //!< Type: [Hz]    Frequency input
        PINTYP_PUL       = _PINTYP_PUL,        //!< Type: [µs]    Read pulse value input
        PINTYP_CNT       = _PINTYP_CNT,        //!< Type: [cnt]   Counter input
        PINTYP_CPX       = _PINTYP_CPX,        //!< Type: [STU]   Complex input
        PINTYP_INC       = _PINTYP_INC,        //!< Type: [cnt]   Incremental input with 2 pins
        PINTYP_DOU       = _PINTYP_DOU,        //!< Type: [0/1]   Digital output
        PINTYP_PWM       = _PINTYP_PWM,        //!< Type: [duty]  PWM output
        PINTYP_PWM_DUAL  = _PINTYP_PWM_DUAL    //!< Type: [duty]  PWM output dual pins with one low side switch
    }EAppPinTyp;

    //! Resistor
    typedef enum
    {
        PINRES_NA,          //!< 0 - Resistor: Option not there
        PINRES_PULLUP,      //!< 1 - Resistor: Pull Up   - 10K Ohm PTD standard value (equal PINRES_PULLUP_10K)
        PINRES_PULLDO,      //!< 2 - Resistor: Pull Down - 10K Ohm PTD standard value (equal PINRES_PULLDO_10K)
        PINRES_PULLUP_10K,  //!< 3 - Resistor: Pull Up   - 10K Ohm
        PINRES_PULLDO_10K,  //!< 4 - Resistor: Pull Down - 10K Ohm
        PINRES_PULLDO_1K8,  //!< 5 - Resistor: Pull Down - 1.8K Ohm
        PINRES_PULLDO_110,  //!< 6 - Resistor: Pull Down - 110 Ohm
        PINRES_CFG_NA       //!< 7 - Resistor: Configuration not option
    }EAppPinRes;

    #define CIO_STATE_OPTION

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

    #define PINTHR_DFLT  (U16_MAX-1)    //!< Threshold set to default value [Low: 2000mV, High:  3500mV]
                                        //!<                                [Low: 5000µA, High: 15000µA]
    #define PINTHR_VIN_THR_LO   2000    //!< [mV] Threshold low
    #define PINTHR_VIN_THR_HI   3500    //!< [mV] Threshold high
    #define PINTHR_CIN_THR_LO   5000    //!< [µA] Threshold low
    #define PINTHR_CIN_THR_HI  15000    //!< [µA] Threshold high

    #define ECU_PWM_DOU_MAX_DUTY 60000  //!< 92,25% Duty Cycle [0xEA60]

    #define PWM_FREQDFLT_VAL 100        //!< Default frequency

    //! Critical Mode
    typedef enum
    {
        CIO_NA,             //!< 0 - not applicable
        CIO_SAFESTA,        //!< 1 - ecu enter the safe state
        CIO_NOREACT         //!< 2 - no reaction - ecu don't enter the safe state, if possible
    }ECioState;

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
         DIAGSTATE_CONFIG    = 0x05,             //!< Diagnostic state machine is in config state
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
         EDiagState    eWatchdogState;         //!<  current state of the watchdog CPU
         TDiaErrorCode tWatchdogError;         //!<  error codes of the watchdog CPU
     }TDiagStatus;

     //--------------------------------------------------------------------------------------------------
     //! @brief      Get the diagnose status
     //! @param[out] ptDiagSta - Diagnose Struct (NULL Save)
     //! @retval     R_OKAY  - fine
     //! @retval     R_UNDEF - struct is not valid
     //--------------------------------------------------------------------------------------------------
     #ifdef COMPILER_SWITCH_ECU_TTC90
         extern ERetVal eCoreGetEcuDiagStatus( TDiagStatus *ptDiagSta );
     #endif
     #ifdef COMPILER_SWITCH_ECU_TTC94
         extern ERetVal eCoreGetEcuDiagStatus( TDiagStatus *ptDiagSta );
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


     #ifdef COMPILER_SWITCH_ECU_TTC90
         //--------------------------------------------------------------------------------------------------
         //! @brief      Show Ecu Diag Information - ( SafeState is a print warning, all other are just a print )
         //! @param[in]  boShowOnlyIfSafeState - Give only the status information if 'Safe-State' is active
         //--------------------------------------------------------------------------------------------------
         extern TVoid vCoreShowEcuDiagInfo( TBoolean boShowOnlyIfSafeState );
     #endif

     #ifdef COMPILER_SWITCH_ECU_TTC94
         //--------------------------------------------------------------------------------------------------
         //! @brief      Show Ecu Diag Information - ( SafeState is a print warning, all other are just a print )
         //! @param[in]  boShowOnlyIfSafeState - Give only the status information if 'Safe-State' is active
         //--------------------------------------------------------------------------------------------------
         extern TVoid vCoreShowEcuDiagInfo( TBoolean boShowOnlyIfSafeState );
     #endif

    #ifdef COMPILER_SWITCH_ECU_TTC60
         //--------------------------------------------------------------------------------------------------
         //! @brief      Control the BSP Task function for mini module for current measurement (call in the core layer after the application part)
         //! @param[in]  boOn           - TRUE call the MM_MCM_Task(), FALSE don't call the MM_MCM_Task() [Dflt=TRUE]
         //--------------------------------------------------------------------------------------------------
         extern TVoid vCoreCtrlBspMmMcmTask( TBoolean boOn );

         //--------------------------------------------------------------------------------------------------
         //! @brief      Get the Status value from the  MM_MCM_Task(), which called in the core layer
         //! @return     value - (65535: MM_MCM_Task() don't call in the core layer, else the IO_ErrorType
         //-------------------------------------------------------------------------------------------------
         extern TUint16 u16CoreGetBspMmMcmTaskSta( TVoid );
    #endif

    #ifdef COMPILER_SWITCH_ECU_TTC90
         //--------------------------------------------------------------------------------------------------
         //! @brief      Control the BSP Task function for mini module for current measurement (call in the core layer after the application part)
         //! @param[in]  boOn           - TRUE call the MM_MCM_Task(), FALSE don't call the MM_MCM_Task() [Dflt=TRUE]
         //--------------------------------------------------------------------------------------------------
         extern TVoid vCoreCtrlBspMmMcmTask( TBoolean boOn );

         //--------------------------------------------------------------------------------------------------
         //! @brief      Get the Status value from the  MM_MCM_Task(), which called in the core layer
         //! @return     value - (65535: MM_MCM_Task() don't call in the core layer, else the IO_ErrorType
         //-------------------------------------------------------------------------------------------------
         extern TUint16 u16CoreGetBspMmMcmTaskSta( TVoid );
    #endif

    #ifdef COMPILER_SWITCH_TAR_PC

           //--------------------------------------------------------------------------------------------------
           //! @brief      Set diagnose status
           //! @param[in]  ptDiagSta      - Diagnose struct
           //! @retval     R_OKAY         - struct is valid
           //! @retval     R_NULL_POINTER - ptDiagSta is a NULL pointer
           //--------------------------------------------------------------------------------------------------
           #ifdef COMPILER_SWITCH_ECU_TTC90
               extern ERetVal eCoreSimSetEcuDiagStatus( TDiagStatus *ptDiaStatus );
           #endif
           #ifdef COMPILER_SWITCH_ECU_TTC94
               extern ERetVal eCoreSimSetEcuDiagStatus( TDiagStatus *ptDiaStatus );
           #endif

           // D I A G N O S T I C   S T A T E   M A C H I N E   E R R O R   V A L U E S

           #define DIAG_E_NO_ERROR                     0   //!< No error

           #define DIAG_E_ADC_5V_SWITCH                119 //!< ADC 5V input switches error
           #define DIAG_E_ADC_VREF                     141 //!< ADC Vref check error
           #define DIAG_E_ADC_5V_SWITCHES_PER          140 //!< ADC 5V periodic switches check error
           #define DIAG_E_ADC_VREF_GND_NORMAL_RANGE    121 //!< ADC Vref GDN check normal range error
           #define DIAG_E_ADC_VREF_GND_GND_RANGE       122 //!< ADC Vref GDN check ground range error
           #define DIAG_E_ADC_RATIO_SHORT_CIRCUIT      123 //!< ADC 5V ratiometric redundant short circuit test error
           #define DIAG_E_ADC_LIMITS                   125 //!< ADC 5V or ADC 32V limit check error
           #define DIAG_E_ADC_CURRENT_LOOP             142 //!< ADC 5V Current Loop check error
           #define DIAG_E_ADC_SWITCH                   146 //!< ADC 32V Switch check error
           #define DIAG_E_ADC_SENSOR_SUPPLY            147 //!< ADC sensor supply check error

           #define DIAG_E_PWD_LIMITS_FREQ              135 //!< PWD frequency limit check error
           #define DIAG_E_PWD_LIMITS_PULSE_WIDTH       143 //!< PWD Pulse width limit check error
           #define DIAG_E_PWD_SWITCH                   145 //!< PWD Switch check error
           #define DIAG_E_PWD_MUX                      148 //!< PWD Mux check error

           #define DIAG_E_PWM_SHORT_CIRCUIT            130 //!< PWM short circuit check error
           #define DIAG_E_PWM_PERIOD_MISMATCH          131 //!< PWM period mismatch
           #define DIAG_E_PWM_LIMITS_RANGE             132 //!< PWM limit range check error
           #define DIAG_E_PWM_LIMITS_TOL               133 //!< PWM limit tolerance check error
           #define DIAG_E_PWM_CURRENT                  134 //!< PWM current check error
           #define DIAG_E_PWM_OVERCURRENT              144 //!< PWM over current check error

           #define DIAG_E_STATE_INIT                   183 //!< Internal error in init state
           #define DIAG_E_STATE_CONFIG                 185 //!< Internal error in config state
           #define DIAG_E_STATE_MAIN                   186 //!< Internal error in main state
           #define DIAG_E_STATE_SAFE                   189 //!< Internal error in safe state

           #define DIAG_E_WATCHDOG_SAFE_STATE          190 //!< WD CPU has entered the safe state
           #define DIAG_E_INVALID_DIAG_STATE           191 //!< Internal error: invalid state for diag state machine
           #define DIAG_E_WATCHDOG_TIMEOUT             192 //!< WD CPU has not replied correctly within the timeout
           #define DIAG_E_APPL_SAFE_STATE              193 //!< Application requested to activate the safe state

           #define DIAG_E_MEM_REGISTER                 127 //!< MEM register check error
           #define DIAG_E_MEM_INT_RAM                  128 //!< Internal RAM check error
           #define DIAG_E_MEM_EXT_RAM                  129 //!< External RAM check error
           #define DIAG_E_MEM_FLASH                    136 //!< Flash check error
           #define DIAG_E_MEM_USER_STACK               126 //!< User Stack check error
           #define DIAG_E_MEM_SYSTEM_STACK             160 //!< System Stack check error
           #define DIAG_E_MEM_GENERAL                  161 //!< General CPU error, TRAP 0x28

           #define DIAG_E_MEM_ECC                      162 //!< ECC check reported an error
           #define DIAG_E_MEM_PAR                      163 //!< PARITY check reported an error
           #define DIAG_E_MEM_SYS_STACK_OF             164 //!< An overflow of the system stack occurred
           #define DIAG_E_MEM_SYS_STACK_UF             165 //!< An underflow of the system stack occurred
           #define DIAG_E_MEM_SR0_TRAP                 166 //!< A System Request 0 trap occurred
           #define DIAG_E_MEM_SOFTBREAK_TRAP           167 //!< A SOFTBREAK trap occurred (software triggered)
           #define DIAG_E_MEM_CLASS_B_SCU_TRAP         168 //!< A class B trap triggered by the SCU occurred
           #define DIAG_E_MEM_CLASS_B_GEN_TRAP         169 //!< A general class B trap occurred

           #define DIAG_E_SW_INTERNAL                  170 //!< internal software error occurred
           #define DIAG_E_WDT                          171 //!< The ECU was reset by the CPU internal watchdog timer

           // W A T C H D O G   C P U   E R R O R   V A L U E S

           #define DIAG_WD_E_NO_ERROR                      0U

           #define DIAG_WD_E_INV_SEQ_NO                    1U
           #define DIAG_WD_E_INV_OPCODE                    2U
           #define DIAG_WD_E_INV_CMD_FRAME_LENGTH          3U
           #define DIAG_WD_E_CRC                           4U
           #define DIAG_WD_E_VALUE_RANGE                   5U
           #define DIAG_WD_E_TIMEOUT                       6U
           #define DIAG_WD_E_MISSING_IO_DATA               7U
           #define DIAG_WD_E_UNEXPECTED_CMD                8U
           #define DIAG_WD_E_WD_CONNECTION_LOST            9U
           #define DIAG_WD_E_L_LIMIT_GREATER_H_LIMIT       10U

           #define DIAG_WD_E_RPV_SHUT_OFF                  11U
           #define DIAG_WD_E_VOLT_MONITOR                  20U
           #define DIAG_WD_E_SUPPLY_VOLT                   21U
           #define DIAG_WD_E_LOW_VOLTAGE                   22U

           #define DIAG_WD_E_STACK_UNDER_OR_OVERFLOW       30U
           #define DIAG_WD_E_REGISTER_ERROR                31U
           #define DIAG_WD_E_WATCHDOG_RAM                  40U
           #define DIAG_WD_E_WATCHDOG_FLASH                41U
           #define DIAG_WD_E_PRGM_FLOW                     42U
           #define DIAG_WD_E_FLAG_TEST                     43U
           #define DIAG_WD_E_FLAG_MONITORING               44U

           #define DIAG_WD_E_ADC_SRC                       50U
           #define DIAG_WD_E_ADC_SHORT_CIRCUIT             51U
           #define DIAG_WD_E_ADC_CR_RC                     52U
           #define DIAG_WD_E_ADC_OVERRIDE                  53U
           #define DIAG_WD_E_PWM_DUTY_CYCLE_SET            60U
           #define DIAG_WD_E_PWM_DUTY_CYCLE_READ           61U
           #define DIAG_WD_E_PWM_TOLERANCE                 62U
           #define DIAG_WD_E_TPU_LIMIT                     70U
           #define DIAG_WD_E_TPU_OVERRIDE                  71U

           #define DIAG_WD_E_RELAY                         80U
           #define DIAG_WD_E_POWERSTAGES_ENABLE            81U
           #define DIAG_WD_E_ADC_SWITCH_SETTINGS           82U

           #define DIAG_WD_E_HARMONICS                     90U
           #define DIAG_WD_E_MAIN_CPU_SAFE_STATE           91U
           #define DIAG_WD_E_APPL_SAFE_STATE               92U

           #define DIAG_WD_E_DRV_IO                        100U
           #define DIAG_WD_E_DRV_ADC                       101U
           #define DIAG_WD_E_DRV_SPI                       102U
           #define DIAG_WD_E_DRV_FLASH                     103U
           #define DIAG_WD_E_MOD_SPI                       104U
           #define DIAG_WD_E_MOD_CHECK_PWM_OUTPUTS         105U
           #define DIAG_WD_E_MOD_CHECK_SUPPLY              106U
           #define DIAG_WD_E_MOD_CHECK_VOLT_MONITOR        107U
           #define DIAG_WD_E_MOD_CHECK_EXT_RELAYS          108U
           #define DIAG_WD_E_MOD_CHECK_DIG_TIMER_INPUTS    109U
           #define DIAG_WD_E_MOD_CHECK_ANALOG_INPUTS       110U
           #define DIAG_WD_E_MOD_CHECK_FLASH               111U
           #define DIAG_WD_E_MOD_CHECK_SHORT_CIRCUIT_AI    112U
           #define DIAG_WD_E_MOD_CHECK_RPV                 113U
           #define DIAG_WD_E_MOD_CHECK_RAM_TEST            114U
           #define DIAG_WD_E_MOD_CHECK_REGISTER_TEST       115U
           #define DIAG_WD_E_MOD_CHECK_PGM_FLOW            116U
           #define DIAG_WD_E_MOD_CHECK_STACK               117U
           #define DIAG_WD_E_MOD_CHECK_CONFIG              118U

           #define DIAG_WD_E_STATE_INIT                    150U
           #define DIAG_WD_E_STATE_START_UP                151U
           #define DIAG_WD_E_STATE_RUNNING                 152U
           #define DIAG_WD_E_STATE_SAFE_STATE              153U
           #define DIAG_WD_E_STATE_SYNC1                   154U
           #define DIAG_WD_E_STATE_SYNC2                   155U
           #define DIAG_WD_E_STATE_SYNC3                   156U

           // D I A G N O S T I C   S T A T E   M A C H I N E   S T A T E S

           #define DIAG_STATE_INIT                        0x03
           #define DIAG_STATE_CONFIG                      0x05
           #define DIAG_STATE_MAIN                        0x06
           #define DIAG_STATE_SAFE_STATE                  0x09
           #define DIAG_STATE_DISABLED                    0x00

           // W A T C H D O G   C P U   S T A T E S

           #define DIAG_WD_STATE_INIT                     0x03
           #define DIAG_WD_STATE_START_UP                 0x05
           #define DIAG_WD_STATE_RUNNING                  0x06
           #define DIAG_WD_STATE_SAFE_STATE               0x09
           #define DIAG_WD_STATE_UNDEFINED                0x00

           // D I A G   D E V I C E S

           #define DIAG_DEV_CONFIG_GLOBAL                 200U
           #define DIAG_DEV_CONFIG_ANALOG_5V              201U
           #define DIAG_DEV_CONFIG_ANALOG_10V             202U
           #define DIAG_DEV_CONFIG_PWM                    203U
           #define DIAG_DEV_CONFIG_TPU                    204U

           #define DIAG_DEV_IO_ANALOG_5V                  205U
           #define DIAG_DEV_IO_ANALOG_10V                 206U
           #define DIAG_DEV_IO_PWM                        207U
           #define DIAG_DEV_IO_TPU                        208U

           #define DIAG_DEV_REF_VOLTAGE_3V                195U
           #define DIAG_DEV_REF_VOLTAGE_2P5V              196U
           #define DIAG_DEV_REF_VOLTAGE_EXT_POWER         197U

           #define DIAG_DEV_RAM_FLASH_WATCHDOG            251U
           #define DIAG_DEV_WATCHDOG_CPU                  252U
           #define DIAG_DEV_SUPPLY_VOLTAGE                253U
           #define DIAG_DEV_TTP_CONTROLLER                254U
           #define DIAG_DEV_MAIN_CPU                      255U

           #define DIAG_DEV_RELAY1                        110U
           #define DIAG_DEV_RELAY2                        111U
           #define DIAG_DEV_RELAY3                        112U

        #endif

    #endif

#endif
