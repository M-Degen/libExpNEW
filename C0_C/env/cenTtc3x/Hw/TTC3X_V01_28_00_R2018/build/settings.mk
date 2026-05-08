###############################################################################
#                                                                             #
#  XC2000  IO-Library                                                         #
#                                                                             #
#  Settings for the make file                                                 #
#                                                                             #
###############################################################################
SHELL=cmd.exe

###############################################################################
#
# PATH TO IO-DRIVER FILES
#
###############################################################################
ifeq ($(IODRIVER_DIR), )
	IODRIVER_DIR = $(CURDIR)
endif

###############################################################################
#
# FLAGS FOR BUILD PROCESS
#
###############################################################################

# Generation of Debug information
# set the variable DEBUGINFO=false to omit debug info from library/binary
# by default debug information is generated
ifeq "$(origin DEBUGINFO)" "undefined"
	DEBUGINFO=true
endif

DEBUGINFO=true

###############################################################################
#
# PATH TO COMPILER INSTALATIONS
#
###############################################################################

# Tasking VX toolset
TSK_VIPER_PATH = C:\Program Files (x86)\TASKING\C166-VX v3.0r3

###############################################################################
#
# TARGET DEPENDENCIES
#
###############################################################################

ifeq ($(TARGET), TTC30SH)
		#
		# TTC30SH uses XC2267,
		# has no external RAM, 
		# and provides safety features
		# ONLY the viper compiler is supported!!
		
		CPUNAME = XC2267-96F
		LIB_TARGET = ttc30sh
		DOWNLOADER_HW_TYPE=0x00002006
		TSK_VIPER_COMP_FLAGS = -DTTC30SH -DSAFETY
else
ifeq ($(TARGET), TTC30H)
		#
		# TTC30H uses XC2267,
		# has no external RAM, 
		# and provides no safety features
		# ONLY the viper compiler is supported!!
		
		CPUNAME = XC2267-96F
		LIB_TARGET = ttc30h
		DOWNLOADER_HW_TYPE=0x00002406
		TSK_VIPER_COMP_FLAGS += -DTTC30H 
else
ifeq ($(TARGET), TTC32)
		#
		# TTC32 uses XC2267,
		# has no external RAM, 
		# and provides no safety features
		# ONLY the viper compiler is supported!!
		
		CPUNAME = XC2267-96F
		LIB_TARGET = ttc32
		DOWNLOADER_HW_TYPE=0x00002C06
		TSK_VIPER_COMP_FLAGS += -DTTC32H 
else
ifeq ($(TARGET), TTC32S)
		#
		# TTC32S uses XC2267,
		# has no external RAM, 
		# and provides no safety features
		# ONLY the viper compiler is supported!!
		
		CPUNAME = XC2267-96F
		LIB_TARGET = ttc32s
		DOWNLOADER_HW_TYPE=0x00003006
		TSK_VIPER_COMP_FLAGS += -DTTC32SH -DSAFETY
else
ifeq ($(TARGET), )
    $(error * Please specify the TARGET which shall be compiled)
    $(error * use one of:)
    $(error *      TTC30H, TTC30SH)
    $(error *      TTC32, TTC32S)
# else
# if a target is defined which is unknown to this settings.mk
# (e.g. the test-kernel variants of the ttc30 for PCB variants)
# then the variables CPUNAME, LIB_TARGET, DOWNLOADER_HW_TYPE and
# TSK_VIPER_COMP_FLAGS have to be defined manually before including this
# settings-file
endif
endif
endif
endif
endif

###############################################################################
#
# COMPILER OPTIONS 
#
###############################################################################

# Tasking Viper compiler flags

CPUTYPE = $(firstword  $(subst -, , $(CPUNAME)))

SFR_FILE = sfr\regxc2267.h
SFR_ADDR_FILE = sfr\regxc2267_addr.h

TSK_VIPER_COMP_FLAGS += -t -Wa-gAHLs --emit-locals=-equ,-symbols -Wa-OgsaJ --section-info=-console -Wa--error-limit=42
TSK_VIPER_COMP_FLAGS += -Mh --iso=99 --language=+cmp14,+div32,-gcc,-strings --mac --tradeoff=0 --source
TSK_VIPER_COMP_FLAGS += -C$(CPUNAME) -Wa-C$(CPUTYPE)

TSK_VIPER_COMP_FLAGS += -Wc-H$(SFR_FILE) -Wc-H$(SFR_ADDR_FILE) -Wc--no-tasking-sfr
TSK_VIPER_COMP_FLAGS += -D__USIC_MEM_TYPE=__far -D__MULTICAN_MEM_TYPE=__far 

ifeq ($(DEBUGINFO),true)
	TSK_VIPER_COMP_FLAGS += -Wc-ga
endif

###############################################################################
#
# LINKER OPTIONS 
#
###############################################################################

# Tasking Viper linker flags
TSK_VIPER_LINK_FLAGS = -t -Wl-OtZXycL -mcrfiklSmNuQ -Wl--error-limit=42 -Wc-ga -Mh
TSK_VIPER_LINK_FLAGS += -C$(CPUNAME)

###############################################################################
#
# INTERNAL SETTINGS - GENERATED FROM OPTIONS SET ABOVE
#
#   DO NOT CHANGE ANYTHING HERE
#
###############################################################################
#
# PATH SETTINGS     
#

# Directory where sources are located
IODRIVER_SDIR = $(subst \,/,$(IODRIVER_DIR)\src)

# Directory where lib will be stored
IODRIVER_LDIR = $(subst \,/,$(IODRIVER_DIR)\lib)

# Path to Board Support Package
IODRIVER_BDIR = $(subst \,/,$(IODRIVER_DIR)\bsp)

# Include directories for compiler
INCDIRS = -I"$(IODRIVER_DIR)\inc"
INCDIRS += -I"$(IODRIVER_DIR)\inc_int"
INCDIRS += -I"$(IODRIVER_DIR)\bsp" 
INCDIRS += -I"$(IODRIVER_DIR)\bsp\sfr" 


###############################################################################
#
# TARGET DEPENDENCIES
#
###############################################################################
#
# FILE NAME SETTINGS
#

# list of all source and object files. afterwards all variant depending config files are removed
TEMP_FILES := $(notdir $(basename $(wildcard $(IODRIVER_SDIR)/*.c)))
TEMP_FILES := $(filter-out IO_INT_Cfg%, $(TEMP_FILES))
# Filter out DBG module - Gets added explicitely for non-safety variants later
TEMP_FILES := $(filter-out IO_INT_DBG%, $(TEMP_FILES))

# assemble correct file list for each variant
ifeq ($(TARGET), TTC30SH)
		TEMP_FILES  += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_Cfg_TTC30SH.c))
else
ifeq ($(TARGET), TTC30H)
		TEMP_FILES  += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_Cfg_TTC30H.c))
		# Add DBG module for non-safety variant
		TEMP_FILES += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_DBG.c))
else
ifeq ($(TARGET), TTC32)
		TEMP_FILES  += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_Cfg_TTC32H.c))
		# Add DBG module for non-safety variant
		TEMP_FILES += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_DBG.c))        
		# do not compile IO_NodeID module for TTC32 variants
		TEMP_FILES := $(filter-out IO_NodeID, $(TEMP_FILES))
else
ifeq ($(TARGET), TTC32S)
		TEMP_FILES  += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_Cfg_TTC32SH.c))
		# do not compile IO_NodeID module for TTC32 variants
		TEMP_FILES := $(filter-out IO_NodeID, $(TEMP_FILES))
else
		TEMP_FILES  += $(notdir $(basename $(IODRIVER_SDIR)/IO_INT_Cfg_TTC30H.c))
endif
endif
endif
endif

FILES = $(TEMP_FILES)
ASM_FILES = $(notdir $(basename $(wildcard $(IODRIVER_SDIR)/*.asm)))

OBJ_FILES := $(addprefix ./build/$(TARGET)/, $(addsuffix .obj, $(notdir $(FILES)))) $(addprefix ./build/$(TARGET)/asm_, $(addsuffix .obj, $(notdir $(ASM_FILES))))
LIB_NAME = xc2000_$(LIB_TARGET).lib 




#
# Executeables for Toolset
#
TKS_VIPER_C = $(TSK_VIPER_PATH)\bin\c166
TSK_VIPER_CC = $(TSK_VIPER_PATH)\bin\cc166
TSK_VIPER_LNK = $(TSK_VIPER_PATH)\bin\cc166
TSK_VIPER_AR = $(TSK_VIPER_PATH)\bin\ar166
TSK_VIPER_ASM = $(TSK_VIPER_PATH)\bin\as166


# insert the build date
BUILDDATE_F = $(IODRIVER_DIR)\build\builddate\getbuilddate.exe
BUILDDATE_FUNC = $(subst \,\\,$(BUILDDATE_F))
DATE_S := $(shell $(BUILDDATE_FUNC))

BUILD_DAY = $(word 1, $(DATE_S))
BUILD_MONTH = $(word 2, $(DATE_S))
BUILD_YEAR = $(word 3, $(DATE_S))
BUILD_HOUR = $(word 4, $(DATE_S))
BUILD_MIN = $(word 5, $(DATE_S))

TSK_VIPER_COMP_FLAGS += -DRTS_TTC_FLASH_DATE_YEAR=$(BUILD_YEAR)
TSK_VIPER_COMP_FLAGS += -DRTS_TTC_FLASH_DATE_MONTH=$(BUILD_MONTH)
TSK_VIPER_COMP_FLAGS += -DRTS_TTC_FLASH_DATE_DAY=$(BUILD_DAY)
TSK_VIPER_COMP_FLAGS += -DRTS_TTC_FLASH_DATE_HOUR=$(BUILD_HOUR)
TSK_VIPER_COMP_FLAGS += -DRTS_TTC_FLASH_DATE_MINUTE=$(BUILD_MIN)
