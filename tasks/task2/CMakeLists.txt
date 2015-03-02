cmake_minimum_required(VERSION 2.6)

project(task2)

include_directories(
	/usr/include
	${FUDZI_INCLUDE_DIRS}
)

link_directories(${FUDZI_LIBRARY_DIRS}
)

add_executable(	
	task2
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(task2
	fudzi 
)


