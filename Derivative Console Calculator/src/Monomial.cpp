#include "../inc/internal/Monomial.h"

Monomial::Monomial()
{
	//ctor
}

Monomial::Monomial(double coefficient, string term)
{
	this->m_coefficient = coefficient;
	this->m_term = term;
}

Monomial::~Monomial()
{
	//dtor
}

double Monomial::getCoef() const
{
	return this->m_coefficient;
}

string Monomial::getTerm() const
{
	return this->m_term;
}

bool Monomial::operator==(Monomial m)
{
	return (this->getCoef() == m.getCoef()) && (this->getTerm() == m.getTerm());
}

ostream& operator<<(ostream& os, const Monomial&)
{
	// TODO: insert return statement here
}

istream& operator>>(istream& is, Monomial&)
{
	// TODO: insert return statement here
}
