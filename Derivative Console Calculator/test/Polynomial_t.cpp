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
		Polynomial f;
		EXPECT_TRUE(f.getPolyn().empty());
	};

	/* f(x) = 2x */
	TEST(polynomialsConstruct, TWOx) {
		Polynomial f;
		string s("2x");
		stringstream iss(s), oss;
		iss >> f;
		oss << f;
		EXPECT_EQ(iss.str(), oss.str());
	};

}
