cmake_minimum_required(VERSION 3.8)


project(CPlusPlusBestC
	LANGUAGES CXX)
	
	
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS_DEBUG "-g")
set (CMAKE_CXX_FLAGS_RELEASE "-O0")

add_executable( main main.cpp)
