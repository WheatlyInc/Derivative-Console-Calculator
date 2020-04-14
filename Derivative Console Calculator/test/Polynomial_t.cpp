/**
* Polynomial_t.cpp 
* A testing file to test class Polynomial 
*
**/


#include "../inc/internal/Polynomial.h"
//#include "gtest/gtest.h"
#include "../extern/googletest/googletest/include/gtest/gtest.h"
 

namespace {

	TEST(polynomialsConstruct, empty) {
		string s("");
		stringstream oss;
		Polynomial f(s);
		EXPECT_TRUE(f.getPolyn().empty());
		EXPECT_FALSE(f.getValid());
		oss << f;
		EXPECT_EQ("ERROR: Invalid Polnomial entered.\n", oss.str());
	};

	/* f(x) = 2x */
	TEST(polynomialsConstruct, TWOx) {
		string s("2x");
		stringstream oss;
		Polynomial f(s);
		oss << f;
		EXPECT_EQ(s, oss.str());
	};

}
