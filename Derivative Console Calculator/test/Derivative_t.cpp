/**
* Derivative_t.cpp
* A testing file to test class Derviative
*
**/

#include "../inc/internal/Derivative.h"
#include "../extern/googletest/googletest/include/gtest/gtest.h"


namespace {

	TEST(constructDerivative, emptyPoly) {
		Polynomial p;
		Derivative d(p);
		EXPECT_TRUE(d.getPolyn().empty());
		EXPECT_FALSE(d.getValid());
	}

	/* dx/x (f(x) = 2x^3)  == 6x^2  */
	TEST(constructDerivative, Non1CoefAndExponent) {
		Polynomial p;
		stringstream iss("2x^3"), oss;
		iss >> p;
		Derivative d(p);
		oss << d;
		EXPECT_EQ("6x^2", oss.str());
		EXPECT_TRUE(d.getValid());
	}
}