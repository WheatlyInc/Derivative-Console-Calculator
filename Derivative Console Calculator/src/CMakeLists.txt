# src_leveled CMakeLists.txt
#
# cmake for Derivative Console Calculator Project

add_library(
	Polynomials 
	../inc/internal/Polynomial.h
	Polynomial.cpp

	../inc/internal/Monomial.h
	Monomial.cpp
)

add_library(
	Derivatives 
	../inc/internal/Derivative.h
	Derivative.cpp
)

add_library(
	Monomials
	../inc/internal/Monomial.h
	Monomial.cpp
)

###################

add_executable(Derivative_Console_Calculator main.cpp)

target_link_libraries(Derivative_Console_Calculator PRIVATE Monomials)
target_link_libraries(Derivative_Console_Calculator PRIVATE Polynomials)
target_link_libraries(Derivative_Console_Calculator PRIVATE Derivatives)