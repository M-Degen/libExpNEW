//**************************************************************************************************
/*!
@file           ItfBloSil.h
@brief          Sik block interface
@date           30.07.2012
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCORESIL__
	#define __ITFCORESIL__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfBasEleErr.h>
    #include <ItfBloErr.h>

// DEFINES & ENUMS  ================================================================================

    #define DIAG_NO_FAULT                0xFF      //!< No fault

    #ifdef COMPILER_SWITCH_FAM_TTC3X
    //!  Ecu0_Safety
    enum
    {
        DM_ECU0_INPBOARDNON,                       //!< 0 - Non-fatal input board circuit errors
        DM_ECU0_INPBOARDFAT,                       //!< 1 - Fatal input board circuit errors
        DM_ECU0_INPUTPINS,                         //!< 2 - Input pin related errors
        DM_ECU0_PWMOUT,                            //!< 3 - Pwm Output Error
        DM_ECU0_CORE,                              //!< 4 - Core Error
        DM_ECU0_MEM,                               //!< 5 - Memory Error
        DM_ECU0_WD,                                //!< 6 - Watchdog Error
        DM_ECU0_SSW                                //!< 7 - Safety Switch Error
    };
    //!  Ecu1_Safety
    enum
    {
        DM_ECU1_APP_SAFESTATE,                     //!< 0 - Application control safe state
        DM_ECU1_BOARD_SAFESTATE,                   //!< 1 - Board control safe state
        DM_ECU1_REQ_SAFESTATE,                     //!< 2 - Board control safe state
        DM_ECU1_OTHERS,                            //!< 3 - Other ECU error
        DM_ECU1_UNDEF                              //!< 4 - Undefined ECU BSP error
    };
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC5X
    //!  Ecu0_Safety
    enum
    {
        DM_ECU0_INPBOARDFAT,                       //!< 0 - Fatal input board circuit errors
        DM_ECU0_INPUTPINS,                         //!< 1 - Input pin related errors
        DM_ECU0_PWMOUT,                            //!< 2 - Pwm output error
        DM_ECU0_CORE,                              //!< 3 - Core error
        DM_ECU0_MEM,                               //!< 4 - Memory error
        DM_ECU0_WD,                                //!< 5 - Watchdog error
        DM_ECU0_PSW                                //!< 6 - Power switch
    };
    //!  Ecu1_Safety
    enum
    {
        DM_ECU1_APP_SAFESTATE,                     //!< 0 - Application control safe state
        DM_ECU1_BOARD_SAFESTATE,                   //!< 1 - Board control safe state (not connect)
        DM_ECU1_REQ_SAFESTATE,                     //!< 2 - Board control safe state (not connect)
        DM_ECU1_OTHERS,                            //!< 3 - Other ecu error
        DM_ECU1_UNDEF                              //!< 4 - Undefined ecu API error
    };
    #endif


    #ifdef COMPILER_SWITCH_ECU_TTC77
    //!  Ecu0_Safety
    enum
    {
        DM_ECU0_INPBOARDNON,                       //!< 0 - Non-fatal input board circuit errors
        DM_ECU0_INPBOARDFAT,                       //!< 1 - Fatal input board circuit errors
        DM_ECU0_INPUTPINS,                         //!< 2 - Input pin related errors
        DM_ECU0_PWMOUT,                            //!< 3 - PWM output error
        DM_ECU0_CORE,                              //!< 4 - Core error
        DM_ECU0_MEM,                               //!< 5 - Memory error
        DM_ECU0_WD,                                //!< 6 - Watchdog error
        DM_ECU0_SHUTOFF                            //!< 7 - Shut off groups
    };

    //!  Ecu1_Safety
    enum
    {
        DM_ECU1_APP_SAFESTATE,                     //!< 0 - Application control safe state
        DM_ECU1_BOARD_SAFESTATE,                   //!< 1 - Board control safe state (not connect)
        DM_ECU1_REQ_SAFESTATE,                     //!< 2 - Board control safe state (not connect)
        DM_ECU1_OTHERS,                            //!< 3 - Other ecu error
        DM_ECU1_UNDEF                              //!< 4 - Undefined ecu API error
    };

    //! ExtEcuSil (only for the TTC77)
    enum
    {
        DM_EXT_SENSOR_SW,                          //!< 'Sensor1 supply' switch is incorrect
        DM_EXT_K15_SW,                             //!< K15 switch is incorrect
        DM_EXT_POWER_SW,                           //!< Power enable switch is incorrect
        DM_EXT_SAFTEY_SW_00,                       //!< Safety switch 0 state is incorrect
        DM_EXT_SAFTEY_SW_01,                       //!< Safety switch 1 state is incorrect
        DM_EXT_SAFTEY_SW_02                        //!< Safety switch 2 state is incorrect
    };
    #endif


    #ifdef COMPILER_SWITCH_ECU_TTC71
    enum
    {
        DM_EXT_SENSOR_SW,                          //!< 'Sensor1 supply' switch is incorrect
        DM_EXT_K15_SW,                             //!< K15 switch is incorrect
        DM_EXT_POWER_SW,                           //!< Power enable switch is incorrect
    };
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC5XX
    //!  Ecu0_Safety
    enum
    {
        DM_ECU0_INPBOARDNON,                       //!< 0 - Non-fatal input board circuit errors
        DM_ECU0_INPBOARDFAT,                       //!< 1 - Fatal input board circuit errors
        DM_ECU0_INPUTPINS,                         //!< 2 - Input pin related errors
        DM_ECU0_DOUT,                              //!< 3 - Digital output pin
        DM_ECU0_PWMOUT,                            //!< 4 - PWM output PIN
        DM_ECU0_CORE,                              //!< 5 - Core error
        DM_ECU0_MEM,                               //!< 6 - Memory error
        DM_ECU0_WD                                 //!< 7 - Watchdog error
    };
    //!  Ecu1_Safety
    enum
    {
        DM_ECU1_SSW,                               //!< 0 - Safety switch error
        DM_ECU1_APP_SAFESTATE,                     //!< 1 - Safe state
        DM_ECU1_BOARD_SAFESTATE,                   //!< 2 - Board control safe state (not connect [alternative variant DM_ECU0_*])
        DM_ECU1_REQ_SAFESTATE,                     //!< 3 - Board control safe state (not connect [alternative DM_ECU1_APP_SAFESTATE])
        DM_ECU1_OTHERS,                            //!< 4 - Other ecu error
        DM_ECU1_UNDEF                              //!< 5 - Undefined ecu API error
    };
    #endif

    #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX
    //!  Ecu0_Safety
    enum
    {
        DM_ECU0_INPBOARDNON,                       //!< 0 - Non-fatal input board circuit errors
        DM_ECU0_INPBOARDFAT,                       //!< 1 - Fatal input board circuit errors
        DM_ECU0_INPUTPINS,                         //!< 2 - Input pin related errors
        DM_ECU0_DOUT,                              //!< 3 - Digital output pin
        DM_ECU0_PWMOUT,                            //!< 4 - PWM output PIN
        DM_ECU0_CORE,                              //!< 5 - Core error
        DM_ECU0_MEM,                               //!< 6 - Memory error
        DM_ECU0_WD                                 //!< 7 - Watchdog error
    };
    //!  Ecu1_Safety
    enum
    {
        DM_ECU1_SSW,                               //!< 0 - Safety switch error
        DM_ECU1_APP_SAFESTATE,                     //!< 1 - Safe state
        DM_ECU1_BOARD_SAFESTATE,                   //!< 2 - Board control safe state (not connect [alternative variant DM_ECU0_*])
        DM_ECU1_REQ_SAFESTATE,                     //!< 3 - Board control safe state (not connect [alternative DM_ECU1_APP_SAFESTATE])
        DM_ECU1_OTHERS,                            //!< 4 - Other ecu error
        DM_ECU1_UNDEF                              //!< 5 - Undefined ecu API error
    };
    #endif

    //==================================================================================================================
    //==================================================================================================================
    //==================================================================================================================

    //EcuSil
    enum
    {
        DM_ECU_TASK_OVERLOAD,                      //!< Cycle time out of range
        DM_ECU_BAT_TO_LOW,                         //!< 'Battery voltage' to low
        DM_ECU_BAT_TO_HIGH,                        //!< 'Battery voltage' to high
        DM_ECU_TEMP_TO_LOW,                        //!< 'Board temperature' to low
        DM_ECU_TEMP_TO_HIGH                        //!< 'Board temperature' to high
    };


    //! SensorSupply
    enum
    {
        #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX
             DM_SEN_S0_TO_LOW                          //!< 'Sensor0 supply' to low
            ,DM_SEN_S0_TO_HIGH                         //!< 'Sensor0 supply' to high
            ,DM_SEN_S1_TO_LOW                          //!< 'Sensor1 supply' to low
            ,DM_SEN_S1_TO_HIGH                         //!< 'Sensor1 supply' to high
            ,DM_SEN_SV_TO_LOW                          //!< 'SensorV supply' to low
            ,DM_SEN_SV_TO_HIGH                         //!< 'SensorV supply' to high
        #else
        #ifdef COMPILER_SWITCH_FAM_TTC5XX
           DM_SEN_S0_TO_LOW                          //!< 'Sensor0 supply' to low
          ,DM_SEN_S0_TO_HIGH                         //!< 'Sensor0 supply' to high
          #ifndef COMPILER_SWITCH_ECU_TTC508
          ,DM_SEN_S1_TO_LOW                          //!< 'Sensor1 supply' to low
          ,DM_SEN_S1_TO_HIGH                         //!< 'Sensor1 supply' to high
          ,DM_SEN_SV_TO_LOW                          //!< 'SensorV supply' to low
          ,DM_SEN_SV_TO_HIGH                         //!< 'SensorV supply' to high
          #endif
        #else
           DM_SEN_S0_TO_LOW                          //!< 'Sensor0 supply' to low
          ,DM_SEN_S0_TO_HIGH                         //!< 'Sensor0 supply' to high
          #ifndef COMPILER_SWITCH_FAM_TTC3X
          ,DM_SEN_S1_TO_LOW                          //!< 'Sensor1 supply' to low
          ,DM_SEN_S1_TO_HIGH                         //!< 'Sensor1 supply' to high
          #endif
          #ifdef COMPILER_SWITCH_FAM_TTC5X
          ,DM_SEN_SV_TO_LOW                          //!< 'SensorV supply' to low
          ,DM_SEN_SV_TO_HIGH                         //!< 'SensorV supply' to high
          #endif
        #endif
        #endif
    };

    //! ErrorList
    enum
    {
        DM_LIST_LOAD_ONESET,                       //!< Fist load fault page is incorrect, second fault page is correct
        DM_LIST_LOAD_DEFECT,                       //!< Fault page is incorrect -> Fault-List have now no faults (back to Dftl)
        DM_LIST_STORE_DEFECT,                      //!< Fault page can't store
        DM_LIST_OVERFLOW                           //!< Fault page have to much active errors
    };

// CONFIGURATION STRUCTURE =========================================================================

    //! Configuration of SIL-Block
    typedef struct
    {   //Common
        TChar      achName[BLO_NAME_STR_LEN];      //!< [STR] - Block name
        EBloStatus eBloProc;                       //!< [DEF] - Block process
        // Fixed settings
        TUint8     u8ErrCnt;                       //!< [NUM] - Cnt of valid error case
        // Error [0-8]
        TErrCfgFea atErrFea[8];                    //!< [CLA] - Error number configurations
    } TSilCfg;

    //! ADDRESS SUB-BLOCK
    typedef struct
    {
        const TSilCfg*  cptCfg;                    //!< [STU] - Configuration struct
              TVoid*    pvObj;                     //!< [STU] - Pointer to the private object
              TUint16   u16Stamp;                  //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block Id
    }TSilAdr;

    //! BLOCK
    typedef struct
    {
        TBehErr tBehErr;                           //!< [STU] - Block error behavior status [status & control]
        TSilAdr tXAdr;                             //!< [STU] - Private address information
    } TBloSil;

// LIBRARY PROTOTYPES ==============================================================================

    //--------------------------------------------------------------------------------------------------
    //! @brief      With that function it is possible to define a error code (or 2, or 3) as a critical error.
    //!             If a critical error is store in the fault memory and the ecu start again - the application,
    //!             goes into the DEBUG-Phase.
    //!             - NOTE: This function shall be called in the eAppPreStart()-function
    //! @param[in]  u32ErrCodeA use u32CoreErrCodePack(u32Spn, u8Fim, u8ExtFmi) to compress the error code
    //! @param[in]  u32ErrCodeB use u32CoreErrCodePack(u32Spn, u8Fim, u8ExtFmi) to compress the error code / '0' is for no more error code
    //! @param[in]  u32ErrCodeC use u32CoreErrCodePack(u32Spn, u8Fim, u8ExtFmi) to compress the error code / '0' is for no more error code
    //--------------------------------------------------------------------------------------------------
    TVoid vBloSilCriticalNeverStart( TUint32 u32ErrCodeA, TUint32 u32ErrCodeB, TUint32 u32ErrCodeC );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error status on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BIT]   If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloSilGetErrStaBit( TBloSil* ptBlo, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the sum error status information
    //! @param[in]  ptBlo   - [PNT] Pointer to the block
    //! @retval     OKAY    - [BIT] Error state bit coded
    //! @retval     ERROR   - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloSilGetErrStaAll( TBloSil* ptBlo );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT]   Pointer to the block
    //! @param[in]  u8BitPos  - [Index] Bit number 0-7
    //! @param[in]  boDetect  - [DEF]   TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BO]    Error state of the specific bit position
    //! @retval     ERROR     - [BO]    If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boBloSilGetErrEveBit( TBloSil* ptBlo, TBoolean boDetect, TUint8 u8BitPos );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the error event on a specified bit position
    //! @param[in]  ptBlo     - [PNT] Pointer to the block
    //! @param[in]  boDetect  - [DEF] TRUE = the Detect-Bit-Event, FALSE = the Delete-Bit-Event
    //! @retval     OKAY      - [BIT] Error state bit coded
    //! @retval     ERROR     - [BIT] If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16BloSilGetErrEveAll( TBloSil* ptBlo, TBoolean boDetect );

#endif
