cmake_minimum_required(VERSION 3.5)
PROJECT(profiler_host_dump_pc) 
MESSAGE(STATUS ${CMAKE_GENERATOR})

MESSAGE(STATUS ${CMAKE_SIZEOF_VOID_P})
if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
	SET(ARCH_POSTFIX "x86")
	MESSAGE(STATUS "x86-Build")
else (${CMAKE_SIZEOF_VOID_P} EQUAL 4)
	SET(ARCH_POSTFIX "x64")
	MESSAGE(STATUS "x64-Build")
endif (${CMAKE_SIZEOF_VOID_P} EQUAL 4)
SET(CMAKE_DEBUG_POSTFIX   "d")


SET(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../../../..)
if (MSVC)
	SET(CMAKE_RUTIME_OUTPUT_DIRECTORY         ./)
    SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   "")
	SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "")
    # etc for the other available configuration types (MinSizeRel, RelWithDebInfo)
else (MSVC)
	SET(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif(MSVC)


#SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${ROOT}/lib)
#SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${ROOT}/lib)



SET(CompilerFlags
       CMAKE_CXX_FLAGS
       CMAKE_CXX_FLAGS_DEBUG
       CMAKE_CXX_FLAGS_RELEASE
       CMAKE_C_FLAGS
       CMAKE_C_FLAGS_DEBUG
       CMAKE_C_FLAGS_RELEASE
       )
#foreach(CompilerFlag ${CompilerFlags})
# string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
#endforeach()


include_directories(
		${ROOT}/include 
		${ROOT}/deps/connector
		$ENV{MC5103}/libload
		$ENV{NM_IO}/include
)

link_directories(
		$ENV{MC5103}/libload
		$ENV{NM_IO}/lib
)

FILE(GLOB  SRC 
		*.cpp
)			
#set_target_properties( profiler_host-${ARCH_POSTFIX} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./ )
#set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
#set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

ADD_EXECUTABLE(profiler_host-${ARCH_POSTFIX} ${SRC} )
set_target_properties(profiler_host-${ARCH_POSTFIX}  PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(profiler_host-${ARCH_POSTFIX}  mc5103load.lib nm_io_host.lib libelf.lib)

#MESSAGE(STATUS ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
#if ( MSVC )
#   set_target_properties( nmpp-x86 PROPERTIES LIBRARY_OUTPUT_DIRECTORY 		d:/GIT/nmpp/1111)
#   set_target_properties( nmpp-x86 PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG 	d:/GIT/nmpp/1111)
#   set_target_properties( nmpp-x86 PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE d:/GIT/nmpp/1111)
#	set_target_properties( nmpp-x86 PROPERTIES RUNTIME_OUTPUT_DIRECTORY 		d:/GIT/nmpp/1111)
#   set_target_properties( nmpp-x86 PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG 	d:/GIT/nmpp/1111)
#   set_target_properties( nmpp-x86 PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE d:/GIT/nmpp/1111)
#set_target_properties( nmpp PROPERTIES ARCHIVE_DIRECTORY 		 d:/GIT/nmpp/1111)
#set_target_properties( nmpp PROPERTIES ARCHIVE_DIRECTORY_DEBUG 	 d:/GIT/nmpp/1111)
#set_target_properties( nmpp PROPERTIES ARCHIVE_DIRECTORY_RELEASE d:/GIT/nmpp/1111)
#set_target_properties( nmpp PROPERTIES OUTPUT_NAME_DEBUG 123 )		# name of debug lib + prefix
#set_target_properties( nmpp PROPERTIES OUTPUT_NAME_RELEASE 123 )	# name of release lib

  

#MESSAGE(STATUS ${ARCHIVE_OUTPUT_DIRECTORY})
#SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${ROOT}/lib)
#MESSAGE(STATUS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
#MESSAGE(STATUS ${LIBRARY_OUTPUT_DIRECTORY}) - Debug/release dir
#SET(CMAKE_BUILD_DIRECTORY ${ROOT}/lib)
#SET(LIBRARY_OUTPUT_PATH   ${ROOT}/lib )  # Create ${ROOT}/lib/debug
#SET(LIBRARY_OUTPUT_NAME 1111) - # FAILED
#SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${ROOT}/lib)
#set(CMAKE_C_COMPILER d:/SDK/mingw32/bin)
#set(CMAKE_CXX_COMPILER d:/SDK/mingw32/bin)
#MESSAGE(${CMAKE_OSX_ARCHITECTURES})
#FILE(MAKE_DIRECTORY ${CMAKE_GENERATOR})
#SET(CMAKE_BUILD_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${CMAKE_GENERATOR})
#MESSAGE(STATUS ${CMAKE_CXX_FLAGS_DEBUG})
#MESSAGE(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
#MESSAGE(STATUS ${CMAKE_SYSTEM_PROCESSOR})


#FILE(GLOB_RECURSE RELATIVE files "../src/*.c")
#MESSAGE(STATUS ${files})
#FOREACH(item ${files})
#  IF(${item} MATCHES "[.]*rpc-arm[.]*")
#    LIST(REMOVE_ITEM files ${item})
#  ENDIF(${item} MATCHES [.]*rpc-arm[.]*)
#ENDFOREACH(item)
#MESSAGE(STATUS "${files}")


#file(GLOB ENDF6_SRC

       #${PROJECT_SOURCE_DIR}/*.cpp
       #${PROJECT_SOURCE_DIR}/File/*.cpp
       #${PROJECT_SOURCE_DIR}/Section/*.cpp)
#AUX_SOURCE_DIRECTORY(. SRC) 


#set(SRC main.c)
#SET(LIBRARY_OUTPUT_DIRECTORY 			d:/GIT/nmpp/lib)
#SET(LIBRARY_OUTPUT_DIRECTORY_DEBUG 		d:/GIT/nmpp/lib)
#SET(LIBRARY_OUTPUT_DIRECTORY_RELEASE 	d:/GIT/nmpp/lib)
#MESSAGE(STATUS "##############" ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
#SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY d:/GIT/nmpp/1111)
