//**************************************************************************************************
/*!
@file       ItfBoardCenTtc5xx.h
@brief      CEN TTC5xx
@date       23.08.2013
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBOARDCENTTC5XX__
  #define __ITFBOARDCENTTC5XX__

   #include <autoconfig.h>
   #include <ItfCoreBoardBasic.h>

   #ifdef COMPILER_SWITCH_FAM_TTC5XX


    #define COMPILER_SWITCH_BSP_DIAGSTATE_MACHINE
    #define COMPILER_SWITCH_FLASH_SETTING
    #define COMPILER_SWITCH_SEC_APP
    #define COMPILER_SWITCH_ETH_HEXFILE_FLASH
    #define COMPILER_SWITCH_WAKE_UP_PIN
    #define COMPILER_SWITCH_FORCE_FEATURE

    #define COMPILER_SWITCH_EXTERNAL_FLASH_ACCESS

    #if defined(COMPILER_SWITCH_ECU_TTC580) || defined(COMPILER_SWITCH_ECU_TTC590) || defined(COMPILER_SWITCH_ECU_TTC508)
        #define COMPILER_SWITCH_USR_CHNG_MNGMNT_FEATURE
    #endif

#ifdef COMPILER_SWITCH_ENV_CEN
    #define COMPILER_SWITCH_MPU
#endif

    #define COMPILER_SWITCH_INIT_WATCHDOG

    #define COMPILER_SWITCH_DB_LIST_64
    #define COMPILER_SWITCH_BLO_60_SIG_60

    #define COMPILER_SWITCH_RSBUS
    #define COMPILER_SWITCH_LINBUS
    #define COMPILER_SWITCH_ETHBUS

    #define COMPILER_SWITCH_CANBUS
       #define _CS_CANBUS_7_

    //! Can Bus
    typedef enum
    {
        CAN_BUS0,          //!< CAN Bus 0
        CAN_BUS1,          //!< CAN Bus 1
        CAN_BUS2,          //!< CAN Bus 3
        CAN_BUS3,          //!< CAN Bus 4
        CAN_BUS4,          //!< CAN Bus 5
        CAN_BUS5,          //!< CAN Bus 6
        CAN_BUS6,          //!< CAN Bus 7
        CAN_BUS_MAX        //!< CAN Bus Max
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

    #define TTC5XX_HW_SND_BUFFER_MAX_SIZE 32 //!< Maximal send Hw buffer size  5*7= 32

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

        CBUS2_HWBUF_RCV0,    //!< 28 - Receive hardware buffer
        CBUS2_HWBUF_RCV1,    //!< 29 - Receive hardware buffer
        CBUS2_HWBUF_RCV2,    //!< 30 - Receive hardware buffer
        CBUS2_HWBUF_RCV3,    //!< 31 - Receive hardware buffer
        CBUS2_HWBUF_RCV4,    //!< 32 - Receive hardware buffer
        CBUS2_HWBUF_RCV5,    //!< 33 - Receive hardware buffer
        CBUS2_HWBUF_RCV6,    //!< 34 - Receive hardware buffer
        CBUS2_HWBUF_RCV7,    //!< 35 - Receive hardware buffer
        CBUS2_HWBUF_SND0,    //!< 36 - Send hardware buffer
        CBUS2_HWBUF_SND1,    //!< 37 - Send hardware buffer
        CBUS2_HWBUF_SND2,    //!< 38 - Send hardware buffer
        CBUS2_HWBUF_SND3,    //!< 39 - Send hardware buffer
        CBUS2_HWBUF_SND4,    //!< 40 - Send hardware buffer
        CBUS2_HWBUF_SND5,    //!< 41 - Send hardware buffer


        CBUS3_HWBUF_RCV0,    //!< 42 - Receive hardware buffer
        CBUS3_HWBUF_RCV1,    //!< 43 - Receive hardware buffer
        CBUS3_HWBUF_RCV2,    //!< 44 - Receive hardware buffer
        CBUS3_HWBUF_RCV3,    //!< 45 - Receive hardware buffer
        CBUS3_HWBUF_RCV4,    //!< 46 - Receive hardware buffer
        CBUS3_HWBUF_RCV5,    //!< 47 - Receive hardware buffer
        CBUS3_HWBUF_RCV6,    //!< 48 - Receive hardware buffer
        CBUS3_HWBUF_RCV7,    //!< 49 - Receive hardware buffer
        CBUS3_HWBUF_SND0,    //!< 50 - Send hardware buffer
        CBUS3_HWBUF_SND1,    //!< 51 - Send hardware buffer
        CBUS3_HWBUF_SND2,    //!< 52 - Send hardware buffer
        CBUS3_HWBUF_SND3,    //!< 53 - Send hardware buffer
        CBUS3_HWBUF_SND4,    //!< 54 - Send hardware buffer
        CBUS3_HWBUF_SND5,    //!< 55 - Send hardware buffer

        CBUS4_HWBUF_RCV0,    //!< 56 - Receive hardware buffer
        CBUS4_HWBUF_RCV1,    //!< 57 - Receive hardware buffer
        CBUS4_HWBUF_RCV2,    //!< 58 - Receive hardware buffer
        CBUS4_HWBUF_RCV3,    //!< 59 - Receive hardware buffer
        CBUS4_HWBUF_RCV4,    //!< 60 - Receive hardware buffer
        CBUS4_HWBUF_RCV5,    //!< 61 - Receive hardware buffer
        CBUS4_HWBUF_RCV6,    //!< 62 - Receive hardware buffer
        CBUS4_HWBUF_RCV7,    //!< 63 - Receive hardware buffer
        CBUS4_HWBUF_SND0,    //!< 64 - Send hardware buffer
        CBUS4_HWBUF_SND1,    //!< 65 - Send hardware buffer
        CBUS4_HWBUF_SND2,    //!< 66 - Send hardware buffer
        CBUS4_HWBUF_SND3,    //!< 67 - Send hardware buffer
        CBUS4_HWBUF_SND4,    //!< 68 - Send hardware buffer
        CBUS4_HWBUF_SND5,    //!< 69 - Send hardware buffer

        CBUS5_HWBUF_RCV0,    //!< 70 - Receive hardware buffer
        CBUS5_HWBUF_RCV1,    //!< 71 - Receive hardware buffer
        CBUS5_HWBUF_RCV2,    //!< 72 - Receive hardware buffer
        CBUS5_HWBUF_RCV3,    //!< 73 - Receive hardware buffer
        CBUS5_HWBUF_RCV4,    //!< 74 - Receive hardware buffer
        CBUS5_HWBUF_RCV5,    //!< 75 - Receive hardware buffer
        CBUS5_HWBUF_RCV6,    //!< 76 - Receive hardware buffer
        CBUS5_HWBUF_RCV7,    //!< 77 - Receive hardware buffer
        CBUS5_HWBUF_SND0,    //!< 78 - Send hardware buffer
        CBUS5_HWBUF_SND1,    //!< 79 - Send hardware buffer
        CBUS5_HWBUF_SND2,    //!< 80 - Send hardware buffer
        CBUS5_HWBUF_SND3,    //!< 81 - Send hardware buffer
        CBUS5_HWBUF_SND4,    //!< 82 - Send hardware buffer
        CBUS5_HWBUF_SND5,    //!< 83 - Send hardware buffer

        CBUS6_HWBUF_RCV0,    //!< 84 - Receive hardware buffer
        CBUS6_HWBUF_RCV1,    //!< 85 - Receive hardware buffer
        CBUS6_HWBUF_RCV2,    //!< 86 - Receive hardware buffer
        CBUS6_HWBUF_RCV3,    //!< 87 - Receive hardware buffer
        CBUS6_HWBUF_RCV4,    //!< 88 - Receive hardware buffer
        CBUS6_HWBUF_RCV5,    //!< 89 - Receive hardware buffer
        CBUS6_HWBUF_RCV6,    //!< 90 - Receive hardware buffer
        CBUS6_HWBUF_RCV7,    //!< 91 - Receive hardware buffer
        CBUS6_HWBUF_SND0,    //!< 92 - Send hardware buffer
        CBUS6_HWBUF_SND1,    //!< 93 - Send hardware buffer
        CBUS6_HWBUF_SND2,    //!< 94 - Send hardware buffer
        CBUS6_HWBUF_SND3,    //!< 95 - Send hardware buffer
        CBUS6_HWBUF_SND4,    //!< 96 - Send hardware buffer
        CBUS6_HWBUF_SND5,    //!< 97 - Send hardware buffer
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
        IDX_66,
        IDX_67,
        IDX_68,
        IDX_69,
        IDX_70,
        IDX_71,
        IDX_72,
        IDX_73,
        IDX_74,
        IDX_75,
        IDX_76,
        IDX_77,
        IDX_78,
        IDX_79,
        IDX_80,
        IDX_81,
        IDX_82,
        IDX_83,
        IDX_84,
        IDX_85,
        IDX_86,
        IDX_87,
        IDX_88,
        IDX_89,
        IDX_90,
        IDX_91,
        IDX_92,
        IDX_93,
        IDX_94,
        IDX_95,
        IDX_96,
        IDX_MAX
    };

    #define FIRST_OUTPUT_PIN  IDX_37                   //!< First output PIN
    #define FIRST_MULTI_PIN   IDX_37                   //!< First multiple PIN
    #define SYSPIN_MAX             7                   //!< System PIN

    #define PIN_OVER_ALL      (IDX_MAX + SYSPIN_MAX)   //!< All PINs

    typedef enum
    {
        PIN_SYS = IDX_00,   //!< System pin
        // G01 - 3 Mode
        PIN_103 = IDX_01,   //!< [00] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_104 = IDX_02,   //!< [01] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_105 = IDX_03,   //!< [02] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_106 = IDX_04,   //!< [03] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_127 = IDX_05,   //!< [04] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_128 = IDX_06,   //!< [05] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_129 = IDX_07,   //!< [06] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        PIN_130 = IDX_08,   //!< [07] Analog inputs (VIN:5V / CIN:24mA / RES:100k)
        // G02 - 2 mode 10V
        PIN_107 = IDX_09,   //!< [00] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_131 = IDX_10,   //!< [01] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_108 = IDX_11,   //!< [02] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_132 = IDX_12,   //!< [03] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_109 = IDX_13,   //!< [04] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_133 = IDX_14,   //!< [05] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_110 = IDX_15,   //!< [06] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_134 = IDX_16,   //!< [07] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. A)
        PIN_111 = IDX_17,   //!< [08] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_135 = IDX_18,   //!< [09] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_112 = IDX_19,   //!< [10] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_136 = IDX_20,   //!< [11] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_113 = IDX_21,   //!< [12] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_137 = IDX_22,   //!< [13] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_114 = IDX_23,   //!< [14] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        PIN_138 = IDX_24,   //!< [15] Analog inputs (VIN:10V / CIN:24mA) (safety redundant Gr. B)
        // G3
        PIN_115 = IDX_25,   //!< [00] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Mast][Cpx][Cnt]    GRP_INC_1
        PIN_139 = IDX_26,   //!< [01] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Slav][Cpx][Cnt]    GRP_INC_1
        PIN_116 = IDX_27,   //!< [02] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Mast][Cpx][Cnt]    GRP_INC_2
        PIN_140 = IDX_28,   //!< [03] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Slav][Cpx][Cnt]    GRP_INC_2
        PIN_117 = IDX_29,   //!< [04] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Mast][Cpx][Cnt]    GRP_INC_3
        PIN_141 = IDX_30,   //!< [05] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Slav][Cpx][Cnt]    GRP_INC_3
        PIN_122 = IDX_31,   //!< [06] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Mast][Cpx][Cnt]    GRP_INC_4
        PIN_146 = IDX_32,   //!< [07] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Slav][Cpx][Cnt]    GRP_INC_4
        PIN_123 = IDX_33,   //!< [08] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Mast][Cpx][Cnt]    GRP_INC_5
        PIN_147 = IDX_34,   //!< [09] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Slav][Cpx][Cnt]    GRP_INC_5
        PIN_124 = IDX_35,   //!< [10] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Mast][Cpx][Cnt]    GRP_INC_6
        PIN_148 = IDX_36,   //!< [11] Timer inputs (FIN / FIN-Pair / VIN / DIN) [INC-Slav][Cpx][Cnt]    GRP_INC_6
        // G4
        PIN_153 = IDX_37,   //!< [00] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_177 = IDX_38,   //!< [01] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_156 = IDX_39,   //!< [02] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_180 = IDX_40,   //!< [03] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_159 = IDX_41,   //!< [04] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_183 = IDX_42,   //!< [05] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_186 = IDX_43,   //!< [06] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_162 = IDX_44,   //!< [07] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_189 = IDX_45,   //!< [08] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_165 = IDX_46,   //!< [09] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_192 = IDX_47,   //!< [10] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_168 = IDX_48,   //!< [11] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_195 = IDX_49,   //!< [12] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_171 = IDX_50,   //!< [13] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 1
        PIN_154 = IDX_51,   //!< [14] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_178 = IDX_52,   //!< [15] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_157 = IDX_53,   //!< [16] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_181 = IDX_54,   //!< [17] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_160 = IDX_55,   //!< [18] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_184 = IDX_56,   //!< [19] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_187 = IDX_57,   //!< [20] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_163 = IDX_58,   //!< [21] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_190 = IDX_59,   //!< [22] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_166 = IDX_60,   //!< [23] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_193 = IDX_61,   //!< [24] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_169 = IDX_62,   //!< [25] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_196 = IDX_63,   //!< [26] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        PIN_172 = IDX_64,   //!< [27] HS PWM controlled output 3A (PWM_C / DOU_C / DIN) Grp 2
        // G04A
        PIN_101 = IDX_65,   //!< [28] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_125 = IDX_66,   //!< [29] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_150 = IDX_67,   //!< [30] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_174 = IDX_68,   //!< [31] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_102 = IDX_69,   //!< [32] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_126 = IDX_70,   //!< [33] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_151 = IDX_71,   //!< [34] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        PIN_175 = IDX_72,   //!< [35] HS PWM controlled output 3A (PWN_C / DOU_C / DIN / FIN / PUL) [CPX]   Grp 3
        // G05
        PIN_149 = IDX_73,   //!< [00] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_173 = IDX_74,   //!< [01] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_152 = IDX_75,   //!< [02] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_176 = IDX_76,   //!< [03] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_155 = IDX_77,   //!< [04] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_179 = IDX_78,   //!< [05] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_158 = IDX_79,   //!< [06] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        PIN_182 = IDX_80,   //!< [07] HS Digital output 4A (DOU_CV / VIN / DIN)  (Option LED Driver)
        // G05
        PIN_251 = IDX_81,   //!< [00] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_238 = IDX_82,   //!< [01] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_252 = IDX_83,   //!< [02] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_239 = IDX_84,   //!< [03] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_253 = IDX_85,   //!< [04] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_240 = IDX_86,   //!< [05] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_254 = IDX_87,   //!< [06] LS Digital Outout 4A (DOU_C / VIN / DIN)
        PIN_241 = IDX_88,   //!< [07] LS Digital Outout 4A (DOU_C / VIN / DIN)
        // G06 - THIS GROUP IS ONLY A PART FROM THE TTC580
        PIN_161 = IDX_89,   //!< [00] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_185 = IDX_90,   //!< [01] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_188 = IDX_91,   //!< [02] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_164 = IDX_92,   //!< [03] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_191 = IDX_93,   //!< [04] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_167 = IDX_94,   //!< [05] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_194 = IDX_95,   //!< [06] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_170 = IDX_96,   //!< [07] Ratiometric Voltage output 4A (VOU / DOU_CV / VIN 32V / DIN) (Option LED Driver HS)
        PIN_MAX = IDX_MAX,
        PIN_NA
    }EPin;

    //! Voltage reference types
    enum
    {
        PINRSL_NA,          //!< 0 - Voltage variable: Not available
        PINRSL_5V,          //!< 1 - Voltage variable: 5V Ref
        PINRSL_10V,         //!< 2 - Voltage variable: 10V Ref
        PINRSL_32V          //!< 3 - Voltage variable: 32V Ref
    };

    //! PIN supply
    enum
    {
        PINSUPPLY_NA,       //!< 0 - No sensor voltage PIN supply
        #ifdef COMPILER_SWITCH_ECU_TTC508
        PINSUPPLY_S0        //!< 1 - Voltage PIN supply sensor '0'
        #else
        PINSUPPLY_S0,       //!< 1 - Voltage PIN supply sensor '0'
        PINSUPPLY_S1,       //!< 2 - Voltage PIN supply sensor '1'
        PINSUPPLY_S2        //!< 3 - Voltage PIN supply sensor '2'
        #endif
    };


    // System PINs
    #define PIN_SYS_BAT       (IDX_MAX)    //!<  97 - for TTC500
    #define PIN_SYS_K15       (IDX_MAX+1)  //!<  98 - for TTC500
    #define PIN_SYS_TEMP      (IDX_MAX+2)  //!<  99 - for TTC500
    #define PIN_SYS_REF       (IDX_MAX+3)  //!< 100 - for TTC500
    #define PIN_SYS_S0        (IDX_MAX+4)  //!< 101 - for TTC500
    #define PIN_SYS_S1        (IDX_MAX+5)  //!< 102 - for TTC500
    #define PIN_SYS_S2        (IDX_MAX+6)  //!< 103 - for TTC500
    #define PIN_SYS_SAFESTATE (IDX_MAX+7)  //!< 104 - for TTC500
    #define PIN_SYS_POWSTAGE  (IDX_MAX+8)  //!< 105 - for TTC500
    #define PIN_SYS_SAFESW0   (IDX_MAX+9)  //!< 106 - for TTC500
    #define PIN_SYS_SAFESW1   (IDX_MAX+10) //!< 107 - for TTC500
    #define PIN_SYS_SAFESW2   (IDX_MAX+11) //!< 108 - for TTC500
    #define PIN_SYS_WAKEUP    (IDX_MAX+12) //!< 109 - for TTC500

    #define PIN_SYS_START  PIN_SYS_BAT     //!< for TTC500
    #define PIN_SYS_END    PIN_SYS_S2      //!< for TTC500
    #define PIN_HST_END    PIN_SYS_END     //!< for TTC500

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
        PINTYP_DOU       =  _PINTYP_DOU,        //!< Type: [0/1]   Digital output

        PINTYP_PWM       = _PINTYP_PWM,         //!< Type: [duty]  PWM output
        PINTYP_LED       = _PINTYP_LED,         //!< Type: [0/1]   LED output
        PINTYP_PVG       = _PINTYP_PVG,         //!< Type: [%/100] Percent of Ubat [1500..8500] , not available for TTC540
        PINTYP_VOU       = _PINTYP_VOU          //!< Type: [mV]    Voltage output               , not available for TTC540

    }EAppPinTyp;

    //! Resistor
    typedef enum
    {
        PINRES_NA,                              //!< 0 - Resistor: Option not there
        PINRES_PULLUP,                          //!< 1 - Resistor: Pull Up   - 10K Ohm PTD standard value (equal PINRES_PULLUP_10K)
        PINRES_PULLDO,                          //!< 2 - Resistor: Pull Down - 10K Ohm PTD standard value (equal PINRES_PULLDO_10K)
        PINRES_PULLUP_10K,                      //!< 3 - Resistor: Pull Up   - 10K Ohm
        PINRES_PULLDO_10K,                      //!< 4 - Resistor: Pull Down - 10K Ohm
        PINRES_PULLDO_1K8,                      //!< 5 - Resistor: Pull Down - 1.8K Ohm
        PINRES_PULLDO_110,                      //!< 6 - Resistor: Pull Down - 110 Ohm
        PINRES_CFG_NA                           //!< 7 - Resistor: Configuration not option
    }EAppPinRes;

    //! Critical Mode
    typedef enum
    {
        CIO_NA,                                 //!< 0 - not applicable
        CIO_SAFESTA,                            //!< 1 - ecu enter the safe state
        CIO_NOREACT,                            //!< 2 - no reaction - ecu don't enter the safe state, if possible
        CIO_OUTOFF                              //!< 3 - Reaction driver off - if possible the pin or the pin group will shut off
    }ECioState;


    #define PINTHR_DFLT  (U16_MAX-1)            //!< Threshold set to default value [Low: 2000mV, High:  3500mV]
                                                //!<                                [Low: 5000µA, High: 15000µA]

    #define PINTHR_VIN_THR_LO   2000            //!< [mV] Threshold low
    #define PINTHR_VIN_THR_HI   3500            //!< [mV] Threshold high
    #define PINTHR_CIN_THR_LO   5000            //!< [µA] Threshold low
    #define PINTHR_CIN_THR_HI  15000            //!< [µA] Threshold high

    #define PWM_FREQDFLT_VAL    200             //!< Default frequency

    #define ECU_PWM_DOU_MAX_DUTY 60000          //!< 92,25% Duty Cycle [0xEA60]

    #define PINPWM_1000         1000            //!< PWM frequency
    #define PINPWM_800          800             //!< PWM frequency
    #define PINPWM_666          666             //!< PWM frequency
    #define PINPWM_571          571             //!< PWM frequency
    #define PINPWM_500          500             //!< PWM frequency
    #define PINPWM_444          444             //!< PWM frequency
    #define PINPWM_400          400             //!< PWM frequency
    #define PINPWM_363          363             //!< PWM frequency
    #define PINPWM_333          333             //!< PWM frequency
    #define PINPWM_307          307             //!< PWM frequency
    #define PINPWM_285          285             //!< PWM frequency
    #define PINPWM_266          266             //!< PWM frequency
    #define PINPWM_250          250             //!< PWM frequency
    #define PINPWM_235          235             //!< PWM frequency
    #define PINPWM_222          222             //!< PWM frequency
    #define PINPWM_210          210             //!< PWM frequency
    #define PINPWM_200          200             //!< PWM frequency
    #define PINPWM_181          181             //!< PWM frequency
    #define PINPWM_166          166             //!< PWM frequency
    #define PINPWM_153          153             //!< PWM frequency
    #define PINPWM_142          142             //!< PWM frequency
    #define PINPWM_133          133             //!< PWM frequency
    #define PINPWM_125          125             //!< PWM frequency
    #define PINPWM_117          117             //!< PWM frequency
    #define PINPWM_111          111             //!< PWM frequency
    #define PINPWM_105          105             //!< PWM frequency
    #define PINPWM_100          100             //!< PWM frequency
    #define PINPWM_90            90             //!< PWM frequency
    #define PINPWM_83            83             //!< PWM frequency
    #define PINPWM_76            76             //!< PWM frequency
    #define PINPWM_71            71             //!< PWM frequency
    #define PINPWM_66            66             //!< PWM frequency
    #define PINPWM_62            62             //!< PWM frequency
    #define PINPWM_58            58             //!< PWM frequency
    #define PINPWM_55            55             //!< PWM frequency
    #define PINPWM_52            52             //!< PWM frequency
    #define PINPWM_50            50             //!< PWM frequency

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
    }TDiagStatus;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the diagnose status
    //! @param[out] ptDiagSta - Diagnose Struct (NULL Save)
    //! @retval     R_OKAY  - fine
    //! @retval     R_UNDEF - struct is not valid
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetEcuDiagStatus( TDiagStatus *ptDiagSta );

    //--------------------------------------------------------------------------------------------------
    //! @brief      ReInit the IoDriver - Please take care to use that function
    //! @param[in]  pfeReInitIoDriver  - The function call to re init
    //!             NOTE: Don't use that function in combination with the Critical-Input/Output Pin setting.
    //!             NOTE: This function destroys the match safety reaction - but it is possible to managed that by the own.
    //!             NOTE: Keep the function call (error_callback, notify_callback) so short as possible. It is forbidden to use string processing function,
    //!                   therefore all print functions are forbidden
    //! @details Example:
    //! <pre>
    //!     #ifdef COMPILER_SWITCH_FAM_TTC5XX
    //!     #include <IO_Driver.h>
    //!     #include <DIAG_Constants.h>
    //!     #include <DIAG_Functions.h>
    //!
    //!     IO_DRIVER_SAFETY_CONF g_tSafetyCf;
    //!
    //!     TUint16 u16ErrCallback( TUint8 u8DiagState, TUint8 u8WatchdogState, DIAG_ERRORCODE* const ptErr )
    //!     {
    //!         if(ptErr->error_code == DIAG_E_ADC_3MODE_SWITCH_TEST && ptErr->device_num == IO_ADC_00 ) { return DIAG_ERR_SAFESTATE; }
    //!         else                                                                                     { return DIAG_ERR_NOACTION;  }
    //!     }
    //!
    //!     ERetVal eReInitIoDriver( TVoid )
    //!     {
    //!         g_tSafetyCf.command_period      = 10000;                                  // [µs] Task Time
    //!         g_tSafetyCf.window_size         = SAFETY_CONF_WINDOW_SIZE_25_PERCENT;
    //!         g_tSafetyCf.reset_behavior      = SAFETY_CONF_RESETS_DISABLED;
    //!         g_tSafetyCf.glitch_filter_time  = 30;
    //!         g_tSafetyCf.error_callback      = u16ErrCallback;
    //!         g_tSafetyCf.notify_callback     = NULL;
    //!
    //!         if( IO_E_OK == IO_Driver_Init( &g_tSafetyCf ) ){ return R_OKAY;    }
    //!         else                                           { return R_UNKNOWN; }
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
    //! </pre>
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreReInitIoDriver( ERetVal (*pfeReInitIoDriver)( TVoid ) );


    // See for more detalis in the BSP documentation (e.g BSP(TTC5xx)Driver.h: SAFETY_CONF_WINDOW_SIZE_100_PERCENT
    #define BSP_SAFETY_CONF_WINDOW_SIZE_100_PERCENT     ( 0U )
    #define BSP_SAFETY_CONF_WINDOW_SIZE_50_PERCENT      ( 1U )
    #define BSP_SAFETY_CONF_WINDOW_SIZE_25_PERCENT      ( 2U )
    #define BSP_SAFETY_CONF_WINDOW_SIZE_12_5_PERCENT    ( 3U )
    #define BSP_SAFETY_CONF_WINDOW_SIZE_6_25_PERCENT    ( 4U )
    #define BSP_SAFETY_CONF_WINDOW_SIZE_3_125_PERCENT   ( 5U )

    //--------------------------------------------------------------------------------------------------
    //! @brief      Reinit the watchdog timing behavior (this function must be called in the vAppFixInit(),
    //!                                                   and is soft reset stable)
    //! @param[in]  u8GlitchFt   -  Only if an error condition persists after expiration of
    //!                             this time range, an error reaction is taken(1..180 [ms])
    //! @param[in]  u8WindowSize  - Watchdog window size. One of:
    //!                                BSP_SAFETY_CONF_WINDOW_SIZE_100_PERCENT
    //!                                BSP_SAFETY_CONF_WINDOW_SIZE_50_PERCENT
    //!                                BSP_SAFETY_CONF_WINDOW_SIZE_25_PERCENT
    //!                                BSP_SAFETY_CONF_WINDOW_SIZE_12_5_PERCENT
    //!                                BSP_SAFETY_CONF_WINDOW_SIZE_6_25_PERCENT
    //!                                BSP_SAFETY_CONF_WINDOW_SIZE_3_125_PERCENT
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreEcuReWatchdogTiming( TUint8 u8GlitchFt, TUint8 u8WindowSize );

    //! Bsp Diag Error Code
    typedef struct
    {
        TUint8  u8ErrorCode;        //!< The error code
        TUint8  u8DeviceNum;        //!< The device number which caused the error. This can either be an internal Device Diagnostic devices
        TUint32 u32FaultyValue;     //!< The value which caused the error
    }TBspDiagErrCode;

    // --- 24.08.2021: Extend interface for using safety config without callback -----
	typedef struct
	{
		TUint8              u8DiagSta;                  //!< Last callback input parameter: u8DiagSta
		TUint8              u8WatchdogSta;              //!< Last callback input parameter: u8WatchdogSta
		TUint16             u16CoreReaction;            //!< Last callback input parameter: u16CoreReaction
		TUint8              u8ErrorCode;                //!< The error code
		TUint8              u8DeviceNum;                //!< The device number which caused the error. This can either be an internal Device Diagnostic devices
		TUint32             u32FaultyValue;             //!< The value which caused the error
		TUint16             u16Reaction;                //!< Is the return reaction if intern callback called
	}TDiagRecItem;

	typedef struct
	{
		TBoolean            boEnabled;                  //!< TRUE = Enable / FALSE = Disable this reaction settings
		TBoolean            boEnDiagSta;                //!< TRUE = Enable / FALSE = Disable u8DiagSta for reaction
		TBoolean            boEnWatchdogSta;            //!< TRUE = Enable / FALSE = Disable u8WatchdogSta for reaction
		TBoolean            boEnCoreReaction;           //!< TRUE = Enable / FALSE = Disable u16CoreReaction for reaction
		TBoolean            boEnErrorCode;              //!< TRUE = Enable / FALSE = Disable u8ErrorCode for reaction
		TBoolean            boEnDeviceNum;              //!< TRUE = Enable / FALSE = Disable u8DeviceNum for reaction
		TBoolean            boEnFaultyValue;            //!< TRUE = Enable / FALSE = Disable u32FaultyValue for reaction
		TDiagRecItem        tDiagRecItem;               //!< Compare values for trigger the reaction
	}TDiagRecReaction;

	typedef struct
	{
		TUint32             u32OutCallCnt;              //!< Gives the total number of function calls (u32OutCallCnt == 0 --> Never called)
		TUint8              u8CallBufSize;              //!< Size of the buffer array
		TDiagRecItem*       ptCallBuf;                  //!< Array for buffering last function call data (Last item --> ptCallBuf[(u32OutCallCnt-1) % u8CallBufSize])
		TUint8              u8ReactionsCnt;             //!< Size of the reaction array
		TDiagRecReaction*   ptReactions;                //!< Array with reaction settings
	}TDiagRec;
	// --------------------------------------------------------------------------------

    #define BSP_DIAG_ERR_NOACTION       0x0001U        //!< take no action (ignore the error)
    #define BSP_DIAG_ERR_SAFESTATE      0x0002U        //!< enter the safe state (switch off all outputs)
    #define BSP_DIAG_ERR_DISABLE_SSW0   0x0004U        //!< disable the shut-off group 0 (#IO_INT_SAFETY_SW_0)
    #define BSP_DIAG_ERR_DISABLE_SSW1   0x0008U        //!< disable the shut-off group 1 (#IO_INT_SAFETY_SW_1)
    #define BSP_DIAG_ERR_DISABLE_SSW2   0x0010U        //!< disable the shut-off group 2 (#IO_INT_SAFETY_SW_2)
    #define BSP_DIAG_ERR_DISABLE_HS00   0x0020U        //!< disable the high side digital output 0 (#IO_DO_00)
    #define BSP_DIAG_ERR_DISABLE_HS01   0x0040U        //!< disable the high side digital output 1 (#IO_DO_01)
    #define BSP_DIAG_ERR_DISABLE_HS02   0x0080U        //!< disable the high side digital output 2 (#IO_DO_02)
    #define BSP_DIAG_ERR_DISABLE_HS03   0x0100U        //!< disable the high side digital output 3 (#IO_DO_03)
    #define BSP_DIAG_ERR_DISABLE_HS04   0x0200U        //!< disable the high side digital output 4 (#IO_DO_04)
    #define BSP_DIAG_ERR_DISABLE_HS05   0x0400U        //!< disable the high side digital output 5 (#IO_DO_05)
    #define BSP_DIAG_ERR_DISABLE_HS06   0x0800U        //!< disable the high side digital output 6 (#IO_DO_06)
    #define BSP_DIAG_ERR_DISABLE_HS07   0x1000U        //!< disable the high side digital output 7 (#IO_DO_07)

    //--------------------------------------------------------------------------------------------------
    //! @brief      u16CorePostSafetyCb
    //!             NOTE: This function destroys the match safety reaction - but it is possible to managed that by the own.
    //! @param[in]  u8DiagState      - Diagnostic state
    //! @param[in]  u8WatchdogState  - Watchdog state
    //! @param[in]  u16CoreReaction  - is the core 'match'-reaction
    //! @param[in]  pctErr           - Bsp diagnostic error code
    //! @return     new safe state reaction - [BSP_DIAG_ERR_SAFESTATE or  BSP_DIAG_ERR_NOACTION]
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreSetPostSafetyCbFct( TUint16 (*pfu16CorePostSafetyCb)( TUint8 u8DiagState, TUint8 u8WatchdogState, TUint16 u16CoreReaction, TBspDiagErrCode *const pctErr ) );

    // --- 24.08.2021: Extend interface for using safety config without callback -----

        //--------------------------------------------------------------------------------------------------
        //! @brief      vCoreSetSafteyConfig
        //!             NOTE: This function sets a data structure for handle the safety configuration without using a callback.
        //!                   Overwrites a callback function, if set with "vCoreSetPostSafetyCbFct" before
        //!                   TVoid Example()
        //!                   {
        //!                   	TUint32 u32Cnt = 0;
        //!                   	TDiagRecItem tRecBuffer[2];
        //!                   	TDiagRecReaction tReaction[2] =
        //!                   	{
        //!                   		{
        //!                   			TRUE,										// Enable this reaction
        //!                   			TRUE, TRUE, TRUE, TRUE, TRUE, TRUE,			// Enable the properties who has to processed
        //!                   			{
        //!                   				0, 0, 0, 0, 0, 0,						// Expected values of the properties
        //!                   				DIAG_ERR_SAFESTATE						// Return value if expected values matches
        //!                   			}
        //!                   		},
        //!                   		{
        //!                   			TRUE,										// Enable this reaction
        //!                   			TRUE, TRUE, TRUE, TRUE, TRUE, TRUE,			// Enable the properties who has to processed
        //!                   			{
        //!                   				1, 1, 1, 1, 1, 1,						// Expected values of the properties
        //!                   				DIAG_ERR_SAFESTATE						// Return value if expected values matches
        //!                   			}
        //!                   		}
        //!                   	};
        //!
        //!                   	TDiagRec tCfg =
        //!                   	{
        //!                   		0,												// u32OutCallCnt	(Outgoing counter of function calls)
        //!                   		2,												// u8CallBufSize	(Size of array tRecBuffer)
        //!                   		&tRecBuffer,									// taCallBuf		(Buffer array for collecting last callback data)
        //!                   		2,												// u8ReactionsCnt	(Size of array tReaction)
        //!                   		&tReaction										// taReactions		(Array with defined reactions by incoming data)
        //!                   	};
        //!
        //!                   	vCoreSetSafteyConfig(&tCfg);
        //!
        //!                   	// ...
        //!
        //!                   	u32Cnt = 0;
        //!                   	while(TRUE)	// represents a frequently called function like "vAppRun"
        //!                   	{
        //!                   		if(tCfg.u32OutCallCnt > u32Cnt)			// Example for just one entry. Could read all entries here from "u32Cnt" to "tCfg.u32OutCallCnt"
        //!                   		{
        //!                   			vPrint("FaultyValue: %d", tCfg.taCallBuf[u32Cnt % tCfg.u8CallBufSize].u32FaultyValue);
        //!                   			u32Cnt++;
        //!                   		}
        //!                   	}
        //!                   }
        //! @param[in]  ptSafetyConfig    - Safety configuration data structure
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreSetSafteyConfig( TDiagRec* ptSafetyConfig );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Show Ecu Diag Information - ( SafeState is a print warning, all other are just a print )
    //! @param[in]  boShowOnlyIfSafeState - Give only the status information if 'Safe-State' is active
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreShowEcuDiagInfo( TBoolean boShowOnlyIfSafeState );

    //--------------------------------------------------------------------------------------------------
    //! @brief      If this function is called during the normal run mode the controller goes to flash mode and waits for the CAN request of
    //!             the TTC downloader. This enables the possibility for flashing the controller through other ECU, because hard power cycle
    //!             is not needed and the other ECU can send the flash mode request.
    //! @retval     R_OKAY         - Fine
    //! @retval     R_UNKNOWN      - Error
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreWdSoftReset( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Configure if defined negative return values for IO_Driver_Init should be handled as positive case(bypassed)
    //! @warning    Use this function on your own risk.\n
    //!             Handling wrong return values might cause unsafe system state!\n
    //!             !THE USE OF THIS FUNCTION IN THE APPLICATION WILL VOID THE HYDAC PRODUCT LIABILITY!
    //! @details    Bypass handles the return values defined by user in cau16BspValue.\n
    //!             These could be [undocumented] return values of IO_Driver_Init that occur in special situations, e.g. after flashing without K15/30.
    //!             Safe state might be active.\n
    //!             Call in vAppFixInit.\n
    //!             Example:
    //!             <pre>
    //!             TVoid vAppFixInit( TVoid )
    //!             {
    //!                 #ifdef COMPILER_SWITCH_TAR_HW
    //!                 const TUint16 cau16BspRet[] = {IO_E_INVALID_ESM_INIT_STATUS, IO_E_INVALID_CHANNEL_ID, IO_E_SAFE_STATE, IO_E_WD_INITIALIZATION};
    //!                 vCoreTtcDriverInitRetBypass( TRUE, cau16BspRet );
    //!                 #endif
    //!                 ...
    //!             }
    //!             </pre>
    //! @param[in]  boBypass         - TRUE: bypass active, FALSE: bypass inactive(dflt)
    //! @param[in]  cau16BspValue[4] - array containing 4 TTC ERROR return values from IO_Error.h(IO_ErrorType), set unused elements to IO_E_OK
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCoreTtcDriverInitRetBypass( TBoolean boBypass, const TUint16 cau16BspValue[4] );

    #ifdef COMPILER_SWITCH_TAR_PC

            //--------------------------------------------------------------------------------------------------
            //! @brief      Set diagnose status
            //! @param[in]  ptDiagSta      - Diagnose struct
            //! @retval     R_OKAY         - struct is valid
            //! @retval     R_NULL_POINTER - ptDiagSta is a NULL pointer
            //--------------------------------------------------------------------------------------------------
            extern ERetVal eCoreSimSetEcuDiagStatus( TDiagStatus *ptDiaStatus );

           // D I A G N O S T I C   S T A T E   M A C H I N E   S T A T E S
           #define DIAG_STATE_DISABLED                  0x00UL //!< Diagnostic state machine is disabled
           #define DIAG_STATE_INIT                      0x03UL //!< Diagnostic state machine is in init state
           #define DIAG_STATE_CONFIG                    0x05UL //!< Diagnostic state machine is in config state
           #define DIAG_STATE_MAIN                      0x06UL //!< Diagnostic state machine is in main state
           #define DIAG_STATE_SAFE                      0x09UL //!< Diagnostic state machine is in safe state

           #define DIAG_WD_STATE_STANDBY                 0x01U //!< Watchdog CPU is in standby state
           #define DIAG_WD_STATE_RESET                   0x03U //!< Watchdog CPU is in reset state
           #define DIAG_WD_STATE_DIAGNOSTIC              0x05U //!< Watchdog CPU is in diagnostic state
           #define DIAG_WD_STATE_ACTIVE                  0x06U //!< Watchdog CPU is in active state
           #define DIAG_WD_STATE_SAFE                    0x09U //!< Watchdog CPU is in safe state
           #define DIAG_WD_STATE_UNKNOWN                 0xFFU //!< Watchdog CPU is in an unknown state

           // D I A G N O S T I C   S T A T E   M A C H I N E   E R R O R   V A L U E S

           #define DIAG_E_NOERROR                           0U  //!< no error
           #define DIAG_E_ADC_3MODE_SWITCH_TEST             1U  //!< ADC 3mode switches test error
           #define DIAG_E_ADC_3MODE_SWITCH_PERIODIC         2U  //!< ADC 3mode switches periodic check error
           #define DIAG_E_ADC_2MODE_RED_CHANNEL_TEST        3U  //!< ADC 2mode redundant channel test error
           #define DIAG_E_ADC_SR_CONF_CHECK                 4U  //!< ADC shift register configuration check error
           #define DIAG_E_ADC_RANGE                         5U  //!< ADC value out of range
           #define DIAG_E_ADC_UBAT                          6U  //!< ADC battery voltage out of range
           #define DIAG_E_ADC_BOARD_TEMP                    7U  //!< ADC board temperature out of range
           #define DIAG_E_ADC_SENSOR_SUPPLY                 8U  //!< ADC sensor supply out of range
           #define DIAG_E_ADC_2V5_REF                       9U  //!< ADC 2V5 reference out of range
           #define DIAG_E_ADC_1V2                          10U  //!< ADC 1V2 supply out of range
           #define DIAG_E_ADC_VPGATE                       11U  //!< ADC VP Gate voltage out of range
           #define DIAG_E_PWM_SHORT_CIRCUIT                12U  //!< PWM check detected a short circuit
           #define DIAG_E_PWM_OPEN_LOAD                    13U  //!< PWM check detected an open load
           #define DIAG_E_PWM_FEEDBACK                     14U  //!< PWM feedback (pulse/period) out of range
           #define DIAG_E_PWM_CURRENT                      15U  //!< PWM current check error
           #define DIAG_E_DO_SHORT_CIRCUIT                 16U  //!< DO check detected a short circuit
           #define DIAG_E_DO_OPEN_LOAD                     17U  //!< DO check detected an open load
           #define DIAG_E_DO_FEEDBACK                      18U  //!< DO feedback value out of range
           #define DIAG_E_PWD_RANGE                        19U  //!< PWD value out of range
           #define DIAG_E_PWD_CURRENT                      20U  //!< PWD current check error
           #define DIAG_E_PWD_THRESH                       21U  //!< PWD threshold out of range
           #define DIAG_E_SSW_TEST                         22U  //!< Safety switch test error
           #define DIAG_E_SSW_PERIODIC                     23U  //!< Safety switch periodic check error
           #define DIAG_E_SSW_EXT_SHUTOFF                  24U  //!< Safety switch external shut off redundancy check error
           #define DIAG_E_VMON_TEST                        25U  //!< Voltage monitor test error
           #define DIAG_E_VMON_PERIODIC                    26U  //!< Voltage monitor periodic check error
           #define DIAG_E_ENABLE_TREE_TEST                 27U  //!< Enable tree test error
           #define DIAG_E_WD_INIT                          28U  //!< internal error, watchdog initialization failed
           #define DIAG_E_WD_ACTIVATION                    29U  //!< internal error, watchdog activation failed
           #define DIAG_E_WD_TRIGGER                       30U  //!< internal error, watchdog triggering failed
           #define DIAG_E_INIT_CORE_L2L3                   31U  //!< L2L3 interconnect test error
           #define DIAG_E_INIT_CORE_EFUSE_ECC              32U  //!< eFuse controller test error
           #define DIAG_E_INIT_CORE_FLASH_WR_ECC           33U  //!< Flash Module Controller - ECC logic test error
           #define DIAG_E_INIT_CORE_STC_TEST               34U  //!< CPU self-test controller test error
           #define DIAG_E_INIT_CORE_SELFTEST               35U  //!< CPU self-test error
           #define DIAG_E_INIT_CORE_PSCON_SELFTEST         36U  //!< Diagnostic power state controller test error
           #define DIAG_E_INIT_CORE_PBIST_TEST             37U  //!< Programmable built-in self-test controller test error
           #define DIAG_E_INIT_CORE_RAM_ECC_B0             38U  //!< CPU ECC logic for accesses to TCRAM B0 test error
           #define DIAG_E_INIT_CORE_RAM_ECC_B1             39U  //!< CPU ECC logic for accesses to TCRAM B1 test error
           #define DIAG_E_INIT_CORE_FLASH_DATA_ECC         40U  //!< CPU ECC logic accesses to program flash test error
           #define DIAG_E_INIT_CORE_CFG_FLASH_ECC          41U  //!< CPU ECC logic accesses to configuration flash test error
           #define DIAG_E_INIT_CORE_IOMM_LOCK              42U  //!< IOMM Lock test error
           #define DIAG_E_INIT_CORE_CCM_SELFTEST           43U  //!< CCM-R4F module test error
           #define DIAG_E_INIT_CORE_ADD_DECODE_B0          44U  //!< TCRAM B0 address redundant comparator test error
           #define DIAG_E_INIT_CORE_ADD_DECODE_B1          45U  //!< TCRAM B1 address redundant comparator test error
           #define DIAG_E_INIT_CORE_DCC1_SELFTEST          46U  //!< DCC1 self-test error
           #define DIAG_E_INIT_CORE_DCC2_SELFTEST          47U  //!< DCC2 self-test error
           #define DIAG_E_INIT_CORE_ERROR_PIN_TEST         48U  //!< Error detected during initialization nERROR pin test
           #define DIAG_E_INIT_CORE_MPU_TEST               49U  //!< MPU test error detected during initialization
           #define DIAG_E_INIT_CORE_RAM_PARITY_TEST        50U  //!< RAM parity test error detected during initialization
           #define DIAG_E_INIT_CORE_RAM_PBIST              51U  //!< RAM self-test error detected during initialization
           #define DIAG_E_CORE_READBACK                    52U  //!< Configuration read back error
           #define DIAG_E_APPL_SAFE_STATE                  53U  //!< Application requested to activate the safe state
           #define DIAG_E_DRIVER_INIT                      54U  //!< Error detected during the execution of \c IO_Driver_Init()
           #define DIAG_E_DATA_ABORT                       55U  //!< Abort exception generated - Data Abort
           #define DIAG_E_PREFETCH_ABORT                   56U  //!< Abort exception generated - Prefetch Abort
           #define DIAG_E_UNDEF_INSTRUCTION                57U  //!< Exception generated - Undefined instruction
           #define DIAG_E_ESM_HLI                          58U  //!< ESM exception generated - High Level Interrupt
           #define DIAG_E_ESM_LLI                          59U  //!< ESM exception generated - Low Level Interrupt
           #define DIAG_E_ESM_LLI_CALLBACK                 60U  //!< ESM exception generated - Low Level Interrupt/Callback
           #define DIAG_E_PARITIY_FALLBACK                 61U  //!< Interrupt vector parity fallback exception generated
           #define DIAG_E_INVALID_DIAG_STATE               62U  //!< internal error, invalid state for diag state machine
           #define DIAG_E_INVALID_IRQ                      63U  //!< Invalid interrupt detected
           #define DIAG_E_PRG_OVERFLOW                     64U  //!< Program overflow
           #define DIAG_E_MAIN_LOOP                        65U  //!< The main loop has been left illegally

           // D I A G   D E V I C E S
           #define DIAG_DEV_SAFETY_SW_VP                   112  //!< Safety Switch VP (intern Mapping: IO_INT_PIN_SAFETY_SW_VP)
           #define DIAG_DEV_PWD                            117  //!< PWD threshold comparator (intern Mapping: IO_INT_PIN_PWD)
           #define DIAG_DEV_REF_2V5                         54  //!< 2.5V reference voltage (intern Mapping: IO_INT_PIN_REF_2V5)
           #define DIAG_DEV_1V2                            122  //!< 1.2V supply voltage (intern Mapping: IO_INT_PIN_1V2)
           #define DIAG_DEV_VMON                           123  //!< Voltage monitor (intern Mapping: IO_INT_PIN_VMON)

           #define DIAG_DEV_MCU                            132U //!< TMS570 MCU peripheral
           #define DIAG_DEV_ESM                            133U //!< TMS570 ESM peripheral
           #define DIAG_DEV_VIM                            134U //!< TMS570 VIM peripheral
           #define DIAG_DEV_ADC                            135U //!< TMS570 ADC peripheral
           #define DIAG_DEV_SPI                            136U //!< TMS570 SPI peripheral
           #define DIAG_DEV_DIO                            137U //!< TMS570 DIO peripheral
           #define DIAG_DEV_RTC                            138U //!< TMS570 RTC peripheral
           #define DIAG_DEV_DMA                            139U //!< TMS570 DMA peripheral
           #define DIAG_DEV_NHET                           140U //!< TMS570 NHET peripheral

           #define DIAG_DEV_ESM_MIBADC2_PARITY             141U //!< MibADC2 - parity error
           #define DIAG_DEV_ESM_DMA_MPU_VIOLATION          142U //!< DMA - MPU
           #define DIAG_DEV_ESM_DMA_PARITY                 143U //!< DMA - parity error
           #define DIAG_DEV_ESM_DMA_DMM_IMPR_READ          144U //!< DMA - imprecise read error
           #define DIAG_DEV_ESM_N2HET1_2_PARITY            145U //!< N2HET1/N2HET2 - parity error
           #define DIAG_DEV_ESM_HET_TU1_2_PARITY           146U //!< HET TU1/HET TU2 - parity error
           #define DIAG_DEV_ESM_PLL1_SLIP                  147U //!< PLL - Slip
           #define DIAG_DEV_ESM_CLOCK_MONITOR              148U //!< Clock Monitor - interrupt
           #define DIAG_DEV_ESM_DMA_DMM_IMPR_WRITE         149U //!< DMA - imprecise write error
           #define DIAG_DEV_ESM_VIM_RAM_PARITY             150U //!< VIM RAM - parity error
           #define DIAG_DEV_ESM_MIBSPI1_PARITY             151U //!< MibSPI1 - parity error
           #define DIAG_DEV_ESM_MIBSPI3_PARITY             152U //!< MibSPI3 - parity error
           #define DIAG_DEV_ESM_MIBADC1_PARITY             153U //!< MibADC1 - parity error
           #define DIAG_DEV_ESM_CPU_SLFTST                 154U //!< CPU - self-test error
           #define DIAG_DEV_ESM_DCC1_ERROR                 155U //!< DCC1 - error
           #define DIAG_DEV_ESM_CCM_R4_SLFTST              156U //!< CCM-R4 - self-test error
           #define DIAG_DEV_ESM_FMC_CFG_FLASH_UNC_ERR      157U //!< FMC - uncorrectable error (configuration flash bank access)
           #define DIAG_DEV_ESM_IOMM_MUX_CONFIG            158U //!< IOMM - Mux configuration error
           #define DIAG_DEV_ESM_PWR_DOM_CNTL_COMP          159U //!< Power domain controller compare error
           #define DIAG_DEV_ESM_PWR_DOM_CNTL_SLFTST        160U //!< Power domain controller self-test error
           #define DIAG_DEV_ESM_E_FUSE_CNTL                161U //!< eFuse Controller error
           #define DIAG_DEV_ESM_E_FUSE_CNTL_SLFTST         162U //!< eFuse Controller - self-test error
           #define DIAG_DEV_ESM_PLL2_SLIP                  163U //!< PLL2 - Slip
           #define DIAG_DEV_ESM_DCC2                       164U //!< DCC2 - error
           #define DIAG_DEV_ESM_CCMR4_COMPARE              165U //!< CCMR4 - compare error
           #define DIAG_DEV_ESM_FMC_B1_UNC_ERR             166U //!< FMC - uncorrectable error (address parity on bus1 accesses)
           #define DIAG_DEV_ESM_RAM_B0_UNC_ERR             167U //!< RAM even bank (B0TCM) - uncorrectable error
           #define DIAG_DEV_ESM_RAM_B1_UNC_ERR             168U //!< RAM odd bank (B1TCM) - uncorrectable error
           #define DIAG_DEV_ESM_RAM_B0_ADDR_PARITY         169U //!< RAM even bank (B0TCM) - address bus parity error
           #define DIAG_DEV_ESM_RAM_B1_ADDR_PARITY         170U //!< RAM odd bank (B1TCM) - address bus parity error
           #define DIAG_DEV_ESM_FLASH_ECC_LIVE_LOCK        171U //!< Flash (ATCM) - ECC live lock detect
           #define DIAG_DEV_ESM_RTI_WDD_NMI                172U //!< RTI_WWD_NMI
           #define DIAG_DEV_ESM_E_FUSE_AUTOLOAD            173U //!< eFuse Controller - autoload error
           #define DIAG_DEV_ESM_RAM_B0_ECC_UNC_ERR         174U //!< RAM even bank (B0TCM) - ECC uncorrectable error
           #define DIAG_DEV_ESM_RAM_B1_ECC_UNC_ERR         175U //!< RAM odd bank (B1TCM) - ECC uncorrectable error
           #define DIAG_DEV_ESM_FMC_B1_B2_UNC_ERR          176U //!< FMC - uncorrectable error: bus1 and bus2 interfaces
           #define DIAG_DEV_ESM_UNKNOWN                    177U //!< Unknown ESM device

           #define DIAG_DEV_2MODE_CONF_0                   178U //!< 2Mode ADC Configuration 0
           #define DIAG_DEV_2MODE_CONF_1                   179U //!< 2Mode ADC Configuration 1
           #define DIAG_DEV_2MODE_CONF_2                   180U //!< 2Mode ADC Configuration 2
           #define DIAG_DEV_2MODE_CONF_3                   181U //!< 2Mode ADC Configuration 3
           #define DIAG_DEV_2MODE_CONF_4                   182U //!< 2Mode ADC Configuration 4
           #define DIAG_DEV_2MODE_CONF_5                   183U //!< 2Mode ADC Configuration 5
           #define DIAG_DEV_2MODE_CONF_6                   184U //!< 2Mode ADC Configuration 6
           #define DIAG_DEV_2MODE_CONF_7                   185U //!< 2Mode ADC Configuration 7

           #define DIAG_DEV_PWD_CONF_0                     186U //!< PWD Configuration 0
           #define DIAG_DEV_PWD_CONF_1                     187U //!< PWD Configuration 1
           #define DIAG_DEV_PWD_CONF_2                     188U //!< PWD Configuration 2
           #define DIAG_DEV_PWD_CONF_3                     189U //!< PWD Configuration 3
           #define DIAG_DEV_PWD_CONF_4                     190U //!< PWD Configuration 4
           #define DIAG_DEV_PWD_CONF_5                     191U //!< PWD Configuration 5

           #define DIAG_DEV_DO_CONF_0                      192U //!< DO Configuration 0
           #define DIAG_DEV_DO_CONF_1                      193U //!< DO Configuration 1
           #define DIAG_DEV_DO_CONF_2                      194U //!< DO Configuration 2

           #define DIAG_DEV_EXT_SHUTOFF_0                  195U //!< External shut off group 0
           #define DIAG_DEV_EXT_SHUTOFF_1                  196U //!< External shut off group 1
           #define DIAG_DEV_EXT_SHUTOFF_2                  197U //!< External shut off group 2

           #define DIAG_DEV_WATCHDOG_CPU                   198U //!< Watchdog CPU
           #define DIAG_DEV_MAIN_CPU                       199U //!< Main CPU

       #endif

    #endif

#endif
