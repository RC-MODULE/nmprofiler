#!lua

-- A solution contains projects, and defines the available configurations
solution "mc5103"
   configurations { "Debug", "Release" }

   -- A project defines one build target
   project "mc5103-x86"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "../src_pc/*.cpp", "../../../src/mc5103/*.cpp" }
	  libdirs { "$(MC5103)/libload","$(HAL)/lib","../../../lib" }
	  links { "mc5103load.lib","hal-mc5103io-x86.lib","mc5103-nmc3"} 
	  includedirs { "$(MC5103)/include","$(HAL)/include","../../../include"}

      configuration "Debug"
         defines { "DEBUG" }
         symbols  "On" 
		 

      configuration "Release"
         defines { "NDEBUG" }
         symbols  "Off" 

		 
		 
	project "mc5103-nmc3"
      kind "Makefile"
      files { "../src_nm0/*.cpp" }
	 
	  configuration "Debug"
		   buildcommands {"make DEBUG=y"}
		   rebuildcommands {"make -B DEBUG=y"}
		   cleancommands {"make clean"}
		   
	  configuration "Release"
		   buildcommands {"make"}
		   rebuildcommands {"make -B"}
		   cleancommands {"make clean"}		   