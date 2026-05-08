//*************************************************************************************************
/*!
@file       ItfBasEleTimer.h
@brief      Basic timer element
@date       20.02.2011
@author     HYDAC/NJP
*/
//*************************************************************************************************

#ifndef __ITFBASTIMER__
  #define __ITFBASTIMER__

// INCLUDES =======================================================================================
	#include <ItfTypes.h>

// DEFINES & ENUMS  ===============================================================================
    // Common settings for all signal elements
    #define CTRL_MAX_DT  500   //!< [ms] - maximum cycle time

// Timer ==========================================================================================
	//! Timer Types
    typedef enum
    {
        TIMTYP_ABORT,          //!< 0 - [DEF] Abort/non recurring timer ( One-time signal )
        TIMTYP_RECUR,          //!< 1 - [DEF] Recurring/periodic        ( cyclic signal   )
        TIMTYP_STOP            //!< 2 - [DEF] Manual stop timer         ( death signal    )
    } ETimTyp;

	//! Element Definition
	typedef struct
    { // Element Error
        TVoid     *pvObj;      //!< [STU] - Pointer to a private object
        TUint16   u16Stamp;    //!< [NUM] - Block stamp 'A'xx,'E'  xx is the block-ID
    } TEleTimAdr;

// VARIABLES ======================================================================================

// PRIVATE PROTOTYPES =============================================================================

// PUBLIC PROTOTYPES ==============================================================================

//a) Constructor

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create a timer element
    //! @param[in]  ptEleAdr   - Timer element address
    //! @param[in]  cpchNa     - [STR] signal name
    //! @retval     R_OKAY     - Functions execute without error
    //! @retval     R_NOT_NAME - Object name is not valid
    //! @retval     R_MEMORY   - Out of memory
    //! @retval     R_NULL_POINTER - Null pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eEleTimerCreate( TEleTimAdr* ptEleAdr, const TChar* cpchNa );

//b) Initialization

	//--------------------------------------------------------------------------------------------------
    //! @brief      Timer     - Initialization of a timer object
    //! @param[in]  ptEleAdr  - Timer element address
    //! @param[in]  eTimTyp   - [DEF] type of the timer
    //! @param[in]  u32Dt     - [ms]  Target time difference
    //! @retval     R_OKAY         - Function executed without error
    //! @retval     R_RANGE        - Type out of predefined range
    //! @retval     R_NULL_POINTER - Null pointer
    //! @retval     R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
	extern ERetVal eEleTimerInit( TEleTimAdr* ptEleAdr, ETimTyp eTimTyp, TUint32 u32Dt );

//c) Get status functions and access functions

    //--------------------------------------------------------------------------------------------------
    //! @brief      Timer - get signal name
    //! @param[in]  ptEleAdr    - Timer element address
    //! @retval     != NULL     - get signal name
    //! @retval     NULL        - name not valid
    //--------------------------------------------------------------------------------------------------
    extern TChar* pchEleTimerGetName(TEleTimAdr* ptEleAdr);

    //--------------------------------------------------------------------------------------------------
    //! @brief      Timer - set target time difference
    //! @param[in]  ptEleAdr  - Timer element address
    //! @param[in]  u32Dt     - [ms]  Target time difference
    //! @retval     R_OKAY          - Function executed without error
    //! @retval     R_NOACT         - Set time for stop timer is useless (no action)
	//! @retval     R_NULL_POINTER  - NULL pointer
    //! @retval     R_ADDRESS       - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eEleTimerSetTime( TEleTimAdr* ptEleAdr, TUint32 u32Dt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Timer - set type of timer
    //! @param[in]  ptEleAdr  - Timer element address
    //! @param[in]  eTimTyp   - [DEF] Type of timer
    //! @retval     R_OKAY          - Function executed without error
    //! @retval     R_RANGE         - Type out of predefined range
    //! @retval     R_NULL_POINTER  - NULL pointer
    //! @retval     R_ADDRESS       - Wrong block address
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eEleTimerSetType( TEleTimAdr* ptEleAdr, ETimTyp eTimTyp );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Timer - start timer (status is TRUE, event is FALSE if Dt is not caught)
    //! @brief      Reset the start time, status is TRUE, event is FALSE
    //! @brief      By eTimTyp=TIMTYP_ABORT: If the time caught dT, status is FALSE, Event is TRUE - only for one call
    //! @brief      By eTimTyp=TIMTYP_RECUR: If the time caught dT, status is TRUE,  Event is TRUE - only for one call
    //! @brief      By eTimTyp=TIMTYP_STOP:  Status is FALSE, Event is FALSE all the time
    //! @param[in]  ptEleAdr  - Timer Element address
    //! @return     OKAY      - [ms]  ReStart Time
    //--------------------------------------------------------------------------------------------------
	extern TUint32 u32EleTimerStart( TEleTimAdr* ptEleAdr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Timer - manual timer stop and calculation of the time difference - status is FALSE, event is TRUE)
    //! @brief      Set the stop time
    //! @brief      By eTimTyp=TIMTYP_ABORT: If the time caught dT, status is FALSE, Event is TRUE
    //! @brief      By eTimTyp=TIMTYP_RECUR: If the time caught dT, status is FALSE, Event is TRUE
    //! @brief      By eTimTyp=TIMTYP_STOP:  Status is FALSE, Event is FALSE all the time
    //! @param[in]  ptEleAdr  - Timer element address
    //! @param[out] pu32Dt    - [ms]  Start to stop time difference
    //! @retval     R_OKAY         - Function executed without error
    //! @retval     R_RANGE        - Stop time less than start time
    //! @retval     R_TIMEOUT      - Timer already OFF
	//! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_ADDRESS      - Wrong block address
    //--------------------------------------------------------------------------------------------------
	extern ERetVal eEleTimerManStop( TEleTimAdr* ptEleAdr, TUint32* pu32Dt );

	//--------------------------------------------------------------------------------------------------
    //! @brief      Timer - get timer status
    //! @param[in]  ptEleAdr   - Timer element address
    //! @retval     OKAY       - TRUE/FALSE  timer status
	//! @retval     ERROR      - If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
	extern TBoolean boEleTimerGetStatus( TEleTimAdr* ptEleAdr );

	//--------------------------------------------------------------------------------------------------
    //! @brief      Timer - get and reset timer event
    //! @param[in]  ptEleAdr   - timer element address
    //! @retval     OKAY       - timer event (TRUE/FALSE)
    //! @retval     ERROR      - if wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
	extern TBoolean boEleTimerGetEvent( TEleTimAdr* ptEleAdr );

	//--------------------------------------------------------------------------------------------------
    //! @brief      Timer - get time difference
    //! @param[in]  ptEleAdr   - timer element address
    //! @retval     OKAY       - [ms] current timer difference (Dt = start time - current time )
	//! @retval     ERROR      - If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
	extern TUint32 u32EleTimerGetDt( TEleTimAdr* ptEleAdr );

//d) Cyclic signal function

    //--------------------------------------------------------------------------------------------------
    //! @brief      Timer - cyclic calculation of a timer - this function trigger the element
    //! @brief      By eTimTyp=TIMTYP_ABORT: If the time caught dT, status is FALSE, Event is TRUE (only once)
    //! @brief      By eTimTyp=TIMTYP_RECUR: If the time caught dT, status is TRUE,  Event is TRUE (cyclic)
    //! @brief      By eTimTyp=TIMTYP_STOP:  Status is FALSE, event is FALSE all the time
    //! @param[in]  ptEleAdr   - timer element address
    //! @retval     OKAY       - timer status TRUE/FALSE
    //! @retval     ERROR      - If wrong ptBlo-Addr, return value is '0'
    //--------------------------------------------------------------------------------------------------
	extern TBoolean boEleTimerCalculate( TEleTimAdr* ptEleAdr );

#endif
