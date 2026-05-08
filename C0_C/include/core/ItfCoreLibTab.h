//**************************************************************************************************
/*!
@file       ItfCoreLibTab.h
@brief      Interface between the LIBARY and the AUTO-CODE
@date       01.02.2011
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREBLOTAB__
    #define __ITFCOREBLOTAB__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>

// DEFINES & ENUMS  ================================================================================

    #define CORE_OBJ_OFFSET 200             //!< Core Offset Value


    //! Standard library Enum for struct, element, basic-signals and blocks - *** NOT CHANGEABLE ***
    typedef enum
    {
        // Internal structures, block and element objects
        STD_STU_HCP_INP = CORE_OBJ_OFFSET,  //!< {00} 200 - HCP input vector         - fix
        STD_STU_HCP_OUT,                    //!< {01} 201 - HCP output vector        - fix
        STD_STU_ECU,                        //!< {02} 202 - Ecu information          - fix
        STD_BLO_FLA,                        //!< {03} 203 - Factory setting          - optional
        STD_STU_PIN,                        //!< {04} 204 - Pin information          - fix
        STD_STU_VER,                        //!< {05} 205 - Version information      - fix
        STD_STU_DB,                         //!< {06} 207 - Data base                - optional
        STD_STU_CSR,                        //!< {07} 208 - Can signal record        - optional
        STD_STU_VER_EXT,                    //!< {08} 206 - Version extended         - optional
        STD_STU_EXC,                        //!< {09} 209 - Exclude list             - optional
        STD_STU_CREC,                       //!< {10} 210 - Can record table         - optional
        STD_ELE_ERR,                        //!< {11} 211 - Element error            - optional (need in the STRUCT_DB, BLOCK_FLA and BLOCK_SIL )
        STD_ELE_TIME,                       //!< {12} 212 - Element time             - optional
        STD_BLO_SIL,                        //!< {13} 213 - SIL faults               - optional
        STD_BLO_ERR,                        //!< {14} 214 - Error block              - optional
        STD_BLO_ADC,                        //!< {15} 215 - Analog digital block     - optional
        STD_BLO_DAC,                        //!< {16} 216 - Digital analog block     - optional
        STD_BLO_CBUS,                       //!< {17} 217 - Can bus                  - optional
        STD_BLO_CBUF,                       //!< {18} 218 - Can buffer               - optional
        STD_BLO_CSND,                       //!< {19} 219 - Can send                 - optional
        STD_BLO_CRCV,                       //!< {20} 220 - Can receive              - optional
        STD_BLO_LBUS,                       //!< {21} 221 - Lin bus                  - optional
        STD_STU_DB_SEC_APP,                 //!< {22} 222 - Data base - 2App         - optional
        STD_STU_CREC_SEC_APP,               //!< {23} 223 - Can record table - 2App  - optional
        STD_STU_PIN_SEC_APP,                //!< {24} 224 - Pining - 2App            - optional
        #ifdef COMPILER_SWITCH_ENV_CDS_23
        STD_BAS_PID,                        //!< {25} 225 - Pid                      - optional
        #endif
        STD_LIB_MAX                         //!<          - Maximum limit
    }EStdTyp;

    //! Block table record
    typedef struct
    {
           TUint16 u16Type;                 //!< which block
           TVoid*  pvBloAdr;                //!< Block address
    }TObjTab;

    extern TUint16  g_u16ObjTabMax;         //!< globvar create by the PDT [block counter]
    extern TObjTab  g_atObjTab[];           //!< globvar create by the PDT [block information set]

    extern TUint16 g_u16EnuStdTypMax;       //!< globvar create automatic [install standard]
    extern TUint16 g_u16EnuBloTypMax;       //!< globvar create automatic [install blocks]
    extern TUint16 g_u16EnuSigTypMax;       //!< globvar create automatic [install signals]

    #define BLO_TYPE_2APP_OFFSET   100      //!< Offset for the second app block's
    #define SIG_TYPE_2APP_OFFSET   100      //!< Offset for the second app signal's

    // include must be know the BLO_TYPE_2APP_OFFSET & SIG_TYPE_2APP_OFFSET defines
    #include <Cfg_LibRegistry.h>
    #ifdef COMPILER_SWITCH_ACTIVE_2APP
    #include <2Cfg_LibRegistry.h>
    #endif

#endif
