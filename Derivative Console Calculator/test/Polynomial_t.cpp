/**
* Polynomial_t.cpp 
* A testing file to test class Polynomial 
*
**/


#include "../inc/internal/Polynomial.h"
#include "gtest/gtest.h"


/*
TEST(true, false) {
	EXPECT_EQ(true, true);
	EXPECT_EQ(false, false);
}
int zero(0), one(1);
TEST(zero, one) {
	EXPECT_EQ(zero, 0);
	EXPECT_EQ(one, 1);
}
*/


TEST(monomials, 1x) {
	monomial m(make_pair(1, "x"));
	monomial p(make_pair(1, "x"));
	EXPECT_EQ(m, p);
}

TEST(polynomials, 0) {
	Polynomial f;
	
}