#!lua
ROOT = "../../.."
-- A solution contains projects, and defines the available configurations
solution "mb7707"
   configurations { "Debug", "Release" }

   -- A project defines one build target
   project "mb7707-x86"
      kind "ConsoleApp"
      language "C++"
      files { "**.h", "../src_pc/*.cpp", ROOT.."/src/mb7707/*.cpp" }
	  libdirs { "$(MB7707)/libload","$(HAL)/lib",ROOT.."/lib"  }
	  links { "mb7707load.lib","hal-mb7707-x86.lib","mb7707-nmc3"} 
	  includedirs { "$(MB7707)/include","$(HAL)/include",ROOT.."/include"}

      configuration "Debug"
         defines { "DEBUG" }
         symbols  "On" 
		 

      configuration "Release"
         defines { "NDEBUG" }
         symbols  "Off" 

		 
		 
	project "mb7707-nmc3"
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