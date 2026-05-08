//**************************************************************************************************
/*!
@file        ItfBasUtility.h
@brief       Utility functions
@date        03.12.2015
@author      HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBASUTILITY__
  #define __ITFBASUTILITY__

// INCLUDES =======================================================================================
	#include <ItfTypes.h>

    #ifdef COMPILER_SWITCH_OEM_TTC

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculation for the correct Pwm-Duty-Cycle with the operated voltage
    //!             [U=gEcu_tSys.u8EcuVoltage]
    //! @param[in]  u16Current       - [mA/10]
    //! @param[in]  u16ResistorCold  - [ohm/10]
    //! @param[in]  i8ResPp          - [%] tolerance of resistor code => u16ResistorCold = u16ResistorCold + percentage rate
    //! @return     Duty cycle
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CalPwmDcBatOperate( TUint16 u16Current, TUint16 u16ResistorCold, TInt8 i8ResPp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculation for the correct Pwm-Duty-Cycle with the CURRENT Voltage
    //!             [U=u16CoreAdcGetPin( ADC_SYS_BAT_CURRENT, PIN_SYS )]
    //! @param[in]  u16Current       - [mA/10]
    //! @param[in]  u16ResistorCold  - [Ohm/10]
    //! @param[in]  i8ResPp          - [%] tolerance of resistor code => u16ResistorCold = u16ResistorCold + percentage rate
    //! @return     Duty Cycle
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CalPwmDcBatCurrent( TUint16 u16Current, TUint16 u16ResistorCold, TInt8 i8ResPp );

    #endif

	#ifdef COMPILER_SWITCH_TAR_PC

    //--------------------------------------------------------------------------------------------------
    //! @brief      For reading the instruction register
    //! @return     instruction register
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64CoreRdtsc( TVoid );

    #endif

#endif
