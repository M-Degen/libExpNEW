#####################################################################################################
#
# Makefile for MinGw
# (c) Copyright by Hydac System GmbH, all rights reserved
#
# DESCRIPTION:  makefile 
# PROJECT:      Hydac Project 
# Note:         for windows commands '\' and for the pur make process '/'
#
# FILE VERSION INFORMATION:
#	$Filename:  general_pc.mk
#	$Version:   1.0
#	$Build No:  0
#	$Date:      03.03.2021
#
####################################################################################################


####################################################################################################
# Internal Library (PC-ONLY)
####################################################################################################

LIB_PC_INTERN = $(ROOT_PATH)/env/_com/peak_lib/CanApi4_win32.lib \
				$(ROOT_PATH)/env/_com/mem/HySharedMemory.a \
				$(ROOT_PATH)/env/_com/cunit/cunit.a 


####################################################################################################
# Condition queries 
####################################################################################################


ifeq ($(RELEASE), YES)
else
  ifeq ($(RELEASE), NO)
  else
  all: end_wrong_release_check
  endif
endif



ifeq ($(DEBUG_INFO), YES)
else
  ifeq ($(DEBUG_INFO), NO)
  else
  all: end_wrong_debug_check
  endif
endif

HYPARSER_CALL = @$(HYPARSER) ./ env\_com\lint\hyparser\hydac_prefix.txt -$(HY_PARSER) -$(HY_PARSER_EXIT) -ap_tol -const_tol -pv_tol -pct_tol -pf_tol -hyRule
	
ifeq ($(LINT_CHECK), NO)
LINT	=
else
  ifeq ($(LINT_CHECK), YES)
  	ifeq ($(LINT_PLUS), YES)
  		include env/_com/lint/pclintplus/pclintplus.mk
  		include env/project.mk
  		LINT	= $(PCLINTPLUS) $(LINT_RULE) -I$(LINT_INC) $(ADD_BSP_INC) $(SUB_LINT)
  	else
        ifeq ($(LINT_PROGRAM), PCLINT)
          include env/_com/lint/pclint/pclint.mk
          include env/project.mk
          LINT	= $(PCLINT) env\_com\lint\pclint\hy_co-gcc.lnt -h1 -width(0,0) $(LINT_RULE) -I$(LINT_INC) $(ADD_BSP_INC) $(SUB_LINT) 
        else
          ifeq ($(LINT_PROGRAM), SPLINT)
          include env/_com/lint/splint/splint.mk
          include env/project.mk
          LINT	= $(SPLINT) -load env\_com\lint\splint\standard.lcd $(LINT_PREPROC) $(LINT_RULE) $(SUB_LINT) #-strict
          else
          all: end_wrong_lint_program
          endif
        endif
 	endif
  else
  all: end_wrong_lint_check
  endif
endif



ifeq ($(PYTHON_SUITE), NO)
LIB_PC_INTERN += $(ROOT_PATH)/env/_com/script/python_deactive.a
else
  ifeq ($(PYTHON_SUITE), YES)
    ifeq ($(PYTHON_VER), PYH324)
    LIB_PC_INTERN	+=	$(ROOT_PATH)/env/_com/script/python_active.a 
    LIB_PC_INTERN	+=	$(ROOT_PATH)/env/_com/script/python32.a 
    else
      ifeq ($(PYTHON_VER), PYH387)
      LIB_PC_INTERN	+=	$(ROOT_PATH)/env/_com/script/python_active.a
      LIB_PC_INTERN	+=	$(ROOT_PATH)/env/_com/script/python38.a 
      else
      all: end_wrong_python_version
      endif
    endif
  else
  all: end_wrong_python_suite
  endif
endif

ifeq ($(HY_PARSER), YES)
else
  ifeq ($(HY_PARSER), NO)
  else
  all: end_wrong_hy_paser
  endif
endif


ifeq ($(DEPCLEAN), YES)
else
  ifeq ($(DEPCLEAN), NO)
  else
  all: end_wrong_depclean
  endif
endif


ifeq ($(PEAK_LIN_BUS), YES)
LIB_PC_INTERN +=$(ROOT_PATH)/env/_com/peak_lib/PLinApi_active.a 
else
  ifeq ($(PEAK_LIN_BUS), NO)
  LIB_PC_INTERN +=$(ROOT_PATH)/env/_com/peak_lib/PLinApi_deactive.a 
  else
  all: end_wrong_lin_bus
  endif
endif


ifeq ($(MPU_LIB_USE), YES)
else
  ifeq ($(MPU_LIB_USE), NO)
  else
  all: end_wrong_mpu_lib_use
  endif
endif

ifeq ($(TTC5XX_HW_GEN), 1)
else
  ifeq ($(TTC5XX_HW_GEN), 2)
  else
  all: end_wrong_hw_gen
  endif
endif


ifeq ($(CPP_TSK_WARN), YES)
else
  ifeq ($(CPP_TSK_WARN), NO)
  else
  all: end_wrong_cpp_use
  endif
endif

all:

####################################################################################################
# Error output 
####################################################################################################

end_wrong_release_check:
	@echo BUILD ERROR: Wrong paramter for 'RELEASE' only YES or NO can be used!
	@$(HYEND) EXIT


end_wrong_debug_check:
	@echo BUILD ERROR: Wrong paramter for 'DEBUG_INFO' only YES or NO can be used!
	@$(HYEND) EXIT


end_wrong_lint_check:
	@echo BUILD ERROR: Wrong paramter for 'LINT_CHECK' only YES or NO can be used!
	@$(HYEND) EXIT


end_wrong_lint_program:
	@echo BUILD ERROR: Wrong paramter for 'LINT_PROGRAM' only PCLINT or SPLINT can be used!
	@$(HYEND) EXIT


end_wrong_hy_paser:  
	@echo BUILD ERROR: Wrong paramter for 'HY_PASER' only YES or NO can be used!
	@$(HYEND) EXIT


end_wrong_python_suite:
	@echo BUILD ERROR: Wrong paramter for 'PYTHON_SUITE' only YES or NO can be used!
	@$(HYEND) EXIT


end_wrong_python_version:
	@echo BUILD ERROR: Wrong paramter for 'PYTHON_VER' only PYH324 or PYH387 can be used!
	@$(HYEND) EXIT


end_wrong_depclean:
	@echo BUILD ERROR: Wrong paramter for 'DEPCLEAN' only PYH387 or PYH324 can be used!
	@$(HYEND) EXIT


end_wrong_lin_bus:
	@echo BUILD ERROR: Wrong paramter for 'PEAK_LIN_BUS' only YES or NO can be used!
	@$(HYEND) EXIT 


end_wrong_mpu_lib_use:
	@echo BUILD ERROR: Wrong paramter for 'MPU_LIB_USE' only YES or NO can be used!
	@$(HYEND) EXIT


end_wrong_hw_gen:
	@echo BUILD ERROR: Wrong paramter for 'end_wrong_hw_gen' only 1 or 2 can be used!
	@$(HYEND) EXIT


end_wrong_cpp_use:
	@echo BUILD ERROR: Wrong paramter for 'CPP_TSK_WARN' only YES or NO can be used!
	@$(HYEND) EXIT

