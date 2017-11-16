ROOT=../../../..
include $(ROOT)/global.mk
-include ../local.mk
HEAP ?= -heap=6384 -heap1=16384 -heap2=16384 -heap3=16384
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MC5103 board and stores return code in ".exitcode"  file

.SUFFIXES:


ifndef MC12101
$(warning *** WARNING: 'MC12101' environment variable is not defined! Board SDK might not have installed correctly. )
endif 
INC_DIRS = -I"$(MC12101)/include" -I$(ROOT)/include -I$(NEURO)/include
LIB_DIRS = -L"$(MC12101)/lib" 	  -L$(ROOT)/lib -L$(NM_IO)/lib
LIBS     = mc12101lib_nm.lib libc4f.lib libc4.lib cppnew4.lib libint_6407.lib nm_io4.lib nmprofiler-nmc4.lib

TARGET   = main.abs
CFG      = mc12101brd-nmc0.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,..))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,..))


# sources
SRC_CPP = ../main.cpp
SRC_ASM = ../test.asm ../proflist_generated.asm
#SRC_C   = 

$(TARGET): $(SRC_CPP) $(SRC_ASM) $(CFG) Makefile 
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) -nmc4 -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) $(HEAP)
#                                                                                                                  [L00]:64kB   [L01]:64kB  [G00]:64kB   [G01]:64kB


PATH:=$(MC12101)/bin;$(PATH)

	

../proflist_generated.asm: 
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm

profile:	
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm .main.map
	
run: $(TARGET)
	-mc12101run $(TARGET) -q 
	
clean:
	-$(OS_RM) *.abs *.elf .*

	
reset:
	reset12101	

