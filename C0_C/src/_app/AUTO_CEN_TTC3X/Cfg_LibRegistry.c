//**************************************************************************************************
//! @crc        419672257
//! @file       Cfg_LibRegistry.c
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
#include <ItfCoreLib.h>
#include <ItfCoreAllObj.h>

// GLOBAL VARIABLES ================================================================================
TUint16 g_u16EnuStdTypMax = (TUint16)STD_LIB_MAX;
TUint16 g_u16EnuBloTypMax = (TUint16)BLO_LIB_MAX;
TUint16 g_u16EnuSigTypMax = (TUint16)SIG_LIB_MAX;

extern TPtcMst gPtc_tMstPtcMstCfg;

//--------------------------------------------------------------------------------------------------
//! @brief      Lib Registry Ptd
//--------------------------------------------------------------------------------------------------
TVoid vLibRegistry( TVoid )
{
    // block's

    // customer block's

    // customer signal's

    // customer protocol's
    eCorePtcRegistry("PTC_MST", cptPtcMstVersionsInfo, boPtcMstVersionCheck, &gPtc_tMstPtcMstCfg, vPtcMstAppCall, boPtcMstRcvHwBuf, boPtcMstSndHwBuf );

}
