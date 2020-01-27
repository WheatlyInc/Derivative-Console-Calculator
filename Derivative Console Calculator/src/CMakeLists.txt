# cmake for Derivative Console Calculator Project

cmake_minimum_required(VERSION 3.0.0)
project(Derivative_Console_Calculator_Project VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(src)
add_library(
	Polynomials 
	Polynomial.h
	Polynomial.cpp
)

add_library(
	Derivatives 
	Derivative.h
	Derivative.cpp
)
###################

add_executable(Derivative_Console_Calculator main.cpp)

target_link_libraries(Derivative_Console_Calculator PRIVATE Polynomials)
target_link_libraries(Derivative_Console_Calculator PRIVATE Derivatives)