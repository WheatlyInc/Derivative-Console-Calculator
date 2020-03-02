#pragma once

/****************************************************
/* The Monomial class will serve either for itself  
/* or as building blocks for the Polynomial class.
/****************************************************/

#include <cmath> /* Trig Funcs, */
#include <iostream>
#include <math.h> /* Log Funcs*/
#include <string>
#include <set>
#include <vector>


using std::istream;
using std::ostream;
using std::pair;
using std::make_pair;
using std::string;


class Monomial
{
	public:
		Monomial();
		Monomial(double, string);
		~Monomial();
		double getCoef() const;
		string getTerm() const;
		bool operator==(const Monomial) const;
		bool operator!=(const Monomial m) const;
		friend ostream& operator<<(ostream& os, const Monomial&);
		friend istream& operator>>(istream& is, Monomial&);

	private:
		double m_coefficient;
		string m_term;
};

