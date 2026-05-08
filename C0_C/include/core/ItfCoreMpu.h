//**************************************************************************************************
/*!
@file       ItfCoreMpu.h
@brief      Itf for special MPU usage
@see        open
@created    10.04.2019      HYDAC

@details
<pre>
    MPU usage only possible on TTC5XX
    MPU_LIB_USE must be set to "YES" to use MPU, otherwise function calls have no effect
    With MPU_LIB_USE=YES a different linking process is used, that is needed for the Lib to work
        Protected memory is located in section .data_2
        RAM variables(.data, .bss) in files located in the folders 2App and AUTO_CEN_TTC5XX_2APP(including their subfolders) are put into section .data_2
        To change the folders the linker script mem_ttc500_bl_mpu.lsf could be adjusted, but this will not allow building in RELEASE mode anymore
        Other data can be manually placed in this section with "#pragma SET_DATA_SECTION (".data_2")"
        The size and alignment of section .data_2 will automatically be adjusted to match driver requirements.
        MPU is used to set data in section .data_2 to readonly
        Currently .data_2 will be placed in internal RAM
        NOTE: The alignment requirements might lead to some wasted memory, minimum size of a section is 256 bytes
              In the worst case twice the memory is allocated that is actually used
    If .data_2" is empty, the MPU cannot be initialized(R_NOACT)
    MPU_REGION1 is used for .data_2, so should not be used otherwise.
    The initialization of the MPU region can only be done once per ECU start/driver initialization, therefore the function eCoreMpuInit should only be called once.
    Calling the function more then once returns R_BUSY. This could also happen in case of a soft reset or fast k15, so the user should react accordingly, e.g. by checking boCoreEcuNewStart() first.
    After initializing the MPU section unsafe application code can be restricted from writing to this section by enabling the MPU.
    Depending on the initialization the MPU must/can be enabled manually or is switched automatically when entering 1App code.

    If the MPU is initialized with the function eCoreActivate2AppMpu the check for boCoreEcuNewStart is done automatically.
    Setting the first parameter to TRUE automatically enables the MPU every time 1App code is executed.
    -> eAppPreStart, eAppStartUp, vSetAppVersion, vGetVersionInfo, eAppInit, vAppRun, eAppShutDown
    If set to FALSE the MPU has to be manually enabled using the functions eCoreMpuEnable/Disable every time unsafe code is entered/exited.
    Setting the second parameter to FALSE forbids the 1App to call MPU functions, otherwise the 1App can still disable the MPU.
    It is not recommended to manually enable/disable the MPU to overwrite the automatic setting.
    After finishing the unsafe code, the MPU must be disabled again so that other Code(including MATCH core) can access the protected sections.
    ~~~
        eCoreMpuEnable();
        //unsafe code
        eCoreMpuDisable();
    ~~~

    If unsafe code tries to write to protected memory, the configured(vCoreMpuSetFaultCb) callback will be executed.
    The callback can only send a CAN message, the IO driver does not allow setting pins or writing to EEPROM.
    Afterwards the application will stop and safety pins are turned off.
    Warning: pin behavior might not be the same as in safe state.
</pre>
*/
//**************************************************************************************************

#ifndef __ITFCOREMPULIB__
    #define __ITFCOREMPULIB__

    #include <ItfTypes.h>

    #ifdef COMPILER_SWITCH_FAM_TTC5XX

        typedef enum
        {
            MPU_STA_ENABLE,                 //! Enable the given MPU region
            MPU_STA_DISABLE,                //! Disable the given MPU region
            MPU_STA_NO_CONFIG,              //! The given region is already enabled
            MPU_STA_INVALID_PARAMETER,      //! An invalid region ID was given
            MPU_STA_UNDEFINE_RETURN         //! Undefined return value (normally no possible bsp return value)
        }EMpuStatus;

        //--------------------------------------------------------------------------------------------------
        //! @brief      Prototype for function used to for mpu fault callback
        //! @warning    Currently only possible to send a CAN message
        //! @param[in]  u32ErrAddr      address access that caused mpu fault
        //! @return     UDS_COM_PR if conditions are ok, otherwise the appropriate NRC
        //--------------------------------------------------------------------------------------------------
        typedef TVoid (*TFpvCoreMpuFaultCb)( TUint32 u32ErrAddr);

        //--------------------------------------------------------------------------------------------------
        //! @brief      Initialize MPU region for write protected mem
        //! @retval R_OKAY      regions successfully initialized
        //! @retval R_BUSY      region already initialized, might be due to fast k15 - check boCoreEcuNewStart()
        //! @retval R_CONFIG    failed due to wrong configuration of MPU region
        //! @retval R_PHASE     called before IO driver init
        //! @retval R_NOACT     mem region size=0 -> no MPU init possible
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreMpuInit( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Give the current MPU behavior
        //--------------------------------------------------------------------------------------------------
        extern EMpuStatus eCoreMpuStatus( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Enable MPU region for protected ram
        //! @retval     R_OKAY      - MPU enabled
        //! @retval     R_CONFIG    - MPU [region] not initialized
        //! @retval     R_NOACT     - MPU was already enabled
        //! @retval     R_PARAMETER - invalid internal parameter, region not valid
        //! @retval     R_UNKNOWN   - unknown error
        //! @retval     R_LOCKED    - operation not allowed by current app(usually 1app)
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreMpuEnable( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Disable MPU region for protected ram
        //! @retval     R_OKAY      - MPU disabled
        //! @retval     R_CONFIG    - MPU [region] not initialized
        //! @retval     R_NOACT     - MPU was already disabled
        //! @retval     R_PARAMETER - invalid internal parameter, region not valid
        //! @retval     R_UNKNOWN   - unknown error
        //! @retval     R_LOCKED    - operation not allowed by current app(usually 1app)
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreMpuDisable( TVoid );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Set MPU fault callback
        //! @warning    Calling this function from 1App has no effect,
        //!             if 1App access to MPU config is disabled in eCoreActivate2AppMpu
        //! @param[in]  pfvMpuFaultCb      fault callback function
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreMpuSetFaultCb( TFpvCoreMpuFaultCb pfvMpuFaultCb );

        //--------------------------------------------------------------------------------------------------
        //! @brief      Initialize Mpu and set auto/manual handling for MPU functionality
        //! @details    If automatic mpu handling was activated by 2App, only 2App is able to deactivate it \n
        //!             Function should be called in AppPreStart(after driver is initialized)
        //! @param      boProtect2App - TRUE  - automatically turn on MPU when entering 1App context(write to 2App blocked)\n
        //!                           - FALSE - vCoreMpuEnable/Disable has to be called manually
        //! @param      boAccess1App  - TRUE/FALSE - allow/forbid 1App to overwrite MPU enable/disable
        //! @return     status of mpu/initialization, see eCoreMpuInit
        //--------------------------------------------------------------------------------------------------
        extern ERetVal eCoreActivate2AppMpu( TBoolean boProtect2App, TBoolean boAccess1App );


        //--------------------------------------------------------------------------------------------------
        //! @brief      Enable/Disable automatic MPU handling when running 1App
        //! @details    If automatic mpu handling was activated by 2App, only 2App is able to deactivate it
        //! @param      boEnable - turn auto mpu enable function on(TRUE)/off(FALSE)
        //--------------------------------------------------------------------------------------------------
        extern TVoid vCoreMpuSetAutoEnable( TBoolean boEnable);


        //--------------------------------------------------------------------------------------------------
        //! @brief      Returns if MPU is automatically enabled when entering 1App
        //! @retval     TRUE    - auto - MPU is automatically enabled when entering 1App
        //! @retval     FALSE   - manual - MPU must be manually enabled
        //--------------------------------------------------------------------------------------------------
        extern TBoolean boCoreMpuIsAutoEnabled( TVoid );


    #endif

#endif
