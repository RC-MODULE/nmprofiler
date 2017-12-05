
PLATFORMS = mc5103 mb7707 mc12101



export  DEVKIT    =d:/git/dev-kit
#?=$(ROOT)/deps/dev-kit-master
export  NEURO     ?=$(DEVKIT)/nmsdk
export  VSHELL32  ?=$(DEVKIT)/vshell32
export  MC5103    ?=$(DEVKIT)/mc5103sdk
export  MB7707    ?=$(DEVKIT)/mb7707sdk
export  NM_IO     ?=$(DEVKIT)/nm_io

ifeq ($(OS),Windows_NT)
   TCLSH    = tclsh86t
   SHELL    = cmd
   OS_MV    = cmd /c move /Y
   OS_RM    = cmd /c del /Q
   OS_RD    = cmd /c rd /Q /S 
   OS_CP    = cp
   OS_CAT   = cat
   OS_WHICH = where
   GNU_WGET = wget -nc --no-check-certificate --content-disposition 
   PS_WGET  = powershell  -ExecutionPolicy Bypass -file $(ROOT)\deps\wget.ps1 
   OS_WGET  = $(GNU_WGET)
   PS_UNZIP = powershell  -ExecutionPolicy Bypass -file unzip.ps1 
   OS_UNZIP = unzip -u -o -q 
   OS_TODIR = -d
   OS_UNPACK= $(OS_UNZIP)
   PATH_DEP = 	$(realpath $(NEURO)/bin);\
				$(realpath $(MC5103)/bin);\
				$(realpath $(MB7707)/bin);\
				$(realpath $(MC7601)/bin);\
				$(realpath $(ROOT)/deps/libxslt-1.1.26.win32/bin)
				
  export PATH    := $(PATH_DEP);$(PATH);
  
  MB7707_MAC ?= 1A-2B-3C-4D-5E-6F
  MB7707_ETH ?= 2
else
  export NEURO     = $(ROOT)/deps/module-nmc
  define OS_PATH
	$(1)
  endef 
  OS_DIFF  = diff   
  OS_SCP   = scp
  OS_RM    = rm -f -r
  RM       = rm -f -r
  OS_RD    = rm -d -r
  OS_FIND  = find
  OS_CAT   = cat
  OS_CP    = cp  
  OS_WHICH = which
  OS_WGET  = wget  
  OS_UNZIP = unzip
  OS_TAR   = tar xvzf 
  OS_TODIR = -C
  PATH    := $(NEURO)/bin:$(MC5103)/bin:$(MB7707)/bin:$(PATH)
  LD_LIBRARY_PATH = $(MC5103)/bin:$(MB7707)/bin
  MB7707_MAC = eth0
endif

define newline


endef	

 