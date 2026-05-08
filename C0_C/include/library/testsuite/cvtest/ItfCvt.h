//**************************************************************************************************
/*!
@file           ItfCvt.h
@brief          C verification test
@see            open
@date           08.04.2019
@author         HYDAC/NJP
@note
~~~
//// LITTE EXAMPLE OF USING -----

    #include <string.h>
    #include <ItfBasEleErr.h>
    #include <ItfCvt.h>
    #include <App_LibTab.h>
    #include <App_CanSigRec.h>

////! Verification Cases
    enum
    {
		CVT_MAIN_STATE,    //! 0 Main State Machine
		CVT_BLO_CSND,      //! 1 Block Can Snd
		CVT_BLO_SIL,       //! 2 Block Sil
		CVT_TEST_MAX       //! 3
    };

	static TCvtRec m_atRec[CVT_TEST_MAX] =
	{
		{ "CVT_MAIN_STATE", TRUE, 0, CVT_CHECK_UNDEF },
		{ "CVT_BLO_CSND",   TRUE, 0, CVT_CHECK_UNDEF },
		{ "CVT_BLO_SIL",    TRUE, 0, CVT_CHECK_UNDEF }
	};

////! Test Functions start  -----------------

    static TUint16 m_au16Test[2] = { 0, 1 };

    static TVoid m_vCvtInit_BloCSnd( TVoid )    // Init-Slot - use a set the conditons
    {
        vCvt_Print("CVT-Init BloSnd: OK"); m_au16Test[0]= 0; m_au16Test[1] = 3000;
    }
    static TVoid m_vCvtInit_BloSil( TVoid )     // Init-Slot
    {
        vCvt_Print("CVT-Init BloSil: OK");
    }

    static ERetVal m_eCvtRun_BloCSnd( TVoid )    // Run Slot: Test mimic
    {
        if( gCSnd_tSnd2.tOut.boSndDat == TRUE )
        {
//// Check CAN-SIGNAL-Record-VALUES
            if( gCsr_tSnd2.i16TestI16 == 5050 || gCsr_tSnd2.i16TestI16 == 5051 )
            {
               ; // Special Values
            }
            else if( gCsr_tSnd2.i16TestI16 <= m_au16Test[0] )
            {
                vCvt_Print("CVT-BloSnd ERR: %d - Soll:%d", gCsr_tSnd2.i16TestI16, m_au16Test[0] );
                return R_RANGE;
            }
            else if( gCsr_tSnd2.i16TestI16 >= m_au16Test[1] )
            {
                vCvt_Print("CVT-BloSnd ERR: %d - Soll:%d", gCsr_tSnd2.i16TestI16, m_au16Test[1] );
                return R_RANGE;
            }
            return R_OKAY;
        }
        return R_BUSY;
    }

    static ERetVal m_eCvtRun_BloSil( TVoid )  // Run Slot: Test mimic
    {
        #define DIAG_E_NOERROR                 0U // BSP:TTC5xx
        #define DIAG_E_INIT_CORE_MPU_TEST     49U // BSP:TTC5xx

        TDiagStatus tDiagSta      =   { DIAGSTATE_SAFE, { DIAG_E_INIT_CORE_MPU_TEST, 33, 77 } };
        TDiagStatus tDiagStaClear =   { DIAGSTATE_MAIN, { DIAG_E_NOERROR, 0, 0} };

        static TUint32 s_u32Run = 0;

        if( s_u32Run++ < 300 ){ eCoreSimSetEcuDiagStatus( &tDiagSta );      }
        else                  { eCoreSimSetEcuDiagStatus( &tDiagStaClear ); }

        if( s_u32Run < 400 )
        {
            return R_BUSY;
        }
        else
        {
            if( TRUE == boGet1BitU16(DM_ECU0_MEM, gSil_tEcu0_Safety.tBehErr.tErrSta.u16ErrSta ) )
            {
                return R_SUPPORT;
            }
            else
            {
                return R_OKAY;
            }
            return R_OKAY;
        }
    }

    TVoid vCvtMainPhaseCheck( EMainPhase ePhase )
	{
		#ifdef COMPILER_SWITCH_TAR_PC

		static EMainPhase s_eOld     = MAIN_CORE_DEBUG;
		static TUint16    s_u16Cnt  = 1;
		static TUint16    s_u16Show = 0;

		AVOID_WARRNING( (TUint8) ePhase );

		if( FALSE == boCvt_IsActiv(CVT_MAIN_STATE) ){ return; }

		if( 15000 < u32CoreGetTime() ) // ms
		{
			if( (s_u16Show % 1000)== 0 )
			{
				vCvt_Print( "CVT-Main-State: K15 switch to OFF");
				eCoreSimAdcSetPin( ADC_SYS_K15_D, PIN_SYS, 0 );
				s_u16Show = 0;
			}
			s_u16Show++;
		}

		if( ePhase != s_eOld )
		{
		   if( (TUint8)ePhase != ((TUint8)(s_eOld) + 1) && ePhase != MAIN_SAFETY_PRE_START )
		   {
			   vCvt_Print( "CVT-Main-State: ERR is not the expect Phase (%d != %d) ", ePhase, ((TUint8)(s_eOld) + 1) );
			   vCvt_TestEnd( CVT_MAIN_STATE, CVT_CHECK_ERROR );
		   }

		   if( ePhase == MAIN_SAFETY_PRE_START )
		   {
			   vCvt_Print( "CVT-Main-State: MainPhase start");
		   }

		   vCvt_Print( "Phase: %d (Cyl: %2d)", ePhase, s_u16Cnt );

		   if( ePhase == MAIN_CORE_EXIT )
		   {
			   vCvt_Print( "CVT-Main-State: Test is CORRECT");
			   vCvt_TestEnd( CVT_MAIN_STATE, CVT_CHECK_OKAY );
		   }

		   s_u16Cnt = 1;
		   s_eOld = ePhase;
		}
		else
		{
		   s_u16Cnt++;
		}

		#else
		AVOID_WARRNING( (TUint8) ePhase );
		vCvt_TestEnd( CVT_MAIN_STATE, CVT_CHECK_NA );
		#endif
	}

////! Test Functions end  -----------------

    TVoid vCvtInstallTestFrame( TVoid )
    {
        vCvt_MemInit( CVT_TEST_MAX, m_atRec );
        vCvt_ResetResults();
    }

    TVoid vCvt_StartUp( TVoid )
    {
       if( boCvt_IsActiv( CVT_BLO_CSND ) ){ m_vCvtStartUp_BloCSnd(); }
       if( boCvt_IsActiv( CVT_BLO_SIL )  ){ m_vCvtStartUp_BloSil();  }
    }

    TVoid vCvt_Init( TVoid )
    {
        if( boCvt_IsActiv( CVT_BLO_CSND ) ){ m_vCvtInit_BloCSnd(); }
        if( boCvt_IsActiv( CVT_BLO_SIL  ) ){ m_vCvtInit_BloSil();  }
    }

    TVoid vCvt_Run( TVoid )
    {
        TUint16  u16Val;
        ERetVal  eRet;

        if( boCvt_ProcessCntl() )
        {
            u16Val = CVT_BLO_CSND;
            if( boCvt_IsActiv( u16Val ) ){ eRet = m_eCvtRun_BloCSnd(); vCvt_Check( u16Val, eRet ); } // m_eCvtRun_BloCSnd() call until !R_BUSY

            u16Val = CVT_BLO_SIL;
            if( boCvt_IsActiv( u16Val ) ){ eRet = m_eCvtRun_BloSil(); vCvt_Check( u16Val, eRet );  } // m_eCvtRun_BloCSnd() call until !R_OKAY
        }

//// Auto report if both testcase don't return busy:
////
//// CVT-Sta: OKAY CVT_BLO_SIL
//// == CVT Result [CASE: 2] ===
////  OK: 2    ERR:   0
////  NA: 0    UNDEF: 0
//// ===========================
////
//// OKAY History:
////   1. CVT_BLO_CSND
////   2. CVT_BLO_SIL
//// Runtime: 4920
    }

//// Musst call in the 'Application Main Phasen'

    TVoid vAppTestStart( TVoid )
    {
        vCvt_FrameInit( vCvtInstallTestFrame );
    }

    ERetVal eAppInit( TVoid )
    {
        vCvt_Init( );
    }

    TVoid vAppRun( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
    {
        vCvt_Run()
    }

    ERetVal eAppShutDown( TCoreInp *ptCoreInp, TCoreOut *ptCoreOut )
    {

    }
~~~
*/
//**************************************************************************************************

#ifndef __ITFCVT__
    #define __ITFCVT__

    #include <ItfTypes.h>

    //! C verification test check status
    typedef enum
    {
        CVT_CHECK_UNDEF,   //! No verification test is active (g_caboCvtCaseCntlFix[x]=FALSE)
        CVT_CHECK_OKAY,    //! Verification is finish and OK  (g_caboCvtCaseCntlFix[x]=TRUE)
        CVT_CHECK_ERROR,   //! Verification is incorrect      (g_caboCvtCaseCntlFix[x]=TRUE)
        CVT_CHECK_NA       //! Test not applicable            (g_caboCvtCaseCntlFix[x]=TRUE)
    }ETestVarCheck;

    typedef struct
    {
    	TChar          achCaseName[32+1];    //!< Cases name -> name can have 32 letters and end with \0
    	const TBoolean cboCaseCntlFix;       //!< Fix control table (important for the soft reset)
    	TBoolean       boCaseCntl;           //!< Working control table
    	ETestVarCheck  eCheckResult;         //!< Result array
    }TCvtRec;


    //--------------------------------------------------------------------------------------------------
    //! @brief      This feature brings a "function" to the system, the function will always executed after
    //!             a new 'ecu start' in the first core main phase.
    //!             Note:  With that function it is possible to create an 'validation test code' in the application
    //!             Note2: Call the function in 'vAppTestStart()'-Phase
    //! @param[in]  m_pfvVal_InstallTestFrame
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCvt_FrameInit( TVoid (*pfvVal_InstallTestFrame)( TVoid ) );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Verification is in the flow or finish
    //! @param[in]  u16Phase - Test case
    //! @return     TRUE  = in the flow
    //!             FALSE = is finish
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCvt_IsActiv( TUint16 u16Phase );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set test result
    //! @param[in]  ePhase - Test case
    //! @retval     R_BUSY: Test is working
    //! @retval     R_OKAY: Test is finish and OK
    //! @retval     else:   Test is finish and incorrect
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCvt_Check( TUint16 u16Phase, ERetVal eRet );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Terminate the test case (OK/INCORRECT)
    //! @param[in]  eCheck - check status
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCvt_TestEnd( TUint16 u16Phase, ETestVarCheck eCheck );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the CVT-Frame work the CVT-Records
    //! @param[in]  u16CaseMax - Count of test cases
    //! @param[in]  ptRec      - Test case records
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCvt_MemInit( TUint16 u16CaseMax, TCvtRec *ptRec );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Reset results must be call in vCvtInstallTestFrame()
    //!             Reset the g_aeCvtCheckResult[] array
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCvt_ResetResults( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      C verification test control process
    //!             review all test cases
    //! @retval     TRUE = same test cases are not finish
    //! @retval     FALSE = all test cases are finished
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCvt_ProcessCntl( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Print of Can => Output: Text+'\n'  [CAN.au8Dat[0]=0xFF, CAN.au8Dat[1...7]=Text-Char]
    //! @brief      Note: For suppress the new line on the end use '\f' eg. "Hello %s \f"
    //! @param[in]  pchTxt
    //! @param[in]  ..
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCvt_Print( const TChar *pchTxt, ... );

    // Important variables - the value / the array size came from the application-'verification cases' see Cvt_Control.h
    extern TUint16        g_u16CvtCaseMax;              //!< how many cases
    extern TChar          g_aachCvtCaseName   [][32+1]; //!< Cases name -> name can have 32 letters and end with \0
    extern const TBoolean g_caboCvtCaseCntlFix[];       //!< Fix control table (important for the soft reset)
    extern TBoolean       g_aboCvtCaseCntl    [];       //!< Working control table
    extern ETestVarCheck  g_aeCvtCheckResult  [];       //!< Result array

#endif


