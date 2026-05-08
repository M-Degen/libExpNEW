//**************************************************************************************************
/*!
@file       ItfBoardCenTtc7x.h
@brief	    CEN TTC7x Family
@date       13.07.2010
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENTTC7X__
  #define __ITFBOARDCENTTC7X__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>

   #ifdef COMPILER_SWITCH_FAM_TTC7X

        #define COMPILER_SWITCH_FLASH_SETTING

        #ifdef COMPILER_SWITCH_ECU_TTC77
           #define COMPILER_SWITCH_BSP_DIAGSTATE_MACHINE
           #define COMPILER_SWITCH_INIT_WATCHDOG
        #endif

        #define COMPILER_SWITCH_SEC_APP
        #define COMPILER_SWITCH_FORCE_FEATURE

        #define COMPILER_SWITCH_INTERNAL_FLASH_ACCESS

        #define COMPILER_SWITCH_MAIN_CORE_EMC_BREAK

        #define COMPILER_SWITCH_CANBUS
         #ifdef COMPILER_SWITCH_ECU_TTC77
            #define _CS_CANBUS_2_
         #else
            #define _CS_CANBUS_1_
         #endif

        //! Can Bus
        typedef enum
        {
            CAN_BUS0,           //!< CAN Bus 0
            #ifdef _CS_CANBUS_2_
            CAN_BUS1,           //!< CAN Bus 1
            #endif
            CAN_BUS_MAX         //!< Max
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
            CBUS0_HWBUF_RCV0,    //!  0 - Receive hardware buffer
            CBUS0_HWBUF_RCV1,    //!  1 - Receive hardware buffer
            CBUS0_HWBUF_RCV2,    //!  2 - Receive hardware buffer
            CBUS0_HWBUF_RCV3,    //!  3 - Receive hardware buffer
            CBUS0_HWBUF_RCV4,    //!  4 - Receive hardware buffer
            CBUS0_HWBUF_RCV5,    //!  5 - Receive hardware buffer
            CBUS0_HWBUF_RCV6,    //!  6 - Receive hardware buffer
            CBUS0_HWBUF_RCV7,    //!  7 - Receive hardware buffer
            CBUS0_HWBUF_SND0,    //!  8 - Send hardware buffer
            CBUS0_HWBUF_SND1,    //!  9 - Send hardware buffer
            CBUS0_HWBUF_SND2,    //! 10 - Send hardware buffer
            CBUS0_HWBUF_SND3,    //! 11 - Send hardware buffer
            CBUS0_HWBUF_SND4,    //! 12 - Send hardware buffer
            CBUS0_HWBUF_SND5,    //! 13 - Send hardware buffer
            #ifdef COMPILER_SWITCH_ECU_TTC77
            CBUS1_HWBUF_RCV0,    //! 14 - Receive hardware buffer
            CBUS1_HWBUF_RCV1,    //! 15 - Receive hardware buffer
            CBUS1_HWBUF_RCV2,    //! 16 - Receive hardware buffer
            CBUS1_HWBUF_RCV3,    //! 17 - Receive hardware buffer
            CBUS1_HWBUF_RCV4,    //! 18 - Receive hardware buffer
            CBUS1_HWBUF_RCV5,    //! 19 - Receive hardware buffer
            CBUS1_HWBUF_RCV6,    //! 20 - Receive hardware buffer
            CBUS1_HWBUF_RCV7,    //! 21 - Receive hardware buffer
            CBUS1_HWBUF_SND0,    //! 22 - Send hardware buffer
            CBUS1_HWBUF_SND1,    //! 23 - Send hardware buffer
            CBUS1_HWBUF_SND2,    //! 24 - Send hardware buffer
            CBUS1_HWBUF_SND3,    //! 25 - Send hardware buffer
            CBUS1_HWBUF_SND4,    //! 26 - Send hardware buffer
            CBUS1_HWBUF_SND5,    //! 27 - Send hardware buffer
            #endif
            HWBUF_NA = 0xFF      //!      No hardware buffer
        }ECBusHwBuf;

        enum
        {
            IDX_00,  // Dummy index
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
            IDX_53,
            IDX_54,
            IDX_55,
            IDX_56,
            IDX_57,
            IDX_58,
            IDX_59,
            IDX_60,
            IDX_61,
            IDX_62,
            IDX_63,
            IDX_64,
            IDX_65,
            IDX_MAX
        };

        #define FIRST_OUTPUT_PIN  IDX_40                     //!< First output PIN
        #define FIRST_MULTI_PIN   IDX_40                     //!< First multiple PIN
        #define SYSPIN_MAX             6                     //!< System PIN

        #define PIN_OVER_ALL      (IDX_MAX + SYSPIN_MAX)     //!< All PINs

        typedef enum
        {
            PIN_SYS = IDX_00,
            PIN_260 = IDX_01,
            PIN_253 = IDX_02,
            PIN_274 = IDX_03,
            PIN_267 = IDX_04,
            PIN_126 = IDX_05,
            PIN_114 = IDX_06,
            PIN_125 = IDX_07,
            PIN_113 = IDX_08,
            PIN_124 = IDX_09,
            PIN_112 = IDX_10,
            PIN_123 = IDX_11,
            PIN_111 = IDX_12,
            PIN_121 = IDX_13,
            PIN_109 = IDX_14,
            PIN_120 = IDX_15,
            PIN_108 = IDX_16,
            PIN_119 = IDX_17,
            PIN_107 = IDX_18,
            PIN_118 = IDX_19,
            PIN_106 = IDX_20,
            PIN_150 = IDX_21,
            PIN_149 = IDX_22,
            PIN_148 = IDX_23,
            PIN_147 = IDX_24,
            PIN_146 = IDX_25,
            PIN_145 = IDX_26,
            PIN_144 = IDX_27,
            PIN_143 = IDX_28,
            PIN_142 = IDX_29,
            PIN_141 = IDX_30,
            PIN_264 = IDX_31,
            PIN_257 = IDX_32,
            PIN_263 = IDX_33,
            PIN_256 = IDX_34,
            PIN_262 = IDX_35,
            PIN_255 = IDX_36,
            PIN_261 = IDX_37,
            PIN_117 = IDX_38,
            PIN_105 = IDX_39,
            PIN_276 = IDX_40,
            PIN_269 = IDX_41,
            PIN_152 = IDX_42,
            PIN_140 = IDX_43,
            PIN_138 = IDX_44,
            PIN_137 = IDX_45,
            PIN_275 = IDX_46,
            PIN_268 = IDX_47,
            PIN_151 = IDX_48,
            PIN_139 = IDX_49,
            PIN_136 = IDX_50,
            PIN_135 = IDX_51,
            PIN_134 = IDX_52,
            PIN_133 = IDX_53,
            PIN_132 = IDX_54,
            PIN_131 = IDX_55,
            PIN_130 = IDX_56,
            PIN_129 = IDX_57,
            PIN_280 = IDX_58,
            PIN_279 = IDX_59,
            PIN_278 = IDX_60,
            PIN_277 = IDX_61,
            PIN_273 = IDX_62,
            PIN_272 = IDX_63,
            PIN_271 = IDX_64,
            PIN_270 = IDX_65,
            PIN_MAX = IDX_MAX,
            PIN_NA
        }EPin;

        //! Voltage reference types
        enum
        { //
            PINRSL_NA,          //!< 0 - Voltage variable: not available
            PINRSL_5V,          //!< 1 - Voltage variable: 5V Ref
            PINRSL_10V,         //!< 2 - Voltage variable: 10V Ref
            PINRSL_15V,         //!< 3 - Voltage variable: 15V Ref
            PINRSL_20V,         //!< 4 - Voltage variable: 20V Ref
            PINRSL_25V,         //!< 5 - Voltage variable: 25V Ref
            PINRSL_30V,         //!< 6 - Voltage variable: 30V Ref
            PINRSL_32V,         //!< 7 - Voltage variable: 32V Ref
        };

        //! PIN supply
        enum
        {
            #ifdef COMPILER_SWITCH_ECU_TTC71
            PINSUPPLY_NA = 0,       //!< 0 - No sensor voltage PIN supply
            PINSUPPLY_S1 = 2        //!< 2 - Voltage PIN supply sensor '1'
            #endif
            #ifdef COMPILER_SWITCH_ECU_TTC77
            PINSUPPLY_NA = 0,       //!< 0 - No sensor voltage PIN supply
            PINSUPPLY_S0 = 1,       //!< 1 - Voltage PIN supply sensor '0'
            PINSUPPLY_S1 = 2        //!< 2 - Voltage PIN supply sensor '1'
            #endif
        };

        // System PINs
        #define PIN_SYS_BAT    (IDX_MAX)    //!< for the 7x family
        #define PIN_SYS_K15    (IDX_MAX+1)  //!< for the 7x family
        #define PIN_SYS_TEMP   (IDX_MAX+2)  //!< for the 7x family
        #define PIN_SYS_REF    (IDX_MAX+3)  //!< for the 7x family
        #define PIN_SYS_S0     (IDX_MAX+4)  //!< for the 7x family
        #define PIN_SYS_S1     (IDX_MAX+5)  //!< for the 7x family

        #define PIN_SYS_START  PIN_SYS_BAT  //!< for the 7x family
        #define PIN_SYS_END    PIN_SYS_S1   //!< for the 7x family
        #define PIN_HST_END    PIN_SYS_END  //!< max

        //! PIN general configuration types from PDT
        typedef enum
        {
            PINTYP_NA        =  _PINTYP_NA,         //!< Type: [-]     Not available
            PINTYP_DIN       =  _PINTYP_DIN,        //!< Type: [0/1]   Digital input
            PINTYP_VIN       =  _PINTYP_VIN,        //!< Type: [mV]    Voltage input
            PINTYP_RES       =  _PINTYP_RES,        //!< Type: [Ohm]   Resistive configuration
            PINTYP_CIN       =  _PINTYP_CIN,        //!< Type: [µA]    Current input

            #ifdef COMPILER_SWITCH_ECU_TTC77
            PINTYP_FIN       =  _PINTYP_FIN,        //!< Type: [Hz]    Frequency input
            PINTYP_PUL       =  _PINTYP_PUL,        //!< Type: [µs]    Read pulse value input
            #endif
            PINTYP_CNT       =  _PINTYP_CNT,        //!< Type: [cnt]   Counter input
            PINTYP_CPX       =  _PINTYP_CPX,        //!< Type: [STU]   Complex input
            #ifndef COMPILER_SWITCH_ECU_TTC71
            PINTYP_INC       =  _PINTYP_INC,        //!< Type: [cnt]   Incremental input with 2 pins
            #endif
            PINTYP_DOU       = _PINTYP_DOU,         //!< Type: [0/1]   Digital output
            #ifdef COMPILER_SWITCH_ECU_TTC77
            PINTYP_PWM       = _PINTYP_PWM,         //!< Type: [duty]  PWM output
            #endif
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

        #define PINPWM_200          200      //!< PWM frequency
        #define PINPWM_166          166      //!< PWM frequency
        #define PINPWM_142          142      //!< PWM frequency
        #define PINPWM_125          125      //!< PWM frequency
        #define PINPWM_111          111      //!< PWM frequency
        #define PINPWM_100          100      //!< PWM frequency
        #define PINPWM_90            90      //!< PWM frequency
        #define PINPWM_83            83      //!< PWM frequency
        #define PINPWM_76            76      //!< PWM frequency
        #define PINPWM_71            71      //!< PWM frequency
        #define PINPWM_66            66      //!< PWM frequency
        #define PINPWM_62            62      //!< PWM frequency
        #define PINPWM_58            58      //!< PWM frequency
        #define PINPWM_55            55      //!< PWM frequency
        #define PINPWM_52            52      //!< PWM frequency
        #define PINPWM_50            50      //!< PWM frequency

        #define PINTHR_DFLT  (U16_MAX-1)     //!< Threshold set to default value [Low: 2000mV, High:  3500mV]
                                             //!<                                [Low: 5000µA, High: 15000µA]

        #define PINTHR_VIN_THR_LO   2000     //!< [mV] Threshold low
        #define PINTHR_VIN_THR_HI   3500     //!< [mV] Threshold high
        #define PINTHR_CIN_THR_LO   5000     //!< [µA] Threshold low
        #define PINTHR_CIN_THR_HI  15000     //!< [µA] Threshold high

        #define PWM_FREQDFLT_VAL     100     //!< Default frequency

        #define ECU_PWM_DOU_MAX_DUTY 60000   //!< 92,25% Duty Cycle [0xEA60]

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
          #ifdef COMPILER_SWITCH_ECU_TTC77
              extern ERetVal eCoreGetEcuDiagStatus( TDiagStatus *ptDiagSta );
          #endif

          //! Ecu Reset Status
          typedef enum
          {
              ECU_RST_STAT_PORST,      //!< Reset status for a power on reset
              ECU_RST_STAT_WDT,        //!< Reset status for a watchdog timer reset
              ECU_RST_STAT_TRAP,       //!< Reset due to exception
              ECU_RST_STAT_SW,         //!< Reset due to call of BSP:IO_Driver_Reset (in or after eAppPreStart() )
              ECU_RST_STAT_UNKOWN_ERR  //!< Unknown reset
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
          //!        Call in the main in the vAppSafetyInit()
          //!
          //!   TVoid main ( TVoid )
          //!   {
          //!        if( R_OKAY == eCoreSuppressEcuAutoReset() ){ return } // Avoid the auto reaction by MATCH Core
          //!
          //!        while( 1 )
          //!        {
          //!            vCoreMain(  &ePhase, ...
          //!
          //! ERetVal eAppPreStart( TVoid )
          //! {
          //!     if( ECU_RST_STAT_PORST != eCoreGetEcuResetStatus() ) // Get the last reset status
          //!     {
          //!         vCoreEcuPowerDown()
          //!         return;
          //!     }
          //!     ....
          //!
          //! @retval     reset cause
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
          //!
          //!     // -----------------------------------------------------------------
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

          #ifdef COMPILER_SWITCH_ECU_TTC77

              //! Bsp Diag Error Code
              typedef struct
              {
                  TUint8  u8ErrorCode;                           //!< The error code
                  TUint8  u8DeviceNum;                           //!< The device number which caused the error. This can either be an internal Device Diagnostic devices
                  TUint32 u32FaultyValue;                        //!< The value which caused the error
              }TBspDiagErrCode;

              #define BSP_DIAG_ERR_NOACTION       0x1            //!< take no action (ignore the error)
              #define BSP_DIAG_ERR_SAFESTATE      0x9            //!< enter the safe state (switch off all outputs)
              #define BSP_DIAG_ERR_DISABLE_SSW0   0x10           //!< disable the safety switch 0
              #define BSP_DIAG_ERR_DISABLE_SSW1   0x11           //!< disable the safety switch 1
              #define BSP_DIAG_ERR_DISABLE_SSW2   0x12           //!< disable the safety switch 2

              //--------------------------------------------------------------------------------------------------
              //! @brief      u8CorePostSafetyCb
              //!             NOTE: This function destroys the match safety reaction - but it is possible to managed that by the own.\n
              //!             NOTE: no effect if there is any pin configured with a non-dflt safety reaction
              //! @param[in]  u8DiagState      - Diagnostic state
              //! @param[in]  u8WatchdogState  - Watchdog state
              //! @param[in]  u8CoreReaction   - is the core 'match'-reaction
              //! @param[in]  pctErr           - Bsp diagnostic error code
              //! @return     new safe state reaction - [BSP_DIAG_ERR_SAFESTATE or  BSP_DIAG_ERR_NOACTION]
              //--------------------------------------------------------------------------------------------------
              extern TVoid vCoreSetPostSafetyCbFct( TUint8 (*pfu8CorePostSafetyCb)( TUint8 u8DiagState, TUint8 u8WatchdogState, TUint8 u8CoreReaction, TBspDiagErrCode *const pctErr ) );

              //--------------------------------------------------------------------------------------------------
              //! @brief      Show Ecu Diag Information - ( SafeState is a print warning, all other are just a print )
              //! @param[in]  boShowOnlyIfSafeState - Give only the status information if 'Safe-State' is active
              //--------------------------------------------------------------------------------------------------
              extern TVoid vCoreShowEcuDiagInfo( TBoolean boShowOnlyIfSafeState );
          #endif

      #ifdef COMPILER_SWITCH_TAR_PC

          //--------------------------------------------------------------------------------------------------
          //! @brief      Set diagnose status
          //! @param[in]  ptDiagSta      - Diagnose struct
          //! @retval     R_OKAY         - struct is valid
          //! @retval     R_NULL_POINTER - ptDiagSta is a NULL pointer
          //--------------------------------------------------------------------------------------------------
          #ifdef COMPILER_SWITCH_ECU_TTC77
              extern ERetVal eCoreSimSetEcuDiagStatus( TDiagStatus *ptDiaStatus );
          #endif

          //D I A G N O S T I C   S T A T E   M A C H I N E   E R R O R   V A L U E S

          #define DIAG_E_NOERROR                           0  //!< No error
          #define DIAG_E_ADC_SWCONF_LIMITS                 1  //!< ADC signal range check violation
          #define DIAG_E_ADC_SWCONF_SWITCHES               2  //!< ADC switches check error
          #define DIAG_E_ADC_SWCONF_SWITCHES_PER           3  //!< ADC periodic switches check error
          #define DIAG_E_ADC_5V_LIMITS                     4  //!< ADC signal range check violation
          #define DIAG_E_ADC_DIG_LIMITS                    5  //!< ADC signal range check violation
          #define DIAG_E_ADC_DIG_SWITCHES                  6  //!< ADC switches check error
          #define DIAG_E_ADC_PDCONF_LIMITS                 7  //!< ADC signal range check violation
          #define DIAG_E_ADC_PDCONF_SWITCHES               8  //!< ADC switches check error

          #define DIAG_E_ADC_CURRENT_LOOP_SHORT            9  //!< ADC current loop short circuit check error
          #define DIAG_E_ADC_RATIO_SHORT                  10  //!< ADC ratiometric short circuit test error

          #define DIAG_E_ADC_BATTERY_VOLT                 11  //!< Battery voltage out of range
          #define DIAG_E_ADC_SENSOR_SUPPLY                12  //!< Sensor supply voltage out of range
          #define DIAG_E_ADC_VREF                         13  //!< ADC Vref check error
          #define DIAG_E_ADC_VREF_GND_GND_RANGE           14  //!< ADC Vref GDN check ground range error
          #define DIAG_E_ADC_VREF_GND_NORMAL_RANGE        15  //!< ADC Vref GDN check normal range error

          #define DIAG_E_PWD_LIMITS_FREQ                  16  //!< PWD frequency limit check error
          #define DIAG_E_PWD_LIMITS_PULSE_WIDTH           17  //!< PWD Pulse width limit check error

          #define DIAG_E_PWM_SHORT_CIRCUIT                18  //!< PWM short circuit check error

          #define DIAG_E_PWM_CURRENT_ZERO                 19  //!< Current zero check error
          #define DIAG_E_PWM_CURRENT_OFFSET               20  //!< Current offset check error
          #define DIAG_E_PWM_CURRENT                      21  //!< PWM current check error

          #define DIAG_E_PWM_LIMITS_RANGE                 22  //!< PWM limit range check error
          #define DIAG_E_PWM_LIMITS_TOL                   23  //!< PWM limit tolerance check error
          #define DIAG_E_PWM_PERIOD_MISMATCH              24  //!< PWM period mismatch

          #define DIAG_E_SHUTOFF_GROUPS                   25  //!< Error during safety switch test
          #define DIAG_E_IPP_ENABLE                       26  //!< Inverse polarity protection not working

          #define DIAG_E_MEM_REGISTER                     27  //!< MEM register check error
          #define DIAG_E_MEM_INT_RAM                      28  //!< Internal RAM check error
          #define DIAG_E_MEM_FLASH                        29  //!< Flash check error
          #define DIAG_E_MEM_USER_STACK                   30  //!< User Stack check error
          #define DIAG_E_MEM_SYSTEM_STACK                 31  //!< System Stack check error
          #define DIAG_E_MEM_GENERAL                      32  //!< General CPU error, TRAP 0x28

          #define DIAG_E_STATE_INIT                       33  //!< Internal error in init state
          #define DIAG_E_STATE_CONFIG                     34  //!< Internal error in config state
          #define DIAG_E_STATE_MAIN                       35  //!< Internal error in main state
          #define DIAG_E_STATE_SAFE                       36  //!< Internal error in safe state

          #define DIAG_E_WATCHDOG_SAFE_STATE              37  //!< WD CPU has entered the safe state
          #define DIAG_E_INVALID_DIAG_STATE               38  //!< Internal error: invalid state for diag state machine
          #define DIAG_E_WATCHDOG_TIMEOUT                 39  //!< WD CPU has not replied correctly within the timeout
          #define DIAG_E_APPL_SAFE_STATE                  40  //!< Application requested to activate the safe state

          // W A T C H D O G   C P U   E R R O R   V A L U E S

          #define DIAG_WD_E_INV_SEQ_NO                    1U   //!< Sequence number check failed
          #define DIAG_WD_E_INV_OPCODE                    2U   //!< Unknown opcode
          #define DIAG_WD_E_INV_CMD_FRAME_LENGTH          3U   //!< Length not within specified range
          #define DIAG_WD_E_CRC                           4U   //!< Invalid CRC
          #define DIAG_WD_E_VALUE_RANGE                   5U   //!< A command frame parameter is not within the specified value range.
          #define DIAG_WD_E_TIMEOUT                       6U   //!< No valid command frame was received within the specified command frame timeout
          #define DIAG_WD_E_MISSING_IO_DATA               7U   //!< For all I/Os that are configured as safety-critical, periodic update of the state information is expected.
                                                               //!< This error code indicates that there is state information missing for one or more I/Os.
          #define DIAG_WD_E_UNEXPECTED_CMD                8U   //!< The main CPU has sent a config or state command at a point in time at which this command is not allowed.
          #define DIAG_WD_E_WD_CONNECTION_LOST            9U   //!< The watchdog does not respond to commands sent by the main CPU.
          #define DIAG_WD_E_L_LIMIT_GREATER_H_LIMIT       10U  //!< Lower limit greater than higher limit

          #define DIAG_WD_E_RPV_SHUT_OFF                  11U  //!< The TTP-controller RPV pin is high
          #define DIAG_WD_E_VOLT_MONITOR                  20U  //!< The test of the voltage monitor circuit failed
          #define DIAG_WD_E_SUPPLY_VOLT                   21U  //!< Supply voltages not within specified ranges
          #define DIAG_WD_E_LOW_VOLTAGE                   22U  //!< Error occurs if the WD's supply voltage drops below 4.25V

          #define DIAG_WD_E_STACK_UNDER_OR_OVERFLOW       30U  //!< Stack-underflow or Stack-overflow detected by the stack monitoring function
          #define DIAG_WD_E_REGISTER_ERROR                31U  //!< Error during tests of internal registers
          #define DIAG_WD_E_WATCHDOG_RAM                  40U  //!< Error detected during RAM test
          #define DIAG_WD_E_WATCHDOG_FLASH                41U  //!< Error detected during Flash test
          #define DIAG_WD_E_PRGM_FLOW                     42U  //!< One or more vital functions were not called during the last iteration of IO-state-loop
          #define DIAG_WD_E_FLAG_TEST                     43U  //!< Error while testing the internal CPU flag register
          #define DIAG_WD_E_FLAG_MONITORING               44U  //!< Error while monitoring the internal CPU flag register

          #define DIAG_WD_E_ADC_SRC                       50U  //!< An ADC-input value is out of the specified signal range.
          #define DIAG_WD_E_ADC_SHORT_CIRCUIT             51U  //!< A short circuit was detected between redundant ADC channels
          #define DIAG_WD_E_ADC_CR_RC                     52U  //!< Error detected when checking the ADC current loop redundant channel(s)
          #define DIAG_WD_E_ADC_OVERRIDE                  53U  //!< Error detected when pulling the ADC reference voltages to GND
          #define DIAG_WD_E_PWM_DUTY_CYCLE_SET            60U  //!< The specified duty cycle range is not allowed
          #define DIAG_WD_E_PWM_DUTY_CYCLE_READ           61U  //!< A PWM output is out of the specified duty cycle range
          #define DIAG_WD_E_PWM_TOLERANCE                 62U  //!< Deviation between PWM-output and feedback-signal is greater than specified tolerance
          #define DIAG_WD_E_TPU_LIMIT                     70U  //!< A TPU input is out of the specified high-time/low-time/frequency value range
          #define DIAG_WD_E_TPU_OVERRIDE                  71U  //!< Error when pulling the TPU inputs to ground / BAT+

          #define DIAG_WD_E_RELAY                         80U  //!< An error was detected during check of an external relay.
          #define DIAG_WD_E_POWERSTAGES_ENABLE            81U  //!< An error was detected during check of the power stages
          #define DIAG_WD_E_ADC_SWITCH_SETTINGS           82U  //!< An error was detected while checking the ADC 5V configuration switches

          #define DIAG_WD_E_HARMONICS                     90U  //!< The watchdog's or the main CPU's clock is running at the wrong speed
          #define DIAG_WD_E_MAIN_CPU_SAFE_STATE           91U  //!< The main CPU has entered the Safe State, therefore the Watchdog activated also it's Safe State
          #define DIAG_WD_E_APPL_SAFE_STATE               92U  //!< The user's application demanded the activation of the Safe State

          #define DIAG_WD_E_DRV_IO                        100U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_DRV_ADC                       101U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_DRV_SPI                       102U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_DRV_FLASH                     103U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_SPI                       104U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_PWM_OUTPUTS         105U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_SUPPLY              106U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_VOLT_MONITOR        107U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_EXT_RELAYS          108U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_DIG_TIMER_INPUTS    109U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_ANALOG_INPUTS       110U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_FLASH               111U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_SHORT_CIRCUIT_AI    112U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_RPV                 113U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_RAM_TEST            114U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_REGISTER_TEST       115U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_PGM_FLOW            116U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_STACK               117U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_MOD_CHECK_CONFIG              118U //!< Internal error in watchdog software, e.g. invalid function call parameter.

          #define DIAG_WD_E_STATE_INIT                    150U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_STATE_START_UP                151U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_STATE_RUNNING                 152U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_STATE_SAFE_STATE              153U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_STATE_SYNC1                   154U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_STATE_SYNC2                   155U //!< Internal error in watchdog software, e.g. invalid function call parameter.
          #define DIAG_WD_E_STATE_SYNC3                   156U //!< Internal error in watchdog software, e.g. invalid function call parameter.

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
