/*
* Monomial_t.cpp
* A testing file for the Monomial class.
*
**/

#include "../inc/internal/Monomial.h"
//#include "gtest/gtest.h"
#include "../extern/googletest/googletest/include/gtest/gtest.h"


namespace {

	/* Empty Monomial */
	TEST(monomialsConstruct, empty) {
		Monomial m;
		EXPECT_EQ(m.getCoef(), 0);
		EXPECT_EQ(m.getTerm(), "");
		EXPECT_EQ(m.getValidMono(), false);
	};

	/* f(x) = 2x */
	TEST(monomialsConstruct, TWOx) {
		Monomial m("2x");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x");
		EXPECT_EQ(oss.str(), "2x");
		EXPECT_TRUE(m.getValidMono());
	};

	/* f(x) = 2x^3 */
	TEST(monomialsConstruct, TWOxEXP3) {
		Monomial m("2x^3");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x^3");
		EXPECT_EQ(oss.str(), "2x^3");
		EXPECT_TRUE(m.getValidMono());
	};

	/* f(x) = x^2 */
	TEST(monomialsConstruct, noCoef_with_TermEXP) {
		Monomial m("x^2");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 1);
		EXPECT_EQ(m.getTerm(), "x^2");
		EXPECT_EQ(oss.str(), "x^2");
		EXPECT_TRUE(m.getValidMono());
	}


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

	/* Simplifying an exponent of 1. Useful for Derivatives of functions like x^2 */
	TEST(monomialSimplify, oneExp) {
		Monomial m("2x^1");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x");
		EXPECT_EQ(oss.str(), "2x");
		EXPECT_TRUE(m.getValidMono());
	}

	/* Simplifying an coefficient */
	TEST(monomialSimplify, oneCoef_with_TermEXP) {
		Monomial m("1x^2");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 1);
		EXPECT_EQ(m.getTerm(), "x^2");
		EXPECT_EQ(oss.str(), "x^2");
		EXPECT_TRUE(m.getValidMono());
	}

	/* Simplifying an coeficient of 1 and a variable of exponent of 1. */
	TEST(monomialSimplify, oneCoefoneExp) {
		Monomial m("1x^1");
		stringstream oss;
		oss << m;
		EXPECT_EQ(m.getCoef(), 1);
		EXPECT_EQ(m.getTerm(), "x");
		EXPECT_EQ(oss.str(), "x");
		EXPECT_TRUE(m.getValidMono());
	};


	/* f(x) == f(x) where f(x) = x */
	TEST(monomialsCompare, m_Equal_m) {
		Monomial m("x");
		EXPECT_TRUE(m == m);
	};

	/* 2x^3 == 3x^2 should be false */
	TEST(monomialsCompare, TWOxExp3_Equal_ThreeExp2) {
		Monomial m1("2x^3"), m2("3x^2");
		EXPECT_FALSE(m1 == m2);
	};

	/* An empty monomial should not equal a nonempty monomial */
	TEST(monomialsCompare, empty_Equal_TWOxExp3) {
		Monomial m1, m2("2x^3");
		EXPECT_FALSE(m1 == m2);
	};

	/*** Retesting the previous 3 monomialsCompare tests, but using the != operator overloader ***/
	/* f(x) == f(x) where f(x) = x */
	TEST(monomialsCompare, m_NotEq_m) {
		Monomial m("x");
		EXPECT_FALSE(m != m);
	};

	/* 2x^3 == 3x^2 should be false */
	TEST(monomialsCompare, TWOxExp3_NotEq_ThreeExp2) {
		Monomial m1("2x^3"), m2("3x^2");
		EXPECT_TRUE(m1 != m2);
	};

	/* An empty monomial should not equal a nonempty monomial */
	TEST(monomialsCompare, empty_NotEq_TWOxExp3) {
		Monomial m1, m2("2x^3");
		EXPECT_TRUE(m1 != m2);
	};
	

	/* Outputting Monomial */
	TEST(monomialOutput, TwoxEXP3) {
		Monomial m("2x^3");
		stringstream oss;
		oss << m;
		EXPECT_EQ(oss.str(), "2x^3");
	};

} // end namespace