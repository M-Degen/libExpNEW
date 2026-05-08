//**************************************************************************************************
/*!
@file       ItfBasOut.h
@brief      Basic Can output functions (for debugging)
@date       20.02.2011
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBASOUT__
	#define __ITFBASOUT__

// INCLUDES ========================================================================================
	#include <ItfTypes.h>
    #include <ItfCore.h>

    #define DEBUG_STR_LEN (64+1)                         //!< String length

    extern volatile TChar vg_achDebugTxt[DEBUG_STR_LEN];  //!< Debug text -> vPrint(...)
    extern volatile TChar vg_achDebugPin[DEBUG_STR_LEN];  //!< Debug text -> vPrintPin(...)
    extern volatile TChar vg_achDebugErr[DEBUG_STR_LEN];  //!< Debug text -> vPrintErr(...)
    extern volatile TChar vg_achDebugWar[DEBUG_STR_LEN];  //!< Debug text -> vPrintWar(...)

    #define ERR_NA      0       //!< No prefix text
    #define ERR_DFLT    1       //!< Error default prefix text: "ERR:

    #define WAR_NA      0       //!< No prefix text
    #define WAR_DFLT    1       //!< Warning default prefix text: "WAR:"

    //! Debug Level Control
    typedef enum
    {
       DEBUGLEVEL_NONE,         //!<  No Debug phase                       - no
       DEBUGLEVEL_ERR,          //!<  Debug phase only by errors [DEFAULT] - vPrintErr()
       DEBUGLEVEL_WAR           //!<  Debug phase by errors and warnings   - vPrintErr(), vPrintWar()
    }EDebugLevelControl;

    //! Print Mode
    typedef enum
    {
        OUT_PRINT_PIN,          //!< Print Pin Symbol
        OUT_PRINT_WAR,          //!< Print Warning Symbol
        OUT_PRINT_ERR_WD,       //!< Print Error Watchdog Symbol
        OUT_PRINT_ERR,          //!< Print Error Symbol
        OUT_PRINT               //!< Print Symbol
    }EPrintMode;

    //! Byte Fifo
    typedef struct
    {
        TUint16  u16StartIdx;    //!< internal start index
        TUint16  u16FreeIdx;     //!< internal the next free index
        TUint16  u16Cnt;         //!< internal count of bytes
        TUint16  u16StrMax;      //!< internal input string length
        TUint16  u16DataSize;    //!< internal fifo size
        TChar    *achData;       //!< internal data
    }TFifoStr;

    //--------------------------------------------------------------------------------------------------
    //! @brief   Clear all vPrint-, vPrintErr-, vPrintWar-, vPrintPin-Strings
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintXxxClearFifo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Set the print out control mode [only protocol needed]
    //! @param   boOn  - FALSE(Debug=OFF) -> vPrint is disabled
    //!                - TRUE (Debug=ON)  -> vPrint is enabled
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintCtrlMode( TBoolean boOn );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Get the print out control mode [only protocol needed]
    //! @return  boOn
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boPrintGetCtrlMode( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Set the print pin out control mode [only protocol needed]
    //! @param   boOn  - FALSE(Debug=OFF) -> the Pin report is disabled
    //!                - TRUE (Debug=ON)  -> the Pin report is enabled
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintPinCtrlMode( TBoolean boOn );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Get the print pin out control mode [only protocol needed]
    //! @param   boOn
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boPrintPinGetCtrlMode( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief   Copy to the debug array [g_achDebugTxt[], g_achDebugPin[], g_achDebugErr[], g_achDebugWar[] ]
    //!          To get the information if the can communication channel failed
    //! @param   boOn
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintCopyToDebug( TBoolean boOn );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Print to the MST interface => Output:  Text+New-Line [CAN.au8Dat[0]=0xFF, CAN.au8Dat[1...7]=Text-Char]
    //! @brief      Note: To suppress the new line at the end use '\f' e.g. "Hello %s \f".
    //! @brief      For print out that is always visible to the user. 
    //! @brief      That message will always be shown in the 'Debug Window'.
    //! @brief      Max 80 Chars will be printed, if string is longer it will be terminated with '#'
    //! @param[in]  cpchTxt
    //! @param[in]  ..
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintAlways( const TChar *cpchTxt, ... );

	//--------------------------------------------------------------------------------------------------
    //! @brief      Print to the MST-Interface => Output: Text+"\n" [CAN.au8Dat[0]=0xFF, CAN.au8Dat[1...7]=Text-Char]
    //! @brief      Note: To suppress the new line at the end use '\f' eg. "Hello %s\f".
    //! @brief      For print out that is visible to the user only if the debug mode is 'ON'. E.g for a status report.
    //! @brief      That Message will be shown in the 'Debug Window' - only if the debug mode is active.
    //! @brief      Max 80 Chars will be printed, if string is longer it will be terminated with '#'
    //! @param[in]  cpchTxt
    //! @param[in]  ..
    //--------------------------------------------------------------------------------------------------
	extern TVoid vPrint( const TChar *cpchTxt, ... );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the debug phase control level - DEBUGLEVEL_ERR is the default value
    //!             Can call in each app phase (the best phase is the AppFix). The setting is soft reset stable!
    //!             It is not possible to over control all DEBUG-Point, also not with 'DEBUGLEVEL_NONE', because it
    //!             is not possible to repair or overrun the incorrect point
    //! @param[in]  eLevel - Control level
    //--------------------------------------------------------------------------------------------------
	extern TVoid vSetDebugLevelControl( EDebugLevelControl eLevel );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Print error to the MST-Interface => Output: "ERR:"+Text"+"\n" [CAN.au8Dat[0]=0xFE, CAN.au8Dat[1...7]=Text-Char]
    //! @brief      Note: To suppress the new at the end use '\f' eg. "Hello %s \f"
    //! @brief      Only for very important print out. E.g for a fault report that the user must always see - to fix a problem
    //! @brief      That Message will be shown always in a red bold color in the 'Debug window'.
    //! @brief      If the function used before the vAppRun phase, the ecu goes into the Debug phase (behavior change: vSetDebugLevelControl() )
    //! @brief      Max 80 Chars will be printed, if string is longer it will be terminated with '#'
    //! @param[in]  u16ErrIdx: ERR_NA=no pre text, ERR_DFLT=pre text "ERR:"+Text+"\n", else "E(Index-Number):"+Text+"\n" eg. "E17: Fault Report\n"
    //!             2-10000: Reserved for the core and the standard blocks
    //! @param[in]  cpchTxt
    //! @param[in]  ..
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintErr( TUint16 u16ErrIdx, const TChar* cpchTxt, ... );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Print warning to the MST-Interface => Output: "WAR:"+Text"+"\n" [CAN.au8Dat[0]=0xFD, CAN.au8Dat[1...7]=Text-Char]
    //! @brief      Note: To suppress the new at the end use '\f' eg. "Hello %s \f"
    //! @brief      That message will be shown in a yellow bold color in the 'Debug Window'.
    //! @brief      Max 80 Chars will be printed, if string is longer it will be terminated with '#'
    //! @param[in]  u16WarIdx: WAR_NA=no pre text, WAR_DFLT pre text "WAR:+Text+"\n", else "W(Index-Number): eg. "W19: Warning Report\n"
    //!             2-10000: Reserved for the core and the standard blocks
    //! @param[in]  cpchTxt
    //! @param[in]  ..
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintWar( TUint16 u16WarIdx, const TChar* cpchTxt, ... );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the marker that the vPrintWar()-Function is called
    //! @retval     TRUE:  marker is active      - vPrintWar(...) is called
    //! @retval     FALSE: marker is not  active - vPrintWar(...) isn't called
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGetPrintWarMarker( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the marker that the vPrintErr()-Function is called
    //! @retval     TRUE:  marker is active      - vPrintErr(...) is called
    //! @retval     FALSE: marker is not  active - vPrintErr(...) isn't called
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGetPrintErrMarker( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the marker that the vPrintErrWd()-Function is called
    //! @retval     TRUE:  marker is active      - vPrintErrWd(...) is called
    //! @retval     FALSE: marker is not  active - vPrintErrWd(...) isn't called
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGetPrintErrWdMarker( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Reset the vPrintWar/Err/ErrWd markers
    //!             !! The use of this functions in the application leads immediately to the exclusion of the HYDAC liability.
    //!             !! The use of the entire application with all the components used a call at your own risk.
    //--------------------------------------------------------------------------------------------------
    extern TVoid vResetAllPrintMarkers( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      With that function it is possible to add an Debug-Function in the error or warning
    //!             Print out function.
    //!             E.g  add in the main-function before the while loop the following.
    //!                 TVoid vDebug( TVoid )
    //!                 {
    //!                 (BP) static TUint8 m_u8Info = 0; m_u8Info++; AVOID_WARRNING( m_u8Info );
    //!                 }
    //!                 while( 1 )
    //!             Now add an breakpoint(BP) in the vDebug-Function, if now will call the vPrintErr(..) or the vPrintWar()
    //!             the debugger will stop on the breakpoint - and now the Debugger-Call-Stack give more information,
    //!             of all involved function calls
    //!             E.g
    //!                 5 vDebug()    main_cen.c:   145 0x0040137f
    //!                 4 vPrintErr() BasOut.c:     475 0x00403cd3
    //!                 3 vAppRun()   AppCode.c:    349 0x0043a4d4
    //!                 2 vCoreMain() CoreMain.c:  1672 0x0042c36f
    //!                 1 main()      main_cen.c:   151 0x0040143f
    //! @param[in]  pfvPrintErr - Error debug interface function
    //! @param[in]  pfvPrintWar - Warning debug interface function
    //--------------------------------------------------------------------------------------------------
    extern TVoid vPrintErrWarDebugItf( TVoid (*pfvPrintErr)( TVoid ), TVoid (*pfvPrintWar)( TVoid ) );

    //--------------------------------------------------------------------------------------------------
    //! @brief         Init the string fifo
    //! @param[in,out] ptFi         - Fifo pointer
    //! @param[in]     u16DataSize  - Fifo length size
    //! @param[in]     u16StrLenMax - Maximal length of a string
    //! @retval        R_OKAY          - fine
    //! @retval        R_NULL_POINTER  - Null pointer in the parameter
    //! @retval        R_MEMORY        - don't get memory
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutFifoStrInit( TFifoStr *ptFi, TUint16 u16DataSize, TUint16 u16StrLenMax );

    //--------------------------------------------------------------------------------------------------
    //! @brief         Clear the the string fifo
    //! @param[in,out] ptFi         - Fifo pointer
    //! @retval        R_OKAY          - fine
    //! @retval        R_NULL_POINTER  - Null pointer in the parameter
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutFifoStrClear( TFifoStr *ptFi );

    //--------------------------------------------------------------------------------------------------
    //! @brief         Add a string in the fifo
    //! @param[in,out] ptFi       - Fifo pointer
    //! @param[in]     u8ChaNo    - Print Channel Number
    //! @param[in]     u8PrintCom - Print command
    //! @param[in]     achData     - add string
    //! @retval        R_OKAY          - fine
    //! @retval        R_NULL_POINTER  - Null pointer in the parameter
    //! @retval        R_RANGE         - a part of the string is copy in the filo (same part is missing - no space)
    //! @retval        R_OVERFLOW      - no space in the fifo
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutFifoStrPut( TFifoStr *ptFi, TChar* pchStr );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get the a string from the print fifo
    //! @param[in,out]  ptFi       - Fifo pointer
    //! @param[out]     pchStr     - string
    //! @param[out]     pu8Dlc     - String data length code
    //! @param[out]     u8ChaNo    - Print channel number
    //! @param[out]     u8PrintCom - Print command
    //! @param[out]     achData     - add string
    //! @retval         R_OKAY          - fine
    //! @retval         R_NULL_POINTER  - Null pointer in the parameter
    //! @retval         R_EMPTY         - the fifo is empty
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutFifoStrGet( TFifoStr *ptFi, TChar *pchStr, TUint8 *pu8Dlc );

    //--------------------------------------------------------------------------------------------------
    //! @brief         Add a string with the 'Channel Number' and Command in the print fifo
    //! @param[in,out] ptFi       - Fifo pointer
    //! @param[in]     u8ChaNo    - Print Channel Number [value range: 0-15, 15 is the vPrintChannel]
    //! @param[in]     ePrintMode - Print Mode
    //! @param[in]     pchStr     - add string
    //! @retval        R_OKAY          - fine
    //! @retval        R_NULL_POINTER  - Null pointer in the parameter
    //! @retval        R_RANGE         - a part of the string is copy in the filo (same part is missing - no space)
    //! @retval        R_OVERFLOW      - no space in the fifo
    //! @retval        R_MAXIMUM       - Channel number to big
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutFifoStrChaComPut( TFifoStr *ptFi, TUint8 u8ChaNo, EPrintMode ePrintMode, TChar* pchStr );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get the a string from fifo, with 'channel id' and 'command'
    //! @param[in,out]  ptFi       - Fifo pointer
    //! @param[out]     pchStr     - string
    //! @param[out]     pu8Dlc     - String data length code
    //! @param[out]     u8ChaNo    - Print channel number
    //! @param[out]     u8Com      - Print command
    //! @retval         R_OKAY          - fine
    //! @retval         R_NULL_POINTER  - Null pointer in the parameter
    //! @retval         R_EMPTY         - the fifo is empty
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutFifoStrChaComGet( TFifoStr *ptFi, TChar *pchStr, TUint8 *pu8Dlc, TUint8 *pu8ChanNo, TUint8 *pu8Com );

    #ifdef COMPILER_SWITCH_TAR_PC

        //--------------------------------------------------------------------------------------------------
        //! @brief      Print to the console (only for the PC application) -> Output: <+"Text"+>+"\n" [printf, with fflush]
        //! @brief      Note: To suppress the new at the end use '\f' eg. "Hello %s \f"
        //! @brief      Note: < ... > show that is only an PC-Shell Print Out
        //! @param[in]  pchTxt
        //! @param[in]  ..
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPrintPcShell( const TChar *cpchTxt, ... );

        //--------------------------------------------------------------------------------------------------
        //! @brief      This Function can release or suppress the output from 'vPrintTestSuite(...)'
        //! @param      boOn  - TRUE release the output, FALSE suppress the output
        //--------------------------------------------------------------------------------------------------
        extern TVoid vSetPrintTestSuiteMode( TBoolean boOn );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Print to the console (only for the PC application) -> Output: "+Text"+"\n" [printf, with fflush]
        //! @brief      Note: To suppress the new at the end use '\f' eg. "Hello %s \f"
        //! @param      chTxt
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPrintTestSuite( const TChar *cpchTxt, ... );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Pipe the vPrint also to the vPrintPcShell
        //! @param      boOn      Connection is TRUE=Active, FALSE=Inactive
        //! @param      boAlways  TRUE=Always open, False=Use the current debug mode behavior
        //--------------------------------------------------------------------------------------------------
        extern TVoid vPrintLinkToShell( TBoolean boOn, TBoolean boAlways );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Open an by pass 'pipe file' for the shell output contents
        //!             To scan the file during the run time - please close the file with the function ePrintShellCloseFile()
        //! @param      pchFileName  File Name
        //! @param      boOverWrite  TRUE=over write the file contents, FALSE=append the file contents
        //! @retval     R_OKAY    - fine
        //! @retval     R_UNKNOWN - file not possible to create/open
        //--------------------------------------------------------------------------------------------------
        extern ERetVal ePrintShellOpenFile( TChar *pchFileName, TBoolean boOverWrite );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Close the File for the shell output
        //! @retval     R_OKAY    - fine
        //! @retval     R_UNKNOWN - file not possible to close
        //--------------------------------------------------------------------------------------------------
        extern ERetVal ePrintShellCloseFile( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Represents the number in binary form and show it only in the pc shell (only the number, without '<','>','\n' )
        //! @param[in]  boZeroFill - also represents a leading zero
        //! @param[in]  u8Val      - number
        //--------------------------------------------------------------------------------------------------
        extern TVoid  vPrintPcU8Binary ( TBoolean boZeroFill, TUint8  u8Val );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Represents the number in binary form and show it only in the pc shell (only the number, without '<','>','\n' )
        //! @param[in]  boZeroFill - also represents a leading zero
        //! @param[in]  u16Val     - number
        //--------------------------------------------------------------------------------------------------
        extern TVoid  vPrintPcU16Binary( TBoolean boZeroFill, TUint16 u16Val );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Represents the number in binary form and show it only in the pc shell (only the number, without '<','>','\n' )
        //! @param[in]  boZeroFill - also represents a leading zero
        //! @param[in]  u32Val     - number
        //--------------------------------------------------------------------------------------------------
        extern TVoid  vPrintPcU32Binary( TBoolean boZeroFill, TUint32 u32Val );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Represents the number in binary form and show it only in the pc shell (only the number, without '<','>','\n' )
        //! @param[in]  boZeroFill - also represents a leading zero
        //! @param[in]  u64Val     - number
        //--------------------------------------------------------------------------------------------------
        extern TVoid  vPrintPcU64Binary( TBoolean boZeroFill, TUint64 u64Val );

    #endif

// ONLY Protocol functions ----------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------------------
    //! @brief          Get the a string from the print fifo [needed ONLY for the protocol connection]
    //! @param[out]     pchStr      - string
    //! @param[out]     pu8Dlc      - String data length code
    //! @param[out]     u8ChaNo     - Print channel number
    //! @param[out]     pu8PrintCom - Print command
    //! @param[out]     achData     - add string
    //! @retval         R_OKAY          - fine
    //! @retval         R_NULL_POINTER  - Null pointer in the parameter
    //! @retval         R_MEMORY        - don't get memory
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eOutPrintFifoGet( TChar *pchStr, TUint8 *pu8Dlc, TUint8 *pu8ChanId, TUint8 *pu8PrintCom );

    //--------------------------------------------------------------------------------------------------
    //! @brief          Set the Print out Access Level - necessary for the show errors on the print out interface
    //! @param[out]     eAccLevel - Access Level
    //--------------------------------------------------------------------------------------------------
    extern TVoid vOutPrintAccessLevel( EAccLevel eAccLevel );

#endif
