#include "../inc/internal/Polynomial.h"

/** 
 * TOBE DEPECRATED
 * 
 *	Post:
 *		Makes an empty monomial object. Not considered a valid monomial. 
 *		Can be changed with class member functions, however. 
 **/
Polynomial::Polynomial()
{
	m_valid = false;
}

vector<Monomial> Polynomial::getPolyn() const
{
   return m_polyn;
}

int Polynomial::getSize() const
{
	return m_polyn.size();
}

/** TO IMPLEMENT:
 *	Post:
 *		Combines any like-termed monomials in the invoked polynomial. 
 *		Called when ever a polynomial is being constructed.
 **/
void Polynomial::combineliketerms()
{
}

/**
 *	Post:
 *		The [] overloader simplifies accessing/changing the vector of monomials, m_polyn[].
 **/
Monomial& Polynomial::operator[](const unsigned int index)
{
	if (index >= m_polyn.size()) { 
		std::cerr << "Error: Polynomial Index out of bound: index " << index << " >= " << m_polyn.size() << std::endl;
	}
	return m_polyn[index];
}

/**
 * Post:
 *		Used by friend and class member functions. Returns true for a valid polynomial,
 *		false for an invalid polynomial.
**/
bool Polynomial::getValid() const
{
	return m_valid;
}

/**
 *	Post:
 *		The [] overloader simplifies accessing the vector of monomials, m_polyn[].
 **/
const Monomial& Polynomial::operator[](const unsigned int index) const
{
	if (index >= m_polyn.size()) {
		std::cerr << "Error: Polynomial Index out of bound.";
	}
	return m_polyn[index];
}

/**
 * Post:
 *		Returns true if both compared polynomials are valid and have the monomials.
 *		It assumes that the individual polynomials have combined like-terms
 * TO IMPLEMENT:
 *		The ability to compare expressions like 0x^2 and 0x^0
**/
bool Polynomial::operator==(const Polynomial other_p) const
{
	return this->getPolyn() == other_p.getPolyn();
}

bool Polynomial::operator!=(const Polynomial other_p) const
{
	return !(*this == other_p);
}

/**
 * Pre:
 *		Takes a polynomial
 * Post:
 *		Prints the polynomial out monomial by monomial. EVENTUALLY will print out an error and
 *		message if its invalid.
**/
ostream& operator<<(ostream& os, const Polynomial& poly)
{
	if (poly.m_valid == true) {
		for (int i(0); i < poly.getSize(); i++) {
			os << poly[i];
		}
		return os;
	}
	else 
		return os << "ERROR: Invalid Polnomial entered.\n";
	
}

/** 
 * TOBE DEPRECATED OR REDONE
 * Pre:
 *		Takes in a string to build one or more monomials into a storable mathematical expression.
 * Post:
 *		Will attempt to build a valid polynomial. Will eventually print appropiate error messages.
**/
istream& operator>>(istream& is, Polynomial& poly)
{
	Monomial m1;
	int num_lft_parenth(0), num_rht_parenth(0);
	bool open_parenth(false); 
	string s; 
	/* Monomials must have either a coefficient, some function of x, or both.
	 	They must be distinct and cannot blend with other monomials.	**/
	
	// Building the first monomial // 
	/* Analyze the first character to be valid.*/
	is >> s;
	if (isdigit(s[0]) || s[0] == 'x') {
		Monomial m1(s);
		poly.m_polyn.push_back(move(m1));
		if (m1.getValidMono())
			poly.m_valid = true;
	}
	else {
		poly.m_valid = false;
		std::cerr << "ERROR: Invalid startpoint to input expression: \"" << s[0] << "\"" <<  std::endl;
		return is;
	}


	
	while (is >> s && poly.m_valid != false) {}
	return is;
}