####################################################################################################
#
# Makefile for lint setting
# (c) Copyright by Hydac System GmbH, all rights reserved
#
# PROJECT: 		Over all
# Hardware: 	Windows XP
#
# FILE VERSION INFORMATION:
#	$Filename:	lint.mak
#   $Version:	1.0 
#   $Date:		29.05.2018
#
####################################################################################################

####################################################################################################
# PC-LINT
####################################################################################################
#   Common Rules
#   -e14    Symbol 'Symbol' previously defined (Location)                - ok - Trick mehr Datein mit LINT überprüfen
#   -e85    Array 'Symbol' has dimension 0                               - ok - Problem im stdio.h
#   -e537   Repeated include file                                        - ok - Doppeltes include
#   -e766   h-File not used in C-File                                    - ok - nicht benutztes include
#   -e734   Loss of precision (assignment)                               - ok - keine Hochcasten
#   -e525   Negative indentation from Location                           - ok
#   -e534   Ignoring return value of function 'Symbol'                   - ok - nicht immer wichtig
#   -e583   Comparing type 'Type'with EOF                                - ok - Dateiende
#   -e818   Pointer parameter could be declared as pointing to const     - ok
#   -e716   while(1)                                                     - ok - Schleife
#   -e545   Suspicious use of &                                          - ok 
#   -e641   Converting enum 'TBloProc' to 'int'                          - ok - cast 
#   -e765   could be made static                                         - ok - Wirkungskreis
#   -e750   local macro XXX not referenced                               - ok - define Wert wird nicht benötigt 
#   -e715   not referenced                                               - ok - Unbenutze Parameter 
#   -e845   The left argument to operator '>>' is certain to be 0        - ok - Shift   
#   -e714   Symbol 'xxx'  not referenced                                 - ok - Test   
#   -e522   Highest operation, function 'xxx', lacks side-effects        - ok - Test
#   -e774   Boolean within 'if' always evaluates to True/Fase            - ok - Auswertungslogig  
#   -e788   enum constant 'xxx' not used within defaulted switch         - ok - Um dynamisch zu erweitern
#   -e793   ANSI/ISO limit of 31 'significant characters in an external  - ok 
#   -e730   Boolean argument to function - ok - for the CUnit test       - ok
#   -e1784  Symbol xx previously declared as "C"                         - ok - benötigt für cpp
#   -e743   Negative character constant                                  - ok - so kann man '€', 'µ' ... verwenden 

LINT_RULE = -dLINT_SWITCH_IGNORE -e14 -e85 -e537 -e766 -e734 -e525 -e534 -e583 -e818 -e716 -e545 -e641 -e765 -e750 -e715 -e845 -e714 -e522 -e774 -e788 -e793 -e1784 \
			-emacro(730,CU_ASSERT_EQUAL) -efunc(730,CU_ASSERT_EQUAL) -e743
