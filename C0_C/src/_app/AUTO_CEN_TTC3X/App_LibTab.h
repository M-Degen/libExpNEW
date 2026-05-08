//**************************************************************************************************
//! @crc        3452532015
//! @file       App_LibTab.h
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

#ifndef __APP_LIBTAB_H__
#define __APP_LIBTAB_H__

// INCLUDES ========================================================================================
#include <ItfCoreAllObj.h>

// GLOBAL VARIABLES ================================================================================

TVoid vAppAutoLibTable( TVoid );


// BLOCKs
extern        TBloCBus gCBus_tCAN_BUS0;
extern const TCBusCfg gCBus_ctCfg_CAN_BUS0;
extern        TBloSil gSil_tEcu0_Safety;
extern const TSilCfg gSil_ctCfg_Ecu0_Safety;
extern        TBloSil gSil_tEcu1_Safety;
extern const TSilCfg gSil_ctCfg_Ecu1_Safety;
extern        TBloSil gSil_tEcuSil;
extern const TSilCfg gSil_ctCfg_EcuSil;
extern        TBloSil gSil_tSensorSupply;
extern const TSilCfg gSil_ctCfg_SensorSupply;
extern        TBloSil gSil_tErrList;
extern const TSilCfg gSil_ctCfg_ErrList;

// STRUCTs


#endif // __APP_LIBTAB_H__

