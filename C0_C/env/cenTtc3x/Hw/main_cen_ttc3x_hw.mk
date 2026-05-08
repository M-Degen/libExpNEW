####################################################################################################
#
# Makefile for Tasking
# (c) Copyright by Hydac System GmbH, all rights reserved
#
# DESCRIPTION:  makefile 
# PROJECT:      Hydac Project 
# Note:         for windows commands '\' and for the pur make process '/'
#
# FILE VERSION INFORMATION:
#	$Filename:  main_cen_ttc3x_hw.mk
#	$Version:   9.0
#	$Build No:  0
#	$Date:      12.03.2021
#
####################################################################################################

### ttc library files ### 

ifeq ($(ECU_TYPE),TTC30H)
### Programming in C, non-safety-hydraulic
HY_IO_LIB    =$(PRJ_DIR)/lib/xc2000_TTC30h.lib 
TARGET_BIG   =TTC30H
TARGET_SMA   =ttc30h
SUB_ECU_BIG  =TTC30
SUB_ECU_SMA  =ttc30
endif
ifeq ($(ECU_TYPE),TTC30SH)
### set to CSH - Programming in C, safety-hydraulic
HY_IO_LIB    =$(PRJ_DIR)/lib/xc2000_TTC30sh.lib 
TARGET_BIG   =TTC30SH
TARGET_SMA   =ttc30sh
SUB_ECU_BIG  =TTC30
SUB_ECU_SMA  =ttc30
endif
ifeq ($(ECU_TYPE),TTC32)
### Programming in C, non-safety-hydraulic
HY_IO_LIB    =$(PRJ_DIR)/lib/xc2000_TTC32.lib 
TARGET_BIG   =TTC32
TARGET_SMA   =ttc32
SUB_ECU_BIG  =TTC32
SUB_ECU_SMA  =ttc32
endif
ifeq ($(ECU_TYPE),TTC32S)
### set to CSH - Programming in C, safety-hydraulic
HY_IO_LIB    =$(PRJ_DIR)/lib/xc2000_TTC32S.lib 
TARGET_BIG   =TTC32S
TARGET_SMA   =ttc32s
SUB_ECU_BIG  =TTC32
SUB_ECU_SMA  =ttc32
endif

### Lib control ####
RELEASE_VER = TTC3X_V01_28_00_R2018
BL_MAJOR    = 3
BL_MINOR    = 6

### project naming and release/debug ####
ifeq ($(DEBUG_INFO),YES)
	DEBUGINFO   =true
endif

### absolute enviroment path ####
ROOT_PATH    =.
PRJ_DIR	     =$(ROOT_PATH)/env/cenTtc3x/Hw/$(RELEASE_VER)

### relative enviroment path ####
BSP_DIR		=$(PRJ_DIR)/bsp
INC_DIR		=$(PRJ_DIR)/inc
COM_DIR		=$(PRJ_DIR)/com

### compiler setting ###
COMPILER			  =viper
COMPILER_TOOL_SETTING =HYDAC
TARGET 				  =$(TARGET_BIG)

### project naming and release/debug ####

LINT_PATH =.\env\..
ADD_BSP_INC = -I.\env\cenTtc3x\Hw\$(RELEASE_VER)\inc


include env/project.mk

# a need for the sub_cen_*.mk

include $(COM_DIR)/settings.mk
include env/cenTtc3x/Hw/sub_cen_ttc3x_hw.mk
include env/_com/general.mk


### output path  ###
OUT_PATH	=_debug\cen_hw\$(TARGET_BIG)

### bsp files ###
BSP_START_FILE =$(BSP_DIR)/bsp_cstart_$(SUB_ECU_SMA)x.obj

### linker file name ###
LSL_FILE  =$(COM_DIR)/application_moreStack.lsl

### include ###
INCDIRS +=  $(SUB_CC_INCLUDES)

### hcp library file ###
LIB_CORE = $(ROOT_PATH)/include/_lib/$(TARGET_BIG)/hw/core/CEN_$(TARGET_BIG)_HW_CoreBasStd.lib 

LIB_EXT = $(SUB_LIB_EXT)

### objects files ###
OBJECTS  = $(SUB_OBJECTS)

OBJECTLIST = $(ROOT_PATH)\env\cenTtc3x\Hw\sub_cen_ttc3x_obj_hw.txt

## build rules
REBUILD_PARM = -hw -$(TARGET_BIG) -rv$(RELEASE_VER) -pj$(OUTPUT_NAME) -s$(ROOT_PATH)\env\cenTtc3x\Hw\_setting\cen_$(TARGET_SMA)_hw_autoconfig.ach  -t$(ROOT_PATH)\src\autoconfig.h -objectlist

### build rule ###
all:
	$(HYREBUILD) $(REBUILD_PARM) -check
	@$(HYVALIDATE) -$(RELEASE) -env  -uenv\_com 
	@$(HYVALIDATE) -$(RELEASE) -env  -uenv\_utility 
	@$(HYVALIDATE) -$(RELEASE) -env  -uenv\cenTtc3x\Hw 
	@$(HYVALIDATE) -$(RELEASE) -lib  -uinclude\_lib\$(TARGET_BIG)\hw -iinclude -hw 
	@$(HYVALIDATE) -$(RELEASE) -file -usrc\_app\AUTO_CEN_$(SUB_ECU_BIG)\_auto.ucc -usrc\_app\AUTO_CEN_TTC3X\_auto.ucc
	@$(HYVALIDATE) -$(RELEASE) -fileop -usrc\_app\AUTO_CEN_$(SUB_ECU_BIG)\_auto.ucc -usrc\_app\AUTO_CEN_TTC3X_2APP\_auto.ucc
	@$(HYPARSER_CALL) 
	@$(HYDEPCLEANER) -p"$(ROOT_PATH)" -d"$(DEPCLEAN)"
	@$(HYREBUILD) $(REBUILD_PARM) -$(DEPCLEAN) -change
	@$(HW_PRE_MAKE)
	@env\_com\make -s -f env\cenTtc3x\Hw\main_cen_ttc3x_hw.mk ECU_TYPE=$(ECU_TYPE) $(OUTPUT_NAME).elf -j$(BUILD_PARALLEL)  
	@$(HW_POST_MAKE)
	@$(HYMAPSCAN) $(OUT_PATH)\$(OUTPUT_NAME).map $(TARGET_BIG)
	@echo ***
	@$(LINT)
	@$(RM) -f $(ROOT_PATH)\nowECC.log
	@$(RM) -f $(ROOT_PATH)\AddAPDB.html
	@$(HYEND) $(RELEASE)


### clean rule ###
clean:
	$(HYREBUILD) $(REBUILD_PARM)

ifeq ($(CPP_TSK_WARN_REPORT), NO)
TSK_CPP_FLAGS = --no-warnings 
else
TSK_CPP_FLAGS = 
endif


.PHONY: $(OUTPUT_NAME).elf 
$(OUTPUT_NAME).elf: $(HY_IO_LIB) $(BSP_START_FILE) $(OBJECTS) $(OBJECTLIST)
	@echo linking $@
	@"$(TSK_VIPER_LNK)" -o"$@" $(BSP_START_FILE) -f $(OBJECTLIST) $(HY_IO_LIB) $(LIB_EXT) $(LIB_CORE)\
	-Wl-o"$(OUT_PATH)/$(OUTPUT_NAME).hex":IHEX -Wl-o"$(OUT_PATH)/$(OUTPUT_NAME).s19":SREC $(TSK_VIPER_LINK_FLAGS) \
	-Wl--map-file="$(OUT_PATH)/$(OUTPUT_NAME).mapxml":XML $(LSL_FILE)
	@if exist $(OUT_PATH)\$(OUTPUT_NAME).hex.addAPDB del $(OUT_PATH)\$(OUTPUT_NAME).hex.addAPDB
	@if exist $(OUT_PATH)\$(OUTPUT_NAME).s19.addAPDB del $(OUT_PATH)\$(OUTPUT_NAME).s19.addAPDB
	@"$(PRJ_DIR)"\\build\\AddAPDB.exe -t $(DOWNLOADER_HW_TYPE) -v $(BL_MAJOR).$(BL_MINOR) -w 32 -f I -k $(PRJ_DIR)\build\public.key "$(PRJ_DIR)"\\build\\targets.xml $(OUT_PATH)\$(OUTPUT_NAME).hex $(OUT_PATH)\$(OUTPUT_NAME).hex.addAPDB
	@"$(PRJ_DIR)"\\build\\AddAPDB.exe -t $(DOWNLOADER_HW_TYPE) -v $(BL_MAJOR).$(BL_MINOR) -w 32 -f M -k $(PRJ_DIR)\build\public.key "$(PRJ_DIR)"\\build\\targets.xml $(OUT_PATH)\$(OUTPUT_NAME).s19 $(OUT_PATH)\$(OUTPUT_NAME).s19.addAPDB
	$(COPY) -f $(OUT_PATH)\$(OUTPUT_NAME).hex.addAPDB $(OUT_PATH)\$(OUTPUT_NAME).hex
	$(COPY) -f $(OUT_PATH)\$(OUTPUT_NAME).s19.addAPDB $(OUT_PATH)\$(OUTPUT_NAME).s19
	@if exist $(OUT_PATH)\$(OUTPUT_NAME).hex.addAPDB del $(OUT_PATH)\$(OUTPUT_NAME).hex.addAPDB
	@if exist $(OUT_PATH)\$(OUTPUT_NAME).s19.addAPDB del $(OUT_PATH)\$(OUTPUT_NAME).s19.addAPDB
	$(COPY)  $(OUTPUT_NAME).map $(OUT_PATH)
	$(COPY)  $(OUTPUT_NAME).elf $(OUT_PATH)
	$(RM) -f $(OUTPUT_NAME)
	$(RM) -f $(OUT_PATH)\src.elf
	$(RM) -f $(OUT_PATH)\src.map
	$(RM) -f $(OUT_PATH)\src.mdf
	$(RM) -f $(ROOT_PATH)\$(OUTPUT_NAME).elf
	$(RM) -f $(ROOT_PATH)\$(OUTPUT_NAME).mdf
	$(RM) -f $(ROOT_PATH)\$(OUTPUT_NAME).map
	$(RM) -f $(ROOT_PATH)\AddAPDB.html

### debug test files ###
$(OUT_PATH)/%.obj : %.c
	@echo compiling: $<
	@"$(TSK_VIPER_CC)" -c -o $@ $(TSK_VIPER_COMP_FLAGS) $(INCDIRS)$<
	
$(OUT_PATH)/%.obj : %.cpp
	@echo compiling: $<
	@"$(TSK_VIPER_CC)" -c -o $@ $(TSK_VIPER_COMP_FLAGS) $(TSK_CPP_FLAGS) $(INCDIRS)$<

