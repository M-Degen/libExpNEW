####################################################################################################
#
# Makefile for MinGw
# (c) Copyright by Hydac System GmbH, all rights reserved
#
# DESCRIPTION:  makefile 
# PROJECT:      Hydac Project 
# Note:         for windows commands '\' and for the pur make process '/'
#
# FILE VERSION INFORMATION:
#	$Filename:  main_cen_ttc3x_pc.mk
#	$Version:   9.0
#	$Build No:  0
#	$Date:      12.03.2021
#
####################################################################################################

####################################################################################################
# Configuration
####################################################################################################

ifeq ($(ECU_TYPE),TTC30H)
TARGET_BIG   =TTC30H
TARGET_SMA   =ttc30h
SUB_ECU_BIG  =TTC30
SUB_ECU_SMA  =ttc30
endif
ifeq ($(ECU_TYPE),TTC30SH)
TARGET_BIG   =TTC30SH
TARGET_SMA   =ttc30sh
SUB_ECU_BIG  =TTC30
SUB_ECU_SMA  =ttc30
endif
ifeq ($(ECU_TYPE),TTC32)
TARGET_BIG   =TTC32
TARGET_SMA   =ttc32
SUB_ECU_BIG  =TTC32
SUB_ECU_SMA  =ttc32
endif
ifeq ($(ECU_TYPE),TTC32S)
TARGET_BIG   =TTC32S
TARGET_SMA   =ttc32S
SUB_ECU_BIG  =TTC32
SUB_ECU_SMA  =ttc32
endif

####################################################################################################
# Include makefiles
####################################################################################################

# a need for the sub_cen_*.mk
LINT_PATH =.\env\..
ADD_BSP_INC =

ROOT_PATH    = .
OUT_PATH     =_debug/cen_pc/$(TARGET_BIG)
ECU_CORE_LIB =$(TARGET_BIG)

include env/project.mk
include env/cenTtc3x/Pc/_setting/cen_ttc3x_pc_compiler_settings.mk
include env/cenTtc3x/Pc/sub_cen_ttc3x_pc.mk
include env/_com/general.mk


####################################################################################################
# Include paths to header filesDPDrv
####################################################################################################

AS_INCLUDES  =

CC_INCLUDES  =$(SUB_CC_INCLUDES) -I.

####################################################################################################
# Path to libraries which should be included
####################################################################################################

LIB_PC_INTERN += $(MPULIB_TARGET) 

LIB_CORE       = $(ROOT_PATH)/include/_lib/$(TARGET_BIG)/pc/core/CEN_$(TARGET_BIG)_PC_CoreBasStd.a  

LIB_EXT        = $(SUB_LIB_EXT)

####################################################################################################
# List of object files to create
####################################################################################################

OBJECTS   = $(SUB_OBJECTS)

OBJECTLIST = $(ROOT_PATH)\env\cenTtc3x\Pc\sub_cen_ttc3x_obj_pc.txt

###################################################################################################
# Compiler, assembler and linker options
###################################################################################################

CC_FLAGS        += -Wall -O0 -fshort-enums
AS_FLAGS        +=
LINKER_FLAGS    += -Wl,-Map,$(OUT_PATH)/$(OUTPUT_NAME).map

####################################################################################################
# DON'T EDIT SOMETHING BELOW THIS LINE
####################################################################################################

TARGET = $(OUT_PATH)/$(OUTPUT_NAME)

REBUILD_PARM = -pc -$(TARGET_BIG) -rv$(RELEASE_VER) -pj$(OUTPUT_NAME) -s$(ROOT_PATH)\env\cenTtc3x\Pc\_setting\cen_$(TARGET_SMA)_pc_autoconfig.ach -t$(ROOT_PATH)\src\autoconfig.h -objectlist

all:
	@$(HYTERMINAT) $(OUTPUT_NAME).exe
	$(HYREBUILD) $(REBUILD_PARM) -check 
	@$(HYVALIDATE) -$(RELEASE) -env  -uenv\_com 
	@$(HYVALIDATE) -$(RELEASE) -env  -uenv\_utility 
	@$(HYVALIDATE) -$(RELEASE) -env  -uenv\cenTtc3x\Pc 
	@$(HYVALIDATE) -$(RELEASE) -lib  -uinclude\_lib\$(TARGET_BIG)\pc -iinclude -pc
	@$(HYVALIDATE) -$(RELEASE) -file -usrc\_app\AUTO_CEN_$(TARGET_BIG)\_auto.ucc   -usrc\_app\AUTO_CEN_TTC3X\_auto.ucc
	@$(HYVALIDATE) -$(RELEASE) -fileop -usrc\_app\AUTO_CEN_$(TARGET_BIG)\_auto.ucc -usrc\_app\AUTO_CEN_TTC3X_2APP\_auto.ucc
	@$(HYPARSER_CALL) 
	@$(HYDEPCLEANER) -p"$(ROOT_PATH)" -d"$(DEPCLEAN)"
	@$(HYREBUILD) $(REBUILD_PARM) -$(DEPCLEAN) -change 
	@$(PC_PRE_MAKE)
	@env\_com\make -s -f env\cenTtc3x\Pc\main_cen_ttc3x_pc.mk ECU_TYPE=$(ECU_TYPE) $(TARGET) -j$(BUILD_PARALLEL) 
	@$(PC_POST_MAKE)
	@$(MINGW_PATH)\bin\size $(TARGET).exe > $(TARGET).map
	@$(HYMAPSCAN) $(TARGET).map PC
	@$(LINT)
	@$(HYEND) $(RELEASE)

clean:
	@$(HYREBUILD) $(REBUILD_PARM)

$(TARGET): $(OBJECTS)
	$(CC) 	-g -o $(TARGET) @$(OBJECTLIST) $(LIB_EXT) $(LIB_CORE) $(LIB_EXT) $(LIB_PC_INTERN)

$(OUT_PATH)/%.o: %.S  
	@echo compiling: $<
	@$(CC) -g -c -o $@ $< $(AS_FLAGS) $(AS_INCLUDES)

$(OUT_PATH)/%.o: %.ss 
	@echo compiling: $<
	@$(CC) -g -c -o $@ $< $(AS_FLAGS) $(AS_INCLUDES)

$(OUT_PATH)/%.o: %.c
	@echo compiling: $<
	@$(CC) -g -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)
	
$(OUT_PATH)/%.o: %.cpp
	@echo compiling: $<
	@$(CPP) -g -c -o $@ $< $(CC_FLAGS) $(CC_INCLUDES)