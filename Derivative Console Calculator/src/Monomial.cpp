#include "../inc/internal/Monomial.h"

Monomial::Monomial()
{
	m_coefficient = 0;
	m_term = "";
	m_valid_mono = false;
}

Monomial::Monomial(double coefficient, string term)
{
	m_coefficient = coefficient;
	m_term = term;
}

Monomial::~Monomial()
{
	//dtor
}

void Monomial::setCoef(double coef)
{
	m_coefficient = coef;
}

void Monomial::setTerm(string term)
{
	m_term = term;
}

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

bool Monomial::getValidMono() const
{
	return m_valid_mono;
}

bool Monomial::operator==(const Monomial m) const
{
	return (this->getCoef() == m.getCoef()) && (this->getTerm() == m.getTerm());
}

bool Monomial::operator!=(const Monomial m) const
{
	return !(*this == m);
}

ostream& operator<<(ostream& os, const Monomial&)
{
	// TODO: insert return statement here
}

istream& operator>>(istream& is, Monomial&)
{
	// TODO: insert return statement here
}
