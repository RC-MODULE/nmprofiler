ROOT = ../../../..
include $(ROOT)/global.mk
#-include ../local.mk
HEAP ?= -heap=6384 -heap1=16384 -heap2=16384 -heap3=16384
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MC12101 board using hoist program
# Rule 'mcrun' executes the application on MC12101 board in standalone mode using mc12101run 

.SUFFIXES:


ifndef MC12101
$(warning *** WARNING: 'MC12101' environment variable is not defined! Board SDK might not have installed correctly. )
endif 



BOARD    = mc12101
HOST     = $(BOARD)-x86


TARGET   = main1.abs
INC_DIRS = -I"$(MC12101)/include" -I$(ROOT)/include -I"$(NEURO)/include" -I$(HAL)/include
LIB_DIRS = -L"$(MC12101)/lib" -L$(ROOT)/lib -L$(HAL)/lib
LIBS     = mc12101lib_nm.lib libc4.lib libc4.lib hal-mc12101.lib nmprofiler-nmc4.lib
CFG      = mc12101brd-nmc1.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,../src_nm1))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,../src_nm1))


all: $(TARGET) $(HOST) 

vs2005 $(HOST): $(HOST).vcproj
	"$(VS80COMNTOOLS)vsvars32" && vcbuild $(BOARD)-x86.vcproj

vs2015 $(HOST): $(HOST).vcxproj
	"$(VS140COMNTOOLS)vsvars32" && msbuild $(HOST).vcxproj /p:Configuration=Debug
	
profile: .main.map 
	$(TCLSH) $(ROOT)/script/generate_proflist.tcl proflist_generated.asm .main.map

$(TARGET) .main.map: $(SRC_CPP) $(SRC_ASM) proflist_generated.asm Makefile $(CFG)
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) proflist_generated.asm -nmc4 -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) -heap=0 -heap1=0 -heap2=0 -heap3=0
	
proflist_generated.asm: 
	$(TCLSH) $(ROOT)/script/generate_proflist.tcl proflist_generated.asm

	
PATH:=$(MC12101)/bin;$(PATH)	
#---------------- user commands ----------------------	
		
run: $(TARGET) $(HOST)
	bin\debug\$(HOST)

mcrun: $(TARGET) $(HOST)
	mc12101run $(TARGET) -p
	


clean:
	-$(OS_RM) *.abs *.elf *.ncb *.map *.elf *.suo *.user *.filters 
	-$(OS_RD) bin obj
	
kill: clean
	-$(OS_RM) *.vcproj *.sln *.vcxproj  proflist_generated.asm
	
$(HOST).vcproj:	premake5.lua 
	premake5 vs2005
	
$(HOST).vcxproj:	premake5.lua 
	premake5 vs2015
	