#include "../inc/internal/Monomial.h"

/** 
 *	Post:
 *		Makes an empty monomial object. Not considered a valid monomial. 
 *		Can be changed with class member functions, however. 
 **/
Monomial::Monomial()
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
}

/**
 * Pre:
 *		Takes in some multi-char input and validates it into a monomial object.
 *
 * Post:
 *		Translates the input into an organized, readable object if validated 
 *		successfully.
 **/
Monomial::Monomial(string s)
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
	string str_coef; str_coef += (s[0]);
	if (isdigit(s[0])) {
		int i(1);
		for (i; i < s.size() && isdigit(s[i]); i++) {
			str_coef += s[i];
		}
		m_coefficient = stod(str_coef);
		if (s[i] == 'x') {
			m_term += s.substr(i);
			m_valid_mono = true;
		}
	}
	else if (s[0] == 'x') {
		m_coefficient = 1;
		m_term += s.substr(1);
		m_valid_mono = true;
	}
}

void Monomial::setCoef(double coef)
{
	m_coefficient = coef;
}

/**
 * Pre: 
 *		Used by friend and class member functions. Assumes validated parameters
**/
void Monomial::setTerm(string term)
{
	m_term = term;
}

/**
 * Pre:
 *		Used by friend and class member functions. Assumes validated parameters
**/
void Monomial::setValidMono(bool b)
{
	m_valid_mono = b;
}

double Monomial::getCoef() const
{
	return m_coefficient;
}

string Monomial::getTerm() const
{
	return m_term;
}

/**
 * Post:
 *		Used by friend and class member functions. Returns true for a valid monomial, 
 *		false for an invalid monomial.
**/
bool Monomial::getValidMono() const
{
	return m_valid_mono;
}

/**
 * Post:
 *		Returns true if both compared monomials are valid and have the same coefficients and terms.
 * TO IMPLEMENT:
 *		The ability to compare expressions like 0x^2 and 0x^0
**/
bool Monomial::operator==(const Monomial m) const
{
	return (this->getCoef() == m.getCoef()) && (this->getTerm() == m.getTerm() && getValidMono() && m.getValidMono());
}

bool Monomial::operator!=(const Monomial m) const
{
	return !(*this == m);
}

/**
 * TOBE IMPLEMENTED
 *	Pre:
 * Pro:
 **/
ostream& operator<<(ostream& os, const Monomial&)
{
	// TODO: insert return statement here
}

/**
 * DEPRECATED
 *
istream& operator>>(istream& is, Monomial&)
{
	// TODO: insert return statement here
}
**/