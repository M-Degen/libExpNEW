//**************************************************************************************************
/*!
@file       ItfBasStruc.h
@brief	    Basic signaling interface
@date       29.02.2012
@author     HYDAC/NJP+ELA
*/
//**************************************************************************************************

#ifndef __ITFBASSTRUC__
	#define __ITFBASSTRUC__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCore.h>
    #include <ItfCoreEcu.h>

// DEFINES & ENUMS  ================================================================================
// CONFIGURATION STRUCTURE =========================================================================

    //! Characteristic node/point definition (needed for SigLut and SigLutd)
    typedef struct
    {
        TInt16 i16X;                   //!< [--]  X point
        TInt16 i16Y;                   //!< [--]  Y point
    } TPntI16;

    //! Proportional signal with command information (needed for SigLut and SigLutd)
    typedef struct
    {
        TBit2  bi2Cmd;                 //!< [DEF] Command status      -  BI2_OFF, BI2_ON, BI2_ERROR, BI2_NOT=^=BI2_UNDEF
        TInt16 i16Sig;                 //!< [cus] Proportional signal
    } TSigCmd;

    //! Proportional signal with direction information (needed for SigLut and SigLutd)
    typedef struct
    {
        TBit3  bi3Dir;                 //!< [DEF] Direction status    - BI3_NEU, BI3_POS, BI3_NEG, BI3_CTLERR, BI3_ERROR, BI3_NOT=^=BI3_UNDEF
        TInt16 i16Sig;                 //!< [cus] Proportional signal
    } TSigDir;

// LIBRARY GLOBAL CONSTANT VARIABLES ===============================================================

// LIBRARY PROTOTYPES ==============================================================================

    // Functions for parameter settings 

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get structure "Proportional signal with command status" (needed for SigLut)
    //! @param[in]  bi2Cmd  - [DEF] Command status
    //! @param[in]  i16Sig  - [cus] Proportional signal
    //! @param[out] ptStruc - [STR] proportional signal with command status
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSetStrucSigCmd(TBit2 bi2Cmd, TInt16 i16Sig, TSigCmd* ptStruc);

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get structure w/ curve parameters (needed for SigLut and SigLutd)
    //! @param[in]  u8ArrMax - [NUM] maximum count of array values used from parameters “ai16X” and “ai16Y”
    //! @param[in]  ai16X[]  - [cus] X node values
    //! @param[in]  ai16Y[]  - [cus] Y node values
    //! @param[in]  u8PntMax - [NUM] count of (x and y) point values, which will be initiated in array “ptPnt”
    //! @param[out] ptPnt    - [PTR] pointer field (pointer to struct array) of merged point arrays
    //! @retval     R_OKAY
    //! @retval     R_RANGE         - array bigger as the pointer field
    //! @retval     R_NULL_POINTER  - ai16X or/and ai16Y or/and ptPnt is/are a Null Pointer
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eSetStrucSigPnt( TUint8 u8ArrMax, TInt16 ai16X[], TInt16 ai16Y[], TUint8 u8PntMax, TPntI16 *ptPnt );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get structure "Proportional signal with direction status" (needed for SigLut and SigLutd)
    //! @param[in]  bi3Dir  - [DEF] direction status
    //! @param[in]  i16Sig  - [cus] proportional signal
    //! @param[out] ptStruc - [STR] proportional signal with direction status
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSetStrucSigDir(TBit3 bi3Dir, TInt16 i16Sig, TSigDir* ptStruc);

#endif
