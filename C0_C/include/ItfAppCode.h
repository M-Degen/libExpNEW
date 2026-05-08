//**************************************************************************************************
/*!
@file           ItfAppCode.h
@brief          Application Program
@date           16.06.2011
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFAPPCODE__
    #define __ITFAPPCODE__

    #include <ItfTypes.h>
    #include <ItfCore.h>
    #include <ItfCoreVer.h>
    #include <App_LibTab.h>

    //--------------------------------------------------------------------------------------------------
    //! @brief  Initialization of new Objects [init]
    //--------------------------------------------------------------------------------------------------
    TVoid vLibRegistry( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Initialization of application CAN [init]
    //--------------------------------------------------------------------------------------------------
    TVoid vAppInitCan( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief Set application version [init]
    //--------------------------------------------------------------------------------------------------
    TVoid vSetAppVersion( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief Show application version after start [init]
    //! @param[in]  ptVer - [STU] Version-Information struct pointer
    //--------------------------------------------------------------------------------------------------
    TVoid vGetVersionInfo( TVerInf *ptVer );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Application test start
    //--------------------------------------------------------------------------------------------------
    TVoid vAppTestStart( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Application test end
    //--------------------------------------------------------------------------------------------------
    TVoid vAppTestEnd( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  App Fix Setting
    //--------------------------------------------------------------------------------------------------
    TVoid vAppFixInit( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  To install all the safety pins
    //--------------------------------------------------------------------------------------------------
    TVoid vAppSafetyInit( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Pre Start
    //! retval  R_OKAY  - go to the next application phase
    //! retval  !R_OKAY - stay in that application phase
    //--------------------------------------------------------------------------------------------------
    ERetVal eAppPreStart( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  First basic Initialization of application [start]
    //! retval  R_OKAY  - go to the next application phase
    //! retval  !R_OKAY - stay in that application phase
    //! @note   possibility to read an encoding plug via 'FIX Pins' and/or set the Default-List
    //!         except the DB-Opt list type
    //!         --> before that function is called the follow things are ready to use
    //!              a) 'FIX Pins'
    //!              b) all DB 'Options' List
    //!              c) the Debug Interface
    //--------------------------------------------------------------------------------------------------
    ERetVal eAppStartUp( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Complete Initialization of application [init]
    //! retval  R_OKAY  - go to the next application phase
    //! retval  !R_OKAY - stay in that application phase
    //! @note   possibility to change the setting for the 'OPT Pin'
    //!         possibility to change the Block Pining
    //--------------------------------------------------------------------------------------------------
    ERetVal eAppInit( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Cyclic application function [cyc]
    //! @retval  ptCoreInp - Application Input Interface to the "HCP Core Library"
    //! @retval  ptCoreOut - Application Output Interface to the "HCP Core Library"
    //--------------------------------------------------------------------------------------------------
    TVoid vAppRun( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Shut-down function [cyc]
    //! @retval  ptCoreInp - Application Input Interface to the "HCP Core Library"
    //! @retval  ptCoreOut - Application Output Interface to the "HCP Core Library"
    //! retval   R_OKAY    - go to the next application phase
    //! retval   !R_OKAY   - stay in that application phase
    //--------------------------------------------------------------------------------------------------
    ERetVal eAppShutDown( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Application Rcv Part [cyc]
    //--------------------------------------------------------------------------------------------------
    TVoid vAppRcv( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Application Snd Part [cyc]
    //--------------------------------------------------------------------------------------------------
    TVoid vAppSnd( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      vAcbPhasenCode - Auto code Builder Code
    //! @param[in]  pfvSafetyInit  - Application "Safety Pin Init"
    //! @param[in]  pfvPreStart    - Application "Pre-Start"
    //! @param[in]  pfvStartUp     - Application "Start Up" phase
    //! @param[in]  pfvInit        - Application "Initialization" phase
    //--------------------------------------------------------------------------------------------------
    TVoid vAcbPhasenCode( TVoid (*pfvSafetyInit ) ( TVoid ),
                          TVoid (*pfvPreStart   ) ( TVoid ),
                          TVoid (*pfvStartUp    ) ( TVoid ),
                          TVoid (*pfvAppInit    ) ( TVoid ));

    //--------------------------------------------------------------------------------------------------
    //! @brief      vAcb2AppPhasenCode - Auto code Builder Code
    //! @param[in]  pfvSafetyInit  - Application "Safety Pin Init"
    //! @param[in]  pfvPreStart    - Application "Pre-Start"
    //! @param[in]  pfvStartUp     - Application "Start Up" phase
    //! @param[in]  pfvInit        - Application "Initialization" phase
    //--------------------------------------------------------------------------------------------------
    TVoid vAcb2AppPhasenCode( TVoid (*pfvSafetyInit ) ( TVoid ),
                              TVoid (*pfvPreStart   ) ( TVoid ),
                              TVoid (*pfvStartUp    ) ( TVoid ),
                              TVoid (*pfvInit        ) ( TVoid ));

    //--------------------------------------------------------------------------------------------------
    //! @brief      vAcbStart
    //! @param[in]  pfvAcbCode     - ACB function call
    //! @note
    //!    Example:
    //!        TVoid vAcbAutoCodePreStart( TVoid ){ eBloCRcvChangeCanIdInc( &gCRcv_tRcv7Inc, 0x17020 ); }
    //!
    //!        TVoid vAcbAutoCode        ( TVoid ){ vAcbPhasenCode( NULL, vAcbAutoCodePreStart, NULL, NULL ); }
    //!
    //!        // if not generated by ACB to autocode, call in main before the while-Loop
    //!        vAcbAutoCodeAppend( vAcbAutoCode );
    //--------------------------------------------------------------------------------------------------
    TVoid vAcbAutoCodeAppend( TVoid (*pfvAcbCode ) ( TVoid ));


#endif

