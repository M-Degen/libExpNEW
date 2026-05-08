//**************************************************************************************************
/*!
@file       ItfCoreEcu.h
@brief      Ecu Interface
@date       01.02.2011
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREECU__
    #define __ITFCOREECU__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreCan.h>
    #include <ItfCoreBoard.h>
    
// DEFINES & ENUMS  ================================================================================
    #define VAL_NA               0xFF         //!< For the ITF interface, if the value have no effect with the TYPE of object
    #define ECU_FEATURE_STR_LEN (16+1)        //!< String length

    //! Protocol Type
    typedef enum
    {
        FAULT_MODE_ECU,                       //!< For one ecu (3 Level)
        FAULT_MODE_SINGLE                     //!< For each fault (8 Level)
    }EFaultMode;

    #define ECU_NA  0xFF                      //!< ECU number isn't in network

    //! Sil
    typedef struct
    {
        // SIL Setting
        TUint8   u8SilLevel;                  //!< [DEF] Safety level - SilLevel = 0 no SIL-Errors,
                                              //!<                    - SilLevel = 1 with SIL-Errors
        TUint16  u16EcuTaskTime;              //!< [ms] Task time
        TUint16  u16EcuBatLow;                //!< [mV] Ecu battery supply     - lowest valid value
        TUint16  u16EcuBatHigh;               //!< [mV] Ecu battery supply     - highest valid value
        TInt16   i16EcuTempLow;               //!< [°C] Ecu temperature        - lowest valid value
        TInt16   i16EcuTempHigh;              //!< [°C] Ecu temperature        - highest valid value
        TUint16  u16SensorSsLow;              //!< [mV] Sensor supply 5V       - lowest valid value
        TUint16  u16SensorSsHigh;             //!< [mV] Sensor supply 5V       - highest valid value
        TUint16  u16SensorVsLow;              //!< [mV] Variable sensor supply - lowest valid value
        TUint16  u16SensorVsHigh;             //!< [mV] Variable sensor supply - highest valid value
    }TEcuSil;

    //! Fault
    typedef struct
    {
        // Fault stack options
        TUint8     u8ParmIdx;                 //!< [NUM] If a parameter was changed -> format the error stack
        EFaultMode eFaultMode;                //!< [DEF] Fault Mode
        TBoolean   boFaultDoubleMode;         //!< [DEF] Fault/Event store double mode
        TBoolean   boEventStore;              //!< [DEF] Change store event
        TUint16    u16StoreTime;              //!< [sec] Delta time between two stores
        TBoolean   boRestartDeactive;         //!< [DEF] After restart Ecu all faults not active
        TUint16    u16DelCustomer;            //!< [h]   Costumer: Delete fault stack (0 no delete)      (maximum about 7 years)
        TUint16    u16DelEngineer;            //!< [h]   Engineer: Delete fault/event stack (0 no delete)(maximum about 7 years)
    }TEcuFault;

    //! Ecu version information
    typedef struct
    {
        // ECU indicator
        TUint8     u8EcuNo;                   //!< [NUM] controller number in network

        // ECU setting
        TUint8     u8EcuVoltage;              //!< [V]   controller UB
        TUint16    u16DiagnosticTime;         //!< [ms]  ECU diagnostic time
        TUint16    u16EcuPowerOffTime;        //!< [ms]  Ecu power Off detection time (50 - 60000)

        // Only TTC5XX - Wake-Up
        TUint16    u16WaitAfterWakeUp;        //!< [sec] Wait Wake up time [special value: 0xFFFF=WAKEUP_NO_EXIT]
        TBoolean   boShutDownAfterWakeUp;     //!< [DEF] AppSchutDown after WakeUp [DEF(Default=TRUE)]

        // Password application settings
        TBoolean   boAppPwCheck;              //!< [DEF] Application password check -> check with vehicle code see version page

        TEcuSil    tSil;                      //!< [STU] SIL error settings

        // TTC50/TTC60 (not TTC90 - have a HW watchdog)
        TUint16    u16WdTimeout;              //!< [ms]  Watchdog timeout

        TEcuFault  tFault;                    //!< [STU] Fault stack settings

    }TEcuSys;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the Ecu Number
    //! @return     Ecu Number
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CoreGetEcuNo( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Give the system information field (pointer of gEcu_tSys)
    //! @return     ptCoreVerInfo  - With the first vCoreMain() call is the pointer valid. [In the vAppFixInit() the function return NULL )
    //--------------------------------------------------------------------------------------------------
    extern TEcuSys *ptCoreEcuSys( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Bypass function to overwrite the K15-OFF value, preventing the ECU from switching off
    //! @Note       For all "core (only) phases" the boSta value is hold, for each "app phase" this function
    //!             must be cyclically called with boSta=TRUE. If there is no cyclic call of this function
    //!             or it is called with boSta=FALSE, the real K15 pin returned to have the master role.
    //!             The function eCoreShutdownByCommand also overrides this hold mechanism and forces the
    //!             ECU to shut down.
    //! @return     R_OKAY     - successful
    //! @return     R_UNKNOWN  - error (currently not possible)
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreK15HoldOnFktSta( TBoolean boSta );

    extern TEcuSys gEcu_tSys;                 //!< globvar create by the PDT [system information]

#endif
