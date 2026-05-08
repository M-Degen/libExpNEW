//**************************************************************************************************
/*!
@file       main_cen.c
@brief      MATCH MAIN
*/
//**************************************************************************************************
#include <ItfCore.h>
#include <ItfAppCode.h>


static TVoid m_vCoreMainPrepareLoopInternal( TVoid );
static TVoid m_vCoreMainTriggerOneCycle( TVoid );

TTimStatistic g_tStatistic = { 0, 0, U32_MAX, U32_MIN, MAIN_SAFETY_PRE_START, 0, FALSE, FALSE };
EMainPhase    g_ePhase     = MAIN_CORE_DEBUG;

#if defined (COMPILER_SWITCH_PLATFORM_TTC2XXX) && defined (COMPILER_SWITCH_TAR_HW)

void MainCore0Hook(void);
void MainCore0Hook(void)
{
    #ifdef COMPILER_SWITCH_ECU_TTC2038
    extern TVoid vAppWkdTtc2038RefVoltageCheck( TVoid );
    vAppWkdTtc2038RefVoltageCheck( );
    #endif
}

void MainCore1Hook(void);
void MainCore1Hook(void)
{
    vCoreRuntime( m_vCoreMainPrepareLoopInternal, m_vCoreMainTriggerOneCycle );
}

#else
TInt32 main( TVoid )
{
    m_vCoreMainPrepareLoopInternal();
    while(1)
    {
        m_vCoreMainTriggerOneCycle();

        #ifdef COMPILER_SWITCH_MAIN_CORE_EMC_BREAK
        if( g_ePhase == MAIN_CORE_EMC_BREAK )
        {// Emergency break
            return 1;
        }
        #endif
    }

}
#endif
//--------------------------------------------------------------------------------------------------
//! @brief      Main Prepare Loop Internal
//! @created    05.01.2020          HYDAC/MOR
//--------------------------------------------------------------------------------------------------
static TVoid m_vCoreMainPrepareLoopInternal( TVoid )
{
    vCoreLibTabAdding( g_atObjTab, g_u16ObjTabMax );

    vCoreTestStart( vAppTestStart, vAppTestEnd );

    vCoreInitEcuStatisticTim( u16CoreGetCycleTime(), 100, &g_tStatistic );

    vCoreFixInit( vAppFixInit );
}



//--------------------------------------------------------------------------------------------------
//! @brief      Trigger One Cycle
//! @created    05.01.2020          HYDAC/MOR
//--------------------------------------------------------------------------------------------------
static TVoid m_vCoreMainTriggerOneCycle( TVoid )
{
        vCoreMain(  &g_ePhase,         // [show] Phase information
                                       //          -> show the current core phase
                    vLibRegistry,      // [ones] Registry of blocks/signal/protocol types
                                       //          -> auto code connection
                    vAppAutoLibTable,  // [ones] Project announcement of the objects and blocks

                    vAppSafetyInit,    // [cyc]  Application "Safety Init"
                                       //          -> factory setting available and safety pin setting functions can be used
                    eAppPreStart,      // [cyc]  Application "Pre-Start"
                                       //          -> safety and fixed pin´s available
                                       //            - outputs on TTC2xxx are only available here with deactivated startup tests, else in vAppRun
                                       //          -> BLO_ADC/DAC (only with fixed pins) available
                                       //             - need 3 task cycles to be here
                    eAppStartUp,       // [cyc]  Application "Start Up" phase
                                       //          -> loaded the Db-Opt-List's, the fault stack and system sector
                                       //             - nvmem loads need 11 task cycles minimum, 20-30 average
                                       //          -> option pin's, VER, BLO-ERR/EXC/CBUS/CBUF/CSND/CRCV available
                                       //          -> Can msg. send is possible / Can msg. receive is not possible (->eAppInit)
                                       //            - need ca. 120 task cycles in total to be here
                                       //               (Depending on block count and NvMem loading behavior)
                    vSetAppVersion,    // [ones] Set application software version information
                                       //          -> only for setting the application version numbers
                                       //             - need ca. 121 task cycle to be here
                    vGetVersionInfo,   // [ones] Output of version information
                                       //          -> to send an custom made application version report to the services tool
                                       //             - need ca. 121 task cycle to be here
                    eAppInit,          // [cyc]  Application "Initialization" phase
                                       //          -> load all DB-List's, all other block including the block pins's are available
                                       //           -> Can msg. receive is possible
                                       //             - need ca. 180 task cycle to be here
                    vAppRun,           // [cyc]  Application "Run" phase
                                       //          -> Machine run part
                                       //             - saving the DB lists is only possible from this phase onwards
                                       //             - need ca. 181 task cycle to be here
                    eAppShutDown );    // [cyc]  Application "Shut Down" phase
                                       //          -> after K15 switch to off (denouncing  time -  power off detection time)
                                       //             save the DB-MEM-List's, the fault stack and the system sector
                                       //             - need ca. 100-x task cycle from the K15=OFF-Switch to exit

         vCoreTestEnd( );

    // *** Unreachable code at token  ***
    // return 0;
}
