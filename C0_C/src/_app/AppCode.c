//**************************************************************************************************
/*!
@file       AppCode.c
@brief      This file is the starting point for the application program.
            Enter the application program code here.

  This file contains the functions for each application phase:
  1. phases for initializing the application.
  2. the main phase: vAppRun(), it is executed cyclically.
  3. the eAppShutDown() phase which is triggered by K15 (ignition off).
  For details see the "C0_C\_doc\Software_Frame.pdf" file.

@created    2023/09/30 HYDAC Software GmbH
*/
//**************************************************************************************************
//
// Default function header includes
// Include any other required headers here, e.g. <App_CanSigRec.h>.
#include <string.h>
#include <ItfGlobal.h>            // global MATCH defines
#include <ItfCoreCan.h>           // CAN interface
#include <ItfCoreLib.h>           // general MATCH block and protocol interface
#include <ItfBasOut.h>            // basic output to debug console
#include <ItfBasMath.h>           // basic mathemathic interface

#include <ItfAppCode.h>           // interface to the MATCH phases
#include <AppCode.h>              // custom includes

//--------------------------------------------------------------------------------------------------
// Define global variables here

//--------------------------------------------------------------------------------------------------


#ifdef COMPILER_SWITCH_ACTIVE_2APP
TVoid vAppFixInitExt( TVoid );
#endif

#ifdef COMPILER_SWITCH_EXT_MEM
     #if defined(COMPILER_SWITCH_TAR_HW) && defined(COMPILER_SWITCH_FAM_TTC5XX)

     // Simple Example of using the external RAM, delete if not needed
     // avoid using variables in external RAM with functions related to FPGA(e.g. CAN ports >=3)

     //#pragma DATA_ALIGN(vUseExternMem, 4U) //- Standard Alignment
     //#pragma DATA_ALIGN(u8Sum,         4U) //- Standard Alignment
     #pragma SET_DATA_SECTION(".EXT_RAM")
     #define EXT_MEM_SIZE 4
     static TUint8 m_au8ExtRamTest[EXT_MEM_SIZE] ={0,1,2,3};
     static TUint8 m_u8Sum = 0;
     #pragma SET_DATA_SECTION( )

     //--------------------------------------------------------------------------------------------------
     //! @brief   vUseExternMem - is only a example of using - source code have no deep sense
     //--------------------------------------------------------------------------------------------------
     TVoid vUseExternMem( TVoid )
     {
         m_u8Sum = m_au8ExtRamTest[0] + m_au8ExtRamTest[1] + m_au8ExtRamTest[2] + m_au8ExtRamTest[3];
         m_au8ExtRamTest[0] = m_u8Sum;
         AVOID_WARRNING(m_u8Sum);
     }
     #endif
#endif





//example to link variable to DSRAM on TTC3X:
// #pragma section huge=my_application_dsram
// TUint8 u8TestDsramData[100];
// #pragma endsection

//--------------------------------------------------------------------------------------------------
//! @brief      Application Test Start      the function is exclusively for PC simulation, mainly unit tests
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vAppTestStart( TVoid )
{
    #ifdef COMPILER_SWITCH_TAR_PC
    //vCoreSimAppCodeCallInMainFct( );
    //vCoreSimSuppressEcuLogic( );
    //ePrintShellOpenFile( "TEST_LOG.txt", TRUE );
    vPrintLinkToShell( TRUE, TRUE );

    //vPcCanClientInfoSuppress();
    //vPcCanClientRemove();
    //vPcCanClientRename("pink_panther", 0 );

    #endif
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Fix Initialization
//!             Define the MATCH core initialization settings.
//!             E.g. the default behavior of the DB list.
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vAppFixInit( TVoid )
{
    //vCoreEventFaultStackActiv( FALSE );
    //vCoreDevelopmentFaultStackActiv( FALSE );

    //vPtcMstSelectDebugMode( PTC_MST_MODE_FIRST_TIME ); // the Debug console shows the vPrint output over CAN shortly
    //vPtcMstLockUntilLogin( NULL, 0, FALSE );

    //DB load behavior settings
    //vCoreDbSetExtendableMode(FALSE);  // allow adding vars to end of existing databases while keeping old data[dflt=FALSE]
    //vCoreDbSetLoadFast(TRUE);        // don't check backup lists if primary list has no errors[dflt=TRUE]
    //vCoreDbSetLoadRangeCheck(FALSE); // don't check range of all DB vars during startup[dflt=TRUE]

    #ifdef COMPILER_SWITCH_OEM_HY
    vPrintCtrlMode( TRUE );
    #endif

    #ifdef COMPILER_SWITCH_ACTIVE_2APP
    vAppFixInitExt( );
    #endif
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Safety Initialization
//!             Initialize the safety pins.
//!             See the "Safety Critical Pin Configuration" chapter in the Safety Manual.
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vAppSafetyInit( TVoid )
{

}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Pre Start
//!             Phase for safety/fixed pin handling after ECU initialization.
//! @retval     R_OKAY  - the phase ends
//! @retval     !R_OKAY - this function is called again (refer to the ERetVal enumeration)
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
ERetVal eAppPreStart( TVoid )
{
    // example for manual ecu licensing before automatic configuration
//    #define LIC_EEPROM_ADR      3500    // nvmem addresse to store lic data, avoid overlap!
//    #define LIC_NUM_LICENSES    1       // number of licenses
//    #define LIC_SIZE_ECU        3       // size of ecu lic data(type, id, crc)
//    vCoreLicInit( LIC_NUM_LICENSES, LIC_EEPROM_ADR ); // Initialization of license system
//    static TUint16 s_au16EcuLicId[LIC_SIZE_ECU] = { LIC_HYDAC_ECU, 1, 0 }; // license type/id, 1 for ECU, needs to be at fixed address
//    s_au16EcuLicId[LIC_SIZE_ECU-1] = u16CalcCrcBlock( (LIC_SIZE_ECU-1)*sizeof(TUint16),
//                                                      (TUint8*)s_au16EcuLicId ); // crc over license ids
//    vCoreLicReg( 0, s_au16EcuLicId, LIC_SIZE_ECU, NULL, 0, NULL ); // register license at slot 0(ECU) with standard settings

    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Start Up
//!             Phase for block and signal creation.
//! @retval     R_OKAY  - the phase ends
//! @retval     !R_OKAY - this function is called again(refer to the ERetVal enumeration)
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
ERetVal eAppStartUp( TVoid )
{
    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Set the application software version
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vSetAppVersion( TVoid )
{
    // Set application software version information
    TVerChapCom tAppVer = { 0,0,0,1, "2023/05/15", "00:00" };
    eCoreVersSetAppInfo( &tAppVer );

    // Set customer part data
    TVerAppSwNo tAppSw  = { "0000", "0000", "0000", "0000" };
    eCoreVersSetAppInfoExtended( "0123456789", &tAppSw, 2023 );
}

//--------------------------------------------------------------------------------------------------
//! @brief      Print the version information
//! @param      ptVer - Version input struct
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vGetVersionInfo( TVerInf *ptVer )
{
    // Version Information, this is an example of some available parameters of the TVerInf structure
    vPrint("-- APP-VERSION --");
    vPrint("EcuType: %s / %s-Version", cpchCoreEcuType(), cpchCoreEnvType() );
    vPrint("AppVer:  %d %d %d %d",     ptVer->tAppVersion.u8Major,
                                       ptVer->tAppVersion.u8Minor,
                                       ptVer->tAppVersion.u8Index,
                                       ptVer->tAppVersion.u16DevStp );
    vPrint("HcpBios: %d %d %d %d",     ptVer->tHcpBios.u8Major,
                                       ptVer->tHcpBios.u8Minor,
                                       ptVer->tHcpBios.u8Index,
                                       ptVer->tHcpBios.u16DevStp );
    //Need a pre load of the NVMEM
    vPrint("EcuInfo: LastTime:%lusec Err:%d",
                                       (TPriU32)(ptVer->tEcuMem.u32EcuLastRunTime/(TUint32)1000),
                                       ptVer->tEcuMem.u8RestartReaInfo );
    vPrint("--");
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Initialization
//!             Phase for signal, block and pin configuration and initialization.
//! @retval     R_OKAY  - vAppRun() will be entered next
//! @retval     !R_OKAY - this function is called again (refer to the ERetVal enumeration)
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
ERetVal eAppInit( TVoid )
{
    // Turn on the engine time. Enable time tracking for error lists.
    vCoreSetEngineOn(TRUE);
    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Run
//!             Phase for the cyclic called application code
//!             Typically, the phase is terminated by K15/ignition off,
//!             core functions are also available for this purpose.
//! @param      ptCoreInp - Core Input Vector
//! @param      ptCoreOut - Core Output Vector
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vAppRun( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
{
    // The following two lines prevent warnings generated by lint code checking.
    AVOID_WARRNING(ptCoreInp);
    AVOID_WARRNING(ptCoreOut);

    // Start here with the application code
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Shut Down
//!             Phase for application shut down
//!             This phase starts after the vAppRun has been terminated by K15/ignition off.
//!             Store DB lists here or execute other cleanup tasks
//! @param      ptCoreInp - Core Input Vector
//! @param      ptCoreOut - Core Output Vector
//! @retval     R_OKAY  - the application ends
//! @retval     !R_OKAY - this function is called again (refer to the ERetVal enumeration)
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
ERetVal eAppShutDown( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
{
    // The following two lines prevent warnings from the Lint code check.
    AVOID_WARRNING(ptCoreInp);
    AVOID_WARRNING(ptCoreOut);

    return R_OKAY;
}

//--------------------------------------------------------------------------------------------------
//! @brief      Application Test End - used only for Python unit tests
//! @created    2023/09/30 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vAppTestEnd( TVoid )
{

}

#ifdef COMPILER_SWITCH_ECU_TTC2038
//--------------------------------------------------------------------------------------------------
//! @brief      Workaround for TTC2000-13013: Violation of 2.5V reference voltage chec
//! @created    2024/09/04 HYDAC Software GmbH
//--------------------------------------------------------------------------------------------------
TVoid vAppWkdTtc2038RefVoltageCheck( TVoid )
{
    // workaround for TTC2000-13013: Violation of 2.5V reference voltage check causing safe state on TTC 2038
    // loop adds ~100ms delay to startup
    // can be removed if conditions for the error situation do not apply
    volatile TUint32 vu32I;
    //lint -esym(850,vu32I )
    for( vu32I=0;vu32I<2100000U; vu32I++ )
    {
        vu32I *=2;
        vu32I /=2;
    }
}
#endif
