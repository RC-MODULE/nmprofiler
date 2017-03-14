ROOT=../../../..
include $(ROOT)/global.mk
-include ../local.mk
HEAP ?= -heap=6384 -heap1=16384 -heap2=16384 -heap3=16384
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MC5103 board and stores return code in ".exitcode"  file

.SUFFIXES:


ifndef MC5103
$(warning *** WARNING: 'MC5103' environment variable is not defined! Board SDK might not have installed correctly. )
endif 
INC_DIRS = -I"$(MC5103)/include" -I$(ROOT)/include -I$(NEURO)/include
LIB_DIRS = -L"$(MC5103)/lib"     -L$(ROOT)/lib -L$(NM_IO)/lib
LIBS     = nm_io.lib mc5103lib.lib libint05.lib nmprofiler-nmc3.lib 
TARGET   = main.abs
CFG      = mc5103brd.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,..))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,..))


# sources
#SRC_CPP = main.cpp
#SRC_ASM = test.asm proflist_generated.asm
#SRC_C   = 

$(TARGET): $(SRC_CPP) $(SRC_ASM) $(CFG) Makefile 
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) -6405 -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) $(HEAP)
#                                                                                                                  [L00]:64kB   [L01]:64kB  [G00]:64kB   [G01]:64kB

PATH:=$(MC5103)/bin;$(PATH)

	

../proflist_generated.asm: 
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm

profile:	
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm .main.map
	
run: $(TARGET)
	mc5103run $(TARGET) 


clean:
	-$(OS_RM) *.abs *.elf .*


	

