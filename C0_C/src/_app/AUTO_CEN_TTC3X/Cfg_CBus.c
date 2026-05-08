//**************************************************************************************************
//! @crc        3942430157
//! @file       Cfg_CBus.c
//! @brief      Generate by: HYDAC Controller Project - Code Builder Tool Chain
//! @ecu        TTC32S
//! @dll        1.4.0 (Build: 021)
//! @dll itf    1.7.0
//! @build      2025-03-12 15:24:11
//! @Pattern    0.5.0
//! @Subpattern 0.0.4
//! @Match      07-08-00-00
//! @PDT        2.12.91.55
//! @PdtProjVer 0.0.0
//! @created    2026-05-08 10:34:48   HYDAC/HCP-CC
//**************************************************************************************************

// INCLUDES ========================================================================================
#include <ItfBloCBus.h> 

// GLOBAL VARIABLES ================================================================================
//Sofware Module Name: SWMain
PUBLIC_VAR const TCBusCfg gCBus_ctCfg_CAN_BUS0 =
{
    // Common
    "CAN_BUS0",                                             //achName                - [STR] Display-Information-String
    BLO_RELEASE,                                            //eBloProc               - [DEF] Block behavior
    // Fixed settings
    CAN_BUS0,                                               //u8CanBus               - [DEF] CAN bus number
    CAN_RATE_250K,                                          //u16Bitrate             - [DEF] CAN bit rate [kBaud]
    #ifdef COMPILER_SWITCH_TAR_PC
    "ServiceBus",                                           //achPeakNetName         - Peak register net name
    PEAK_DEVICE_USB,                                        //ePeakDevice            - Peak CAN device
    PEAK_INTERN,                                            //ePeakChannel           - Peak device can channel
    #endif    
    {  
        {// Hardware Receive Buffer 0: BUFRCV0
            16,                                             //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            16,                                             //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 1: BUFRCV1
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 2: BUFRCV2
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 3: BUFRCV3  
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 4: BUFRCV4  
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 5: BUFRCV5  
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 6: BUFRCV6  
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        }, 
        {// Hardware Receive Buffer 7: BUFRCV7          
            0,                                              //u8HwRcvSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
            TRUE,                                           //boExtId                - [DEF] Can-Rcv extended identifier (11/29 Bit) 
            0,                                              //u32Id                  - [DEF] Can-Rcv id (only with acceptance maske)
            0,                                              //u32AccMask             - [DEF] Can-Rcv acceptance mask
        } 
    },
    {
        {// Hardware Sende Buffer 0: BUFSND0    
            16,                                             //u8HwSndSize            - [NUM] Can Hardware Msg-Buffer
            16,                                             //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
        },
        {// Hardware Sende Buffer 1: BUFSND1
            0,                                              //u8HwSndSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
        },
        {// Hardware Sende Buffer 2: BUFSND2    
            0,                                              //u8HwSndSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
        },
        {// Hardware Sende Buffer 3: BUFSND3
            0,                                              //u8HwSndSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
        },
        {// Hardware Sende Buffer 4: BUFSND4    
            0,                                              //u8HwSndSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
        },
        {// Hardware Sende Buffer 5: BUFSND5
            0,                                              //u8HwSndSize            - [NUM] Can Hardware Msg-Buffer
            8,                                              //u8CallCountOfCycle     - [NUM] Cyclic can buffer call [count of cycles]
        }
    },
    //All Errors
    ERR_CNT_DFLT,                                           //u8ErrCnt               - [DEF] Error Count  
    // Error [0-15]  
    { // TErrCfgFea
        { //ErrTag[0] - CAN Bus off [DM_CBUS_OFF0]
            1023,                                           //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                        //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                     //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                    //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                 //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                   //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                  //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                        //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                        //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                            //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                          //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                        //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                           //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                          //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                        //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                       //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                           //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                        //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[1] - CAN warning [DM_CBUS_WARN0]
            1024,                                           //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                        //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                     //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                    //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                 //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                   //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                  //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                        //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                        //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                            //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                          //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                        //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                           //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                          //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                        //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                       //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                           //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                        //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV0]
            1031,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV1]
            1032,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV2]
            1033,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV3]
            1034,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV4]
            1035,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV5]
            1036,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV6]
            1037,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow receive [DM_CAN_BUSx_BUFRCV7]
            1038,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow send [DM_CAN_BUSx_BUFSND0]
            1025,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow send [DM_CAN_BUSx_BUFSND1]
            1026,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow send [DM_CAN_BUSx_BUFSND2]
            1027,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow send [DM_CAN_BUSx_BUFSND3]
            1028,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow send [DM_CAN_BUSx_BUFSND4]
            1029,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        },
        { //ErrTag[0] - HW-Buffer overflow send [DM_CAN_BUSx_BUFSND5]
            1030,                                                   //u32ErrNum              - [num] Error Number
            FMI_31_CONDITION_EXISTS,                                //u8ErrMode              - [enu] Failure Mode Indicator
            FMIEX_NONE,                                             //u8ErrModeExt           - [def] Extended Failure Mode Indicator
            ACC_ALL_CL1,                                            //u16ErrAccLevel         - [def] Failure Access Level
            ERR_TYPE_ERROR,                                         //u8ErrType              - [enu] Error Type
            ERR_CAT0_NOT,                                           //u8ErrCat               - [enu] Error Category ( Lamp Type )
            ERR_STORE_ALL,                                          //u8ErrStore             - [enu] Error Store Behavior
            EG_NONE,                                                //u8ExcludeGroup         - [def] Error Exclude Group
            SC_NONE,                                                //u8SetCond              - [def] Set Condition - allows to activate an error detection
            500,                                                    //u32TimeDetect          - [ms]  Error Detection ( Debounce ) Time
            FALSE,                                                  //boDetectDboAfterSc     - [boo] Start debounce timer after a valid set condition
            RC_NONE,                                                //u8ReleaCond            - [def] Release Condition - allows an error to be released ( removed )
            1000,                                                   //u32TimeReset           - [ms]  Error Release ( Debounce ) Time
            FALSE,                                                  //boResetDboAfterRc      - [boo] Start debounce timer after a valid release condition 
            RM_NONE,                                                //u8RestrictMode         - [def] Restricted Mode
            INF_NONE,                                               //u8InfoVarIdx           - [num] Array Index of Error Information Page
            TRUE,                                                   //boCustList             - [boo] Memorized in a Customer List
            DIS_NONE                                                //u8DisplayOutput        - [def] Display Output ( Error Output Interface )
        }
    }
};
