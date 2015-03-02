cmake_minimum_required(VERSION 2.6)

set(BOOST_LIBRARIES boost_thread boost_iostreams boost_system boost_filesystem boost_random boost_regex boost_program_options boost_date_time)

set(CMAKE_SYSTEM_NAME Linux)

set(PLATFORM_ARCH x64)

set(CMAKE_C_COMPILER gcc)

set(CMAKE_CXX_COMPILER g++)

#set(CMAKE_CXX_LINK_FLAGS  ${CMAKE_CXX_LINK_FLAGS} -lthreads)

#set(CMAKE_C_LINK_FLAGS  ${CMAKE_C_LINK_FLAGS} -lthreads)

set(FUDZI_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/inc)

set(FUDZI_SOURCE_DIRS ${CMAKE_SOURCE_DIR}/src)

set(FUDZI_LIBRARY_DIRS ${CMAKE_SOURCE_DIR}/build)

project(fudzi)

include_directories(${FUDZI_INCLUDE_DIRS})

add_library(	
	fudzi SHARED
	${FUDZI_SOURCE_DIRS}/algebra_elementary.cpp
	${FUDZI_SOURCE_DIRS}/strings.cpp
)

# tests temprorary disabled
#add_subdirectory(tests)

add_subdirectory(tasks)
