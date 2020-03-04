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
		Monomial m(2, "x");
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x");
	};

	/* f(x) = 2x^3*/
	TEST(monomialsConstruct, TWOxEXP3) {
		Monomial m(2, "x^3");
		EXPECT_EQ(m.getCoef(), 2);
		EXPECT_EQ(m.getTerm(), "x^3");
	};

	/* f(x) == f(x) where f(x) = x */
	TEST(monomialsCompare, mEqualsm) {
		Monomial m(1, "x");
		EXPECT_TRUE(m == m);
	};

} // namespace