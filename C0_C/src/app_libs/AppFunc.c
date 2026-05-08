/*
 * AppFunc.c
 *
 *  Created on: 08.05.2026
 *      Author: MoritzDegen
 */
#include "AppFunc.h"
TUint32 u32DoSomething( TUint32 u32A )
{
return u32A >> ( u32A % 32 );
}

