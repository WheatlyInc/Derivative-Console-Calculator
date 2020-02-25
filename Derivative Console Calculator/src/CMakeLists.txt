# src_leveled CMakeLists.txt
#
# cmake for Derivative Console Calculator Project

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