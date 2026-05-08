//**************************************************************************************************
/*!
@file       ItfBoardCenTtc20xx.h
@brief      CEN TTC20xx
@date       23.10.2020
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENTTC20XX__
  #define __ITFBOARDCENTTC20XX__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>

   #ifdef COMPILER_SWITCH_FAM_TTC20XX


    #define COMPILER_SWITCH_BSP_DIAGSTATE_MACHINE
    #define COMPILER_SWITCH_FLASH_SETTING
    #define COMPILER_SWITCH_SEC_APP
    #define COMPILER_SWITCH_WAKE_UP_PIN
    #define COMPILER_SWITCH_WAKE_UP_CAN
    #define COMPILER_SWITCH_FORCE_FEATURE

    //#define COMPILER_SWITCH_ETH_HEXFILE_FLASH
    //#define COMPILER_SWITCH_MPU

    #define COMPILER_SWITCH_INIT_WATCHDOG

    #define COMPILER_SWITCH_DB_LIST_64
    #define COMPILER_SWITCH_BLO_60_SIG_60

    //#define COMPILER_SWITCH_RSBUS
    #define COMPILER_SWITCH_LINBUS
    //#define COMPILER_SWITCH_ETHBUS

#ifdef COMPILER_SWITCH_TAR_HW
    #define COMPILER_SWITCH_SENT
#endif

    #define COMPILER_SWITCH_CANBUS
       #define _CS_CANBUS_2_

    //! Can Bus
    typedef enum
    {
        CAN_BUS0,          //!< CAN Bus 0
        CAN_BUS1,          //!< CAN Bus 1
		CAN_BUS_MAX        //!< CAN Bus Max
    }ECanBus;

    //! CAN bit rate
    typedef enum
    {
        CAN_RATE_50K        = _CAN_RATE_50K,    //!<   50 kBaud
        CAN_RATE_100K       = _CAN_RATE_100K,   //!<  100 kBaud
        CAN_RATE_125K       = _CAN_RATE_125K,   //!<  125 kBaud
        CAN_RATE_250K       = _CAN_RATE_250K,   //!<  250 kBaud
        CAN_RATE_500K       = _CAN_RATE_500K,   //!<  500 kBaud
        CAN_RATE_667K       = _CAN_RATE_667K,   //!<  667 kBaud
        CAN_RATE_800K       = _CAN_RATE_800K,   //!<  800 kBaud
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

        HWBUF_NA = 0xFF      //!<      No hardware buffer
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
        IDX_MAX
    };



    #define FIRST_OUTPUT_PIN  IDX_17                   //!< First output PIN
    #define FIRST_MULTI_PIN   IDX_17                   //!< First multiple PIN
    #define SYSPIN_MAX             6                   //!< System PIN

    #define PIN_OVER_ALL      (IDX_MAX + SYSPIN_MAX)   //!< All PINs

    typedef enum
    {
        PIN_SYS = IDX_00,   //!< System pin
        // G01 - 5V ADC inputs (4 mode)
        PIN_J4 = IDX_01,   //!< [00]
        PIN_H4 = IDX_02,   //!< [01]
        PIN_E4 = IDX_03,   //!< [02]
        PIN_D4 = IDX_04,   //!< [03]
        PIN_C4 = IDX_05,   //!< [04]
        PIN_B4 = IDX_06,   //!< [05]
        PIN_A3 = IDX_07,   //!< [06]
        PIN_A4 = IDX_08,   //!< [07]
        // 32V ADC inputs ( 2mode )
        PIN_L4 = IDX_09,   //!< [00]
        PIN_F3 = IDX_10,   //!< [01]
        // Timer/SENT inputs
        PIN_E3 = IDX_11,   //!< [04]
        PIN_D3 = IDX_12,   //!< [05]
        PIN_C3 = IDX_13,   //!< [06]
        PIN_B3 = IDX_14,   //!< [07]
        // Timer/CL inputs
        PIN_G4 = IDX_15,   //!< [08]
        PIN_F4 = IDX_16,   //!< [09]
        // PWM HS outputs (4A+CM+FM)
        PIN_K1 = IDX_17,   //!< [00]
        PIN_J1 = IDX_18,   //!< [01]
        PIN_H1 = IDX_19,   //!< [02]
        PIN_G1 = IDX_20,   //!< [03]
        PIN_F1 = IDX_21,   //!< [04]
        PIN_E1 = IDX_22,   //!< [05]
        PIN_D1 = IDX_23,   //!< [06]
        PIN_C1 = IDX_24,   //!< [07]
        // DOP HS outputs (4A+CS/LPO)
        PIN_K2 = IDX_25,   //!< [08]
        PIN_J2 = IDX_26,   //!< [09]
        PIN_H2 = IDX_27,
        PIN_G2 = IDX_28,   //!< [11]
        PIN_F2 = IDX_29,   //!< [00]
        PIN_E2 = IDX_30,   //!< [01]
        // PWM LS outputs(4A+CM+FM)
        PIN_A1 = IDX_31,   //!< [02]
        PIN_B1 = IDX_32,   //!< [03]
        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;

    //! Voltage reference types
    enum
    {
        PINRSL_NA,          //!< 0 - Voltage variable: Not available
        PINRSL_5V,          //!< 1 - Voltage variable: 5V Ref
        PINRSL_32V          //!< 2 - Voltage variable: 32V Ref
    };

    //! PIN supply
    enum
    {
        PINSUPPLY_NA,       //!< 0 - No sensor voltage PIN supply
        PINSUPPLY_S0        //!< 1 - Voltage PIN supply sensor '0'
    };

    // System PINs
    #define PIN_SYS_BAT        (IDX_MAX)       //!<  97 - for TTC2038
    #define PIN_SYS_K15        (IDX_MAX+1)     //!<  98 - for TTC2038
    #define PIN_SYS_WAKEUP     (IDX_MAX+2)     //!<  99 - for TTC2038
    #define PIN_SYS_TEMP       (IDX_MAX+3)     //!< 103 - for TTC2038
    #define PIN_SYS_REF        (IDX_MAX+4)     //!< 104 - for TTC2038
    #define PIN_SYS_S0         (IDX_MAX+5)     //!< 105 - for TTC2038

    #define PIN_SYS_START      PIN_SYS_BAT     //!< for TTC2038
    #define PIN_SYS_END        PIN_SYS_S0      //!< for TTC2038
    #define PIN_HST_END        PIN_SYS_END     //!< for TTC2038

    //! PIN general configuration types from PDT
    typedef enum
    {
        PINTYP_NA        =  _PINTYP_NA,         //!< Type: [-]     Not available
        PINTYP_DIN       =  _PINTYP_DIN,        //!< Type: [0/1]   Digital input
        PINTYP_VIN       =  _PINTYP_VIN,        //!< Type: [mV]    Voltage input
        PINTYP_RES       =  _PINTYP_RES,        //!< Type: [Ohm]   Resistive configuration
        PINTYP_CIN       =  _PINTYP_CIN,        //!< Type: [µA]    Current input
        PINTYP_CNT       =  _PINTYP_CNT,        //!< Type: [cnt]   Counter input
        PINTYP_CPX       =  _PINTYP_CPX,        //!< Type: [STU]   Complex input
        PINTYP_INC       =  _PINTYP_INC,        //!< Type: [cnt]   Incremental input with 2 pins
        PINTYP_DOU       =  _PINTYP_DOU,        //!< Type: [0/1]   Digital high-side output
        PINTYP_DOU_LS    =  _PINTYP_DOU_LS,     //!< Type: [0/1]   Digital low-side output - not supported
        PINTYP_PWM       =  _PINTYP_PWM,        //!< Type: [duty]  PWM high-side output
        PINTYP_PWM_LS    =  _PINTYP_PWM_LS,     //!< Type: [duty]  PWM low-side output
        PINTYP_LED       =  _PINTYP_LED,        //!< Type: [0/1]   LED output
        PINTYP_PVG       =  _PINTYP_PVG,        //!< Type: [%/100] Percent of Ubat [1500..8500]
        PINTYP_VOU       =  _PINTYP_VOU         //!< Type: [mV]    Voltage output
    }EAppPinTyp;

    //! Resistor
    typedef enum
    {
        PINRES_NA,                              //!< 0 - Resistor: Option not there
        PINRES_PULLUP_WEAK,
        PINRES_PULLUP_STRONG,
        PINRES_PULLDO_WEAK,
        PINRES_PULLDO_STRONG,
        PINRES_PULLCUR_LOOP,
        PINRES_CFG_NA,                           //!< 6 - Resistor: Configuration not option
        PINRES_NO_PULL                           //!< 7 - Resistor: No pull resistor
    }EAppPinRes;

    //! Critical Mode
    typedef enum
    {
        CIO_NA,                                 //!< 0 - not applicable
        CIO_SAFESTA,                            //!< 1 - ecu enter the safe state
        CIO_NOREACT,                            //!< 2 - no reaction - ecu don't enter the safe state, if possible
        CIO_OUTOFF                              //!< 3 - Reaction driver off - if possible the pin or the pin group will shut off
    }ECioState;

    typedef enum
    {
        PWM_DIAG_MODE_SAFE,                //!< Default diagnostic mode. This mode is **highly recommended** for safety-related applications
                                           //!< and recommended in general for all ohmic and inductive loads.
        PWM_DIAG_MODE_DEFAULT,             //!< Mode providing the minimum required diagnostic capability for safety-related applications.
                                           //!< If there are indications against applying the diagnostic margin that is being activated by
                                           //!< mode #E_TT_PWM_DIAG_MODE_SAFE then this mode can be selected instead. It however comes with
                                           //!< the penalty that open-load/short-to-battery cannot be detected with every set target duty cycle.
        PWM_DIAG_MODE_MOTOR_HBR,           //!< Diagnostic mode for controlling electric DC motors in an H-bridge setup for
                                           //!< the output that is applying the PWM signal.
        PWM_DIAG_MODE_MOTOR_HBR_STATIC,    //!< Diagnostic mode for controlling electric DC motors in an H-bridge setup for
                                           //!< the output that is applying the static signal.
        PWM_DIAG_MODE_MOTOR                //!< Diagnostic mode for controlling electric DC motors in a single output setup.
    }EPwmDiagModeType;

    #define PINTHR_DFLT  (U16_MAX-1)            //!< Threshold set to default value [Low: 2000mV, High:  3500mV]
                                                //!<                                [Low: 5000µA, High: 15000µA]

    #define PINTHR_VIN_THR_LO   2000            //!< [mV] Threshold low
    #define PINTHR_VIN_THR_HI   3500            //!< [mV] Threshold high
    #define PINTHR_CIN_THR_LO   5000            //!< [µA] Threshold low
    #define PINTHR_CIN_THR_HI  15000            //!< [µA] Threshold high

    #define PWM_FREQDFLT_VAL    200             //!< Default frequency

    #define ECU_PWM_DOU_MAX_DUTY 0xFFFF          //!< 100% Duty Cycle [0xFFFF]




    // Available PWM frequencies
    #define PINPWM_4000      4000   //!< [Hz] PWM frequency - only LS
    #define PINPWM_2000      2000   //!< [Hz] PWM frequency - only LS
    #define PINPWM_1333      1333   //!< [Hz] PWM frequency - only LS
    #define PINPWM_1000      1000   //!< [Hz] PWM frequency
    #define PINPWM_800        800   //!< [Hz] PWM frequency
    #define PINPWM_667        667   //!< [Hz] PWM frequency
    #define PINPWM_571        571   //!< [Hz] PWM frequency
    #define PINPWM_500        500   //!< [Hz] PWM frequency
    #define PINPWM_444        444   //!< [Hz] PWM frequency
    #define PINPWM_400        400   //!< [Hz] PWM frequency
    #define PINPWM_364        364   //!< [Hz] PWM frequency
    #define PINPWM_333        333   //!< [Hz] PWM frequency
    #define PINPWM_307        307   //!< [Hz] PWM frequency
    #define PINPWM_286        286   //!< [Hz] PWM frequency
    #define PINPWM_267        267   //!< [Hz] PWM frequency
    #define PINPWM_250        250   //!< [Hz] PWM frequency
    #define PINPWM_235        235   //!< [Hz] PWM frequency
    #define PINPWM_222        222   //!< [Hz] PWM frequency
    #define PINPWM_210        210   //!< [Hz] PWM frequency
    #define PINPWM_200        200   //!< [Hz] PWM frequency
    #define PINPWM_182        182   //!< [Hz] PWM frequency
    #define PINPWM_167        167   //!< [Hz] PWM frequency
    #define PINPWM_152        152   //!< [Hz] PWM frequency
    #define PINPWM_143        143   //!< [Hz] PWM frequency
    #define PINPWM_133        133   //!< [Hz] PWM frequency
    #define PINPWM_125        125   //!< [Hz] PWM frequency
    #define PINPWM_118        118   //!< [Hz] PWM frequency
    #define PINPWM_111        111   //!< [Hz] PWM frequency
    #define PINPWM_105        105   //!< [Hz] PWM frequency
    #define PINPWM_100        100   //!< [Hz] PWM frequency
    #define PINPWM_91          91   //!< [Hz] PWM frequency
    #define PINPWM_83          83   //!< [Hz] PWM frequency
    #define PINPWM_77          77   //!< [Hz] PWM frequency
    #define PINPWM_71          71   //!< [Hz] PWM frequency
    #define PINPWM_67          67   //!< [Hz] PWM frequency
    #define PINPWM_63          63   //!< [Hz] PWM frequency
    #define PINPWM_59          59   //!< [Hz] PWM frequency
    #define PINPWM_56          56   //!< [Hz] PWM frequency
    #define PINPWM_53          53   //!< [Hz] PWM frequency
    #define PINPWM_50          50   //!< [Hz] PWM frequency





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
        DIAGSTATE_PRERUN    = 0x04,             //!< Diagnostic state machine is in pre-run state
                                                //!< I/O init is complete, output test have been triggered. Startup tests are being executed.
        DIAGSTATE_MAIN      = 0x06,             //!< Diagnostic state machine is in main state. Startup test have been finished.
        DIAGSTATE_SAFE      = 0x09,             //!< Diagnostic state machine is in safe state
        DIAGSTATE_UNDEF     = 0xFF              //!< Undefined  - BSP call is wrong
    }EDiagState;

    //! Diagnostic error code structure
    typedef struct
    {
        TUint32 u32ErrorCode;                     //!< BSP value: error code
        TUint8  u8DeviceNum;                      //!< BSP value: error device
    }TDiaErrorCode;

    //! Status function for diagnostic state machine
    typedef struct
    {
        EDiagState    eDiagState;             //!<  current state of the diagnostic state machine
        TDiaErrorCode tDiagError;             //!<  error codes of the diagnostic state machine
    }TDiagStatus;

    #ifdef COMPILER_SWITCH_TAR_HW
    // reduced trap type
    typedef enum
    {
        TRAP_TYPE_NONE,             //!< no trap stored
        TRAP_TYPE_MMU,              //!< mmu issue(not supported)
        TRAP_TYPE_PROTECTION,       //!< mpu/access violation(check read/write/execution rights)
        TRAP_TYPE_NULLPOINTER,      //!< nullpointer access
        TRAP_TYPE_BUS_ERROR,        //!< bus/peripheral error, could be access to invalid/uninitialized memory/crc error
        TRAP_TYPE_ILLEGAL_CODE,     //!< executed invalid code
        TRAP_TYPE_ADDR_ALIGNMENT,   //!< unaligned memory access or some other address constraint violated
        TRAP_TYPE_CONTEXT,          //!< context save/restore issue
        TRAP_TYPE_FPU,              //!< FPU error(e.g. null pointer if not configured without trap)
        TRAP_TYPE_COPROCESSOR,      //!< coprocessor error(other than FPU)
        TRAP_TYPE_ARITHMETIC,       //!< arithmetic error
        TRAP_TYPE_SYSCALL,          //!< system call
        TRAP_TYPE_INTERRUPT,        //!< non-maskable external interrupt, e.g. wd timer
        TRAP_TYPE_UNKNOWN           //!< other trap
    } EMatchTrapType;

    //full TTC trap type
    typedef enum
    {
        E_TTC_TRAP_UNKNOWN = 0,
        // Class 0 - MMU
        E_TTC_TRAP_C0_T0_VAF,   //!< Synch. HW Virtual Address Fill.
        E_TTC_TRAP_C0_T1_VAP,   //!< Synch. HW Virtual Address Protection.
        // Class 1 - Internal Protection Traps
        E_TTC_TRAP_C1_T1_PRIV,  //!< Synch. HW Privileged Instruction.
        E_TTC_TRAP_C1_T2_MPR,   //!< Synch. HW Memory Protection Read.
        E_TTC_TRAP_C1_T3_MPW,   //!< Synch. HW Memory Protection Write.
        E_TTC_TRAP_C1_T4_MPX,   //!< Synch. HW Memory Protection Execution.
        E_TTC_TRAP_C1_T5_MPP,   //!< Synch. HW Memory Protection Peripheral Access.
        E_TTC_TRAP_C1_T6_MPN,   //!< Synch. HW Memory Protection Null Address.
        E_TTC_TRAP_C1_T7_GRWP,  //!< Synch. HW Global Register Write Protection.
        // Class 2 - Instruction Errors
        E_TTC_TRAP_C2_T1_IOPC,  //!< Synch. HW Illegal Opcode.
        E_TTC_TRAP_C2_T2_UOPC,  //!< Synch. HW Unimplemented Opcode.
        E_TTC_TRAP_C2_T3_OPD,   //!< Synch. HW Invalid Operand specification.
        E_TTC_TRAP_C2_T4_ALN,   //!< Synch. HW Data Address Alignment.
        E_TTC_TRAP_C2_T5_MEM,   //!< Synch. HW Invalid Local Memory Address.
        // Class 3 - Context Management
        E_TTC_TRAP_C3_T1_FCD,   //!< Synch. HW Free Context List Depletion (FCX = LCX).
        E_TTC_TRAP_C3_T2_CDO,   //!< Synch. HW Call Depth Overflow.
        E_TTC_TRAP_C3_T3_CDU,   //!< Synch. HW Call Depth Underflow.
        E_TTC_TRAP_C3_T4_FCU,   //!< Synch. HW Free Context List Underflow (FCX = 0).
        E_TTC_TRAP_C3_T5_CSU,   //!< Synch. HW Call Stack Underflow (PCX = 0).
        E_TTC_TRAP_C3_T6_CTYP,  //!< Synch. HW Context Type (PCXI.UL wrong).
        E_TTC_TRAP_C3_T7_NEST,  //!< Synch. HW Nesting Error: RFE with non-zero call depth.
        // Class 4 - System Bus and Peripheral Errors
        E_TTC_TRAP_C4_T1_PSE,   //!< Synch. HW Program Fetch Synchronous Error.
        E_TTC_TRAP_C4_T2_DSE,   //!< Synch. HW Data Access Synchronous Error.
        E_TTC_TRAP_C4_T3_DAE,   //!< Asynch. HW Data Access Asynchronous Error.
        E_TTC_TRAP_C4_T4_CAE,   //!< Asynch HW Coprocessor Trap Asynchronous Error.
        E_TTC_TRAP_C4_T5_PIE,   //!< Synch HW Program Memory Integrity Error.
        E_TTC_TRAP_C4_T6_DIE,   //!< Asynch HW Data Memory Integrity Error.
        E_TTC_TRAP_C4_T7_TAE,   //!< Asynch HW Temporal Asynchronous Error
        // Class 5 - Assertion Traps
        E_TTC_TRAP_C5_T1_OVF,   //!< Synch. SW Arithmetic Overflow.
        E_TTC_TRAP_C5_T2_SOVF,  //!< Synch. SW Sticky Arithmetic Overflow.
        // Class 6 - System Call
        E_TTC_TRAP_C6_SYS,      //!< Synch. SW System Call.
        // Class 7 - Non-Maskable Interrupt
        E_TTC_TRAP_C7_T0_NMI,   //!< Asynch. HW Non-Maskable Interrupt.
    }ETtcTrapType;

    // trap origin
    typedef enum
    {
        TRAP_ORG_APP,           //!< application caused trap
        TRAP_ORG_SYS,           //!< system task/bsp caused trap
        TRAP_ORG_UNKNOWN        //!< other trap origin
    }EMatchTrapOrigin;

    //! Status function for traps
    typedef struct
    {
        EMatchTrapType   eTrapType;     //!<  trap type
        EMatchTrapOrigin eTrapOrigin;   //!<  trap origin
        TUint8           u8Core;        //!<  core that trap occurred on
    }TTrapStatus;

    typedef union
    {
        // Bit-wise access.
        struct
        {
            TUint32 u32Sre  : 1; //!< [0] Scratch range error.
            TUint32 u32Gae  : 1; //!< [1] Global Address Error.
            TUint32 u32Lbe  : 1; //!< [2] Load Bus Error.
            TUint32 u32Dre  : 1; //!< [3] Local DLMU Range Error.
            TUint32 u32Res0 : 2; //!< [5:4] Reserved.
            TUint32 u32Cre  : 1; //!< [6] Cache Refill Error.
            TUint32 u32Res1 : 7; //!< [13:7] Reserved.
            TUint32 u32Dtme : 1; //!< [14] DTAG MSIST Error.
            TUint32 u32Loe  : 1; //!< [15] Load Overlay Error.
            TUint32 u32Sde  : 1; //!< [16] Segment Difference Error.
            TUint32 u32Sce  : 1; //!< [17] Segment Crossing Error.
            TUint32 u32Cac  : 1; //!< [18] CSFR Access Error.
            TUint32 u32Mpe  : 1; //!< [19] Memory Protection Error.
            TUint32 u32Cle  : 1; //!< [20] Context Location Error.
            TUint32 u32Res2 : 3; //!< [23:21] Reserved.
            TUint32 u32Aln  : 1; //!< [24] Alignment Error.
            TUint32 u32Res3 : 7; //!< [31:25] Reserved.
        }tBitwise;
        TUint32 u32UnsignedAccess; //!< Unsigned access.
    }UTrapDstrType;

    typedef struct
    {
        TUint32 u32AddrOfAccess; //!< The field addrOfAccess stores the content of the DEADD register
                                 //!< and thus contains the trap address information for the data memory system.
        UTrapDstrType uDstr;     //!< Content of the Data Synchronous Error Trap Register (DSTR)
                                 //!< updated in case of E_TT_TRAP_C4_T2_DSE, E_TT_TRAP_C2_T4_ALN,
                                 //!< E_TT_TRAP_C2_T5_MEM and Data memory protection traps
        UTrapDstrType uDatr;     //!< Content of the Data Asynchronous Error Trap Register (DATR)
                                 //!< updated in case of E_TT_TRAP_C4_T3_DAE traps
        TUint8 u8Tcn;            //!< Hardware defined trap class number.
        TUint8 u8Tin;            //!< Hardware defined Trap Identification Number (TIN).
        ETtcTrapType eTtcTrap;   //!< Resolved trap class and TIN and information.
    }TTrapInfoType;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the trap information
    //! @details    Check, if there is a trap recorded. The application should read and evaluate the trap
    //!             information on each boot. The trap record is cleared with this get function.
    //!             It is recommended to use an error block for trap handling. It is useful to check
    //!             the trap information in an early app phase e.g. eAppPreStart() to avoid re-run of
    //!             the same trap.
    //! @param[out] ptTrapSta   - Diagnose trap status struct (NULL Save)
    //!             ->eTrapType - TRAP_TYPE_NONE    in case no trap exists
    //!                         - TRAP_TYPE_UNKNOWN in case a trap exists but there are no additional
    //!                                             trap information available
    //!                         - all others: see more information in definition of EMatchTrapType
    //! @param[out] ptTrapInfo  - Diagnose trap info struct (NULL Save)
    //! @retval     R_OKAY  - fine
    //! @retval     R_EMPTY - no trap record is available
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetEcuTrapInfo( TTrapStatus *ptTrapSta, TTrapInfoType *ptTrapInfo );

    #endif //COMPILER_SWITCH_TAR_HW

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the diagnose status
    //! @param[out] ptDiagSta - Diagnose Struct (NULL Save)
    //! @retval     R_OKAY  - fine
    //! @retval     R_UNDEF - struct is not valid
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetEcuDiagStatus( TDiagStatus *ptDiagSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      ReInit the IoDriver - currently not used on TTC2xxx
    //! @param[in]  pfeReInitIoDriver  - The function call to re init
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreReInitIoDriver( ERetVal (*pfeReInitIoDriver)( TVoid ) );




    //! Bsp Diag Error Code
    typedef struct
    {
        TUint8  u8ErrorCode;        //!< The error code
        TUint8  u8DeviceNum;        //!< The device number which caused the error. This can either be an internal Device Diagnostic devices
        TUint32 u32FaultyValue;     //!< The value which caused the error
    }TBspDiagErrCode;


    //--------------------------------------------------------------------------------------------------
    //! @brief      Show Ecu Diag Information - ( SafeState is a print warning, all other are just a print )
    //! @param[in]  boShowOnlyIfSafeState - Give only the status information if 'Safe-State' is active
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreShowEcuDiagInfo( TBoolean boShowOnlyIfSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      If this function is called during the normal run mode the controller goes to flash mode and waits for the CAN request of
    //!             the TTC downloader. This enables the possibility for flashing the controller through other ECU, because hard power cycle
    //!             is not needed and the other ECU can send the flash mode request.
    //!             Currently no function in TTC2xxx
    //! @retval     R_OKAY         - Fine
    //! @retval     R_UNKNOWN      - Error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreWdSoftReset( TVoid );

    #ifdef COMPILER_SWITCH_TAR_HW
    //--------------------------------------------------------------------------------------------------
    //! @brief      This function can only be called in the AppFixInit to set the Watchdog timeout
    //! @param[in]  u16WdTimeout   - Watchdog timeout in ms
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetWdTimeout( TUint16 u16WdTimeout );

    //--------------------------------------------------------------------------------------------------
    //! @brief      This function can be called in the vAppSafetyInit to deactivate the output startup tests
    //!             No usage in safety applications recommended - please check the safety manual!
    //!             TTC functions affected by output startup tests:
    //!             - PWM and DOP output pins
    //!             If the startup tests are disabled, pins that are used as output pins(DOP_x or PWM_x)
    //!             can be initialized after ECU_APP_INIT otherwise this is not possible anymore.
    //!             Disabled output startup test also mean, that the PWM or DOP outputs can be activated
    //!             immediately after initialization
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreDeactStartUpTests( TVoid );



    #endif // COMPILER_SWITCH_TAR_HW

    #ifdef COMPILER_SWITCH_TAR_PC

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set diagnose status
    //! @param[in]  ptDiagSta      - Diagnose struct
    //! @retval     R_OKAY         - struct is valid
    //! @retval     R_NULL_POINTER - ptDiagSta is a NULL pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSimSetEcuDiagStatus( TDiagStatus *ptDiaStatus );


    // D I A G N O S T I C   S T A T E   M A C H I N E   E R R O R   V A L U E S

    //status values are currently dummies for simulation
    #define  TT_S_OK                        0

    #define  TT_S_SSP_LIMIT_MIN             1
    #define  TT_S_SSP_LIMIT_MAX             2
    #define  TT_S_SSP_OPERATION_FAILED      3

    #define  TT_S_ADC_PROT_ACTIVE           9
    #define  TT_S_ADC_PROT_REENABLE         10
    #define  TT_S_ADC_PROT_PERMANENT_OFF    11
    #define  TT_S_ADC_SWITCH_CHECK_PERIODIC 12
    #define  TT_S_ADC_LIMIT_MIN             13
    #define  TT_S_ADC_LIMIT_MAX             14

    #define  TT_S_DOP_STARTUP
    #define  TT_S_DOP_STARTUP_SHORT_GND     15
    #define  TT_S_DOP_STARTUP_OPEN_LOAD     16
    #define  TT_S_DOP_STARTUP_SHORT_BAT     17
    #define  TT_S_DOP_STARTUP_SHORT_OTHER   18
    #define  TT_S_DOP_STARTUP_RSO           19
    #define  TT_S_DOP_PROT_ACTIVE           20
    #define  TT_S_DOP_PROT_REENABLE         21
    #define  TT_S_DOP_PROT_PERMANENT_OFF    22
    #define  TT_S_DOP_SHORT_GND             23
    #define  TT_S_DOP_OPEN_LOAD             24
    #define  TT_S_DOP_SHORT_BAT             25
    #define  TT_S_DOP_PWR_OFF               26
    #define  TT_S_DOP_BUSY                  27

    #define TT_S_PWM_STARTUP                28
    #define TT_S_PWM_STARTUP_SHORT_GND      29
    #define TT_S_PWM_STARTUP_OPEN_LOAD      30
    #define TT_S_PWM_STARTUP_SHORT_BAT      31
    #define TT_S_PWM_STARTUP_SHORT_OTHER    32
    #define TT_S_PWM_STARTUP_RSO            33
    #define TT_S_PWM_PROT_ACTIVE            34
    #define TT_S_PWM_PROT_REENABLE          35
    #define TT_S_PWM_PROT_PERMANENT_OFF     36
    #define TT_S_PWM_SHORT_GND              37
    #define TT_S_PWM_OPEN_LOAD              38
    #define TT_S_PWM_SHORT_BAT              39
    #define TT_S_PWM_PWR_OFF                40
    #define TT_S_PWM_BUSY                   41
    #define TT_S_PWM_PULSE_LENGTHENED       42
    #define TT_S_PWM_PERIOD_MISMATCH        43

    #define TT_S_ECU_VALUE_OOR              44
    #define TT_S_ECU_LIMIT_MIN              45
    #define TT_S_ECU_LIMIT_MAX              46
    #define TT_S_ECU_FATAL_VALUE_OOR        47
    #define TT_S_ECU_FATAL_LIMIT_MIN        48
    #define TT_S_ECU_FATAL_LIMIT_MAX        49
    #define TT_S_ECU_FATAL_ETR_STARTUP      50
    #define TT_S_ECU_FATAL_ETR_PRE          51
    #define TT_S_ECU_FATAL_ETR_VMON         52
    #define TT_S_ECU_FATAL_ETR_VMON_SOP     53
    #define TT_S_ECU_FATAL_ETR_SMU          54
    #define TT_S_ECU_FATAL_ETR_SMU_SOP      55
    #define TT_S_ECU_FATAL_ETR_SMU_RESP     56
    #define TT_S_ECU_FATAL_ETR_WD           57
    #define TT_S_ECU_FATAL_ETR_WD_SOP       58
    #define TT_S_ECU_FATAL_ETR_VMON_PRE     59
    #define TT_S_ECU_FATAL_ETR_VMON_OVP     60
    #define TT_S_ECU_FATAL_ETR_VMON_UVP     61
    #define TT_S_ECU_FATAL_ETR_VMON_RST     62
    #define TT_S_ECU_FATAL_OS_CORRUPTION    63

    #define TT_S_SSW_STARTUP                64
    #define TT_S_SSW_STARTUP_SHORT_GND      65
    #define TT_S_SSW_STARTUP_SHORT_BAT      66
    #define TT_S_SSW_STARTUP_SHORT_OTHER    67
    #define TT_S_SSW_PROT_PERMANENT_OFF     68
    #define TT_S_SSW_SHORT_GND              69
    #define TT_S_SSW_SHORT_BAT              70
    #define TT_S_SSW_PWR_OFF                71
    #define TT_S_SSW_BUSY                   72

    #define  TT_S_LPO_PROT_ACTIVE           73
    #define  TT_S_LPO_PROT_REENABLE         74
    #define  TT_S_LPO_PROT_PERMANENT_OFF    75

    #define  TT_S_WDT_FATAL_MISSED_LO       76
    #define  TT_S_WDT_FATAL_MISSED_HI       77
    #define  TT_S_WDT_FATAL_MISSED_START    78
    #define  TT_S_WDT_FATAL_SUPERVISION     79

    #define TT_STATUS_SCOPE_OFFS_ECU_USR    (0x00EF0000UL)
    #define TT_STATUS_SEVERITY_FATAL        (0xC0000000UL)


    #endif // COMPILER_SWITCH_TAR_PC

    //! Offset for app safestate status value
    #define DIAG_SAFESTATE_APP_TRIGGERED    0x1U
    //! Reported status value for app triggered safestate
    #define ECU_USR_SAFESTATE ( TT_STATUS_SEVERITY_FATAL | TT_STATUS_SCOPE_OFFS_ECU_USR | DIAG_SAFESTATE_APP_TRIGGERED )



    //! CAN wakeup message configuration
    typedef struct
    {
        TBoolean boIdExtended;   //!< TRUE:=Extended CAN ID, FALSE:=Standard CAN ID
        TUint32  u32Id;          //!< CAN-ID to match
        TUint32  u32IdMask;      //!< Mask for the CAN ID, set every bit to 0 for bits in u32Id that have to be matched
        TBoolean boUseDataMask;  //!< TRUE:=DLC/Datamask to be matched against received frame,FALSE:=only ID checked
        TUint8   u8Dlc;          //!< Data length code
        TUint8   au8DataMask[8]; //!< Data mask, match if at least one set bit in data mask matches received msg data
    } TCanWakeupMessage;

    //--------------------------------------------------------------------------------------------------
    //! @brief      CAN wakeup(TTC23XX: CAN2, TTC2038: CAN1) enable/wakeup message config
    //! @pre        call in vAppSafetyInit
    //!             (in later phases ecu must have been started via k15/wakeup pin before can wakeup possible))
    //! @details    can wakeup functionality does not acknowledge can frames,
    //!             application should configure the wakeup can port with same CAN speed to confirm messages
    //!             and avoid bus error/transmit loops in case no other bus participant is available
    //! @param      eBaudRate - Baudrate
    //! @param[in]  cpctWakeUpMessage - wakeup message configuration, NULL=any signal causes wakeup
    //! @retval     R_OKAY          - can wakeup enabled
    //! @retval     R_PARAMETER     - invalid wakeup message configuration
    //! @retval     R_PHASE         - called in wrong phase(driver not ready)
    //! @retval     R_SUPPORT       - CAN wakeup not supported
    //! @retval     R_UNKNOWN       - system error(e.g. not enough os ressources)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreCanWakeupEnable( EBitRate eBaudRate, const TCanWakeupMessage* const cpctWakeUpMessage );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Configure K15 thresholds and shutdown behavior
    //! @pre        call in vAppFixInit
    //! @warning    Fixed transition threshold for sleep mode to operational mode(wakeup) is ~3.6V(see TTC2xxx SystemManual).\n
    //!             configuring highMin>3.6V threshold might currently cause reset loop in the range [3.6V,highMin] with boK15ForceDown=FALSE
    //! @param      u16LowMin       - [ms]Minimum threshold for low level interpretation(DFLT:0)
    //! @param      u16LowMax       - [ms]Maximum threshold for low level interpretation(DFLT:2500)
    //! @param      u16HighMin      - [ms]Minimum threshold for high level interpretation(DFLT:2500)
    //! @param      u16HighMax      - [ms]Maximum threshold for high level interpretation(DFLT:65535)
    //! @param      boK15ForceDown  - TRUE: K15 needs to go <3.6V after shutdown to cause wakeup again
    //!                             - FALSE: K15 > 3.6V causes wakeup (DFLT: FALSE)
    //! @retval     R_OKAY          - ok
    //! @retval     R_INCONSISTENT  - threshold values are inconsistent, must be:
    //!             -   highMax >= highMin
    //!             -   highMax >= lowMax
    //!             -   highMin >= lowMin
    //!             -   lowMax  >= lowMin
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreConfigK15OffBehavior( TUint16 u16LowMin, TUint16 u16LowMax,
                                              TUint16 u16HighMin, TUint16 u16HighMax, TBoolean boK15ForceDown );

   #endif // COMPILER_SWITCH_FAM_TTC20XX

#endif // __ITFBOARDCENTTC20XX__
