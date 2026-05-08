//**************************************************************************************************
/*!
@file        ItfBasMath.h
@brief       Math functions
@date        10.01.2019
@author      HYDAC/NJP
*/
//**************************************************************************************************

#ifndef __ITFBASMATH__
  #define __ITFBASMATH__

// INCLUDES ========================================================================================
    #include <ItfTypes.h>

    #define CRC_VALUE_IMPOSSIBLE 0                  //!< Impossible CRC value

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates a control deviation of setpoint minus actual value
    //! @param[in]  i16XCom     Setpoint
    //! @param[in]  i16XAct     Actual value
    //! @retval     TInt16      Result value
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16Sub( TInt16 i16XCom, TInt16 i16XAct );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates a control deviation of setpoint minus actual value
    //! @param[in]  u16XCom     Setpoint
    //! @param[in]  u16XAct     Actual value
    //! @retval     TUint16     Result value
    //!                         If u16XCom <= u16XAct -> is the result 0
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16Sub( TUint16 u16XCom, TUint16 u16XAct );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates a control deviation of setpoint minus actual value
    //! @param[in]  i32XCom     Setpoint
    //! @param[in]  i32XAct     Actual value
    //! @retval     TInt32      Result value
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32Sub( TInt32 i32XCom, TInt32 i32XAct );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates a control deviation of setpoint minus actual value
    //! @param[in]  u32XCom     Setpoint
    //! @param[in]  u32XAct     Actual value
    //! @retval     TUint32     Result value
    //!                         If u32XCom <= u32XAct -> is the result 0
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32Sub( TUint32 u32XCom, TUint32 u32XAct );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the sum of X1 and X2
    //! @param[in]  i16X1       Input 1
    //! @param[in]  i16X2       Input 2
    //! @retval     TInt16      Result value
    //!                         If the mathematical result is > I16_MAX, the result value is I16_MAX.
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16Sum( TInt16 i16X1, TInt16 i16X2 );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the sum of X1 and X2
    //! @param[in]  u16X1       Input 1
    //! @param[in]  u16X2       Input 2
    //! @retval     TUint16     Result value
    //!                         If the mathematical result is > U16_MAX, the result value is U16_MAX.
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16Sum( TUint16 u16X1, TUint16 u16X2 );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the sum of X1 and X2
    //! @param[in]  i32X1       Input 1
    //! @param[in]  i32X2       Input 2
    //! @retval     TInt32      Result value
    //!                         If the mathematical result is > I32_MAX, the result value is I32_MAX.
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32Sum( TInt32 i32X1, TInt32 i32X2 );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the sum of X1 and X2
    //! @param[in]  u32X1       Input 1
    //! @param[in]  u32X2       Input 2
    //! @retval     TUint32     Result value
    //!                         If the mathematical result is > U32_MAX, the result value is U32_MAX.
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32Sum( TUint32 u32X1, TUint32 u32X2 );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculate the sum of X1 and X2
    //! @param[in]  i64X1       Input 1
    //! @param[in]  i64X2       Input 2
    //! @retval     TInt64      Result value \n
    //!                         If the mathematical result is > I64_MAX, the result value is I64_MAX. \n
    //!                         If the mathematical result is < I64_MIN, the result value is I64_MIN.
    //--------------------------------------------------------------------------------------------------
    extern TInt64 i64Sum( TInt64 i64X1, TInt64 i64X2 );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Multiplies X1 with X2 and returns the product
    //! @param[in]  i32A       Input 1
    //! @param[in]  i32B       Input 2
    //! @retval     TInt32     Result value
    //!                        If X1 or X2 is '0' the result is '1'
    //!                        If the mathematical result is > I32_MAX, the result value is I32_MAX.
    //!                        If the mathematical result is < I32_MIN, the result value is I32_MIN.
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32MulNeverNull( TInt32 i32A, TInt32 i32B );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Multiples X1 with X2 and after that divides by the scaling factor (if i16Scale != 0)
    //! @param[in]  i16X1      Input 1
    //! @param[in]  i16X2      Input 2
    //! @param[in]  i16Scale   Scaling Factor for division
    //! @retval     TInt16     Result value
    //!                        If the i16Scale is 0, no division is executed.
    //!                        If the mathematical result is > I16_MAX, the result value is I16_MAX.
    //!                        If the mathematical result is < I16_MIN, the result value is I16_MIN.
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16Mul( TInt16 i16X1, TInt16 i16X2, TInt16 i16Scale );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Multiples X1 with X2 and after that divides by the scaling factor (if i16Scale != 0).
    //! @param[in]  u16X1     Input 1
    //! @param[in]  u16X2     Input 2
    //! @param[in]  u16Scale  Scaling Factor for division
    //! @retval     TUint16   Result value
    //!                       If the u16Scale is 0, no division is executed.
    //!                       If the mathematical result is > U16_MAX, the result value is U16_MAX.
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16Mul( TUint16 u16X1, TUint16 u16X2, TUint16 u16Scale );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Multiples X1 with X2 and after that divides by the scaling factor (if i16Scale != 0).
    //! @param[in]  i32X1     Input 1
    //! @param[in]  i32X2     Input 2
    //! @param[in]  i32Scale  Scaling Factor for division
    //! @retval     TInt32    Result value
    //!                       If the i16Scale is 0, no division is executed.
    //!                       If the mathematical result is > I32_MAX, the result value is I32_MAX.
    //!                       If the mathematical result is < I32_MIN, the result value is I32_MIN.
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32Mul( TInt32 i32X1, TInt32 i32X2, TInt32 i32Scale );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Multiples X1 with X2 and after that divides by the scaling factor (if i16Scale != 0)
    //! @param[in]  u32X1     Input 1
    //! @param[in]  u32X2     Input 2
    //! @param[in]  u32Scale  Scaling Factor for division
    //! @retval     TUint32   Result value
    //!                       If the u32Scale is 0, no division is executed.
    //!                       If the mathematical result is > U32_MAX, the result value is U32_MAX.
    //!                       If the mathematical result is < U32_MIN, the result value is U32_MIN.
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32Mul( TUint32 u32X1, TUint32 u32X2, TUint32 u32Scale );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the quotient of numerator i16Xn divided by denominator i16Xd
    //! @param[in]  i16Xn     Numerator
    //! @param[in]  i16Xd     Denominator
    //! @retval     TInt16    Result value
    //!                       If i16Xd == 0 the result value is i16Xn, overflow: I16_MIN/-1 = I16_MAX
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16Div( TInt16 i16Xn, TInt16 i16Xd );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the quotient of numerator u16Xn divided by denominator u16Xd
    //! @param[in]  u16Xn     Numerator
    //! @param[in]  u16Xd     Denominator
    //! @retval     TUint16   Result value
    //!                       If u16Xd == 0 the result value is u16Xn
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16Div( TUint16 u16Xn, TUint16 u16Xd );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the quotient of numerator i32Xn divided by denominator i32Xd
    //! @param[in]  i32Xn     Numerator
    //! @param[in]  i32Xd     Denominator
    //! @retval     TInt32    Result value
    //!                       If i32Xd == 0 the result is i32Xn, overflow: I32_MIN/-1 = I32_MAX
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32Div(TInt32 i32Xn, TInt32 i32Xd);

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the quotient of numerator u32Xn devided by denominator u32Xd
    //! @param[in]  u32Xn     Numerator
    //! @param[in]  u32Xd     Denominator
    //! @retval     TUint32   Result value
    //!                       If u32Xd == 0 the result is u32Xn
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32Div( TUint32 u32Xn, TUint32 u32Xd );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the i16Cust value (x-value) over the i16Val value (y-value) in an linear function
    //! @brief                ---                                            ---
    //! @brief                | i16CustMax - i16CustMin                        |
    //! @brief      i16Cust = | ----------------------- * (i16Val - i16ValMin) | + i16CustMin
    //! @brief                |  i16ValMax - i16ValMin                         |
    //! @brief                ---                                            ---
    //! @param[in]  i16Val      Value
    //! @param[in]  i16ValMin   Minimum value
    //! @param[in]  i16CustMin  Minimum custom value
    //! @param[in]  i16ValMax   Maximum value
    //! @param[in]  i16CustMax  Maximum custom value
    //! @retval                 Result value
    //!                         If (i16ValMax - i16ValMin) == 0 the result is always i16CustMin
    //!                         Customer  e.g => y = i16CalcLinear2Dots( x, 80, 400, 200, 200 )
    //!                                              80->400, 200->200, x->y
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CalcLinear2Dots( TInt16 i16Val, TInt16 i16ValMin, TInt16 i16CustMin, TInt16 i16ValMax, TInt16 i16CustMax );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculates the i32Cust value (x-value) over the i32Val value (y-value) in an linear function
    //! @brief                ---                                            ---
    //! @brief                | i32CustMax - i32CustMin                        |
    //! @brief      i32Cust = | ----------------------- * (i32Val - i32ValMin) | + i32CustMin
    //! @brief                |  i32ValMax - i32ValMin                         |
    //! @brief                ---                                            ---
    //! @param[in]  i32Val      Value
    //! @param[in]  i32ValMin   Minimum value
    //! @param[in]  i32CustMin  Minimum custom value
    //! @param[in]  i32ValMax   Maximum value
    //! @param[in]  i32CustMax  Maximum custom value
    //! @retval                 Result value
    //!                         If (i32ValMax - i32ValMin) == 0 the result is always i32CustMin
    //!                         Customer  e.g => y = i32CalcLinear2Dots( x, 80, 400, 200, 200 );
    //!                                               80->400, 200->200, x->y
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32CalcLinear2Dots( TInt32 i32Val, TInt32 i32ValMin, TInt32 i32CustMin, TInt32 i32ValMax, TInt32 i32CustMax );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculation of a linear function
    //! @brief                    i16GNum
    //! @brief      i16Y = i16X * --------  + i16Zero
    //! @brief                    i16GDiv
    //! @param[in]  i16X     X-Value
    //! @param[in]  i16GNum  Gradient numerator
    //! @param[in]  i16GDiv  Gradient divisor
    //! @param[in]  i16Zero  Minimum value
    //! @retval     i16Y     Result value
    //!                      If i16GDiv == 0 the result is i16Zero
    //--------------------------------------------------------------------------------------------------
    extern TInt16 i16CalcLinearFunc( TInt16 i16X, TInt16 i16GNum, TInt16 i16GDiv, TInt16 i16Zero );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Calculation of a linear function
    //! @brief                    i32GNum
    //! @brief      i32Y = i32X * --------  + i32Zero
    //! @brief                     i32GDiv
    //! @param[in]  i32X     X-Value
    //! @param[in]  i32GNum  Gradient numerator
    //! @param[in]  i32GDiv  Gradient Divisor
    //! @param[in]  i32Zero  Minimum value
    //! @retval     i32Y     Result value
    //!                      If i32GDiv == 0 the result is i32Zero
    //--------------------------------------------------------------------------------------------------
    extern TInt32 i32CalcLinearFunc( TInt32 i32X, TInt32 i32GNum, TInt32 i32GDiv, TInt32 i32Zero );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Creates a 16-Bit priority word (because the CRC-Calc is too slow [5 times faster than a CRC-calculation])
    //! @param[in]  u16DataLen  Number of bytes
    //! @param[in]  pu8Data     A pointer to the block
    //! @return     u16Crc      The result (Result:CRC_VALUE_IMPOSSIBLE change to Result=CRC_VALUE_IMPOSSIBLE+1)
    //-------------------------------------------------------------------------------------------------
    extern TUint16 u16CalcPrioBlock( TUint16 u16DataLen, TUint8 *pu8Data );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Creates a 16-Bit CRC of a TUint16 including a CRC (with CRC-TABLE - FAST) - [CRC-CCITT 0xFFFF]
    //! @param[in]  u16CrcSum   CRC Sum (init with 0xFFFF)
    //! @param[in]  u16Data     Data word
    //! @return     u16Crc      The new CRC sum (Result:CRC_VALUE_IMPOSSIBLE change to Result=CRC_VALUE_IMPOSSIBLE+1)
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CalcCrcOneStep( TUint16 u16CrcSum, TUint16 u16Data );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Creates a 16-Bit CRC of a block (with CRC-TABLE - FAST) - [CRC-CCITT 0xFFFF]
    //! @param[in]  u16DataLen  Number of bytes
    //! @param[in]  pu8Data     A pointer to the block
    //! @return     u16Crc      The result (Result:CRC_VALUE_IMPOSSIBLE change to Result=CRC_VALUE_IMPOSSIBLE+1)
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CalcCrcBlock( TUint16 u16DataLen, TUint8 *pu8Data );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Create a 16-Bit CRC of a Block (with CRC-TABLE - FAST)  - [CRC-CCITT 0x1D0F]
    //! @param[in]  u16DataLen  Number of bytes
    //! @param[in]  pu8Data     A pointer to the block
    //! @return     u16Crc      The result (Result:CRC_VALUE_IMPOSSIBLE change to Result=CRC_VALUE_IMPOSSIBLE+1)
    //--------------------------------------------------------------------------------------------------
    extern TUint16 u16CalcCrcBlock_0x1D0F( TUint16 u16DataLen, TUint8 *pu8Data );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Creates a 32-Bit CRC of a TUint32 including a CRC sum  (with CRC-TABLE - FAST)
    //! @param[in]  u32CrcSum   CRC Sum (init with 0xFFFFFFFF)
    //! @param[in]  u32Data     Data double word
    //! @return     u32Crc      The new CRC sum (Result:CRC_VALUE_IMPOSSIBLE change to Result=CRC_VALUE_IMPOSSIBLE+1)
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CalcCrcOneStep( TUint32 u32CrcSum, TUint32 u32Data );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Creates a 32-Bit CRC of a block (with CRC-TABLE - FAST)
    //! @param[in]  u16DataLen  Number of bytes
    //! @param[in]  pu8Data     A pointer to the block
    //! @return     u32Crc      the Result (Result:CRC_VALUE_IMPOSSIBLE change to Result=CRC_VALUE_IMPOSSIBLE+1)
    //--------------------------------------------------------------------------------------------------
    extern TUint32 u32CalcCrcBlock( TUint16 u16DataLen, TUint8 *pu8Data );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Xor Random Generator - over ( u32ObjMemoryFree | u32EcuLastRunTime | u32EcuOnSwitch and polynomial )
    //-------------------------------------------------------------------------------------------------
    extern TUint16 u16XorRandomGenerator( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Xor Random Generator - over u32ObjMemoryFree | u32EcuLastRunTime | u32EcuOnSwitch and polynomial
    //-------------------------------------------------------------------------------------------------
    extern TUint32 u32XorRandomGenerator( TVoid );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Comparison of floating point numbers using FLT_EPSILON
    //! @param[in]  f32Val1     - Value 1
    //! @param[in]  f32Val2     - Value 2
    //! @return     TBoolean    - TRUE or FALSE 
    //-------------------------------------------------------------------------------------------------
    extern TBoolean boEqualFloatCheck( TFloat32 f32Val1, TFloat32 f32Val2 );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Use non conform CRC algorithm
    //! @param[in]  TBoolean    - TRUE or FALSE
    //-------------------------------------------------------------------------------------------------
    extern TVoid vUseNonConformCRC( TBoolean boUseNonConform );

    //--------------------------------------------------------------------------------------------------
    //! @brief      Get the setting from function vUseNonConformCRC()
    //! @return     TRUE or FALSE
    //-------------------------------------------------------------------------------------------------
    extern TBoolean boGetUseNonConformCRC( TVoid );
#endif

