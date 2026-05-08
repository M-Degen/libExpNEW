//**************************************************************************************************
//! @crc        3441600588
//! @file       Cfg_Ver.c
//! @brief      Generate by: HYDAC Controller Project - Code Builder Tool Chain
//! @ecu        TTC32S
//! @dll        1.4.0 (Build: 021)
//! @dll itf    1.7.0
//! @build      2025-03-12 15:24:11
//! @Pattern    1.2.0
//! @Subpattern ----
//! @Match      07-08-00-00
//! @PDT        2.12.91.55
//! @PdtProjVer 0.0.0
//! @created    2026-05-08 10:34:48   HYDAC/HCP-CC
//**************************************************************************************************

// INCLUDES ========================================================================================
#include <ItfCoreVer.h>

// GLOBAL VARIABLES ================================================================================
//Sofware Module Name: AppPrivate
TVerInf gVer_tInf = 
{
    // Enviroment Information ---------------------------------------------------------------------
    "06-06",                                                //achHistory             - Project History Version  

    // Machine Access Protection ------------------------------------------------------------------
    "HY1234HY",                                             //achVehicleCode         - Vehicle Code 
    
    // Vehicle Identification --------------------------------------------------------------------- 
    "HYDAC Internat.",                                      //achManufacturer        - Vehicle Manufacturer Name / Fahrzeughersteller                     
    "Potsdam",                                              //achManuLocation        - Vehicle Manufacturing Location / Fahrzeug Produktionsstandort      
    "Demo NJP",                                             //achBrand               - Brand Name / Markenname                                            
    "425-01",                                               //achType                - Vehicle Type / Fahrzeugtyp (z.B. 416-01)                           
    "SAP 001",                                              //achVehPartNo           - Vehicle Part Number / SAP Materialnummer Fahrzeuggrupp (SAP)       
    "Demo Machine",                                         //achVehSalesName        - Vehicle Sales Name / Verkaufsbezeichnung (z.B: Zero Emission 803)  
    "0",                                                    //achVehSerNo            - Vehicle Serial Number / Fahrgestellnummer                          
    "08.05.2026",                                           //achVehProdDate         - Production Date / Produktionsdatum                                 
    "10:34:47",                                             //achVehProdTime         - Production Time / Produktionszeit                                  
    "20 km/h",                                              //achVehMaxSpeed         - Vehicle Maximum Speed / Maximale Fahrgeschwindigkeit               
    "Production Code",                                      //achVehProdCode         - Complete Production Code / Vollstaendiger Produktionskode
    "425-01",                                               //achVehProdType         - SAP Product Type Customer / SAP Produkttyp Kunde    
    
    // Application Software ----------------------------------------------------------------------
    {  
        0,                                                  //u8Major                - Major Software Version Number
        0,                                                  //u8Minor                - Minor Software Version Number
        0,                                                  //u8Index                - Software Version Index
        0,                                                  //u16DevStp              - Software Development Step    
        "-",                                                //achDate[10+1]          - Creation Date - eg: '01.01.2011'
        "-"                                                 //achTime[8+1]           - Creation Time - eg: '00:00:00'
    }, 
    "-",                                                    // achAppHydSwNo         - Hydac Application Software Part Numbers / Hydac Applikations-Software Materialnummern
    {
        "-",                                                // achAppSwPartNo Customer SW Part Number/ Kunden Software Materialnummer             
        "-",                                                // achAppSwPartNo Customer SW Version Number/ Kunden Software Versionsnummer          
        "-",                                                // achAppSwPartNo Customer Parameter Part Number/ Kunden Parameter Materialnummer     
        "-"                                                 // achAppSwPartNo Customer Parameter Version Number/ Kunden Parameter Versionsnummer  
    },
    // SAP Information -----------------------------------------------------------------------------
    0,                                                      //u32SapArtCodeApp 
    0,                                                      //u32SapArtCodeCore 
   
   // Detail Software Informations ----------------------------------------------------------------
    {   // FrameSoftware Version Information
        0,                                                  //u8Major                - Major Software Version Number
        0,                                                  //u8Minor                - Minor Software Version Number
        0,                                                  //u8Index                - Software Version Index
        0,                                                  //u8DbParIdx             - Database Parameter Index
        0,                                                  //u8FlaParIdx            - Factory Flash Data Index
        1,                                                  //u16DevStp              - Software Development Step    
        "08.05.2026",                                       //achDate[10+1]          - Creation Date - eg: '01.01.2011'
        "10:34:47"                                          //achTime[8+1]           - Creation Time - eg: '00:00:00'
    },
    {   // Software Hcp-Bios Version Information
        0xFF,                                               //u8Major                - Major Software Version Number
        0xFF,                                               //u8Minor                - Minor Software Version Number
        0xFF,                                               //u8Index                - Software Version Index
        0xFFFF,                                             //u16DevStp              - Software Development Step    
        "-",                                                //achDate[10+1]          - Creation Date - eg: '01.01.2011'
        "-"                                                 //achTime[8+1]           - Creation Time - eg: '00:00:00'
    },
    {   // Software Ecu-Bios/Cds-Rts Version Information 
        0xFF,                                               // u8Major               -  Major Software Version Number
        0xFF,                                               // u8Minor               - Minor Software Version Number
        0xFFFF                                              // u16DevStp             - Software Development Step  
    },
    {   // Software IO-Driver Version Information
        0xFF,                                               // u8Major               - Major Software Version Number
        0xFF,                                               // u8Minor               - Minor Software Version Number
        0xFFFF                                              // u16DevStp             - Software Development Step  
    },
    {  // Software MinmodulVersion Information
        0xFF,                                               // u8Major               - Major Software Version Number
        0xFF,                                               // u8Minor               - Minor Software Version Number
        0xFFFF                                              // u16DevStp             - Software Development Step  
    },
    {  // Compiler Version Information
        "-",                                                //achSupplier[32+1]      - Compiler Supplier
        "-",                                                //achVersion[32+1]       - Compiler Version
        0xFFFF                                              //u16BuildProcNo         - Build Process Number
    },
     // Controller Information  --------------------------------------------------------------------
    "-",                                                    //achEcuType[32+1]       - Controller Type
    "-",                                                    //achEcuVerNo[32+1]      - Controller Version Number 'xx.xx'
    "-",                                                    //achEcuSerNo[32+1]      - Controller Serial Number  'xxxxxxxxxxx'
    
    "",                                                     // achEcuPartNo           Controller Part Number / Materialnummer Steuergeraet (Hydac)
    "HY-TTC 32S - 00 ",                                     // Part Number for Assembly Controller (incl. Application SW) / Materialnummer Baugruppe Steuergeraet (Kunde) 
    "",                                                     // achEcuSapPartNo        Controller Customer Part Number / Kunden-Materialnummer Steuergeraet (SAP)
    "",                                                     // achEcuSapVerNo         Controller Customer Version Number / Kunden-Versionsnummer Steuergeraet (SAP)
    
    {   // Watchdog Hardware Version Information
        0xFF,                                               // u8Major               - Major Software Version Number
        0xFF,                                               // u8Minor               - Minor Software Version Number
        0xFFFF                                              // u16DevStp             - Software Development Step  
    },
    {   // Flash stamp
        0,                                                  //u16Year                - Major Software Version Number
        0,                                                  //u8Month                - Minor Software Version Number
        0,                                                  //u8Day                  - Software Version Index
        0,                                                  //u8Hour                 - Software Development Step    
        0,                                                  //u8Minute               - Software Development Step    
    },
    // Conrtoller HCP-Environment Information ------------------------------------------------------
    {   // Nvmem Storage
        0,                                                  //u32EcuLastRunTime      - Last run time
        0,                                                  //u32EcuOnSwitch         - Count of On/Off switch Cycles
        0,                                                  //u32NvmDbStoreCnt       - Count of nvmem store processe
        0,                                                  //u32NvmMemStoreCnt      - Count of nvmem mem field store cycles counts
        0,                                                  //u32NvmErrStoreCnt      - Count of nvmem errors store cycle counts
        0,                                                  //u8RestartReaInfo       - Reason for the last restart info
        0,                                                  //u8RestartReaDetail     - Reason for the last restart info in detail
    },
    // Hcp-Code-Creater Version + Enviroment -------------------------------------------------------
    "C-Code",                                               //achEnvVer[8]           - Enviroment OS
    "1-4-0",                                                //achExeVer[8]           - Executable Tool Version      
    "1-2-0",                                                //achPatVer[8]           - Pattern Version  
    
    3324990964U,                                            //u32ErrHstFileCrc       - HST Error Definition File Checknumber
    2485879966U,                                            //u32IomHstFileCrc       - HST Pin Definition File Checknumber
    2667250347U,                                            //u32TbcHstFileCrc       - HST Tbc Definition File Checknumber
    
    // Auto Generate Code - FRAME_CRC_STOP
    0,                                                      //u32AutoCodePreCrc //!< Auto Code Crc
    0,                                                      //u32AutCodePostCrc //!< Auto Code Crc
    
    // Check Core-Frame
    {
        7,                                                  //u8Major                - Major Software Version Number
        8,                                                  //u8Minor                - Minor Software Version Number
        VER_DIGIT_DONTCARE_U8,                              //u8Index                - Software Version Index
        VER_DIGIT_DONTCARE_U16                              //u16DevStp              - Software Development Step
    }
};
