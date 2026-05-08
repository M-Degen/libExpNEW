//**************************************************************************************************
/*!
@file       2AppCode.c
@brief      Application Program
*/
//**************************************************************************************************
#include <string.h>
#include <stdlib.h>
#include <ItfGlobal.h>
#include <ItfCoreCan.h>
#include <ItfCoreLib.h>
#include <ItfBasOut.h>
#include <ItfAppCode.h>

#ifdef COMPILER_SWITCH_ACTIVE_2APP


#include <2Cfg_Ver.h>

#ifdef COMPILER_SWITCH_ECU_2APP_DB
 #include <2App_Db.h>
#endif

#ifdef COMPILER_SWITCH_ECU_2APP_CSR
 #include <2App_CanSigRec.h>
#endif


#ifdef COMPILER_SWITCH_MPU
 #include <ItfCoreMpu.h>
#endif



extern TVoid vAppAutoLibTableExt( TVoid );
extern TVoid vLibRegistryExt( TVoid );

//--------------------------------------------------------------------------------------------------
//! @brief      Application Safety Initialization
//!             eAppPreStart will be called soon
//! @created    27.03.2019       HYDAC/NJP
//--------------------------------------------------------------------------------------------------
TVoid vAppSafetyInitExt( TVoid )
{

}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Pre Start
//! @retval     R_OKAY  - eAppStartUp(..) will be called soon
//! @retval     !R_OKAY - this function call again
//--------------------------------------------------------------------------------------------------
ERetVal eAppPreStartExt( TVoid )
{
    #ifdef COMPILER_SWITCH_MPU
    // eCoreActivate2AppMpu( TRUE, FALSE ); //activate automatic MPU protection for 2app data
    #endif

    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Start Up
//! @retval     R_OKAY  - vSetAppVersion(..) will be called soon
//! @retval     !R_OKAY - this function call again
//--------------------------------------------------------------------------------------------------
ERetVal eAppStartUpExt( TVoid )
{
    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Initialization
//! @retval     R_OKAY  - vAppRun(..) will be called soon
//! @retval     !R_OKAY - this function call again
//--------------------------------------------------------------------------------------------------
ERetVal eAppInitExt( TVoid )
{
    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Run
//!             If K15 is for the 'Ecu Power Off detection time' OFF, eAppShutDown( ) will be called soon
//! @param      ptCoreInp - Core Input Vector
//! @param      ptCoreOut - Core Output Vector
//--------------------------------------------------------------------------------------------------
TVoid vAppRunExt( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
{
    AVOID_WARRNING(ptCoreInp);
    AVOID_WARRNING(ptCoreOut);
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Shut Down
//! @param      ptCoreInp - Core Input Vector
//! @param      ptCoreOut - Core Output Vector
//! @retval     R_OKAY  - Ecu shut down
//! @retval     !R_OKAY - this function call again
//--------------------------------------------------------------------------------------------------
ERetVal eAppShutDownExt( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
{
    AVOID_WARRNING(ptCoreInp);
    AVOID_WARRNING(ptCoreOut);
    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Fix Initialization
//--------------------------------------------------------------------------------------------------
TVoid vAppFixInitExt( TVoid )
{
     eCoreExtErrIomFileCrc( APP2_ERR_FILE_CRC, APP2_IOM_FILE_CRC );

     vCoreMainExt( APP2_EXT_DB_ACTIVE,                  // boSecDbRoot,
                   APP2_EXT_MST_SA,                     // u8SecSaId,
                   (TChar*) APP2_EXT_VEHICLE_CODE,               // *pchVehicleCode,
                   (TUint32)atol(APP2_EXT_SERIAL_NUM),  //  u32SerielNo,
                   vLibRegistryExt,        // (*pfvLibRegistry)    ( TVoid ),
                   vAppAutoLibTableExt,    // (*pfvAppAutoLibTable)( TVoid ),
                   vAppSafetyInitExt,      // (*pfvSafetyPinInit)  ( TVoid ),
                   eAppPreStartExt,        // (*pfeAppPreStart)    ( TVoid ),
                   eAppStartUpExt,         // (*pfeAppStartUp)     ( TVoid ),
                   eAppInitExt,            // (*pfeAppInit)        ( TVoid ),
                   vAppRunExt,             // (*pfvAppRun)         ( TCoreInp *ptHctInp, TCoreOut *ptHctOut ),
                   eAppShutDownExt );      // (*pfeAppShutDown)    ( TCoreInp *ptHctInp, TCoreOut *ptHctOut )
}


#endif

