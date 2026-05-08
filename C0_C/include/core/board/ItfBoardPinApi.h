//*****i*********************************************************************************************
/*!
@file       ItfBoardPinApi.h
@brief      Board Interface
@date       26.10.2020
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef INCLUDE_CORE_BOARD_ITFBOARDPINAPI_H_
#define INCLUDE_CORE_BOARD_ITFBOARDPINAPI_H_

    #include <autoconfig.h>

    #ifdef COMPILER_SWITCH_OEM_TTC

    #ifdef COMPILER_SWITCH_PLATFORM_TTC2XXX
       #include <ItfBoardPinApiTtc2xxx.h>
    #else
      #include <ItfBoardPinApiTtc.h>        // TTControl Hydac International
    #endif

    #endif

    #ifdef COMPILER_SWITCH_OEM_HY
      #ifdef COMPILER_SWITCH_FAM_HYMEB
        #include <ItfBoardPinApiHySoft.h>   // Hydac Software
      #else
        #include <ItfBoardPinApiHyElec.h>   // Hydac Electronik
      #endif
    #endif

    #ifdef COMPILER_SWITCH_OEM_UNJO
        #include <ItfBoardPinApiUnjo.h>
    #endif

    // ==============================================================================================================
    // !! The use of these functions in the application leads immediately to the exclusion of the HYDAC liability. !!
    // !! The use of the entire application with all the components used a call at your own risk.                  !!
    // !! IF YOU USE THE FUNCTIONS IN THIS H-FILE, THE HYDAC PRODUCT LIABILITY WILL BE EXTINGUISHED                !!
    // ==============================================================================================================

    #if defined(COMPILER_SWITCH_CORE_BUILD) || defined(COMPILER_SWITCH_PTC_BUILD)

      //--------------------------------------------------------------------------------------------------
      //! @brief     Give pin input type
      //! @note      THE USE OF THESE FUNCTIONS WILL VOID THE PRODUCT LIABILITY
      //! @param[in] u8PinIdx
      //! @retval    Input type
      //! @retval    PININ_NA   if the pin index is out of range
      //--------------------------------------------------------------------------------------------------
      extern EEcuPinInTyp eCorePinInTyp( TUint8 u8PinIdx );

      //--------------------------------------------------------------------------------------------------
      //! @brief     Give pin output type
      //! @note      THE USE OF THESE FUNCTIONS WILL VOID THE PRODUCT LIABILITY
      //! @param[in] u8PinIdx
      //! @retval    Output type
      //! @retval    PINOUT_NA   if the pin index is out of range
      //--------------------------------------------------------------------------------------------------
      extern EEcuPinOutTyp eCorePinOutTyp( TUint8 u8PinIdx );

      //--------------------------------------------------------------------------------------------------
      //! @brief     Give the last system pin values
      //! @note      THE USE OF THESE FUNCTIONS WILL VOID THE PRODUCT LIABILITY
      //! @return    The Pointer to the System pins
      //--------------------------------------------------------------------------------------------------
      extern const TSysPinLast *cptCoreSysPinLast( TVoid );

      //--------------------------------------------------------------------------------------------------
      //! @brief     Give the last pin layer struct
      //! @note      THE USE OF THESE FUNCTIONS WILL VOID THE PRODUCT LIABILITY
      //! @param[in] u8PinIdx
      //! @return    The Pointer to the pins struct
      //-------------------------------------------------------------------------------------------------
      extern const UPinLast *cptCorePinLast( TUint8 u8PinIdx );


        #ifdef COMPILER_SWITCH_FORCE_FEATURE

          // THE USE OF THESE FOLLOWING FUNCTIONS WILL VOID THE PRODUCT LIABILITY ------------------------

          //!< Forcing Option
          typedef enum
          {
              PINFORCE_NONE         = 0,       //!< no Forcing / Stop Forcing       ( only ADC(boIsDacGrp=FALSE) or DAC(boIsDacGrp==TRUE) part
              PINFORCE_NONE_DACADC  = 1,       //!< no Forcing / Stop Forcing       ( ADC+DAC part )
              PINFORCE_DAC_VAL      = 2,       //!< Force only the value            ( PIN-OUT: VALUE  (e.g. DC) | PIN-IN: ----  )
              PINFORCE_DAC_STAVAL   = 3,       //!< Force the status and the value  ( PIN-OUT: 1 & 2            | PIN-IN: ----  )
              PINFORCE_ADC_STAVAL   = 4        //!< Force the status and the value  ( PIN-OUT: ----             | PIN-IN: VALUE )
          }EPinForce;

          typedef enum
          {
             FORCE_CTRL_CPY_RUN   = 0,       //!< Force the pin (with the one or with all prepared forcing values)
             FORCE_CTRL_CPY_WAIT  = 1,       //!< Prepare forced pin value
             FORCE_CTRL_NO        = 2        //!< Init value and forcing switch from 'ON' to 'OFF
          }EForceCtrlMode;

          //--------------------------------------------------------------------------------------------------
          //! @brief       Control function for the PIN forcing (PTC (e.g MST) -> ECU)
          //!              - Pins can only be set (forced) in AppRun phase
          //!              - advice use that function in the AppInit phase or AppRun phase, but all other phase are not forbidden
          //!              - deactivate the 'TSE-Pin Forcing'
          //! @param[in]   boEnable     FALSE: forcing is not possible, TRUE: the App/PTC (e.g. MST-PTC) can force the PIN's [DFTL: FALSE]
          //! @param[in]   boStopOut    if the PTC finished the forcing with a special command (e.g MST->PTC_FORCE_QUICK_STOP)
          //!                            TRUE:  POWERSTAGE_ENABLE, SAFTEY_SW, PWM_ENABLE will turn 'off' if the ECU support it
          //!                            FALSE: normal mode
          //! @param[in]   boPtcTimeOut if the PTC don't trigger the forcing pins (in time - PinForceCnt++ < PIN_FORCING_TASK_CNT_WINDOW (DFLT:=20)
          //!                            By each pin forcing command: PinForceCnt=0 )
          //!                            TRUE:  POWERSTAGE_ENABLE, SAFTEY_SW, PWM_ENABLE will turn 'off' if the ECU support it
          //!                            FALSE: normal mode
          //--------------------------------------------------------------------------------------------------
          extern TVoid vCorePinForceAppCtrl( TBoolean boEnable, TBoolean boStopOut, TBoolean boPtcTimeOut );

          //--------------------------------------------------------------------------------------------------
          //! @brief     Give the enable forcing enable status back (status from vCorePinForceCtrl via app or ptc)
          //! @return    TRUE/FALSE
          //--------------------------------------------------------------------------------------------------
          extern TBoolean boCorePinForceAppEnabled( TVoid );

          //--------------------------------------------------------------------------------------------------
          //! @brief      Outputs should be stopped if MST forces stop for pin forcing?(set in vCorePinForceCtrl)
          //! @return     TRUE/FALSE
          //--------------------------------------------------------------------------------------------------
          extern TBoolean boCorePinForceAppStopOut( TVoid );

          //--------------------------------------------------------------------------------------------------
          //! @brief       Extended Control function for the PIN forcing.
          //!              This function supplements the vCorePinForceCtrl() function
          //! @note        Need for the 'normal' forcing mode.
          //! @param[in]   u8TaskTrigCntWindow  0-255 (0 the time window is OFF)
          //!                                   Change for the vCorePinForceCtrl() the PIN_FORCING_TASK_CNT_WINDOW-Value see the
          //!                                   input parameter boPtcTimeOut
          //--------------------------------------------------------------------------------------------------
          extern TVoid vCorePinForceAppCtrlTaskCntWindow( TUint8 u8TaskTrigCntWindow );

          //--------------------------------------------------------------------------------------------------
          //! @brief       Get the 'Task Count Window' from the pin forcing back.
          //!              (DFLT=20, change with vCorePinForceCtrlTaskCntWindow()) This function supplements the vCorePinForceCtrl() function.
          //! @note        Need for the 'normal' forcing mode.
          //! @return      u8TaskTrigCntWindow  0-255 (0 the time window is OFF)
          //--------------------------------------------------------------------------------------------------
          extern TUint8 u8CorePinForceAppTaskCntWindow( TVoid );

          //--------------------------------------------------------------------------------------------------
          //! @brief      Clear Task Counter.
          //! @param[in]  u8PinIdx
          //--------------------------------------------------------------------------------------------------
          extern TVoid vCorePinForceAppClrTaskCnt( TUint8 u8PinIdx );

          //--------------------------------------------------------------------------------------------------
          //! @brief     Forcing pin master control action
          //! @param[in] TRUE  = Active
          //!            FALSE = Inactive -> Deactivates forcing for each pin in the forcing structure.
          //--------------------------------------------------------------------------------------------------
          extern TVoid vCorePinForceMasterCtrl( TBoolean boOn );

          //--------------------------------------------------------------------------------------------------
          //! @brief       Control function for the TSE PIN forcing. (Use at your own risk - There are no security concepts such as time windows or magic number)
          //!              The 'TSE Pin Forcing' work only, if the 'Pin Forcing' is active. The 'TSE Pin Forcing' overwirte the normal 'Pin Forcing' on.
          //! @param[in]    boEnable    TRUE:  Quick-TSE-Pin-Forcing is on - No Time-Check and no Magic-Nummer is needed.
          //!                           FALSE: Quick-TSE-Pin-Forcing is off(DFLT)
          //--------------------------------------------------------------------------------------------------
          extern TVoid vCorePinForceTseCtrl( TBoolean boEnable );

          //--------------------------------------------------------------------------------------------------
          //! @brief     Enable TSE Forcing
          //! @note      THE USE OF THESE FUNCTIONS WILL VOID THE PRODUCT LIABILITY
          //! @return    TRUE - TSE forcing enabled, FALSE - TSE forcing disabled
          //--------------------------------------------------------------------------------------------------
          extern TBoolean boCorePinForceTseEnabled( TVoid );

          //--------------------------------------------------------------------------------------------------
          //! @brief      Set forcing data for given pin (PTC helper function)
          //! @details    Function is used to force values/status for pin. \n
          //!             Forced pin values/status are returned by MATCH functions reading pins instead of the actual HW/BSP based values.\n
          //!             Forced pin values are used when writing pin values instead of values set in application.\n
          //!             If multiple input/output values for the given pin are to be forced use FORCE_CTRL_CPY_WAIT to buffer them first
          //!             and FORCE_CTRL_CPY_RUN to activate those forcing settings for the pin at the same time. \n
          //!             Using this function with a different pin as the one in the buffer, will reset the buffer and return an error.
          //! @param[in]  eCtrlMode     - FORCE_CTRL_CPY_RUN: immediately force values,
          //!                             FORCE_CTRL_CPY_WAIT: prepare value to be forced, write to buffer,
          //!                             FORCE_CTRL_NO: forcing off(clear buffer)
          //! @param[in]  u8Pin         - pin to be forced (system pin: pin=0 + adc-grp: e.g. pin=0, adc-grp=ADC_SYS_SAFE_STATE)
          //! @param[in]  eForce        - PINFORCE_NONE: stop forcing( only ADC(boIsDacGrp=FALSE) or DAC(boIsDacGrp==TRUE) part
          //!                           - PINFORCE_NONE_DACADC: stop forcing      ( ADC+DAC part )
          //!                           - PINFORCE_DAC_VAL: force only the DAC value
          //!                           - PINFORCE_DAC_STAVAL: force DAC value+status
          //!                           - PINFORCE_ADC_STAVAL: for ADC value+status
          //! @param[in]  boBspOff      - TRUE:  BSP function to access pin(HW) will not be called
          //!                           - FALSE: BSP function will be called/applied to HW output
          //! @param[in]  boIsDacGrp    - TRUE:  u8AdcDacGrp is EDacTyp,
          //!                           - FALSE: u8AdcDacGrp is EAdcTyp
          //! @param[in]  u8AdcDacGrp   - ADC/DAC type for pin to be forced
          //! @param[in]  ePinStatus    - pin status to be forced
          //! @param[in]  u16PinVal     - pin value to be forced
          //! @param[in]  boExtendedVal - TRUE=u16PinVal contains MSBs of 32Bit values or extended value, FALSE=LSBs/16bit main value
          //!                              if ADC type does not support extended value, regular value is overwritten
          //! @retval     R_OKAY          - fine
          //! @retval     R_INCONSISTENT  - Parameters do not fit installed pin or combination of parameters invalid. \n.
          //!                               e.g. u8AdcDacGrp doesn't match the installed pin type, eForce incompatible with boIsDacGrp
          //! @retval     R_RANGE         - pin out of range
          //! @retval     R_SUPPORT       - u8AdcDacGrp not supported for forcing [with given settings]
          //! @retval     R_PARAMETER     - DAC does not support boExtendedVal==TRUE/invalid eForce value
          //! @retval     R_CONFIG        - pin forcing not enabled
          //--------------------------------------------------------------------------------------------------
          extern ERetVal eCorePinForcePrepare( EForceCtrlMode eCtrlMode, TUint8 u8Pin, EPinForce eForce, TBoolean boBspOff,
                                               TBoolean boIsDacGrp, TUint8 u8AdcDacGrp,
                                               EPinStatus ePinStatus, TUint16 u16PinVal, TBoolean boExtendedVal );

          //--------------------------------------------------------------------------------------------------
          //! @brief      Return if pin input(any ADC function) is forced
          //! @param[in]  u8PinIdx
          //! @retval     TRUE    - [a] pin input is forced
          //! @retval     FALSE   - no input forced
          //! @created    28.10.2021         HYDAC/THU
          //--------------------------------------------------------------------------------------------------
          extern TBoolean boCorePinForceIsAdcForced( TUint8 u8PinIdx );
          //--------------------------------------------------------------------------------------------------
          //! @brief      Return if pin output(DAC function) is forced
          //! @param[in]  u8PinIdx
          //! @retval     TRUE    - pin output is forced
          //! @retval     FALSE   - output not forced
          //! @created    28.10.2021         HYDAC/THU
          //--------------------------------------------------------------------------------------------------
          extern TBoolean boCorePinForceIsDacForced( TUint8 u8PinIdx );

          //--------------------------------------------------------------------------------------------------
          //! @brief      Return if forcing is active for PIN based on update flags
          //! @param[in]  u8PinIdx
          //! @return     TRUE -  status/value or bsp off is configured, FALSE - nothing forced
          //--------------------------------------------------------------------------------------------------
          extern TBoolean boCorePinForceUpdate( TUint8 u8PinIdx );

          //--------------------------------------------------------------------------------------------------
          //! @brief      Deactivate the forcing for that pin
          //! @param[in]  u8PinIdx
          //--------------------------------------------------------------------------------------------------
          extern TVoid vCorePinForceDeactive( TUint8 u8PinIdx );

        #endif

    #endif

#endif
