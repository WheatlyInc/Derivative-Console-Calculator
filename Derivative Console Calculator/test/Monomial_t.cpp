/*
* Monomial_t.cpp
* A testing file for the Monomial class.
*
**/

#include "../inc/internal/Monomial.h"
//#include "gtest/gtest.h"
#include "../extern/googletest/googletest/include/gtest/gtest.h"


namespace {

	/* Empty Monomial*/
	TEST(monomialsConstruct, empty) {
		Monomial m;
		EXPECT_EQ(m.getCoef(), 0);
		EXPECT_EQ(m.getTerm(), "");
		EXPECT_EQ(m.getValidMono(), false);
	};

	/* f(x) = 2x*/
	TEST(monomialsConstruct, TWOx) {
		Monomial m("2x");
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x");
		EXPECT_TRUE(m.getValidMono());
	};

	/* f(x) = 2x^3*/
	TEST(monomialsConstruct, TWOxEXP3) {
		Monomial m("2x^3");
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x^3");
		EXPECT_TRUE(m.getValidMono());
	};

	/* Omitting unnecesary exponent 0 on a simple monomial */
	TEST(monomialSimplify, zeroExp) {
		Monomial m("2x^0");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "");
		EXPECT_EQ(oss.str(), "2");
		EXPECT_TRUE(m.getValidMono());
	}

	/* Simpilying an exponent of 1. Useful for Derivatives of functions like x^2 */
	TEST(monomialSimplify, oneExp) {
		Monomial m("2x^1");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x");
		EXPECT_EQ(oss.str(), "2x");
		EXPECT_TRUE(m.getValidMono());
	}

	/* f(x) == f(x) where f(x) = x */
	TEST(monomialsCompare, mEqualsm) {
		Monomial m("x");
		EXPECT_TRUE(m == m);
	};

	/* Outputting Monomial */
	TEST(monomialOutput, TwoxEXP3) {
		Monomial m("2x^3");
		stringstream oss;
		oss << m;
		EXPECT_EQ(oss.str(), "2x^3");
	};

} // namespace