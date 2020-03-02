/**
* Polynomial_t.cpp 
* A testing file to test class Polynomial 
*
**/


#include "../inc/internal/Polynomial.h"
#include "gtest/gtest.h"
 

TEST(polynomialsConstruct, empty) {
	Polynomial f;
	EXPECT_TRUE(f.getPolyn().empty());

}
