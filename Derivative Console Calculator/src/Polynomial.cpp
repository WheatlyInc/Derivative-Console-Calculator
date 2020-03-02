#include "../inc/internal/Polynomial.h"

Polynomial::Polynomial()
{
    //ctor
}

Polynomial::~Polynomial()
{
    //dtor
}

vector<Monomial> Polynomial::getPolyn() const
{
   return m_polyn;
}

bool Polynomial::operator==(const Polynomial other_p) const
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
