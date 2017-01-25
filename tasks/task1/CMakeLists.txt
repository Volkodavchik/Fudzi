cmake_minimum_required(VERSION 2.6)

project(task1)

include_directories(
	/usr/include
	${FUDZI_INCLUDE_DIRS}
)

link_directories(${FUDZI_LIBRARY_DIRS}
)

add_executable(	
	task1
	${CMAKE_CURRENT_SOURCE_DIR}/task1.cpp
)

target_link_libraries(task1
	fudzi 
	pthread
)


