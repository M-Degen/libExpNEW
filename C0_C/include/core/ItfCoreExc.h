//**************************************************************************************************
/*!
@file  	    ItfCoreExc.h
@brief	    Exclude group interface
@date       04.12.2011
@author     HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFCOREEXC__
    #define __ITFCOREEXC__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfBasEleErr.h>
    #include <ItfCore.h>

// CONFIGURATION STRUCTURE =========================================================================

    //! Configuration of the exclude group block
    typedef struct
    {   // Fault code
        TUint32 u32ErrNum;                      //!< [NUM] error number
        TUint8  u8ErrMode;                      //!< [NUM] failure mode indicator
        TUint8  u8ErrModeExt;                   //!< [NUM] failure mode indicator
    } TExcFault;

    //! Configuration of the exclude group block
    typedef struct
    {   // Common
        TChar     achName[BLO_NAME_STR_LEN];    //!< [STR] - object name
        // Fixed settings
        TUint8    u8BitPosition;                //!< [NUM] - Bit position of exclude group(enum value)
        TUint8    u8ExcCnt;                     //!< [NUM] - count of errors
        // Fault code
        TExcFault atCode[8];                    //!< [STU] - failure code
    } TExcCfg;

    //--------------------------------------------------------------------------------------------------
    //! @brief      Initialization of the exclude group (it a bypass to the PDT)
    //! @param[in]  ptCfg           exclude group struct
    //! @retval     R_OKAY         - functions execute without error
    //! @retval     R_NULL_POINTER - NULL pointer
    //! @retval     R_RANGE        - range
    //! @retval     R_DOUBLE       - bit position already used
    //--------------------------------------------------------------------------------------------------
    extern ERetVal eCoreExcGrpInit( TExcCfg* ptCfg );

#endif
