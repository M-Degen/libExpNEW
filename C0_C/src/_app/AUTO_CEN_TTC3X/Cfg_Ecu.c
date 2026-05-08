//**************************************************************************************************
//! @crc        2127236091
//! @file       Cfg_Ecu.c
//! @brief      Generate by: HYDAC Controller Project - Code Builder Tool Chain
//! @ecu        TTC32S
//! @dll        1.4.0 (Build: 021)
//! @dll itf    1.7.0
//! @build      2025-03-12 15:24:11
//! @Pattern    1.3.3
//! @Subpattern ----
//! @Match      07-08-00-00
//! @PDT        2.12.91.55
//! @PdtProjVer 0.0.0
//! @created    2026-05-08 10:34:48   HYDAC/HCP-CC
//**************************************************************************************************

// INCLUDES ========================================================================================
#include <ItfCoreEcu.h>
#include <ItfBloCBuf.h>
#include <Cfg_CBuf.h>

// GLOBAL VARIABLES ================================================================================
//Software Module Name: AppPrivate
TEcuSys gEcu_tSys= 
{
   // ECU Indicator
    0,                                                      //u8EcuNo                - [NUM] Network controller number
   // ECU Setting
    12,                                                     //u8EcuVoltage           - [V] ECU operating voltage  
    3000,                                                   //u16DiagnosticTime      - [ms] ECU diagnostic time 
    50,                                                     //u16EcuPowerOffTime     - [ms] ECU power off detection time
    // Only TTC5XX - WakeUp
    30,                                                     //u16WaitAfterWakeUp     - [ ] The parameter is not used at this ECU
    TRUE,                                                   //boShutDownAfterWakeUp  - [ ] The parameter is not used at this ECU
    // Password Application setting 
    TRUE,                                                   //boAppPwCheck           - [DEF] Application password check   
    {// SIL Setting 
        1,                                                  //u8SilLevel             - [DEF] Safety Level - 0 = Without SIL errors, 1 = with SIL-Errors
        10,                                                 //u16EcuTaskTime         - [ms] Task time
        9000,                                               //u16EcuBatLow           - [mV] ECU battery supply voltage     - Lowest valid value
        16000,                                              //u16EcuBatHigh          - [mV] ECU battery supply voltage     - Highest valid value
        -40,                                                //i16EcuTempLow          - [°C] ECU temperature        - Lowest valid value
        80,                                                 //i16EcuTempHigh         - [°C] ECU temperature        - Highest valid value
        4900,                                               //u16SensorSsLow         - [mV] Sensor Supply 5V       - Lowest valid value
        5100,                                               //u16SensorSsHigh        - [mV] Sensor Supply 5V       - Highest valid value
        0,                                                  //u16SensorVsLow         - [mV] Variable Sensor Supply - Lowest valid value
        0                                                   //u16SensorVsHigh        - [mV] Variable Sensor Supply - Highest valid value
    },
    //TTC50/TTC60 (not TTC90 have an HW Watchdog)
    14,                                                     //u16WdTimeout           - [ms] Watchdog timeout
    {// Fault Stack 
        0,                                                  //u8FaultParmIdx         - [NUM] If a Parameter change -> format the Error-Stack
        FAULT_MODE_ECU,                                     //eFaultMode             - [DEF] Fault mode 
        TRUE,                                               //boFaultDoubleMode      - [DEF] Fault/Event store double mode 
        TRUE,                                               //boFaultEventStore      - [DEF] Change store event 
        1200,                                               //u16FaultStoreTime      - [s] Dealer time between two stores
        FALSE,                                              //boFaultRestartDeactive - [DEF] After ECU restart all faults deactive
        100,                                                //u16DelFaultDealer      - [h]   Dealer:   Delete fault stack (0 - No deletetion)      (Max. approx. 7 years)
        100                                                 //u16DelFaultEngineer    - [h]   Engineer: Delete Fault/Event-stack 0 - No deletetion)      (Max. approx. 7 years)
    }
};
