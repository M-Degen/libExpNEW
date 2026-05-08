//**************************************************************************************************
/*!
@file           ItfGlobal.h
@brief          Global defines
@date           01.11.2011
@author         HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFGLOBAL__
    #define  __ITFGLOBAL__

#include <autoconfig.h>

// Common defines ==================================================================================
    // Common

    #define OFF             0                       //!< OFF value
    #define ON              1                       //!< ON value
    #define ERR             2                       //!< ERR value

    #define HIGH            1                       //!< HIGH value
    #define LOW             0                       //!< LOW value

    #ifdef TRUE
       #undef TRUE                                  //!< Special undefined - for the hardware abstract
    #endif
    #ifdef FALSE
       #undef FALSE                                 //!< Special undefined - for the hardware abstract
    #endif

    #ifdef COMPILER_SWITCH_FAM_TTC7X
      #define FALSE         0U                      //!< BSP: For compatibility with the IO driver
      #define TRUE          1U                      //!< BSP: For compatibility with the IO driver
    #else
     #ifdef COMPILER_SWITCH_ENV_CEN
      #define TRUE           ((TBoolean)1)          //!< TRUE Value
      #define FALSE          ((TBoolean)0)          //!< FALSE Value
     #else
      #define TRUE           1                      //!< TRUE Value
      #define FALSE          0                      //!< FALSE Value
     #endif
    #endif

    #ifdef NULL
       #undef NULL                                  //!< Special undefined - for the hardware abstract
    #endif
    #ifdef NONE
       #undef NONE                                  //!< Special undefined - for the hardware abstract
    #endif
    #define NULL        (0L)                        //!< No pointer
    #define NONE        (-1)                        //!< Undefined/nothing for signed integer

    //! Return values for HCP-Functions
    typedef enum
    {
        R_OKAY            =   0,   //!< [ 0] - OKAY
        R_BUSY            =  -1,   //!< [FF] - process is busy              - im Prozess
        R_UNKNOWN         =  -2,   //!< [FE] - unknown error                - nicht spezifiziert
        R_WARN            =  -3,   //!< [FD] - warning                      - Warnung
        R_DEFAULT         =  -4,   //!< [FC] - default setting              - Default Wert
        R_RANGE           =  -5,   //!< [FB] - out of range                 - ausserhalb des gültigen Wertebereichs
        R_OVERFLOW        =  -6,   //!< [FA] - buffer overflow              - Pufferüberlauf
        R_NOACT           =  -7,   //!< [F9] - no action                    - keine Aktion
        R_CONFIG          =  -8,   //!< [F8] - wrong configuration          - falsche Konfiguration
        R_CHECKSUM        =  -9,   //!< [F7] - wrong CHECKSUM               - falsche Check-Summe
        R_SUPPORT         = -10,   //!< [F6] - don't support that           - keine Unterstützung
        R_EMPTY           = -11,   //!< [F5] - is empty                     - ist leer
        R_PARAMETER       = -12,   //!< [F4] - no valid parameter           - Ungültiger Parameter
        R_INCONSISTENT    = -13,   //!< [F3] - inconsistent data            - Unstimmige Daten
        R_TIMEOUT         = -14,   //!< [F2] - timeout                      - Timeout
        R_COMMUNICA       = -15,   //!< [F1] - communication error          - Kommunikations Probleme
        R_PTC_SUPPORT     = -16,   //!< [F0] - no protocol support          - keine PTC Unterstützung
        R_RD_WR           = -17,   //!< [EF] - read/write access rights     - falsche Schreib-/Lese-Rechte
        R_ACCESSLEVEL     = -18,   //!< [EE] - wrong access level           - falsches Access-Level
        R_MEMORY          = -19,   //!< [ED] - out of memory                - Ungültiger Speicher-Bereich
        R_ADDRESS         = -20,   //!< [EC] - out of address range         - Ungültige Addresse
        R_USERADDRESS     = -21,   //!< [EB] - error: db or error adr. not possible  - Ungültige Addresse da Db- oder Error-List
        R_NV_LOAD         = -22,   //!< [EA] - can't read the NvMem list    - Fehler beim Laden des NvMem
        R_NV_STORE        = -23,   //!< [E9] - can't store the NvMem list   - Fehler beim Speichern des NvMem
        R_DB_LIST         = -24,   //!< [E8] - no valid data list           - Ungültige Liste
        R_DB_TYPE         = -25,   //!< [E7] - no valid data list type      - Ungültiger Listtype
        R_DB_VAR          = -26,   //!< [E6] - no valid variable type       - Ungültiger Variablentype
        R_DB_DIM          = -27,   //!< [E5] - no valid array dimension     - Ungültige Array-Größe
        R_DB_LOAD         = -28,   //!< [E4] - can't read the data list     - Fehler beim Laden der Daten Liste
        R_DB_STORE        = -29,   //!< [E3] - can't store the data list    - Fehler beim Speichern der Daten Liste
        R_DB_CRC          = -30,   //!< [E2] - wrong data base CRC          - Ungültige Checksumme
        R_DB_PARM         = -31,   //!< [E1] - list param idx has change    - der Listen Parameter Index hat sich geändert
        R_DB_COM          = -32,   //!< [E0] - don't find COM-ID            - Ungültige COM-ID
        R_DB_DEFSET       = -33,   //!< [DF] - wrong default set            - Ungültiger Default Set
        R_MONOTONY        = -34,   //!< [DE] - not monotonic                - Nicht monoton
        R_ZERO            = -35,   //!< [DD] - zero value                   - Wert ist NULL
        R_MINMAX          = -36,   //!< [DC] - overrun value range min/max  - Min-Max Überschreitung
        R_MINIMUM         = -37,   //!< [DB] - below minimum allowed value  - Kleiner als kleinster erlaubter Wert
        R_MAXIMUM         = -38,   //!< [DA] - above maximum allowed value  - Grösser als grösster erlaubter Wert
        R_SIL_CRITICAL    = -39,   //!< [D9] - critical SIL error           - Kritische SIL Fehler gefunden
        R_NULL_POINTER    = -40,   //!< [D8] - Null pointer                 - Null Pointer
        R_NOT_INITIALIZED = -41,   //!< [D7] - object not yet initialized   - Objekt noch nicht initialisiert
        R_NOT_REGISTRY    = -42,   //!< [D6] - Object not registered        - Objekt nicht registriert
        R_NOT_NAME        = -43,   //!< [D5] - Object not named             - Objekt nicht benannt
        R_DOUBLE          = -44,   //!< [D4] - Duplicated object            - Objekt doppelt
        R_DEBUGMODE       = -45,   //!< [D3] - App is in Debug-Mode         - Application ist im Debug-Mode, die Funktion geht nicht
        R_PHASE           = -46,   //!< [D2] - App is in wrong phase        - Application ist in falscher Phase
        R_PIN             = -47,   //!< [D1] - Pin is wrong                 - falscher Pin
        R_PIN_FIX         = -48,   //!< [D0] - Pin is not changeable        - Pin ist nicht änderbar
        R_BSP             = -49,   //!< [CF] - Internal BSP fault           - Interner BSP Fehler
        R_LOGIN           = -50,   //!< [CE] - Login is missing             - keine Login
        R_LOCKED          = -51,   //!< [CD] - Locked                       - verschlossen
        R_DOUBLE_CALL     = -52,   //!< [CC] - Double call                  - doppelter Aufruf
        R_FRAME_LENGTH    = -53,   //!< [CB] - Frame length                 - Frame Länge
        R_FRAME_SYN       = -54,   //!< [CB] - Frame syn                    - Frame syn
        R_PTC_ERR         = -55,   //!< [CA] - Protocol error               - Protokoll Fehler
        R_BUFFER_FULL     = -56,   //!< [C0] - Buffer full                  - Speicher voll
        // the following enum values are only available for the library code development - CORE RETURN VALUES.
        // Do not use these enum values in the application code.
        // Do not use these values by an interface function as a parameter or return value.
        R_CORE_CHAN_REMIT = -1001, //!< -1001 R_CORE_CHAN_REMIT
        R_CORE_CHAN_TRANS = -1002, //!< -1002 R_CORE_CHAN_TRANS
        R_CVT_TEST_NA     = -1003  //!< -1003 CVT test no applicable / test nicht möglich
    }ERetVal;


// Definition of variable type ranges ==============================================================

    //! BI2 Command Status Definition
    #define BI2_OFF         ((TBit2)0x00)                        //!< OFF
    #define BI2_ON          ((TBit2)0x01)                        //!< ON
    #define BI2_ERROR       ((TBit2)0x02)                        //!< Error
    #define BI2_NOT         ((TBit2)0x03)                        //!< not defined
    #define BI2_UNDEF       ((TBit2)0x03)                        //!< undefined

    //! BI3 Direction Status Definition
    #define BI3_NEU         ((TBit3)0x00)                        //!< Neutral  position
    #define BI3_POS         ((TBit3)0x01)                        //!< Positive direction
    #define BI3_NEG         ((TBit3)0x02)                        //!< Negative direction
    #define BI3_CTLERR      ((TBit3)0x05)                        //!< Control/calculation error
    #define BI3_ERROR       ((TBit3)0x06)                        //!< error
    #define BI3_NOT         ((TBit3)0x07)                        //!< not defined
    #define BI3_UNDEF       ((TBit3)0x07)                        //!< undefined

    #define BI4_ERROR       ((TBit4)0x0E)                        //!< error
    #define BI4_NOT         ((TBit4)0x0F)                        //!< not defined

    #define BI5_ERROR       ((TBit5)0x1E)                        //!< error
    #define BI5_NOT         ((TBit5)0x1F)                        //!< not defined

    #define BI6_ERROR       ((TBit6)0x3E)                        //!< error
    #define BI6_NOT         ((TBit6)0x3F)                        //!< not defined

    #define BI7_ERROR       ((TBit7)0x7E)                        //!< error
    #define BI7_NOT         ((TBit7)0x7F)                        //!< not defined

    // BIx Max values
    #define BI2_MIN         ((TBit2)0x00)                        //!< minimum count
    #define BI2_MAX         ((TBit2)0x03)                        //!< maximum count

    #define BI3_MIN         ((TBit3)0x00)                        //!< minimum count
    #define BI3_MAX         ((TBit3)0x07)                        //!< maximum count

    #define BI4_MIN         ((TBit4)0x00)                        //!< minimum count
    #define BI4_MAX         ((TBit4)0x0F)                        //!< maximum count

    #define BI5_MIN         ((TBit5)0x00)                        //!< minimum count
    #define BI5_MAX         ((TBit5)0x1F)                        //!< maximum count

    #define BI6_MIN         ((TBit6)0x00)                        //!< minimum count
    #define BI6_MAX         ((TBit6)0x3F)                        //!< maximum count

    #define BI7_MIN         ((TBit7)0x00)                        //!< minimum count
    #define BI7_MAX         ((TBit7)0x7F)                        //!< maximum count

    // TChar
    #if defined(COMPILER_SWITCH_COM_TEXAS) || \
        defined(COMPILER_SWITCH_COM_IAR)   || \
        ( defined(COMPILER_SWITCH_COM_GCC) && defined(COMPILER_SWITCH_OEM_UNJO) )
        #define CH_MIN         ((TChar)(   0))                  //!< minimum - the char is unsigned
        #define CH_MAX         ((TChar)( 255))                  //!< maximum - the char is unsigned
    #else
        #define CH_MIN         ((TChar)(-128))                  //!< minimum - the char is signed
        #define CH_MAX         ((TChar)( 127))                  //!< maximum - the char is signed
    #endif

    // TInt8
    #define I8_MIN          ((TInt8)(-128))                      //!< minimum value
    #define I8_MAX          ((TInt8)( 127))                      //!< maximum value
    #define I8_LIMIT        ((TInt8)(0x79))                      //!< g.t. is reserved for specific definitions
    #define I8_ERROR        ((TInt8)(0x7E))                      //!< error
    #define I8_UNDEF        ((TInt8)(0x7F))                      //!< undefined
    // TUint8
    #define U8_MIN          ((TUint8)(   0))                     //!< minimum value
    #define U8_MAX          ((TUint8)( 255))                     //!< maximum value
    #define U8_LIMIT        ((TUint8)(0xF9))                     //!< g.t. is reserved for specific definitions
    #define U8_ERROR        ((TUint8)(0xFE))                     //!< error
    #define U8_UNDEF        ((TUint8)(0xFF))                     //!< undefined
    // TInt16
    #define I16_MIN         ((TInt16)(-32768))                   //!< minimum value
    #define I16_MAX         ((TInt16)( 32767))                   //!< maximum value
    #define I16_LIMIT       ((TInt16)(0x7FF9))                   //!< g.t. is reserved for specific definitions
    #define I16_ERROR       ((TInt16)(0x7FFE))                   //!< error
    #define I16_UNDEF       ((TInt16)(0x7FFF))                   //!< undefined
    // TUint16
    #define U16_MIN         ((TUint16)(     0))                  //!< minimum value
    #define U16_MAX         ((TUint16)( 65535))                  //!< maximum value
	#define U16_OFFSET      ((TUint16)( 65535/2+1))              //!< offset value
    #define U16_LIMIT       ((TUint16)(0xFFF9))                  //!< g.t. is reserved for specific definitions
    #define U16_ERROR       ((TUint16)(0xFFFE))                  //!< error
    #define U16_UNDEF       ((TUint16)(0xFFFF))                  //!< undefined
    // TInt32
    #define I32_MIN         ((TInt32)(-2147483647-1))            //!< minimum value
    #define I32_MAX         ((TInt32)( 2147483646+1))            //!< maximum value
    #define I32_LIMIT       ((TInt32)( 0x7FFFFFF9))              //!< g.t. is reserved for specific definitions
    #define I32_ERROR       ((TInt32)( 0x7FFFFFFE))              //!< error
    #define I32_UNDEF       ((TInt32)( 0x7FFFFFFF))              //!< undefined
    // TUint32
    #define U32_MIN         ((TUint32)(         0))              //!< minimum value
    #define U32_MAX         ((TUint32)(4294967295U))             //!< maximum value
    #define U32_LIMIT       ((TUint32)(0xFFFFFFF9))              //!< g.t. is reserved for specific definitions
    #define U32_ERROR       ((TUint32)(0xFFFFFFFE))              //!< error
    #define U32_UNDEF       ((TUint32)(0xFFFFFFFF))              //!< undefined
    // TUint64
    #define U64_BITMASK_32L ((TUint64)(0x00000000FFFFFFFF))      //!< Mask for the lower 32bit of a U64
    #define U64_BITMASK_32H ((TUint64)(0xFFFFFFFF00000000))      //!< Mask for the higher 32bit of a U64
    #define U64_MIN         ((TUint64)(                   0U))   //!< minimum value
    #define U64_MAX         ((TUint64)(18446744073709551615U))   //!< maximum -> 0xFFFFFFFFFFFFFFFF
    // TInt64
    #define I64_MIN         ((TInt64)(-9223372036854775807-1))   //!< minimum -> 0x8000000000000000
    #define I64_MAX         ((TInt64)( 9223372036854775806+1))   //!< maximum -> 0x7FFFFFFFFFFFFFFF
    // Float32
    #define F32_MIN_POS     ((TFloat32)1.1754943508e-38)         //!< minimum ( positive minimum value)
    #define F32_MAX_POS     ((TFloat32)3.4028234664e+38)         //!< maximum ( positive maximum value)
    #define F32_MIN_NEG     ((TFloat32)-1.1754943508e-38)        //!< minimum ( negative minimum value)
    #define F32_MAX_NEG     ((TFloat32)-3.4028234664e+38)        //!< maximum ( negative maximum value)
    #define F32_MIN          F32_MAX_NEG                         //!< absolute minimum
    #define F32_MAX          F32_MAX_POS                         //!< absolute maximum
    #define F32_EPSILON     ((TFloat32)1.192092896e-07)          //!< minimum value x with 1.0+x is unequal to 1.0

// Definition of scaling values ====================================================================
    // Decimal places
    #define DECI5           100000                               //!< Resolution 5 decimal(n)
    #define DECI4           10000                                //!< Resolution 4 decimal(n)
    #define DECI3           1000                                 //!< Resolution 3 decimal(n)
    #define DECI2           100                                  //!< Resolution 2 decimal(n)
    #define DECI1           10                                   //!< Resolution 1 decimal(n)

#endif
