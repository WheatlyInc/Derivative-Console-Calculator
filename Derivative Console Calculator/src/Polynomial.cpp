#include "../inc/internal/Polynomial.h"

Polynomial::Polynomial()
{
    //ctor
}

Polynomial::~Polynomial()
{
    //dtor
}

ostream& operator<<(ostream& os, Polynomial poly)
{

	return os << poly;
}

istream& operator>>(istream& is, Polynomial& poly)
{

}
