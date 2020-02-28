#include "../inc/internal/Polynomial.h"

Polynomial::Polynomial()
{
    //ctor
}

Polynomial::~Polynomial()
{
    //dtor
}

vector<monomial> Polynomial::getPolyn() const
{
   return m_polyn;
}

bool Polynomial::operator==(Polynomial other_p)
{
	return this->getPolyn() == other_p.getPolyn();
}

ostream& operator<<(ostream& os, const Polynomial& poly)
{
	return os << poly;
}

istream& operator>>(istream& is, Polynomial& poly)
{
	
}
