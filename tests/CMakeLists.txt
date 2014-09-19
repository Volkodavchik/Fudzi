cmake_minimum_required(VERSION 2.6)

project(tests)

#set(CMAKE_CXX_LINK_FLAGS  ${CMAKE_CXX_LINK_FLAGS} -lthreads -llibgtest)
#set(CMAKE_C_LINK_FLAGS  ${CMAKE_C_LINK_FLAGS} -lpthread -llibgtest)

include_directories(${pkgs_INCLUDE_DIRS} 
	/usr/include
	${GTEST_DIR}/include
	${FUDZI_INCLUDE_DIRS}
)

link_directories(${GTEST_DIR}/build)

add_executable(	
	tests
	# 
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(tests
	pthreads
	gtest
)


