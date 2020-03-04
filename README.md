# Derivative Console Calculator
 A simple calculus console program. Built as a VS project using CMake in a linux environment. 
 Requires g++ compiler, cmake.
 Uses googletest framework for test driven development.

# How to build and run:
First, cd into Derivative Console Calculator/ and do the following to build makefiles 
and download googletest as a submodule:

	mkdir build
	cd build
	cmake ..

To compile and run, just simply:

	make all
	./src/Derivative_Console_Calculator
	
To run all unit tests, do:

	make test
	
You can also run individual tests. These are the following that are available:

	./test/Polynomial_t
    ./test/Monomial_t

And to clean:

	make clean
