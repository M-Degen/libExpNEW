### Build with HyRebuilder Version: 05.24.02 ####

SUB_CC_INCLUDES = \
-I"$(ROOT_PATH)/include" \
-I"$(ROOT_PATH)/include/basic"  \
-I"$(ROOT_PATH)/include/core"  \
-I"$(ROOT_PATH)/include/core/board"  \
-I"$(ROOT_PATH)/include/core/pin"  \
-I"$(ROOT_PATH)/include/library"  \
-I"$(ROOT_PATH)/include/library/standard"  \
-I"$(ROOT_PATH)/include/library/testsuite"  \
-I"$(ROOT_PATH)/include/library/testsuite/cvtest"  \
-I"$(ROOT_PATH)/include/protocol"  \
-I"$(ROOT_PATH)/include/protocol/PtcMst"  \
-I"$(ROOT_PATH)/src" \
-I"$(ROOT_PATH)/src/app_libs"  \
-I"$(ROOT_PATH)/src/_app"  \
-I"$(ROOT_PATH)/src/_app/2App"  \
-I"$(ROOT_PATH)/src/_app/AUTO_CEN_TTC3X" 


SUB_LIB_EXT = \
$(ROOT_PATH)/include/_lib/TTC32S/hw/core/CEN_TTC32S_HW_CoreBasStd.lib \
$(ROOT_PATH)/include/_lib/TTC32S/hw/protocol/CEN_TTC32S_HW_PtcMst.lib


SUB_OBJECTS = \
$(OUT_PATH)/src/app_libs/AppFunc.obj \
$(OUT_PATH)/src/main_cen.obj \
$(OUT_PATH)/src/_app/2App/2AppCode.obj \
$(OUT_PATH)/src/_app/AppBspMem.obj \
$(OUT_PATH)/src/_app/AppCode.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/App_LibTab.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/App_Pin.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/Cfg_CBus.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/Cfg_Ecu.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/Cfg_LibRegistry.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/Cfg_PtcMst.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/Cfg_Sil.obj \
$(OUT_PATH)/src/_app/AUTO_CEN_TTC3X/Cfg_Ver.obj


SUB_LINT = \
-I$(LINT_PATH)\include \
-I$(LINT_PATH)\include\basic \
-I$(LINT_PATH)\include\core \
-I$(LINT_PATH)\include\core\board \
-I$(LINT_PATH)\include\core\pin \
-I$(LINT_PATH)\include\library \
-I$(LINT_PATH)\include\library\standard \
-I$(LINT_PATH)\include\library\testsuite \
-I$(LINT_PATH)\include\library\testsuite\cvtest \
-I$(LINT_PATH)\include\protocol \
-I$(LINT_PATH)\include\protocol\PtcMst \
-I$(LINT_PATH)\src \
-I$(LINT_PATH)\src\app_libs \
-I$(LINT_PATH)\src\_app \
-I$(LINT_PATH)\src\_app\2App \
-I$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X \
	$(LINT_PATH)\src\app_libs\AppFunc.c \
	$(LINT_PATH)\src\main_cen.c \
	$(LINT_PATH)\src\_app\2App\2AppCode.c \
	$(LINT_PATH)\src\_app\AppBspMem.c \
	$(LINT_PATH)\src\_app\AppCode.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\App_LibTab.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\App_Pin.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\Cfg_CBus.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\Cfg_Ecu.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\Cfg_LibRegistry.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\Cfg_PtcMst.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\Cfg_Sil.c \
	$(LINT_PATH)\src\_app\AUTO_CEN_TTC3X\Cfg_Ver.c
