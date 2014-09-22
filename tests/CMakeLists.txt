cmake_minimum_required(VERSION 2.6)

project(tests)

#set(CMAKE_CXX_LINK_FLAGS  ${CMAKE_CXX_LINK_FLAGS} -lthreads -llibgtest)
#set(CMAKE_C_LINK_FLAGS  ${CMAKE_C_LINK_FLAGS} -lpthread -llibgtest)

#add_definitions(-DGTEST_DIR=/opt/gtest-1.7.0)

#add_subdirectory(${GTEST_DIR})

include_directories(${pkgs_INCLUDE_DIRS} 
	/usr/include
	$ENV{GTEST_DIR}/include
	${FUDZI_INCLUDE_DIRS}
)

link_directories($ENV{GTEST_DIR}/build
)

add_executable(	
	tests
	# 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tests_algebra_elementary.cpp
)

target_link_libraries(tests
    fudzi
	gtest
	gtest_main
    pthread
)


