/*
* Monomial_t.cpp
* A testing file for the Monomial class.
*
**/

#include "../inc/internal/Monomial.h"
#include "gtest/gtest.h"


namespace {

TEST(monomialsConstruct, empty) {
	Monomial m;
	EXPECT_EQ(m.getCoef(), 0);
	EXPECT_EQ(m.getTerm(), "");
}

TEST(monomialsConstruct, 2x) {
	Monomial m(2, "x");
	EXPECT_EQ(m.getCoef(), 2);
	EXPECT_EQ(m.getTerm(), "x");
}

TEST(monomialsConstruct, 2xEXP3) {
	Monomial m(2, "x^3");
	EXPECT_EQ(m.getCoef(), 2);
	EXPECT_EQ(m.getTerm(), "x^3");
}

TEST(monomialsConstruct, mEqualsm) {
	Monomial m(1, "x");
	EXPECT_TRUE(m == m);
}

} // namespace