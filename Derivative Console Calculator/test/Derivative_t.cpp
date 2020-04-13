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
		Polynomial p("2x^3");
		Derivative d(p);
		stringstream oss;
		oss << d;
		EXPECT_EQ("6x^2", oss.str());
		EXPECT_TRUE(d.getValid());
	}
	
	TEST(constructDerivative, multiDigtCoefAndExponent) {
		Polynomial p("20x^30");
		Derivative d(p);
		stringstream oss;
		oss << d;
		EXPECT_EQ(oss.str(), "600x^29");
		EXPECT_TRUE(d.getValid());
	}
}