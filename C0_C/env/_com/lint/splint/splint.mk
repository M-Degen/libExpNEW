#####################################################################################################################################################
#
# Makefile for splint setting
# (c) Copyright by Hydac System GmbH, all rights reserved
#
# PROJECT: 		Over all
# Hardware: 	Windows 7
#
# FILE VERSION INFORMATION:
#	$Filename:	splint.mk
#   $Version:	1.0 
#   $Date:		25.04.2019
#   $Author:	Nico Lehmann $
#
##################################################################################################################################################################
# SPLINT (Suppress Warnings with "-")
##################################################################################################################################################################
#	Common Rules
#	-weak					 weakest checking-mode
#	-standard				 default checking-mode
#	-checks					 slightly strict checking-mode
#	-strict					 really strict checking-mode
#			 
#	-hints					 Don't show any hints
#	+forcehints				 Provide hints for all errors reported
#	+posixlib				 Use the POSIX standard library
#	-preproc				 Preprocessing error
#	-nestcomment			 A comment open sequence (/*) appears inside a comment. This usually indicates that an earlier comment was not closed	
#	-maintype				 Type of main does not match expected type 
#	+gnuextensions			 Support some GNU and Microsoft language extensions  													**default
#	-type					 Type mismatch
#	-fixedformalarray		 an array formal parameter is declared with a fixed size 
#	-nullassign				 A reference with no null annotation is assigned or initialized to NULL
#	-incondefs				 A function, variable or constant is redefined with a different type
#	-mustfreeonly			 Allocated storage was not released before return or scope exit. Errors are reported for !!only!! storage
#	-usereleased			 Storage used after it may have been released
#	-gnuextensions			 Support some GNU and Microsoft language extensions
#	-unrecogdirective		 Preprocessor directive is not recognized
#	-oldstyle				 Function definition is in old style syntax.  Standard prototype syntax is preferred
#	-mutrep					 Representation of mutable type has sharing semantics
#	-macroredef				 Macro is redefined
#	-varuse					 Variable never used
#	-macrovarprefix 		 Set namespace prefix for variables declared in a macro body
#	-charindex				 Allow char to index arrays
#	-nullpass				 A possibly null pointer is passed as a parameter corresponding to a formal parameter
#	-predboolothers			 Type of condition test is not a Boolean, pointer or integral type
#	-mustfreefresh			 Allocated storage was not released before return or scope exit
#	-statictrans			 Static storage is transferred in an inconsistent way
#	-aliasunique			 An actual parameter that is passed as a unique formal parameter is aliased by another parameter or global variable
#	-compdef				 Storage derivable from a parameter, return value or global variable is not completely defined
#	-globstate				 A function returns with global in inconsistent state (null or undefined)
#	-usedef					 The value of a location that may not be initialized on some execution path is used
#	-boolops				 The operand of a boolean operator is not a boolean
#	-sysdirs <dir>			 Set directories for system files (default is /usr/)
#	+skipsysheaders			 Prevent inclusion of all header files in system directories
#	-noeffect				 Statement has no effect
#	+enumindex				 Allow members of enum type to index arrays
#	-nullret				 Function returns a possibly null pointer
#	-nullstate				 A possibly null pointer is reachable from a parameter or global variable
#	-compmempass			 Storage derivable from a parameter does not match the alias kind expected for the formal parameter
#	-compdestroy			 All only references derivable from out only parameter of type void * must be released
#	-unrecogcomments		 Stylized comment is unrecognized
#	-likelybool				 Splint has found a type which appears to be the boolean type - Splint can use just one type as boolean type
#	+timedist				 Display distribution of where checking time is spent
#	-warnposix				 Don't show warnings for posix headers (f.e. dirent.h)
#	-formattype				 Type-mismatch in parameter corresponding to format code in a printflike or scanflike function (f.e. TUint8 instead of expected int)
#	-noret					 There is a path with no return in a function declared to return a non-void value
#	-unrecog				 An unrecognized identifier is used
#	+fcnmacros				 Macros defined with parameter lists are not expanded and are checked as functions
#	-macroassign			 A macro parameter is used as the left side of an assignment expression
#	-macroparens			 A macro parameter is used without parentheses (in potentially dangerous context)
#	-macroparams			 Each parameter to a macro must be used exactly once in all possible executions of the macro
#	-macrofcndecl			 Macro definition with parameter list has no corresponding function prototype. Without a prototype, the types of the macro result and parameters are unknown
#	-structimponly			 Assume unannotated structure or union field is only
#
#	Lint - Equivalents
#	-redef					 A function or variable is defined more than once																		-e14
#	-initsize				 Initializer block contains more elements than the size of a declared array												-e85
#	+singleinclude			 Optimize header inclusion to only include each header file once														-e537
#	-relaxquals				 Report qualifier mismatches (larger to smaller type)																	-e734
#	-retval					 Return value ignored																									-e534
#	-unsignedcompare		 An unsigned value is used in a comparison with zero in a way that is either a bug or confusing							-e583
#	-forwarddecl			 Forward declarations of pointers to abstract representation match abstract type						**default		-e818
#	-infloops				 Likely infinite loop is detected																						-e716
#	-immediatetrans			 An immediate address (result of &) is transferred inconsistently														-e545
#	-enumint				 Make enum and int types equivalent																						-e641
#	-exportlocal			 A declaration is exported but not used outside this module. (Declaration can use the static qualifier.)				-e765
#	-macroempty				 Macro definition of a function is empty																**default		-e750
#	-paramuse				 Function parameter never used																							-e715
#	-topuse					 An external declaration is not used in any file														**default		-e714
#	-fcnuse					 Function is never used 																								-e714
#	-evalorder				 subexpressions contain interfering side effects that may be evaluated in any order										-e522
#	-misscase				 A switch on an enum type is missing a case for a member of the enumerator												-e788
#	-ansi89limits			 Check for violations of minimum limits prescribed by ANSI C89 standard													-e793
#	-iso99limits			 Check for violations of minimum limits prescribed by ISO C99 standard													-e793
#	-linelen				 Set length of maximum message line to <number> characters. Splint will split messages longer than <number>				-width(x,y)
#
#	Preprocessor-Definition of constants
#	-D<new_identifier>=<identifier>
#
##################################################################################################################################################################

generateLCD: $(LCD_HEADER) $(SPLINT)
	-rm -f $(PLATFORM_PATH)/env/_com/lint/splint/general.lcd
	-$(SPLINT) -nof -nolib +impconj $(LCD_HEADER) -dump $(PLATFORM_PATH)/env/_com/lint/splint/general
	@touch $(PLATFORM_PATH)/env/_com/lint/splint/general.lcd
	
LINT_RULE = 	-structimponly -statictrans -macrofcndecl -macroparams -macroparens -macroassign +fcnmacros -imptype -format-type -likelybool \
				-unrecogcomments -compdestroy -compmempass -nullstate -noeffect +enumindex -nullret -boolops -globstate -compdef -aliasunique \
				-mustfreefresh -predboolothers -nullpass +charindex -macrovarprefix "m__" -macroredef -linelen 10000 -hints -preproc -nestcomment -maintype \
				-type -predboolint -fixedformalarray -nullassign -incondefs -mustfreeonly -gnuextensions -mutrep -redef -initsize +singleinclude \
				-relaxquals -retval -unsignedcompare -infloops -immediatetrans -enumint -exportlocal -paramuse -fcnuse -evalorder -misscase -ansi89limits -iso99limits \
				-sysdirs L:/MinGW/include +skipsysheaders -warnposix \
				
LINT_PREPROC = 	 -D__builtin_va_list=void* \
				 -D__const=const \
				 -Dconst=const \
				 -D__null=0 \
				 -D__typeof=__typeof__ \
				 -D__PRETTY_FUNCTION__=__func__ \
				 -D__FUNCTION__=__func__ \
				 -D__inline=inline \
				 -D__inline__=inline \
				 -D__signed__=signed \
				 -D__signed=signed \
				 -D__volatile__=volatile \
				 -D__volatile=volatile \
				 -Dasm=_up_to_brackets \
				 -D__asm=_up_to_brackets \
				 -D__asm__=_up_to_brackets \
				 -D__alignof__=__alignof \
				 -DLINT_SWITCH_IGNORE= \
				 -D_CRTIMP=  \
				 -D__MINGW_NOTHROW= \
				 -D__cdecl= \
				 -D__restrict__=restrict \
				 #-D__builtin_stdarg_start()=_to_semi \
				 -D__builtin_va_end()=_to_semi \
				 -D"__builtin_va_arg(a,b)=(*( (b *) ( ((a) += sizeof(b)) - sizeof(b) ))) \
				 -D__builtin_strchr=(char*) \
				 -D__builtin_strpbrk=(char*) \
				 -D__builtin_strrchr=(char*) \
				 -D__builtin_strstr=(char*) \" 
				
LCD_HEADER = \
	L:/Splint/lib/standard.h #\
	L:\MinGW\include\string.h 