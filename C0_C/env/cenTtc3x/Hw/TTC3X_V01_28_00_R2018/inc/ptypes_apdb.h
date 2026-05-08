/**************************************************************************
 * Copyright (c) 2013 TTTControl. All rights reserved. Confidential proprietary
 * Schoenbrunnerstrasse 7, A-1040 Vienna, Austria. office@ttcontrol.com
 **************************************************************************/
/**********************************************************************//**
 * \file ptypes_apdb.h
 *
 * \brief Definitions for APDB.h
 *
 *      This file defines important settings for the APDB.h 
 *
 **************************************************************************/
#ifndef _PTYPES_H_APDB
#define _PTYPES_H_APDB 1

#include "ptypes_xe167.h"

#ifdef __cplusplus
extern "C" {
#endif


/* prototype for cstart */
extern void _cstart( void );

#define APPL_START      ((ubyte4) &_cstart)

#define APDB_ADDRESS    0xC10000

#define APDB volatile __huge const BL_APDB __at(APDB_ADDRESS)


#ifdef  __cplusplus
   }
#endif /* __cplusplus */

#endif /* _PTYPES_H_APDB */