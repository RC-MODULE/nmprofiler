#
# This is a universal Makefile for NeuroMatrix projects (application or library) [EDITION 20]
# with automatic recursive search of source files , compiling and linking.
# Makefile is processed by GNU make and may be used both in Linux and Windows OS
#
# To compile it you need: 
# * Latest NMSDK installed with utilities in your $PATH
# * NEURO environment variable pointing to NMSDK directory
# * Host GCC (Since nmcpp doesn't support generating header dependences, we use gcc for that) 
#
# Under OS Windows you need:
# * GNU Make           http://gnuwin32.sourceforge.net/packages/make.htm
# * GNU UNIX utilities http://sourceforge.net/projects/unxutils/
# * PATH enviroment variable pointing to GnuWin32 gcc
# * PATH enviroment variable pointing to GNU make
# * PATH enviroment variable pointing to GNU Utilities  (rm,find..)
#
# NOTE: You can use all-in-one package for Windows (Mingw32 + GNU make + GNU UNIX Utilities) 
#   available at \\dragon\distrib\ext_soft\gcc_make\mingw32_plus_gnumake.zip 
#   set PATH enviroment variable pointing to \mingw32\bin only
#
# USAGE:
#   For release build                    run 'make'
#   For debug   build                    run 'make DEBUG=y'
#   For debug & release  build           run 'make all'
#   For full  rebuild                    run 'make -B'
#   Multithread build (speed up)         run 'make -j4'
#   To clean                             run 'make clean'
#   To clean DEBUG & RELEASE             run 'make cleanall'
#   To create VisualStudio 2005 project  run 'make vs8'
#   For verbose build (no colorizing)    run 'make VERBOSE=y'
#   Execute target                       run 'make run'
#   Execute debug target                 run 'make rund'
#
# WARNING:
#   Makefile is sensitive to leading or trailing spaces and backslashes in the pathes
#
# DEFENITIONS:
#   PROJECT         - project name     
#   TARGET          - output target (.lib or .abs) file with path
#   INC_DIRS        - set of search pathes for the macro libraries and includes (with -I flag separated)
#   SRC_DIRS        - set of explicit  search pathes of all (.c .cpp .asm) source files (with space separated)
#   #SRC_DIR_RECURSE - set of recursive search pathes of all (.c .cpp .asm) source files (with space separated)
#   LIB_DIRS        - set of search library pathes (with -l flag separated)
#   TMP_DIR         - temporary build-folder (Debug/Release)
#   LIBS            - set of (.lib) libraries to be linked (with space separated)
#   
#   CROSS_COMPILE   - prefix before gcc in crosscompiler full name (for example: i686-w64-mingw32-) needed for generation of header dependences
#   CC              - C/C++ compiler(nmcpp/nmcc)
#   CC_FLAGS        - C/C++ compiler(nmcpp/nmcc) flags   
#   AS				- assembler(asm/nmcc)
#   AS_FLAGS        - assembler(asm/nmcc) flags for compiling of pure .asm files 
#   AS_FLAGS_C2ASM  - assembler(asm/nmcc) flags for compiling of .asm files compiled from .c/.cpp sources
#   BUILDER         - builder  (libr/linker) 			
#   BUILDER_FLAGS   - build flags of (libr/linker)
#   RUN_COMMAND     - command line to run target    
#
#   HEADER_DIRS     - set of pathes for .h   files to be included into Visual Studio project (with space separated)
#   RESOURCES       - set of any additionals files to be included into Visual Studio project
#
#============== PROJECT & BUILD CONFIGURATION ==========
#
ifdef NEURO
else 
  $(error *** ERROR: 'NEURO' environment variable is not defined! NMSDK might not have installed correctly. )
  .DEFAULT_GOAL := skip
endif

ROOT = ../../../../..
include $(ROOT)/global.mk
#--------------  target & input dirs -------------------
PROJECT          = mc5103_stdout_nm
OUT_DIR          = .
TARGET           = $(OUT_DIR)/$(PROJECT).abs
INC_DIRS         = -I"$(NEURO)/include" -I$(ROOT)/include 
SRC_DIRS         = . 
LIB_DIRS         = -l"$(NEURO)/lib" -L"$(MC5103)/lib" -L$(NM_IO)/lib -L$(ROOT)/lib
TMP_DIR          = Release
#--------------  RELEASE/ALL config -------------------
CROSS_COMPILE   ?=
AS               = asm 				 
AS_FLAGS         = -nmc3 -nm2ms  $(INC_DIRS)
AS_FLAGS_C2ASM   = -nmc3 -nm2ms  $(INC_DIRS)
LIBS             = nm_io.lib mc5103lib.lib libc05.lib libint05.lib cppnew05.lib nmprofiler-nmc3.lib
CC               = nmcpp
CC_FLAGS         = -6405 -DNEURO -OPT2 -inline 
BUILDER          = linker
BUILDER_FLAGS    = -cmc5103brd.cfg -m  -heap=6000 -heap1=32000 -heap2=30000 -heap3=32000 -o$(TARGET) $(LIB_DIRS) -full_names 
#--------------  DEBUG config -------------------------
#ifdef DEBUG      
TARGET           = $(OUT_DIR)/$(PROJECT)d.abs
CC_FLAGS         = -6405 -DNEURO -OPT0 -inline -debug 
LIBS            := $(subst nmc3.lib,nmc3d.lib,$(LIBS)) 
AS_FLAGS        += -ga
BUILDER_FLAGS   += -d0
TMP_DIR          = Debug
#endif 
#--------------  Visual Studio config (for vs8.mk)--
HEADER_DIRS      =../include .
RESOURCES        =Makefile about.txt mc5103brd.cfg



#==================== Handle OS Specifics ==========================
ifeq ($(OS),Windows_NT)
  OS_WHICH= where
  OS_RM   = del /Q
  OS_RD   = rd /Q /S
else
  OS_WHICH= which
  OS_RM   = rm -f -r
  OS_RD   = rm -f -r
endif

#=================== SOURCE & OBJECTS COLLECTION ===========================

.SUFFIXES:

# regular search of *.c *.cpp,*.asm sources in all $(SRC_DIRS)
ALL_CPP = main.cpp 
ALL_ASM = test.asm proflist_generated.asm
ALL_C   = 

#VPATH    = $(SRC_DIRS)

# collecting of objects
OBJECTS_CPP = $(notdir $(patsubst %.cpp,%.o,$(ALL_CPP)))
OBJECTS_ASM = $(notdir $(patsubst %.asm,%.o,$(ALL_ASM)))
OBJECTS_C   = $(notdir $(patsubst %.c,%.o,$(ALL_C)))
OBJECTS     = $(addprefix $(TMP_DIR)/,$(OBJECTS_C) $(OBJECTS_CPP)  $(OBJECTS_ASM))

#======================== BUILD RULES ====================================
.PHONY:all  clean cleanall vs8 vs8stdout skip

.DEFAULT_GOAL=default
default: $(TMP_DIR) $(OUT_DIR)  $(TARGET)

all: 
	$(MAKE) -j4 DEBUG=y
	$(MAKE) -j4

	
$(TMP_DIR):
	-mkdir "$(@)"

$(TARGET): $(OBJECTS) 
	$(BUILDER) $(BUILDER_FLAGS) $(OBJECTS) $(LIBS)

$(OUT_DIR): 
	-mkdir "$(@)"
	
$(TMP_DIR)/%.o: %.asm 
	$(AS) $(AS_FLAGS) $(<) -o$(@)
	
$(TMP_DIR)/%.o: $(TMP_DIR)/%.asmx 
	$(AS) $(AS_FLAGS_C2ASM) $(<) -o$(@)

$(TMP_DIR)/%.asmx: %.cpp 
	$(CC) $(CC_FLAGS) $(<) -O$(@) $(INC_DIRS) 

$(TMP_DIR)/%.asmx: %.c
	$(PREPROCESS_CPP_DEP)
	$(CC) $(CC_FLAGS) $(<) -O$(@) $(INC_DIRS) 

clean:
	-$(OS_RM) "$(TARGET)" *.o *.ncb *.ilk  *.dep *.ac *.map *.suo *.user *.ncb null
	-$(OS_RD) $(TMP_DIR)
 
cleanall:
	$(MAKE) clean
	$(MAKE) clean DEBUG=y
	
	
../proflist_generated.asm: 
	tclsh $(ROOT)/script/generate_proflist.tcl ../nm/proflist_generated.asm

profile:	
	tclsh $(ROOT)/script/generate_proflist.tcl ../nm/proflist_generated.asm $(PROJECT)d.map

	
	
#========================== Visual Studio 8 support ===================
-include $(ROOT)/script/vs8.mk

vs8:
	@$(MAKE) vs8stdout --silent >$(PROJECT).vcproj

vs8stdout:	
	$(info $(XML))

skip:
	@echo SDK missing. Compilation is skipped!
