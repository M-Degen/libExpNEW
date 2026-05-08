//**************************************************************************************************
/*!
@file           ItfTypes.h
@brief          Type definition
@date           01.11.2011
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFTYPES__
    #define __ITFTYPES__

    #include <autoconfig.h>
    #include <appconfig.h>
    #include <ItfGlobal.h>

    #ifdef __cplusplus
        #define PUBLIC_VAR extern                   //!< Important for the C++ compatibility
    #else
        #define PUBLIC_VAR                          //!< Important for the C++ compatibility
    #endif

    #ifdef SCRIPT_TEST_FCT
      #define member_fct                            //!< member for function - the new defintionen
      #define member                                //!< Important for the PC-UNIT Test functions (NOTE: a. Functions can be called in other modules
                                                    //!<                                                 b. Local variables lose their value!        )

    #else
      #define member_fct static                     //!< member for function - the new defintionen
      #define member     static                     //!< Standard case (NOTE: Use the member definition only for function definitions, not variable definitions)
    #endif

    #define member_var static                       //!< member for variables

    // Function return values
    #define AVOID_WARRNING(param)         if((param) != 0){           }  //!< Imported PC-LINT test, avoid not use parameters
    #define AVOID_WARRNING_FLOAT(param)   if((param)  > 0){ param+=1; }  //!< Imported PC-LINT test, avoid not use parameters

// TYPE DEFINITIONS ================================================================================

    // Type adjustment for the application of ECUs

#ifdef COMPILER_SWITCH_COM_TASKING                  // Predefined variables 
    #define TVoid void                              //!< variable prefix -> v
    typedef char                TChar;              //!< variable prefix -> ch (is signed)
    typedef unsigned char       TBit;               //!< variable prefix -> bi, bi2, bi3, ... bi16 (for TUint16 bit struct)
    typedef unsigned char       TBoolean;           //!< variable prefix -> bo
    typedef unsigned char       TBit2;              //!< variable prefix -> bi2
    typedef unsigned char       TBit3;              //!< variable prefix -> bi3
    typedef unsigned char       TBit4;              //!< variable prefix -> bi4
    typedef unsigned char       TBit5;              //!< variable prefix -> bi5
    typedef unsigned char       TBit6;              //!< variable prefix -> bi6
    typedef unsigned char       TBit7;              //!< variable prefix -> bi7
    typedef unsigned char       TUint8;             //!< variable prefix -> u8
    typedef signed char         TInt8;              //!< variable prefix -> i8
    typedef unsigned int        TUint16;            //!< variable prefix -> u16
    typedef signed int          TInt16;             //!< variable prefix -> i16
    typedef unsigned long       TUint32;            //!< variable prefix -> u32
    typedef signed long         TInt32;             //!< variable prefix -> i32
    typedef unsigned long long  TUint64;            //!< variable prefix -> u64
    typedef signed long long    TInt64;             //!< variable prefix -> i64
    typedef float               TFloat32;           //!< variable prefix -> f32
    typedef double              TFloat64;           //!< variable prefix -> f64
    typedef long unsigned int   TPriU32;            //!< for a short cast e.g. vPrint( "%lu", (TPriU32)U32_MAX);
    typedef long signed int     TPriI32;            //!< for a short cast e.g. vPrint( "%ld", (TPriI32)I32_MAX);
    typedef double              TPriF32;            //!< for a short cast e.g. vPrint( "%lf", (TPriF32)F32_MAX);
#endif

#ifdef COMPILER_SWITCH_COM_IAR                      // Predefined variables
    #define TVoid void                              //!< variable prefix -> v
    typedef char                TChar;              //!< variable prefix -> ch (is unsigned)
    typedef unsigned char       TBit;               //!< variable prefix -> bi, bi2, bi3, ... bi16 (for TUint16 bit struct)
    typedef unsigned char       TBoolean;           //!< variable prefix -> bo
    typedef unsigned char       TBit2;              //!< variable prefix -> bi2
    typedef unsigned char       TBit3;              //!< variable prefix -> bi3
    typedef unsigned char       TBit4;              //!< variable prefix -> bi4
    typedef unsigned char       TBit5;              //!< variable prefix -> bi5
    typedef unsigned char       TBit6;              //!< variable prefix -> bi6
    typedef unsigned char       TBit7;              //!< variable prefix -> bi7
    typedef unsigned char       TUint8;             //!< variable prefix -> u8
    typedef signed char         TInt8;              //!< variable prefix -> i8
    typedef unsigned short      TUint16;            //!< variable prefix -> u16
    typedef signed short        TInt16;             //!< variable prefix -> i16
    typedef unsigned int        TUint32;            //!< variable prefix -> u32
    typedef signed int          TInt32;             //!< variable prefix -> i32
    typedef unsigned long long  TUint64;            //!< variable prefix -> u64
    typedef signed long long    TInt64;             //!< variable prefix -> i64
    typedef float               TFloat32;           //!< variable prefix -> f32
    typedef double              TFloat64;           //!< variable prefix -> f64
    typedef long unsigned int   TPriU32;            //!< for a short cast e.g. vPrint( "%lu", (TPriU32)U32_MAX);
    typedef long signed int     TPriI32;            //!< for a short cast e.g. vPrint( "%ld", (TPriI32)I32_MAX);
    typedef double              TPriF32;            //!< for a short cast e.g. vPrint( "%lf", (TPriF32)F32_MAX);
#endif

#ifdef COMPILER_SWITCH_COM_GCC                      // Predefined variables
    #define TVoid void                              //!< variable prefix -> v
    typedef char                TChar;              //!< variable prefix -> ch (is unsigned)
    typedef unsigned char       TBit;               //!< variable prefix -> bi, bi2, bi3, ... bi16 (for TUint16 bit struct)
    typedef unsigned char       TBoolean;           //!< variable prefix -> bo
    typedef unsigned char       TBit2;              //!< variable prefix -> bi2
    typedef unsigned char       TBit3;              //!< variable prefix -> bi3
    typedef unsigned char       TBit4;              //!< variable prefix -> bi4
    typedef unsigned char       TBit5;              //!< variable prefix -> bi5
    typedef unsigned char       TBit6;              //!< variable prefix -> bi6
    typedef unsigned char       TBit7;              //!< variable prefix -> bi7
    typedef unsigned char       TUint8;             //!< variable prefix -> u8
    typedef signed char         TInt8;              //!< variable prefix -> i8
    typedef unsigned short      TUint16;            //!< variable prefix -> u16
    typedef signed short        TInt16;             //!< variable prefix -> i16
    typedef unsigned int        TUint32;            //!< variable prefix -> u32
    typedef signed int          TInt32;             //!< variable prefix -> i32
    typedef unsigned long long  TUint64;            //!< variable prefix -> u64
    typedef signed long long    TInt64;             //!< variable prefix -> i64
    typedef float               TFloat32;           //!< variable prefix -> f32
    typedef double              TFloat64;           //!< variable prefix -> f64
    typedef long unsigned int   TPriU32;            //!< for a short cast e.g. vPrint( "%lu", (TPriU32)U32_MAX);
    typedef long signed int     TPriI32;            //!< for a short cast e.g. vPrint( "%ld", (TPriI32)I32_MAX);
    typedef double              TPriF32;            //!< for a short cast e.g. vPrint( "%lf", (TPriF32)F32_MAX);
#endif

#ifdef COMPILER_SWITCH_COM_TEXAS                    // Predefined variables
    #define TVoid void                              //!< variable prefix -> v
    typedef char                TChar;              //!< variable prefix -> ch (is unsigned)
    typedef unsigned char       TBit;               //!< variable prefix -> bi, bi2, bi3, ... bi16 (for TUint16 bit struct)
    typedef unsigned char       TBoolean;           //!< variable prefix -> bo
    typedef unsigned char       TBit2;              //!< variable prefix -> bi2
    typedef unsigned char       TBit3;              //!< variable prefix -> bi3
    typedef unsigned char       TBit4;              //!< variable prefix -> bi4
    typedef unsigned char       TBit5;              //!< variable prefix -> bi5
    typedef unsigned char       TBit6;              //!< variable prefix -> bi6
    typedef unsigned char       TBit7;              //!< variable prefix -> bi7
    typedef unsigned char       TUint8;             //!< variable prefix -> u8
    typedef signed char         TInt8;              //!< variable prefix -> i8
    typedef unsigned short int  TUint16;            //!< variable prefix -> u16
    typedef signed short int    TInt16;             //!< variable prefix -> i16
    typedef unsigned long       TUint32;            //!< variable prefix -> u32
    typedef signed long         TInt32;             //!< variable prefix -> i32
    typedef unsigned long long  TUint64;            //!< variable prefix -> u64
    typedef signed long long    TInt64;             //!< variable prefix -> i64
    typedef float               TFloat32;           //!< variable prefix -> f32
    typedef double              TFloat64;           //!< variable prefix -> f64
    typedef long unsigned int   TPriU32;            //!< for a short cast e.g. vPrint( "%lu", (TPriU32)U32_MAX )
    typedef long signed int     TPriI32;            //!< for a short cast e.g. vPrint( "%ld", (TPriI32)I32_MAX);
    typedef double              TPriF32;            //!< for a short cast e.g. vPrint( "%lf", (TPriF32)F32_MAX);
#endif

#ifdef COMPILER_SWITCH_COM_HIGHTEC                  // Predefined variables
    #define TVoid void                              //!< variable prefix -> v
    typedef char                TChar;              //!< variable prefix -> ch (is signed)
    typedef unsigned char       TBit;               //!< variable prefix -> bi, bi2, bi3, ... bi16 (for TUint16 bit struct)
    typedef unsigned char       TBoolean;           //!< variable prefix -> bo
    typedef unsigned char       TBit2;              //!< variable prefix -> bi2
    typedef unsigned char       TBit3;              //!< variable prefix -> bi3
    typedef unsigned char       TBit4;              //!< variable prefix -> bi4
    typedef unsigned char       TBit5;              //!< variable prefix -> bi5
    typedef unsigned char       TBit6;              //!< variable prefix -> bi6
    typedef unsigned char       TBit7;              //!< variable prefix -> bi7
    typedef unsigned char       TUint8;             //!< variable prefix -> u8
    typedef signed char         TInt8;              //!< variable prefix -> i8
    typedef unsigned short      TUint16;            //!< variable prefix -> u16
    typedef signed short        TInt16;             //!< variable prefix -> i16
    typedef unsigned int        TUint32;            //!< variable prefix -> u32
    typedef signed int          TInt32;             //!< variable prefix -> i32
    typedef unsigned long long  TUint64;            //!< variable prefix -> u64
    typedef signed long long    TInt64;             //!< variable prefix -> i64
    typedef float               TFloat32;           //!< variable prefix -> f32
    typedef double              TFloat64;           //!< variable prefix -> f64
    typedef long unsigned int   TPriU32;            //!< for a short cast e.g. vPrint( "%lu", (TPriU32)U32_MAX )
    typedef long signed int     TPriI32;            //!< for a short cast e.g. vPrint( "%ld", (TPriI32)I32_MAX);
    typedef double              TPriF32;            //!< for a short cast e.g. vPrint( "%lf", (TPriF32)F32_MAX);
#endif

#ifdef COMPILER_SWITCH_COM_MINGW                       // Predefined variables
    #define TVoid void                                 //!< variable prefix -> v
    typedef char                   TChar;              //!< variable prefix -> ch (is signed)
    typedef unsigned char          TBit;               //!< variable prefix ->(TUint16) bi, bi2, bi3, ... bi16
    typedef unsigned char          TBoolean;           //!< variable prefix -> bo
    typedef unsigned char          TBit2;              //!< variable prefix -> bi2
    typedef unsigned char          TBit3;              //!< variable prefix -> bi3
    typedef unsigned char          TBit4;              //!< variable prefix -> bi4
    typedef unsigned char          TBit5;              //!< variable prefix -> bi5
    typedef unsigned char          TBit6;              //!< variable prefix -> bi6
    typedef unsigned char          TBit7;              //!< variable prefix -> bi7
    typedef unsigned char          TUint8;             //!< variable prefix -> u8
    typedef signed char            TInt8;              //!< variable prefix -> i8
    typedef unsigned short         TUint16;            //!< variable prefix -> u16
    typedef signed short           TInt16;             //!< variable prefix -> i16
    typedef unsigned               TUint32;            //!< variable prefix -> u32
    typedef signed                 TInt32;             //!< variable prefix -> i32
    typedef unsigned long long     TUint64;            //!< variable prefix -> u64
    typedef signed long long       TInt64;             //!< variable prefix -> i64
    typedef float                  TFloat32;           //!< variable prefix -> f32                                   [Note: vPrint( "%f", 1.8)]
    typedef double                 TFloat64;           //!< variable prefix -> f64                                   [Note: vPrint( "%f", 1.8)]
    typedef long unsigned int      TPriU32;            //!< for a short cast e.g. vPrint( "%lu",  (TPriU32)U32_MAX);
    typedef long signed int        TPriI32;            //!< for a short cast e.g. vPrint( "%ld",  (TPriI32)I32_MAX);
    typedef long long unsigned int TPriU64;            //!< for a short cast e.g. vPrint( "%llu", (TPriU64)U32_MAX); [Note: need compile with -std=c11]
    typedef long long signed int   TPriI64;            //!< for a short cast e.g. vPrint( "%lld", (TPriI64)I32_MAX); [Note: need compile with -std=c11]
    typedef double                 TPriF32;            //!< for a short cast e.g. vPrint( "%lf",  (TPriF32)F32_MAX);
#endif

    //! TUint16 union
    typedef union UAto16
    {
        TUint16 u16;                                //!< biggest element
        TUint8  au8[2];                             //!< short elements
    }UAto16;

    //! TInt16 union
    typedef union IAto16
    {
        TInt16  i16;                                //!< biggest element
        TUint8  au8[2];                             //!< short elements
    }IAto16;

    //! TUint32 union
    typedef union UAto32
    {
        TUint32 u32;                                //!< biggest element
        TUint16 au16[2];                            //!< middle elements
        TUint8  au8[4];                             //!< short elements
    }UAto32;

    //! TFloat32 union
    typedef union UAtoF32
    {
        TFloat32 f32;                               //!< biggest element
        TUint8   au8[4];                            //!< short elements
    }UAtoF32;

    //! TUint64 Union
    typedef union UAto64
    {
        TUint64 u64;                                //!< biggest element
        TUint32 au32[2];                            //!< middle elements
        TUint16 au16[4];                            //!< middle elements
        TUint8  au8[8];                             //!< short elements
    }UAto64;

    #ifdef COMPILER_SWITCH_TAR_PC
    #include <ItfTestSuite.h>
    #endif

#endif
