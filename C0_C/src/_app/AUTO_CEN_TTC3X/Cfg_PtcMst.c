//**************************************************************************************************
//! @crc        2037004568
//! @file       Cfg_PtcMst.c
//! @brief      Generate by: HYDAC Controller Project - Code Builder Tool Chain
//! @ecu        TTC32S
//! @dll        1.4.0 (Build: 021)
//! @dll itf    1.7.0
//! @build      2025-03-12 15:24:11
//! @Pattern    0.9.12.0
//! @Subpattern 0.0.4
//! @Match      07-08-00-00
//! @PDT        2.12.91.55
//! @PdtProjVer 0.0.0
//! @created    2026-05-08 10:34:48   HYDAC/HCP-CC
//**************************************************************************************************

// INCLUDES ========================================================================================
#include <ItfPtcMst.h>

// GLOBAL VARIABLES ================================================================================
//Software Module Name: SWMain
TPtcMst gPtc_tMstPtcMstCfg =
{
    // Common
    "PtcMst",                                               //achName                - [STR] Display-Information-String
    // Setting
    TRUE,                                                   //boActiv                - MST Protocol active
    PTC_MST_HYDSTD,                                         //eType                  - Protocol Type Switch
    1000,                                                   //u16MstPrintBufSize     - Print Buffer Size in Byte
    MST_LINK_CAN,                                           //eLinkType              - Link type
    CBUS0_HWBUF_SND0,                                       //u8SndHwBufNo           - CAN send buffer position connection link
    CBUS0_HWBUF_RCV0,                                       //u8RcvHwBufNo           - CAN receive buffer position connection link
    FALSE,                                                  //boBcstActive           - Broadcast Active - for FaultUpdate, FaultRegisterUpdate
    TRUE,                                                   //boCanExt               - Extended CAN ID
    0x18,                                                   //u8Prio                 - Message Priority
    0x00,                                                   //u8BcstSa               - Broadcast SA
    0x20,                                                   //u8EcuSa                - J1939 ECU SA
    0xe8,                                                   //u8MstSa                - J1939 MST SA
    0x2f,                                                   //u8CluSa                - J1939 Cluster SA 
    0x34,                                                   //u8HmgSa                - J1939 Hmg SA 
    0x2e,                                                   //u8RemSa                - J1939 Remote Maintenance SA
    DATA_INTEL,                                             //eDbValueFormat         - DB - Value Format (Read/Write)
    DATA_MOTOROLA,                                          //eDbComIdFormat         - DB - COM-ID Format
    DATA_MOTOROLA,                                          //eOthersFormat          - Service Values Format DFLT: MOTOROLA]
    //Mst Result [calc in Init]
    0,                                                      // u32IdSndBcst          - CAN-ID from ECU Broadcast send  
    0,                                                      // u32IdRcvBcst          - CAN-ID from ECU Broadcast receive 
    0,                                                      // u32IdSndMst           - CAN-ID from ECU send to Service Tool
    0,                                                      // u32IdRcvMst           - CAN-ID from ECU receive from Service Tool
    0,                                                      // u32IdSndClu           - CAN-ID from ECU send to Cluster
    0,                                                      // u32IdRcvClu           - CAN-ID from ECU receive from Cluster
    0,                                                      // u32IdSndHmg           - CAN-ID from ECU send to HMG
    0,                                                      // u32IdRcvHmg           - CAN-ID from ECU receive from HMG
    0,                                                      // u32IdSndRem           - CAN-ID from ECU send to remote maintenance
    0,                                                      // u32IdRcvRem           - CAN-ID from ECU receive from remote maintenance  
    // Error [0]  
    { // TErrCfgFea
        { //ErrTag[0] - CAN Snd Overflow [DM_MST_SND_OVERFLOW]
            54,                                             //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                        //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                     //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                    //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                 //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                   //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                  //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                        //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                        //u8SetCond              - [def] Set Condition - allows to activate an error detection
            0,                                              //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                          //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                        //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            0,                                              //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                          //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                        //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                       //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                           //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                        //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        }
    }   
};

