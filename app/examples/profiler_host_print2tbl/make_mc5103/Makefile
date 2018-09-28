ROOT = ../../../..
include $(ROOT)/global.mk
#-include ../local.mk
HEAP ?= -heap=6384 -heap1=16384 -heap2=16384 -heap3=16384
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MC5103 board

.SUFFIXES:


ifndef MC5103
$(error ERROR: 'MC5103' environment variable is not defined!  )
endif 


BOARD    = mc5103
HOST     = $(BOARD)-x86


TARGET   = main0.abs
INC_DIRS = -I"$(MC5103)/include" -I$(ROOT)/include -I"$(NEURO)/include" -I$(HAL)/include
LIB_DIRS = -L"$(MC5103)/lib" -L$(ROOT)/lib -L$(HAL)/lib -L.
LIBS     = libc05.lib mc5103lib.lib libint05.lib nmprofiler-nmc3.lib hal-mc5103.lib 
CFG      = mc5103brd.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,../src_nm0))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,../src_nm0))


all: $(TARGET) 

#vs2015

	
vs2005: $(HOST).vcproj 
	"$(VS80COMNTOOLS)vsvars32" && vcbuild $(HOST).vcproj

vs2015:	$(HOST).vcxproj
	"$(VS140COMNTOOLS)vsvars32" && msbuild $(HOST).vcxproj /p:Configuration=Debug

$(HOST).vcproj: premake5.lua 
	premake5 vs2005

$(HOST).vcxproj: premake5.lua 
	premake5 vs2015


	

profile: .main.map 
	$(TCLSH) $(ROOT)/script/generate_proflist.tcl proflist_generated.asm .main.map

$(TARGET) .main.map: $(SRC_CPP) $(SRC_ASM) proflist_generated.asm Makefile $(CFG)
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) proflist_generated.asm -nmc3 -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) -heap=1024 -heap1=1024 -heap2=1024 -heap3=1024
	
proflist_generated.asm: 
	$(TCLSH) $(ROOT)/script/generate_proflist.tcl proflist_generated.asm

	
PATH:=$(MC5103)/bin;$(PATH)	
#---------------- user commands ----------------------	
		
run: $(TARGET) vs2015
	bin\debug\$(HOST)
	
clean:
	-$(OS_RM) *.abs *.elf *.ncb *.map *.elf *.suo *.user *.filters
	-$(OS_RD) bin obj
	
kill: clean
	-$(OS_RM) *.vcproj *.sln *.vcxproj  proflist_generated.asm
