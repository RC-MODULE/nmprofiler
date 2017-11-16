ROOT=../../../..
include $(ROOT)/global.mk
# BUILD AND RUN MAKEFILE
# This makefile builds simple nmc-application containing single cpp-file  
# Rule 'run' executes the application on MB7707 board and stores return code in ".exitcode"  file

.SUFFIXES:



ifndef MB7707
$(warning*** WARNING: 'MB7707' environment variable is not defined! Board SDK might not have installed correctly. )
endif 




INC_DIRS = -I"$(MB7707)/include" -I$(ROOT)/include -L$(NEURO)/include
LIB_DIRS = -L"$(MB7707)/lib" 	-L$(ROOT)/lib -L$(NM_IO)/lib -L$(NEURO)/lib
LIBS     = nm_io.lib mb7707lib.lib libint_soc.lib libc05.lib cppnew05.lib nmprofiler-nmc3.lib
TARGET   = main.abs
CFG      = mb7707brd.cfg
SRC_CPP  = $(wildcard $(addsuffix /*.cpp,..))
SRC_ASM  = $(wildcard $(addsuffix /*.asm,..))



$(TARGET): $(SRC_CPP)  $(CFG)   Makefile 
	nmcc -o$(TARGET) -m.main.map $(SRC_CPP) $(SRC_ASM) -soc -g -O0 $(INC_DIRS) $(LIB_DIRS) $(LIBS) -c$(CFG) 
#                                                                                         [L00]:64kB   [L01]:64kB  [G00]:64kB   [G01]:64kB

PATH:=$(MB7707)/bin;$(PATH)
../proflist_generated.asm: 
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm

profile:	
	tclsh $(ROOT)/script/generate_proflist.tcl ../proflist_generated.asm .main.map

	
run: $(TARGET)
	-mb7707run $(TARGET)  -t10000 --recv_file_name=profile.dat --recv_sect=.shared_profile --recv_size=0x1000 
	lua53 $(ROOT)/script/profiledump2tbl.lua profile.dat
		
clean:
	-$(OS_RM) *.abs *.elf .*


	

