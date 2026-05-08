//**************************************************************************************************
/*!
@file       ItfBasConv.h
@brief      This header file contains a number of basic functions for value conversion.
@date       20.02.2011
@author     HYDAC/NJP
@version    0.01

--------------------------------------------------------------------------------
# Base functions for value conversion

The functions or this header file provide the following function groups of value conversion: 

## A0 - primitive functions

- a function that shift the parameter 32 bit down
- a function that shift the parameter 32 bit up
- functions that creates a value from an array
- functions that fills an array from the parameter value
- functions that exchange the high and the low value of the parameter

## A1 - CAN functions (Implicit automatic convert to the system [INTEL/MOTOROLA])

The CAN bus supports different methods for data storage: 
 - *MOTOROLA* When storing a word in big-endian format the most significant byte, which is the byte containing the most significant bit, is stored first and the following bytes are stored in decreasing significance order with the least significant byte, which is the byte containing the least significant bit, thus being stored at last place.

 - *INTEL* Little-endian format reverses the order of the sequence and stores the least significant byte at the first location with the most significant byte being stored last.

See: https://en.wikipedia.org/wiki/Endianness

## B1 - functions that converts (by C type casting) a value to the type "integer u8"

The following input types are available here for the type casting: 
- signed byte, 
- signed short, 
- unsigned short, 
- signed long
- unsigned long

## B2 - functions that converts (by C type casting) a value to the type unsigned byte `u8Var`

The following input types are available here for the type casting: 
- signed byte, 
- signed short, 
- unsigned short, 
- signed long
- unsigned long

## B3 - functions that converts (by C type casting) a value to the type signed integer `i16Var`

The following input types are available here for the type casting: 
- unsigned short, 
- signed long
- signed long long

## B4 - functions that convert a value to the type "unsigned integer u16"

The following input types are available here for the type casting: 
- signed short, 
- signed long
- unsigned long
- unsigned long long

## B5 - functions that converts (by C type casting) the parameter to a unsigned long `TUint32`

The following input types are available here for the type casting: 
- signed short, 
- signed long
- unsigned long long
- signed long long

## B6 - functions that convert (by C type casting) the parameter to a signed long `Tint32` or a unsigned long long `TUint64`

The following input types are available here for the type casting: 
- unsigned long, 
- unsigned long long
- signed long long

## C1 - functions for bit manipulation 

Functions that set the content of one ore more bits at the given value. 
The bit mask for byte manipulation can be: 
- a unsigned byte, 
- a unsigned short, 
- a unsigned long, 
- an array of two unsigned long, or
- a unsigned long long

There are also a set of functions that returns the searched bis of a given value. 


## C2 - functions that returns bits


## D1 - more functions


## D2 - tolerance functions


## D3 - time functions


## D4 - temperature functions

*/
//**************************************************************************************************

#ifndef __ITFBASCONV__
  #define __ITFBASCONV__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>
    #include <ItfCoreCan.h>

// (A0) Primitive functions

    //--------------------------------------------------------------------------------------------------
    //! @brief  Shift the input value down -> `u64Val` >> 32  *Reason*: Avoid compiler warnings.
    //!
    //! The operation is shift right >> 32
    //!
    //! Use this function to avoid compiler warnings because type mismatch.
    //!
    //! @sa         u64ShiftUp32
    //! @param[in]  u64Val a `TUint64` value
    //! @return     a `TUint16` value
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32ShiftDownU64( TUint64 u64Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Shift the input value up -> `u64Val` << 32  *Reason*: Avoid compiler warnings.
    //! 
    //! The operation is shift left << 32 
    //!
    //! Use this function to avoid warnings. 
    //!
    //! @sa         u32ShiftDownU64
    //! @param[in]  u32Val 		a long value
    //! @return     a `TUint64`         a unsigned long long value
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64ShiftUp32( TUint32 u32Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Creates a `TUint16` variable form an two elements `au8Array`.
    //!
    //! The function copies two values form the array to the returned unsigned int.
    //! 
    //! ### For example
    //! an input array of `au8Array[0]=0b00011100,au8Array[1]=0b00011011`
    //! returns: `0b0001101100011100`
    //!
    //! @sa	    i16CopyFromArr, u32CopyFromArr, i32CopyFromArr
    //! @param[in]  au8Array 	an array with two char elements. 
    //! @return     `TUint16` 	a unsigned int value.
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CopyFromArr( TUint8 au8Array[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create a `TInt16` variable form an two elements `au8Array`.
    //!
    //! The function copies two values form the array to the returned int.
    //! 
    //! ### For example
    //! an input array of `au8Array[0]=0b00011100,au8Array[1]=0b00011011`
    //! returns: `0b0001101100011100`
    //!
    //! @sa	    u16CopyFromArr, u32CopyFromArr, i32CopyFromArr
    //! @param[in]  au8Array 	an array with two char elements. 
    //! @return     `TInt16` 	an int value.
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CopyFromArr( TUint8 au8Array[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create a `TUint32` variable form an four elements `au8Array`.
    //!
    //! The function copies four values form the array to the returned unsigned long. 
    //! 
    //! @sa	    u16CopyFromArr, i16CopyFromArr, i32CopyFromArr
    //! @param[in]  au8Array 	array with four char elements.
    //! @return     `TUint32` 	a unsigned long value. 
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CopyFromArr( TUint8 au8Array[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create a `TInt32` variable form an four elements `au8Array`.
    //!
    //! The function copies four values form the array to the returned long value.
    //! 
    //! @sa	    u16CopyFromArr, i16CopyFromArr, u32CopyFromArr
    //! @param[in]  au8Array 	array with four char elements.
    //! @return     TInt32 	a long value.
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32CopyFromArr( TUint8 au8Array[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Fill a `au8Adr[2]` array from a `TUint16` variable.
    //!
    //! The function copies the bytes from the unsigned int to the elements of an array.
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `u16Val=0xFFFE`
    //! returns au8Adr[0]=0xFE
    //! returns au8Adr[1]=0xFF
    //!
    //! @sa         vCopyI16toArr, vCopyU32toArr, vCopyI32toArr
    //! @param[in]  u16Val      unsigned int value.
    //! @param[out] au8Adr      Pointer to a `TUint8` array with two byte elements.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCopyU16toArr( TUint16 u16Val, TUint8 au8Adr[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Fill a `au8Adr[2]` array from a `TInt16` variable.
    //!
    //! The function copies the bytes from the unsigned int to the array
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `i16Val=0xFFFE`
    //! returns au8Adr[0]=0xFE
    //! returns au8Adr[1]=0xFF
    //!
    //! @sa         vCopyU16toArr, vCopyU32toArr, vCopyI32toArr
    //! @param[in]  i16Val      int value.
    //! @param[out] au8Adr      Pointer to a 2 `TUint8` array with two byte elements.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCopyI16toArr( TInt16 i16Val, TUint8 au8Adr[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief     Fill a `au8Adr[4]` array from a `TUint32` variable.
    //!
    //! The function copies the bits from the unsigned long to the array.
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `u32Val=0xFFFEAA01`
    //! returns au8Adr[0]=0x01
    //! returns au8Adr[1]=0xAA
    //! returns au8Adr[2]=0xFE
    //! returns au8Adr[3]=0xFF
    //!
    //! @sa         vCopyU16toArr, vCopyI16toArr, vCopyI32toArr
    //! @param[in]  u32Val      unsigned long values.
    //! @param[out] au8Adr      pointer to a 4 `TUint8` array with four byte elements.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCopyU32toArr( TUint32 u32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Fill a `au8Adr[4]` array from a `TInt32` variable.
    //!
    //! The function copies the bits from the long to the array.
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `i32Val=0xFFFEAA01`
    //! returns au8Adr[0]=0x01
    //! returns au8Adr[1]=0xAA
    //! returns au8Adr[2]=0xFE
    //! returns au8Adr[3]=0xFF
    //!
    //! @sa         vCopyU16toArr, vCopyI16toArr, vCopyU32toArr
    //! @param[in]  i32Val      long value.
    //! @param[out] au8Adr      pointer to a 4 `TUint8` array with four byte elements.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vCopyI32toArr( TInt32 i32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Swap = exchange the high and low bytes of a unsigned int.
    //!
    //! The function swaps the bytes of a unsigned int variable.
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `u16Val=0b00010101`
    //! returns `0b01010001`
    //!
    //! @sa          u32Swap, u64Swap
    //! @param[in]   u16Val     unsigned int. 
    //! @return      unsigned int with swapped bits. 
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16Swap( TUint16 u16Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Swap = exchange the high and low shorts of a unsigned long.
    //!
    //! The function swaps the high and low shorts of a unsigned long value.
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `u32Val=0b11111111000000001111111100001111`
    //! returns `0b11111111000011111111111100000000`
    //!
    //! @sa          u16Swap, u64Swap
    //! @param[in]   u32Val - a unsigned long.  
    //! @return unsigned long with swapped bits.
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32Swap( TUint32 u32Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief       Swap  = exchange the high and low long of a unsigned long long variable. 
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### For example
    //! an input value of `u64Val=0b111111111111111111111111111111111111111111111111111111111000111`
    //! returns `0b111111111111111111111111110001111111111111111111111111111111111`
    //! 
    //! @sa          u16Swap, u32Swap
    //! @param[in]   u64Val - a unsigned long, long.
    //! @return a unsigned long long with swapped bits. 
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64Swap( TUint64 u64Val );

// (A1) CAN Functions (Implicit automatic convert to the system [INTEL/MOTOROLA])

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TUint16` form an `au8Array` with two elements. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         i16ConvFromCanArr, u32ConvFromCanArr, i32ConvFromCanArr, f32ConvFromCanArr
    //! @param[in]  au8Array with two elements.
    //! @return     `TUint16` unsigned int value.
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16ConvFromCanArr( TUint8 au8Array[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TInt16` form `au8Array` with two elements. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         u16ConvFromCanArr, u32ConvFromCanArr, i32ConvFromCanArr, f32ConvFromCanArr
    //! @param[in]  au8Array with two elements.
    //! @return     `TInt16` int value.
    //-------------------------------------------------------------------------------------------------
    extern TInt16 i16ConvFromCanArr( TUint8 au8Array[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TUint32` form `au8Array` with four elements. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         u16ConvFromCanArr, i16ConvFromCanArr, i32ConvFromCanArr, f32ConvFromCanArr
    //! @param[in]  au8Array with four elements.
    //! @return     `TUint32` unsigned long value.
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32ConvFromCanArr( TUint8 au8Array[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TInt32` form `au8Array` with four elements. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         u16ConvFromCanArr, i16ConvFromCanArr, u32ConvFromCanArr, f32ConvFromCanArr
    //! @param[in]  au8Array with four elements.
    //! @return     `TInt32` long value.
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32ConvFromCanArr( TUint8 au8Array[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TUint64` form `au8Array` with eight elements.
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         u16ConvFromCanArr, i16ConvFromCanArr, i32ConvFromCanArr, f32ConvFromCanArr
    //! @param[in]  au8Array with eight elements.
    //! @return     `TUint64` unsigned long long value.
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64ConvFromCanArr( TUint8 au8Array[8] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TInt64` form `au8Array` with eight elements.
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         u16ConvFromCanArr, i16ConvFromCanArr, u32ConvFromCanArr, f32ConvFromCanArr
    //! @param[in]  au8Array with eight elements.
    //! @return     `TInt64` long long value.
    //--------------------------------------------------------------------------------------------------
    extern TInt64 i64ConvFromCanArr( TUint8 au8Array[8] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create `TFloat32` form `au8Array` with four elements. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         u16ConvFromCanArr, i16ConvFromCanArr, u32ConvFromCanArr, i32ConvFromCanArr
    //! @param[in]  au8Array with four elements.
    //! @return     `TFloat32` float value.
    //--------------------------------------------------------------------------------------------------
    extern TFloat32 f32ConvFromCanArr( TUint8 au8Array[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of a `TUint16` variable into a two elements of a `TUint8` array. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvI16toCanArr, vConvI32toCanArr, vConvU32toCanArr, vConvF32toCanArr
    //! @param[in]  u16Val unsigned long value
    //! @param[out] au8Adr pointer to a 2 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvU16toCanArr( TUint16 u16Val, TUint8 au8Adr[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of `TInt16` variable into a two elements of a `TUint8` array. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvU16toCanArr, vConvI32toCanArr, vConvU32toCanArr, vConvF32toCanArr
    //! @param[in]  i16Val   long value.
    //! @param[out] au8Adr   pointer to a 2 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvI16toCanArr( TInt16 i16Val, TUint8 au8Adr[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of `TUint32` variable into a four elements of a `TUint8` array.
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvU16toCanArr, vConvI16toCanArr, vConvI32toCanArr, vConvF32toCanArr
    //! @param[in]  u32Val   unsigned long long value.
    //! @param[out] au8Adr   pointer to a 4 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvU32toCanArr( TUint32 u32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of `TInt32` variable into a four elements of a `TUint8` array.
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvU16toCanArr, vConvI16toCanArr, vConvU32toCanArr, vConvF32toCanArr
    //! @param[in]  i32Val  long long value.
    //! @param[in]  au8Adr  pointer to a 4 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvI32toCanArr( TInt32 i32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of `TFloat32` variable into a four elements of a `TUint8` array. 
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvU16toCanArr, vConvI16toCanArr, vConvI32toCanArr, vConvU32toCanArr
    //! @param[in]  f32Val  float value.
    //! @param[in]  au8Adr  pointer to a 4 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvF32toCanArr( TFloat32 f32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of `TUint64` variable into a eight elements of a `TUint8` array.
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvU16toCanArr, vConvI16toCanArr, vConvU32toCanArr, vConvI32toCanArr, vConvF32toCanArr
    //! @param[in]  u64Val   unsigned long long value.
    //! @param[out] au8Adr   pointer to a 8 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvU64toCanArr( TUint64 u64Val, TUint8 au8Adr[8] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Copy of `TInt64` variable into a eight elements of a `TUint8` array.
    //!
    //! *Reason*: Automatic conversion between INTEL/MOTOROLA system.
    //!
    //! @sa         vConvU16toCanArr, vConvI16toCanArr, vConvU32toCanArr, vConvF32toCanArr
    //! @param[in]  i64Val  long long value.
    //! @param[in]  au8Adr  pointer to a 8 `TUint8` array.
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvI64toCanArr( TInt64 i64Val, TUint8 au8Adr[8] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap = exchange high- and low-byte of a `TUint16` variable.
    //!
    //! @sa i16ConvCanDat, u32ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  pu8Adr      pointer to an `TUint8` array with 2 bytes.
    //! @return     u16Ret	unsigned short.
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16ConvCanDat( ECanFormat eFormat, TUint8* pu8Adr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap = exchange high- and low-byte of  a `TInt16` variable.
    //!
    //! @sa u16ConvCanDat, u32ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  pu8Adr      pointer to an `TUint8` array with 2 bytes.
    //! @return     i16Ret	signed short.
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16ConvCanDat( ECanFormat eFormat, TUint8* pu8Adr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap = exchange high- and low-byte of a `TUint32` variable.
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  pu8Adr      pointer to an `TUint8` array with 4 bytes.
    //! @return     uAto.u32    Result
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32ConvCanDat( ECanFormat eFormat, TUint8* pu8Adr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap = exchange high- and low-byte of a `TInt32` variable.
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, u32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat 	CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  pu8Adr  	pointer to an `TUint8` array with 4 bytes.
    //! @return     i32Ret  	Result
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32ConvCanDat( ECanFormat eFormat, TUint8* pu8Adr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap = exchange high- and low-byte of a `TUint64` variable.
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  pu8Adr      pointer to an `TUint8` array with 8 bytes.
    //! @return     uAto.u64    Result
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64ConvCanDat( ECanFormat eFormat, TUint8* pu8Adr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap = exchange high- and low-byte of a `TInt64` variable.
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, u32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  pu8Adr      pointer to an `TUint8` array with 8 bytes.
    //! @return     i64Ret      Result
    //--------------------------------------------------------------------------------------------------
    extern TInt64 i64ConvCanDat( ECanFormat eFormat, TUint8* pu8Adr );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap a `TUint16` variable.
    //!
    //! --------------------------------------------------------------------------------
    //! ### Example for the DATA_INTEL eFormat
    //! an input value of `u16Val=0b0010111110000111` # Dec 12167, 0x2F87
    //! returns: `au8Adr[0] = 0b10000111` and
    //!          `au8Adr[1] = 0b00101111`
    //!
    //! ### Example for the DATA_MOTOROLA eFormat
    //! an input value of `u16Val=0b0010111110000111` # Dec 12167, 0x2F87
    //! returns: `au8Adr[0] = 0b00101111` and
    //!          `au8Adr[1] = 0b10000111`
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, u32ConvCanDat, i32ConvCanDat, vConvI16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  u16Val      unsigned short
    //! @param[out] au8Adr      Pointer to a 2 TUint8 array
    //! @return     NULL

    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvU16toCanDat( ECanFormat eFormat, TUint16 u16Val, TUint8 au8Adr[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap a `TInt16` variable.
    //!
    //! --------------------------------------------------------------------------------
    //! ### Example for the DATA_INTEL eFormat
    //! an input value of `i16Val=0b0010111110000111` # Dec 12167, 0x2F87
    //! returns: `au8Adr[0] = 0b10000111` and
    //!          `au8Adr[1] = 0b00101111`
    //!
    //! ### Example for the DATA_MOTOROLA eFormat
    //! an input value of `i16Val=0b0010111110000111` # Dec 12167, 0x2F87
    //! returns: `au8Adr[0] = 0b00101111` and
    //!          `au8Adr[1] = 0b10000111`
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, u32ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvU32toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  i16Val      signed short
    //! @param[out] au8Adr      Pointer to a 2 TUint8 array
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvI16toCanDat( ECanFormat eFormat, TInt16  i16Val, TUint8 au8Adr[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap a `TUint32` variable.
    //!
    //! --------------------------------------------------------------------------------
    //! ### Example for the DATA_INTEL eFormat
    //! an input value of `u32Val=0b11111111111111111010010001100000` # Dec 4294943840, Hex 0xffffa460
    //! returns: `au8Adr[0] = 0b01100000`
    //!          `au8Adr[1] = 0b10100100`
    //!          `au8Adr[2] = 0b11111111` and
    //!          `au8Adr[3] = 0b11111111`
    //!
    //! ### Example for the DATA_MOTOROLA eFormat
    //! an input value of `u32Val=0b0010111110000111` # Dec 4294943840, 0xffffa460
    //! returns: `au8Adr[0] = 0b11111111`
    //!          `au8Adr[1] = 0b11111111`
    //!          `au8Adr[2] = 0b10100100` and
    //!          `au8Adr[3] = 0b01100000`
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, u32ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvI32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  u32Val      unsigned long
    //! @param[out] au8Adr      Pointer to a 4 TUint8 array
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvU32toCanDat( ECanFormat eFormat, TUint32 u32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap a `TInt32` variable.
    //!
    //! --------------------------------------------------------------------------------
    //! ### Example for the DATA_INTEL eFormat
    //! an input value of `i32Val=0b11111111111111111010010001100000` # Dec 4294943840, Hex 0xffffa460
    //! returns: `au8Adr[0] = 0b01100000`
    //!          `au8Adr[1] = 0b10100100`
    //!          `au8Adr[2] = 0b11111111` and
    //!          `au8Adr[3] = 0b11111111`
    //!
    //! ### Example for the DATA_MOTOROLA eFormat
    //! an input value of `i32Val=0b0010111110000111` # Dec 4294943840, 0xffffa460
    //! returns: `au8Adr[0] = 0b11111111`
    //!          `au8Adr[1] = 0b11111111`
    //!          `au8Adr[2] = 0b10100100` and
    //!          `au8Adr[3] = 0b01100000`
    //!
    //! @sa u16ConvCanDat, i16ConvCanDat, u32ConvCanDat, i32ConvCanDat, vConvU16toCanDat, vConvI16toCanDat, vConvU32toCanDat
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  i32Val      signed long
    //! @param[out] au8Adr[]    Pointer to a 4 TUint8 array
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvI32toCanDat( ECanFormat eFormat, TInt32 i32Val, TUint8 au8Adr[4] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap a `TUint64` variable.
    //! @param[in]  eFormat    CAN Format  DATA_INTEL or MSB_FORMAT
    //! @param[in]  u64Val     u64 Value
    //! @param[out] au8Adr     Pointer to 8 TUint8 array
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvU64toCanDat( ECanFormat eFormat, TUint64 u64Val, TUint8 au8Adr[8] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Swap a `TInt64` variable.
    //! @param[in]  eFormat    CAN Format  DATA_INTEL or MSB_FORMAT
    //! @param[in]  i64Val     i64 Value
    //! @param[out] au8Adr     Pointer to 8 TUint8 array
    //--------------------------------------------------------------------------------------------------
    extern TVoid vConvI64toCanDat( ECanFormat eFormat, TInt64 i64Val, TUint8 au8Adr[8] );

// (B1) Functions for conversion to type "unsigned integer u8"

    //--------------------------------------------------------------------------------------------------
    //! @brief      Convert "bo" to real boolean 1=>TRUE, else FALSE
    //! @param[in]  boVar       0...255 (reason TBoolean is no real data type )
    //! @return     TBoolean    only FALSE, TRUE
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boCastBo( TBoolean boVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned integer `u8Var` to a signed integer `i8Var`
    //!
    //! @sa i8CastI16, i8CastU16, i8CastI32, i8CastU32
    //! @param[in]  u8Var       unsigned byte
    //! @return     TInt8       Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8CastU8( TUint8 u8Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a signed integer `i16Var` to a signed integer `i8Var`
    //!
    //! @sa i8CastU8, i8CastU16, i8CastI32, i8CastU32
    //! @param[in]  i16Var      signed short
    //! @return     TInt8       Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8CastI16( TInt16 i16Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a signed integer `u16Var` to a signed integer `i8Var`
    //!
    //! @sa i8CastU8, i8CastI16, i8CastU16, i8CastI32, i8CastU32
    //! @param[in]  u16Var      unsigned short
    //! @return     TInt8       Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8CastU16( TUint16 u16Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a signed integer `i32Var` to a signed integer `i8Var`
    //!
    //! @sa i8CastU8, i8CastI16, i8CastI32, i8CastU32
    //! @param[in]  i32Var      signed long 
    //! @return     TInt8       Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8CastI32( TInt32 i32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a signed integer `u32Var` to a signed integer `i8Var`
    //!
    //! @sa i8CastU8, i8CastI16, i8CastU16, i8CastI32
    //! @param[in]  u32Var      unsigned long
    //! @return     TInt8       Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8CastU32( TUint32 u32Var );


// (B2) Functions that converts (by C type casting) the parameter to the type unsigned byte `u8Var`

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a byte `i8Var` to a unsigned byte `u8Var`
    //!
    //! @sa u8CastI16, u8CastU16, u8CastI32, u8CastU32
    //! @param[in]  i8Var       signed byte
    //! @return     TUint8      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CastI8( TInt8 i8Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a short `i16Var` to a unsigned byte `u8Var`
    //!
    //! @sa u8CastI8, u8CastI16, u8CastI32, u8CastU32
    //! @param[in]  i16Var      signed short
    //! @return     TUint8      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CastI16( TInt16  i16Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned short `u16Var` to a unsigned byte `u8Var`
    //!
    //! @sa u8CastI8, u8CastI16, u8CastI32, u8CastU32
    //! @param[in]  u16Var      unsigned short
    //! @return     TUint8      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CastU16( TUint16 u16Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a long `i32Var` to a unsigned byte `u8Var`
    //!
    //! @sa u8CastI8, u8CastI16, u8CastU16, u8CastU32
    //! @param[in]  i32Var      signed long
    //! @return     TUint8      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8CastI32 ( TInt32  i32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned long `u32Var` to a unsigned byte `u8Var`
    //!
    //! @sa u8CastI8, u8CastI16, u8CastU16, u8CastI32
    //! @param[in]  u32Var      unsigned long
    //! @return     TUint8      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint8  u8CastU32( TUint32 u32Var );

// (B3) Functions that converts (by C type casting) the parameter to the type signed integer `i16Var`

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned short `u16Var` to a signed short `i16Var`
    //!
    //! @sa i16CastI32, i16CastU32
    //! @param[in]  u16Var      unsigned short
    //! @return     TInt16      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CastU16( TUint16 u16Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a long `i32Var` to a signed short `i16Var`
    //!
    //! @sa i16CastU16, i16CastU32
    //! @param[in]  i32Var      long
    //! @return     TInt16      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CastI32( TInt32  i32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned long `u32Var` to a signed short `i16Var`
    //!
    //! @sa i16CastU16, i16CastI32
    //! @param[in]  u32Var      long long
    //! @return     TInt16      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CastU32( TUint32 u32Var );

// (B4) Functions that converts (by C type casting) the parameter to a unsigned short `u16Var`

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a signed short `i16Var` to a unsigned short `u16Var`
    //!
    //! @sa u16CastI32, u16CastU32, u16CastU64
    //! @param[in]  i16Var      short
    //! @return     TUint16     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CastI16( TInt16  i16Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a long `i32Var` to a unsigned short `u16Var`
    //!
    //! @sa u16CastI16, u16CastU32, u16CastU64
    //! @param[in]  i32Var      long
    //! @return     TUint16     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint16  u16CastI32( TInt32  i32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned long `u32var` to a unsigned short `u16Var`
    //!
    //! @sa u16CastI16, u16CastI32, u16CastU64
    //! @param[in]  u32Var      unsigned long
    //! @return     TUint16     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint16  u16CastU32( TUint32 u32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief Combined cast with offset calculation.
    //!        Moves the input value from range [I16_MIN, I16_MAX]
    //!        of i32Var to value range [U16_MIN, U16_MAX] and saturates out of range input values at these
    //!        TUint16 limits.
    //! @param[in] i32Var   TInt32
    //! @return TUint16     Result of Assignment:
    //!     - i32Var > I16_MAX: U16_MAX
    //!     - i32Var < I32_MIN: 0
    //!     - else:             i32Var+U16_OFFSET
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CastOffsetI32(TInt32 i32Var);

    //--------------------------------------------------------------------------------------------------
    //! @brief Combined cast with offset calculation.
    //!        Moves the input value from range [U16_MIN U16_MAX]
    //!        of u16Var to value range [I16_MIN, I16_MAX]
    //! @param[in]  u16Var      TUint16
    //! @return     TInt16      u16Var- U16_OFFSET
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CastOffsetU16(TUint16 u16Var);

    //--------------------------------------------------------------------------------------------------
    //! @brief Combined cast with offset calculation.
    //!        Moves the input value from range [U16_MIN U16_MAX]
    //!        of u16Var to value range [I16_MIN, I16_MAX]
    //! @param[in]  u16Var      TUint16
    //! @return     TInt32      Result of assignment:
    //!     - u16Var == 0:          I16_MIN
    //!     - u16Var == U16_MAX:    I16_MAX
    //!     - else:                 u16Var-U16_OFFSET
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32CastOffsetU16(TUint16 u16Var);

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned long long `u64var` to a unsigned short `u16Var`
    //!
    //! @sa u16CastI16, u16CastI32, u16CastU32
    //! @param[in]  u64Var      unsigned long long
    //! @return     TUint16     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint16  u16CastU64( TUint64 u64Var );

// (B5) Functions that converts (by C type casting) the parameter to a unsigned long `TUint32`

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a short `i16Var` to a unsigned long `TUint32`
    //!
    //! @sa u32CastI32, u32CastU64, u32CastI64
    //! @param[in]  i16Var      short
    //! @return     TUint32     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint32  u32CastI16( TInt16  i16Var );
    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a long `i32Var` to a unsigned long `TUint32`
    //!
    //! @sa u32CastI16, u32CastU64, u32CastI64
    //! @param[in]  i32Var      long
    //! @return     TUint32     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint32  u32CastI32( TInt32  i32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned long long `u64var` to a unsigned long `TUint32`
    //!
    //! @sa u32CastI16, u32CastI32, u32CastI64
    //! @param[in]  u64Var      unsigned long long
    //! @return     TUint32     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CastU64( TUint64 u64Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a long long `i64Var` to a unsigned long `TUint32`
    //!
    //! @sa u32CastI16, u32CastI32, u32CastU64
    //! @param[in]  i64Var      long long
    //! @return     TUint32     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CastI64( TInt64 i64Var );

// (B6) Functions that convert (by C type casting) the parameter to a signed long `Tint32` or a unsigned long long `TUint64`

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a unsigned long `u32Var` to a long `Tint32`
    //!
    //! @sa i32CastI64, u64CastI64
    //! @param[in]  u32Var      long
    //! @return     TInt16      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32CastU32( TUint32 u32Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief      *C type casting:* convert a long long `i64Var` to a long `TInt32`
    //!
    //! @sa i32CastU32, u64CastI64
    //! @param[in]  i64Var      long long
    //! @return     TInt16      Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32CastI64( TInt64  i64Var );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Assign Long Long "i64Var" to Float "f32Var"
    //! @param[in]  i64Var      LongLong Variable
    //! @return     TFloat32    Result of Assignment
    //--------------------------------------------------------------------------------------------------
    extern TFloat32 f32CastI64(TInt64 i64Var);

    //--------------------------------------------------------------------------------------------------
    //! @brief  *C type casting:* convert a long long `i64Var` to a unsigned long long `TUint64`
    //!
    //! @sa i32CastU32, i32CastI64
    //! @param[in]  i64Var      long long
    //! @return     TUint64     Result of the assignment
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64CastI64(TInt64 i64Var);

    //--------------------------------------------------------------------------------------------------
    //! @brief  Cast TUInt64 "u64Var" to TInt64
    //! @param[in]  u64Var      unsigned long long Variable
    //! @return     TInt64      Result has range[0,I64_MAX]
    //--------------------------------------------------------------------------------------------------
    extern TInt64 i64CastU64( TUint64 u64Var );


// (C1) Functions for bit manipulation 

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the state `boState` at bit position `u8Pos` of the variable `pu8RetVar`
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu8RetVar = 0x5f = 95 = 1011111`
    //! the position of the bit `u8Pos = 1`
    //! the state of the bit `boState = 0`
    //! returns: `pu8RetVar = 0x5d = 93 = 1011101`
    //! 
    //! @sa vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Position of the bit
    //! @param[in]  boState     State of bit
    //! @param[out] pu8RetVar   the unsigned byte variable with the bitmaks to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet1BitU8( TUint8 u8Pos, TBoolean boState, TUint8 *pu8RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set state `u8State` of 2 bits at position `u8Pos` of the variable `pu8RetVar`
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu8RetVar = 0x5f = 95 = 1011111`
    //! the position of the bit `u8Pos = 2`
    //! the state of the bit `bi2State = 1`
    //! returns: `pu8RetVar = 0x5b = 91 = 1011011`
    //! 
    //! @sa vSet1BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the 2 bits
    //! @param[in]  bi2State    State of the 2 bits
    //! @param[out] pu8RetVar   the unsigned byte variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet2BitU8( TUint8 u8Pos, TBit2 bi2State, TUint8  *pu8RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set state `u8State` of 3 bits at position `u8Pos` in u8 variable `pu8RetVar`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu8RetVar = 0x5f = 95 = 1011111`
    //! the position of the bit `u8Pos = 2`
    //! the state of the bit `bi3State = 1`
    //! returns: `pu8RetVar = 0x53 = 83 = 1010011`
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the 3 bits
    //! @param[in]  bi3State    State of the 3 bits
    //! @param[out] pu8RetVar   the unsigned byte variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet3BitU8( TUint8 u8Pos, TBit3  bi3State, TUint8  *pu8RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set state `u8State` of 4 bits at position `u8Pos` in u8 variable `pu8RetVar`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu8RetVar = 0x5f = 95 = 1011111`
    //! the position of the bit `u8Pos = 2`
    //! the state of the bit `bi4State = 1`
    //! returns: `pu8RetVar = 0x43 = 67 = 1000011`
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the 4 bits
    //! @param[in]  bi4State    State of the 4 bits
    //! @param[out] pu8RetVar   the unsigned byte variable with the bitmask to be manipulate 
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet4BitU8( TUint8 u8Pos, TBit4 bi4State, TUint8  *pu8RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set state `u8State` of 5 bits at position `u8Pos` in u8 variable `pu8RetVar`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu8RetVar = 0x5f = 95 = 1011111`
    //! the position of the bit `u8Pos = 2`
    //! the state of the bit `bi5State = 1`
    //! returns: `pu8RetVar = 0x43 = 67 = 1000011`
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the 5 bits
    //! @param[in]  bi5State    State of the 5 bits
    //! @param[out] pu8RetVar   the unsigned byte variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet5BitU8( TUint8 u8Pos, TBit5 bi5State, TUint8  *pu8RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set state `u8State` of the bits at position `u8StartPos` in short variable `pu16RetVar`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu16RetVar = 0xFFFF = 65535 = 1111111111111111`
    //! the position of the bit `u8Pos = 3`
    //! the state of the bit `boState = 0`
    //! returns: `pu16RetVar = 0xFFF7 = 65527 = 1111111111110111`
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos        Start position of the 1 bit
    //! @param[in]  boState      State of bit
    //! @param[in]  pu16RetVar   the unsigned short variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet1BitU16( TUint8 u8Pos, TBoolean boState,  TUint16 *pu16RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set state `bState` of 2 bits at position  `bStartPos` in short variable `pu16RetVar`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `pu16RetVar = 0xFFFF = 65535 = 1111111111111111`
    //! the position of the bit `u8Pos = 1`
    //! the state of the bit `boState = 0 = 00`
    //! returns: `pu8RetVar = 0xFFF9 = 65529 = 1111111111111001`
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos        Start position of the 2 bits
    //! @param[in]  bi2State     State of the 2 bit (TRUE/FALSE)
    //! @param[out] pu16RetVar   the unsigned short variable with the bitmask to be manipulate 
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
     extern TVoid vSet2BitU16( TUint8 u8Pos, TBit2 bi2State, TUint16 *pu16RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the state of the bit `u8State` at position `u8StartPos` in long variable `pu32RetVar`. 
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the bit 
    //! @param[in]  boState     State of the bits
    //! @param[out] pu32RetVar  the unsigned long variable with the bitmask to be manipulate 
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet1BitU32( TUint8 u8Pos, TBoolean boState,  TUint32 *pu32RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the state of the 2 bit `u8State` at position `u8StartPos` in long variable `pu32RetVar`. 
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the bit
    //! @param[in]  bi2State    State of the 2 bits
    //! @param[out] pu32RetVar  the unsigned long variable with the bitmask to be manipulate 
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet2BitU32( TUint8 u8Pos, TBit2 bi2State, TUint32 *pu32RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the state of the bit `u8State` at position `u8StartPos` in the long long variable `pu64RetVar`.
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the bit
    //! @param[in]  boState     State of the bits
    //! @param[out] pu64RetVar  the unsigned long long variable with the bitmask to be manipulate 
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet1BitU64( TUint8 u8Pos, TBoolean boState, TUint64 *pu64RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Set the state of the bit `u8State` at position `u8Pos` in the TUint32-Array[2].
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos        Start position of the bit
    //! @param[in]  boState      State of the bits
    //! @param[in,out] au32Array    the two value long array with the bitmask to be manipulate 
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet64BitAu32( TUint8 u8Pos, TBoolean boState, TUint32 au32Array[2] );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Set the state of 2 bit `u8State` at position `u8Pos` in the long long variable `pu64RetVar`. 
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the bit 
    //! @param[in]  bi2State    State of the 2 bits
    //! @param[out] pu64RetVar  the unsigned long long variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSet2BitU64( TUint8 u8Pos, TBit2 bi2State, TUint64 *pu64RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Set the state of bits `u32Value` at position `u8Pos` for the number `u8size` of bits in the long variable `pu32RetVar`.
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  u8Pos       Start position of the bit
    //! @param[in]  u8Size      Number of bits to be set
    //! @param[in]  u32Value    State of the bits 
    //! @param[out] pu32RetVar  the unsigned long variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSetxBitU32( TUint8 u8Pos, TUint8 u8Size, TUint32 u32Value, TUint32 *pu32RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Set the state `u32Value` of `u8size` of bits from start position `u8Pos` of the long long variable `pu64RetVar` that use the CAN bus format `eFormat`.
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, u32GetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  u8Pos       Start position of the bit
    //! @param[in]  u8Size      Number of bits to be set
    //! @param[in]  u32Value    State of the bits
    //! @param[out] pu64RetVar  the unsigned long variable with the bitmask to be manipulate
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vSetxBitU64( ECanFormat eFormat, TUint8 u8Pos, TUint8 u8Size, TUint32 u32Value, TUint64 *pu64RetVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Get the state of `u8Size` bits from start position `u8Pos` of the long long variable `u64InpVar` that use the CAN bus format `eFormat`.
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, vValConvertToBinaere, u32GetValueInvBits
    //! @param[in]  eFormat     CAN format DATA_INTEL or DATA_MOTOROLA, call it `ECanFormat.DATA_MOTOROLA` or `ECanFormat.DATA_INTEL`.
    //! @param[in]  u8Pos       Start position of the bit
    //! @param[in]  u8Size      Number of bits to get the state
    //! @param[in]  u64InpVar   inputVariable
    //! @return     TUint32     state of size bits
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32GetxBitU64( ECanFormat eFormat, TUint8 u8Pos, TUint8 u8Size, TUint64 u64InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Converts the value `u64Val` to a string that represents the binary format of the value and a second string that represents the positions of this binary string.
    //! -------------------------------------------------------------------------------- 
    //! The input `u64val` is a unsigned long long. 
    //! The parameter `pchBin` is a pointer to the output string. The string ist terminated with NULL. 
    //! The maximum value for 0xFFFFFFFFFFFFFFFF is "1111111111111111111111111111111111111111111111111111111111111111" 
    //! The parameter `pchPos` is a pointer to the string with the bit position of every character. The string is terminated with NULL. 
    //! The maximum value for 64 bits is: "321F987654321E987654321D987654321C987654321B987654321A9876543210"
    //! A stands for the bit 10 , B for the bit 20, C for the bit 30, D for the bit 40, E for the bit 50, and F for the bit 60
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value `u64Val = 0x93B86F12 = 2478337810 = 0xb10010011101110000110111100010010`
    //! the pointer `pchBin` points to a string "10010011101110000110111100010010\0".
    //! the pointer `pchPos` points to a string "1C987654321B987654321A9876543210\0" 
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, u32GetValueInvBits
    //! @param[in]   u64Val  - a unsigned long long value
    //! @param[out]  pchBin  - Output String [String lenght TChar achOut[65] -> 64 bits + NULL]  '0' ... '0' '1' '1'
    //! @param[out]  pchPos  - Output String [String lenght TChar achOut[65] -> 64 bits + NULL]   n  ...  2   1   0
    //!                      - NULL don't create a number field
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vValConvertToBinaere( TUint64 u64Val, TChar *pchBin, TChar *pchPos);

    //--------------------------------------------------------------------------------------------------
    //! @brief  Return the invert of the long parameter `u32Val` for the given number of bits `u8Size`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 1
    //! an input value `u32Val = 0x93B86F12 = 2478337810 = 0xb10010011101110000110111100010010`
    //! the count of bits to invert `u8Size = 32`, that means all bit will be inverted.
    //! the return value `TUint32 is 0x6c4790ed = 1816629485 = 0x0b01101100010001111001000011101101`
    //!
    //! ### Example 2
    //! Here is a simple example to show the goal of the function more clearly: 
    //! The input value `u32Val = 0xFFFFFFFF`
    //! The count of invert bits `u8Size = 32`
    //! The return value `TUint32 = 0x0`
    //!
    //! @sa vSet1BitU8, vSet2BitU8, vSet3BitU8, vSet4BitU8, vSet5BitU8, vSet1BitU16, vSet2BitU16, vSet1BitU32, vSet2BitU32, vSet1BitU64, vSet64BitAu32, vSet2BitU64, vSetxBitU32, vSetxBitU64, u32GetxBitU64, vValConvertToBinaere
    //! @param[in]  u32Val      value
    //! @param[in]  u8Size      the count of invert bits
    //! @return     TUint32     invert value
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32GetValueInvBits( TUint32 u32Val, TUint8 u8Size );

// (C2) Functions that returns bits

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of the bit on position `u8Pos` of a byte value `u8InpVar`.
    //!
    //! @sa bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Position of the requested bit 
    //! @param[in]  u8InpVar    Byte value to be checked for the requested bit
    //! @return     TUint8      State of the requested bit
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGet1BitU8( TUint8 u8Pos, TUint8 u8InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of 2 bits on position `u8Pos` of a byte value `u8InpVar`.
    //!
    //! @sa boGet1BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the 2 requested bits
    //! @param[in]  u8InpVar    Byte value to be checked for the requested bits
    //! @return     TUint8      State of the requested 2 bits
    //--------------------------------------------------------------------------------------------------
    extern TBit2 bi2Get2BitU8( TUint8 u8Pos, TUint8 u8InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of 3 bits on position `u8Pos` of a byte value `u8InpVar`.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! an input value of `u8InpVar = 11111111 = 255 = 0xFF`
    //! the start position of the bits to be checked `u8Pos = 0`
    //! returns: `TUint8 = 0x7 = 7 = 111`
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the 3 requested bits
    //! @param[in]  u8InpVar    Byte value to be checked for the requested bits
    //! @return     i      State of the requested 3 bits
    //--------------------------------------------------------------------------------------------------
    extern TBit3 bi3Get3BitU8( TUint8 u8Pos, TUint8 u8InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of 4 bits on position `u8Pos` of a byte value `u8InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the 4 requested bits 
    //! @param[in]  u8InpVar    Byte value to be checked for the requested bits
    //! @return     TUint8      State of the requested 4 bits
    //--------------------------------------------------------------------------------------------------
    extern TBit4 bi4Get4BitU8( TUint8 u8Pos, TUint8 u8InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of 5 bits on position `u8Pos` of a byte value `u8InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the 5 requested bits
    //! @param[in]  u8InpVar    Byte value to be checked for the requested bits
    //! @return     TUint8      State of the requested 5 bits
    //--------------------------------------------------------------------------------------------------
    extern TBit5 bi5Get5BitU8( TUint8 u8Pos, TUint8 u8InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of 6 bits on position `u8Pos` of a byte value `u8InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start Position of the 6 requested bits
    //! @param[in]  u8InpVar    Byte value to be checked for the requested bits
    //! @return     TUint8      State of the requested 6 bits
    //--------------------------------------------------------------------------------------------------
    extern TBit6 bi6Get6BitU8( TUint8 u8Pos, TUint8 u8InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of a bit on position `u8Pos` of a short value `u16InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the requested bit
    //! @param[in]  u16InpVar   Short value to be checked for the requested bit
    //! @return     TUint8      State of the bit
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGet1BitU16( TUint8 u8Pos, TUint16 u16InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of two bits on position `u8Pos` of a short value `u16InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the 2 requested bits
    //! @param[in]  u16InpVar   Short value to be checked for the requested bits 
    //! @return     TUint8      State of the requested 2 bits
    //--------------------------------------------------------------------------------------------------
    extern TBit2 bi2Get2BitU16( TUint8 u8Pos, TUint16 u16InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of a bit on position `u8Pos` of a long value `u32InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, bi2Get2BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start position of the requested bit
    //! @param[in]  u32InpVar   Long value to be checked for the requested bit
    //! @return     TUint8      State of the requested bit
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGet1BitU32( TUint8 u8Pos, TUint32 u32InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of 2 bits on position `u8Pos` of a long value `u32InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, boGet1BitU64, boGet1BitAU32
    //! @param[in]  u8Pos       Start Position of the requested bit 
    //! @param[in]  u32InpVar   Long value to be checked for the requested bits
    //! @return     TUint8      State of the bits requested bit
    //--------------------------------------------------------------------------------------------------
    extern TBit2 bi2Get2BitU32( TUint8 u8Pos, TUint32 u32InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the state of a bit on position `u8Pos` of a long long value `u64InpVar`.
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitAU32
    //! @param[in]  u8Pos       Start Position of the requested bit
    //! @param[in]  u64InpVar   Long long value to be checked for the requested bits
    //! @return     TBoolean    State of the requested bit
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGet1BitU64( TUint8 u8Pos, TUint64 u64InpVar );

    //--------------------------------------------------------------------------------------------------
    //! @brief Get the state of 1 bit of a long value array `au32InpVar[2]` at start position `u8Pos`.
    //! -------------------------------------------------------------------------------- 
    //! ### For example: 
    //! The following values are given: 
    //!   au32InpVar[0x93B77BB6,0x93B86F12] 
    //! in binary 
    //!   au32InpVar[0b10010011101101110111101110110110,0b10010011101110000110111100010010]
    //! u8Pos = 5
    //! The return value is 0
    //!
    //! @sa boGet1BitU8, bi2Get2BitU8, bi3Get3BitU8, bi4Get4BitU8, bi5Get5BitU8, bi6Get6BitU8, boGet1BitU16, bi2Get2BitU16, boGet1BitU32, bi2Get2BitU32, boGet1BitU64
    //! @param[in]  u8Pos       Start Position of the  requested bit
    //! @param[in]  au32InpVar  Long array to be checked for the requested bits
    //! @return     TBoolean    State of the requested bit
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boGet1BitAU32( TUint8 u8Pos, TUint32 au32InpVar[2] );


// (D1) More Functions

    //--------------------------------------------------------------------------------------------------
    //! @brief      Returns the Y short value to a given X value and a number of points by approximation over the given curve.
    //!
    //! -------------------------------------------------------------------------------- 
    //! Given is a array of X-values au16Px[] and X-values au16Py[] and the size of the field `u8Size`. 
    //! This values (X,Y) creates a curve. 
    //! For the given X-value (i16X) is done a approximation over this curve to find out the Y-value 
    //! that is returned by the function.
    //! -------------------------------------------------------------------------------- 
    //! ### For example: 
    //! The following values are given: au16Px[1,3,5,7,9], au16Py[1,3,5,7,9] u8Size == 5 
    //! The `i16X` value is 4.
    //! The `i16x` return value will be 4. 
    //!
    //! @sa i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i16X        X-value
    //! @param[in]  u8Size      field size
    //! @param[in]  au16Px[]    X-values (field)
    //! @param[in]  au16Py[]    Y-values (field)
    //! @return     i16Ret      Y-value
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16GetCurveY( TInt16 i16X, TUint8 u8Size, TUint16 au16Px[], TUint16 au16Py[] );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculate the absolute value of a signed byte `i8Val` (an input of -128 returns +127).
    //!
    //! @sa i16GetCurveY, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i8Val       a signed byte
    //! @return     iRetVal     absolute value of the input as signed byte
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8AbsI8( TInt8 i8Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculate the absolute value of a signed byte `i8Val` (an input of -128 returns +127).
    //!
    //! @sa i16GetCurveY, i8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i8Val       a signed byte
    //! @return     uRetVal     absolute value of the input as unsigned byte
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8AbsI8( TInt8 i8Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculate the absolute value of a signed short `i16Val` (an input of -128 returns +128).
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i16Val      a signed short
    //! @return     i16Ret      absolute value of the input as signed short
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16AbsI16( TInt16 i16Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Calculate the absolute value of a unsigned short `i16Val` (an input of -128 returns +128).
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i16Val      a signed short
    //! @return     u16Ret      absolute value of the input as signed short
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16AbsI16( TInt16 i16Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Calculate the absolute value of a signed long `i32Val` (an input of -128 returns +128).
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i32Val        a signed long
    //! @return     i32Ret        absolute value of the input as signed long
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32AbsI32( TInt32 i32Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Calculate the absolute value of a signed long `i32Val` (an input of -128 returns +128).
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i32Val        a signed long
    //! @return     u32Ret        absolute value of the input as unsigned long
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32AbsI32( TInt32 i32Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Calculate the absolute value of a signed long long `i64Val` (an input of -128 returns +128).
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i64Val        a signed long long 
    //! @return     i64Ret        absolute value of the input as signed long long
    //--------------------------------------------------------------------------------------------------
    extern TInt64 i64AbsI64( TInt64 i64Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Calculate the absolute value of a signed long long `i64Val` (an input of -128 returns +128).
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i64Val        a signed long long
    //! @return     u64Ret        absolute value of the input as unsigned long long 
    //--------------------------------------------------------------------------------------------------
    extern TUint64 u64AbsI64( TInt64 i64Val );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Compares the two given values A and B. Returns the smaller value.
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  u8A         input value A
    //! @param[in]  u8B         input value B
    //! @return     TUint8      Smaller value
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8Min2U8( TUint8 u8A, TUint8 u8B );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Two threshold values (`i8Min`, `i8Max`) and a test value (`i8Val`) are given. If the test value exceeds the threshold the neares threshold value is retuned otherwise the test value is returned. 
    //!
    //! For example: 
    //!  i8Min = 0  - minimum value of the threshold
    //!  i8Max = 10 - maximum value of the threshold
    //!  i8Val = 12 - test value
    //!  i8Ret = 10 - return value
    //!
    //! Note: If Min and Max are incorrectly swapped, the Min value is output as long as value <= Max, if this is not the case, the Min value is output.
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i8Val       test value as signed byte
    //! @param[in]  i8Min       minimum value of the threshold as signed byte
    //! @param[in]  i8Max       maximum value of the threshold as signed byte
    //! @return     i8Ret       return value as signed byte
    //--------------------------------------------------------------------------------------------------
    extern TInt8 i8RangeMinMax ( TInt8 i8Val, TInt8 i8Min, TInt8 i8Max );

    //--------------------------------------------------------------------------------------------------
    //! @brief  Two threshold values (`u8Min`, `u8Max`) and a test value (`u8Val`) are given. If the test value exceeds the threshold the neares threshold value is retuned otherwise the test value is returned.
    //!
    //! For example: 
    //!  u8Min = 0  - minimum value of the threshold
    //!  u8Max = 10 - maximum value of the threshold
    //!  u8Val = 12 - test value
    //!  u8Ret = 10 - return value
    //!
    //! Note: If Min and Max are incorrectly swapped, the Min value is output as long as value <= Max, if this is not the case, the Min value is output.
    //! 
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  u8Val       Check Value
    //! @param[in]  u8Min       Min Value
    //! @param[in]  u8Max       Max Value
    //! @return     u8Ret       limited value
    //--------------------------------------------------------------------------------------------------
    extern TUint8 u8RangeMinMax( TUint8 u8Val, TUint8 u8Min, TUint8 u8Max );

    //--------------------------------------------------------------------------------------------------
    //! @brief Two threshold values (`i16Min`, `i16Max`) and a test value (`i16Val`) are given. If the test value exceeds the threshold the neares threshold value is retuned otherwise the test value is returned.
    //!
    //! For example: 
    //!  i16Min = 0  - minimum value of the threshold
    //!  i16Max = 10 - maximum value of the threshold
    //!  i16Val = 12 - test value
    //!  i16Ret = 10 - return value
    //!
    //! Note: If Min and Max are incorrectly swapped, the Min value is output as long as value <= Max, if this is not the case, the Min value is output.
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, u16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  i16Val      Check Value
    //! @param[in]  i16Min      Min Value
    //! @param[in]  i16Max      Max Value
    //! @return     i16Ret      limited value
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16RangeMinMax( TInt16 i16Val, TInt16 i16Min, TInt16 i16Max );

    //--------------------------------------------------------------------------------------------------
    //! @brief Two threshold values (`u16Min`, `u16Max`) and a test value (`u16Val`) are given. If the test value exceeds the threshold the nearest threshold value is returned otherwise the test value is returned.
    //!
    //! For example: 
    //!  u16Min = 0  - minimum value of the threshold
    //!  u16Max = 10 - maximum value of the threshold
    //!  u16Val = 12 - test value
    //!  u16Ret = 10 - return value
    //!
    //! Note: If Min and Max are incorrectly swapped, the Min value is output as long as value <= Max, if this is not the case, the Min value is output.
    //!
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, i32RangeMinMax, u32RangeMinMax
    //! @param[in]  u16Val      Check Value
    //! @param[in]  u16Min      Min Value
    //! @param[in]  u16Max      Max Value
    //! @return     u16Ret      limited value
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16RangeMinMax( TUint16 u16Val, TUint16 u16Min, TUint16 u16Max);

    //--------------------------------------------------------------------------------------------------
    //! @brief  Two threshold values (`i32Min`, `i32Max`) and a test value (`i32Val`) are given. If the test value exceeds the threshold the neares threshold value is retuned otherwise the test value is returned.
    //!
    //! For example: 
    //!  i32Min = 0  - minimum value of the threshold
    //!  i32Max = 10 - maximum value of the threshold
    //!  i32Val = 12 - test value
    //!  i32Ret = 10 - return value
    //!
    //! Note: If Min and Max are incorrectly swapped, the Min value is output as long as value <= Max, if this is not the case, the Min value is output.
    //! 
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, u32RangeMinMax
    //! @param[in]  i32Val      Check Value
    //! @param[in]  i32Min      Min Value
    //! @param[in]  i32Max      Max Value
    //! @return     i32Ret      limited value
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32RangeMinMax( TInt32 i32Val, TInt32 i32Min, TInt32 i32Max );

    //--------------------------------------------------------------------------------------------------
    //! @brief Two threshold values (`u32Min`, `u32Max`) and a test value (`u32Val`) are given. If the test value exceeds the threshold the neares threshold value is retuned otherwise the test value is returned.
    //!
    //! For example: 
    //!  u32Min = 0  - minimum value of the threshold
    //!  u32Max = 10 - maximum value of the threshold
    //!  u32Val = 12 - test value
    //!  u32Ret = 10 - return value
    //!
    //! Note: If Min and Max are incorrectly swapped, the Min value is output as long as value <= Max, if this is not the case, the Min value is output.
    //! 
    //! @sa i16GetCurveY, i8AbsI8, u8AbsI8, i16AbsI16, u16AbsI16, i32AbsI32, u32AbsI32, i64AbsI64, u64AbsI64, u8Min2U8, i8RangeMinMax, u8RangeMinMax, i16RangeMinMax, u16RangeMinMax, i32RangeMinMax
    //! @param[in]  u32Val      Check Value
    //! @param[in]  u32Min      Min Value
    //! @param[in]  u32Max      Max Value
    //! @return     u32Ret      limited value
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32RangeMinMax( TUint32 u32Val, TUint32 u32Min, TUint32 u32Max );

// (D2) Tolerance Functions

    //--------------------------------------------------------------------------------------------------
    //! @brief Adds the given tolerance `u32Perc` to the original value `u32Val` and return the result `u32Ret`. 
    //!
    //! @sa u16ToleranceVal, u32ToleranceVal
    //! @param[in]  u32Val      - [-] Orginal Value
    //! @param[in]  i32Perc     - [&] Tolerance
    //! @return     u32Ret      - Val = Val +((Val*ValPp)/100)
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32ValWithToleranceVal( TUint32 u32Val, TInt32 i32Perc );

    //--------------------------------------------------------------------------------------------------
    //! @brief Adds the given tolerance `u8Perc` to the original value `u16Val` and return the result `u16Ret`.
    //!
    //! @sa u32ValWithToleranceVal, u32ToleranceVal
    //! @param[in]  u16Val     - [-] Orginal Value
    //! @param[in]  u8Perc     - [%] Tolerance
    //! @return     u16Ret     - Val =((Val*ValPp)/100)
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16ToleranceVal( TUint16 u16Val, TUint8 u8Perc );

    //--------------------------------------------------------------------------------------------------
    //! @brief Adds the given tolerance `u8Perc` to the original value `u32Val` and return the result `u32Ret`.
    //!
    //! @sa u32ValWithToleranceVal, u16ToleranceVal
    //! @param[in]  u32Val    - [-] Orginal Value
    //! @param[in]  u8Perc    - [%] Tolerance
    //! @return     u32Ret    - Val =((Val*ValPp)/100)
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32ToleranceVal( TUint32 u32Val, TUint8 u8Perc );

// (D3) Time Functions

    //--------------------------------------------------------------------------------------------------
    //! @brief      Converts a given value in ms into four values: hours, minutes, seconds, and milliseconds.
    //!
    //! @sa vTimeConvSecToHms
    //! @param[in]  u32Time    - [ms]  Input time in milliseconds
    //! @param[out] pu32Hours  - [h]   Calculated hours
    //! @param[out] pu8Min     - [min] Calculated minutes
    //! @param[out] pu8Sec     - [sec] Calculated seconds
    //! @param[out] pu16Ms     - [ms]  Calculated milliseconds
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vTimeConvMsToHmss( TUint32 u32Time, TUint32* pu32Hours, TUint8* pu8Min, TUint8* pu8Sec, TUint16* pu16Ms );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Converts a given value in s into four values: hours, minutes, and seconds.
    //!
    //! @sa vTimeConvMsToHmss
    //! @param[in]  u32Time    - [sec] Input time in seconds
    //! @param[out] pu32Hours  - [h]   Calculated hours
    //! @param[out] pu8Min     - [min] Calculated minutes
    //! @param[out] pu8Sec     - [sec] Calculated seconds
    //! @return     NULL
    //--------------------------------------------------------------------------------------------------
    extern TVoid vTimeConvSecToHms( TUint32 u32Time, TUint32* pu32Hours, TUint8* pu8Min, TUint8* pu8Sec );

// (D4) Temperature Functions

    //--------------------------------------------------------------------------------------------------
    //! @brief      Converts the temperature from Celsius to Kelvin [i16Kelvin = i16Celsius + 273].
    //!
    //! @sa i16KelvinToCelsius, i16CelsiusToFahrenheit, i16FahrenheitToCelsius, boDataChange
    //! @param[in]  i16Celsius
    //! @return     i16Kelvin
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CelsiusToKelvin( TInt16 i16Celsius );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Converts the temperature from Kelvin to Celsius [i16Celsius = i16Kelvin - 273].
    //!
    //! @sa i16CelsiusToKelvin, i16CelsiusToFahrenheit, i16FahrenheitToCelsius, boDataChange
    //! @param[in]  i16Kelvin
    //! @return     i16Celsius
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16KelvinToCelsius( TInt16 i16Kelvin );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Converts the temperature from Celsius to Fahrenheit [`i16Fahrenheit` = (`i16Celsius` * 18)/10 + 32].
    //!
    //! @sa i16CelsiusToKelvin, i16KelvinToCelsius, i16FahrenheitToCelsius, boDataChange
    //! @param[in]  i16Celsius     - temperature in [°C] as a signed short
    //! @return     i16Fahrenheit  - temperature in [°F] as a signed short
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CelsiusToFahrenheit( TInt16 i16Celsius );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Converts the temperature form Fahrenheit to Celsius [`i16Celsius` = (`i16Fahrenheit` - 32) * (5/9)].
    //!
    //! @sa i16CelsiusToKelvin, i16KelvinToCelsius, i16CelsiusToFahrenheit, boDataChange
    //! @param[in]  i16Fahrenheit  - temperature in [°F] as a signed short
    //! @return     i16Celsius     - temperature in [°C] as a signed short
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16FahrenheitToCelsius( TInt16 i16Fahrenheit );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Compare and update a data-field.
    //!
    //! -------------------------------------------------------------------------------- 
    //! ### Example 
    //! The pointer `pu8DataOrg` points to a data field with the following content of the original data field: 0xFF.
    //! The pointer `pu8DataCpy` points to a data field with the following content of the memory data field: 0xFA.
    //! The data size of the field is 8 bit so that the `u32MaxSize = 8`.
    //! The return value of the function is TRUE, the content of the `pu8DataCpy` is 0xFF after the function call. 
    //!
    //! @sa i16CelsiusToKelvin, i16KelvinToCelsius, i16CelsiusToFahrenheit, i16FahrenheitToCelsius
    //! @param[in]  pu8DataOrg  - Original Data
    //! @param[in]  pu8DataCpy  - Memory Data
    //! @param[in]  u32MaxSize     - Data size
    //! @return     FALSE if the data fields are identical, 
    //!             TRUE if the data fields are not identical (after that call the fields are identical)
    //-------------------------------------------------------------------------------------------------
    extern TBoolean boDataChange( TUint8 *pu8DataOrg, TUint8 *pu8DataCpy, TUint32 u32Size );

// (E1) String Functions

    //--------------------------------------------------------------------------------------------------
    //! @brief      Save string copy function (destination string ends always with NULL - by strncpy this is not safe)
    //! @param[in]  pchDestination  - Pointer to the destination array the content is to be copied to.
    //! @param[in]  cpchSource      - C string to be copied
    //! @param[in]  u8StrLen        - Maximum number of characters to be copied from source.
    //! @retval     TRUE            - String fit complete to the destination
    //! @retval     FALSE           - String don't fit to the destination
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boStringCopy( TChar *pchDestination, const TChar *cpchSource, TUint8 u8StrLen );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Save string cat function (destination string end always with NULL - by strcat this is not safe)
    //! @param[in]  pchDestination - Pointer to the destination array, which contains a C string
    //!                              and be large enough to receive the concatenated string result.
    //! @param[in]  cpchSource     - C string to be appended. This should not overlap the destination.
    //! @param[in]  u8StrLen       - Maximum number of characters in the destination array
    //! @retval     TRUE           - String fit complete
    //! @retval     FALSE          - String don't fit complete
    //--------------------------------------------------------------------------------------------------
    extern TBoolean boStringCat( TChar *pchDestination, const TChar *cpchSource, TUint8 u8StrLen );

#endif
