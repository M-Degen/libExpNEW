//**************************************************************************************************
//! @crc        2055324210
//! @file       App_ErrDefine.h
//! @brief      Generate by: HYDAC Controller Project - Code Builder Tool Chain
//! @ecu        TTC32S
//! @dll        1.4.0 (Build: 021)
//! @dll itf    1.7.0
//! @build      2025-03-12 15:24:11
//! @Match      07-08-00-00
//! @PDT        2.12.91.55
//! @PdtProjVer 0.0.0
//! @created    2026-05-08 10:34:48   HYDAC/HCP-CC
//**************************************************************************************************

#ifndef __APP_ERRDEFINE_H__
#define __APP_ERRDEFINE_H__

#ifdef COMPILER_SWITCH_ACTIVE_2APP
#include <2App_ErrDefine.h>
#endif // COMPILER_SWITCH_ACTIVE_2APP

enum
{ //!< Fmi - bit position
    FMI_00_VALID_ABOVE_NORM_MOST_SEVERE      =    0,
    FMI_01_VALID_BELOW_NORM_MOST_SEVERE      =    1,
    FMI_02_DATA_INCORRECT                    =    2,
    FMI_03_VOLTAGE_HIGH_SHT_PWR              =    3,
    FMI_04_VOLTAGE_LOW_SHT_GND               =    4,
    FMI_05_CURRENT_LOW_OC                    =    5,
    FMI_06_CURRENT_HIGH_SHT_GND              =    6,
    FMI_07_MECH_SYS_NOT_RESP                 =    7,
    FMI_08_ABNORM_FREQ_PW_PER                =    8,
    FMI_09_ABNORM_UPDATE_RATE_TIMEOUT        =    9,
    FMI_10_ABNORM_RATE_OF_CHG                =    10,
    FMI_11_ROOT_CAUSE_UNKNOWN                =    11,
    FMI_12_BAD_DEVICE                        =    12,
    FMI_13_OUT_OF_CAL                        =    13,
    FMI_14_SPECIAL_INSTRUCTIONS              =    14,
    FMI_15_VALID_ABOVE_NORM_LEAST_SEVERE     =    15,
    FMI_16_VALID_ABOVE_NORM_MOD_SEVERE       =    16,
    FMI_17_VALID_BELOW_NORM_LEAST_SEVERE     =    17,
    FMI_18_VALID_BELOW_NORM_MOD_SEVERE       =    18,
    FMI_19_RCV_NETWORK_DATA_ERR              =    19,
    FMI_20_DATA_DRIFTED_HIGH                 =    20,
    FMI_21_DATA_DRIFTED_LOW                  =    21,
    FMI_22_NO_SIGNAL                         =    22,
    FMI_23_NOT_CALIBRATED                    =    23,
    FMI_24_LOGICAL_ERROR                     =    24,
    FMI_25_STUCK_OPEN                        =    25,
    FMI_26_OUT_OF_RANGE                      =    26,
    FMI_27_OC_SHT_GND                        =    27,
    FMI_28_OC_SHT_PWR                        =    28,
    FMI_29_RESERVE                           =    29,
    FMI_30_RESERVE                           =    30,
    FMI_31_CONDITION_EXISTS                  =    31
};

#endif // __APP_ERRDEFINE_H__

