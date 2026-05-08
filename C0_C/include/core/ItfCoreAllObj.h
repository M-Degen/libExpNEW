//**************************************************************************************************
/*!
@file       ItfCoreAllObj.h
@brief      Include all blocks
@date       01.02.2011
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREALLOBJ__
    #define __ITFCOREALLOBJ__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfBasEleErr.h>
    #include <ItfCoreEcu.h>
    #include <ItfCoreExc.h>
    #include <ItfCoreDb.h>
    #include <ItfCoreCanSigRec.h>
    #include <ItfCoreVer.h>

    // inside the following blocks
    #include <ItfBloFla.h>
    #include <ItfBloSil.h>
    #include <ItfBloErr.h>
    #include <ItfBloAdc.h>
    #include <ItfBloDac.h>
    #include <ItfBloCBus.h>
    #include <ItfBloCBuf.h>
    #include <ItfBloCSnd.h>
    #include <ItfBloCRcv.h>
    #include <ItfBloLBus.h>

    // Library inside costumer blocks and signals
    #include <Cfg_LibCustomer.h>
    #ifdef COMPILER_SWITCH_ACTIVE_2APP
        #include <2Cfg_LibCustomer.h>
    #endif

#endif
