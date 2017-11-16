ROOT=../../../..
include $(ROOT)/global.mk
-include ../local.mk
HEAP ?= -heap=6384 -heap1=16384 -heap2=16384 -heap3=16384
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MC5103 board and stores return code in ".exitcode"  file

.SUFFIXES:


ifndef MC7601
$(warning *** WARNING: 'MC7601' environment variable is not defined! Board SDK might not have installed correctly. )
endif 


INC_DIRS = -I"$(MC7601)/include" -I$(ROOT)/include -I$(NEURO)/include
LIB_DIRS = -L"$(MC7601)/lib" -L$(ROOT)/lib -L$(NM_IO)/lib
LIBS     = nm_io_dummy.lib mc7601_ll_nm.lib libint_soc.lib  nmprofiler-nmc3.lib
TARGET   = main.abs
CFG      = mc7601brd.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,..))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,..))


# sources
#SRC_CPP = main.cpp
#SRC_ASM = test.asm proflist_generated.asm
#SRC_C   = 

$(TARGET): $(SRC_CPP) $(SRC_ASM) $(CFG) Makefile 
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) -nmc3 -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) $(HEAP)
#                                                                                                                  [L00]:64kB   [L01]:64kB  [G00]:64kB   [G01]:64kB

PATH:=$(MC7601)/bin;$(PATH)



../proflist_generated.asm: 
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm

profile:	
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm .main.map
	
run: $(TARGET)
	mc7601run $(TARGET) -x192.168.1.2

#	lua53 $(ROOT)/script/profiledump2tbl.lua profile.dat
#-t10000 --recv_file_name=profile.dat --recv_sect=.shared_profile --recv_size=0x1000 	
clean:
	-rm -f *.abs *.elf .*

skip:
	@echo SDK missing. Compilation is skipped!
	

