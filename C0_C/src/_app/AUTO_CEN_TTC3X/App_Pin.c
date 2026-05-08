//**************************************************************************************************
//! @crc        1515573685
//! @file       App_Pin.c
//! @brief      Generate by: HYDAC Controller Project - Code Builder Tool Chain
//! @ecu        TTC32S
//! @dll        1.4.0 (Build: 021)
//! @dll itf    1.7.0
//! @build      2025-03-12 15:24:11
//! @Match      07-08-00-00
//! @PDT        2.12.91.55
//! @PdtProjVer 0.0.0
//! @created    2026-05-08 10:34:48   HYDAC/HCP-CC
//**************************************************************************************************

#include <ItfCoreBoard.h>

const TAppPin gPin_catApp[PIN_MAX] = 
{
    // Idx  Pin    Map-Opt       Pin Type        Safety        Res Pos          Pin-Thr Low       Pin-Thr Hig       Pin-PWM FB-Idx     Pin-Pwm Freq
    {   0,    0,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,                0,                0,                0,                0 },
    {   1,  104,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   2,   84,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   3,   54,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   4,   44,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   5,   34,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   6,   24,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   7,   14,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   8,   13,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_CFG_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {   9,   74,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {  10,   64,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {  11,   53,  PIN_FIX,      PINTYP_NA,      CIO_NA,        PINRES_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {  12,   43,  PIN_FIX,      PINTYP_NA,      CIO_NA,        PINRES_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {  13,   33,  PIN_FIX,      PINTYP_NA,      CIO_NA,        PINRES_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {  14,   23,  PIN_FIX,      PINTYP_NA,      CIO_NA,        PINRES_NA,      PINTHR_DFLT,      PINTHR_DFLT,     PINSUPPLY_NA,        PINRSL_NA },
    {  15,   81,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,           CFG_NA,           CFG_NA,           CFG_NA,      PINPWM_DFLT },
    {  16,   71,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,           CFG_NA,           CFG_NA,           CFG_NA,      PINPWM_DFLT },
    {  17,   61,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,           CFG_NA,           CFG_NA,           CFG_NA,      PINPWM_DFLT },
    {  18,   51,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,           CFG_NA,           CFG_NA,           CFG_NA,      PINPWM_DFLT },
    {  19,   41,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,           CFG_NA,           CFG_NA,           CFG_NA,      PINPWM_DFLT },
    {  20,   31,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,           CFG_NA,           CFG_NA,           CFG_NA,      PINPWM_DFLT },
    {  21,  111,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,      PINPWM_DFLT },
    {  22,  101,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,      PINPWM_DFLT },
    {  23,   21,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,        PINRSL_NA },
    {  24,   11,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLUP,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,        PINRSL_NA },
    {  25,  112,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,             5000 },
    {  26,  102,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,             5000 },
    {  27,   82,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,             5000 },
    {  28,   72,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,             5000 },
    {  29,   62,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,             5000 },
    {  30,   52,  PIN_FIX,      PINTYP_NA,      CIO_NA,    PINRES_PULLDO,      PINTHR_DFLT,      PINTHR_DFLT,           CFG_NA,             5000 }
};

#ifdef COMPILER_SWITCH_TAR_PC

    TAppPinDftVal gPin_tSim =
    {
        {
                  0,                                        //!< Idx: 0
                  0,                                        //!< Idx: 1
                  0,                                        //!< Idx: 2
                  0,                                        //!< Idx: 3
                  0,                                        //!< Idx: 4
                  0,                                        //!< Idx: 5
                  0,                                        //!< Idx: 6
                  0,                                        //!< Idx: 7
                  0,                                        //!< Idx: 8
                  0,                                        //!< Idx: 9
                  0,                                        //!< Idx: 10
                  0,                                        //!< Idx: 11
                  0,                                        //!< Idx: 12
                  0,                                        //!< Idx: 13
                  0,                                        //!< Idx: 14
                  0,                                        //!< Idx: 15
                  0,                                        //!< Idx: 16
                  0,                                        //!< Idx: 17
                  0,                                        //!< Idx: 18
                  0,                                        //!< Idx: 19
                  0,                                        //!< Idx: 20
                  0,                                        //!< Idx: 21
                  0,                                        //!< Idx: 22
                  0,                                        //!< Idx: 23
                  0,                                        //!< Idx: 24
                  0,                                        //!< Idx: 25
                  0,                                        //!< Idx: 26
                  0,                                        //!< Idx: 27
                  0,                                        //!< Idx: 28
                  0,                                        //!< Idx: 29
                  0,                                        //!< Idx: 30
              12000,                                        //!< Idx: 31
                  1,                                        //!< Idx: 32
                300,                                        //!< Idx: 33
               5000,                                        //!< Idx: 34
               5000                                         //!< Idx: 35
        }
    };

    const TPinInfo gPinInfo_ctAppPin =
    {
        gPin_catApp,
        NULL,
        &gPin_tSim
    };

#else

    const TPinInfo gPinInfo_ctAppPin =
    {
        gPin_catApp,
        NULL,
        NULL
    };

#endif // COMPILER_SWITCH_TAR_PC

