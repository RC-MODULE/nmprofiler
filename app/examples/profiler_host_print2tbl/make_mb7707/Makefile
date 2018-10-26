ROOT = ../../../..
include $(ROOT)/global.mk
#-include ../local.mk
HEAP ?= -heap=6384 -heap1=16384 -heap2=16384 -heap3=16384
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MB7707 board and stores return code in ".exitcode"  file

.SUFFIXES:


ifndef MB7707
$(error ERROR: 'MB7707' environment variable is not defined!  )
endif 


BOARD    = mb7707
HOST     = $(BOARD)-x86


TARGET   = main0.abs
INC_DIRS = -I$(ROOT)/include -I"$(NEURO)/include" -I$(HAL)/include
LIB_DIRS = -L"$(MB7707)/lib" -L$(NM_IO)/lib -L$(ROOT)/lib -L$(HAL)/lib 
LIBS     = nm_io.lib mb7707lib.lib libint05.lib nmprofiler-nmc3.lib hal-mb7707.lib 
CFG      = mb7707brd.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,../src_nm0))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,../src_nm0))


all: $(TARGET) 



	
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
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) proflist_generated.asm -soc -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) -heap=1024 -heap1=1024 -heap2=1024 -heap3=1024
	
proflist_generated.asm: 
	$(TCLSH) $(ROOT)/script/generate_proflist.tcl proflist_generated.asm


PATH:=$(MB7707)/bin;$(PATH)

run: $(TARGET) 
	bin\debug\$(HOST)
	
clean:
	-$(OS_RM) *.abs *.elf *.ncb *.map *.elf *.suo *.user *.filters
	-$(OS_RD) bin obj
	
kill: clean
	-$(OS_RM) *.vcproj *.sln *.vcxproj  proflist_generated.asm
