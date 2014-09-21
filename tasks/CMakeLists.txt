cmake_minimum_required(VERSION 2.6)

project(tasks)

include_directories(
	/usr/include
	${FUDZI_INCLUDE_DIRS}
)

link_directories(${FUDZI_LIBRARY_DIRS}
)

add_executable(	
	tasks
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(tasks
	fudzi 
	pthread
)


