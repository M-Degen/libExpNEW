//**************************************************************************************************
/*!
@file       appconfig.h
@brief      MATCH Application configuration file
@created    25.05.2019  HYDAC/NJP
*/
//**************************************************************************************************

    #include <autoconfig.h>

    // #define VERIFICATION_TEST                   //!< Only for the validation test necessary

    // #define COMPILER_SWITCH_ACTIVE_2APP         //!< Activate the second application framework

    // #define COMPILER_SWITCH_DEBUG_ON            //!< Activate the JTAC debug interface for the TTC5xx

    #ifdef COMPILER_SWITCH_TAR_PC
    //#define SCRIPT_TEST_FCT                     //!< removes static modifier from "member" objects
    #endif

    //#define __cplusplus
