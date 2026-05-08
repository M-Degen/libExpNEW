//**************************************************************************************************
/*!
@file       ItfCoreVer.h
@brief      Versions Interface
@date       20.02.2011
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREVER__
    #define __ITFCOREVER__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreCan.h>

// DEFINES & ENUMS  ================================================================================
                                     // +1 -> String terminate with 0
    #define VERVEHI_STR_8            ( 8+1)        //!< Vehicle code
    #define VERINFO_STR_16           (16+1)        //!< Version information space
    #define VERINFO_STR_32           (32+1)        //!< Version information space
    #define VEREXTE_STR_16           (16+1)        //!< Version environment space
    #define VERDATE_STR_16           (16+1)        //!< Date space xxxx.xx.xx  ( effective 10 + more 6)
    #define VERTIME_STR_16           (16+1)        //!< Time space xx:xx:xx    ( effective  8 + more 6)

    #define VER_EXT_REC_MAX             82         //!< Version extended record max length
    #define VER_NA                    0xFF         //!< Version extended define - no storing possible

    #define VER_DIGIT_DONTCARE_U8     0xFF         //!< Version digit don't care
    #define VER_DIGIT_DONTCARE_U16  0xFFFF         //!< Version digit don't care

    //! Chapter common
    typedef struct
    {
        TUint8  u8Major;                           //!< Major software version number
        TUint8  u8Minor;                           //!< Minor software version number
        TUint8  u8Index;                           //!< Software version index
        TUint16 u16DevStp;                         //!< Software development step
        TChar   achDate[VERDATE_STR_16];           //!< Creation date - e.g.: '01.01.2011'
        TChar   achTime[VERTIME_STR_16];           //!< Creation time - e.g.: '00:00:00'
    }TVerChapCom;

    //! Chapter common
    typedef struct
    {
        TChar   achAppSwPartNo[VERINFO_STR_16];    //!< Customer SW part number/ Kunden Software Materialnummer
        TChar   achAppSwVerNo[VERINFO_STR_16];     //!< Customer SW version number/ Kunden Software Versionsnummer
        TChar   achAppParPartNo[VERINFO_STR_16];   //!< Customer parameter part number/ Kunden Parameter Materialnummer
        TChar   achAppParVerNo[VERINFO_STR_16];    //!< Customer parameter version number/ Kunden Parameter Versionsnummer
    }TVerAppSwNo;

    //! Chapter frame
    typedef struct
    {
        TUint8  u8Major;                           //!< Major software version number
        TUint8  u8Minor;                           //!< Minor software version number
        TUint8  u8Index;                           //!< Software version index
        TUint8  u8DbParIdx;                        //!< Database parameter index
        TUint8  u8FlaParIdx;                       //!< Factory flash data index
        TUint16 u16DevStp;                         //!< Software development step
        TChar   achDate[VERDATE_STR_16];           //!< Creation date - e.g.: '01.01.2011'
        TChar   achTime[VERTIME_STR_16];           //!< Creation time - e.g.: '00:00:00'
    }TVerChapFra;

    //! Chapter number short
    typedef struct
    {
        TUint8  u8Major;                            //!< Major software version number
        TUint8  u8Minor;                            //!< Minor software version number
        TUint16 u16DevStp;                          //!< Software development step
    }TVerChapNumShort;

    //! Chapter number
    typedef struct
    {
        TUint8  u8Major;                            //!< Major software version number
        TUint8  u8Minor;                            //!< Minor software version number
        TUint8  u8Index;                            //!< Software version index
        TUint16 u16DevStp;                          //!< Software development step
    }TVerChapNum;

    //! Compiler version
    typedef struct
    {
        TChar   achSupplier[VERINFO_STR_16];        //!< Compiler supplier
        TChar   achVersion[VERINFO_STR_16];         //!< Compiler version
        TUint16 u16BuildProcNo;                     //!< Build process number
    }TVerCompiler;

    //! Ecu memory information
    typedef struct
    {
        TUint32 u32EcuLastRunTime;                  //!< 4 Last run time
        TUint32 u32EcuOnSwitch;                     //!< 4 Count of On/Off switch cycles
        TUint32 u32NvmDbStoreCnt;                   //!< 4 Count of NvMem store process
        TUint32 u32NvmMemStoreCnt;                  //!< 4 Count of NvMem memory field store cycles counts
        TUint32 u32NvmErrStoreCnt;                  //!< 4 Count of NvMem errors store cycle counts
        TUint8  u8RestartReaInfo;                   //!< 2 Reason for the last restart info
        TUint8  u8RestartReaDetail;                 //!< 2 Reason for the last restart info in detail
    }TVerEcuMem; // 24

    //! Hex-file flash date
    typedef struct
    {
        TUint16  u16Year;                           //!< [y] - Year
        TUint8   u8Month;                           //!< [m] - Month
        TUint8   u8Day;                             //!< [d] - Day
        TUint8   u8Hour;                            //!< [h] - Hour
        TUint8   u8Minute;                          //!< [s] - Minute
    }TVerFlashDate;

    //! Version information
    typedef struct
    {
        // ECU number
                                                           //!< (00)[SUB0.0] ECU number - from the ECU page
        // Environment information
        TChar         achHistory[VERINFO_STR_16];          //!< (01)[SUB0.1] Project history version no
        // Machine access protection
        TChar         achVehicleCode[VERVEHI_STR_8];       //!< (02)[SUB0.2] Vehicle access code
                                                           //!<
        // Vehicle identification
        TChar         achManufacturer[VERINFO_STR_16];     //!< (03)[SUB1.0] Vehicle manufacturer name / Fahrzeughersteller
        TChar         achManuLocation[VERINFO_STR_16];     //!< (04)[SUB1.1] Vehicle manufacturing location / Fahrzeug Produktionsstandort
        TChar         achBrand[VERINFO_STR_16];            //!< (05)[SUB1.2] Brand name / Markenname
        TChar         achType[VERINFO_STR_16];             //!< (06)[SUB1.3] Vehicle type / Fahrzeugtyp (z.B. 416-01)
        TChar         achVehPartNo[VERINFO_STR_16];        //!< (07)[SUB1.4] Vehicle part number / SAP Materialnummer Fahrzeuggruppe (SAP)
        TChar         achVehSalesName[VERINFO_STR_32];     //!< (08)[SUB1.5] Vehicle sales name / Verkaufsbezeichnung (z.B: Zero Emission 803)
        TChar         achVehSerNo[VERINFO_STR_32];         //!< (09)[SUB2.0] Vehicle serial number / Fahrgestellnummer
        TChar         achVehProdDate[VERINFO_STR_16];      //!< (10)[SUB2.1] Production date / Produktionsdatum
        TChar         achVehProdTime[VERINFO_STR_16];      //!< (11)[SUB2.2] Production time / Produktionszeit
        TChar         achVehMaxSpeed[VERINFO_STR_16];      //!< (12)[SUB2.3] Vehicle maximum speed / Maximale Fahrgeschwindigkeit
        TChar         achVehProdCode[VERINFO_STR_32];      //!< (13)[SUB2.4] Complete production code / Vollständiger Produktionskode
        TChar         achVehProdType[VERINFO_STR_16];      //!< (14)[SUB2.5] SAP product type / SAP Produkt-Typ (Customer)

        // Application software
        TVerChapCom   tAppVersion;                         //!< (20)[SUB3.0-5]  Application software version information
        TChar         achAppHydSwNo[VERINFO_STR_16];       //!< (21)[SUB3.6]    Hydac application software part numbers / Hydac Applikations-Software Materialnummern
        TVerAppSwNo   tAppCusSwNo;                         //!< (25)[SUB3.7-10] Customer application software numbers / Customer Applikations-Software Nummern

        // SAP Information
        TUint32       u32SapArtCodeApp;                    //!< (26)[SUB4.0] SAP article code for: application
        TUint32       u32SapArtCodeCore;                   //!< (27)[SUB4.1] SAP article code for: HCP-, ECU-BIOS, environment

        // Detailed software informations
        TVerChapFra      tFrameVersion;                    //!< (35)[ SUB5.0-7] Frame software version information
        TVerChapCom      tHcpBios;                         //!< (41)[ SUB6.0-5] Software Hcp-Bios version information
        TVerChapNumShort tBootOrRtsBios;                   //!< (44)[ SUB7.0-2] Software bootloader/Cds-Rts version information
        TVerChapNumShort tIoDriver;                        //!< (47)[ SUB8.0-2] Software IO driver version information
        TVerChapNumShort tMiniModul;                       //!< (50)[ SUB9.0-2] Software mini module version information
        TVerCompiler     tCompiler;                        //!< (53)[SUB10.0-2] Compiler version information

        // Controller hardware information
        TChar            achEcuType[VERINFO_STR_16];       //!< (54)[SUB11.0] Controller type
        TChar            achEcuVerNo[VERINFO_STR_32];      //!< (55)[SUB11.1] Controller version number 'xx.xx' (TTControl)
        TChar            achEcuSerNo[VERINFO_STR_16];      //!< (56)[SUB11.2] Controller serial number  'xxxxxxxxxxx' (TTControl)
        TChar            achEcuPartNo[VERINFO_STR_16];     //!< (57)[SUB11.3] Controller part number / Materialnummer Steuergerät (Hydac)
        TChar            achEcuAssPartNo[VERINFO_STR_16];  //!< (58)[SUB11.4] Controller  assembly customer part number / Materialnummer Baugruppe Steuergerät  Kunde
        TChar            achEcuSapPartNo[VERINFO_STR_16];  //!< (59)[SUB11.5] Controller customer part number / Kunden-Materialnummer Steuergerät (SAP)
        TChar            achEcuSapVerNo[VERINFO_STR_16];   //!< (60)[SUB11.6] Controller customer version number / Kunden-Versionsnummer Steuergerät (SAP)
        TVerChapNumShort tWatchdog;                        //!< (63)[SUB12.0-2] Watchdog hardware version information
        TVerFlashDate    tFlash;                           //!< (68)[SUB13.0-4] Flash stamp

        // Controller HCP-environment information
        TVerEcuMem    tEcuMem;                             //!< (75)[SUB14.0-6] Controller stored information
        TChar         achEnvVer[VEREXTE_STR_16];           //!< (76)[SUB15.0] Environment OS
        TChar         achExeVer[VEREXTE_STR_16];           //!< (77)[SUB15.1] Executable tool version
        TChar         achPatVer[VEREXTE_STR_16];           //!< (78)[SUB15.2] Pattern version

        // File check numbers
        TUint32       u32ErrMstFileCrc;                    //!< (79)[SUB16.0] MST error definition file check number
        TUint32       u32IomMstFileCrc;                    //!< (80)[SUB16.1] MST PIN definition file check number
        TUint32       u32TbcMstFileCrc;                    //!< (81)[SUB16.2] MST 'License List' file check number

        // Auto generate code - FRAME_CRC_STOP
        TUint32       u32AutoCodePreCrc;                   //!< Auto code Pre Crc
        TUint32       u32AutCodePostCrc;                   //!< Auto code Post Crc

        // Check core frame
        TVerChapNum   tCoreFrameCheck;                     //!< Core frame check
    }TVerInf;

    //! Version extended recorder
    typedef struct
    {
        TUint16   u16ComId;                                //!< Communication ID
        TBoolean  boFlashStore;                            //!< Flash store option
        TBoolean  boNvmStore;                              //!< NvMem store option
        TUint16   u16AccCode;                              //!< Access level
    }TVerExtRec;

    //! Version extended record collection
    typedef struct
    {
        TVerExtRec atRec[VER_EXT_REC_MAX];             //!< Version record
    }TVerExtInf;

    //! Version extended software version info
    typedef struct
    {
        TVerChapCom tVerChapCom;                       //!< Common version info
        TChar       achAppHydSwNo[VERINFO_STR_16];     //!< Software number
        TVerAppSwNo tAppCusSwNo;                       //!< Customer software number
        TUint32     u32SapArtCode;                     //!< Sap art code
        TVerChapFra tAppFra;                           //!< App frame
    }TVerExtSoftVersion;

    extern const TUint32      g_cu32VersionKeyNo;      //!< @generate [changes are forbidden] the autoCode key

    extern TVerInf            gVer_tInf;               //!< @globvar  [changes are forbidden] created by the PDT [version information]

    extern const TVerExtInf   gVerExt_ctInf;           //!< @globvar  [changes are forbidden] created by the PDT [version extended information]

    extern TVerExtSoftVersion g_tVerExtSoftVersion;    //!< @globvar  [changes are forbidden] extended software versions info

    extern TUint32            g_u32ExtAppErrFileCrc;   //!< @globvar  [changes are forbidden] extended application Err-File crc (Second App)

    extern TUint32            g_u32ExtAppIomFileCrc;   //!< @globvar  [changes are forbidden] extended application IOM-File crc (Second App)

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the version information field (pointer of gVer_tInf)
    //! @return     ptCoreVerInfo  - With the first vCoreMain() call is the pointer valid. [In the vAppFixInit() the function return NULL )
    //--------------------------------------------------------------------------------------------------
    extern TVerInf *ptCoreVerInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the application version in the information field
    //! @param[in]  ptAppVersion   - Application software version information
    //! @return     R_OKAY
    //! @return     R_NOT_INITIALIZED
    //! @return     R_NULL_POINTER
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreVersSetAppInfo( TVerChapCom *ptAppVersion );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the application version in the information field with more details
    //! @param[in]  pchAppHydSwNo     - Hydac application software part numbers
    //! @param[in]  ptAppCusSwNo      - Customer application software numbers
    //! @param[in]  u32SapArtCodeApp  - SAP article code for: Application
    //! @return     R_OKAY
    //! @return     R_NOT_INITIALIZED
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreVersSetAppInfoExtended( TChar const *pchAppHydSwNo, TVerAppSwNo *ptAppCusSwNo, TUint32 u32SapArtCodeApp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the second (extended) application version in the information field
    //! @note       Parameter value is soft reset stable
    //! @param[in]  ptAppVersion      - Application software version information [must -> R_NULL_POINTER]
    //! @return     R_OKAY
    //! @return     R_NULL_POINTER
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreExtVersSetAppInfo( TVerChapCom *ptAppVersion );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the  second (extended) application version in the information field with more details
    //! @note       Parameter value is soft reset stable
    //! @param[in]  pchAppHydSwNo     - Hydac application software part numbers [NULL Pointer save]
    //! @param[in]  ptAppCusSwNo      - Customer application software numbers   [NULL Pointer save]
    //! @param[in]  u32SapArtCodeApp  - SAP article code for: Application
    //! @return     R_OKAY
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreExtVersSetAppInfoExtended( TChar const *pchAppHydSwNo, TVerAppSwNo *ptAppCusSwNo, TUint32 u32SapArtCodeApp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the second (extended) application frame field
    //! @note       Parameter value is soft reset stable
    //! @param[in]  ptAppFram      - Application software version information [must -> R_NULL_POINTER]
    //! @return     R_OKAY
    //! @return     R_NULL_POINTER
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreExtVersSetFram( TVerChapFra *ptAppFram );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the HCP BIOS version information
    //! @return     Version pointer
    //--------------------------------------------------------------------------------------------------
    extern const TVerChapNum* cptCoreGetHcpBiosVersionInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the general block api interface version information
    //! @note       If the data of the following files changes, the version number will be changed
    //!             ItfCore.h, ItfCoreBoard.h, ItfCoreDb.h, ItfCoreLib.h, ItfCorePin.h, ItfCoreVer.h
    //!             ItfBasConv.h, ItfBasUtility.h, ItfBasEleErr.h, ItfBasEleTimer.h, ItfBasMath.h,
    //!             ItfBasMath.h, ItfBasOut.h, ItfBasStruc.h
    //! @return     Version pointer
    //--------------------------------------------------------------------------------------------------
    extern const TVerChapNum* cptCoreGetBloApiVersionInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the block registry interface version information
    //! @return     Version pointer
    //--------------------------------------------------------------------------------------------------
    extern const TVerChapNum* cptCoreGetBloItfVersionInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the signal registry interface version information
    //! @return     Version pointer
    //--------------------------------------------------------------------------------------------------
    extern const TVerChapNum* cptCoreGetSigItfVersionInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the protocol interface version information
    //! @return     Version pointer
    //--------------------------------------------------------------------------------------------------
    extern const TVerChapNum* cptCoreGetPtcItfVersionInfo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if the major and minor number of the core version is equal
    //! @param[in]  u8Major     - Major number
    //! @param[in]  u8Minor     - Minor number
    //! @param[in]  cpchObjName - Object name (block name)
    //! @return     TRUE/FALSE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreVerCheckMajorMinor( TUint8 u8Major, TUint8 u8Minor, const TChar *cpchObjName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if the major and minor number match with block interface major and minor number
    //! @param[in]  u8Major     - Major number
    //! @param[in]  u8Minor     - Minor number
    //! @param[in]  cpchObjName - Object name (block name)
    //! @return     TRUE/FALSE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreBloItfCheckMajorMinor( TUint8 u8Major, TUint8 u8Minor, const TChar *cpchObjName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if the major and minor number match with signal interface major and minor number
    //! @param[in]  u8Major     - Major number
    //! @param[in]  u8Minor     - Minor number
    //! @param[in]  cpchObjName - Object name (signal name)
    //! @return     TRUE/FALSE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreSigItfCheckMajorMinor( TUint8 u8Major, TUint8 u8Minor, const TChar *cpchObjName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check if the major and minor number match with protocol interface major and minor number
    //! @param[in]  u8Major     - Major number
    //! @param[in]  u8Minor     - Minor number
    //! @param[in]  cpchObjName - Object name (protocol name)
    //! @return     TRUE/FALSE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCorePtcItfCheckMajorMinor( TUint8 u8Major, TUint8 u8Minor, const TChar *cpchObjName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Check the TVerChapNum if the major and minor number are equal with the ptChapNum pointer
    //! @param[in]  cptChapCom  - Chapter common version
    //! @param[in]  u8Major     - Major number
    //! @param[in]  u8Minor     - Minor number
    //! @param[in]  cpchObjName - Object name (signal- or block name)
    //! @param[in]  cpchSigName - Signal name
    //! @return     TRUE/FALSE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCoreSigCheckMajorMinor( const TVerChapCom* cptChapCom, TUint8 u8Major, TUint8 u8Minor, const TChar *cpchObjName, const TChar *cpchSigName );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Found Version Record via Communication ID
    //! @param[in]  u16ComId     - Communication ID
    //! @param[out] pu8Rec       - Record position
    //! @param[out] pu16AccCode  - Access Code
    //! @retval     R_OKAY         - ok
    //! @retval     R_RANGE        - Don't find that COM-ID
    //! @retval     R_NULL_POINTER - ok
    //! @retval     R_PHASE        - call to early
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreGetVersionRecViaComId( TUint16 u16ComId, TUint8 *pu8Rec, TUint16 *pu16AccCode );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set vehicle code
    //!             Call in phase >= MAIN_APP_INIT to overwrite version extended setting
    //! @param[in]  pchVehicleCode  -   vehicle code string
    //! @retval     R_OKAY              - ok
    //! @retval     R_NOT_INITIALIZED   - version information struct not initialized
    //! @retval     R_PARAMETER         - invalid parameter
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreSetVehicleCode( TChar* pchVehicleCode );

#endif
