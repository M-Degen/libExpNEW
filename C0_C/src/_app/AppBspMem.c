//**************************************************************************************************
/*!
@file       AppBspMem.c
@brief      Bsp and Memory setting
@see        open
@created    25.04.2018  HYDAC/NJP
*/
//**************************************************************************************************
#include <autoconfig.h>
#include <ItfCore.h>
#include <ItfBasOut.h>
#include <ItfAppCode.h>

#if defined(COMPILER_SWITCH_TAR_HW) && !defined(COMPILER_SWITCH_OEM_HY) && !defined(COMPILER_SWITCH_OEM_UNJO) && !defined(COMPILER_SWITCH_PLATFORM_TTC2XXX)
  #ifndef LINT_SWITCH_IGNORE

#ifndef COMPILER_SWITCH_PLATFORM_TTC2XXX
    #include <APDB.h>
#endif

    // to define the software version in three levels major.minor.patch. This version can read from ttc-downloader
    #define SW_VERSION_MAJOR 1                   //  8-bit
    #define SW_VERSION_MINOR 0                   //  8-bit
    #define SW_VERSION_PATCH 0                   // 16-bit

    // to define the node-number and baud-rate used by the device
    #define NODE_NR         1                    //  8-bit
    #define CAN_BAUDRATE  250                    // 16-bit

    // The values for these definitions have to be requested from TTControl. Do not use the predefined values!
    #define APDB_MANUF_ID  ((ubyte1) 0x00)   //  8-bit
    #define APDB_APP_ID    ((ubyte1) 0x00)   //  8-bit

    // Debugging switch
    #ifdef COMPILER_SWITCH_DEBUG_ON
        #define DEBUG_KEY 0xC0FFEE           // Prepare for the Lauterbach-Debugging (Toggle K30, Reset and Run)
    #else
        #define DEBUG_KEY 0                  // Lock for the Lauterbach-Debugging (For a Release)
    #endif

    #define QUICK_SWITCH_AUTOMATIC_DATE
       #ifdef QUICK_SWITCH_AUTOMATIC_DATE
        #ifndef COMPILER_SWITCH_PLATFORM_TTC2XXX
           #define CORE_FLASH_DATE_YEAR    RTS_TTC_FLASH_DATE_YEAR
           #define CORE_FLASH_DATE_MONTH   RTS_TTC_FLASH_DATE_MONTH
           #define CORE_FLASH_DATE_DAY     RTS_TTC_FLASH_DATE_DAY
           #define CORE_FLASH_DATE_HOUR    RTS_TTC_FLASH_DATE_HOUR
           #define CORE_FLASH_DATE_MINUTE  RTS_TTC_FLASH_DATE_MINUTE
       #else
           #define CORE_FLASH_DATE_YEAR    _TTC_BUILD_DATE_YEAR_
           #define CORE_FLASH_DATE_MONTH   _TTC_BUILD_DATE_MONTH_
           #define CORE_FLASH_DATE_DAY     _TTC_BUILD_DATE_DAY_
           #define CORE_FLASH_DATE_HOUR    _TTC_BUILD_DATE_HOUR_
           #define CORE_FLASH_DATE_MINUTE  _TTC_BUILD_DATE_MINUTE_
        #endif
       #else
           #define CORE_FLASH_DATE_YEAR    2016
           #define CORE_FLASH_DATE_MONTH   6
           #define CORE_FLASH_DATE_DAY     30
           #define CORE_FLASH_DATE_HOUR    14
           #define CORE_FLASH_DATE_MINUTE  30
       #endif

     #ifdef COMPILER_SWITCH_FAM_TTC3X
     APDB appl_db =
     {         APDB_VERSION,         // ubyte4 versionAPDB
             {0},                    // BL_T_DATE flashDate
                                     // BL_T_DATE buildDate
             { (ubyte4) (((( (ubyte4) CORE_FLASH_DATE_YEAR)   & 0x0FFF) <<  0)  |
                          ((((ubyte4) CORE_FLASH_DATE_MONTH)  & 0x000F) << 12)  |
                          ((((ubyte4) CORE_FLASH_DATE_DAY)    & 0x001F) << 16)  |
                          ((((ubyte4) CORE_FLASH_DATE_HOUR)   & 0x001F) << 21)  |
                          ((((ubyte4) CORE_FLASH_DATE_MINUTE) & 0x003F) << 26)) },
             0,                       // ubyte4 nodeType
             0,                       // ubyte4 startAddress
             0,                       // ubyte4 codeSize
             0,                       // ubyte4 legacyAppCRC
             0,                       // ubyte4 appCRC
             NODE_NR,                 // ubyte1 nodeNr
             0,                       // ubyte4 CRCInit
             APDB_FLAGS_ABRD_ENABLE,  // ubyte4 flags
             0,                       // ubyte4 hook1
             0,                       // ubyte4 hook2
             0,                       // ubyte4 hook3
             APPL_START,              // ubyte4 mainAddress
             {0, 1},                  // BL_T_CAN_ID canDownloadID
             {0, 2},                  // BL_T_CAN_ID canUploadID
             0,                       // ubyte4 legacyHeaderCRC
             { (ubyte4) (((ubyte4) ((ubyte1) (SW_VERSION_MAJOR & 0x00FF)) << 24) |
                         ((ubyte4) ((ubyte1) (SW_VERSION_MINOR & 0x00FF)) << 16) |
                         ((ubyte4) ((ubyte2) (SW_VERSION_PATCH & 0xFFFF))))  },
             CAN_BAUDRATE,           // ubyte2 canBaudrate
             0,                      // ubyte1 canChannel
             0,                      // ubyte4 password
             0,                      // ubyte4 magicSeed
             { 10, 120,  30, 200},   // ubyte1 targetIPaddress[4]
             {255, 255,   0,   0},   // ubyte1 sub net mask[4]
             {239,   0,   0,   1},   // ubyte1 dlMulticastIP[4]
             0,                      // ubyte4 debugKey;
             3,                      // timeout value for ABRD in calm mode. [seconds]
             0xC1,                   // ubyte1 manufacturerID
             0xA0,                   // ubyte1 applicationID
             {0},                    // ubyte1[2] reserved for future use
             0                       // ubyte4 headerCRC
     };
     #endif

     #ifdef COMPILER_SWITCH_FAM_TTC5X
     APDB appl_db =
     {
           APDB_VERSION,            // ubyte4 versionAPDB
           {0},                     // BL_T_DATE flashDate
                                    // BL_T_DATE buildDate
           { (ubyte4) ((((  (ubyte4) CORE_FLASH_DATE_YEAR)   & 0x0FFF) <<  0)  |
                         ((((ubyte4) CORE_FLASH_DATE_MONTH)  & 0x000F) << 12)  |
                         ((((ubyte4) CORE_FLASH_DATE_DAY)    & 0x001F) << 16)  |
                         ((((ubyte4) CORE_FLASH_DATE_HOUR)   & 0x001F) << 21)  |
                         ((((ubyte4) CORE_FLASH_DATE_MINUTE) & 0x003F) << 26)) },
           0,                      // ubyte4 nodeType
           0,                      // ubyte4 startAddress
           0,                      // ubyte4 codeSize
           0,                      // ubyte4 legacyAppCRC
           0,                      // ubyte4 appCRC
           NODE_NR,                // ubyte1 nodeNr
           0,                      // ubyte4 CRCInit
           0,                      // ubyte4 flags
           0,                      // ubyte4 hook1
           0,                      // ubyte4 hook2
           0,                      // ubyte4 hook3
           APPL_START,             // ubyte4 mainAddress
           {0, 1},                 // BL_T_CAN_ID canDownloadID
           {0, 2},                 // BL_T_CAN_ID canUploadID
           0,                      // ubyte4 legacyHeaderCRC
                                   // ubyte4 version; (8bit.8bit.16bit)
           { (ubyte4) (((ubyte4) ((ubyte1) (SW_VERSION_MAJOR & 0x00FF)) << 24) |
                       ((ubyte4) ((ubyte1) (SW_VERSION_MINOR & 0x00FF)) << 16) |
                       ((ubyte4) ((ubyte2) (SW_VERSION_PATCH & 0xFFFF))))  },
           CAN_BAUDRATE,           // ubyte2 canBaudrate
           0,                      // ubyte1 canChannel
           0,                      // ubyte4 password
           0,                      // ubyte4 magicSeed
           {  0,   0,   0,   0},   // ubyte1 targetIPaddress[4]
           {  0,   0,   0,   0},   // ubyte1 sub net mask[4]
           {  0,   0,   0,   0},   // ubyte1 dlMulticastIP[4]
           DEBUG_KEY,                      // ubyte4 debugKey;
           3,                      // timeout value for ABRD in calm mode. [seconds]
           APDB_MANUF_ID,          // ubyte1 manufacturerID
           APDB_APP_ID,            // ubyte1 application ID
           { 0 },                  // reserved for future use (should be 0)
           0                       // ubyte4 headerCRC
     };
     #endif

     #ifdef COMPILER_SWITCH_FAM_TTC7X
     APDB appl_db =
     {
          APDB_VERSION,            // ubyte4 versionAPDB
          {0},                     // BL_T_DATE flashDate
                                   // BL_T_DATE buildDate
          { (ubyte4) ((((  (ubyte4) CORE_FLASH_DATE_YEAR)   & 0x0FFF) <<  0)  |
                        ((((ubyte4) CORE_FLASH_DATE_MONTH)  & 0x000F) << 12)  |
                        ((((ubyte4) CORE_FLASH_DATE_DAY)    & 0x001F) << 16)  |
                        ((((ubyte4) CORE_FLASH_DATE_HOUR)   & 0x001F) << 21)  |
                        ((((ubyte4) CORE_FLASH_DATE_MINUTE) & 0x003F) << 26)) },
          0,                       // ubyte4 nodeType
          0,                       // ubyte4 startAddress
          0,                       // ubyte4 codeSize
          0,                       // ubyte4 legacyAppCRC
          0,                       // ubyte4 appCRC
          NODE_NR,                 // ubyte1 nodeNr
          0,                       // ubyte4 CRCInit
          APDB_FLAGS_ABRD_ENABLE,  // ubyte4 flags
          0,                       // ubyte4 hook1
          0,                       // ubyte4 hook2
          0,                       // ubyte4 hook3
          APPL_START,              // ubyte4 mainAddress
          {0, 1},                  // BL_T_CAN_ID canDownloadID
          {0, 2},                  // BL_T_CAN_ID canUploadID
          0,                       // ubyte4 legacyHeaderCRC
                                   // ubyte4 version; (8bit.8bit.16bit)
          { (ubyte4) (((ubyte4) ((ubyte1) (SW_VERSION_MAJOR & 0x00FF)) << 24) |
                      ((ubyte4) ((ubyte1) (SW_VERSION_MINOR & 0x00FF)) << 16) |
                      ((ubyte4) ((ubyte2) (SW_VERSION_PATCH & 0xFFFF))))  },
          CAN_BAUDRATE,            // ubyte2 canBaudrate
          0,                       // ubyte1 canChannel
          0,                       // ubyte4 password
          0,                       // ubyte4 magicSeed
          {  0,   0,   0,   0},    // ubyte1 targetIPaddress[4]
          {  0,   0,   0,   0},    // ubyte1 sub net mask[4]
          {  0,   0,   0,   0},    // ubyte1 dlMulticastIP[4]
          0,                       // ubyte4 debugKey;
          3,                       // timeout value for ABRD in calm mode. [seconds]
          APDB_MANUF_ID,           // ubyte1 manufacturerID
          APDB_APP_ID,             // ubyte1 application ID
          { 0 },                   // reserved for future use (should be 0)
          0                        // ubyte4 headerCRC
     };
     #endif

     #ifdef COMPILER_SWITCH_FAM_TTC5XX
     #pragma SET_DATA_SECTION (".APDB_SEC")
     #define                appl_db Apdb_t   // need the naming for the IO_DOWNLOADER -> flashing with ETH
     volatile const BL_APDB appl_db =
     {
         APDB_VERSION,            // ubyte4 versionAPDB
         { 0 },                   // BL_T_DATE flashDate
         {
             (ubyte4) (
                 ((((ubyte4) RTS_TTC_FLASH_DATE_YEAR) & 0x0FFF) <<  0) |
                 ((((ubyte4) RTS_TTC_FLASH_DATE_MONTH)  & 0x0F) << 12) |
                 ((((ubyte4) RTS_TTC_FLASH_DATE_DAY)    & 0x1F) << 16) |
                 ((((ubyte4) RTS_TTC_FLASH_DATE_HOUR)   & 0x1F) << 21) |
                 ((((ubyte4) RTS_TTC_FLASH_DATE_MINUTE) & 0x3F) << 26)
             )
         },                       // BL_T_DATE buildDate
         0,                       // ubyte4 nodeType
         0,                       // ubyte4 CRCStartAddress
         0,                       // ubyte4 codeSize
         0,                       // ubyte4 LegacyApplicationCRC
         0,                       // ubyte4 ApplicationCRC
         NODE_NR,                 // ubyte4 NodeNumber
         0,                       // ubyte4 CRCSeed
         APDB_FLAGS_ABRD_ENABLE,  // ubyte4 Flags
         0,                       // ubyte4 Hook1
         0,                       // ubyte4 Hook2
         0,                       // ubyte4 Hook3
         APPL_START,              // ubyte4 MainAddress
         { 0, 1 },                // BL_T_CAN_ID CANDownloadID
         { 0, 2 },                // BL_T_CAN_ID CANUploadID
         0,                       // ubyte4 LegacyHeaderCRC
                                  // ubyte4 version; (8bit.8bit.16bit)
        { (ubyte4) (((ubyte4) ((ubyte1) (SW_VERSION_MAJOR & 0x00FF)) << 24) |
                    ((ubyte4) ((ubyte1) (SW_VERSION_MINOR & 0x00FF)) << 16) |
                    ((ubyte4) ((ubyte2) (SW_VERSION_PATCH & 0xFFFF))))  },
         CAN_BAUDRATE,            // ubyte4 CANBaudrate
         0,                       // ubyte4 CANChannel
         0,                       // ubyte4 Password
         0,                       // ubyte4 MagicSeed
         { 10, 120,  30, 200},    // ubyte1 TargetIPAddress[4]
         {255, 255,   0,   0},    // ubyte1 SubnetMask[4]
         {239,   0,   0,   1},    // ubyte1 DLMulticastIPAddress[4]
         DEBUG_KEY,               // ubyte4 DebugKey
         0,                       // ubyte4 ABRDTimeout
         APDB_MANUF_ID,           // ubyte1 ManufacturerID
         APDB_APP_ID,             // ubyte1 ApplicationID
         {0},                     // ubyte2 Reserved
         0                        // ubyte4 HeaderCRC
     };
     #pragma SET_DATA_SECTION()
     #endif

    #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX

    #include <Apdb.h>
    #include <BspCrt0.h>

    /***********************************************************************************************************************
     * Data
     **********************************************************************************************************************/
    #pragma section ".rodata.a4.app.apdb" a 4
    const ApdbType g_cAppApdb =
        {
        .ApdbVersion          = 0UL,
        .FlashDate            = 0UL,
        .BuildDate            =
                     (uint32) (((((uint32) CORE_FLASH_DATE_YEAR) & 0x0FFF) <<  0) |
                               ((((uint32) CORE_FLASH_DATE_MONTH)  & 0x0F) << 12) |
                               ((((uint32) CORE_FLASH_DATE_DAY)    & 0x1F) << 16) |
                               ((((uint32) CORE_FLASH_DATE_HOUR)   & 0x1F) << 21) |
                               ((((uint32) CORE_FLASH_DATE_MINUTE) & 0x3F) << 26)),
        .NodeType             = 0UL,
        .CrcStartAddress      = 0UL,
        .CodeSize             = 0UL,
        .LegacyApplicationCrc = 0UL,
        .ApplicationCrc       = 0UL,
        .NodeNumber           = NODE_NR,
        .CrcSeed              = 0UL,
        .Flags                = 0UL,
        .Hook1                = 0UL,
        .Hook2                = 0UL,
        .Hook3                = 0UL,
        .MainAddress          = (uint32) BspCrt0Reset,
        .CanDownloadId        = {0U, 1U},
        .CanUploadId          = {0U, 2U},
        .LegacyHeaderCrc      = 0UL,
        .ApplicationVersion   = 0UL,
        .CanBaudrate          = CAN_BAUDRATE,
        .CanChannel           = 0UL,
        .Password             = 0UL,
        .MagicSeed            = 0UL,
        .TargetIpAddress      = {0U, 0U, 0U, 0U},
        .SubnetMask           = {0U, 0U, 0U, 0U},
        .DlMulticastIpAddress = {0U, 0U, 0U, 0U},
        .DebugKey             = 0UL,
        .AbrdTimeout          = 0UL,
        .ManufacturerId       = 0U,
        .ApplicationId        = 0U,
        .Reserved             = 0U,
        .HeaderCrc            = 0UL
    };
    #pragma section
    #endif

     TVoid vGetRtsFlashDate (TUint16 *pu16Year, TUint8 *pu8Month, TUint8 *pu8Day, TUint8 *pu8Hour, TUint8 *pu8Minute)
     {
         #ifdef COMPILER_SWITCH_FAM_TTC3X
          *pu16Year  = ((ubyte2)            appl_db.FlashDate.date) & 0x0FFF;
          *pu8Month  = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 12)) & 0x0F;
          *pu8Day    = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 16)) & 0x1F;
          *pu8Hour   = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 21)) & 0x1F;
          *pu8Minute = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 26)) & 0x3F;
         #endif
         #ifdef COMPILER_SWITCH_FAM_TTC5X
          *pu16Year  = ((ubyte2)            appl_db.FlashDate.date) & 0x0FFF;
          *pu8Month  = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 12)) & 0x0F;
          *pu8Day    = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 16)) & 0x1F;
          *pu8Hour   = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 21)) & 0x1F;
          *pu8Minute = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 26)) & 0x3F;
         #endif
         #ifdef COMPILER_SWITCH_FAM_TTC7X
          *pu16Year  = ((ubyte2)            appl_db.FlashDate.date) & 0x0FFF;
          *pu8Month  = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 12)) & 0x0F;
          *pu8Day    = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 16)) & 0x1F;
          *pu8Hour   = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 21)) & 0x1F;
          *pu8Minute = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 26)) & 0x3F;
         #endif
         #ifdef COMPILER_SWITCH_FAM_TTC5XX
         *pu16Year  = ((ubyte2)            appl_db.FlashDate.date) & 0x0FFF;
         *pu8Month  = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 12)) & 0x0F;
         *pu8Day    = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 16)) & 0x1F;
         *pu8Hour   = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 21)) & 0x1F;
         *pu8Minute = ((ubyte1) (((ubyte4) appl_db.FlashDate.date) >> 26)) & 0x3F;
         #endif
         #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX
         *pu16Year  = ((uint16)           g_cAppApdb.FlashDate) & 0x0FFF;
         *pu8Month  = ((uint8) (((uint32) g_cAppApdb.FlashDate) >> 12)) & 0x0F;
         *pu8Day    = ((uint8) (((uint32) g_cAppApdb.FlashDate) >> 16)) & 0x1F;
         *pu8Hour   = ((uint8) (((uint32) g_cAppApdb.FlashDate) >> 21)) & 0x1F;
         *pu8Minute = ((uint8) (((uint32) g_cAppApdb.FlashDate) >> 26)) & 0x3F;
         #endif
     }
  #else  // else: !LINT_SWITCH_IGNORE

    TVoid vGetRtsFlashDate(TUint16 *pu16Year, TUint8 *pu8Month, TUint8 *pu8Day, TUint8 *pu8Hour, TUint8 *pu8Minute)
    {
        AVOID_WARRNING(*pu16Year); AVOID_WARRNING(*pu8Month); AVOID_WARRNING(*pu8Day);
        AVOID_WARRNING(*pu8Hour);  AVOID_WARRNING(*pu8Minute);
    }

  #endif  // close: LINT_SWITCH_IGNORE
#endif

#ifdef COMPILER_SWITCH_ENV_CEN

    //! The MISRA C rule discourages the use of malloc for dynamic memory allocation.
    //! To get memory for objects (blocks/signals) in a nice way you can use the pvCoreGetMemory(...) core function.
    //! To give this function more memory you can change the following MEMORY_SIZE define for the needed controller.
    //! The core function u32CoreGetMemoryTotalSize() give the total size in byte of the object memory back and the
    //! function u32CoreGetMemoryUsedSpace() give you the used memory in byte back
    #define MEM_KBYTE ( (TUint32)1024 )
    #ifdef COMPILER_SWITCH_FAM_TTC3X
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32) 22 )        // complete: 82kB (intern)  => 20kB
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC5X
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32) 28 )        // complete: TTC50/60 82kB(intern) => 28kB                                                         // complete: TTC90    58kB(intern) => 28kB, 512kB(extern)
    #endif                                                      // complete: TTC90    58kB(intern) => 28kB, 512kB(extern)
    #ifdef COMPILER_SWITCH_FAM_TTC7X
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32) 32 )        // complete: 138kB(intern) => 32kB
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC5XX
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32)130 )        // complete: 256Kb(intern) => 130kB, 2MB(extern)
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC23XX
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32)80 )        // complete: 240Kb(intern) => value see left
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC20XX
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32)40 )        // complete: 192Kb(intern) => value see left
    #endif
    #ifdef COMPILER_SWITCH_OEM_HY
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32) 22 )        // complete: 82kB (intern)  => 20kB
    #endif
    #ifdef COMPILER_SWITCH_OEM_UNJO
        #define MEMORY_SIZE ( MEM_KBYTE * (TUint32) 22 )        // complete: 82kB (intern)  => 20kB
    #endif

    //! Scaling the block init loop steps to optimizing the run up phase
    #ifdef COMPILER_SWITCH_FAM_TTC3X
        const TBloLoopStep g_ctBloLoopStep = { 10, 10, 10 };    // block step - u8Basic, u8Can, u8Extended
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC5X
        const TBloLoopStep g_ctBloLoopStep = { 10, 10,  5 };    // block step - u8Basic, u8Can, u8Extended
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC7X
        const TBloLoopStep g_ctBloLoopStep = {  4,  5,  2 };    // block step - u8Basic, u8Can, u8Extended
    #endif
    #ifdef COMPILER_SWITCH_FAM_TTC5XX
        const TBloLoopStep g_ctBloLoopStep = { 10, 10,  6 };    // block step - u8Basic, u8Can, u8Extended
    #endif
    #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX
        const TBloLoopStep g_ctBloLoopStep = { 10, 10,  6 };    // block step - u8Basic, u8Can, u8Extended
    #endif
    #ifdef COMPILER_SWITCH_OEM_HY
        const TBloLoopStep g_ctBloLoopStep = { 10, 10,  6 };    // block step - u8Basic, u8Can, u8Extended
    #endif
    #ifdef COMPILER_SWITCH_OEM_UNJO
        const TBloLoopStep g_ctBloLoopStep = { 10, 10, 6 };    // block step - u8Basic, u8Can, u8Extended
    #endif

    const TUint32 g_cu32ObjMemMax=MEMORY_SIZE;
    TUint8 g_au8ObjData[MEMORY_SIZE];

#endif
