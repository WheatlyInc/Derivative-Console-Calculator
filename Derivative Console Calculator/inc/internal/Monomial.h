#pragma once

/****************************************************
/* The Monomial class will serve either for itself  
/* or as building blocks for the Polynomial class.
/****************************************************/


#include <cctype> /* isdigit*/
#include <cmath> /* Trig Funcs, */
#include <iostream>
#include <math.h> /* Log Funcs*/
#include <set>
#include <sstream> /* istringstream ostringstream */
#include <string>


using std::isdigit;
using std::istream;
using std::ostream;
using std::stod;
using std::string;
using std::stringstream;
using std::to_string;


enum arithmetic_op {
	plus=0,
	minus,
	times,
	divide,
};

enum quantity {
	lft_parenth,
	rht_parenth,
};

enum exponent {
	exponent,
};

enum funcs {
	log_10,
	natural_log,
};

/**
* This class is a coding representation of a mathematical monomial. An example: 2x 
* The current implementation requires you to provide a coefficient (represented as a double)
* and then the context of the term (represented as a string). Will eventually support more
* sophsticated terms, like: x^2 and log(x). The construction will focus on validating passed
* params. 
*
*/
class Monomial
{
	public:
		Monomial();
		Monomial(string);
		void setCoef(double);
		void setTerm(string);
		void setValidMono(bool);
		double getCoef() const;
		string getTerm() const;
		bool isNum(const string) const;
		bool getValidMono() const;
		bool operator==(const Monomial) const;
		bool operator!=(const Monomial m) const;
		friend ostream& operator<<(ostream& os, const Monomial&);

	private:
		bool m_valid_mono;
		double m_coefficient;
		string m_term;
};

