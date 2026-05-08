//**************************************************************************************************
/*!
@file           ItfTestSuite.h
@brief          Test suite interface
@date           22.05.2013
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFTESTSUITE__
    #define __ITFTESTSUITE__

    #include <autoconfig.h>
    #include <ItfCUnit.h>

    #ifdef  COMPILER_SWITCH_TAR_PC

        #define TESTSUITE_PATH_SESSION_MAX  16      //!<  Maximal path session values

        #define _setTestSuitePath( u8Index, u8Value ) g_au8TestSuitePathSession[u8Index] = u8Value   //!< set path control value
        #define _GetTestSuitePath( u8Index          ) g_au8TestSuitePathSession[u8Index]             //!< get path control value

        // DEFINES & ENUMS  ================================================================================

        //! Path control memory array
        extern TUint8 g_au8TestSuitePathSession[TESTSUITE_PATH_SESSION_MAX];    //!< Session array

        //! Phase control memory
        extern TUint8  g_u8TestSuitePhase;                                      //!< Suite phase variable
        extern TUint16 g_u16TestSuiteExtPhase;                                  //!< Extend suite phase variable

        //--------------------------------------------------------------------------------------------------
        //! @brief      This Function can release or suppress the output from 'vPrintTestSuite(...)'
        //! @param[in]  boOn  - TRUE release the output, FALSE suppress the output
        //--------------------------------------------------------------------------------------------------
        extern TVoid vSetPrintTestSuiteMode( TBoolean boOn );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Print to PC shell
        //!             The output can release or suppress with the 'vSetPrintTestSuiteMode(..)'
        //! @param[in]  chTxt - Text interface via printf
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPrintTestSuite( const TChar *pchTxt, ... );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Print to PC shell
        //!             The output can release or suppress with the 'vSetPrintTestSuiteMode(..)'
        //! @param[in]  pchName   - Module name
        //! @param[in]  pvApiFunc - API module variable
        //! @param[in]  pvApiTab  - Module table
        //! @param[in]  u16Cnt    - Count
        //--------------------------------------------------------------------------------------------------
        extern TVoid vSetSuiteApi( TChar *pchName, TVoid *pvApiFunc, TVoid *pvApiTab, TUint16 u16Cnt );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set the suit path
        //! @param[in]  pchPath - the path
        //--------------------------------------------------------------------------------------------------
        extern TVoid vSetSuitePath( TChar *pchPath );

        //--------------------------------------------------------------------------------------------------
        //! @brief     Suite prepare - this function take care that the 'Main-State-Machine' start in the
        //!            first EMainPhase. This function should be called in the main() function, before the while-loop.
        //!            Note: With out call that function the 'Main-State-Machine' start with the second phase
        //!                  EMainPhase
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPySuitePrepare( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief     Set for the script test the system variable 'PY_ECUTYPE' to the ECU TYPE e.g PY_ECUTYPE=TTC90
        //!            Note: The core library set the system variable with: putenv("PY_ECUTYPE=TTC30") by calling that function
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPySuiteSetEcuType( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief     Set the PySuite test level (see HyTestSuite option - testlevel)
        //! @param[in] cpchLevel - Test level
        //!            Note: The core library set the system variable with: putenv("PY_TEST_LEVEL=1") by calling that function
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPySuiteTestLevel( const TChar *cpchLevel );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Suite run
        //! @param[in]  pchMainPyScript - Name of the started main python script
        //! @param[in]  pchSuiteName    - Name of the started suite,
        //!                               if pchSuiteName=NULL - all test suites will be started
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPySuiteRun( TChar *pchMainPyScript, TChar *pchSuiteName  );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Suite exit - stop the application (disconnect the CAN, terminated the application )
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPySuiteExit( TVoid );

    #else

        #define _setTestSuitePath( u8Index, u8Value )  //!< Set path control value - make nothing
        #define _GetTestSuitePath( u8Index          )  //!< Get path control value - make nothing

        #define vSetTestSuitePhase   ( u8Value )       //!< Set phase control
        #define vSetTestSuiteExtPhase( u16Value )      //!< Set phase control

    #endif

#endif
