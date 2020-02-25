# usr_leveled CMakeLists.txt
#
# Cmake for Derivative Console Calculator Project

cmake_minimum_required(VERSION 3.9)
project(Derivative_Console_Calculator_Project 
		VERSION 1.0.0
		DESCRIPTION "Capstone Project"
		LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()