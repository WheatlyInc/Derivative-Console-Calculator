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


static const char plus = '+';
static const char minus = '-';
static const char times = '*';
static const char divide = '/';
static const char lft_parenth = '(';
static const char rht_parenth = ')';
static const char exponent = '^';
static const char log_10[] = "log(";
static const char natural_log[] = "ln(";


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
		Monomial(const string&);
		void setValidMono(bool);
		void omitTrailZeros(string&);
		double getCoef() const;
		string getTerm() const;
		bool isNum(const string&) const;
		bool getValidMono() const;
		bool operator==(const Monomial) const;
		bool operator!=(const Monomial m) const;
		friend ostream& operator<<(ostream& os, const Monomial&);

	private:
		bool m_valid_mono;
		double m_coefficient;
		string m_term;
};

