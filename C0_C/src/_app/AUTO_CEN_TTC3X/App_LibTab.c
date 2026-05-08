//**************************************************************************************************
//! @crc        2494226675
//! @file       App_LibTab.c
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

// INCLUDES ========================================================================================
#include <ItfCoreLibTab.h>
#include <App_LibTab.h>

// GLOBAL VARIABLES ================================================================================
// STRUC-BLOCK-Itf
TCoreInp  gCore_tInp;
TCoreOut  gCore_tOut;
TBloCBus gCBus_tCAN_BUS0;
TBloSil gSil_tEcu0_Safety;
TBloSil gSil_tEcu1_Safety;
TBloSil gSil_tEcuSil;
TBloSil gSil_tSensorSupply;
TBloSil gSil_tErrList;

#define OBJ_TAB_MAX 11

TObjTab g_atObjTab[OBJ_TAB_MAX];
TUint16 g_u16ObjTabMax = OBJ_TAB_MAX;

TVoid vAppAutoLibTable( TVoid )
{
    gCBus_tCAN_BUS0.tXAdr.cptCfg = &gCBus_ctCfg_CAN_BUS0;
    g_atObjTab[0].u16Type = (TUint16)STD_BLO_CBUS;
    g_atObjTab[0].pvBloAdr = &gCBus_tCAN_BUS0;

    gSil_tEcu0_Safety.tXAdr.cptCfg = &gSil_ctCfg_Ecu0_Safety;
    g_atObjTab[1].u16Type = (TUint16)STD_BLO_SIL;
    g_atObjTab[1].pvBloAdr = &gSil_tEcu0_Safety;

    gSil_tEcu1_Safety.tXAdr.cptCfg = &gSil_ctCfg_Ecu1_Safety;
    g_atObjTab[2].u16Type = (TUint16)STD_BLO_SIL;
    g_atObjTab[2].pvBloAdr = &gSil_tEcu1_Safety;

    gSil_tEcuSil.tXAdr.cptCfg = &gSil_ctCfg_EcuSil;
    g_atObjTab[3].u16Type = (TUint16)STD_BLO_SIL;
    g_atObjTab[3].pvBloAdr = &gSil_tEcuSil;

    gSil_tSensorSupply.tXAdr.cptCfg = &gSil_ctCfg_SensorSupply;
    g_atObjTab[4].u16Type = (TUint16)STD_BLO_SIL;
    g_atObjTab[4].pvBloAdr = &gSil_tSensorSupply;

    gSil_tErrList.tXAdr.cptCfg = &gSil_ctCfg_ErrList;
    g_atObjTab[5].u16Type = (TUint16)STD_BLO_SIL;
    g_atObjTab[5].pvBloAdr = &gSil_tErrList;

    g_atObjTab[6].u16Type  = (TUint16)STD_STU_VER;
    g_atObjTab[6].pvBloAdr = (TVoid*)&gVer_tInf;

    g_atObjTab[7].u16Type  = (TUint16)STD_STU_PIN;
    g_atObjTab[7].pvBloAdr = (TVoid*)&gPinInfo_ctAppPin;

    g_atObjTab[8].u16Type  = (TUint16)STD_STU_ECU;
    g_atObjTab[8].pvBloAdr = (TVoid*)&gEcu_tSys;

    g_atObjTab[9].u16Type  = (TUint16)STD_STU_HCP_OUT;
    g_atObjTab[9].pvBloAdr = (TVoid*)&gCore_tOut;

    g_atObjTab[10].u16Type = (TUint16)STD_STU_HCP_INP;
    g_atObjTab[10].pvBloAdr = (TVoid*)&gCore_tInp;
}
